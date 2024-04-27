#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>
#include <QMainWindow>
#include <QString>
#include <QMessageBox>

#include <stdlib.h>
#include <stdio.h>

#include <QDataStream>
#include <QDialog>
#include <QTcpSocket>

#include "ui_mainwindow.h"
#include <iec61850_control.h>
#include <sitipe_master.h>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void on_commandTermination(string result);

//user interface
private:
    Ui::MainWindow *ui;
private slots:
    void on_bu_close_clicked();
    void on_bu_connect_clicked();
    void on_bu_disconnect_clicked();
    void on_lw_PTM_clicked();
    void on_lw_PTM_selection_changed();
    void setConnectionStatus(bool value);
    void setPTMConnectionStatus(bool value);

    void on_bu_addPTM_clicked();
    void on_bu_delPTM_clicked();

    void on_IO_1_clicked();



signals:
    void on_ptm_change(int ptmID);
    void on_setIO(int channel, bool value);


    void on_bu_KITT_clicked();
    void on_bu_TEST_clicked();


//SITIPE socket
private:
    TcpSocket sitipe_socket;
private slots:
    void receive_from_object(bool value);
    void writeTCPLog(QString txt, QColor fColor, QColor bColor);
    void setIO(int io, bool state);
signals:
    void transmit_to_object(bool value);

//SITIPE Master
private:
    SITIPE_Master sitipe_master;

//MMS Client
private:
    IEC61850_Client client;


};




#endif // MAINWINDOW_H


