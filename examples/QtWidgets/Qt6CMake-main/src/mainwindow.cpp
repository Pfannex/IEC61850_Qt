#include "mainwindow.h"


MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //TcpServerThread* t = new TcpServerThread();

 
    //Dialog Events
    QObject::connect(ui->lw_PTM, SIGNAL(itemSelectionChanged()), this, SLOT(on_lw_PTM_selection_changed()));

//----[ SITIPE Master Client ]-----------------------
    //sitipe SOCKET -> mainwindow
    connect(&sitipe_socket, SIGNAL(do_writePTMLog(QString, QColor, QColor)), this, SLOT(writePTMLog(QString, QColor, QColor)));
    connect(&sitipe_socket, SIGNAL(do_setConnectionStatus(bool)), this, SLOT(setConnectionStatus(bool)));
    //mainwindow -> sitipe SOCKET
    connect(this, SIGNAL(on_ptm_change(int)), &sitipe_master, SLOT(ptm_change(int)));

    //sitipe MASTER -> mainwindow 
    connect(&sitipe_master, SIGNAL(do_writePTMLog(QString, QColor, QColor)), this, SLOT(writePTMLog(QString, QColor, QColor)));
    connect(&sitipe_master, SIGNAL(do_setPTMstate()), this, SLOT(setPTMstate()));
    //mainwindow -> sitipe MASTER
    connect(this, SIGNAL(on_setIO(int, bool)), &sitipe_master, SLOT(setIO(int, bool)));
    connect(this, SIGNAL(on_setIO(QByteArray)), &sitipe_master, SLOT(setIO(QByteArray)));
    connect(this, SIGNAL(on_bu_TEST_clicked()), &sitipe_master, SLOT(TEST()));

    //sitipe SOCKET -> sitipe MASTER
    connect(&sitipe_socket, SIGNAL(do_setConnectionStatus(bool)), &sitipe_master, SLOT(updateSocketState(bool)));
    connect(&sitipe_socket, SIGNAL(do_receiveFrame(QByteArray)), &sitipe_master, SLOT(receiveFrame(QByteArray)));
    //sitipe MASTER -> sitipe SOCKET
    connect(&sitipe_master, SIGNAL(sendFrame(QByteArray)), &sitipe_socket, SLOT(write(QByteArray)));
    
    //sitipe MASTER <-> sitipe SLAVE
    connect(&sitipe_master, SIGNAL(do_sendToSlave(QByteArray)), &sitipe_slave, SLOT(write(QByteArray)));
    connect(&sitipe_slave, SIGNAL(do_sendToMaster(QByteArray, bool)), &sitipe_master, SLOT(writeToSlave(QByteArray, bool)));


//----[ SITIPE Slave Server ]-----------------------
    //104Server -> mainwindow
    connect(&sitipe_slave, &SITIPE_Slave::do_writeSTSLog, this, &MainWindow::writeSTSLog);
    //connect(&sitipe_master, SIGNAL(do_writePTMLog(QString, QColor, QColor)), this, SLOT(writePTMLog(QString, QColor, QColor)));
    //connect(&sitipe_socket, SIGNAL(do_setConnectionStatus(bool)), this, SLOT(setConnectionStatus(bool)));
    //mainwindow -> 104ServerT
    //connect(this, SIGNAL(on_ptm_change(int)), &sitipe_master, SLOT(ptm_change(int)));

