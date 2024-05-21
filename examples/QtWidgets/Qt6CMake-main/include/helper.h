
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QDebug>
#include <QThread>
#include <QMessageBox>
#include <QTimer>

#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#include <iostream>


uint64_t getInt_fromData(QByteArray data);
QByteArray getHex_fromInt(uint64_t value, int bytes);
QByteArray getHex_fromStr(int value, int bytes);