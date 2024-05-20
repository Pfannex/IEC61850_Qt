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

//#############################################################################
// TCP Socket
//#############################################################################

class IEC104_Server //: public QObject
{
   // Q_OBJECT

public:
    //IEC104_Server(QObject* parent = 0);

    void start();

//public slots:
    //void newConnection();

private:
    //QTcpSocket* socket;
};
