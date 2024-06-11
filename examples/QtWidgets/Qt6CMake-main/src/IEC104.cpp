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

    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(send_TESTFR()) );
    timer->start(2000);

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
    socketOnline = false;
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
    socketOnline = false;
    qDebug() << "--------------------------------------------------------";
    qDebug() << "[IEC104_Server::disconnected()]";
    emit do_write104Log("disconnected",
        Qt::white, Qt::blue);
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
    qDebug() << "-----------";
    qDebug() << "  data[0]: " << data.mid(0, 1).toHex();
    qDebug() << "  data[1]: " << data.mid(1, 1).toHex();
    qDebug() << "  data[2]: " << data.mid(2, 1).toHex();

    if (data[0] == 0x68) {  //start
        //01 S-Frame
        if ((data[2] & 0b00000011) == 1) {
            //emit do_write104Log("--> S-Frame", color_in, Qt::white);
            S_FrameHandle(data);
        }
        //#11 U-Frame
        else if ((data[2] & 0b00000011) == 3) {
            //emit do_write104Log("--> U-Frame", color_in, Qt::white);
            U_FrameHandle(data);
        }
        //11 I-Frame
        else if ((data[2] & 0b00000001) == 0) {
            //emit do_write104Log("--> I-Frame", color_in, Qt::white);
            I_FrameHandle(data);
        }
        else {
            qDebug() << "Wrong size of incomming IEC 60870-5-104 Frame";
        }
    }
}

void IEC104_Server::S_FrameHandle(QByteArray data) {
    emit do_write104Log("--> S-Frame", color_in, Qt::white);
}

void IEC104_Server::U_FrameHandle(QByteArray data) {
    QString type = data.mid(2, 1).toHex();
    qDebug() << "  data[2]: " << type;

    if (type == "07") {
        socketOnline = true;
        rx_count = 0;
        tx_count = 0;

        emit do_write104Log("--> U (STARTDT act)", color_in, Qt::white);
        data[2] = 0x0B;
        emit do_write104Log("<-- U (STARTDT con)", color_out, Qt::white);
        write(data);
    }
    else if (type == "13") {
        socketOnline = false;
        emit do_write104Log("--> U (STOPDT act)", color_in, Qt::white);
        data[2] = 0x23;
        emit do_write104Log("<-- U (STOPDT con)", color_out, Qt::white);
        write(data);
    }
    else if (type == "43") {
        emit do_write104Log("--> U (TESTFR act)", color_in, Qt::white);
        data[2] = 0x83;
        emit do_write104Log("<-- U (TESTFR con)", color_out, Qt::white);
        write(data);
    }
    else if (type == "83") {
        emit do_write104Log("<-- U (TESTFR con)", color_out, Qt::white);
    }
    else {
        emit do_write104Log("--> unknown U {}", color_in, Qt::white);
    }
}

void IEC104_Server::I_FrameHandle(QByteArray data) {
    qDebug() << "--------------------------------------------------------";
    qDebug() << "[IEC104_Server::I_FrameHandle(QByteArray data)]";
    
    rx_count = data[2] << 8;
    rx_count += (data[3] & 0b11111110) << 1;
    tx_count = data[4] << 8;
    tx_count += (data[5] & 0b11111110) << 1;
    uint ti = data[6];
    quint8 cot = (data[8] & 0b00111111);

    qDebug() << "  rx_count: " << rx_count;
    qDebug() << "  tx_count: " << tx_count;
    qDebug() << "  TI:       " << ti;
    qDebug() << "  COT:      " << cot;
    rx_count++;

    emit do_write104Log("--> I-Frame (TI " + QString::number(ti) + " act)"
        , color_in, Qt::white);

    if (ti == 100) {
        data[2] = (tx_count & 0b0000000001111111) << 1;
        data[3] = (tx_count & 0b0111111110000000) >> 7;
        data[4] = (rx_count & 0b0000000001111111) << 1;
        data[5] = (rx_count & 0b0111111110000000) >> 7;
        data[8] = (data[8] & 0b11000000) | 7;
        QString myStringOfBits(QString::number(data[8], 2));
        qDebug() << "  COT:      " << myStringOfBits;

        emit do_write104Log("<-- I-Frame (TI 100 ActCon)", color_out, Qt::white);
        write(data);
        tx_count++;

    }

}

void IEC104_Server::send_TESTFR() {
    if (socketOnline == true) {
        qDebug() << "--------------------------------------------------------";
        qDebug() << "[IEC104_Server::send_TESTFR()]";

        QByteArray data = QByteArray::fromHex(
            "680443000000");
        emit do_write104Log("--> U (TESTFR act)", color_in, Qt::white);
        write(data);
    }
}


void IEC104_Server::errorOccurred() {
}

void IEC104_Server::write(QByteArray data) {
    qDebug() << "--------------------------------------------------------";
    qDebug() << "[IEC104_Server::write(QByteArray data)]";

    socket104->setSocketOption(QAbstractSocket::LowDelayOption, 1);

    socket104->write(data);
    socket104->flush();

    //emit do_write104Log("dataWrite: " + QString(data), color_out, Qt::white);
    //qDebug() << "dataWrite " << QString(data);

}

