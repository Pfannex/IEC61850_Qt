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
        emit do_writePTMLog("try to reconnect...", Qt::white,Qt::blue);
        QThread::msleep(1000);
        socket->connectToHost(ip, port);
    }
    else {
        emit do_writePTMLog("connecting to: " + ip + ":" + QString::number(port), Qt::white, Qt::blue);
        socket->connectToHost(ip, port);
    }
 
    // we need to wait...
    if (!socket->waitForConnected(5000)) {
        emit do_writePTMLog("Error: " + socket->errorString(), Qt::white, Qt::blue);
    }
}

void TcpSocket::doDisconnect() {
    socket->abort();
    socket->close();
    //QThread::msleep(1000);
}
void TcpSocket::destroyed() {
    emit do_writePTMLog("all cleanded up...", Qt::white, Qt::blue);
    emit do_setConnectionStatus(false);

}

void TcpSocket::connected(){
    emit do_writePTMLog("connected...", Qt::white, Qt::blue);
    emit do_setConnectionStatus(true);
}

void TcpSocket::disconnected(){
    emit do_writePTMLog("disconnected...", Qt::white, Qt::blue);
    emit do_setConnectionStatus(false);

}

void TcpSocket::readyRead(){
    //qDebug() << "reading...";
    //emit do_writePTMLog("reading...");

    QByteArray data;
    while (socket->bytesAvailable())
    {        
        data = socket->read(6);

        int size = getInt_fromData(data.mid(2,4));
        //qDebug() << "Size: " << size;
        
        data.append(socket->read(size));

        //emit do_writePTMLog(data.toHex());
        emit do_receiveFrame(data);
    }
}

void TcpSocket::write(QByteArray data){
    socket->setSocketOption(QAbstractSocket::LowDelayOption, 1);

    socket->write(data);
    socket->flush();

}

void TcpSocket::bytesWritten(qint64 bytes){
    //emit do_writePTMLog(QString::number(bytes) + " bytes written...");
}

//....................


//#############################################################################
// SITIPE PTM
//#############################################################################

SITIPE_PTM::SITIPE_PTM(QObject* parent) :
    QObject(parent)
{
}


void SITIPE_PTM::add(int ptmID, int listIndex) {
    PTM x;
    x.ptmID = ptmID;
    x.ptmListIndex = listIndex;

    //active_ptmID = ptmID;
    //active_ptmListIndex = listIndex;
     
    //x.ptmIndex = id.count();
    x.str_ptmID = QStringLiteral("%1").arg(ptmID, 5, 10, QLatin1Char('0'));
    index.append(x);
}
void SITIPE_PTM::del(int index) {
    SITIPE_PTM::index.remove(index);
}

int SITIPE_PTM::getptmIndexfromPtmID(int ptmID) {
    //qDebug() << "    [SITIPE_PTM::getptmIndexfromPtmID]------------------";
    //qDebug() << "      ptmID " << ptmID;


    for (int i = 0; i < index.count(); i++) {
        //qDebug() << "      index " << i 
        //    << "  ptmID  " << index[i].ptmID;

        if (index[i].ptmID == ptmID) {
            //qDebug() << "      return " << index[i].ptmIndex;
            return index[i].ptmIndex;
        }
    }
    return 0;
}
int SITIPE_PTM::getListIndexfromPtmID(int ptmID) {
    //qDebug() << "    [SITIPE_PTM::getListIndexfromPtmID]------------------";
    //qDebug() << "      ptmID " << ptmID;

    for (int i = 0; i < index.count(); i++) {
        //qDebug() << "      index " << i 
        //    << "  ptmID  " << index[i].ptmID;

        if (index[i].ptmID == ptmID) {
            //qDebug() << "      return " << i;
            return i;
        }
    }
    return 0;
}

