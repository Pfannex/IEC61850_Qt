#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QMessageBox>

#include <stdlib.h>
#include <stdio.h>
#include <string>
using namespace std;

#include <iec61850_control.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_bu_connect_clicked();
    void on_bu_on_clicked();
    void on_bu_off_clicked();

private:
    Ui::MainWindow *ui;
    IEC61850_Client client;
};

#endif // MAINWINDOW_H


