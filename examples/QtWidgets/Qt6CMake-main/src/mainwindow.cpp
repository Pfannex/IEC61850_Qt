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
    delete ui;
}

void MainWindow::on_bu_connect_clicked() {
    
    IedClientError error;
    IedConnection con = IedConnection_create();
    IedConnection_connect(con, &error, "127.0.0.1", 102);

    if (error == IED_ERROR_OK) {
        ui->tb_serverLog->append("connected to server: 127.0.0.1");
        IedConnection_close(con);
        ui->tb_serverLog->append("connection closed");
    }
    else {
        ui->tb_serverLog->append("failed to connect");
    }

    IedConnection_destroy(con);
}