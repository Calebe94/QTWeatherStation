#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPort>
#include <QRunnable>

using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
    {
        ui->setupUi(this);
        connect(ui->BuscarButton, SIGNAL(clicked()), this, SLOT(BuscarDados()));
        connect(ui->LimparButton, SIGNAL(clicked()), this, SLOT(LimparDados()));
        connect(ui->buttonConnect, SIGNAL(clicked()), this, SLOT(ConnectSerial()));
        connect(&this->serial, SIGNAL(ReadSerialData()), this, SLOT(ReadSerialData));
    }

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::BuscarDados(){
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

void MainWindow::ReadSerialData()
{
    if (serial.isOpen() && serial.isWritable())
    {

        QByteArray output;

        output = "t";
        this->serial.write(output);
        this->serial.flush();
        this->serial.waitForBytesWritten(100);
        this->serial.waitForReadyRead(500);
        this->temperature = this->serial.readAll();

        output = "h";
        this->serial.write(output);
        this->serial.flush();
        this->serial.waitForBytesWritten(100);
        this->serial.waitForReadyRead(500);
        this->humidity = this->serial.readAll();

        cout << "Temperature:"+this->temperature.toStdString() << endl;
        cout << "Humidity:"+this->humidity.toStdString() << endl;
     }
}
void MainWindow::ConnectSerial(){
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
        this->serial.open(QIODevice::ReadWrite);
        this->serial.setBaudRate(baudrateString.toInt());
        this->serial.setDataBits(QSerialPort::Data8);
        this->serial.setParity(QSerialPort::NoParity);
        this->serial.setStopBits(QSerialPort::OneStop);
        this->serial.setFlowControl(QSerialPort::HardwareControl);

        while(true)
        {
            ReadSerialData();
        }
    }
    else
    {
        cout << "Nao Conecta na Serial!"<< endl;
    }
}

void MainWindow::LimparDados(){
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
void MainWindow::UpdateAverage(QString Query){
    try {
      sql::Driver *driver = nullptr;
      sql::Connection *con;
      sql::Statement *stmt;
      sql::ResultSet *res;
      driver = get_driver_instance();
      con = driver->connect("tcp://127.0.0.1:3306", "root", "");
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
void MainWindow::UpdateMin(QString Query){
    try {
      sql::Driver *driver = nullptr;
      sql::Connection *con;
      sql::Statement *stmt;
      sql::ResultSet *res;
      driver = get_driver_instance();
      con = driver->connect("tcp://127.0.0.1:3306", "root", "");
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
void MainWindow::UpdateMax(QString Query){
    try {
      sql::Driver *driver = nullptr;
      sql::Connection *con;
      sql::Statement *stmt;
      sql::ResultSet *res;
      driver = get_driver_instance();
      con = driver->connect("tcp://127.0.0.1:3306", "root", "");
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
void MainWindow::UpdateMostRecent(QString Query){
    try {
      sql::Driver *driver = nullptr;
      sql::Connection *con;
      sql::Statement *stmt;
      sql::ResultSet *res;
      driver = get_driver_instance();
      con = driver->connect("tcp://127.0.0.1:3306", "root", "");
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
