/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QCalendarWidget *calendarWidget;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QTimeEdit *HoraFinal;
    QPushButton *BuscarButton;
    QPushButton *LimparButton;
    QTimeEdit *HoraInicial;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *labelMaiorUmidade;
    QLabel *labelMenorUmidade;
    QLabel *labelMediaUmidade;
    QLabel *labelUltimoUmidade;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *maiorumidade;
    QLabel *menorumidade;
    QLabel *mediaumidade;
    QLabel *ultimaumidade;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *Umidade_label;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *maior_label;
    QLabel *menor_label;
    QLabel *media_label;
    QLabel *ultimo_label;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *verticalLayout_5;
    QLabel *maiortemperatura;
    QLabel *menortemperatura;
    QLabel *mediatemperatura;
    QLabel *ultimatemperatura;
    QWidget *verticalLayoutWidget_6;
    QVBoxLayout *verticalLayout_6;
    QLabel *Temperatura_label;
    QGraphicsView *graphicsView;
    QLabel *label_whatisshowing;
    QComboBox *comboBoxPorts;
    QComboBox *comboBoxBaudrates;
    QPushButton *buttonConnect;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 400);
        MainWindow->setTabShape(QTabWidget::Triangular);
        MainWindow->setUnifiedTitleAndToolBarOnMac(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 322, 189));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        calendarWidget = new QCalendarWidget(gridLayoutWidget);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        calendarWidget->setGridVisible(true);

        gridLayout->addWidget(calendarWidget, 0, 0, 1, 1);

        gridLayoutWidget_2 = new QWidget(centralWidget);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(10, 200, 321, 130));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        HoraFinal = new QTimeEdit(gridLayoutWidget_2);
        HoraFinal->setObjectName(QString::fromUtf8("HoraFinal"));
        HoraFinal->setLocale(QLocale(QLocale::Portuguese, QLocale::Brazil));
        HoraFinal->setMaximumDateTime(QDateTime(QDate(2000, 1, 1), QTime(23, 59, 59)));
        HoraFinal->setMinimumDateTime(QDateTime(QDate(2000, 1, 1), QTime(0, 0, 0)));
        HoraFinal->setCurrentSection(QDateTimeEdit::HourSection);
        HoraFinal->setDisplayFormat(QString::fromUtf8("hh:mm"));
        HoraFinal->setCurrentSectionIndex(0);
        HoraFinal->setTimeSpec(Qt::UTC);
        HoraFinal->setTime(QTime(14, 0, 0));

        gridLayout_2->addWidget(HoraFinal, 1, 0, 1, 1);

        BuscarButton = new QPushButton(gridLayoutWidget_2);
        BuscarButton->setObjectName(QString::fromUtf8("BuscarButton"));

        gridLayout_2->addWidget(BuscarButton, 2, 0, 1, 1);

        LimparButton = new QPushButton(gridLayoutWidget_2);
        LimparButton->setObjectName(QString::fromUtf8("LimparButton"));

        gridLayout_2->addWidget(LimparButton, 3, 0, 1, 1);

        HoraInicial = new QTimeEdit(gridLayoutWidget_2);
        HoraInicial->setObjectName(QString::fromUtf8("HoraInicial"));
        HoraInicial->setLocale(QLocale(QLocale::Portuguese, QLocale::Brazil));
        HoraInicial->setMaximumTime(QTime(12, 59, 59));
        HoraInicial->setDisplayFormat(QString::fromUtf8("hh:mm"));
        HoraInicial->setTimeSpec(Qt::LocalTime);

        gridLayout_2->addWidget(HoraInicial, 0, 0, 1, 1);

        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(400, 90, 71, 231));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        labelMaiorUmidade = new QLabel(verticalLayoutWidget);
        labelMaiorUmidade->setObjectName(QString::fromUtf8("labelMaiorUmidade"));

        verticalLayout->addWidget(labelMaiorUmidade);

        labelMenorUmidade = new QLabel(verticalLayoutWidget);
        labelMenorUmidade->setObjectName(QString::fromUtf8("labelMenorUmidade"));

        verticalLayout->addWidget(labelMenorUmidade);

        labelMediaUmidade = new QLabel(verticalLayoutWidget);
        labelMediaUmidade->setObjectName(QString::fromUtf8("labelMediaUmidade"));

        verticalLayout->addWidget(labelMediaUmidade);

        labelUltimoUmidade = new QLabel(verticalLayoutWidget);
        labelUltimoUmidade->setObjectName(QString::fromUtf8("labelUltimoUmidade"));

        verticalLayout->addWidget(labelUltimoUmidade);

        verticalLayoutWidget_2 = new QWidget(centralWidget);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(470, 90, 71, 231));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        maiorumidade = new QLabel(verticalLayoutWidget_2);
        maiorumidade->setObjectName(QString::fromUtf8("maiorumidade"));

        verticalLayout_2->addWidget(maiorumidade);

        menorumidade = new QLabel(verticalLayoutWidget_2);
        menorumidade->setObjectName(QString::fromUtf8("menorumidade"));

        verticalLayout_2->addWidget(menorumidade);

        mediaumidade = new QLabel(verticalLayoutWidget_2);
        mediaumidade->setObjectName(QString::fromUtf8("mediaumidade"));

        verticalLayout_2->addWidget(mediaumidade);

        ultimaumidade = new QLabel(verticalLayoutWidget_2);
        ultimaumidade->setObjectName(QString::fromUtf8("ultimaumidade"));

        verticalLayout_2->addWidget(ultimaumidade);

        verticalLayoutWidget_3 = new QWidget(centralWidget);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(390, 50, 141, 31));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        Umidade_label = new QLabel(verticalLayoutWidget_3);
        Umidade_label->setObjectName(QString::fromUtf8("Umidade_label"));
        Umidade_label->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(Umidade_label);

        verticalLayoutWidget_4 = new QWidget(centralWidget);
        verticalLayoutWidget_4->setObjectName(QString::fromUtf8("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(580, 90, 71, 231));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        maior_label = new QLabel(verticalLayoutWidget_4);
        maior_label->setObjectName(QString::fromUtf8("maior_label"));

        verticalLayout_4->addWidget(maior_label);

        menor_label = new QLabel(verticalLayoutWidget_4);
        menor_label->setObjectName(QString::fromUtf8("menor_label"));

        verticalLayout_4->addWidget(menor_label);

        media_label = new QLabel(verticalLayoutWidget_4);
        media_label->setObjectName(QString::fromUtf8("media_label"));

        verticalLayout_4->addWidget(media_label);

        ultimo_label = new QLabel(verticalLayoutWidget_4);
        ultimo_label->setObjectName(QString::fromUtf8("ultimo_label"));

        verticalLayout_4->addWidget(ultimo_label);

        verticalLayoutWidget_5 = new QWidget(centralWidget);
        verticalLayoutWidget_5->setObjectName(QString::fromUtf8("verticalLayoutWidget_5"));
        verticalLayoutWidget_5->setGeometry(QRect(650, 90, 71, 231));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget_5);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        maiortemperatura = new QLabel(verticalLayoutWidget_5);
        maiortemperatura->setObjectName(QString::fromUtf8("maiortemperatura"));

        verticalLayout_5->addWidget(maiortemperatura);

        menortemperatura = new QLabel(verticalLayoutWidget_5);
        menortemperatura->setObjectName(QString::fromUtf8("menortemperatura"));

        verticalLayout_5->addWidget(menortemperatura);

        mediatemperatura = new QLabel(verticalLayoutWidget_5);
        mediatemperatura->setObjectName(QString::fromUtf8("mediatemperatura"));

        verticalLayout_5->addWidget(mediatemperatura);

        ultimatemperatura = new QLabel(verticalLayoutWidget_5);
        ultimatemperatura->setObjectName(QString::fromUtf8("ultimatemperatura"));

        verticalLayout_5->addWidget(ultimatemperatura);

        verticalLayoutWidget_6 = new QWidget(centralWidget);
        verticalLayoutWidget_6->setObjectName(QString::fromUtf8("verticalLayoutWidget_6"));
        verticalLayoutWidget_6->setGeometry(QRect(560, 50, 141, 31));
        verticalLayout_6 = new QVBoxLayout(verticalLayoutWidget_6);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        Temperatura_label = new QLabel(verticalLayoutWidget_6);
        Temperatura_label->setObjectName(QString::fromUtf8("Temperatura_label"));
        Temperatura_label->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(Temperatura_label);

        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(360, 40, 401, 291));
        label_whatisshowing = new QLabel(centralWidget);
        label_whatisshowing->setObjectName(QString::fromUtf8("label_whatisshowing"));
        label_whatisshowing->setGeometry(QRect(360, 8, 401, 21));
        comboBoxPorts = new QComboBox(centralWidget);
        comboBoxPorts->addItem(QString());
        comboBoxPorts->addItem(QString());
        comboBoxPorts->addItem(QString());
        comboBoxPorts->addItem(QString());
        comboBoxPorts->addItem(QString());
        comboBoxPorts->setObjectName(QString::fromUtf8("comboBoxPorts"));
        comboBoxPorts->setGeometry(QRect(360, 10, 131, 26));
        comboBoxBaudrates = new QComboBox(centralWidget);
        comboBoxBaudrates->addItem(QString());
        comboBoxBaudrates->addItem(QString());
        comboBoxBaudrates->addItem(QString());
        comboBoxBaudrates->addItem(QString());
        comboBoxBaudrates->addItem(QString());
        comboBoxBaudrates->addItem(QString());
        comboBoxBaudrates->addItem(QString());
        comboBoxBaudrates->addItem(QString());
        comboBoxBaudrates->setObjectName(QString::fromUtf8("comboBoxBaudrates"));
        comboBoxBaudrates->setGeometry(QRect(490, 10, 151, 26));
        buttonConnect = new QPushButton(centralWidget);
        buttonConnect->setObjectName(QString::fromUtf8("buttonConnect"));
        buttonConnect->setGeometry(QRect(640, 10, 121, 26));
        MainWindow->setCentralWidget(centralWidget);
        graphicsView->raise();
        gridLayoutWidget->raise();
        gridLayoutWidget_2->raise();
        verticalLayoutWidget->raise();
        verticalLayoutWidget_2->raise();
        verticalLayoutWidget_3->raise();
        verticalLayoutWidget_4->raise();
        verticalLayoutWidget_5->raise();
        verticalLayoutWidget_6->raise();
        label_whatisshowing->raise();
        comboBoxPorts->raise();
        comboBoxBaudrates->raise();
        buttonConnect->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Esta\303\247\303\243o Metereol\303\263gica", nullptr));
        BuscarButton->setText(QApplication::translate("MainWindow", "Buscar", nullptr));
        LimparButton->setText(QApplication::translate("MainWindow", "Limpar", nullptr));
        labelMaiorUmidade->setText(QApplication::translate("MainWindow", "Maior:", nullptr));
        labelMenorUmidade->setText(QApplication::translate("MainWindow", "Menor:", nullptr));
        labelMediaUmidade->setText(QApplication::translate("MainWindow", "M\303\251dia:", nullptr));
        labelUltimoUmidade->setText(QApplication::translate("MainWindow", "\303\232ltimo:", nullptr));
        maiorumidade->setText(QApplication::translate("MainWindow", "80%", nullptr));
        menorumidade->setText(QApplication::translate("MainWindow", "75%", nullptr));
        mediaumidade->setText(QApplication::translate("MainWindow", "67,5%", nullptr));
        ultimaumidade->setText(QApplication::translate("MainWindow", "79%", nullptr));
        Umidade_label->setText(QApplication::translate("MainWindow", "Umidade", nullptr));
        maior_label->setText(QApplication::translate("MainWindow", "Maior:", nullptr));
        menor_label->setText(QApplication::translate("MainWindow", "Menor:", nullptr));
        media_label->setText(QApplication::translate("MainWindow", "M\303\251dia:", nullptr));
        ultimo_label->setText(QApplication::translate("MainWindow", "\303\232ltimo:", nullptr));
        maiortemperatura->setText(QApplication::translate("MainWindow", "24\302\272C", nullptr));
        menortemperatura->setText(QApplication::translate("MainWindow", "24\302\272C", nullptr));
        mediatemperatura->setText(QApplication::translate("MainWindow", "24\302\272C", nullptr));
        ultimatemperatura->setText(QApplication::translate("MainWindow", "24\302\272C", nullptr));
        Temperatura_label->setText(QApplication::translate("MainWindow", "Temperatura", nullptr));
        label_whatisshowing->setText(QString());
        comboBoxPorts->setItemText(0, QApplication::translate("MainWindow", "Porta", nullptr));
        comboBoxPorts->setItemText(1, QApplication::translate("MainWindow", "/dev/ttyACM0", nullptr));
        comboBoxPorts->setItemText(2, QApplication::translate("MainWindow", "/dev/ttyACM1", nullptr));
        comboBoxPorts->setItemText(3, QApplication::translate("MainWindow", "/dev/ttyUSB0", nullptr));
        comboBoxPorts->setItemText(4, QApplication::translate("MainWindow", "/dev/ttyUSB1", nullptr));

        comboBoxBaudrates->setItemText(0, QApplication::translate("MainWindow", "Baudrate", nullptr));
        comboBoxBaudrates->setItemText(1, QApplication::translate("MainWindow", "9600", nullptr));
        comboBoxBaudrates->setItemText(2, QApplication::translate("MainWindow", "19200", nullptr));
        comboBoxBaudrates->setItemText(3, QApplication::translate("MainWindow", "38400", nullptr));
        comboBoxBaudrates->setItemText(4, QApplication::translate("MainWindow", "56000", nullptr));
        comboBoxBaudrates->setItemText(5, QApplication::translate("MainWindow", "115200", nullptr));
        comboBoxBaudrates->setItemText(6, QApplication::translate("MainWindow", "128000", nullptr));
        comboBoxBaudrates->setItemText(7, QApplication::translate("MainWindow", "256000", nullptr));

        buttonConnect->setText(QApplication::translate("MainWindow", "Conectar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
