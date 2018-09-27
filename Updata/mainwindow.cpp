#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QIcon>
#include <QFile>
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>
#include <QStandardPaths>
#include "series.h"
#include <QTextStream>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    my_serialport= new QSerialPort();

    this->setMinimumSize(520,370);//设置最小窗口尺寸
//    this->setMaximumSize(550,370);
   // setFixedSize(520,370);
//    setWindowState(Qt::WindowMinimized);
//    setWindowState(Qt::WindowMaximized);
//    setFixedSize(size());
//    setWindowIcon(QIcon("/new/icon/icon.jpeg"));
    setWindowTitle(tr("Remote Upgrade"));

    DetectSeriesPortInit();             //串口检测
    BautSelectSetInit();                //波特率初始化
    StopBitInit();                      //停止位初始化
    DataBitInit();                      //数据位初始化
    ParityBitInit();

    ui->connectStatusLabel->setText(tr("串口未打开"));
    ui->connectTerStatusLabe->setText((tr("设备未连接")));
    ui->pushButtonSeriesSet->setEnabled(false);

    timer = new QTimer(this);
    timer->start(100);                  //定时100ms
    connect(timer, SIGNAL(timeout()), this,SLOT(handleTimeout()));

    connect(my_serialport, &QSerialPort::readyRead, this, &MainWindow::receiveData);//接收槽

    timerCOM = new QTimer(this);      //建立串口读写超时定时器
    connect(timerCOM,SIGNAL(timeout()),this,SLOT(TimerUpdate_COM()));//必须要有的

    //    QIcon icon;
    //    icon.addFile(tr("D:\Update_APP\Updata.png"));
    //    ui->openSeriesButton->setIcon(icon);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete[] binByte;
}



void MainWindow::on_pushButtonConnect_clicked()
{

    if(my_serialport->isOpen())//如果当前串口是打开的，则关闭
    {
        closeSerialPort();      //关闭串口
        ui->pushButtonConnect->setText(tr("打开串口")); //显示打开串口
        ui->pushButtonSeriesSet->setEnabled(false);
    }
    else    //打开串口
    {
        my_serialport->setPortName(ui->comboSeriePort->currentText());
        my_serialport->setBaudRate(ui->comboBautRate->currentText().toInt());
//        my_serialport->setBaudRate(static_cast<QSerialPort::BaudRate>(ui->comboBautRate->itemData(ui->comboBautRate->currentIndex()).toInt()));
        my_serialport->setDataBits(static_cast<QSerialPort::DataBits>(ui->comboDataBit->itemData(ui->comboDataBit->currentIndex()).toInt()));
        my_serialport->setParity(static_cast<QSerialPort::Parity>(ui->comboParityBit->itemData(ui->comboParityBit->currentIndex()).toInt()));
        my_serialport->setStopBits(static_cast<QSerialPort::StopBits>(ui->comboStopBit->itemData(ui->comboStopBit->currentIndex()).toInt()));
        my_serialport->setFlowControl(QSerialPort::NoFlowControl);
        if (my_serialport->open(QIODevice::ReadWrite))
        {
            showStatusMessage(tr("串口打开成功"));
            ui->pushButtonConnect->setText(tr("关闭串口"));
            ui->pushButtonSeriesSet->setEnabled(true);
        }
        else
        {
            showStatusMessage(tr("打开串口失败"));
        }
    }

//    connect(my_serialport,SIGNAL(readyRead()),this,SLOT(my_readuart()));

//    ui->pushButton->setEnabled(false);//禁止打开串口按钮
//    ui->pushButton_3->setEnabled(true);//允许关闭串口按钮

//    my_serialport->setBaudRate(ui->comboBautRate->currentText().toInt());
//    switch(ui->comboDataBit->currentText().toInt())//数据位
//    {
//        case 8:
//            my_serialport->setDataBits(QSerialPort::Data8);
//            break;
//        case 7:
//            my_serialport->setDataBits(QSerialPort::Data7);
//            break;
//        case 6:
//            my_serialport->setDataBits(QSerialPort::Data6);
//            break;
//        case 5:
//            my_serialport->setDataBits(QSerialPort::Data5);
//            break;
//        default:
//            my_serialport->setDataBits(QSerialPort::UnknownDataBits);
//        break;
//    }

//    switch(ui->comboStopBit->currentIndex())//停止位
//    {
//        case 0:
//            my_serialport->setStopBits(QSerialPort::OneStop);
//            break;
//        case 1:
//            my_serialport->setStopBits(QSerialPort::OneAndHalfStop);
//            break;
//        case 2:
//            my_serialport->setStopBits(QSerialPort::OneStop);
//            break;
//        default:
//            my_serialport->setStopBits(QSerialPort::UnknownStopBits);
//            break;
//    }

//    switch(ui->comboParityBit->currentIndex())      //奇偶检验位
//    {
//        case 0:
//            my_serialport->setParity(QSerialPort::NoParity);
//            break;
//        case 1://奇校验
//            my_serialport->setParity(QSerialPort::OddParity);
//            break;
//        case 2://偶校验
//            my_serialport->setParity(QSerialPort::EvenParity);
//            break;
//        default:
//            my_serialport->setParity(QSerialPort::UnknownParity);
//            break;
//    }
}

