#include "mainwindow.h"


MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
    ui->setupUi(this);
 
    //Dialog Events
    QObject::connect(ui->lw_PTM, SIGNAL(itemSelectionChanged()),this, SLOT(on_lw_PTM_selection_changed()));

    //sitipe SOCKET -> mainwindow
    connect(&sitipe_socket, SIGNAL(do_writeTCPLog(QString, QColor, QColor)), this, SLOT(writeTCPLog(QString, QColor, QColor)));
    connect(&sitipe_socket, SIGNAL(do_setConnectionStatus(bool)), this, SLOT(setConnectionStatus(bool)));
    //mainwindow -> sitipe SOCKET
    connect(this, SIGNAL(on_ptm_change(int)), &sitipe_master, SLOT(ptm_change(int)));


    //sitipe MASTER -> mainwindow 
    connect(&sitipe_master, SIGNAL(do_writeTCPLog(QString, QColor, QColor)), this, SLOT(writeTCPLog(QString, QColor, QColor)));
    connect(&sitipe_master, SIGNAL(do_setIO()), this, SLOT(setIO()));
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

    ioGroup = new QButtonGroup(this);
    ioGroup->setExclusive(false);
    //ioGroup->addButton(ui->IO_1);
    
    for (int i = 0; i < 48; i++) {
        QString cbName = "IO_";
        cbName.append(QString::number(i + 1));
        QCheckBox* cb = ui->SITIPEMaster->findChild<QCheckBox*>(cbName);

        ioGroup->addButton(cb, i);
    }
    connect(ioGroup, SIGNAL(idClicked(int)), this, SLOT(on_ioGroup_clicked(int)));

    //connect(ioGroup, SIGNAL(buttonClicked(int)), this, SLOT(on_ioGroup_clicked(int)(int)));
    //connect(ioGroup, &QButtonGroup::idClicked, this, &MainWindow::on_ioGroup_clicked);

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

    ui->lw_serverLog->scrollToBottom();

    //ui->lw_serverLog->setAutoScroll(true);
}

//----------------------------


void MainWindow::on_ioGroup_clicked(int id) {
    qDebug() << "[MainWindow::on_ioGroup_clicked]----------------";
    qDebug() << "  id clicked " << id;

    QAbstractButton* cb = ioGroup->button(id);
    cb->setChecked(cb->isChecked());

    qDebug() << "  Object     " << cb->objectName();
    qDebug() << "  buttonID   " << id + 1;

    emit on_setIO(id + 1, cb->isChecked());
}

