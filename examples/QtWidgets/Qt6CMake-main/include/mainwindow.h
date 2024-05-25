#pragma

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
#include <QEvent>
#include <QWidget>
#include <QButtonGroup>

#include "ui_mainwindow.h"
#include <iec61850_control.h>
#include <sitipe_master.h>
#include <sitipe_slave.h>
#include <IEC104.h>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

//user interface
private:
    Ui::MainWindow *ui;
    QButtonGroup* outputGroup;
    QButtonGroup* inputGroup;
    QButtonGroup* ioUpdate;

private slots:
    //SITIPE Master
    void on_bu_close_clicked();
    void on_bu_connect_clicked();
    void on_bu_disconnect_clicked();
    void on_lw_PTM_selection_changed();
    //void on_bu_disconnect_clicked();
    void setConnectionStatus(bool value);

    void on_bu_addPTM_clicked();
    void on_bu_delPTM_clicked();

    void on_outputGroup_clicked(int id);
    void on_ioUpdate_clicked(int id);
    void on_bu_setGroup_clicked();

    //SITIPE Slave
    void on_bu_openSTSServer_clicked();
    void on_bu_closeSTSServer_clicked();

    //IEC104
    void on_bu_open104Server_clicked();
    void on_bu_close104Server_clicked();


signals:
    void on_ptm_change(int ptmID);
    void on_setIO(int channel, bool value);
    void on_setIO(QByteArray);


    void on_bu_TEST_clicked();


//SITIPE socket
private:
    TcpSocket sitipe_socket;
private slots:
    void writePTMLog(QString txt, QColor fColor, QColor bColor);
    void writeSTSLog(QString txt, QColor fColor, QColor bColor);
    void write104Log(QString txt, QColor fColor, QColor bColor);
    void setPTMstate();

//SITIPE Master
private:
    SITIPE_Master sitipe_master;
//SITIPE Slave
private:
    SITIPE_Slave sitipe_slave;

//IEC 61870-5-104 Server
private:
    IEC104_Server iec104;

//MMS Client
//private:
    //IEC61850_Client client;


};


#endif // MAINWINDOW_H

//-----------------------------------------------------------------------------
// build for external use
//-----------------------------------------------------------------------------
//
// ..\Qt6CMake-main\build > cd .\Release\
// ..\Qt6CMake-main\build\Release> windeployqt .\MY_PROJECT.exe