void MainWindow::DetectSeriesPortInit()
{
//        comboSeriePort = new QComboBox();
    ui->comboSeriePort->clear();
    const auto infos = QSerialPortInfo::availablePorts();
    if(infos.size() == 0)
    {
        ui->comboSeriePort->addItem(tr("None"));
        ui->pushButtonConnect->setEnabled(false);
    }
    else
    {
        foreach(const QSerialPortInfo &info, infos)
        {
            QSerialPort serial;
            serial.setPort(info);
            if(serial.open(QIODevice::ReadWrite))
            {
                ui->pushButtonConnect->setEnabled(true);
                ui->comboSeriePort->addItem(info.portName());
                serial.close();
            }

//        qDebug() << "Name : " << info.portName();
//        qDebug() << "Description : " << info.description();
//        qDebug() << "Manufacturer: " << info.manufacturer();
//        qDebug() << "Serial Number: " << info.serialNumber();
//        qDebug() << "System Location: " << info.systemLocation();
        }
    }
}

void MainWindow::BautSelectSetInit()
{
//    comboBaut = new QComboBox();//波特率下拉框
//    ui->comboBaut->setEditable(true);//可在下拉框中输入

//    ui->comboBoxRate->addItem(QStringLiteral("9600"), QSerialPort::Baud9600);

    QStringList baudList;//波特率
    baudList<<"4800"<<"9600"<<"76800"<<"115200";

    ui->comboBautRate->addItems(baudList);
    ui->comboBautRate->setCurrentIndex(3);

//    ui->comboBautRate->addItem(QWidget::tr("2400"));
//    ui->comboBautRate->addItem(QWidget::tr("4800"));
//    ui->comboBautRate->addItem(QWidget::tr("9600"));
//    ui->comboBautRate->addItem(QWidget::tr("14400"));
//    ui->comboBautRate->addItem(QWidget::tr("19200"));
//    ui->comboBautRate->addItem(QWidget::tr("38400"));
//    ui->comboBautRate->addItem(QWidget::tr("57600"));
//    ui->comboBautRate->addItem(QWidget::tr("76800"));
//    ui->comboBautRate->addItem(QWidget::tr("115200"));
//    ui->comboBautRate->addItem(QWidget::tr("128000"));
//    ui->comboBautRate->addItem(QWidget::tr("256000"));
//    ui->comboBautRate->addItem(QWidget::tr("460800"));

//    ui->comboBaut->setCurrentText(QWidget::tr("115200"));
    //ui->comboBaut->setCurrentIndex(8);//设置波特率下拉菜单默认显示115200
}

