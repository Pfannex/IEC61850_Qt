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

void MainWindow::on_pushButton_clicked() {
    
    QString txt = "HelloWorld!";

    
    IedClientError error;

    IedConnection con = IedConnection_create();
    
    IedConnection_connect(con, &error, "localhost", 102);

    if (error == IED_ERROR_OK) {
        txt = "connected";
        IedConnection_close(con);
    }
    else {
        txt = "failed to connect";
    }

    IedConnection_destroy(con);
    /**/

    QMessageBox::about(this, "Title", txt);
}