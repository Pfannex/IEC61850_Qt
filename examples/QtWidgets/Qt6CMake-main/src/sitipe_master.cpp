#include <sitipe_master.h>

//#############################################################################
// SITIPE socket handling
//#############################################################################

TcpSocket::TcpSocket(QObject* parent) :
    QObject(parent)
{
    socket = new QTcpSocket(this);

    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(socket, SIGNAL(bytesWritten(qint64)), this, SLOT(bytesWritten(qint64)));
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
}

void TcpSocket::doConnect(QString ip, int port)
{
    if (socket->isOpen()) {
        socket->abort();
        socket->close();
        emit do_writeTCPLog("try to reconnect...", Qt::white,Qt::blue);
        QThread::msleep(1000);
        socket->connectToHost(ip, port);
    }
    else {
        emit do_writeTCPLog("connecting to: " + ip + ":" + QString::number(port), Qt::white, Qt::blue);
        socket->connectToHost(ip, port);
    }
 
    // we need to wait...
    if (!socket->waitForConnected(5000)) {
        emit do_writeTCPLog("Error: " + socket->errorString(), Qt::white, Qt::blue);
    }
}

void TcpSocket::doDisconnect() {
    socket->abort();
    socket->close();
    //QThread::msleep(1000);
}
void TcpSocket::destroyed() {
    emit do_writeTCPLog("all cleanded up...", Qt::white, Qt::blue);
    emit do_setConnectionStatus(false);

}

void TcpSocket::connected(){
    emit do_writeTCPLog("connected...", Qt::white, Qt::blue);
    emit do_setConnectionStatus(true);
}

void TcpSocket::disconnected(){
    emit do_writeTCPLog("disconnected...", Qt::white, Qt::blue);
    emit do_setConnectionStatus(false);

}

void TcpSocket::readyRead(){
    qDebug() << "reading...";
    //emit do_writeTCPLog("reading...");

    QByteArray data;
    while (socket->bytesAvailable())
    {        
        data = socket->read(6);

        int size = getInt_fromData(data.mid(2,4));
        //qDebug() << "Size: " << size;
        
        data.append(socket->read(size));

        //emit do_writeTCPLog(data.toHex());
        emit do_receiveFrame(data);
    }
}

void TcpSocket::write(QByteArray data){
    socket->setSocketOption(QAbstractSocket::LowDelayOption, 1);

    socket->write(data);
    socket->flush();

}

void TcpSocket::bytesWritten(qint64 bytes){
    //emit do_writeTCPLog(QString::number(bytes) + " bytes written...");
}

//....................
void TcpSocket::receive_from_gui(bool value){
    QByteArray data;
    data = QByteArray::fromHex("AABBCCDD");
    socket->write(data);
}


//#############################################################################
// SITIPE PTM
//#############################################################################

SITIPE_PTM::SITIPE_PTM(QObject* parent) :
    QObject(parent)
{
}
void SITIPE_PTM::add(int ptmID) {
    PTM x;
    x.ptmID = ptmID;
    x.str_ptmID = QString::number(ptmID);
    id.append(x);
}
void SITIPE_PTM::del(int index) {
    id.remove(index);
}

int SITIPE_PTM::getIndexfromPtmID(int ptmID) {
    for (int i = 0; i < id.count(); i++) {
        if (id[i].ptmID == ptmID) return i;
    }
    return 0;
}


//#############################################################################
// SITIPE Master handling
//#############################################################################

SITIPE_Master::SITIPE_Master(QObject* parent) :
    QObject(parent)
{
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(KeepAllive()));
    timer->start(500);
}