void SITIPE_PTM::printInfo() {

}
void SITIPE_PTM::printPTM(int ptmID) {
    int ptmListIndex = getListIndexfromPtmID(ptmID);
    qDebug() << "--------------------------------------------------------";
    qDebug() << "[PTM " << index[ptmListIndex].str_ptmID << "]";
    qDebug() << " Modul ID:        " << index[ptmListIndex].str_ptmID;
    qDebug() << " Modul Index:     " << index[ptmListIndex].ptmIndex;
    qDebug() << " Modul ListIndex: " << index[ptmListIndex].ptmListIndex;
    QString con = (index[ptmListIndex].connected) ? "connected" : "disconnected";
    qDebug() << " connected:   " << con;
    if (index[ptmListIndex].connected) {
        QString val = "";
        for (int i = 0; i < 5; i++) {
            val.append((index[ptmListIndex].io[i].inValue) ? "X" : "-");
        }
        val.append(" ");
        for (int i = 5; i < 10; i++) {
            val.append((index[ptmListIndex].io[i].inValue) ? "X" : "-");
        }
        qDebug() << "         I/O  1-10" << val;
        val.clear();

        for (int i=10; i < 15; i++) {
            val.append((index[ptmListIndex].io[i].inValue) ? "X" : "-");
        }
        val.append(" ");
        for (int i = 15; i < 20; i++) {
            val.append((index[ptmListIndex].io[i].inValue) ? "X" : "-");
        }
        qDebug() << "         I/O 11-20" << val;
        val.clear();

        for (int i=20; i < 25; i++) {
            val.append((index[ptmListIndex].io[i].inValue) ? "X" : "-");
        }
        val.append(" ");
        for (int i = 25; i < 30; i++) {
            val.append((index[ptmListIndex].io[i].inValue) ? "X" : "-");
        }
        qDebug() << "         I/O 21-30" << val;
        val.clear();

        for (int i=30; i < 35; i++) {
            val.append((index[ptmListIndex].io[i].inValue) ? "X" : "-");
        }
        val.append(" ");
        for (int i = 35; i < 40; i++) {
            val.append((index[ptmListIndex].io[i].inValue) ? "X" : "-");
        }
        qDebug() << "         I/O 31-40" << val;
        val.clear();

        for (int i=40; i < 45; i++) {
            val.append((index[ptmListIndex].io[i].inValue) ? "X" : "-");
        }
        val.append(" ");
        for (int i = 45; i < 48; i++) {
            val.append((index[ptmListIndex].io[i].inValue) ? "X" : "-");
        }
        qDebug() << "         I/O 41-48" << val;


    }
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
    qDebug() << "--------------------------------------------------------";
    qDebug() << "[SITIPE_Master::receiveFrame(QByteArray data)]";
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
        if (h.type == 4) {
            qDebug() << "  slaveInitResponse_0004";
            slaveInitResponse_0004(data, h);
        }
        else if (h.type == 5){
            //qDebug() << "  slaveKeepAlive_0005";
            slaveKeepAlive_0005(data, h);
            //emit do_sendToSlave(data);
        }
        else if (h.type == 6) {
            qDebug() << "  slavePTMStatus_0006";
            slavePTMStatus_0006(data, h);
            emit do_sendToSlave(data);
        }
        else if (h.type == 7) {
            qDebug() << "  slaveTransmit_0007";
            slaveTransmit_0007(data, h);
            emit do_sendToSlave(data);
        }
        else if (h.type == 8) {
            qDebug() << "  slaveQuit_0008";
            slaveQuit_0008(data, h);
            emit do_sendToSlave(data);
        }
        else if (h.type == 9) {
            qDebug() << "  slaveAcceptedPTMUpdate_0009";
            slaveAcceptedPTMUpdate_0009(data, h);
            emit do_sendToSlave(data);
        }
        else
            emit do_writePTMLog("unknown type!", Qt::yellow, Qt::red);
    }
    else {
        emit do_writePTMLog("FrameSize NOT OK", Qt::yellow, Qt::red);
    }
}

void SITIPE_Master::updateSocketState(bool online) {
    socketOnline = online;
    qDebug() << "socket state = " << socketOnline;

    masterQuit_0003(MASTER_RESTART);
    masterInitRequest_0000();
}