void MainWindow::setIO() {
    qDebug() << "[MainWindow::setIO]-------------------------";
    qDebug() << "  ptmCount: " << sitipe_master.ptm.index.count();
    if (sitipe_master.ptm.index.count() > 0) {
        int active_ptmListIndex = sitipe_master.ptm.active_ptmListIndex;
        qDebug() << "  active PTMListIndex: " << active_ptmListIndex;
        
        for (int i = 0; i < 48; i++) {
            QString cbName = "IO_";
            cbName.append(QString::number(i + 1));
            QCheckBox* cb = ui->SITIPEMaster->findChild<QCheckBox*>(cbName);

            //qDebug() << "    IO:  " << cb->objectName();
            //qDebug() << "    val: " << sitipe_master.ptm.index[active_ptmIndex].io[i].value;

            //cb->setChecked(true);
            cb->setChecked(sitipe_master.ptm.index[active_ptmListIndex].io[i].value);
        }
 
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

        qDebug() << "[MainWindow::on_lw_PTM_selection_changed]------------------";
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
        setIO();
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

        qDebug() << "[MainWindow::on_bu_delPTM_clicked]-----------------";
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

// add PTM Index

/*
void MainWindow::on_IO_1_clicked() {
    ui->IO_1->setChecked(ui->IO_1->isChecked());
    emit on_setIO(1, ui->IO_1->isChecked());
}
void MainWindow::on_IO_2_clicked() {
    ui->IO_2->setChecked(ui->IO_2->isChecked());
    emit on_setIO(2, ui->IO_2->isChecked());
}
void MainWindow::on_IO_3_clicked() {
    ui->IO_3->setChecked(ui->IO_3->isChecked());
    emit on_setIO(3, ui->IO_3->isChecked());
}
void MainWindow::on_IO_4_clicked() {
    ui->IO_4->setChecked(ui->IO_4->isChecked());
    emit on_setIO(4, ui->IO_4->isChecked());
}
void MainWindow::on_IO_5_clicked() {
    ui->IO_5->setChecked(ui->IO_5->isChecked());
    emit on_setIO(5, ui->IO_5->isChecked());
}
void MainWindow::on_IO_6_clicked() {
    ui->IO_6->setChecked(ui->IO_6->isChecked());
    emit on_setIO(6, ui->IO_6->isChecked());
}
void MainWindow::on_IO_7_clicked() {
    ui->IO_7->setChecked(ui->IO_7->isChecked());
    emit on_setIO(7, ui->IO_7->isChecked());
}
void MainWindow::on_IO_8_clicked() {
    ui->IO_8->setChecked(ui->IO_8->isChecked());
    emit on_setIO(8, ui->IO_8->isChecked());
}
void MainWindow::on_IO_9_clicked() {
    ui->IO_9->setChecked(ui->IO_9->isChecked());
    emit on_setIO(9, ui->IO_9->isChecked());
}
void MainWindow::on_IO_10_clicked() {
    ui->IO_10->setChecked(ui->IO_10->isChecked());
    emit on_setIO(10, ui->IO_10->isChecked());
}
void MainWindow::on_IO_11_clicked() {
    ui->IO_11->setChecked(ui->IO_11->isChecked());
    emit on_setIO(11, ui->IO_11->isChecked());
}
void MainWindow::on_IO_12_clicked() {
    ui->IO_12->setChecked(ui->IO_12->isChecked());
    emit on_setIO(12, ui->IO_12->isChecked());
}
void MainWindow::on_IO_13_clicked() {
    ui->IO_13->setChecked(ui->IO_13->isChecked());
    emit on_setIO(13, ui->IO_13->isChecked());
}
void MainWindow::on_IO_14_clicked() {
    ui->IO_14->setChecked(ui->IO_14->isChecked());
    emit on_setIO(14, ui->IO_14->isChecked());
}
void MainWindow::on_IO_15_clicked() {
    ui->IO_15->setChecked(ui->IO_15->isChecked());
    emit on_setIO(15, ui->IO_15->isChecked());
}
void MainWindow::on_IO_16_clicked() {
    ui->IO_16->setChecked(ui->IO_16->isChecked());
    emit on_setIO(16, ui->IO_16->isChecked());
}
void MainWindow::on_IO_17_clicked() {
    ui->IO_17->setChecked(ui->IO_17->isChecked());
    emit on_setIO(17, ui->IO_17->isChecked());
}
void MainWindow::on_IO_18_clicked() {
    ui->IO_18->setChecked(ui->IO_18->isChecked());
    emit on_setIO(18, ui->IO_18->isChecked());
}
void MainWindow::on_IO_19_clicked() {
    ui->IO_19->setChecked(ui->IO_19->isChecked());
    emit on_setIO(19, ui->IO_19->isChecked());
}
void MainWindow::on_IO_20_clicked() {
    ui->IO_20->setChecked(ui->IO_20->isChecked());
    emit on_setIO(20, ui->IO_20->isChecked());
}
void MainWindow::on_IO_21_clicked() {
    ui->IO_21->setChecked(ui->IO_21->isChecked());
    emit on_setIO(21, ui->IO_21->isChecked());
}
void MainWindow::on_IO_22_clicked() {
    ui->IO_22->setChecked(ui->IO_22->isChecked());
    emit on_setIO(22, ui->IO_22->isChecked());
}
void MainWindow::on_IO_23_clicked() {
    ui->IO_23->setChecked(ui->IO_23->isChecked());
    emit on_setIO(23, ui->IO_23->isChecked());
}
void MainWindow::on_IO_24_clicked() {
    ui->IO_24->setChecked(ui->IO_24->isChecked());
    emit on_setIO(24, ui->IO_24->isChecked());
}
void MainWindow::on_IO_25_clicked() {
    ui->IO_25->setChecked(ui->IO_25->isChecked());
    emit on_setIO(25, ui->IO_25->isChecked());
}
void MainWindow::on_IO_26_clicked() {
    ui->IO_26->setChecked(ui->IO_26->isChecked());
    emit on_setIO(26, ui->IO_26->isChecked());
}
void MainWindow::on_IO_27_clicked() {
    ui->IO_27->setChecked(ui->IO_27->isChecked());
    emit on_setIO(27, ui->IO_27->isChecked());
}
void MainWindow::on_IO_28_clicked() {
    ui->IO_28->setChecked(ui->IO_28->isChecked());
    emit on_setIO(28, ui->IO_28->isChecked());
}
void MainWindow::on_IO_29_clicked() {
    ui->IO_29->setChecked(ui->IO_29->isChecked());
    emit on_setIO(29, ui->IO_29->isChecked());
}
void MainWindow::on_IO_30_clicked() {
    ui->IO_30->setChecked(ui->IO_30->isChecked());
    emit on_setIO(30, ui->IO_30->isChecked());
}
void MainWindow::on_IO_31_clicked() {
    ui->IO_31->setChecked(ui->IO_31->isChecked());
    emit on_setIO(31, ui->IO_31->isChecked());
}
void MainWindow::on_IO_32_clicked() {
    ui->IO_32->setChecked(ui->IO_32->isChecked());
    emit on_setIO(32, ui->IO_32->isChecked());
}
void MainWindow::on_IO_33_clicked() {
    ui->IO_33->setChecked(ui->IO_33->isChecked());
    emit on_setIO(33, ui->IO_33->isChecked());
}
void MainWindow::on_IO_34_clicked() {
    ui->IO_34->setChecked(ui->IO_34->isChecked());
    emit on_setIO(34, ui->IO_34->isChecked());
}
void MainWindow::on_IO_35_clicked() {
    ui->IO_35->setChecked(ui->IO_35->isChecked());
    emit on_setIO(35, ui->IO_35->isChecked());
}
void MainWindow::on_IO_36_clicked() {
    ui->IO_36->setChecked(ui->IO_36->isChecked());
    emit on_setIO(36, ui->IO_36->isChecked());
}
void MainWindow::on_IO_37_clicked() {
    ui->IO_37->setChecked(ui->IO_37->isChecked());
    emit on_setIO(37, ui->IO_37->isChecked());
}
void MainWindow::on_IO_38_clicked() {
    ui->IO_38->setChecked(ui->IO_38->isChecked());
    emit on_setIO(38, ui->IO_38->isChecked());
}
void MainWindow::on_IO_39_clicked() {
    ui->IO_39->setChecked(ui->IO_39->isChecked());
    emit on_setIO(39, ui->IO_39->isChecked());
}
void MainWindow::on_IO_40_clicked() {
    ui->IO_40->setChecked(ui->IO_40->isChecked());
    emit on_setIO(40, ui->IO_40->isChecked());
}
void MainWindow::on_IO_41_clicked() {
    ui->IO_41->setChecked(ui->IO_41->isChecked());
    emit on_setIO(41, ui->IO_41->isChecked());
}
void MainWindow::on_IO_42_clicked() {
    ui->IO_42->setChecked(ui->IO_42->isChecked());
    emit on_setIO(42, ui->IO_42->isChecked());
}
void MainWindow::on_IO_43_clicked() {
    ui->IO_43->setChecked(ui->IO_43->isChecked());
    emit on_setIO(43, ui->IO_43->isChecked());
}
void MainWindow::on_IO_44_clicked() {
    ui->IO_44->setChecked(ui->IO_44->isChecked());
    emit on_setIO(44, ui->IO_44->isChecked());
}
void MainWindow::on_IO_45_clicked() {
    ui->IO_45->setChecked(ui->IO_45->isChecked());
    emit on_setIO(45, ui->IO_45->isChecked());
}
void MainWindow::on_IO_46_clicked() {
    ui->IO_46->setChecked(ui->IO_46->isChecked());
    emit on_setIO(46, ui->IO_46->isChecked());
}
void MainWindow::on_IO_47_clicked() {
    ui->IO_47->setChecked(ui->IO_47->isChecked());
    emit on_setIO(47, ui->IO_47->isChecked());
}
void MainWindow::on_IO_48_clicked() {
    ui->IO_48->setChecked(ui->IO_48->isChecked());
    emit on_setIO(48, ui->IO_48->isChecked());
}

*/

/*
 ui->IO_1->setChecked(sitipe_master.ptm.id[id].io[0].value);
 ui->IO_2->setChecked(sitipe_master.ptm.id[id].io[1].value);
 ui->IO_3->setChecked(sitipe_master.ptm.id[id].io[2].value);
 ui->IO_4->setChecked(sitipe_master.ptm.id[id].io[3].value);
 ui->IO_5->setChecked(sitipe_master.ptm.id[id].io[4].value);
 ui->IO_6->setChecked(sitipe_master.ptm.id[id].io[5].value);
 ui->IO_7->setChecked(sitipe_master.ptm.id[id].io[6].value);
 ui->IO_8->setChecked(sitipe_master.ptm.id[id].io[7].value);
 ui->IO_9->setChecked(sitipe_master.ptm.id[id].io[8].value);
 ui->IO_10->setChecked(sitipe_master.ptm.id[id].io[9].value);
 ui->IO_11->setChecked(sitipe_master.ptm.id[id].io[10].value);
 ui->IO_12->setChecked(sitipe_master.ptm.id[id].io[11].value);
 ui->IO_13->setChecked(sitipe_master.ptm.id[id].io[12].value);
 ui->IO_14->setChecked(sitipe_master.ptm.id[id].io[13].value);
 ui->IO_15->setChecked(sitipe_master.ptm.id[id].io[14].value);
 ui->IO_16->setChecked(sitipe_master.ptm.id[id].io[15].value);
 ui->IO_17->setChecked(sitipe_master.ptm.id[id].io[16].value);
 ui->IO_18->setChecked(sitipe_master.ptm.id[id].io[17].value);
 ui->IO_19->setChecked(sitipe_master.ptm.id[id].io[18].value);
 ui->IO_20->setChecked(sitipe_master.ptm.id[id].io[19].value);
 ui->IO_21->setChecked(sitipe_master.ptm.id[id].io[20].value);
 ui->IO_22->setChecked(sitipe_master.ptm.id[id].io[21].value);
 ui->IO_23->setChecked(sitipe_master.ptm.id[id].io[22].value);
 ui->IO_24->setChecked(sitipe_master.ptm.id[id].io[23].value);
 ui->IO_25->setChecked(sitipe_master.ptm.id[id].io[24].value);
 ui->IO_26->setChecked(sitipe_master.ptm.id[id].io[25].value);
 ui->IO_27->setChecked(sitipe_master.ptm.id[id].io[26].value);
 ui->IO_28->setChecked(sitipe_master.ptm.id[id].io[27].value);
 ui->IO_29->setChecked(sitipe_master.ptm.id[id].io[28].value);
 ui->IO_30->setChecked(sitipe_master.ptm.id[id].io[29].value);
 ui->IO_31->setChecked(sitipe_master.ptm.id[id].io[30].value);
 ui->IO_32->setChecked(sitipe_master.ptm.id[id].io[31].value);
 ui->IO_33->setChecked(sitipe_master.ptm.id[id].io[32].value);
 ui->IO_34->setChecked(sitipe_master.ptm.id[id].io[33].value);
 ui->IO_35->setChecked(sitipe_master.ptm.id[id].io[34].value);
 ui->IO_36->setChecked(sitipe_master.ptm.id[id].io[35].value);
 ui->IO_37->setChecked(sitipe_master.ptm.id[id].io[36].value);
 ui->IO_38->setChecked(sitipe_master.ptm.id[id].io[37].value);
 ui->IO_39->setChecked(sitipe_master.ptm.id[id].io[38].value);
 ui->IO_40->setChecked(sitipe_master.ptm.id[id].io[39].value);
 ui->IO_41->setChecked(sitipe_master.ptm.id[id].io[40].value);
 ui->IO_42->setChecked(sitipe_master.ptm.id[id].io[41].value);
 ui->IO_43->setChecked(sitipe_master.ptm.id[id].io[42].value);
 ui->IO_44->setChecked(sitipe_master.ptm.id[id].io[43].value);
 ui->IO_45->setChecked(sitipe_master.ptm.id[id].io[44].value);
 ui->IO_46->setChecked(sitipe_master.ptm.id[id].io[45].value);
 ui->IO_47->setChecked(sitipe_master.ptm.id[id].io[46].value);
 ui->IO_48->setChecked(sitipe_master.ptm.id[id].io[47].value);
 */

