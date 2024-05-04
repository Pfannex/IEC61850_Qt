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
    QButtonGroup *ioGroup;


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

    void on_ioGroup_clicked(int id);

    /*
    void on_IO_1_clicked();
    void on_IO_2_clicked();
    void on_IO_3_clicked();
    void on_IO_4_clicked();
    void on_IO_5_clicked();
    void on_IO_6_clicked();
    void on_IO_7_clicked();
    void on_IO_8_clicked();
    void on_IO_9_clicked();
    void on_IO_10_clicked();
    void on_IO_11_clicked();
    void on_IO_12_clicked();
    void on_IO_13_clicked();
    void on_IO_14_clicked();
    void on_IO_15_clicked();
    void on_IO_16_clicked();
    void on_IO_17_clicked();
    void on_IO_18_clicked();
    void on_IO_19_clicked();
    void on_IO_20_clicked();
    void on_IO_21_clicked();
    void on_IO_22_clicked();
    void on_IO_23_clicked();
    void on_IO_24_clicked();
    void on_IO_25_clicked();
    void on_IO_26_clicked();
    void on_IO_27_clicked();
    void on_IO_28_clicked();
    void on_IO_29_clicked();
    void on_IO_30_clicked();
    void on_IO_31_clicked();
    void on_IO_32_clicked();
    void on_IO_33_clicked();
    void on_IO_34_clicked();
    void on_IO_35_clicked();
    void on_IO_36_clicked();
    void on_IO_37_clicked();
    void on_IO_38_clicked();
    void on_IO_39_clicked();
    void on_IO_40_clicked();
    void on_IO_41_clicked();
    void on_IO_42_clicked();
    void on_IO_43_clicked();
    void on_IO_44_clicked();
    void on_IO_45_clicked();
    void on_IO_46_clicked();
    void on_IO_47_clicked();
    void on_IO_48_clicked();
    */


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
    void setIO();
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