void MainWindow::StopBitInit()
{
//    comboStopBit = new QComboBox();//停止位下拉框
//    ui->comboStopBit->addItem(QWidget::tr("1"));
//    ui->comboStopBit->addItem(QWidget::tr("1.5"));
//    ui->comboStopBit->addItem(QWidget::tr("2"));

    ui->comboStopBit->addItem(QStringLiteral("1"), QSerialPort::OneStop);
    ui->comboStopBit->addItem(QStringLiteral("1.5"), QSerialPort::OneAndHalfStop);
    ui->comboStopBit->addItem(QStringLiteral("2"), QSerialPort::TwoStop);
    ui->comboStopBit->setCurrentIndex(0);//默认显示1
//    ui->comboStopBit->setCurrentText(QWidget::tr("1"));
}

void MainWindow::DataBitInit()
{
//    comboDataBit = new QComboBox();//数据位下拉框
//    ui->comboDataBit->addItem(QWidget::tr("8"));

    ui->comboDataBit->addItem(QStringLiteral("8"), QSerialPort::Data8);
    ui->comboDataBit->addItem(QStringLiteral("7"), QSerialPort::Data7);
    ui->comboDataBit->addItem(QStringLiteral("6"), QSerialPort::Data6);
    ui->comboDataBit->addItem(QStringLiteral("5"), QSerialPort::Data5);
    ui->comboDataBit->setCurrentIndex(0);//8设定为默认
}

void MainWindow::ParityBitInit()
{
//    comboParityBit = new QComboBox();
//    ui->comboParityBit->addItem(QWidget::tr("无"));

    ui->comboParityBit->addItem(tr("None"), QSerialPort::NoParity);
    ui->comboParityBit->addItem(tr("Even"), QSerialPort::EvenParity);
    ui->comboParityBit->addItem(tr("Odd"), QSerialPort::OddParity);
    ui->comboParityBit->addItem(tr("Mark"), QSerialPort::MarkParity);
    ui->comboParityBit->addItem(tr("Space"), QSerialPort::SpaceParity);

    ui->comboParityBit->setCurrentIndex(0);
}


void MainWindow::closeSerialPort()
{
    my_serialport->close();
    showStatusMessage(tr("串口已关闭"));
}

void MainWindow::showStatusMessage(const QString &content)
{
//    ui->labelTipCategory->setText(category);
    ui->connectStatusLabel->setText(content);
}


void MainWindow::on_pushButtonSeriesSet_clicked()
{
    if(my_serialport->isOpen()) //串口已打开
    {
        my_serialport->setPortName(ui->comboSeriePort->currentText());
        my_serialport->setBaudRate(ui->comboBautRate->currentText().toInt());
    //  my_serialport->setBaudRate(static_cast<QSerialPort::BaudRate>(ui->comboBautRate->itemData(ui->comboBautRate->currentIndex()).toInt()));
        my_serialport->setDataBits(static_cast<QSerialPort::DataBits>(ui->comboDataBit->itemData(ui->comboDataBit->currentIndex()).toInt()));
        my_serialport->setParity(static_cast<QSerialPort::Parity>(ui->comboParityBit->itemData(ui->comboParityBit->currentIndex()).toInt()));
        my_serialport->setStopBits(static_cast<QSerialPort::StopBits>(ui->comboStopBit->itemData(ui->comboStopBit->currentIndex()).toInt()));
        my_serialport->setFlowControl(QSerialPort::NoFlowControl);
    }
}

