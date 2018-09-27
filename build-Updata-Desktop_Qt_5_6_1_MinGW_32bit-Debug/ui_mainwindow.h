/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_2;
    QComboBox *comboSeriePort;
    QLabel *label_3;
    QComboBox *comboBautRate;
    QLabel *label_4;
    QLineEdit *browseFileEdit;
    QPushButton *browserButton;
    QLabel *label_5;
    QLineEdit *fileSizeEdit;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *oneSizeEdit;
    QPushButton *ConnectButton;
    QPushButton *upgrateButton;
    QLineEdit *termialAddrEdit;
    QLabel *label_9;
    QComboBox *comboStopBit;
    QLabel *label_10;
    QComboBox *comboDataBit;
    QLabel *label_11;
    QComboBox *comboParityBit;
    QLabel *label_12;
    QPushButton *pushButtonConnect;
    QPushButton *pushButtonSeriesSet;
    QLabel *label_13;
    QLabel *connectStatusLabel;
    QPlainTextEdit *displayBinEdit;
    QLabel *connectTerStatusLabe;
    QLineEdit *sendingNumEdit;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLineEdit *sendAllNumEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(808, 494);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(150, 0, 201, 31));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 50, 54, 21));
        comboSeriePort = new QComboBox(centralWidget);
        comboSeriePort->setObjectName(QStringLiteral("comboSeriePort"));
        comboSeriePort->setGeometry(QRect(80, 50, 69, 22));
        QFont font1;
        font1.setPointSize(10);
        comboSeriePort->setFont(font1);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(181, 51, 64, 18));
        comboBautRate = new QComboBox(centralWidget);
        comboBautRate->setObjectName(QStringLiteral("comboBautRate"));
        comboBautRate->setGeometry(QRect(251, 51, 76, 20));
        comboBautRate->setFont(font1);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 130, 71, 21));
        browseFileEdit = new QLineEdit(centralWidget);
        browseFileEdit->setObjectName(QStringLiteral("browseFileEdit"));
        browseFileEdit->setEnabled(true);
        browseFileEdit->setGeometry(QRect(110, 130, 281, 20));
        browseFileEdit->setReadOnly(false);
        browserButton = new QPushButton(centralWidget);
        browserButton->setObjectName(QStringLiteral("browserButton"));
        browserButton->setGeometry(QRect(400, 130, 75, 23));
        QFont font2;
        font2.setPointSize(12);
        browserButton->setFont(font2);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(30, 170, 71, 21));
        label_5->setFont(font2);
        fileSizeEdit = new QLineEdit(centralWidget);
        fileSizeEdit->setObjectName(QStringLiteral("fileSizeEdit"));
        fileSizeEdit->setEnabled(false);
        fileSizeEdit->setGeometry(QRect(110, 170, 101, 20));
        fileSizeEdit->setReadOnly(true);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(220, 170, 71, 21));
        label_6->setFont(font2);
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(30, 200, 111, 21));
        label_7->setFont(font2);
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(220, 200, 71, 21));
        label_8->setFont(font2);
        oneSizeEdit = new QLineEdit(centralWidget);
        oneSizeEdit->setObjectName(QStringLiteral("oneSizeEdit"));
        oneSizeEdit->setEnabled(true);
        oneSizeEdit->setGeometry(QRect(140, 200, 71, 20));
        oneSizeEdit->setReadOnly(false);
        ConnectButton = new QPushButton(centralWidget);
        ConnectButton->setObjectName(QStringLiteral("ConnectButton"));
        ConnectButton->setGeometry(QRect(100, 310, 75, 23));
        ConnectButton->setFont(font2);
        upgrateButton = new QPushButton(centralWidget);
        upgrateButton->setObjectName(QStringLiteral("upgrateButton"));
        upgrateButton->setGeometry(QRect(270, 310, 75, 23));
        upgrateButton->setFont(font2);
        termialAddrEdit = new QLineEdit(centralWidget);
        termialAddrEdit->setObjectName(QStringLiteral("termialAddrEdit"));
        termialAddrEdit->setEnabled(true);
        termialAddrEdit->setGeometry(QRect(110, 280, 141, 20));
        termialAddrEdit->setReadOnly(false);
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(30, 280, 71, 21));
        label_9->setFont(font2);
        comboStopBit = new QComboBox(centralWidget);
        comboStopBit->setObjectName(QStringLiteral("comboStopBit"));
        comboStopBit->setGeometry(QRect(420, 50, 51, 22));
        comboStopBit->setFont(font1);
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(360, 50, 54, 21));
        comboDataBit = new QComboBox(centralWidget);
        comboDataBit->setObjectName(QStringLiteral("comboDataBit"));
        comboDataBit->setGeometry(QRect(90, 90, 51, 22));
        comboDataBit->setFont(font1);
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(30, 90, 54, 21));
        comboParityBit = new QComboBox(centralWidget);
        comboParityBit->setObjectName(QStringLiteral("comboParityBit"));
        comboParityBit->setGeometry(QRect(240, 90, 51, 22));
        comboParityBit->setFont(font1);
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(160, 90, 81, 21));
        pushButtonConnect = new QPushButton(centralWidget);
        pushButtonConnect->setObjectName(QStringLiteral("pushButtonConnect"));
        pushButtonConnect->setGeometry(QRect(370, 90, 101, 23));
        pushButtonConnect->setFont(font2);
        pushButtonSeriesSet = new QPushButton(centralWidget);
        pushButtonSeriesSet->setObjectName(QStringLiteral("pushButtonSeriesSet"));
        pushButtonSeriesSet->setGeometry(QRect(310, 90, 41, 23));
        pushButtonSeriesSet->setFont(font2);
        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(10, 410, 81, 16));
        label_13->setFont(font2);
        connectStatusLabel = new QLabel(centralWidget);
        connectStatusLabel->setObjectName(QStringLiteral("connectStatusLabel"));
        connectStatusLabel->setGeometry(QRect(110, 410, 121, 16));
        connectStatusLabel->setFont(font2);
        displayBinEdit = new QPlainTextEdit(centralWidget);
        displayBinEdit->setObjectName(QStringLiteral("displayBinEdit"));
        displayBinEdit->setGeometry(QRect(480, 0, 301, 351));
        connectTerStatusLabe = new QLabel(centralWidget);
        connectTerStatusLabe->setObjectName(QStringLiteral("connectTerStatusLabe"));
        connectTerStatusLabe->setGeometry(QRect(130, 340, 211, 31));
        QFont font3;
        font3.setPointSize(18);
        font3.setBold(true);
        font3.setWeight(75);
        connectTerStatusLabe->setFont(font3);
        sendingNumEdit = new QLineEdit(centralWidget);
        sendingNumEdit->setObjectName(QStringLiteral("sendingNumEdit"));
        sendingNumEdit->setEnabled(false);
        sendingNumEdit->setGeometry(QRect(100, 240, 51, 20));
        sendingNumEdit->setReadOnly(false);
        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(30, 240, 61, 21));
        label_14->setFont(font2);
        label_15 = new QLabel(centralWidget);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(160, 240, 31, 21));
        label_15->setFont(font2);
        label_16 = new QLabel(centralWidget);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(310, 240, 31, 21));
        label_16->setFont(font2);
        label_17 = new QLabel(centralWidget);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(190, 240, 61, 21));
        label_17->setFont(font2);
        sendAllNumEdit = new QLineEdit(centralWidget);
        sendAllNumEdit->setObjectName(QStringLiteral("sendAllNumEdit"));
        sendAllNumEdit->setEnabled(false);
        sendAllNumEdit->setGeometry(QRect(250, 240, 51, 20));
        sendAllNumEdit->setReadOnly(false);
        MainWindow->setCentralWidget(centralWidget);
        comboSeriePort->raise();
        label_3->raise();
        comboBautRate->raise();
        label_4->raise();
        browseFileEdit->raise();
        browserButton->raise();
        label_5->raise();
        fileSizeEdit->raise();
        label_6->raise();
        label_7->raise();
        label_8->raise();
        oneSizeEdit->raise();
        ConnectButton->raise();
        upgrateButton->raise();
        termialAddrEdit->raise();
        label_9->raise();
        comboStopBit->raise();
        label_10->raise();
        comboDataBit->raise();
        label_11->raise();
        comboParityBit->raise();
        label_12->raise();
        pushButtonConnect->raise();
        label->raise();
        label_2->raise();
        pushButtonSeriesSet->raise();
        label_13->raise();
        connectStatusLabel->raise();
        displayBinEdit->raise();
        connectTerStatusLabe->raise();
        sendingNumEdit->raise();
        label_14->raise();
        label_15->raise();
        label_16->raise();
        label_17->raise();
        sendAllNumEdit->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 808, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label->setText(QApplication::translate("MainWindow", "\345\207\272\346\260\264\345\217\243\350\277\234\347\250\213\345\215\207\347\272\247", 0));
        label_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">\344\270\262\345\217\243\357\274\232</span></p></body></html>", 0));
        label_3->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">\346\263\242\347\211\271\347\216\207\357\274\232</span></p></body></html>", 0));
        label_4->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">\351\200\211\346\213\251\346\226\207\344\273\266\357\274\232</span></p></body></html>", 0));
        browserButton->setText(QApplication::translate("MainWindow", "\346\265\217\350\247\210", 0));
        label_5->setText(QApplication::translate("MainWindow", "\346\226\207\344\273\266\345\244\247\345\260\217\357\274\232", 0));
        label_6->setText(QApplication::translate("MainWindow", "Bytes", 0));
        label_7->setText(QApplication::translate("MainWindow", "\345\215\225\346\254\241\345\217\221\351\200\201\351\225\277\345\272\246\357\274\232", 0));
        label_8->setText(QApplication::translate("MainWindow", "Bytes", 0));
        ConnectButton->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245\350\256\276\345\244\207", 0));
        upgrateButton->setText(QApplication::translate("MainWindow", "\350\277\234\347\250\213\345\215\207\347\272\247", 0));
        label_9->setText(QApplication::translate("MainWindow", "\350\256\276\345\244\207\347\274\226\345\217\267\357\274\232", 0));
        label_10->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">\345\201\234\346\255\242\344\275\215\357\274\232</span></p></body></html>", 0));
        label_11->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">\346\225\260\346\215\256\344\275\215\357\274\232</span></p></body></html>", 0));
        label_12->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">\345\245\207\345\201\266\346\243\200\351\252\214\357\274\232</span></p></body></html>", 0));
        pushButtonConnect->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", 0));
        pushButtonSeriesSet->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256", 0));
        label_13->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245\347\212\266\346\200\201\357\274\232", 0));
        connectStatusLabel->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        connectTerStatusLabe->setText(QString());
        label_14->setText(QApplication::translate("MainWindow", "\346\255\243\345\217\221\351\200\201\357\274\232", 0));
        label_15->setText(QApplication::translate("MainWindow", "\346\235\241", 0));
        label_16->setText(QApplication::translate("MainWindow", "\346\235\241", 0));
        label_17->setText(QApplication::translate("MainWindow", "\345\205\261\345\217\221\351\200\201\357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
