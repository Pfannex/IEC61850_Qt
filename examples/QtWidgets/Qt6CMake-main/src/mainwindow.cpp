#include "mainwindow.h"


MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    client.cb.set_callback(std::bind(&MainWindow::on_commandTermination, this, std::placeholders::_1));
 
    //Dialog Events
    QObject::connect(ui->lw_PTM, SIGNAL(itemSelectionChanged()),this, SLOT(on_lw_PTM_selection_changed()));

    //DEMO
    connect(&sitipe_socket, SIGNAL(transmit_to_gui(bool)), this, SLOT(receive_from_object(bool)));
    connect(this, SIGNAL(transmit_to_object(bool)), &sitipe_socket, SLOT(receive_from_gui(bool)));

    //sitipe SOCKET -> mainwindow
    connect(&sitipe_socket, SIGNAL(do_writeTCPLog(QString, QColor, QColor)), this, SLOT(writeTCPLog(QString, QColor, QColor)));
    connect(&sitipe_socket, SIGNAL(do_setConnectionStatus(bool)), this, SLOT(setConnectionStatus(bool)));
    //mainwindow -> sitipe SOCKET
    connect(this, SIGNAL(on_ptm_change(int)), &sitipe_master, SLOT(ptm_change(int)));


    //sitipe MASTER -> mainwindow 
    connect(&sitipe_master, SIGNAL(do_writeTCPLog(QString, QColor, QColor)), this, SLOT(writeTCPLog(QString, QColor, QColor)));
    connect(&sitipe_master, SIGNAL(do_setIO(int, bool)), this, SLOT(setIO(int, bool)));
    connect(&sitipe_master, SIGNAL(do_setPTMConnectionStatus(bool)), this, SLOT(setPTMConnectionStatus(bool)));
    //mainwindow -> sitipe MASTER
    connect(this, SIGNAL(on_setIO(int, bool)), &sitipe_master, SLOT(setIO(int, bool)));
    connect(this, SIGNAL(on_bu_KITT_clicked()), &sitipe_master, SLOT(KITT()));
    connect(this, SIGNAL(on_bu_TEST_clicked()), &sitipe_master, SLOT(TEST()));

    //sitipe SOCKET -> sitipe MASTER
    connect(&sitipe_socket, SIGNAL(do_setConnectionStatus(bool)), &sitipe_master, SLOT(updateSocketState(bool)));
    connect(&sitipe_socket, SIGNAL(do_receiveFrame(QByteArray)), &sitipe_master, SLOT(receiveFrame(QByteArray)));
    //sitipe MASTER -> sitipe SOCKET
    connect(&sitipe_master, SIGNAL(sendFrame(QByteArray)), &sitipe_socket, SLOT(write(QByteArray)));
}

MainWindow::~MainWindow()
{
    client.close();
    delete ui;
}

void MainWindow::on_bu_close_clicked() {
    close();
}
void MainWindow::on_bu_connect_clicked() {
    sitipe_socket.doConnect(ui->tb_serverIp->text(), ui->tb_port->text().toInt());
}
void MainWindow::on_bu_disconnect_clicked() {
    sitipe_master.masterQuit_0003(0);
    sitipe_socket.doDisconnect();
}
void MainWindow::setConnectionStatus(bool value) {
    ui->cb_online->setChecked(value);
}
void MainWindow::setPTMConnectionStatus(bool value) {
    qDebug() << "PTM online: " << value;

    ui->cb_ptmonline->setChecked(value);
}

void MainWindow::writeTCPLog(QString txt, QColor fColor, QColor bColor) {
    ui->lw_serverLog->addItem(txt);
    ui->lw_serverLog->item(ui->lw_serverLog->count() - 1)->setForeground(bColor);
    ui->lw_serverLog->item(ui->lw_serverLog->count() - 1)->setBackground(fColor);
    //ui->lw_serverLog->setAutoScroll(true);
}

//----------------------------

