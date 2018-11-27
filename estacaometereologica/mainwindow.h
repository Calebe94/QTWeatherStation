#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <stdlib.h>
#include <iostream>

//#include <mysql-cppconn/jdbc/mysql_driver.h>
//#include <mysql-cppconn/jdbc/mysql_error.h>
//#include <mysql-cppconn/jdbc/cppconn/connection.h>
//#include <mysql-cppconn/jdbc/cppconn/resultset.h>
//#include <mysql-cppconn/jdbc/cppconn/statement.h>
//#include <mysql-cppconn/jdbc/cppconn/config.h>


#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <QSerialPort>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void UpdateAverage(QString Query);
    void UpdateMin(QString Query);
    void UpdateMax(QString Query);
    void UpdateMostRecent(QString Query);
    void ReadSerialData();
private:
    Ui::MainWindow *ui;
    QSerialPort serial;
    int HOUR;
    int MINUTE;
    int HOUR_FINAL;
    int MINUTE_FINAL;
    int YEAR, MONTH, DAY;
    QByteArray temperature;
    QByteArray humidity;
private slots:
    void BuscarDados();
    void LimparDados();
    void ConnectSerial();
};

#endif // MAINWINDOW_H