void SITIPE_Master::ptm_change(int ptmID) {
    qDebug() << "--------------------------------------------------------";
    qDebug() << "[SITIPE_Master::ptm_change]";
    qDebug() << "  ptmID" << ptmID;

    //update index
    for (int i = 0; i < ptm.index.count(); i++) {
        qDebug() << "  index: " << i
            << " PTM: " << ptm.index[i].str_ptmID;
    }


     if (ptmID > 0) {
        //if (ptm.active_ptmID != ptmID) {
            ptm.active_ptmID = ptmID;
            ptm.active_ptmIndex = ptm.getptmIndexfromPtmID(ptmID);
            ptm.active_ptmListIndex = ptm.getListIndexfromPtmID(ptmID);
            //if (slaveConnected) masterInitRequest_0000();
        //}
     }
     else {
         ptm.active_ptmID = -1;
         ptm.active_ptmIndex = -1;
         ptm.active_ptmListIndex = -1;

     }
     qDebug() << "  activePTM:           " << ptm.active_ptmID;
     qDebug() << "  activePTM_index:     " << ptm.active_ptmIndex;
     qDebug() << "  activePTM_Listindex: " << ptm.active_ptmListIndex;

}

void SITIPE_Master::setIO(int channel, bool value) {
    qDebug() << "--------------------------------------------------------";
    qDebug() << "[SITIPE_Master::setIO]";
    qDebug() << "  channel: " << channel;
    qDebug() << "  value:   " << value;

    if (ptm.index.count() > 0) {
        ptm.index[ptm.active_ptmListIndex].io[channel - 1].outValue = value;

        if (ptm.index[ptm.active_ptmListIndex].connected)
            masterTransmit_0001(ptm.active_ptmID, channel, value);
    }
}
void SITIPE_Master::setIO(QByteArray io) {
    qDebug() << "--------------------------------------------------------";
    qDebug() << "[SITIPE_Master::setIO-all]";
    qDebug() << "  PTM: " << ptm.active_ptmID;
    masterOutputs_0010(ptm.active_ptmID, io);
}


void SITIPE_Master::KeepAllive() {
    masterKeepAlive_0002();
}