void MainWindow::on_browserButton_clicked()
{
    //获取升级文件（bin）名称
    QString upgradeFileName = QFileDialog::getOpenFileName(this,"OpenFile",QStandardPaths::writableLocation(QStandardPaths::DesktopLocation),tr("升级文件 (*.bin *.hex);;所有文件(*.*)"));//获取桌面路径
    if(upgradeFileName.isNull())//未点击文件
    {
//        QMessageBox::information(this,"错误",QWidget::tr("请选择文件"));
        return;
    }
    if(upgradeFileName.isEmpty())//未点击文件
    {
        QMessageBox::information(this,"错误",QWidget::tr("请选择文件"));
        return;
    }

    QFile *upgradeFile = new QFile;
    upgradeFile->setFileName(upgradeFileName);
    bool openOK = upgradeFile->open(QIODevice::ReadOnly);
    if(openOK)//文件打开
    {
        QString *programHex;
        QString toBeShow;

        QFileInfo upgradeInfo = QFileInfo(upgradeFileName);
        upgradeSize = upgradeInfo.size();
        ui->browseFileEdit->clear();
        FilePath = upgradeInfo.absoluteFilePath();
        ui->browseFileEdit->setText(FilePath);    //显示路径

        ui->fileSizeEdit->clear();
        ui->fileSizeEdit->setText(QString::number(upgradeSize/*,10*/)); //  显示文件大小

        QDataStream outdata(upgradeFile);
        outdata.setVersion(QDataStream::Qt_5_6);
 #if 1
        binByte = new char[upgradeSize];
        outdata.readRawData(binByte,upgradeSize);//读出文件到缓存
        sendHexByte = new QByteArray(binByte,upgradeSize);//格式转换
        programHex = new QString(sendHexByte->toHex ().toUpper ());//toUpper把小写字母转化成大写
//        ui->displayBinEdit->appendPlainText(*programHex);//直接显示，没有空格
        for(/*auto*/QString::iterator it = programHex->begin(); it != programHex->end(); ++it)//运行结果和ultra打开的结果一致
        {
            toBeShow.append(*it++).append(*it).append(" ");
        }
        ui->displayBinEdit->appendPlainText(toBeShow);//plaintext中显示数据
#else

        binByte = new char[8192];
        int count = upgradeSize / 8192;
        int leftlen = upgradeSize % 8192;
        if(leftlen > 0)
            count ++;
        QString::iterator it;
        int readlen = 0;
        for(int i = 0; i < count; i++)
        {
            if(i < count - 1)
                readlen = 8192;
            else
                readlen = leftlen;

            upgradeFile->seek(i * 8192);
            outdata.readRawData(binByte,readlen);//读出文件到缓存
            sendHexByte = new QByteArray(binByte,readlen);//格式转换
            programHex = new QString(sendHexByte->toHex ().toUpper ());//toUpper把小写字母转化成大写
            for(/*auto*/it = programHex->begin(); it != programHex->end(); ++it)//运行结果和ultra打开的结果一致
            {
                toBeShow.append(*it++).append(*it).append(" ");
            }
            ui->displayBinEdit->appendPlainText(toBeShow);//plaintext中显示数据
        }
#endif
        upgradeFile->close();
        delete upgradeFile;
    }
    else//打开失败
    {
        QMessageBox::information(this,QWidget::tr("错误"),QWidget::tr("打开文件失败")+upgradeFile->errorString());
        return;
    }
}

void MainWindow::on_upgrateButton_clicked()
{
    if(!my_serialport->isOpen()) //串口未打开
    {
        QMessageBox::warning(this,tr("错误"),tr("请打开串口"));
        return;
    }

    //确定打开升级程序
    if(upgradeSize == 0)
    {
        QMessageBox::warning(this,tr("错误"),tr("请先打开升级程序"));
        return;
    }
    //判断是否已连接
    if(terminalOnlineFlag != 1)
    {
        QMessageBox::warning(this,tr("错误"),tr("请先连接终端设备"));
        return;
    }

    //获取单次发送长度
    if(ui->oneSizeEdit->text().isEmpty())
    {
        oneSendLen = ONELENGTH;
        ui->oneSizeEdit->setText(QString::number(oneSendLen));      //显示
    }
    else
        oneSendLen  = ui->oneSizeEdit->text().toShort();

    allSendNum = 0;
    allSendNum = (unsigned short)(upgradeSize / oneSendLen);
    lastLefByte = upgradeSize % oneSendLen;
    if(lastLefByte > 0)
        allSendNum ++;
    ui->sendAllNumEdit->setText(QString::number(allSendNum));      //显示

    sendUpgradeProFlag = 1;                                     //发送升级程序标志

    UpgradeTimeoutNum = 0;
    sendingNum = 1;
    sendUpgradePro();                                          //发送第1条

    //    my_serialport->write(binByte,upgradeSize);


//    const QString sendString(ui->displayBinEdit->toPlainText());
//    bool ok;
//    QByteArray temp;
//    QStringList list(sendString.simplified().split(" "));
//    for(QString &e : list)
//    {
//        temp.append(e.toInt(&ok, 16) & 0xFF);
//    }
//    if(ok)
//    {
//        my_serialport->write(temp);
//    }
//    else
//    {
//       showStatusMessage(tr("Unknown hexadecimal"));
////       deactiveAuto();
//       QMessageBox::critical(this, tr("Error"), tr("Unknown hexadecimal"));
//    }
}