//----[ 104 Server ]-----------------------
    //104Server -> mainwindow
    connect(&iec104, &IEC104_Server::do_write104Log, this, &MainWindow::write104Log);
    //connect(&sitipe_master, SIGNAL(do_writePTMLog(QString, QColor, QColor)), this, SLOT(writePTMLog(QString, QColor, QColor)));
    //connect(&sitipe_socket, SIGNAL(do_setConnectionStatus(bool)), this, SLOT(setConnectionStatus(bool)));
    //mainwindow -> 104ServerT
    //connect(this, SIGNAL(on_ptm_change(int)), &sitipe_master, SLOT(ptm_change(int)));



    //OUTPUT
    outputGroup = new QButtonGroup(this);
    outputGroup->setExclusive(false);
    for (int i = 0; i < 48; i++) {
        QString cbName = "out_";
        cbName.append(QString::number(i + 1));
        QPushButton* cb = ui->SITIPEMaster->findChild<QPushButton*>(cbName);

        outputGroup->addButton(cb, i);
    }
    //inputGroup->addButton(ui->bu_IO_1, 100);
    connect(outputGroup, SIGNAL(idClicked(int)), this, SLOT(on_outputGroup_clicked(int)));

    //INPUT
    inputGroup = new QButtonGroup(this);
    inputGroup->setExclusive(false);
    for (int i = 0; i < 48; i++) {
        QString cbName = "in_";
        cbName.append(QString::number(i + 1));
        QCheckBox* cb = ui->SITIPEMaster->findChild<QCheckBox*>(cbName);

        inputGroup->addButton(cb, i);
    }


    ioUpdate = new QButtonGroup(this);
    ioUpdate->addButton(ui->rb_singleTransmit, 0);
    ioUpdate->addButton(ui->rb_groupTransmit, 1);
    connect(ioUpdate, SIGNAL(idClicked(int)), this, SLOT(on_ioUpdate_clicked(int)));

    //connect(ioGroup, SIGNAL(buttonClicked(int)), this, SLOT(on_ioGroup_clicked(int)(int)));
    //connect(ioGroup, &QButtonGroup::idClicked, this, &MainWindow::on_ioGroup_clicked);
    // 
    
 }

MainWindow::~MainWindow()
{
    //client.close();
    delete ui;
}


//#############################################################################
// SITIPE Master
//#############################################################################

void MainWindow::on_bu_close_clicked() {
    close();
}
void MainWindow::on_bu_connect_clicked() {
    if (sitipe_master.ptm.index.count() > 0)
        sitipe_socket.doConnect(ui->tb_ptmServerIp->text(), ui->tb_ptmServerPort->text().toInt());
}
void MainWindow::on_bu_disconnect_clicked() {
    sitipe_master.masterQuit_0003(0);
    sitipe_socket.doDisconnect();
}
void MainWindow::setConnectionStatus(bool value) {
    ui->cb_online->setChecked(value);
}


void MainWindow::writePTMLog(QString txt, QColor fColor, QColor bColor) {
    ui->lw_PTMserverLog->addItem(txt);
    ui->lw_PTMserverLog->item(ui->lw_PTMserverLog->count() - 1)->setForeground(bColor);
    ui->lw_PTMserverLog->item(ui->lw_PTMserverLog->count() - 1)->setBackground(fColor);

    ui->lw_PTMserverLog->scrollToBottom();

    //ui->lw_serverLog->setAutoScroll(true);
}

//----------------------------


void MainWindow::on_outputGroup_clicked(int id) {
    qDebug() << "--------------------------------------------------------";
    qDebug() << "[MainWindow::on_outputGroup_clicked]";
    qDebug() << "  id clicked " << id;

    QAbstractButton* bu = outputGroup->button(id);
    qDebug() << "  class      " << bu->metaObject()->className();

    /*
    if (cb->metaObject()->className() == QString("QPushButton")) {
        qDebug() << "isPushButton";
    }
    else if (cb->metaObject()->className() == QString("QCheckBox")) {
        qDebug() << "isCheckBox";
    }
    */
  
    //bu->setChecked(bu->isChecked());

    qDebug() << "  Object              " << bu->objectName();
    qDebug() << "  buttonID            " << id;
    qDebug() << "  active_ptmListIndex " << sitipe_master.ptm.active_ptmListIndex;

    sitipe_master.ptm.index[sitipe_master.ptm.active_ptmListIndex].io[id].outValue = bu->isChecked();
    if (ui->rb_singleTransmit->isChecked()) emit on_setIO(id + 1, bu->isChecked());
}

