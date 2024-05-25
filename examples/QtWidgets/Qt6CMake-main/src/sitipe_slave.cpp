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
    timer->start(300);


    //foreach(QTcpSocket * socket, connection_set) {
        //if (socketSTS != NULL) socketSTS->close();
        //socketSTS->deleteLater();
    //}
    //serverSTS->close();
    //serverSTS->deleteLater();
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
void SITIPE_Slave::KeepAllive() {
    if (socketOpen) {
        qDebug() << "--------------------------------------------------------";
        qDebug() << "[SITIPE_Slave::KeepAllive()]";

        QByteArray data = QByteArray::fromHex(
                "0005000000100000"
                "0000E1F6931D3888"
                "980000000000");

            write(data);
    }
    //masterKeepAlive_0002();


}


//#############################################################################
// SITIPE client socket handling
//#############################################################################
/*
void IEC104_Server::appendToSocketList(QTcpSocket* socket){
    qDebug() << "--------------------------------------------------------";
    qDebug() << "[IEC104_Server::appendToSocketList(QTcpSocket* socket)";

    connection_set.insert(socket);
    connect(socket, &QTcpSocket::readyRead, this, &IEC104_Server::readyRead);
    connect(socket, &QTcpSocket::disconnected, this, &IEC104_Server::disconnected);
    connect(socket, &QAbstractSocket::errorOccurred, this, &IEC104_Server::errorOccurred);

    QString socStr = QString::number(socket->socketDescriptor());
    emit do_writeSTSLog("socket " + socStr + " connected",
        Qt::white, Qt::blue);
    qDebug() << "INFO :: new client: " << socket->socketDescriptor();
}
*/

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

    receiveFrame(data);
}

void SITIPE_Slave::errorOccurred() {
}

void SITIPE_Slave::write(QByteArray data) {
    qDebug() << "--------------------------------------------------------";
    qDebug() << "[SITIPE_Slave::write(QByteArray data)]";

    socketSTS->setSocketOption(QAbstractSocket::LowDelayOption, 1);

    socketSTS->write(data);
    socketSTS->flush();

    emit do_writeSTSLog("dataWite: " + QString(data),
        color_out, Qt::white);
    qDebug() << "dataWited: " << QString(data);

}

//#############################################################################
// SITIPE Master handling
//#############################################################################

void SITIPE_Slave::receiveFrame(QByteArray data) {
    qDebug() << "--------------------------------------------------------";
    qDebug() << "[SITIPE_Slave::receiveFrame(QByteArray data)]";

    Header h;

    if (getHeader(data, h)) {
        /*
        qDebug() << "------------------------------";
        qDebug() << "Typ:     " << h.type;
        qDebug() << "Size:    " << h.size;
        //qDebug() << "ts_sec:  " << h.ts_sec;
        //qDebug() << "ts_ms:   " << h.ts_ms;
        qDebug() << h.str_ts;
        qDebug() << "------------------------------";
        */
        if (h.type == 0) {
            qDebug() << "Type 0000";
            QByteArray data = QByteArray::fromHex(
                "00040000002C0000"
                "0000E1F13D43CBBF"
                "4000000000000000"
                "0000000100000005"
                "3030303438");

            write(data);

        }
        else if (h.type == 1)
            qDebug() << "Type 0001";
        else if (h.type == 2)
            qDebug() << "Type 0002";
        else if (h.type == 3)
            qDebug() << "Type 0003";
        else if (h.type == 10)
            qDebug() << "Type 0010";
        else
            qDebug() << "unknown type";
            //emit do_writePTMLog("unknown type!", Qt::yellow, Qt::red);
    }
    else {
        qDebug() << "FrameSize NOT OK";
        //emit do_writePTMLog("FrameSize NOT OK", Qt::yellow, Qt::red);
    }
}

//#############################################################################
// Helper
//#############################################################################

bool SITIPE_Slave::getHeader(QByteArray data, Header& h) {
    bool frameOK = false;

    h.size = getInt_fromData(data.mid(2, 4)) + 6;
    if (h.size != data.size()) {
        qDebug() << "Frame size ERROR!";
        return frameOK;
    }
    else {
        frameOK = true;

        h.type = getInt_fromData(data.mid(0, 2));
        h.ts_sec = getInt_fromData(data.mid(6, 8));
        h.ts_ms = getInt_fromData(data.mid(14, 8));

        h.ts.setMSecsSinceEpoch((h.ts_sec * 1000) + (h.ts_ms * pow(2, -64) * 1000));
        h.str_ts = h.ts.toString("dd:MM:yyyy hh:mm:ss,zzz");
    }
    /*
    qDebug() << "+++++++++++++++++++++";
    qDebug() << "Typ:    " << h.type;
    qDebug() << "Size:   " << h.size;
    qDebug() << "ts_sec: " << h.ts_sec;
    qDebug() << "ts_ms:  " << h.ts_ms;
    */
    return frameOK;

}