//向指定终端发送连接数据
void MainWindow::on_ConnectButton_clicked()
{
    //检查串口是否打开
    if(!my_serialport->isOpen())//串口没打开
    {
        QMessageBox::warning(this,tr("错误"),tr("请打开串口"));
        return;
    }

    //读取终端地址
    QString sendAddressString = ui->termialAddrEdit->text();

    if(sendAddressString.isEmpty())
    {
//        QMessageBox::warning(this,tr("错误"),tr("请输入终端地址"));
//        return;
        sendAddressString = "80808080";
    }
    TerminalAddrLength = sendAddressString.size();
    unsigned char i = 0;
    for(i=0;i<TerminalAddrLength;i++)
         TerminalAddr[i] = sendAddressString.at(i).toLatin1();

    if(upgradeSize == 0)    //未打开文件
    {
        QMessageBox::warning(this,tr("错误"),tr("请选择升级程序"));
        return;
    }
    //获取单次发送长度
    if(ui->oneSizeEdit->text().isEmpty())
    {
        oneSendLen = ONELENGTH;
        ui->oneSizeEdit->setText(QString::number(oneSendLen));      //显示
    }
    else
        oneSendLen  = ui->oneSizeEdit->text().toShort();

    allSendNum = (unsigned short)(upgradeSize / oneSendLen);
    lastLefByte = upgradeSize % oneSendLen;
    if(lastLefByte > 0)
        allSendNum ++;
    ui->sendAllNumEdit->setText(QString::number(allSendNum));      //显示

    TimeoutNum = 0;
    sendConnectPro();

//    unsigned short resCRC = 0;  //uchCRCLo和uchCRCHi设置成局部变量
//    resCRC = Series::CRC16(sendBuf,len);
//    sendBuf[len++] = (unsigned char)(resCRC & 0xFF);        //CL
//    sendBuf[len++] = (unsigned char)(resCRC >> 8);        //CH
}

void MainWindow::receiveData()
{
    timerCOM->stop();
    timerCOM->start(500);       //500ms判断数据接收完毕

    recData.append(my_serialport->readAll());


//    ui->fileSizeEdit->setText(QString::number(terminalOnlineFlag/*,10*/)); //  显示文件大小

//    std::string temp(data.toHex().toUpper().toStdString());
//    QString toBeShow;
//    for(auto it = temp.begin(); it != temp.end(); ++it)
//    {
//        toBeShow.append(*it++).append(*it).append(" ");
//    }
//    ui->plainTextEditReceive->appendPlainText(toBeShow);
}
void MainWindow::TimerUpdate_COM()
{
    recLength = 0;
    timerCOM->stop();
    recLength = recData.size();
    if(recLength == 0)
        return;
    SeriesTimeout = 0;
    recUpgradeTimeout = 0;

    receiveResponeData();       //接收应答数据

    recData.clear();

}
void MainWindow::handleTimeout()        //定时器用来计数
{
    SeriesTimeout ++;
    recUpgradeTimeout ++;
    if(sendConnectOrderFlag == 1)
    {
        receiveConnectTimeout();
    }

    if(sendUpgradeProFlag == 1)
    {
        receiveUpgradeTimeout();
    }
}

