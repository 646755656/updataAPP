#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QSerialPort>
#include <QSerialPortInfo>
#include "series.h"
#include <QTimer>

#define ONELENGTH 1024       //默认单次发送长度

#define TIME100MS   1
#define TIME200MS   2
#define TIME500MS   5
#define TIME1S      10
#define TIME2S      20
#define TIME5S      50
#define TIME10S     100
#define TIME1MIN    600
#define TIME10MIN   6000

namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    //下面几个无需定义，ui界面修改其objectName后直接使用
//    QComboBox *comboSeriePort;
//    QComboBox *comboBautRate;
//    QComboBox *comboStopBit;
//    QComboBox *comboDataBit;
//    QComboBox *comboParityBit;



//    QPushButton



private slots:

    void on_pushButtonConnect_clicked();

    void on_pushButtonSeriesSet_clicked();

    void on_browserButton_clicked();

    void on_upgrateButton_clicked();

    void on_ConnectButton_clicked();

    void handleTimeout();                           //超时处理函数

    void on_oneSizeEdit_returnPressed();

    void TimerUpdate_COM();
private:
    Ui::MainWindow *ui;
    QSerialPort *my_serialport = nullptr;             //串口参数
    QTimer *timer = nullptr;
    QTimer *timerCOM = nullptr;

    QByteArray *sendHexByte = nullptr;                            //升级程序的16进制数据
    char * binByte = nullptr;
    qint64 upgradeSize = 0;
    Series classCRC;//调用外部类成员时，实例化一个对象
    QByteArray recData;//读取到的原始叠加后的数据

    QString FilePath = nullptr;


    unsigned char terminalOnlineFlag = 0;           //终端在线标志
    unsigned char sendConnectOrderFlag = 0;         //发送终端连接命令标志
    unsigned int SeriesTimeout = 0;                 //串口判断超时
    unsigned int DelayTime = 0;                     //串口收到数据有延时时间
    unsigned char TimeoutNum = 0;                   //超时计数器
    unsigned short recLength = 0;                   //接收到的数据长度
    unsigned short allSendNum = 0;                  //共要发送升级程序的条书
    unsigned short lastLefByte = 0;                 //最后一条剩余的未发送数据的长度
    unsigned short oneSendLen = 0;                  //每条发送的数据长度
    unsigned char sendUpgradeProFlag = 0;           //发送终端升级的标志
    unsigned short sendingNum = 1;                   //当前正在发送的条数
    unsigned int recUpgradeTimeout = 0;             //接收升级超时定时
    unsigned char UpgradeTimeoutNum = 0;            //接收升级超时次数
    unsigned char TerminalAddr[20] = {0};           //终端地址
    unsigned char TerminalAddrLength = 0;                   //终端地址长度


    void DetectSeriesPortInit();
    void BautSelectSetInit();
    void StopBitInit();
    void DataBitInit();
    void ParityBitInit();
    void closeSerialPort();
//    void showStatusMessage(const QString &category, const QString &content);
    void showStatusMessage(const QString &content);
    void receiveData();
    void receiveResponeData();
    void sendUpgradePro();
    void receiveUpgradeTimeout();
    void receiveConnectTimeout();
    void sendConnectPro();


};



#endif // MAINWINDOW_H