void SITIPE_Master::receiveFrame(QByteArray data) {
    Header h;

    if (getHeader(data, h)) {
        qDebug() << "------------------------------";
        qDebug() << "Typ:     " << h.type;
        qDebug() << "Size:    " << h.size;
        //qDebug() << "ts_sec:  " << h.ts_sec;
        //qDebug() << "ts_ms:   " << h.ts_ms;
        qDebug() << h.str_ts;
        qDebug() << "------------------------------";

        if (h.type == 4)
            slaveInitResponse_0004(data, h);
        else if (h.type == 5)
            slaveKeepAlive_0005(data, h);
        else if (h.type == 6)
            slavePTMStatus_0006(data, h);
        else if (h.type == 7)
            slaveTransmit_0007(data, h);
        else if (h.type == 8)
            slaveQuit_0008(data, h);
        else if (h.type == 9)
            slaveAcceptedPTMUpdate_0009(data, h);
        else  
            emit do_writeTCPLog("unknown type!", Qt::yellow, Qt::red);
    }
    else {
        emit do_writeTCPLog("FrameSize NOT OK", Qt::yellow, Qt::red);
    }
}

void SITIPE_Master::updateSocketState(bool online) {
    socketOnline = online;
    qDebug() << "socket state = " << socketOnline;

    masterQuit_0003(MASTER_RESTART);
    masterInitRequest_0000();
}

void SITIPE_Master::ptm_change(int ptmID) {
     if (ptmID > 0) {
        if (activePTM != ptmID) {
            activePTM = ptmID;
            activePTM_index = ptm.getIndexfromPtmID(ptmID);
            //if (slaveConnected) masterInitRequest_0000();
        }
     }
     else {
         activePTM = 0;
         activePTM_index = -1;

     }
     qDebug() << "activePTM:       " << activePTM;
     qDebug() << "activePTM_index: " << activePTM_index;

}

void SITIPE_Master::setIO(int channel, bool value) {

    if (ptm.id.count() > 0) {
        masterTransmit_0001(activePTM_index, activePTM, channel, value);
    }
}


void SITIPE_Master::KeepAllive() {
    masterKeepAlive_0002();
}

void SITIPE_Master::KITT() {
    qDebug() << "KITT...";
    masterTransmit_0001(0,0, 1, 1);


    /*
    QByteArray data = QByteArray::fromHex("000a0000004d00000000e1f13d5c76e0"
        "f0000000000000000005303032303100"
        "00003001000100010001000100010001"
        "00010001000100010001000100010001"
        "00010001000100010001000100010001"
        "000100");
    emit sendFrame(data);
    */
}

void SITIPE_Master::TEST() {
    qDebug() << "TEST...";
    masterTransmit_0001(0,0, 1, 0);

    
    /*
    QByteArray data = QByteArray::fromHex("000a0000004d00000000e1f13d5c76e0"
        "f0000000000000000005303032303100"
        "00003000010001000100010001000100"
        "01000100010001000100010001000100"
        "01000100010001000100010001000100"
        "010001");
    emit sendFrame(data);
    */
}


//#############################################################################
// SITIPE command Frames
//#############################################################################
// 
//-----------------------------------------------------------------------------
//Master->Slave
//-----------------------------------------------------------------------------

void SITIPE_Master::masterInitRequest_0000() {
    if (socketOnline) {
        emit do_writeTCPLog("<-- [0000] masterInitRequest", color_master, Qt::white);

        //MasterInitRequest
        QByteArray data;
        QString hex;
        int length = 0;

        data.append(getHex_fromInt(0, 2));                                     //Type 0000
        data.append(getHex_fromInt(QDateTime::currentSecsSinceEpoch(), 8));    //Time 
        data.append(getHex_fromInt(0, 8));                                     //Time
        length = length + 16;

        if (ptm.id.count() > 0) {
            data.append(getHex_fromInt(ptm.id.count(), 4));                    //PTMs count
            length = length + 4;

            for (int i = 0; i < ptm.id.count(); i++) {
                data.append(getHex_fromInt(5, 4));                              //legth PTM ID String
                length = length + 4;
                data.append(getHex_fromStr(ptm.id[i].ptmID, 5));                //PTM ID String
                length = length + 5;
            }
        }
        else {
            qDebug() << "alle weg... ";
            masterQuit_0003(MASTER_STOPPED);
            slaveConnected = false;
            emit do_setPTMConnectionStatus(false);
            exit;
        }

        data.insert(2, getHex_fromInt(length, 4));
        emit sendFrame(data);

    }
    else {
        slaveConnected = false;
    }
}