void MainWindow::setIO(int io, bool state) {
    if (io == 1) {
        ui->IO_1->setEnabled(true);
        ui->IO_1->setChecked(state);
    }
    if (io == 2) ui->IO_2->setChecked(state);
    if (io == 3) ui->IO_3->setChecked(state);
    if (io == 4) ui->IO_4->setChecked(state);
    if (io == 5) ui->IO_5->setChecked(state);
    if (io == 6) ui->IO_6->setChecked(state);
    if (io == 7) ui->IO_7->setChecked(state);
    if (io == 8) ui->IO_8->setChecked(state);
    if (io == 9) ui->IO_9->setChecked(state);
    if (io == 10) ui->IO_10->setChecked(state);
    if (io == 11) ui->IO_11->setChecked(state);
    if (io == 12) ui->IO_12->setChecked(state);
    if (io == 13) ui->IO_13->setChecked(state);
    if (io == 14) ui->IO_14->setChecked(state);
    if (io == 15) ui->IO_15->setChecked(state);
    if (io == 16) ui->IO_16->setChecked(state);
    if (io == 17) ui->IO_17->setChecked(state);
    if (io == 18) ui->IO_18->setChecked(state);
    if (io == 19) ui->IO_19->setChecked(state);
    if (io == 20) ui->IO_20->setChecked(state);
    if (io == 21) ui->IO_21->setChecked(state);
    if (io == 22) ui->IO_22->setChecked(state);
    if (io == 23) ui->IO_23->setChecked(state);
    if (io == 24) ui->IO_24->setChecked(state);
    if (io == 25) ui->IO_25->setChecked(state);
    if (io == 26) ui->IO_26->setChecked(state);
    if (io == 27) ui->IO_27->setChecked(state);
    if (io == 28) ui->IO_28->setChecked(state);
    if (io == 29) ui->IO_29->setChecked(state);
    if (io == 30) ui->IO_30->setChecked(state);
    if (io == 31) ui->IO_31->setChecked(state);
    if (io == 32) ui->IO_32->setChecked(state);
    if (io == 33) ui->IO_33->setChecked(state);
    if (io == 34) ui->IO_34->setChecked(state);
    if (io == 35) ui->IO_35->setChecked(state);
    if (io == 36) ui->IO_36->setChecked(state);
    if (io == 37) ui->IO_37->setChecked(state);
    if (io == 38) ui->IO_38->setChecked(state);
    if (io == 39) ui->IO_39->setChecked(state);
    if (io == 40) ui->IO_40->setChecked(state);
    if (io == 41) ui->IO_41->setChecked(state);
    if (io == 42) ui->IO_42->setChecked(state);
    if (io == 43) ui->IO_43->setChecked(state);
    if (io == 44) ui->IO_44->setChecked(state);
    if (io == 45) ui->IO_45->setChecked(state);
    if (io == 46) ui->IO_46->setChecked(state);
    if (io == 47) ui->IO_47->setChecked(state);
    if (io == 48) ui->IO_48->setChecked(state);
}

void MainWindow::on_lw_PTM_clicked() {
}
void MainWindow::on_lw_PTM_selection_changed() {
    int ptmID = 0;

    if (ui->lw_PTM->selectedItems().count() > 0) {

        int row = ui->lw_PTM->currentRow();
        //qDebug() << "row: " << row;

        QListWidgetItem* item = ui->lw_PTM->item(row);
        ptmID = item->text().toInt();
        emit on_ptm_change(ptmID);
    }
    else {
        ui->lw_PTM->setCurrentRow(ui->lw_PTM->count() - 1);
    }
}