void MainWindow::sendConnectPro()   //发送连接命令
{
    short i=0,pos=0;
    unsigned short sendLen = 0;              //发送终端连接的数据长度
    unsigned char sendBuf[50] = {0};         //


    sendBuf[sendLen++] = 0x3c;          //起始帧
    sendBuf[sendLen++] = 0x23;          //版本号

    pos = sendLen;
    sendBuf[sendLen++] = 0;             //数据总长度
    sendBuf[sendLen++] = 0;             //数据总长度

    sendBuf[sendLen++] = TerminalAddrLength;       //地址长度
    //地址
    for(i=0;i<TerminalAddrLength;i++)
        sendBuf[sendLen++] = TerminalAddr[i];

    sendBuf[sendLen++] = 1;     //帧号
    sendBuf[sendLen++] = 1;     //指令方向
    sendBuf[sendLen++] = 0xA1;  //指令码
    sendBuf[sendLen++] = 0x30;          //连接终端功能码
    sendBuf[sendLen++] = 2;     //指令版本

    unsigned char datalen = 0,transbuf[5]={0},desbuf[5]={0};

    //数据总长度
    datalen = classCRC.change_DEC_to_HEX(upgradeSize,transbuf);
    classCRC.char_string_right(transbuf,datalen,desbuf,4);
    sendBuf[sendLen++] = desbuf[0];
    sendBuf[sendLen++] = desbuf[1];
    sendBuf[sendLen++] = desbuf[2];
    sendBuf[sendLen++] = desbuf[3];

    //发送总次数
    sendBuf[sendLen++] = allSendNum;

    //单次发送数据长度
    datalen = classCRC.change_DEC_to_HEX(oneSendLen,transbuf);
    classCRC.char_string_right(transbuf,datalen,desbuf,2);
    sendBuf[sendLen++] = desbuf[0];
    sendBuf[sendLen++] = desbuf[1];

    //最后一次发送数据长度
    datalen = classCRC.change_DEC_to_HEX(lastLefByte,transbuf);
    classCRC.char_string_right(transbuf,datalen,desbuf,2);
    sendBuf[sendLen++] = desbuf[0];
    sendBuf[sendLen++] = desbuf[1];

    datalen = classCRC.change_DEC_to_HEX(sendLen + 3,transbuf);     //协议数据长度
    classCRC.char_string_right(transbuf,datalen,desbuf,2);
    sendBuf[pos] = desbuf[0];
    sendBuf[pos+1] = desbuf[1];

    //计算CRC
    classCRC.CRC16(&sendBuf[1],sendLen - 1);
    sendBuf[sendLen++] = classCRC.uchCRCLo;
    sendBuf[sendLen++] = classCRC.uchCRCHi;

    sendBuf[sendLen++] = 0x3e;      //协议尾

    my_serialport->clear();
    my_serialport->write((char *)sendBuf,sendLen);
    sendConnectOrderFlag = 1;       //已发送终端连接命令标志
    SeriesTimeout = 0;
    ui->connectTerStatusLabe->setText((tr("设备未连接")));
}

void MainWindow::receiveConnectTimeout()        //发送连接终端后，超时判断，5s后再次发送连接终端指令，3次
{
    if(SeriesTimeout < TIME5S)     //
        return;
    if(recLength > 7)
        return;
    TimeoutNum ++;
    if(TimeoutNum < 3)
    {
        SeriesTimeout = 0;
        sendConnectPro();
    }
    else
    {
        TimeoutNum = 3;
        sendConnectOrderFlag = 0;
        ui->connectTerStatusLabe->setText((tr("设备连接失败")));
    }
}

