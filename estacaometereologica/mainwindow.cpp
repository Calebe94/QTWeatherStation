#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPort>
#include <QRunnable>
#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
#include <QTimer>

using namespace std;
MainWindow::MainWindow(QWidget *parent) :// extancia classe main window
    QMainWindow(parent),
    ui(new Ui::MainWindow)
    {
        ui->setupUi(this);
        connect(ui->BuscarButton, SIGNAL(clicked()), this, SLOT(BuscarDados()));
        connect(ui->LimparButton, SIGNAL(clicked()), this, SLOT(LimparDados()));
        connect(ui->buttonConnect, SIGNAL(clicked()), this, SLOT(ConnectSerial()));// quando clica aqui q chama o evento do botao conectar
//        connect(&this->serial, SIGNAL(ReadSerialData()), this, SLOT(ReadSerialData));
    }

MainWindow::~MainWindow()// destrutor da clasee main windown
{
    delete ui;
}
// ========================= FUNCAO DESATIVADA ===========================
void MainWindow::BuscarDados(){// funcao desativada
HOUR   = ui->HoraInicial->time().hour();
MINUTE = ui->HoraInicial->time().minute();
HOUR_FINAL = ui->HoraFinal->time().hour();
MINUTE_FINAL = ui->HoraFinal->time().minute();
ui->calendarWidget->selectedDate().getDate(&YEAR, &MONTH, &DAY);
ui->label_whatisshowing->setText("Mostrando medições para o dia: " + QString::number(DAY) + "-" + QString::number(MONTH) + "-" + QString::number(YEAR));
QString FULL_DATE = QString::number(YEAR) + "-" + QString::number(MONTH) + "-" + QString::number(DAY);
QString FULL_INITIALHOUR = QString("%1").arg(HOUR, 2, 10, QChar('0')) + ":" + QString("%1").arg(MINUTE, 2, 10, QChar('0'));
QString FULL_FINALHOUR = QString("%1").arg(HOUR_FINAL, 2, 10, QChar('0')) + ":" + QString("%1").arg(MINUTE_FINAL, 2, 10, QChar('0'));
QString Query_Average = "SELECT AVG(umidade), AVG(temperatura) from metereologia.medicoes where (data = '" + FULL_DATE + "' AND hora between '" + FULL_INITIALHOUR + ":00' and '" + FULL_FINALHOUR + ":00');";
QString Query_Min = "SELECT MIN(umidade), MIN(temperatura) from metereologia.medicoes where (data = '" + FULL_DATE + "' AND hora between '" + FULL_INITIALHOUR + ":00' and '" + FULL_FINALHOUR + ":00');";
QString Query_Max = "SELECT MAX(umidade), MAX(temperatura) from metereologia.medicoes where (data = '" + FULL_DATE + "' AND hora between '" + FULL_INITIALHOUR + ":00' and '" + FULL_FINALHOUR + ":00');";
QString Query_FilterRecent = "SELECT umidade, temperatura from metereologia.medicoes where (data = '" + FULL_DATE + "' AND hora between '" + FULL_INITIALHOUR + ":00' and '" + FULL_FINALHOUR + ":00') order by ID desc LIMIT 1;";
QString Query_Recent = "select * from metereologia.medicoes order by ID desc LIMIT 1;";
cout << Query_Average.toStdString() << endl;
cout << Query_Min.toStdString() << endl;
cout << Query_Max.toStdString() << endl;
cout << Query_FilterRecent.toStdString() << endl;
UpdateAverage(Query_Average);
UpdateMax(Query_Max);
UpdateMin(Query_Min);
UpdateMostRecent(Query_FilterRecent);
}

void MainWindow::UpdateWindow() //funcao atualiza tela a cada 1 s
{
    cout << "Chamada da UPDATE_WINDOW()" << endl;
    QString query_average = "SELECT AVG(umidade), AVG(temperatura) from metereologia.medicoes";
    QString query_min = "SELECT MIN(umidade), MIN(temperatura) from metereologia.medicoes";
    QString query_max = "SELECT MAX(umidade), MAX(temperatura) from metereologia.medicoes";
    QString Query_Recent = "select * from metereologia.medicoes order by ID desc LIMIT 1;";
    QString Query_FilterRecent = "SELECT umidade, temperatura from metereologia.medicoes order by ID desc LIMIT 1;";

    UpdateAverage(query_average);
    UpdateMax(query_max);
    UpdateMin(query_min);
    UpdateMostRecent(Query_FilterRecent);
}

