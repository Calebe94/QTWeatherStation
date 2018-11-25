#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <stdlib.h>
#include <iostream>
#include <mysql-cppconn/jdbc/mysql_driver.h>
#include <mysql-cppconn/jdbc/mysql_error.h>
#include <mysql-cppconn/jdbc/cppconn/connection.h>
#include <mysql-cppconn/jdbc/cppconn/resultset.h>
#include <mysql-cppconn/jdbc/cppconn/statement.h>
#include <mysql-cppconn/jdbc/cppconn/config.h>



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
private:
    Ui::MainWindow *ui;
    int HOUR;
    int MINUTE;
    int HOUR_FINAL;
    int MINUTE_FINAL;
    int YEAR, MONTH, DAY;
private slots:
    void BuscarDados();
    void LimparDados();
};

#endif // MAINWINDOW_H
