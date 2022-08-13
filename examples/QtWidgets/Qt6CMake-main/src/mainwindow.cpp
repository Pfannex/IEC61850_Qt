#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    client.close_client();
    delete ui;
}

void MainWindow::on_bu_connect_clicked() {
    int res = client.connect_to_server("127.0.0.1", 102);
    ui->tb_serverLog->append((QString::number(res)));
}

void MainWindow::on_bu_on_clicked() {
    ui->tb_controlLog->append("control -> ON");
    //printf("IEC61850_Client::control\n");
    //client.xcontrol();
    //control("", 2);
    //ui->tb_controlLog->append(control("ON", 2));
    //Thread_sleep(1000);


    IedConnection con;
    IedClientError error;

    con = IedConnection_create();
    IedConnection_connect(con, &error, "127.0.0.1", 102);

    ControlObjectClient control = ControlObjectClient_create("WA22_Q06_B1_B42Steuerung/LSCSWI1.Pos", con);

    //ControlObjectClient_setCommandTerminationHandler(control, commandTerminationHandler, NULL);

    MmsValue* ctlVal = MmsValue_newBoolean(true);
    //MmsValue* ctlVal = MmsValue_newBitString(2);            ;

    ControlObjectClient_setOrigin(control, NULL, 3);

    if (ControlObjectClient_operate(control, ctlVal, 0 /* operate now */)) {
        printf("operated successfully\n");
    }
    else {
        printf("failed to operate\n");
    }


}
void MainWindow::on_bu_off_clicked() {
    ui->tb_controlLog->append("control -> OFF");
    ui->tb_controlLog->append("control -> ON");
    //printf("IEC61850_Client::control\n");
    //client.xcontrol();
    //control("", 2);
    //ui->tb_controlLog->append(control("ON", 2));
    //Thread_sleep(1000);


    IedConnection con;
    IedClientError error;

    con = IedConnection_create();
    IedConnection_connect(con, &error, "127.0.0.1", 102);

    ControlObjectClient control = ControlObjectClient_create("WA22_Q06_B1_B42Steuerung/LSCSWI1.Pos", con);

    //ControlObjectClient_setCommandTerminationHandler(control, commandTerminationHandler, NULL);

    MmsValue* ctlVal = MmsValue_newBoolean(false);
    //MmsValue* ctlVal = MmsValue_newBitString(2);            ;

    ControlObjectClient_setOrigin(control, NULL, 3);

    if (ControlObjectClient_operate(control, ctlVal, 0 /* operate now */)) {
        printf("operated successfully\n");
    }
    else {
        printf("failed to operate\n");
    }

}


//------------------------------------------------------------------------------------------------------------------