void SITIPE_Master::masterTransmit_0001(int ptmIndex, int ptmID, int channel, bool value) {
    if (socketOnline and slaveConnected) {
        emit do_writeTCPLog("<-- [0001] masterTransmit", color_master, Qt::white);

        QByteArray data;
        QString hex;
        int length = 0;

        data.append(getHex_fromInt(1, 2));                                     //Type 0000
        data.append(getHex_fromInt(QDateTime::currentSecsSinceEpoch(), 8));    //Time 
        data.append(getHex_fromInt(0, 8));                                     //Time
        length = length + 16;

        data.append(getHex_fromInt(ptmIndex, 2));                              //PTM Index
        length = length + 2;
        data.append(getHex_fromInt(channel-1, 2));                             //Channel 
        length = length + 2;
        data.append(getHex_fromInt(0, 8));                                     //time int
        length = length + 8;
        data.append(getHex_fromInt(1, 1));                                     //update 
        length = length + 1;
        data.append(getHex_fromInt(value, 1));                                 //value 
        length = length + 1;
        data.append(getHex_fromInt(5, 4));                                     //legth PTM ID String
        length = length + 4;
        data.append(getHex_fromStr(ptmID, 5));                                 //PTM ID String
        length = length + 5;

        data.insert(2, getHex_fromInt(length, 4));
        emit sendFrame(data);

        QString strState = " -> ";
        strState.append((value) ? "ON" : "OFF");
        emit do_writeTCPLog("                   I/O: " + QString::number(channel) + strState, color_masterSub, Qt::black);

    }
    else {
        slaveConnected = false;
        emit do_setPTMConnectionStatus(false);
    }
}

void SITIPE_Master::masterKeepAlive_0002() {
    if (socketOnline and slaveConnected) {
        emit do_writeTCPLog("<-- [0002] masterKeepAlive", color_master, Qt::white);

        qDebug() << "KeepAllive";
        QByteArray data;
        data = QByteArray::fromHex("00020000001000000000e1f13d5cf7e5"
            "080000000000");
        emit sendFrame(data);
        data = 0;
    }
}

void SITIPE_Master::masterQuit_0003(int reason) {
    emit do_writeTCPLog("<-- [0003] masterQuit", color_master, Qt::white);
    emit do_setPTMConnectionStatus(false);
}

void SITIPE_Master::masterOutputs_0010() {
    emit do_writeTCPLog("<-- [0010] masterOutputs", color_master, Qt::white);
}

//-----------------------------------------------------------------------------
//Slave->Master
//-----------------------------------------------------------------------------
void SITIPE_Master::slaveInitResponse_0004(QByteArray data, Header h) {
    int connections_accepted = getInt_fromData(data.mid(22, 2));
    int ptm_count = getInt_fromData(data.mid(24, 4));

    emit do_writeTCPLog("--> [0004] slaveInitResponse", color_slave, Qt::white);
    if (connections_accepted != 0) {
        emit do_writeTCPLog("                    conection refused", color_slaveSub, Qt::black);
        slaveConnected = false;
    }
    else {
        emit do_writeTCPLog("                    connection accepted", color_slaveSub, Qt::black);
        slaveConnected = true;
        emit do_setPTMConnectionStatus(true);


        emit do_writeTCPLog(QString("                    %1 PTMs connected").arg(ptm_count), color_slaveSub, Qt::black);
        for (int i = 0; i < ptm_count; i++) {
            QString ptm = QString(data.mid(32 + (i*9), 5));
            emit do_writeTCPLog("                       - " + ptm, color_slaveSub, Qt::black);
        }   
    }
}

