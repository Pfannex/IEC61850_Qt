#include <helper.h>

//#############################################################################
// Helper
//#############################################################################
uint64_t getInt_fromData(QByteArray data) {
    uint64_t value = 0;
    uint64_t byte = 0;
    uint64_t tmp = 0;

    //qDebug() << "hex:  " << data.toHex();

    for (int i = data.size() - 1; i >= 0; i--)
    {
        byte = (unsigned char)data.at(i);
        int shift = data.size() - i - 1;
        tmp = (byte << (8 * shift));
        value += tmp;

        //qDebug() << "pos:  " << i << " | shift: " << shift << " | " << byte << " | shifted: " << tmp;
        //qDebug() << "value:" << " |" << value;
    }
    //qDebug() << "---------------------------------------";

    return value;
}

QByteArray getHex_fromInt(uint64_t value, int bytes) {
    QString hexvalue = QString("%1").arg(value, bytes*2, 16, QLatin1Char('0'));
    return QByteArray::fromHex(hexvalue.toUtf8());
}

QByteArray getHex_fromStr(int value, int bytes) {
    QString number = QStringLiteral("%1").arg(value, bytes, 10, QLatin1Char('0'));
    QByteArray array = number.toLocal8Bit();
    return array;
}



//#include <IEC104.h>

//#############################################################################
// SITIPE socket handling
//#############################################################################

/*
//IEC104_Server::IEC104_Server(QObject* parent) :
//    QObject(parent)
//{
//    server104 = new QTcpServer(this);

    //connect(server104, &QTcpServer::newConnection, this, newConnection);

//}


void IEC104_Server::start() {
    qDebug() << "--------------------------------------------------------";
    qDebug() << "[IEC104_Server::start()]";

    
 //   if (server104->listen(QHostAddress::Any, 8080)){
 //       qDebug() << "Server is listening...";
 //   }
 //   else
 //   {
 //       qDebug() << "Unable to start the server";
 //   }
 //   server104->listen(QHostAddress::Any, 8080);
    
}

//void IEC104_Server::newConnection() {

//}

*/