void MainWindow::receiveResponeData()         //接收回应数据
{
    unsigned char pos = 16,revd = 0;
    unsigned char charData[100] = {0};
    unsigned int Delay = 0xFFFF * 2;
    //数据长度
    for(unsigned short i=0;i<recLength;i++)
        charData[i] = recData.at(i);

    if(recLength > 200)
        return;
    if((charData[0] != 0x3c) || (charData[1] != 0x23) || (charData[recLength-1] != 0x3E))
        return;

    //CRC判断
    classCRC.CRC16(&charData[1],recLength - 4);
    if((classCRC.uchCRCLo != charData[recLength - 3]) || (classCRC.uchCRCHi != charData[recLength - 2]))
        return;
    //数据长度判断
//    if(charData[4] != recLength - 7)
//        return;
    revd = charData[pos + 2];
    switch(charData[pos])
    {
        case 0x30:
            if(revd == 1)   //应答
            {
                terminalOnlineFlag = 1;
                sendConnectOrderFlag = 0;
                recLength = 0;
                ui->connectTerStatusLabe->setText((tr("设备连接成功")));
            }
            else
            {
                recLength = 0;
                ui->connectTerStatusLabe->setText((tr("设备连接失败")));
                sendConnectPro();
                TimeoutNum = 0;
                SeriesTimeout = 0;
            }
            break;
        case 0x32:
            if(revd == 0)       //升级失败
            {
                ui->connectTerStatusLabe->setText((tr("升级失败")));
                sendUpgradePro();
                return;
            }
            else
            {
                if(sendingNum < allSendNum)
                {
                    QString count = QString().sprintf("接收第%d条成功",sendingNum);
                    ui->connectTerStatusLabe->setText(count);
//                    ui->connectTerStatusLabe->setText((tr("接收成功")));

                    sendingNum ++;
                    UpgradeTimeoutNum = 0;
                    while(--Delay);
                    sendUpgradePro();
                }
                else
                {
                    UpgradeTimeoutNum = 0;
                    ui->connectTerStatusLabe->setText((tr("接收完成")));

                }
                return;
            }
            break;
    }
}