void SITIPE_Master::slaveKeepAlive_0005(QByteArray data, Header h) {
    emit do_writeTCPLog("--> [0005] slaveKeepAlive", color_slave, Qt::white);
}

void SITIPE_Master::slavePTMStatus_0006(QByteArray data, Header h) {
    emit do_writeTCPLog("--> [0006] slavePTMStatus", color_slave, Qt::white);
    
    int ptm_count = getInt_fromData(data.mid(22, 4));
    QString strPtm_count = QString::number(ptm_count);
    emit do_writeTCPLog("                    PTM count: " + strPtm_count, color_slaveSub, Qt::black);
    for (int i = 0; i < ptm_count; i++) {
        QString ptm = QString(data.mid(30 + (i * 62), 5));
        bool readOK = getInt_fromData(data.mid(35 + (i * 62), 1));
        QString result = (readOK) ? " -> read OK" : " -> read NOT OK";
        emit do_writeTCPLog("                       - " + ptm + result, color_slaveSub, Qt::black);
    }
}

void SITIPE_Master::slaveTransmit_0007(QByteArray data, Header h) {
    emit do_writeTCPLog("--> [0007] slaveTransmit", color_slave, Qt::white);

    qint16 io = getInt_fromData(data.mid(24, 2)) +1;
    qint8 state = data[35];
    QString strState = " -> ";
    strState.append((state) ? "ON" : "OFF");
    emit do_writeTCPLog("                   I/O: " + QString::number(io) + strState, color_slaveSub, Qt::black);


    qDebug() << "IO: " << io << " | state: " << state;

    emit do_setIO(io, state);
}

void SITIPE_Master::slaveQuit_0008(QByteArray data, Header h) {
    emit do_writeTCPLog("--> [0008] slaveQuit", color_slave, Qt::white);
    slaveConnected = false;
    emit do_setPTMConnectionStatus(false);


}

void SITIPE_Master::slaveAcceptedPTMUpdate_0009(QByteArray data, Header h) {
    emit do_writeTCPLog("--> [0009] slaveAcceptedPTMUpdate", color_slave, Qt::white);
}


//#############################################################################
// Helper
//#############################################################################

bool SITIPE_Master::getHeader(QByteArray data, Header &h) {
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

        h.ts.setMSecsSinceEpoch((h.ts_sec * 1000) + (h.ts_ms * pow(2, -64)*1000));
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





//TIME

// QDateTime now = QDateTime::currentDateTime();
 //quint64 t;
 //data.append(getHex_fromInt(t, 8));

 //length = length + 8;
 //data.append(getHex_fromInt(0, 8));

 //t = now.date().year() * 24 * 60 * 60;
 //t = t + now.date().month() * 60 * 60;
 //t = t + now.date().day() * 60 * 60;


 //QDateTime labView(QDate(1958).year());

 //qDebug("There are %d seconds to Christmas", now.secsTo(labView));


 //QString strts = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss,zzz");
 //qDebug() << "time: " << strts;

 //data.append(getHex_fromInt(QDateTime::currentSecsSinceEpoch() - (50 * 24 * 60 * 60), 8));

 //QString hexvalue = QString("0x%1").arg(length, 8, 16, QLatin1Char('0'));
 //data.append(QByteArray::fromHex(hexvalue.toUtf8()));

 //QByteArray::fromHex(ui->xtxtAdress->text());

 //QString x = format("{:#010x}", 1);

 //hex = "00000000";
 //data.append(QByteArray::fromHex("00000000"));  //Type

 //QString str = QString("%1").arg(length, 8, 16, QLatin1Char(' 0'));
 //data.append(str.toUtf8());


 /*
 data = QByteArray::fromHex("00000000002600000000e1f13d5c6431"
     "60000000000000000002000000053030"
     "303438000000053030323031");


 emit sendFrame(data);
 */