void MainWindow::ReadSerialData()// funcao le serial e joga temperatura e umidade no banco
{
    if (serial.isOpen() && serial.isWritable())
    {
        time_t     now = time(0);
        struct tm  tstruct;
        char       date[80], hour[80];
        tstruct = *localtime(&now);
        // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
        // for more information about date/time format
        strftime(date, sizeof(date), "%Y-%m-%d", &tstruct);
        strftime(hour, sizeof(hour), "%R", &tstruct);

        cout << "Data:" << date << endl;
        cout << "Hora:" << hour << endl;// desde o incio da funcao ate aqui pega a data do sistema

        QByteArray output;

        output = "t";// enviar t para buscar temperatura da serial
        this->serial.write(output);
        this->serial.flush();
        this->serial.waitForBytesWritten(100);
        this->serial.waitForReadyRead(500);
        this->temperature = this->serial.readAll();

        output = "h";// envia h para buscar humidade da serial
        this->serial.write(output);
        this->serial.flush();
        this->serial.waitForBytesWritten(100);
        this->serial.waitForReadyRead(500);
        this->humidity = this->serial.readAll();

        cout << "Temperature:"+this->temperature.toStdString() << endl;
        cout << "Humidity:"+this->humidity.toStdString() << endl;

        this->InsertOnDatabase(); // chama outra funcao insere temperatura e humidade no banco, q e a funcao de baixo
     }
}

