/********************************************************************************
** Form generated from reading UI file 'mainwindowpKDGdt.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAINWINDOWPKDGDT_H
#define MAINWINDOWPKDGDT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *SITIPEMaster;
    QPushButton *bu_connect;
    QLineEdit *tb_serverIp;
    QLabel *label;
    QLineEdit *tb_port;
    QLabel *label_3;
    QPushButton *bu_disconnect;
    QListWidget *lw_PTM;
    QFrame *line;
    QLabel *label_4;
    QPushButton *bu_addPTM;
    QPushButton *bu_delPTM;
    QPushButton *bu_close;
    QWidget *layoutWidget;
    QGridLayout *IO_grid;
    QCheckBox *IO_1;
    QCheckBox *IO_11;
    QCheckBox *IO_21;
    QCheckBox *IO_31;
    QCheckBox *IO_41;
    QCheckBox *IO_2;
    QCheckBox *IO_12;
    QCheckBox *IO_22;
    QCheckBox *IO_32;
    QCheckBox *IO_42;
    QCheckBox *IO_3;
    QCheckBox *IO_13;
    QCheckBox *IO_23;
    QCheckBox *IO_33;
    QCheckBox *IO_43;
    QCheckBox *IO_4;
    QCheckBox *IO_14;
    QCheckBox *IO_24;
    QCheckBox *IO_34;
    QCheckBox *IO_44;
    QCheckBox *IO_5;
    QCheckBox *IO_15;
    QCheckBox *IO_25;
    QCheckBox *IO_35;
    QCheckBox *IO_45;
    QCheckBox *IO_6;
    QCheckBox *IO_16;
    QCheckBox *IO_26;
    QCheckBox *IO_36;
    QCheckBox *IO_46;
    QCheckBox *IO_7;
    QCheckBox *IO_17;
    QCheckBox *IO_27;
    QCheckBox *IO_37;
    QCheckBox *IO_47;
    QCheckBox *IO_8;
    QCheckBox *IO_18;
    QCheckBox *IO_28;
    QCheckBox *IO_38;
    QCheckBox *IO_48;
    QCheckBox *IO_9;
    QCheckBox *IO_19;
    QCheckBox *IO_29;
    QCheckBox *IO_39;
    QCheckBox *IO_10;
    QCheckBox *IO_20;
    QCheckBox *IO_30;
    QCheckBox *IO_40;
    QLineEdit *tb_ptmID;
    QCheckBox *cb_online;
    QPushButton *bu_KITT;
    QPushButton *bu_TEST;
    QListWidget *lw_serverLog;
    QCheckBox *cb_ptmonline;
    QWidget *MMSServer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(850, 516);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        SITIPEMaster = new QWidget();
        SITIPEMaster->setObjectName(QString::fromUtf8("SITIPEMaster"));
        bu_connect = new QPushButton(SITIPEMaster);
        bu_connect->setObjectName(QString::fromUtf8("bu_connect"));
        bu_connect->setGeometry(QRect(79, 43, 110, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Calibri")});
        font.setPointSize(14);
        bu_connect->setFont(font);
        tb_serverIp = new QLineEdit(SITIPEMaster);
        tb_serverIp->setObjectName(QString::fromUtf8("tb_serverIp"));
        tb_serverIp->setGeometry(QRect(80, 16, 151, 22));
        tb_serverIp->setFont(font);
        tb_serverIp->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label = new QLabel(SITIPEMaster);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 13, 81, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Calibri")});
        font1.setPointSize(12);
        label->setFont(font1);
        tb_port = new QLineEdit(SITIPEMaster);
        tb_port->setObjectName(QString::fromUtf8("tb_port"));
        tb_port->setGeometry(QRect(240, 16, 71, 22));
        tb_port->setFont(font);
        tb_port->setCursorPosition(5);
        tb_port->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_3 = new QLabel(SITIPEMaster);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(233, 10, 21, 31));
        label_3->setFont(font1);
        bu_disconnect = new QPushButton(SITIPEMaster);
        bu_disconnect->setObjectName(QString::fromUtf8("bu_disconnect"));
        bu_disconnect->setGeometry(QRect(200, 43, 110, 31));
        bu_disconnect->setFont(font);
        bu_disconnect->setFlat(false);
        lw_PTM = new QListWidget(SITIPEMaster);
        lw_PTM->setObjectName(QString::fromUtf8("lw_PTM"));
        lw_PTM->setGeometry(QRect(350, 110, 71, 261));
        lw_PTM->setFont(font);
        lw_PTM->setItemAlignment(Qt::AlignRight);
        line = new QFrame(SITIPEMaster);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(320, 20, 20, 351));
        line->setFrameShadow(QFrame::Plain);
        line->setLineWidth(3);
        line->setFrameShape(QFrame::VLine);
        label_4 = new QLabel(SITIPEMaster);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(350, 10, 91, 31));
        label_4->setFont(font1);
        bu_addPTM = new QPushButton(SITIPEMaster);
        bu_addPTM->setObjectName(QString::fromUtf8("bu_addPTM"));
        bu_addPTM->setGeometry(QRect(350, 40, 30, 30));
        bu_addPTM->setFont(font);
        bu_addPTM->setIconSize(QSize(30, 30));
        bu_addPTM->setFlat(false);
        bu_delPTM = new QPushButton(SITIPEMaster);
        bu_delPTM->setObjectName(QString::fromUtf8("bu_delPTM"));
        bu_delPTM->setGeometry(QRect(390, 40, 30, 30));
        bu_delPTM->setFont(font);
        bu_delPTM->setIconSize(QSize(30, 30));
        bu_delPTM->setFlat(false);
        bu_close = new QPushButton(SITIPEMaster);
        bu_close->setObjectName(QString::fromUtf8("bu_close"));
        bu_close->setGeometry(QRect(10, 380, 811, 41));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(bu_close->sizePolicy().hasHeightForWidth());
        bu_close->setSizePolicy(sizePolicy1);
        layoutWidget = new QWidget(SITIPEMaster);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(440, 85, 381, 281));
        IO_grid = new QGridLayout(layoutWidget);
        IO_grid->setObjectName(QString::fromUtf8("IO_grid"));
        IO_grid->setContentsMargins(0, 0, 0, 0);
        IO_1 = new QCheckBox(layoutWidget);
        IO_1->setObjectName(QString::fromUtf8("IO_1"));
        IO_1->setStyleSheet(QString::fromUtf8(""));
        IO_1->setText(QString::fromUtf8("01"));
        IO_1->setIconSize(QSize(30, 30));
        IO_1->setCheckable(true);
        IO_1->setTristate(false);

        IO_grid->addWidget(IO_1, 0, 0, 1, 1);

        IO_11 = new QCheckBox(layoutWidget);
        IO_11->setObjectName(QString::fromUtf8("IO_11"));
        IO_11->setStyleSheet(QString::fromUtf8(""));
        IO_11->setIconSize(QSize(30, 30));
        IO_11->setCheckable(true);

        IO_grid->addWidget(IO_11, 0, 1, 1, 1);

        IO_21 = new QCheckBox(layoutWidget);
        IO_21->setObjectName(QString::fromUtf8("IO_21"));
        IO_21->setStyleSheet(QString::fromUtf8(""));
        IO_21->setIconSize(QSize(30, 30));
        IO_21->setCheckable(true);

        IO_grid->addWidget(IO_21, 0, 2, 1, 1);

        IO_31 = new QCheckBox(layoutWidget);
        IO_31->setObjectName(QString::fromUtf8("IO_31"));
        IO_31->setStyleSheet(QString::fromUtf8(""));
        IO_31->setIconSize(QSize(30, 30));
        IO_31->setCheckable(true);

        IO_grid->addWidget(IO_31, 0, 3, 1, 1);

        IO_41 = new QCheckBox(layoutWidget);
        IO_41->setObjectName(QString::fromUtf8("IO_41"));
        IO_41->setStyleSheet(QString::fromUtf8(""));
        IO_41->setIconSize(QSize(30, 30));
        IO_41->setCheckable(true);

        IO_grid->addWidget(IO_41, 0, 4, 1, 1);

        IO_2 = new QCheckBox(layoutWidget);
        IO_2->setObjectName(QString::fromUtf8("IO_2"));
        IO_2->setStyleSheet(QString::fromUtf8(""));
        IO_2->setIconSize(QSize(30, 30));
        IO_2->setCheckable(true);

        IO_grid->addWidget(IO_2, 1, 0, 1, 1);

        IO_12 = new QCheckBox(layoutWidget);
        IO_12->setObjectName(QString::fromUtf8("IO_12"));
        IO_12->setStyleSheet(QString::fromUtf8(""));
        IO_12->setIconSize(QSize(30, 30));
        IO_12->setCheckable(true);

        IO_grid->addWidget(IO_12, 1, 1, 1, 1);

        IO_22 = new QCheckBox(layoutWidget);
        IO_22->setObjectName(QString::fromUtf8("IO_22"));
        IO_22->setStyleSheet(QString::fromUtf8(""));
        IO_22->setIconSize(QSize(30, 30));
        IO_22->setCheckable(true);

        IO_grid->addWidget(IO_22, 1, 2, 1, 1);

        IO_32 = new QCheckBox(layoutWidget);
        IO_32->setObjectName(QString::fromUtf8("IO_32"));
        IO_32->setStyleSheet(QString::fromUtf8(""));
        IO_32->setIconSize(QSize(30, 30));
        IO_32->setCheckable(true);

        IO_grid->addWidget(IO_32, 1, 3, 1, 1);

        IO_42 = new QCheckBox(layoutWidget);
        IO_42->setObjectName(QString::fromUtf8("IO_42"));
        IO_42->setStyleSheet(QString::fromUtf8(""));
        IO_42->setIconSize(QSize(30, 30));
        IO_42->setCheckable(true);

        IO_grid->addWidget(IO_42, 1, 4, 1, 1);

        IO_3 = new QCheckBox(layoutWidget);
        IO_3->setObjectName(QString::fromUtf8("IO_3"));
        IO_3->setStyleSheet(QString::fromUtf8(""));
        IO_3->setIconSize(QSize(30, 30));
        IO_3->setCheckable(true);

        IO_grid->addWidget(IO_3, 2, 0, 1, 1);

        IO_13 = new QCheckBox(layoutWidget);
        IO_13->setObjectName(QString::fromUtf8("IO_13"));
        IO_13->setStyleSheet(QString::fromUtf8(""));
        IO_13->setIconSize(QSize(30, 30));
        IO_13->setCheckable(true);

        IO_grid->addWidget(IO_13, 2, 1, 1, 1);

        IO_23 = new QCheckBox(layoutWidget);
        IO_23->setObjectName(QString::fromUtf8("IO_23"));
        IO_23->setStyleSheet(QString::fromUtf8(""));
        IO_23->setIconSize(QSize(30, 30));
        IO_23->setCheckable(true);

        IO_grid->addWidget(IO_23, 2, 2, 1, 1);

        IO_33 = new QCheckBox(layoutWidget);
        IO_33->setObjectName(QString::fromUtf8("IO_33"));
        IO_33->setStyleSheet(QString::fromUtf8(""));
        IO_33->setIconSize(QSize(30, 30));
        IO_33->setCheckable(true);

        IO_grid->addWidget(IO_33, 2, 3, 1, 1);

        IO_43 = new QCheckBox(layoutWidget);
        IO_43->setObjectName(QString::fromUtf8("IO_43"));
        IO_43->setStyleSheet(QString::fromUtf8(""));
        IO_43->setIconSize(QSize(30, 30));
        IO_43->setCheckable(true);

        IO_grid->addWidget(IO_43, 2, 4, 1, 1);

        IO_4 = new QCheckBox(layoutWidget);
        IO_4->setObjectName(QString::fromUtf8("IO_4"));
        IO_4->setStyleSheet(QString::fromUtf8(""));
        IO_4->setIconSize(QSize(30, 30));
        IO_4->setCheckable(true);

        IO_grid->addWidget(IO_4, 3, 0, 1, 1);

        IO_14 = new QCheckBox(layoutWidget);
        IO_14->setObjectName(QString::fromUtf8("IO_14"));
        IO_14->setStyleSheet(QString::fromUtf8(""));
        IO_14->setIconSize(QSize(30, 30));
        IO_14->setCheckable(true);

        IO_grid->addWidget(IO_14, 3, 1, 1, 1);

        IO_24 = new QCheckBox(layoutWidget);
        IO_24->setObjectName(QString::fromUtf8("IO_24"));
        IO_24->setStyleSheet(QString::fromUtf8(""));
        IO_24->setIconSize(QSize(30, 30));
        IO_24->setCheckable(true);

        IO_grid->addWidget(IO_24, 3, 2, 1, 1);

        IO_34 = new QCheckBox(layoutWidget);
        IO_34->setObjectName(QString::fromUtf8("IO_34"));
        IO_34->setStyleSheet(QString::fromUtf8(""));
        IO_34->setIconSize(QSize(30, 30));
        IO_34->setCheckable(true);

        IO_grid->addWidget(IO_34, 3, 3, 1, 1);

        IO_44 = new QCheckBox(layoutWidget);
        IO_44->setObjectName(QString::fromUtf8("IO_44"));
        IO_44->setStyleSheet(QString::fromUtf8(""));
        IO_44->setIconSize(QSize(30, 30));
        IO_44->setCheckable(true);

        IO_grid->addWidget(IO_44, 3, 4, 1, 1);

        IO_5 = new QCheckBox(layoutWidget);
        IO_5->setObjectName(QString::fromUtf8("IO_5"));
        IO_5->setStyleSheet(QString::fromUtf8(""));
        IO_5->setIconSize(QSize(30, 30));
        IO_5->setCheckable(true);

        IO_grid->addWidget(IO_5, 4, 0, 1, 1);

        IO_15 = new QCheckBox(layoutWidget);
        IO_15->setObjectName(QString::fromUtf8("IO_15"));
        IO_15->setStyleSheet(QString::fromUtf8(""));
        IO_15->setIconSize(QSize(30, 30));
        IO_15->setCheckable(true);

        IO_grid->addWidget(IO_15, 4, 1, 1, 1);

        IO_25 = new QCheckBox(layoutWidget);
        IO_25->setObjectName(QString::fromUtf8("IO_25"));
        IO_25->setStyleSheet(QString::fromUtf8(""));
        IO_25->setIconSize(QSize(30, 30));
        IO_25->setCheckable(true);

        IO_grid->addWidget(IO_25, 4, 2, 1, 1);

        IO_35 = new QCheckBox(layoutWidget);
        IO_35->setObjectName(QString::fromUtf8("IO_35"));
        IO_35->setStyleSheet(QString::fromUtf8(""));
        IO_35->setIconSize(QSize(30, 30));
        IO_35->setCheckable(true);

        IO_grid->addWidget(IO_35, 4, 3, 1, 1);

        IO_45 = new QCheckBox(layoutWidget);
        IO_45->setObjectName(QString::fromUtf8("IO_45"));
        IO_45->setStyleSheet(QString::fromUtf8(""));
        IO_45->setIconSize(QSize(30, 30));
        IO_45->setCheckable(true);

        IO_grid->addWidget(IO_45, 4, 4, 1, 1);

        IO_6 = new QCheckBox(layoutWidget);
        IO_6->setObjectName(QString::fromUtf8("IO_6"));
        IO_6->setStyleSheet(QString::fromUtf8(""));
        IO_6->setIconSize(QSize(30, 30));
        IO_6->setCheckable(true);

        IO_grid->addWidget(IO_6, 5, 0, 1, 1);

        IO_16 = new QCheckBox(layoutWidget);
        IO_16->setObjectName(QString::fromUtf8("IO_16"));
        IO_16->setStyleSheet(QString::fromUtf8(""));
        IO_16->setIconSize(QSize(30, 30));
        IO_16->setCheckable(true);

        IO_grid->addWidget(IO_16, 5, 1, 1, 1);

        IO_26 = new QCheckBox(layoutWidget);
        IO_26->setObjectName(QString::fromUtf8("IO_26"));
        IO_26->setStyleSheet(QString::fromUtf8(""));
        IO_26->setIconSize(QSize(30, 30));
        IO_26->setCheckable(true);

        IO_grid->addWidget(IO_26, 5, 2, 1, 1);

        IO_36 = new QCheckBox(layoutWidget);
        IO_36->setObjectName(QString::fromUtf8("IO_36"));
        IO_36->setStyleSheet(QString::fromUtf8(""));
        IO_36->setIconSize(QSize(30, 30));
        IO_36->setCheckable(true);

        IO_grid->addWidget(IO_36, 5, 3, 1, 1);

        IO_46 = new QCheckBox(layoutWidget);
        IO_46->setObjectName(QString::fromUtf8("IO_46"));
        IO_46->setStyleSheet(QString::fromUtf8(""));
        IO_46->setIconSize(QSize(30, 30));
        IO_46->setCheckable(true);

        IO_grid->addWidget(IO_46, 5, 4, 1, 1);

        IO_7 = new QCheckBox(layoutWidget);
        IO_7->setObjectName(QString::fromUtf8("IO_7"));
        IO_7->setStyleSheet(QString::fromUtf8(""));
        IO_7->setIconSize(QSize(30, 30));
        IO_7->setCheckable(true);

        IO_grid->addWidget(IO_7, 6, 0, 1, 1);

        IO_17 = new QCheckBox(layoutWidget);
        IO_17->setObjectName(QString::fromUtf8("IO_17"));
        IO_17->setStyleSheet(QString::fromUtf8(""));
        IO_17->setIconSize(QSize(30, 30));
        IO_17->setCheckable(true);

        IO_grid->addWidget(IO_17, 6, 1, 1, 1);

        IO_27 = new QCheckBox(layoutWidget);
        IO_27->setObjectName(QString::fromUtf8("IO_27"));
        IO_27->setStyleSheet(QString::fromUtf8(""));
        IO_27->setIconSize(QSize(30, 30));
        IO_27->setCheckable(true);

        IO_grid->addWidget(IO_27, 6, 2, 1, 1);

        IO_37 = new QCheckBox(layoutWidget);
        IO_37->setObjectName(QString::fromUtf8("IO_37"));
        IO_37->setStyleSheet(QString::fromUtf8(""));
        IO_37->setIconSize(QSize(30, 30));
        IO_37->setCheckable(true);

        IO_grid->addWidget(IO_37, 6, 3, 1, 1);

        IO_47 = new QCheckBox(layoutWidget);
        IO_47->setObjectName(QString::fromUtf8("IO_47"));
        IO_47->setStyleSheet(QString::fromUtf8(""));
        IO_47->setIconSize(QSize(30, 30));
        IO_47->setCheckable(true);

        IO_grid->addWidget(IO_47, 6, 4, 1, 1);

        IO_8 = new QCheckBox(layoutWidget);
        IO_8->setObjectName(QString::fromUtf8("IO_8"));
        IO_8->setStyleSheet(QString::fromUtf8(""));
        IO_8->setIconSize(QSize(30, 30));
        IO_8->setCheckable(true);

        IO_grid->addWidget(IO_8, 7, 0, 1, 1);

        IO_18 = new QCheckBox(layoutWidget);
        IO_18->setObjectName(QString::fromUtf8("IO_18"));
        IO_18->setStyleSheet(QString::fromUtf8(""));
        IO_18->setIconSize(QSize(30, 30));
        IO_18->setCheckable(true);

        IO_grid->addWidget(IO_18, 7, 1, 1, 1);

        IO_28 = new QCheckBox(layoutWidget);
        IO_28->setObjectName(QString::fromUtf8("IO_28"));
        IO_28->setStyleSheet(QString::fromUtf8(""));
        IO_28->setIconSize(QSize(30, 30));
        IO_28->setCheckable(true);

        IO_grid->addWidget(IO_28, 7, 2, 1, 1);

        IO_38 = new QCheckBox(layoutWidget);
        IO_38->setObjectName(QString::fromUtf8("IO_38"));
        IO_38->setStyleSheet(QString::fromUtf8(""));
        IO_38->setIconSize(QSize(30, 30));
        IO_38->setCheckable(true);

        IO_grid->addWidget(IO_38, 7, 3, 1, 1);

        IO_48 = new QCheckBox(layoutWidget);
        IO_48->setObjectName(QString::fromUtf8("IO_48"));
        IO_48->setStyleSheet(QString::fromUtf8(""));
        IO_48->setIconSize(QSize(30, 30));
        IO_48->setCheckable(true);

        IO_grid->addWidget(IO_48, 7, 4, 1, 1);

        IO_9 = new QCheckBox(layoutWidget);
        IO_9->setObjectName(QString::fromUtf8("IO_9"));
        IO_9->setStyleSheet(QString::fromUtf8(""));
        IO_9->setIconSize(QSize(30, 30));
        IO_9->setCheckable(true);

        IO_grid->addWidget(IO_9, 8, 0, 1, 1);

        IO_19 = new QCheckBox(layoutWidget);
        IO_19->setObjectName(QString::fromUtf8("IO_19"));
        IO_19->setStyleSheet(QString::fromUtf8(""));
        IO_19->setIconSize(QSize(30, 30));
        IO_19->setCheckable(true);

        IO_grid->addWidget(IO_19, 8, 1, 1, 1);

        IO_29 = new QCheckBox(layoutWidget);
        IO_29->setObjectName(QString::fromUtf8("IO_29"));
        IO_29->setStyleSheet(QString::fromUtf8(""));
        IO_29->setIconSize(QSize(30, 30));
        IO_29->setCheckable(true);

        IO_grid->addWidget(IO_29, 8, 2, 1, 1);

        IO_39 = new QCheckBox(layoutWidget);
        IO_39->setObjectName(QString::fromUtf8("IO_39"));
        IO_39->setStyleSheet(QString::fromUtf8(""));
        IO_39->setIconSize(QSize(30, 30));
        IO_39->setCheckable(true);

        IO_grid->addWidget(IO_39, 8, 3, 1, 1);

        IO_10 = new QCheckBox(layoutWidget);
        IO_10->setObjectName(QString::fromUtf8("IO_10"));
        IO_10->setStyleSheet(QString::fromUtf8(""));
        IO_10->setIconSize(QSize(30, 30));
        IO_10->setCheckable(true);

        IO_grid->addWidget(IO_10, 9, 0, 1, 1);

        IO_20 = new QCheckBox(layoutWidget);
        IO_20->setObjectName(QString::fromUtf8("IO_20"));
        IO_20->setStyleSheet(QString::fromUtf8(""));
        IO_20->setIconSize(QSize(30, 30));
        IO_20->setCheckable(true);

        IO_grid->addWidget(IO_20, 9, 1, 1, 1);

        IO_30 = new QCheckBox(layoutWidget);
        IO_30->setObjectName(QString::fromUtf8("IO_30"));
        IO_30->setStyleSheet(QString::fromUtf8(""));
        IO_30->setIconSize(QSize(30, 30));
        IO_30->setCheckable(true);

        IO_grid->addWidget(IO_30, 9, 2, 1, 1);

        IO_40 = new QCheckBox(layoutWidget);
        IO_40->setObjectName(QString::fromUtf8("IO_40"));
        IO_40->setStyleSheet(QString::fromUtf8(""));
        IO_40->setIconSize(QSize(30, 30));
        IO_40->setCheckable(true);

        IO_grid->addWidget(IO_40, 9, 3, 1, 1);

        tb_ptmID = new QLineEdit(SITIPEMaster);
        tb_ptmID->setObjectName(QString::fromUtf8("tb_ptmID"));
        tb_ptmID->setGeometry(QRect(350, 80, 71, 22));
        tb_ptmID->setFont(font);
        tb_ptmID->setCursorPosition(0);
        tb_ptmID->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        cb_online = new QCheckBox(SITIPEMaster);
        cb_online->setObjectName(QString::fromUtf8("cb_online"));
        cb_online->setGeometry(QRect(13, 44, 60, 30));
        cb_online->setStyleSheet(QString::fromUtf8(""));
        cb_online->setIconSize(QSize(41, 30));
        bu_KITT = new QPushButton(SITIPEMaster);
        bu_KITT->setObjectName(QString::fromUtf8("bu_KITT"));
        bu_KITT->setGeometry(QRect(620, 20, 121, 51));
        bu_KITT->setFont(font);
        bu_KITT->setStyleSheet(QString::fromUtf8(""));
        bu_KITT->setIconSize(QSize(115, 60));
        bu_KITT->setAutoDefault(false);
        bu_KITT->setFlat(false);
        bu_TEST = new QPushButton(SITIPEMaster);
        bu_TEST->setObjectName(QString::fromUtf8("bu_TEST"));
        bu_TEST->setGeometry(QRect(750, 20, 61, 51));
        bu_TEST->setFont(font);
        bu_TEST->setStyleSheet(QString::fromUtf8(""));
        bu_TEST->setIconSize(QSize(106, 49));
        bu_TEST->setFlat(false);
        lw_serverLog = new QListWidget(SITIPEMaster);
        lw_serverLog->setObjectName(QString::fromUtf8("lw_serverLog"));
        lw_serverLog->setGeometry(QRect(10, 80, 301, 291));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Calibri")});
        font2.setPointSize(10);
        lw_serverLog->setFont(font2);
        lw_serverLog->setItemAlignment(Qt::AlignRight);
        cb_ptmonline = new QCheckBox(SITIPEMaster);
        cb_ptmonline->setObjectName(QString::fromUtf8("cb_ptmonline"));
        cb_ptmonline->setGeometry(QRect(440, 40, 111, 30));
        cb_ptmonline->setStyleSheet(QString::fromUtf8(""));
        cb_ptmonline->setIconSize(QSize(41, 30));
        tabWidget->addTab(SITIPEMaster, QString());
        MMSServer = new QWidget();
        MMSServer->setObjectName(QString::fromUtf8("MMSServer"));
        tabWidget->addTab(MMSServer, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 850, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        bu_disconnect->setDefault(false);
        bu_KITT->setDefault(true);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "SITIPE Master - MMS-Server", nullptr));
        bu_connect->setText(QCoreApplication::translate("MainWindow", "connect", nullptr));
        tb_serverIp->setText(QCoreApplication::translate("MainWindow", "192.168.238.1", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Server IP:", nullptr));
        tb_port->setInputMask(QString());
        tb_port->setText(QCoreApplication::translate("MainWindow", "23000", nullptr));
        tb_port->setPlaceholderText(QCoreApplication::translate("MainWindow", "33333", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", ":", nullptr));
        bu_disconnect->setText(QCoreApplication::translate("MainWindow", "disconnect", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "PTM-Module", nullptr));
#if QT_CONFIG(tooltip)
        bu_addPTM->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>PTM-Modul hinzuf\303\274gen</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        bu_addPTM->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
        bu_addPTM->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
#if QT_CONFIG(tooltip)
        bu_delPTM->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>PTM-Modul entfernen</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        bu_delPTM->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        bu_close->setText(QCoreApplication::translate("MainWindow", "CLOSE", nullptr));
        IO_11->setText(QCoreApplication::translate("MainWindow", "11", nullptr));
        IO_21->setText(QCoreApplication::translate("MainWindow", "21", nullptr));
        IO_31->setText(QCoreApplication::translate("MainWindow", "31", nullptr));
        IO_41->setText(QCoreApplication::translate("MainWindow", "41", nullptr));
        IO_2->setText(QCoreApplication::translate("MainWindow", "02", nullptr));
        IO_12->setText(QCoreApplication::translate("MainWindow", "12", nullptr));
        IO_22->setText(QCoreApplication::translate("MainWindow", "22", nullptr));
        IO_32->setText(QCoreApplication::translate("MainWindow", "32", nullptr));
        IO_42->setText(QCoreApplication::translate("MainWindow", "42", nullptr));
        IO_3->setText(QCoreApplication::translate("MainWindow", "03", nullptr));
        IO_13->setText(QCoreApplication::translate("MainWindow", "13", nullptr));
        IO_23->setText(QCoreApplication::translate("MainWindow", "23", nullptr));
        IO_33->setText(QCoreApplication::translate("MainWindow", "33", nullptr));
        IO_43->setText(QCoreApplication::translate("MainWindow", "43", nullptr));
        IO_4->setText(QCoreApplication::translate("MainWindow", "04", nullptr));
        IO_14->setText(QCoreApplication::translate("MainWindow", "14", nullptr));
        IO_24->setText(QCoreApplication::translate("MainWindow", "24", nullptr));
        IO_34->setText(QCoreApplication::translate("MainWindow", "34", nullptr));
        IO_44->setText(QCoreApplication::translate("MainWindow", "44", nullptr));
        IO_5->setText(QCoreApplication::translate("MainWindow", "05", nullptr));
        IO_15->setText(QCoreApplication::translate("MainWindow", "15", nullptr));
        IO_25->setText(QCoreApplication::translate("MainWindow", "25", nullptr));
        IO_35->setText(QCoreApplication::translate("MainWindow", "35", nullptr));
        IO_45->setText(QCoreApplication::translate("MainWindow", "45", nullptr));
        IO_6->setText(QCoreApplication::translate("MainWindow", "06", nullptr));
        IO_16->setText(QCoreApplication::translate("MainWindow", "16", nullptr));
        IO_26->setText(QCoreApplication::translate("MainWindow", "26", nullptr));
        IO_36->setText(QCoreApplication::translate("MainWindow", "36", nullptr));
        IO_46->setText(QCoreApplication::translate("MainWindow", "46", nullptr));
        IO_7->setText(QCoreApplication::translate("MainWindow", "07", nullptr));
        IO_17->setText(QCoreApplication::translate("MainWindow", "17", nullptr));
        IO_27->setText(QCoreApplication::translate("MainWindow", "27", nullptr));
        IO_37->setText(QCoreApplication::translate("MainWindow", "37", nullptr));
        IO_47->setText(QCoreApplication::translate("MainWindow", "47", nullptr));
        IO_8->setText(QCoreApplication::translate("MainWindow", "08", nullptr));
        IO_18->setText(QCoreApplication::translate("MainWindow", "18", nullptr));
        IO_28->setText(QCoreApplication::translate("MainWindow", "28", nullptr));
        IO_38->setText(QCoreApplication::translate("MainWindow", "38", nullptr));
        IO_48->setText(QCoreApplication::translate("MainWindow", "48", nullptr));
        IO_9->setText(QCoreApplication::translate("MainWindow", "09", nullptr));
        IO_19->setText(QCoreApplication::translate("MainWindow", "19", nullptr));
        IO_29->setText(QCoreApplication::translate("MainWindow", "29", nullptr));
        IO_39->setText(QCoreApplication::translate("MainWindow", "39", nullptr));
        IO_10->setText(QCoreApplication::translate("MainWindow", "10", nullptr));
        IO_20->setText(QCoreApplication::translate("MainWindow", "20", nullptr));
        IO_30->setText(QCoreApplication::translate("MainWindow", "30", nullptr));
        IO_40->setText(QCoreApplication::translate("MainWindow", "40", nullptr));
        tb_ptmID->setInputMask(QString());
        tb_ptmID->setText(QString());
        tb_ptmID->setPlaceholderText(QCoreApplication::translate("MainWindow", "00000", nullptr));
        cb_online->setText(QCoreApplication::translate("MainWindow", "TCP OK", nullptr));
        bu_KITT->setText(QCoreApplication::translate("MainWindow", "KITT", nullptr));
        bu_TEST->setText(QCoreApplication::translate("MainWindow", "TEST", nullptr));
        cb_ptmonline->setText(QCoreApplication::translate("MainWindow", "PTM connected", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(SITIPEMaster), QCoreApplication::translate("MainWindow", "SITIPE-Master", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(MMSServer), QCoreApplication::translate("MainWindow", "MMS-Server", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAINWINDOWPKDGDT_H
