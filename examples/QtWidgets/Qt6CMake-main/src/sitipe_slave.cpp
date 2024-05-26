#include <sitipe_slave.h>
//https://github.com/manfredipist/QTcpSocket/blob/master/QTCPServer/mainwindow.cpp

//#############################################################################
// SITIPE slave handling
//#############################################################################

SITIPE_Slave::SITIPE_Slave(QObject* parent) :
    QObject(parent)
{
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(KeepAllive()));
    timer->start(200);
}

void SITIPE_Slave::open(quint16 port) {
    qDebug() << "--------------------------------------------------------";
    qDebug() << "[SITIPE_Slave::open()]";

    serverSTS = new QTcpServer(this);
    connect(serverSTS, &QTcpServer::newConnection, this, &SITIPE_Slave::newConnection);
    serverSTS->setMaxPendingConnections(1);

    if (serverSTS->listen(QHostAddress::Any, port)) {
        emit do_writeSTSLog("server is listening on Port: " + QString::number(port),
            Qt::white, Qt::blue);
        qDebug() << "server is listening on Port: " << port;
    }
    else {
        emit do_writeSTSLog("Unable to start the server!",
            Qt::white, Qt::blue);
        qDebug() << "Unable to start the server";
    }
}

void SITIPE_Slave::close() {
    qDebug() << "--------------------------------------------------------";
    qDebug() << "[IEC104_Server::close()]";
    emit do_writeSTSLog("server closing..",
        Qt::white, Qt::blue);
    socketOpen = false;
    serverSTS->close();
    serverSTS->deleteLater();
}

void SITIPE_Slave::newConnection() {
    qDebug() << "--------------------------------------------------------";
    qDebug() << "[SITIPE_Slave::newConnection()]";
    while (serverSTS->hasPendingConnections()) {
        socketSTS = serverSTS->nextPendingConnection();
        socketOpen = true;

        connect(socketSTS, &QTcpSocket::readyRead, this, &SITIPE_Slave::readyRead);
        connect(socketSTS, &QTcpSocket::disconnected, this, &SITIPE_Slave::disconnected);
        connect(socketSTS, &QAbstractSocket::errorOccurred, this, &SITIPE_Slave::errorOccurred);

        QString socStr = QString::number(socketSTS->socketDescriptor());
        emit do_writeSTSLog("socket " + socStr + " connected",
            Qt::white, Qt::blue);
        qDebug() << "INFO :: new client: " << socketSTS->socketDescriptor();



    }
}



//#############################################################################
// SITIPE client socket handling
//#############################################################################

void SITIPE_Slave::disconnected() {
}

void SITIPE_Slave::readyRead() {
    qDebug() << "--------------------------------------------------------";
    qDebug() << "[SITIPE_Slave::readyRead()]";

    QByteArray data;
    while (socketSTS->bytesAvailable())
    {
        data = socketSTS->read(6);

        int size = getInt_fromData(data.mid(2, 4));
        //qDebug() << "Size: " << size;

        data.append(socketSTS->read(size));

        //emit do_writePTMLog(data.toHex());
        //emit do_receiveFrame(data);
    }
    emit do_writeSTSLog("dataRead: " + QString(data.toHex()),
        color_in, Qt::white);
    qDebug() << "dataRead: " << QString(data.toHex());

    int type = getInt_fromData(data.mid(0, 2));

    if (firstInit){
        if (type == 0) {
            qDebug() << "  receive type 0000";
            qDebug() << "  send SlaveInitResponse_0004";
            data.clear();
            data = QByteArray::fromHex(
                "00040000002300000000e278e05a5c43"
                "d8000000000000000000000100000005"
                "303032303100000000");
            emit write(data);

            //QThread::msleep(100);
            
            qDebug() << "  send SlaveInitResponse_0006";
            data.clear();
            data = QByteArray::fromHex(
                "00060000005200000000e2790f6bacb9"
                "80000000000000000001000000053030"
                "32303101000000300000000000000000"
                "00000000000000000000000000000000"
                "00000000000000000000000000000000"
                "0000000000000000"
            );
            emit write(data);


        }
        else if (type == 10) {
            qDebug() << "  receive type 0010";
            firstInit = false;
            emit do_sendToMaster(data, firstInit);
        }
    }
    else {
        qDebug() << "  connected send normal";
        emit do_sendToMaster(data, false);
    }
}

void SITIPE_Slave::errorOccurred() {
}

void SITIPE_Slave::write(QByteArray data) {
    if (socketOpen) {
        qDebug() << "--------------------------------------------------------";
        qDebug() << "[SITIPE_Slave::write(QByteArray data)]";

        socketSTS->setSocketOption(QAbstractSocket::LowDelayOption, 1);

        socketSTS->write(data);
        socketSTS->flush();

        emit do_writeSTSLog("dataWrite: " + QString(data),
            color_out, Qt::white);
        qDebug() << "dataWrited: " << QString(data);
    }else
        qDebug() << "NO dataWrite Slave Socket closed";

}

void SITIPE_Slave::keepAlive() {
    if (!firstInit){
        QByteArray data = QByteArray::fromHex(
            "00050000001000000000E1F6931D3888"
            "980000000000");
        write(data);
    }
}