void MainWindow::sendUpgradePro()
{
    unsigned short i = 0, pos = 0;
    unsigned char sendBuf[1200] = {0};
    unsigned short sendLen = 0;              //发送升级程序的数据长度
    unsigned char datalen = 0, transbuf[5] = {0}, desbuf[5] = {0};
    unsigned short length = 0;
    char * Byte = nullptr;

    if(sendingNum > allSendNum)     //发送完毕
    {
        sendUpgradeProFlag = 0;
        return;
    }
//    QString count = QString().sprintf("发送第%d条",sendingNum);
//    ui->connectTerStatusLabe->setText(count);

    if(sendingNum < allSendNum)
        length = oneSendLen;
    else
        length = lastLefByte + 2;   //添加2个字节的结束标志，用来检查程序的完整

#if 1
    QFile upgradeFile(FilePath);
    bool openOK = upgradeFile.open(QIODevice::ReadOnly);
    if(openOK)//文件打开
    {
        QDataStream outdata(&upgradeFile);
        outdata.setVersion(QDataStream::Qt_5_6);
        Byte = new char[1100];

        int seekpos = (sendingNum - 1) * oneSendLen;
        upgradeFile.seek(seekpos);
        outdata.readRawData(Byte,length);//读出文件到缓存
        upgradeFile.close();
    }
#endif

    //发送第一条
    sendBuf[sendLen++] = 0x3c;          //起始帧
    sendBuf[sendLen++] = 0x23;          //版本号

    pos = sendLen;
    sendBuf[sendLen++] = 0;             //数据总长度
    sendBuf[sendLen++] = 0;             //数据总长度

    sendBuf[sendLen++] = TerminalAddrLength;       //地址长度
    //地址
    for(i=0;i<TerminalAddrLength;i++)
        sendBuf[sendLen++] = TerminalAddr[i];

    sendBuf[sendLen++] = 1;     //帧号
    sendBuf[sendLen++] = 1;     //指令方向
    sendBuf[sendLen++] = 0xA1;  //指令码
    sendBuf[sendLen++] = 0x32;          //连接终端功能码
    sendBuf[sendLen++] = 2;     //指令版本

    datalen = classCRC.change_DEC_to_HEX(sendingNum,transbuf);  //当前正在发送的第几条
    classCRC.char_string_right(transbuf,datalen,desbuf,2);
    sendBuf[sendLen++] = desbuf[0];
    sendBuf[sendLen++] = desbuf[1];

    datalen = classCRC.change_DEC_to_HEX(length,transbuf);  //数据段长度
    classCRC.char_string_right(transbuf,datalen,desbuf,2);
    sendBuf[sendLen++] = desbuf[0];
    sendBuf[sendLen++] = desbuf[1];

    //升级程序部分
#if 1
    if(sendingNum < allSendNum)                     //不是最后一次发送
    {
        for(i = 0; i < oneSendLen; i++)
            sendBuf[sendLen++] = Byte[i];
    }
    else if(sendingNum == allSendNum)               //最后一次
    {
        for(i=0;i<lastLefByte;i++)
            sendBuf[sendLen++] = Byte[i];
        sendBuf[sendLen++] = 0xAA;      //最后添加两个字节的结束标志
        sendBuf[sendLen++] = 0xAA;
    }
#else
    unsigned int startByte = (sendingNum - 1) * oneSendLen;
    if(sendingNum < allSendNum)                     //不是最后一次发送
    {
        for(i = 0; i < oneSendLen; i++)
            sendBuf[sendLen++] = binByte[startByte + i];
    }
    else if(sendingNum == allSendNum)               //最后一次
    {
        for(i=0;i<lastLefByte;i++)
            sendBuf[sendLen++] = binByte[startByte + i];
        sendBuf[sendLen++] = 0xAA;      //最后添加两个字节的结束标志
        sendBuf[sendLen++] = 0xAA;
    }
#endif
    datalen = classCRC.change_DEC_to_HEX(sendLen + 3,transbuf);     //协议数据长度
    classCRC.char_string_right(transbuf,datalen,desbuf,2);
    sendBuf[pos] = desbuf[0];
    sendBuf[pos+1] = desbuf[1];

    //计算CRC
    classCRC.CRC16(&sendBuf[1],sendLen - 1);
    sendBuf[sendLen++] = classCRC.uchCRCLo;
    sendBuf[sendLen++] = classCRC.uchCRCHi;

    sendBuf[sendLen++] = 0x3e;      //协议尾

    my_serialport->clear();
    my_serialport->write((char*)sendBuf,sendLen);

    ui->sendingNumEdit->setText(QString::number(sendingNum));
    recUpgradeTimeout = 0;
    recLength = 0;

}

void MainWindow::receiveUpgradeTimeout()        //发送升级程序，等待接收回应
{
    if(recUpgradeTimeout < (TIME5S * 3))     //
        return;
    if(recLength > 7)
        return;
    UpgradeTimeoutNum ++;
    if(UpgradeTimeoutNum < 3)
    {
        recUpgradeTimeout = 0;
        sendUpgradePro();
    }
    else
    {
//        recUpgradeTimeout = 0;
//        sendingNum ++;
//        sendUpgradePro();
        UpgradeTimeoutNum = 3;
        sendUpgradeProFlag = 0;
        ui->connectTerStatusLabe->setText((tr("接收超时")));
    }
}


void MainWindow::on_oneSizeEdit_returnPressed()     //输入单次发送字节数，按下回车，计算需要发送多少次
{
    //获取单次发送长度
    if(ui->oneSizeEdit->text().isEmpty())
    {
        oneSendLen = 1024;
        ui->oneSizeEdit->setText(QString::number(oneSendLen));      //显示
    }
    else
        oneSendLen  = ui->oneSizeEdit->text().toShort();

    allSendNum = (unsigned short)(upgradeSize / oneSendLen);
    lastLefByte = upgradeSize % oneSendLen;
    if(lastLefByte > 0)
        allSendNum ++;
    ui->sendAllNumEdit->setText(QString::number(allSendNum));      //显示
}

