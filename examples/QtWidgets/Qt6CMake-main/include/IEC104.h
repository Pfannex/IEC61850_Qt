#pragma

#include <QObject>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QDebug>
#include <QThread>
#include <QMessageBox>
#include <QTimer>
#include <QTime>
#include <QtWidgets/QListWidget>

#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#include <iostream>
#include <cmath>
#include <helper.h>
#include <format>

#ifndef IEC104_Server_H
#define IEC104_Server_H
//#############################################################################
// TCP Socket
//#############################################################################

class IEC104_Server : public QObject
{
    Q_OBJECT

public:
    explicit IEC104_Server(QObject* parent = 0);

    void open(quint16 port);
    void close();
    bool socketOnline = false;

    //Server
public slots:
    void newConnection();
signals:
    void do_write104Log(QString txt, QColor fColor, QColor bColor);

    //Sockts
public slots:
    void disconnected();
    void readyRead();
    void readHandle(QByteArray data);
    void errorOccurred();
    void write(QByteArray data);

    void S_FrameHandle(QByteArray data);
    void U_FrameHandle(QByteArray data);
    void I_FrameHandle(QByteArray data);

    void send_TESTFR();

private:
    QTcpServer* server104;
    QTcpSocket* socket104;
    quint16 rx_count = 0;
    quint16 tx_count = 0;

    //void appendToSocketList(QTcpSocket* socket);

    //Helper
    QColor color_out = QColor(84, 130, 53, 255);
    QColor color_outSub = QColor(169, 208, 142, 255);
    QColor color_in = QColor(48.84, 150, 255);
    QColor color_inSub = QColor(142, 168, 219, 255);

};

#endif