void MainWindow::on_bu_addPTM_clicked() {
    int ptmID = ui->tb_ptmID->text().toInt();
    ui->tb_ptmID->clear();
    QString str_ptmID = QString::number(ptmID).rightJustified(5, '0');
    
    QList<QListWidgetItem*> items = ui->lw_PTM->findItems(str_ptmID, Qt::MatchExactly);
    if (items.size() == 0 and ptmID != 0) {
        ui->lw_PTM->addItem(str_ptmID);
        ui->lw_PTM->setCurrentRow(ui->lw_PTM->count() - 1);

        //PTM 
        sitipe_master.ptm.add(ptmID);
        emit on_ptm_change(ptmID);

        //qDebug() << "on_bu_addPTM_clicked----------------------- ";
        //qDebug() << "count: " << sitipe_master.ptm.id.count();

        //for (int i = 0; i < sitipe_master.ptm.id.count(); ++i) {
        //    qDebug() << "iterate ID: " << sitipe_master.ptm.id[i].ptmID;
        //}

    }
    else {
        QMessageBox msgBox;
        msgBox.critical(nullptr, "Inputerror!",
            "Fehlerhafte PTM-ID oder PTM-ID bereits vorhanden!");

    }
 

    /*
    QList<QListWidgetItem*> items = ui->lw_PTM->findItems(str_ptmID, Qt::MatchExactly);
    if (items.size() == 0 and ptmID != 0) {
        ui->lw_PTM->addItem(str_ptmID);
        ui->tb_ptmID->clear();
 
        QList<int> modules;
        for (int i = 0; i < ui->lw_PTM->count(); ++i) {
            QListWidgetItem* item = ui->lw_PTM->item(i);
            QString qitem = item->text();

            qDebug() << "PTM: " << qitem;
            modules.append(qitem.toInt());
            ui->lw_PTM->setCurrentItem(item);
        }
        emit on_update_ptm(modules);

    }
    else {
        QMessageBox msgBox;
        msgBox.critical(nullptr, "Inputerror!", 
            "Fehlerhafte PTM-ID oder PTM-ID bereits vorhanden!");
    }
    */
}

void MainWindow::on_bu_delPTM_clicked() {
    int ptmID = 0;
    if (ui->lw_PTM->selectedItems().size() > 0) {
        int row = ui->lw_PTM->currentRow();
        ui->lw_PTM->takeItem(row);

        //PTM 
        sitipe_master.ptm.del(row);
        if (ui->lw_PTM->selectedItems().size() > 0) 
            ptmID = sitipe_master.ptm.id[ui->lw_PTM->count() - 1].ptmID;
    }
        emit on_ptm_change(ptmID);


    //qDebug() << "on_bu_delPTM_clicked----------------------- ";
    //qDebug() << "count: " << sitipe_master.ptm.id.count();

    //for (int i = 0; i < sitipe_master.ptm.id.count(); ++i) {
    //    qDebug() << "iterate ID: " << sitipe_master.ptm.id[i].ptmID;
    //}



    /*
    QList<int> modules;
    for (int i = 0; i < ui->lw_PTM->count(); ++i) {
        QListWidgetItem* item = ui->lw_PTM->item(i);
        QString qitem = item->text();

        qDebug() << "PTM: " << qitem;
        modules.append(qitem.toInt());
        ui->lw_PTM->setCurrentItem(item);

    }
    emit on_update_ptm(modules);
    */
}

void MainWindow::on_setIO(int channel, bool value) {

}


void MainWindow::on_IO_1_clicked() {
    ui->IO_1->setChecked(ui->IO_1->isChecked());
    ui->IO_1->setEnabled(false);
    QListWidgetItem* item = ui->lw_PTM->currentItem();
    QString qitem = item->text();
    int id = qitem.toInt();
    qDebug() << "##############################" ;
    qDebug() << "row: " << id;
    qDebug() << "##############################";

    sitipe_master.masterTransmit_0001(0,id, 1, ui->IO_1->isChecked());

    //use ID from selected List entry
}



















//.....................................................
void MainWindow::on_commandTermination(string result) {
    //ui->tb_serverLog->append("callback received");
    //ui->tb_serverLog->append(QString::fromStdString(result));
}
//.....................................................
void MainWindow::receive_from_object(bool value) {
    qDebug() << "connecting... from client";
    //if (value) {
        //ui->tb_serverLog->append("receive true");
    //}
    //else {
        //ui->tb_serverLog->append("receive false");
    //}
}
