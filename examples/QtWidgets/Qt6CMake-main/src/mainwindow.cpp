#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //client.set_callback(std::bind(&MainWindow::on_commandTermination, this, std::placeholders::_1));
}

//void MainWindow::on_commandTermination(string result) {
//    ui->tb_serverLog->append(QString::fromStdString(result));
//}

MainWindow::~MainWindow()
{
    client.close();
    delete ui;
}

void MainWindow::on_bu_connect_clicked() {
    int ret = client.connect_to_server("127.0.0.1", 102);
    //int ret = client.connect_to_server("192.168.2.61", 102);
    ui->tb_serverLog->append((QString::number(ret)));
}

void MainWindow::on_bu_on_clicked() {
    ui->tb_controlLog->append("control -> ON");
    if (client.control_switch("WA22_Q06_B1_B42Steuerung/LSCSWI1.Pos", true, 500)) {
        ui->tb_controlLog->append("control successfull");
        ui->tb_controlLog->append(QString::fromStdString(client.read_state("WA22_Q06_B1_B42Steuerung/LSCSWI1.Pos.stVal")));
    }
    else {
        ui->tb_controlLog->append("control failed");
    };
 }
void MainWindow::on_bu_off_clicked() {
    ui->tb_controlLog->append("control -> OFF");
    if (client.control_switch("WA22_Q06_B1_B42Steuerung/LSCSWI1.Pos", false, 500)) {
        ui->tb_controlLog->append("control successfull");
        ui->tb_controlLog->append(QString::fromStdString(client.read_state("WA22_Q06_B1_B42Steuerung/LSCSWI1.Pos.stVal")));
    }
    else {
        ui->tb_controlLog->append("control failed");
    };
}

void MainWindow::on_bu_state_clicked() {
    ui->tb_controlLog->append(QString::fromStdString(client.read_state("WA22_Q06_B1_B42Steuerung/LSCSWI1.Pos.stVal")));
}


