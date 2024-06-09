#include <IEC104.h>
//https://github.com/manfredipist/QTcpSocket/blob/master/QTCPServer/mainwindow.cpp

//#############################################################################
// SITIPE server handling
//#############################################################################

IEC104_Server::IEC104_Server(QObject* parent) :
    QObject(parent)
{
    server104 = new QTcpServer(this);
    connect(server104, &QTcpServer::newConnection, this, &IEC104_Server::newConnection);
    server104->setMaxPendingConnections(1);

    //foreach(QTcpSocket * socket, connection_set) {
        //if (socket104 != NULL) socket104->close();
        //socket104->deleteLater();
    //}
    //server104->close();
    //server104->deleteLater();
}


void IEC104_Server::open(quint16 port) {
    qDebug() << "--------------------------------------------------------";
    qDebug() << "[IEC104_Server::open()]";
    //server104->close();

    if (server104->listen(QHostAddress::Any, port)) {
        emit do_write104Log("server is listening on Port: " + QString::number(port),
            Qt::white, Qt::blue);
        qDebug() << "server is listening on Port: " << port;
    }
    else {
        emit do_write104Log("Unable to start the server!",
            Qt::white, Qt::blue);
        qDebug() << "Unable to start the server";
    }
}

void IEC104_Server::close() {
    qDebug() << "--------------------------------------------------------";
    qDebug() << "[IEC104_Server::close()]";
    emit do_write104Log("server closing..",
        Qt::white, Qt::blue);
    server104->close();
    //server104->deleteLater();
}

void IEC104_Server::newConnection() {
    qDebug() << "--------------------------------------------------------";
    qDebug() << "[IEC104_Server::newConnection()]";
    while (server104->hasPendingConnections()) {
        socket104 = server104->nextPendingConnection();

        connect(socket104, &QTcpSocket::readyRead, this, &IEC104_Server::readyRead);
        connect(socket104, &QTcpSocket::disconnected, this, &IEC104_Server::disconnected);
        connect(socket104, &QAbstractSocket::errorOccurred, this, &IEC104_Server::errorOccurred);

        QString socStr = QString::number(socket104->socketDescriptor());
        emit do_write104Log("socket " + socStr + " connected",
            Qt::white, Qt::blue);
        qDebug() << "INFO :: new client: " << socket104->socketDescriptor();

    }
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
    emit do_write104Log("socket " + socStr + " connected",
        Qt::white, Qt::blue);
    qDebug() << "INFO :: new client: " << socket->socketDescriptor();
}
*/

void IEC104_Server::disconnected() {
}

void IEC104_Server::readyRead() {
    qDebug() << "--------------------------------------------------------";
    qDebug() << "[IEC104_Server::readyRead()]";

    QByteArray data;

    while (socket104->bytesAvailable())
    {
        data = socket104->read(2);

        int size = getInt_fromData(data.mid(1, 1));
        qDebug() << "Size: " << size;
        data.append(socket104->read(size));


        qDebug() << "dataRead: " << QString(data.toHex());
        readHandle(data);

        //emit do_writePTMLog(data.toHex());
    }
    /*
    while (socket104->bytesAvailable()) {
        data.append(socket104->read(1));
    }
    emit do_write104Log("dataRead: " + QString(data),
        color_in, Qt::white);
    qDebug() << "dataRead: " << QString(data);
    readHandle(data);
    //write(data);
    */
}

void IEC104_Server::readHandle(QByteArray data) {

    if (data[0] == 0x68) {  //start
        //01 S-Frame
        if (data[2] && 0x00000011 == 0x01) {
            emit do_write104Log("--> S-Frame", color_in, Qt::white);
            S_FrameHandle(data);
        }
        //#11 U-Frame
        else if (data[2] && 0b00000011 == 0b11) {
            emit do_write104Log("--> U-Frame", color_in, Qt::white);
            U_FrameHandle(data);
        }
        //11 I-Frame
        else if (data[2] && 0b00000001 == 0b0) {
            emit do_write104Log("--> I-Frame", color_in, Qt::white);
            I_FrameHandle(data);
        }
        else {
            qDebug() << "Wrong size of incomming IEC 60870-5-104 Frame";
        }
    }
}

void IEC104_Server::S_FrameHandle(QByteArray data) {
}

void IEC104_Server::U_FrameHandle(QByteArray data) {
    if (data[2] == 0x07) {
        emit do_write104Log("--> U (STARTDT act)", color_in, Qt::white);
        data[2] = 0x0B;
        emit do_write104Log("<-- U (STARTDT con)", color_out, Qt::white);
        write(data);
    }
    else if (data[2] == 0x13) {
        emit do_write104Log("--> U (STOPDT act)", color_in, Qt::white);
        data[2] = 0x23;
        emit do_write104Log("<-- U (STOPDT con)", color_out, Qt::white);
        write(data);
    }
    else if (data[2] == 0x43) {
        emit do_write104Log("--> U (TESTFR act)", color_in, Qt::white);
        data[2] = 0x83;
        emit do_write104Log("<-- U (TESTFR act)", color_out, Qt::white);
        write(data);
    }
    else {
        emit do_write104Log("--> unknown U {}", color_in, Qt::white);
    }
}

void IEC104_Server::I_FrameHandle(QByteArray data) {
}


void IEC104_Server::errorOccurred() {
}

void IEC104_Server::write(QByteArray data) {
    qDebug() << "--------------------------------------------------------";
    qDebug() << "[IEC104_Server::write(QByteArray data)]";

    socket104->setSocketOption(QAbstractSocket::LowDelayOption, 1);

    socket104->write(data);
    socket104->flush();

    emit do_write104Log("dataWite: " + QString(data),
        color_out, Qt::white);
    qDebug() << "dataWited: " << QString(data);

}