void MainWindow::on_ioUpdate_clicked(int id) {
    qDebug() << "--------------------------------------------------------";
    qDebug() << "[MainWindow::on_ioUpdate_clicked]";
    qDebug() << "  id clicked " << id;

    QAbstractButton* rb = ioUpdate->button(id);
    qDebug() << "  Object     " << rb->objectName();
    qDebug() << "  buttonID   " << id + 1;

    if (ui->rb_groupTransmit->isChecked()) ui->bu_setGroup->setEnabled(true);
    else ui->bu_setGroup->setEnabled(false);
}

void MainWindow::on_bu_setGroup_clicked() {
    qDebug() << "--------------------------------------------------------";
    qDebug() << "[MainWindow::on_bu_setGroup_clicked]";

    QByteArray io;
    for (int i = 0; i < 48; i++) {
        QAbstractButton* bu = outputGroup->button(i);
        io.append(bu->isChecked());

    }
    emit on_setIO(io);
}


void MainWindow::setPTMstate() {
    qDebug() << "--------------------------------------------------------";
    qDebug() << "[MainWindow::setPTMstate]";
    qDebug() << "  ptmCount: " << sitipe_master.ptm.index.count();
    if (sitipe_master.ptm.index.count() > 0) {
        int active_ptmListIndex = sitipe_master.ptm.active_ptmListIndex;
        qDebug() << "  active PTMListIndex: " << active_ptmListIndex;
        
        for (int i = 0; i < 48; i++) {
            QString cbName = "in_";
            cbName.append(QString::number(i + 1));
            QCheckBox* cb = ui->SITIPEMaster->findChild<QCheckBox*>(cbName);

            //qDebug() << "    IO:  " << cb->objectName();
            //qDebug() << "    val: " << sitipe_master.ptm.index[active_ptmListIndex].io[i].value;

            //cb->setChecked(true);
            cb->setChecked(sitipe_master.ptm.index[active_ptmListIndex].io[i].inValue);

            QString buName = "out_";
            buName.append(QString::number(i + 1));
            QPushButton* bu = ui->SITIPEMaster->findChild<QPushButton*>(buName);

            //qDebug() << "    IO:  " << bu->objectName();
            //qDebug() << "    val: " << sitipe_master.ptm.index[active_ptmListIndex].io[i].value;

            //cb->setChecked(true);
            bu->setChecked(sitipe_master.ptm.index[active_ptmListIndex].io[i].outValue);

        }
        ui->cb_ptmonline->setChecked(sitipe_master.ptm.index[active_ptmListIndex].connected);
    }
}

void MainWindow::on_lw_PTM_selection_changed() {
    int ptmID = -1;

    if ((ui->lw_PTM->selectedItems().count() > 0) and 
        (sitipe_master.ptm.index.count() == ui->lw_PTM->count())) {

        int row = ui->lw_PTM->currentRow();
        //qDebug() << "row: " << row;

        QListWidgetItem* item = ui->lw_PTM->item(row);
        ptmID = item->text().toInt();

        qDebug() << "--------------------------------------------------------";
        qDebug() << "[MainWindow::on_lw_PTM_selection_changed]";
        qDebug() << "  ptmID:        " << ptmID;
        qDebug() << "  list count:   " << ui->lw_PTM->count();
        qDebug() << "  ptm count:    " << sitipe_master.ptm.index.count();

        //update index
        for (int i = 0; i < ui->lw_PTM->count(); i++) {
            qDebug() << "  index: " << i
                << " List: " << ui->lw_PTM->item(i)->text()
                << " PTM: " << sitipe_master.ptm.index[i].str_ptmID;
        }
        emit on_ptm_change(ptmID);
        setPTMstate();
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
        sitipe_master.ptm.add(ptmID, ui->lw_PTM->currentRow());
        emit on_ptm_change(ptmID);
    }
    else {
        QMessageBox msgBox;
        msgBox.critical(nullptr, "Inputerror!",
            "Fehlerhafte PTM-ID oder PTM-ID bereits vorhanden!");
    }
    ui->tb_ptmID->setFocus();
}

