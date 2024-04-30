#include <QObject>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QDebug>
#include <QThread>
#include <QMessageBox>
#include <QTimer>
#include <QTime>


#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#include <iostream>
#include <cmath>
#include <helper.h>
#include <format>


//#############################################################################
// TCP Socket
//#############################################################################

#ifndef TcpSocket_H
#define TcpSocket_H
class TcpSocket : public QObject
{
    Q_OBJECT

public:
    explicit TcpSocket(QObject* parent = 0);

    void doConnect(QString ip, int port);
    void doDisconnect();


signals:
    void do_writeTCPLog(QString txt, QColor fColor, QColor bColor);
    void do_setConnectionStatus(bool value);
    void do_receiveFrame(QByteArray data);

signals:
    void transmit_to_gui(bool value);

private slots:
    void receive_from_gui(bool value);

public slots:
    void connected();
    void disconnected();
    void destroyed();
    void bytesWritten(qint64 bytes);
    void readyRead();
    void write(QByteArray data);

private:
    QTcpSocket* socket;
};
#endif

#ifndef SITIPE_Master_H
#define SITIPE_Master_H


//#############################################################################
// SITIPE PTM
//#############################################################################
class SITIPE_PTM : public QObject
{
    Q_OBJECT

public:
    explicit SITIPE_PTM(QObject* parent = 0);
    void add(int ptmID);
    void del(int index);
    int getIndexfromPtmID(int ptmID);
    void printPTM(int ptmID);

private:
    struct IOSet {
        bool value = false;
    };
    struct PTM {
        int ptm_index;
        int ptmID;
        bool connected = false;
        QString str_ptmID;
        IOSet io[48];
    };

public:
    QList<PTM> id;

public:
};

//#############################################################################
// SITIPE Master
//#############################################################################
class SITIPE_Master : public QObject
{
    Q_OBJECT



public:
    explicit SITIPE_Master(QObject* parent = 0);
    void masterQuit_0003(int reason);
    void masterTransmit_0001(int ptmIndex, int ptmID, int channel, bool value);
    SITIPE_PTM ptm;
    int activePTM = 0;
    int activePTM_index = 0;

signals:
    void sendFrame(QByteArray data);
    void do_setIO(int activePTM_index);
    void do_writeTCPLog(QString txt, QColor fColor, QColor bColor);
    void do_setPTMConnectionStatus(bool value);


public slots:
    void receiveFrame(QByteArray data);
    void KeepAllive();
    void updateSocketState(bool online);
    void setIO(int channel, bool value);
    void KITT();
    void TEST();
    void ptm_change(int ptmID);

private:
    const int MASTER_STOPPED = 0;
    const int MASTER_RESTART = 1;

    const int SLAVE_STOPPED = 0;
    const int MASTER_REFUSED = 1;
    const int MASTER_TIMEOUT = 2;
    const int MASTER_QUIT = 3;
    const int GENERIC_TCP_ERROR = 4;

    struct Header {
        int type;
        int size;
        uint64_t ts_sec;
        uint64_t ts_ms;
        QDateTime ts;
        QString str_ts;
    };

 
    bool socketOnline = false;
    bool slaveConnected = false;

    //Master->Slave
    void masterInitRequest_0000();
    void masterKeepAlive_0002();
    void masterOutputs_0010();
    //Slave->Master
    void slaveInitResponse_0004(QByteArray data, Header h);
    void slaveKeepAlive_0005(QByteArray data, Header h);
    void slavePTMStatus_0006(QByteArray data, Header h);
    void slaveTransmit_0007(QByteArray data, Header h);
    void slaveQuit_0008(QByteArray data, Header h);
    void slaveAcceptedPTMUpdate_0009(QByteArray data, Header h);
    
    //Helper
    bool getHeader(QByteArray data, Header &h);
    QColor color_master = QColor(84, 130, 53, 255);
    QColor color_masterSub = QColor(169, 208, 142, 255);
    QColor color_slave = QColor(48.84, 150, 255);
    QColor color_slaveSub = QColor(142, 168, 219, 255);

};
#endif

