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
    void keepAlive();

signals:
    void do_writeSTSLog(QString txt, QColor fColor, QColor bColor);
    void do_sendToMaster(QByteArray data, bool firstInit);

    //Sockts
public slots:
    void disconnected();
    void readyRead();
    void errorOccurred();
    void readHandle(QByteArray data);
    void write(QByteArray data);

private:
    QTcpServer* serverSTS;
    QTcpSocket* socketSTS;
    bool socketOpen = false;
    bool firstInit = true;

 

    //void appendToSocketList(QTcpSocket* socket);

    //Helper
    QColor color_out = QColor(84, 130, 53, 255);
    QColor color_outSub = QColor(169, 208, 142, 255);
    QColor color_in = QColor(48.84, 150, 255);
    QColor color_inSub = QColor(142, 168, 219, 255);

};

#endif