void MainWindow::on_bu_delPTM_clicked() {
    int ptmID = -1;
    if (ui->lw_PTM->selectedItems().size() > 0) {
        int index = ui->lw_PTM->currentRow();
        QString delPTM = ui->lw_PTM->item(index)->text();
        ui->lw_PTM->takeItem(index);

        qDebug() << "--------------------------------------------------------";
        qDebug() << "[MainWindow::on_bu_delPTM_clicked]";
        qDebug() << "  del Index: " << index;
        qDebug() << "  del PTM:   " << delPTM;

        //PTM 
        sitipe_master.ptm.del(index);

        /*
        qDebug() << "  ---------" ;
        qDebug() << "  list count:   " << ui->lw_PTM->count();
        qDebug() << "  ptm count:    " << sitipe_master.ptm.id.count();

        //update index
        for (int i = 0; i < ui->lw_PTM->count(); i++) {
            qDebug() << "  index: " << i 
                << " List: " << ui->lw_PTM->item(i)->text()
                << " PTM: " << sitipe_master.ptm.id[i].str_ptmID;
        }
        */

        if (ui->lw_PTM->selectedItems().size() > 0) {
            ui->lw_PTM->setCurrentRow(0);

            ptmID = sitipe_master.ptm.index[0].ptmID;
            on_lw_PTM_selection_changed();
        }
    }
    //emit on_ptm_change(ptmID);

}

//#############################################################################
// SITIPE Slave Server handle
//#############################################################################
void MainWindow::writeSTSLog(QString txt, QColor fColor, QColor bColor) {
    ui->lw_STSserverLog->addItem(txt);
    ui->lw_STSserverLog->item(ui->lw_STSserverLog->count() - 1)->setForeground(bColor);
    ui->lw_STSserverLog->item(ui->lw_STSserverLog->count() - 1)->setBackground(fColor);

    ui->lw_STSserverLog->scrollToBottom();

    //ui->lw_serverLog->setAutoScroll(true);

}

void MainWindow::on_bu_openSTSServer_clicked() {
    qDebug() << "--------------------------------------------------------";
    qDebug() << "[MainWindow::on_bu_openSTSServer_clicked()]";
    quint16 port = ui->tb_STSport->text().toUInt();
    qDebug() << "Port to open: " << port;

    sitipe_slave.open(port);

}
void MainWindow::on_bu_closeSTSServer_clicked() {
    qDebug() << "--------------------------------------------------------";
    qDebug() << "[MainWindow::on_bu_closeSTSServer_clicked()]";
    sitipe_slave.close();

}


//#############################################################################
// IEC 61870-5-104 Server handle
//#############################################################################
void MainWindow::write104Log(QString txt, QColor fColor, QColor bColor) {
    ui->lw_104serverLog->addItem(txt);
    ui->lw_104serverLog->item(ui->lw_104serverLog->count() - 1)->setForeground(bColor);
    ui->lw_104serverLog->item(ui->lw_104serverLog->count() - 1)->setBackground(fColor);

    ui->lw_104serverLog->scrollToBottom();

    //ui->lw_serverLog->setAutoScroll(true);

}

void MainWindow::on_bu_open104Server_clicked() {
    qDebug() << "--------------------------------------------------------";
    qDebug() << "[MainWindow::on_bu_open104Server_clicked()]";
    quint16 port = ui->tb_104port->text().toUInt();
    qDebug() << "Port to open: " << port;

    iec104.open(port);

}
void MainWindow::on_bu_close104Server_clicked() {
    qDebug() << "--------------------------------------------------------";
    qDebug() << "[MainWindow::on_bu_close104Server_clicked()]";
    iec104.close();

}