void MainWindow::InsertOnDatabase()// aqui insere temperatura  e humidade no banco
{
    time_t     now = time(0);
    struct tm  tstruct;
    char       date[80], hour[80];
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(date, sizeof(date), "%Y-%m-%d", &tstruct);
    strftime(hour, sizeof(hour), "%T", &tstruct);

    QString qdate = date;
    QString qhour = hour;
    QString qhumidity = this->humidity;
    QString qtemperature = this->temperature;

    try {
      sql::Driver *driver = nullptr;
      sql::Connection *con;
      sql::Statement *stmt;
      sql::ResultSet *res;
      driver = get_driver_instance();
      con = driver->connect("tcp://127.0.0.1:3306", "root", this->password);
      con->setSchema("metereologia");
      stmt = con->createStatement();
      QString query = "INSERT INTO `metereologia`.`medicoes` (`data`,`hora`,`umidade`,`temperatura`) VALUES (\""+qdate+"\", \""+qhour+"\", "+qhumidity+" ,"+qtemperature+");";
      res = stmt->executeQuery(query.toStdString());
//      while (res->next()) {
//       ui->maiorumidade->setText(res->getString("MAX(umidade)").append("%").c_str());
//       ui->maiortemperatura->setText(res->getString("MAX(temperatura)").append("ºC").c_str());
//      }
      delete res;
      delete stmt;
      delete con;

    } catch (sql::SQLException &e) {
      cout << "# ERR: SQLException in " << __FILE__;
      cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
      cout << "# ERR: " << e.what();
      cout << " (MySQL error code: " << e.getErrorCode();
      cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
}

void MainWindow::ConnectSerial(){ // quando clica no botao conectar chama essa funcao
    /*
     * Referencia para Serial:
     * https://stackoverflow.com/questions/26459788/qt-serial-port-write-and-read-data
     * https://pt.stackoverflow.com/questions/9947/como-funciona-a-comunicação-serial-e-como-fazer-utilizando-c-c
    */

    QString baudrateString = ui->comboBoxBaudrates->currentText();
    QString portString = ui->comboBoxPorts->currentText();
    if(baudrateString.toStdString() != "Baudrate" && portString.toStdString() != "Porta")
    {
        cout << baudrateString.toStdString() << endl;
        cout << portString.toStdString() << endl;
        cout << "Conecta Serial!"<< endl;
        this->serial.setPortName(portString);
        this->serial.open(QIODevice::ReadWrite); // tenta conectar na serial
        if(this->serial.isOpen())
        {
            this->serial.setBaudRate(baudrateString.toInt());// se concectar entra aqui
            this->serial.setDataBits(QSerialPort::Data8);
            this->serial.setParity(QSerialPort::NoParity);
            this->serial.setStopBits(QSerialPort::OneStop);
            this->serial.setFlowControl(QSerialPort::HardwareControl);

            this->timer = new QTimer(this); // SETA O TIMER PARA 1 SEGUNDO
            connect(this->timer, SIGNAL(timeout()), this, SLOT(ReadSerialData())); // CONECTA FUNCAO DE LER SERIAL
            connect(this->timer, SIGNAL(timeout()), this, SLOT(UpdateWindow())); // CONECTA FUNCAO DE ATUALIZAR TELA
            this->timer->start(1000);
            ui->comboBoxBaudrates->setStyleSheet("QComboBox { background-color: blue; }");// se sucesso coloca cor azul
            ui->comboBoxPorts->setStyleSheet("QComboBox { background-color: blue; }");
            ui->buttonConnect->setEnabled(false);
        }
        else
        {
            ui->comboBoxBaudrates->setStyleSheet("QComboBox { background-color: red; }");// se fracasso fica em vermelho
            ui->comboBoxPorts->setStyleSheet("QComboBox { background-color: red; }");
        }
    }
    else
    {
        ui->comboBoxBaudrates->setStyleSheet("QComboBox { background-color: red; }");
        ui->comboBoxPorts->setStyleSheet("QComboBox { background-color: red; }");// se fracasso fica em vermelho
        cout << "Nao Conecta na Serial!"<< endl;
    }
}
// ========================= FUNCAO DESATIVADA ===========================
void MainWindow::LimparDados(){ // Funcao desativada
    QDate date = QDate::currentDate();
    QString dateString = date.toString();
    ui->calendarWidget->setSelectedDate(date);
    HOUR   = ui->HoraInicial->time().hour();
    MINUTE = ui->HoraInicial->time().minute();
    HOUR_FINAL = ui->HoraFinal->time().hour();
    MINUTE_FINAL = ui->HoraFinal->time().minute();
    ui->calendarWidget->selectedDate().getDate(&YEAR, &MONTH, &DAY);
    QString FULL_DATE = QString::number(YEAR) + "-" + QString::number(MONTH) + "-" + QString::number(DAY);
    QString FULL_INITIALHOUR = QString("%1").arg(HOUR, 2, 10, QChar('0')) + ":" + QString("%1").arg(MINUTE, 2, 10, QChar('0'));
    QString FULL_FINALHOUR = QString("%1").arg(HOUR_FINAL, 2, 10, QChar('0')) + ":" + QString("%1").arg(MINUTE_FINAL, 2, 10, QChar('0'));
    ui->label_whatisshowing->setText("Mostrando medições para o dia: " + dateString);
    QString Query_Average = "SELECT AVG(umidade), AVG(temperatura) from metereologia.medicoes where (data = '" + FULL_DATE + "' AND hora between '" + FULL_INITIALHOUR + ":00' and '" + FULL_FINALHOUR + ":00') order by ID desc LIMIT 5;";
    QString Query_Min = "SELECT MIN(umidade), MIN(temperatura) from metereologia.medicoes where (data = '" + FULL_DATE + "' AND hora between '" + FULL_INITIALHOUR + ":00' and '" + FULL_FINALHOUR + ":00') order by ID desc LIMIT 5;";
    QString Query_Max = "SELECT MAX(umidade), MAX(temperatura) from metereologia.medicoes where (data = '" + FULL_DATE + "' AND hora between '" + FULL_INITIALHOUR + ":00' and '" + FULL_FINALHOUR + ":00') order by ID desc LIMIT 5;";
    QString Query_Recent = "select umidade, temperatura from metereologia.medicoes where (data = '" + FULL_DATE + "') order by ID desc LIMIT 1;";
    cout << Query_Average.toStdString() << endl;
    cout << Query_Min.toStdString() << endl;
    cout << Query_Max.toStdString() << endl;
    cout << Query_Recent.toStdString() << endl;
    UpdateAverage(Query_Average);
    UpdateMax(Query_Max);
    UpdateMin(Query_Min);
    UpdateMostRecent(Query_Recent);
}

void MainWindow::UpdateAverage(QString Query){ // FUNCAO CHAMADA PELA UPDATE TELA: ATUALIZA A MEDIA, busca do banco e atualiza a media
    try {
      sql::Driver *driver = nullptr;
      sql::Connection *con;
      sql::Statement *stmt;
      sql::ResultSet *res;
      driver = get_driver_instance();
      con = driver->connect("tcp://127.0.0.1:3306", "root", this->password);
      con->setSchema("metereologia");

      stmt = con->createStatement();
      res = stmt->executeQuery(Query.toStdString());
      while (res->next()) {
       ui->mediaumidade->setText(res->getString("AVG(umidade)").append("%").c_str());
       ui->mediatemperatura->setText(res->getString("AVG(temperatura)").append("ºC").c_str());
      }
      delete res;
      delete stmt;
      delete con;

    } catch (sql::SQLException &e) {
      cout << "# ERR: SQLException in " << __FILE__;
      cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
      cout << "# ERR: " << e.what();
      cout << " (MySQL error code: " << e.getErrorCode();
      cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
}
void MainWindow::UpdateMin(QString Query){ // FUNCAO CHAMADA PELA UPDATE TELA: ATUALIZA O VALOR MINIMO
    try {
      sql::Driver *driver = nullptr;
      sql::Connection *con;
      sql::Statement *stmt;
      sql::ResultSet *res;
      driver = get_driver_instance();
      con = driver->connect("tcp://127.0.0.1:3306", "root", this->password);
      con->setSchema("metereologia");

      stmt = con->createStatement();
      res = stmt->executeQuery(Query.toStdString());
      while (res->next()) {
       ui->menorumidade->setText(res->getString("MIN(umidade)").append("%").c_str());
       ui->menortemperatura->setText(res->getString("MIN(temperatura)").append("ºC").c_str());
      }
      delete res;
      delete stmt;
      delete con;

    } catch (sql::SQLException &e) {
      cout << "# ERR: SQLException in " << __FILE__;
      cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
      cout << "# ERR: " << e.what();
      cout << " (MySQL error code: " << e.getErrorCode();
      cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
}
void MainWindow::UpdateMax(QString Query){ // FUNCAO CHAMADA PELA UPDATE TELA: ATUALIZA O VALOR MAXIMO
    try {
      sql::Driver *driver = nullptr;
      sql::Connection *con;
      sql::Statement *stmt;
      sql::ResultSet *res;
      driver = get_driver_instance();
      con = driver->connect("tcp://127.0.0.1:3306", "root", this->password);
      con->setSchema("metereologia");

      stmt = con->createStatement();
      res = stmt->executeQuery(Query.toStdString());
      while (res->next()) {
       ui->maiorumidade->setText(res->getString("MAX(umidade)").append("%").c_str());
       ui->maiortemperatura->setText(res->getString("MAX(temperatura)").append("ºC").c_str());
      }
      delete res;
      delete stmt;
      delete con;

    } catch (sql::SQLException &e) {
      cout << "# ERR: SQLException in " << __FILE__;
      cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
      cout << "# ERR: " << e.what();
      cout << " (MySQL error code: " << e.getErrorCode();
      cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
}
void MainWindow::UpdateMostRecent(QString Query){ // FUNCAO CHAMADA PELA UPDATE TELA: ATUALIZA O VALOR MAIS RECENTE
    try {
      sql::Driver *driver = nullptr;
      sql::Connection *con;
      sql::Statement *stmt;
      sql::ResultSet *res;
      driver = get_driver_instance();
      con = driver->connect("tcp://127.0.0.1:3306", "root", this->password);
      con->setSchema("metereologia");

      stmt = con->createStatement();
      res = stmt->executeQuery(Query.toStdString());
      while (res->next()) {
       ui->ultimaumidade->setText(res->getString("umidade").append("%").c_str());
       ui->ultimatemperatura->setText(res->getString("temperatura").append("ºC").c_str());
      }
      delete res;
      delete stmt;
      delete con;

    } catch (sql::SQLException &e) {
      cout << "# ERR: SQLException in " << __FILE__;
      cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
      cout << "# ERR: " << e.what();
      cout << " (MySQL error code: " << e.getErrorCode();
      cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
}
void MainWindow::closeEvent(QCloseEvent *event) { // QUANDO FECHA O PROGRAMA PARA O TIMER E FECHA A PORTA SERIAL
    this->timer->stop();
    this->serial.close();
}