void SITIPE_Master::TEST() {
    qDebug() << "TEST...";
    masterTransmit_0001(0, 1, 0);

    
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
        emit do_writePTMLog("<-- [0000] masterInitRequest", color_master, Qt::white);

        //MasterInitRequest
        QByteArray data;
        QString hex;
        int length = 0;

        data.append(getHex_fromInt(0, 2));                                     //Type 0000
        data.append(getHex_fromInt(QDateTime::currentSecsSinceEpoch(), 8));    //Time 
        data.append(getHex_fromInt(0, 8));                                     //Time
        length = length + 16;

        if (ptm.index.count() > 0) {
            data.append(getHex_fromInt(ptm.index.count(), 4));                    //PTMs count
            length = length + 4;

            for (int i = 0; i < ptm.index.count(); i++) {
                data.append(getHex_fromInt(5, 4));                              //legth PTM ID String
                length = length + 4;
                data.append(getHex_fromStr(ptm.index[i].ptmID, 5));                //PTM ID String
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

void SITIPE_Master::masterTransmit_0001(int ptmID, int channel, bool value) {
    
    //check if PTM is connected

    int ptmIndex = ptm.getptmIndexfromPtmID(ptmID);
    int ptmListIndex = ptm.getListIndexfromPtmID(ptmID);
    if (ptmIndex < 0) ptmIndex = ptmListIndex;

    qDebug() << "--------------------------------------------------------";
    qDebug() << "[masterTransmit_0001]";
    qDebug() << "  ptmID        " << ptmID;
    qDebug() << "  ptmIndex     " << ptmIndex;
    qDebug() << "  ptmListIndex " << ptmListIndex;
    qDebug() << "  channel " << channel;
    qDebug() << "  value   " << value;

    if (socketOnline) {
        emit do_writePTMLog("<-- [0001] masterTransmit", color_master, Qt::white);

        QByteArray data;
        QString hex;
        int length = 0;

        data.append(getHex_fromInt(1, 2));                                     //Type 0001
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

        QString strState = " -> ";
        strState.append((value) ? "ON" : "OFF");

        emit sendFrame(data);
        emit do_writePTMLog("       PTM: " + ptm.index[ptmListIndex].str_ptmID + "  I/O: "
            + QString::number(channel) + strState, color_masterSub, Qt::black);

    }
    else {
        slaveConnected = false;
        emit do_setPTMConnectionStatus(false);
    }
}

void SITIPE_Master::masterKeepAlive_0002() {
    if (socketOnline and slaveConnected) {

        //qDebug() << "KeepAllive";
        QByteArray data;
        QString hex;
        int length = 0;

        data.append(getHex_fromInt(2, 2));                                     //Type 0010
        data.append(getHex_fromInt(QDateTime::currentSecsSinceEpoch(), 8));    //Time 
        data.append(getHex_fromInt(0, 8));                                     //Time
        length = length + 16;

        data.insert(2, getHex_fromInt(length, 4));
        emit sendFrame(data);

        //emit do_writePTMLog("<-- [0002] masterKeepAlive", color_master, Qt::white);
    }
}

void SITIPE_Master::masterQuit_0003(int reason) {
    emit do_writePTMLog("<-- [0003] masterQuit", color_master, Qt::white);
    emit do_setPTMConnectionStatus(false);
}

void SITIPE_Master::masterOutputs_0010(int ptmID, QByteArray io) {
    int ptmListIndex = ptm.getListIndexfromPtmID(ptmID);
    //int ptmIndex = ptm.index[ptmListIndex].ptmIndex;


    QByteArray data;
    QString hex;
    int length = 0;

    data.append(getHex_fromInt(10, 2));                                    //Type 0010
    data.append(getHex_fromInt(QDateTime::currentSecsSinceEpoch(), 8));    //Time 
    data.append(getHex_fromInt(0, 8));                                     //Time
    length = length + 16;

    data.append(getHex_fromInt(5, 4));                                     //length PTM ID String
    length = length + 4;
    data.append(getHex_fromStr(ptmID, 5));                                 //PTM ID String
    length = length + 5;

    data.append(getHex_fromInt(48, 4));                                    //length IOs
    length = length + 4;

    //for (int i = 0; i < 48; i++) {                                         //IOs state
        data.append(io);
    //}
    length = length + 48;

    data.insert(2, getHex_fromInt(length, 4));
    emit sendFrame(data);

    emit do_writePTMLog("<-- [0010] masterOutputs", color_master, Qt::white);
    emit do_writePTMLog("       PTM: " + ptm.index[ptmListIndex].str_ptmID, color_masterSub, Qt::black);
}

//-----------------------------------------------------------------------------
//Slave->Master
//-----------------------------------------------------------------------------
void SITIPE_Master::slaveInitResponse_0004(QByteArray data, Header h) {
    int connections_accepted = getInt_fromData(data.mid(22, 2));
    int ptm_count = getInt_fromData(data.mid(24, 4));
    int ptmID = 0;

    for (int i = 0; i < ptm_count; i++) {
        ptm.index[i].connected = false;
    }

    emit do_writePTMLog("--> [0004] slaveInitResponse", color_slave, Qt::white);
    if (connections_accepted != 0) {
        emit do_writePTMLog("                    conection refused", color_slaveSub, Qt::black);
        slaveConnected = false;
    }
    else {
        emit do_writePTMLog("                    connection accepted", color_slaveSub, Qt::black);
        slaveConnected = true;
        emit do_setPTMConnectionStatus(true);


        emit do_writePTMLog(QString("                    %1 PTMs connected").arg(ptm_count), color_slaveSub, Qt::black);
        for (int i = 0; i < ptm_count; i++) {
            QString strPTM = QString(data.mid(32 + (i*9), 5));
            int ptmID = strPTM.toInt();

            int ptmListIndex = ptm.getListIndexfromPtmID(ptmID);
            ptm.index[ptmListIndex].connected = true;

            emit do_writePTMLog("                       - " + ptm.index[ptmListIndex].str_ptmID,
                color_slaveSub, Qt::black);
        }   
    }

    for (int i = 0; i < ptm.index.count(); i++) {
        ptm.printPTM(ptm.index[i].ptmID);
    }
}

void SITIPE_Master::slaveKeepAlive_0005(QByteArray data, Header h) {
    //emit do_writePTMLog("--> [0005] slaveKeepAlive", color_slave, Qt::white);
}

void SITIPE_Master::slavePTMStatus_0006(QByteArray data, Header h) {
    emit do_writePTMLog("--> [0006] slavePTMStatus", color_slave, Qt::white);
    
    int ptm_count = getInt_fromData(data.mid(22, 4));
    for (int i = 0; i < ptm_count; i++) {
        ptm.index[i].connected = false;
    }

    QString strPtm_count = QString::number(ptm_count);
    emit do_writePTMLog("                    PTM count: " + strPtm_count, color_slaveSub, Qt::black);
    for (int i = 0; i < ptm_count; i++) {
        QString strPTM = QString(data.mid(30 + (i * 62), 5));
        int ptmID = strPTM.toInt();
        int ptmListIndex = ptm.getListIndexfromPtmID(ptmID);

        bool readOK = getInt_fromData(data.mid(35 + (i * 62), 1));
        QString result = (readOK) ? " -> read OK" : " -> read NOT OK";
        if (readOK) ptm.index[ptmListIndex].connected = true;
        
        for (int j = 0; j < 48; j++) {
            bool ioVal = getInt_fromData(data.mid((40 + j) + (i * 62), 1));
            ptm.index[ptmListIndex].io[i].inValue = ioVal;
        }

        emit do_writePTMLog("                       - " + ptm.index[ptmListIndex].str_ptmID
            + result, color_slaveSub, Qt::black);

        if (readOK == 1) {
            QString val = "";
            for (int i = 0; i < 5; i++) {
                val.append((ptm.index[ptmListIndex].io[i].inValue) ? "X" : "-");
            }
            val.append(" ");
            for (int i = 5; i < 10; i++) {
                val.append((ptm.index[ptmListIndex].io[i].inValue) ? "X" : "-");
            }
            emit do_writePTMLog("                         I/O   1-10  " + val, color_slaveSub, Qt::black);
            val.clear();

            for (int i = 10; i < 15; i++) {
                val.append((ptm.index[ptmListIndex].io[i].inValue) ? "X" : "-");
            }
            val.append(" ");
            for (int i = 15; i < 20; i++) {
                val.append((ptm.index[ptmListIndex].io[i].inValue) ? "X" : "-");
            }
            emit do_writePTMLog("                         I/O 11-20  " + val, color_slaveSub, Qt::black);
            val.clear();

            for (int i = 20; i < 25; i++) {
                val.append((ptm.index[ptmListIndex].io[i].inValue) ? "X" : "-");
            }
            val.append(" ");
            for (int i = 25; i < 30; i++) {
                val.append((ptm.index[ptmListIndex].io[i].inValue) ? "X" : "-");
            }
            emit do_writePTMLog("                         I/O 21-30  " + val, color_slaveSub, Qt::black);
            val.clear();

            for (int i = 30; i < 35; i++) {
                val.append((ptm.index[ptmListIndex].io[i].inValue) ? "X" : "-");
            }
            val.append(" ");
            for (int i = 35; i < 40; i++) {
                val.append((ptm.index[ptmListIndex].io[i].inValue) ? "X" : "-");
            }
            emit do_writePTMLog("                         I/O 31-40  " + val, color_slaveSub, Qt::black);
            val.clear();

            for (int i = 40; i < 45; i++) {
                val.append((ptm.index[ptmListIndex].io[i].inValue) ? "X" : "-");
            }
            val.append(" ");
            for (int i = 45; i < 48; i++) {
                val.append((ptm.index[ptmListIndex].io[i].inValue) ? "X" : "-");
            }
            emit do_writePTMLog("                         I/O 41-48  " + val, color_slaveSub, Qt::black);
        }
        emit do_setPTMstate();
        ptm.printPTM(ptm.index[i].ptmID);
    }
}

void SITIPE_Master::slaveTransmit_0007(QByteArray data, Header h) {
    emit do_writePTMLog("--> [0007] slaveTransmit", color_slave, Qt::white);

    qDebug() << "--------------------------------------------------------";
    qDebug() << "[SITIPE_Master::slaveTransmit_0007]";

    QString strPTM = QString(data.mid(40, 5));
    int ptmID = strPTM.toInt();
    qDebug() << "  strPTM: " << strPTM;
    qDebug() << "  ptmID: " << ptmID;

    int ptmIndex = getInt_fromData(data.mid(22, 2));
    qDebug() << "  ptmIndex:     " << ptmIndex;

    qint16 io = getInt_fromData(data.mid(24, 2)) +1;
    qint8 outputEvent = data[34];
    qint8 state = data[35];

    int ptmListIndex = ptm.getListIndexfromPtmID(ptmID);

    ptm.index[ptmListIndex].ptmIndex = ptmIndex;
    ptm.index[ptmListIndex].ptmListIndex = ptmListIndex;

    if (!outputEvent)
        ptm.index[ptmListIndex].io[io - 1].inValue = state;

    //ptm.printPTM(ptm.index[ptmListIndex].ptmID);

    QString strState = " -> ";
    strState.append((state) ? "ON" : "OFF");

    qDebug() << "  ptmID   :     " << ptm.index[ptmListIndex].str_ptmID;
    qDebug() << "  ptmIndex:     " << ptmIndex;
    qDebug() << "  ptmListIndex: " << ptmListIndex;

    emit do_writePTMLog("       PTM: " + ptm.index[ptmListIndex].str_ptmID + "  I/O: "
        + QString::number(io) + strState, color_slaveSub, Qt::black);
 

    //qDebug() << "IO: " << io << " | state: " << state;
    qDebug() << "  ptm.active_ptmIndex " << ptm.active_ptmIndex;
    qDebug() << "  ptm.active_ptmListIndex " << ptm.active_ptmListIndex;

    if (ptmListIndex == ptm.active_ptmListIndex) {
        //qDebug() << "  emit do_setPTMstate()";
        ptm_change(ptmID);
        emit do_setPTMstate();
    }
    ptm.printPTM(ptm.index[ptmListIndex].ptmID);

}

void SITIPE_Master::slaveQuit_0008(QByteArray data, Header h) {
    emit do_writePTMLog("--> [0008] slaveQuit", color_slave, Qt::white);
    slaveConnected = false;
    emit do_setPTMConnectionStatus(false);


}

void SITIPE_Master::slaveAcceptedPTMUpdate_0009(QByteArray data, Header h) {
    emit do_writePTMLog("--> [0009] slaveAcceptedPTMUpdate", color_slave, Qt::white);
}

//#############################################################################
// connection handling to SITIPE Master
//#############################################################################

void SITIPE_Master::writeToSlave(QByteArray data, bool firstInit) {
    qDebug() << "--------------------------------------------------------";
    qDebug() << "[SITIPE_Master::writeToSlave(QByteArray data)]";

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
        if (h.type == 99){
            //slaveInitResponse_0004(data, h);
            qDebug() << "  send -> slaveInitResponse_0004";
            data.clear();
            data = QByteArray::fromHex(
                "00040000002300000000e278e05a5c43"
                "d8000000000000000000000100000005"
                "303032303100000000");
            emit do_sendToSlave(data);

            //slavePTMStatus_0006(data, h);
            /*
            qDebug() << "  send -> slavePTMStatus_0006";
            data.clear();
            data = QByteArray::fromHex(
                "00060000005200000000e278e05a5e92"
                "60000000000000000001000000053030"
                "32303101000000300000000000000000"
                "00000000000000000000000000000000"
                "00000000000000000000000000000000"
                "0000000000000000");
            emit do_sendToSlave(data);
            */
        
        }else if(h.type == 99 and firstInit == true) {
            qDebug() << "  send -> firstInit SlavePTMstatus_0006";
            data.clear();
            data = QByteArray::fromHex(
                "00060000005200000000e2790f6bacb9"
                "80000000000000000001000000053030"
                "32303101000000300000000000000000"
                "00000000000000000000000000000000"
                "00000000000000000000000000000000"
                "0000000000000000"
            );
            emit do_sendToSlave(data);

        }
        else{
            qDebug() << "  send -> Type " << h.type << " to Slave";
            emit sendFrame(data);
        }
    }

}
//void SITIPE_Master::do_sendToSlave(QByteArray data) {

//}


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

