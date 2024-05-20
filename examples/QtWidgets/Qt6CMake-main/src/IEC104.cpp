#include <IEC104.h>

//#############################################################################
// SITIPE socket handling
//#############################################################################

//IEC104_Server::IEC104_Server(QObject* parent) :
//    QObject(parent)
//{
    //server104 = new QTcpServer(this);

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
