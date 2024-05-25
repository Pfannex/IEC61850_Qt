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

#ifndef SITIPE_Slave_H
#define SITIPE_Slave_H
//#############################################################################
// SITIPE Slave Server
//#############################################################################



class SITIPE_Slave : public QObject
{
    Q_OBJECT

public:
    explicit SITIPE_Slave(QObject* parent = 0);

    void open(quint16 port);
    void close();

    //Server
public slots:
    void newConnection();
signals:
    void do_writeSTSLog(QString txt, QColor fColor, QColor bColor);

    //Sockts
public slots:
    void disconnected();
    void readyRead();
    void errorOccurred();
    void write(QByteArray data);
    void KeepAllive();

private:
    QTcpServer* serverSTS;
    QTcpSocket* socketSTS;
    bool socketOpen = false;

    struct Header {
        int type;
        int size;
        uint64_t ts_sec;
        uint64_t ts_ms;
        QDateTime ts;
        QString str_ts;
    };
    void receiveFrame(QByteArray data);
    bool getHeader(QByteArray data, Header& h);


    //void appendToSocketList(QTcpSocket* socket);

    //Helper
    QColor color_out = QColor(84, 130, 53, 255);
    QColor color_outSub = QColor(169, 208, 142, 255);
    QColor color_in = QColor(48.84, 150, 255);
    QColor color_inSub = QColor(142, 168, 219, 255);

};

#endif