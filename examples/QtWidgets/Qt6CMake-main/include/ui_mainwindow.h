/********************************************************************************
** Form generated from reading UI file 'mainwindowqlqQsw.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAINWINDOWQLQQSW_H
#define MAINWINDOWQLQQSW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
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
    QLineEdit *tb_ptmServerIp;
    QLabel *label;
    QLineEdit *tb_ptmServerPort;
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
    QPushButton *out_13;
    QCheckBox *in_45;
    QCheckBox *in_11;
    QPushButton *out_30;
    QPushButton *out_8;
    QPushButton *out_12;
    QCheckBox *in_33;
    QCheckBox *in_6;
    QCheckBox *in_37;
    QPushButton *out_34;
    QCheckBox *in_1;
    QPushButton *out_26;
    QCheckBox *in_14;
    QCheckBox *in_8;
    QCheckBox *in_10;
    QPushButton *out_23;
    QCheckBox *in_22;
    QCheckBox *in_35;
    QPushButton *out_36;
    QCheckBox *in_43;
    QPushButton *out_11;
    QCheckBox *in_13;
    QPushButton *out_37;
    QCheckBox *in_31;
    QPushButton *out_18;
    QCheckBox *in_24;
    QCheckBox *in_40;
    QPushButton *out_15;
    QCheckBox *in_27;
    QCheckBox *in_39;
    QCheckBox *in_38;
    QPushButton *out_2;
    QPushButton *out_1;
    QPushButton *out_40;
    QCheckBox *in_32;
    QCheckBox *in_28;
    QCheckBox *in_48;
    QPushButton *out_10;
    QPushButton *out_39;
    QCheckBox *in_18;
    QPushButton *out_29;
    QPushButton *out_31;
    QCheckBox *in_41;
    QCheckBox *in_12;
    QPushButton *out_5;
    QPushButton *out_24;
    QPushButton *out_4;
    QCheckBox *in_29;
    QCheckBox *in_3;
    QPushButton *out_20;
    QPushButton *out_16;
    QCheckBox *in_23;
    QPushButton *out_22;
    QCheckBox *in_16;
    QPushButton *out_32;
    QPushButton *out_25;
    QCheckBox *in_20;
    QCheckBox *in_5;
    QCheckBox *in_4;
    QCheckBox *in_46;
    QPushButton *out_3;
    QCheckBox *in_47;
    QCheckBox *in_9;
    QCheckBox *in_19;
    QCheckBox *in_26;
    QPushButton *out_28;
    QCheckBox *in_34;
    QCheckBox *in_7;
    QPushButton *out_21;
    QCheckBox *in_21;
    QCheckBox *in_25;
    QPushButton *out_7;
    QCheckBox *in_30;
    QPushButton *out_27;
    QPushButton *out_38;
    QCheckBox *in_36;
    QPushButton *out_9;
    QCheckBox *in_44;
    QCheckBox *in_42;
    QCheckBox *in_2;
    QPushButton *out_19;
    QCheckBox *in_17;
    QPushButton *out_14;
    QPushButton *out_33;
    QPushButton *out_6;
    QCheckBox *in_15;
    QPushButton *out_17;
    QPushButton *out_35;
    QPushButton *out_41;
    QPushButton *out_43;
    QPushButton *out_44;
    QPushButton *out_48;
    QPushButton *out_45;
    QPushButton *out_47;
    QPushButton *out_46;
    QPushButton *out_42;
    QLineEdit *tb_ptmID;
    QCheckBox *cb_online;
    QPushButton *bu_TEST;
    QListWidget *lw_PTMserverLog;
    QCheckBox *cb_ptmonline;
    QGroupBox *gb_ioUpdate;
    QRadioButton *rb_singleTransmit;
    QRadioButton *rb_groupTransmit;
    QPushButton *bu_setGroup;
    QWidget *SITIPESlave;
    QWidget *IEC104;
    QPushButton *bu_open104Server;
    QCheckBox *cb_clientConnected;
    QListWidget *lw_104serverLog;
    QPushButton *bu_close104Server;
    QLabel *label_2;
    QLineEdit *tb_104port;
    QWidget *SIM;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(848, 519);
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
        tb_ptmServerIp = new QLineEdit(SITIPEMaster);
        tb_ptmServerIp->setObjectName(QString::fromUtf8("tb_ptmServerIp"));
        tb_ptmServerIp->setGeometry(QRect(80, 16, 151, 22));
        tb_ptmServerIp->setFont(font);
        tb_ptmServerIp->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label = new QLabel(SITIPEMaster);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 13, 81, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Calibri")});
        font1.setPointSize(12);
        label->setFont(font1);
        tb_ptmServerPort = new QLineEdit(SITIPEMaster);
        tb_ptmServerPort->setObjectName(QString::fromUtf8("tb_ptmServerPort"));
        tb_ptmServerPort->setGeometry(QRect(240, 16, 71, 22));
        tb_ptmServerPort->setFont(font);
        tb_ptmServerPort->setCursorPosition(5);
        tb_ptmServerPort->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
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
        layoutWidget->setGeometry(QRect(440, 80, 371, 291));
        IO_grid = new QGridLayout(layoutWidget);
        IO_grid->setObjectName(QString::fromUtf8("IO_grid"));
        IO_grid->setContentsMargins(0, 0, 0, 0);
        out_13 = new QPushButton(layoutWidget);
        out_13->setObjectName(QString::fromUtf8("out_13"));
        out_13->setMinimumSize(QSize(40, 20));
        out_13->setMaximumSize(QSize(30, 30));
        out_13->setCheckable(true);

        IO_grid->addWidget(out_13, 3, 2, 1, 1);

        in_45 = new QCheckBox(layoutWidget);
        in_45->setObjectName(QString::fromUtf8("in_45"));
        in_45->setEnabled(false);
        in_45->setStyleSheet(QString::fromUtf8(""));
        in_45->setIconSize(QSize(30, 30));
        in_45->setCheckable(true);

        IO_grid->addWidget(in_45, 5, 9, 1, 1);

        in_11 = new QCheckBox(layoutWidget);
        in_11->setObjectName(QString::fromUtf8("in_11"));
        in_11->setEnabled(false);
        in_11->setStyleSheet(QString::fromUtf8(""));
        in_11->setIconSize(QSize(30, 30));
        in_11->setCheckable(true);

        IO_grid->addWidget(in_11, 1, 3, 1, 1);

        out_30 = new QPushButton(layoutWidget);
        out_30->setObjectName(QString::fromUtf8("out_30"));
        out_30->setMinimumSize(QSize(40, 20));
        out_30->setMaximumSize(QSize(30, 30));
        out_30->setCheckable(true);

        IO_grid->addWidget(out_30, 10, 4, 1, 1);

        out_8 = new QPushButton(layoutWidget);
        out_8->setObjectName(QString::fromUtf8("out_8"));
        out_8->setMinimumSize(QSize(40, 20));
        out_8->setMaximumSize(QSize(30, 30));
        out_8->setCheckable(true);

        IO_grid->addWidget(out_8, 8, 0, 1, 1);

        out_12 = new QPushButton(layoutWidget);
        out_12->setObjectName(QString::fromUtf8("out_12"));
        out_12->setMinimumSize(QSize(40, 20));
        out_12->setMaximumSize(QSize(30, 30));
        out_12->setCheckable(true);

        IO_grid->addWidget(out_12, 2, 2, 1, 1);

        in_33 = new QCheckBox(layoutWidget);
        in_33->setObjectName(QString::fromUtf8("in_33"));
        in_33->setEnabled(false);
        in_33->setStyleSheet(QString::fromUtf8(""));
        in_33->setIconSize(QSize(30, 30));
        in_33->setCheckable(true);

        IO_grid->addWidget(in_33, 3, 7, 1, 1);

        in_6 = new QCheckBox(layoutWidget);
        in_6->setObjectName(QString::fromUtf8("in_6"));
        in_6->setEnabled(false);
        in_6->setStyleSheet(QString::fromUtf8(""));
        in_6->setIconSize(QSize(30, 30));
        in_6->setCheckable(true);

        IO_grid->addWidget(in_6, 6, 1, 1, 1);

        in_37 = new QCheckBox(layoutWidget);
        in_37->setObjectName(QString::fromUtf8("in_37"));
        in_37->setEnabled(false);
        in_37->setStyleSheet(QString::fromUtf8(""));
        in_37->setIconSize(QSize(30, 30));
        in_37->setCheckable(true);

        IO_grid->addWidget(in_37, 7, 7, 1, 1);

        out_34 = new QPushButton(layoutWidget);
        out_34->setObjectName(QString::fromUtf8("out_34"));
        out_34->setMinimumSize(QSize(40, 20));
        out_34->setMaximumSize(QSize(30, 30));
        out_34->setCheckable(true);

        IO_grid->addWidget(out_34, 4, 6, 1, 1);

        in_1 = new QCheckBox(layoutWidget);
        in_1->setObjectName(QString::fromUtf8("in_1"));
        in_1->setEnabled(false);
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(in_1->sizePolicy().hasHeightForWidth());
        in_1->setSizePolicy(sizePolicy2);
        in_1->setStyleSheet(QString::fromUtf8(""));
        in_1->setIconSize(QSize(30, 30));
        in_1->setCheckable(true);
        in_1->setTristate(false);

        IO_grid->addWidget(in_1, 1, 1, 1, 1);

        out_26 = new QPushButton(layoutWidget);
        out_26->setObjectName(QString::fromUtf8("out_26"));
        out_26->setMinimumSize(QSize(40, 20));
        out_26->setMaximumSize(QSize(30, 30));
        out_26->setCheckable(true);

        IO_grid->addWidget(out_26, 6, 4, 1, 1);

        in_14 = new QCheckBox(layoutWidget);
        in_14->setObjectName(QString::fromUtf8("in_14"));
        in_14->setEnabled(false);
        in_14->setStyleSheet(QString::fromUtf8(""));
        in_14->setIconSize(QSize(30, 30));
        in_14->setCheckable(true);

        IO_grid->addWidget(in_14, 4, 3, 1, 1);

        in_8 = new QCheckBox(layoutWidget);
        in_8->setObjectName(QString::fromUtf8("in_8"));
        in_8->setEnabled(false);
        in_8->setStyleSheet(QString::fromUtf8(""));
        in_8->setIconSize(QSize(30, 30));
        in_8->setCheckable(true);

        IO_grid->addWidget(in_8, 8, 1, 1, 1);

        in_10 = new QCheckBox(layoutWidget);
        in_10->setObjectName(QString::fromUtf8("in_10"));
        in_10->setEnabled(false);
        in_10->setStyleSheet(QString::fromUtf8(""));
        in_10->setIconSize(QSize(30, 30));
        in_10->setCheckable(true);

        IO_grid->addWidget(in_10, 10, 1, 1, 1);

        out_23 = new QPushButton(layoutWidget);
        out_23->setObjectName(QString::fromUtf8("out_23"));
        out_23->setMinimumSize(QSize(40, 20));
        out_23->setMaximumSize(QSize(30, 30));
        out_23->setCheckable(true);

        IO_grid->addWidget(out_23, 3, 4, 1, 1);

        in_22 = new QCheckBox(layoutWidget);
        in_22->setObjectName(QString::fromUtf8("in_22"));
        in_22->setEnabled(false);
        in_22->setStyleSheet(QString::fromUtf8(""));
        in_22->setIconSize(QSize(30, 30));
        in_22->setCheckable(true);

        IO_grid->addWidget(in_22, 2, 5, 1, 1);

        in_35 = new QCheckBox(layoutWidget);
        in_35->setObjectName(QString::fromUtf8("in_35"));
        in_35->setEnabled(false);
        in_35->setStyleSheet(QString::fromUtf8(""));
        in_35->setIconSize(QSize(30, 30));
        in_35->setCheckable(true);

        IO_grid->addWidget(in_35, 5, 7, 1, 1);

        out_36 = new QPushButton(layoutWidget);
        out_36->setObjectName(QString::fromUtf8("out_36"));
        out_36->setMinimumSize(QSize(40, 20));
        out_36->setMaximumSize(QSize(30, 30));
        out_36->setCheckable(true);

        IO_grid->addWidget(out_36, 6, 6, 1, 1);

        in_43 = new QCheckBox(layoutWidget);
        in_43->setObjectName(QString::fromUtf8("in_43"));
        in_43->setEnabled(false);
        in_43->setStyleSheet(QString::fromUtf8(""));
        in_43->setIconSize(QSize(30, 30));
        in_43->setCheckable(true);

        IO_grid->addWidget(in_43, 3, 9, 1, 1);

        out_11 = new QPushButton(layoutWidget);
        out_11->setObjectName(QString::fromUtf8("out_11"));
        out_11->setMinimumSize(QSize(40, 20));
        out_11->setMaximumSize(QSize(30, 30));
        out_11->setCheckable(true);

        IO_grid->addWidget(out_11, 1, 2, 1, 1);

        in_13 = new QCheckBox(layoutWidget);
        in_13->setObjectName(QString::fromUtf8("in_13"));
        in_13->setEnabled(false);
        in_13->setStyleSheet(QString::fromUtf8(""));
        in_13->setIconSize(QSize(30, 30));
        in_13->setCheckable(true);

        IO_grid->addWidget(in_13, 3, 3, 1, 1);

        out_37 = new QPushButton(layoutWidget);
        out_37->setObjectName(QString::fromUtf8("out_37"));
        out_37->setMinimumSize(QSize(40, 20));
        out_37->setMaximumSize(QSize(30, 30));
        out_37->setCheckable(true);

        IO_grid->addWidget(out_37, 7, 6, 1, 1);

        in_31 = new QCheckBox(layoutWidget);
        in_31->setObjectName(QString::fromUtf8("in_31"));
        in_31->setEnabled(false);
        in_31->setStyleSheet(QString::fromUtf8(""));
        in_31->setIconSize(QSize(30, 30));
        in_31->setCheckable(true);

        IO_grid->addWidget(in_31, 1, 7, 1, 1);

        out_18 = new QPushButton(layoutWidget);
        out_18->setObjectName(QString::fromUtf8("out_18"));
        out_18->setMinimumSize(QSize(40, 20));
        out_18->setMaximumSize(QSize(30, 30));
        out_18->setCheckable(true);

        IO_grid->addWidget(out_18, 8, 2, 1, 1);

        in_24 = new QCheckBox(layoutWidget);
        in_24->setObjectName(QString::fromUtf8("in_24"));
        in_24->setEnabled(false);
        in_24->setStyleSheet(QString::fromUtf8(""));
        in_24->setIconSize(QSize(30, 30));
        in_24->setCheckable(true);

        IO_grid->addWidget(in_24, 4, 5, 1, 1);

        in_40 = new QCheckBox(layoutWidget);
        in_40->setObjectName(QString::fromUtf8("in_40"));
        in_40->setEnabled(false);
        in_40->setStyleSheet(QString::fromUtf8(""));
        in_40->setIconSize(QSize(30, 30));
        in_40->setCheckable(true);

        IO_grid->addWidget(in_40, 10, 7, 1, 1);

        out_15 = new QPushButton(layoutWidget);
        out_15->setObjectName(QString::fromUtf8("out_15"));
        out_15->setMinimumSize(QSize(40, 20));
        out_15->setMaximumSize(QSize(30, 30));
        out_15->setCheckable(true);

        IO_grid->addWidget(out_15, 5, 2, 1, 1);

        in_27 = new QCheckBox(layoutWidget);
        in_27->setObjectName(QString::fromUtf8("in_27"));
        in_27->setEnabled(false);
        in_27->setStyleSheet(QString::fromUtf8(""));
        in_27->setIconSize(QSize(30, 30));
        in_27->setCheckable(true);

        IO_grid->addWidget(in_27, 7, 5, 1, 1);

        in_39 = new QCheckBox(layoutWidget);
        in_39->setObjectName(QString::fromUtf8("in_39"));
        in_39->setEnabled(false);
        in_39->setStyleSheet(QString::fromUtf8(""));
        in_39->setIconSize(QSize(30, 30));
        in_39->setCheckable(true);

        IO_grid->addWidget(in_39, 9, 7, 1, 1);

        in_38 = new QCheckBox(layoutWidget);
        in_38->setObjectName(QString::fromUtf8("in_38"));
        in_38->setEnabled(false);
        in_38->setStyleSheet(QString::fromUtf8(""));
        in_38->setIconSize(QSize(30, 30));
        in_38->setCheckable(true);

        IO_grid->addWidget(in_38, 8, 7, 1, 1);

        out_2 = new QPushButton(layoutWidget);
        out_2->setObjectName(QString::fromUtf8("out_2"));
        out_2->setMinimumSize(QSize(40, 20));
        out_2->setMaximumSize(QSize(30, 30));
        out_2->setCheckable(true);

        IO_grid->addWidget(out_2, 2, 0, 1, 1);

        out_1 = new QPushButton(layoutWidget);
        out_1->setObjectName(QString::fromUtf8("out_1"));
        out_1->setMinimumSize(QSize(40, 20));
        out_1->setMaximumSize(QSize(30, 30));
        out_1->setCheckable(true);

        IO_grid->addWidget(out_1, 1, 0, 1, 1);

        out_40 = new QPushButton(layoutWidget);
        out_40->setObjectName(QString::fromUtf8("out_40"));
        out_40->setMinimumSize(QSize(40, 20));
        out_40->setMaximumSize(QSize(30, 30));
        out_40->setCheckable(true);

        IO_grid->addWidget(out_40, 10, 6, 1, 1);

        in_32 = new QCheckBox(layoutWidget);
        in_32->setObjectName(QString::fromUtf8("in_32"));
        in_32->setEnabled(false);
        in_32->setStyleSheet(QString::fromUtf8(""));
        in_32->setIconSize(QSize(30, 30));
        in_32->setCheckable(true);

        IO_grid->addWidget(in_32, 2, 7, 1, 1);

        in_28 = new QCheckBox(layoutWidget);
        in_28->setObjectName(QString::fromUtf8("in_28"));
        in_28->setEnabled(false);
        in_28->setStyleSheet(QString::fromUtf8(""));
        in_28->setIconSize(QSize(30, 30));
        in_28->setCheckable(true);

        IO_grid->addWidget(in_28, 8, 5, 1, 1);

        in_48 = new QCheckBox(layoutWidget);
        in_48->setObjectName(QString::fromUtf8("in_48"));
        in_48->setEnabled(false);
        in_48->setStyleSheet(QString::fromUtf8(""));
        in_48->setIconSize(QSize(30, 30));
        in_48->setCheckable(true);

        IO_grid->addWidget(in_48, 8, 9, 1, 1);

        out_10 = new QPushButton(layoutWidget);
        out_10->setObjectName(QString::fromUtf8("out_10"));
        out_10->setMinimumSize(QSize(40, 20));
        out_10->setMaximumSize(QSize(30, 30));
        out_10->setCheckable(true);

        IO_grid->addWidget(out_10, 10, 0, 1, 1);

        out_39 = new QPushButton(layoutWidget);
        out_39->setObjectName(QString::fromUtf8("out_39"));
        out_39->setMinimumSize(QSize(40, 20));
        out_39->setMaximumSize(QSize(30, 30));
        out_39->setCheckable(true);

        IO_grid->addWidget(out_39, 9, 6, 1, 1);

        in_18 = new QCheckBox(layoutWidget);
        in_18->setObjectName(QString::fromUtf8("in_18"));
        in_18->setEnabled(false);
        in_18->setStyleSheet(QString::fromUtf8(""));
        in_18->setIconSize(QSize(30, 30));
        in_18->setCheckable(true);

        IO_grid->addWidget(in_18, 8, 3, 1, 1);

        out_29 = new QPushButton(layoutWidget);
        out_29->setObjectName(QString::fromUtf8("out_29"));
        out_29->setMinimumSize(QSize(40, 20));
        out_29->setMaximumSize(QSize(30, 30));
        out_29->setCheckable(true);

        IO_grid->addWidget(out_29, 9, 4, 1, 1);

        out_31 = new QPushButton(layoutWidget);
        out_31->setObjectName(QString::fromUtf8("out_31"));
        out_31->setMinimumSize(QSize(40, 20));
        out_31->setMaximumSize(QSize(30, 30));
        out_31->setCheckable(true);

        IO_grid->addWidget(out_31, 1, 6, 1, 1);

        in_41 = new QCheckBox(layoutWidget);
        in_41->setObjectName(QString::fromUtf8("in_41"));
        in_41->setEnabled(false);
        in_41->setStyleSheet(QString::fromUtf8(""));
        in_41->setIconSize(QSize(30, 30));
        in_41->setCheckable(true);

        IO_grid->addWidget(in_41, 1, 9, 1, 1);

        in_12 = new QCheckBox(layoutWidget);
        in_12->setObjectName(QString::fromUtf8("in_12"));
        in_12->setEnabled(false);
        in_12->setStyleSheet(QString::fromUtf8(""));
        in_12->setIconSize(QSize(30, 30));
        in_12->setCheckable(true);

        IO_grid->addWidget(in_12, 2, 3, 1, 1);

        out_5 = new QPushButton(layoutWidget);
        out_5->setObjectName(QString::fromUtf8("out_5"));
        out_5->setMinimumSize(QSize(40, 20));
        out_5->setMaximumSize(QSize(30, 30));
        out_5->setCheckable(true);

        IO_grid->addWidget(out_5, 5, 0, 1, 1);

        out_24 = new QPushButton(layoutWidget);
        out_24->setObjectName(QString::fromUtf8("out_24"));
        out_24->setMinimumSize(QSize(40, 20));
        out_24->setMaximumSize(QSize(30, 30));
        out_24->setCheckable(true);

        IO_grid->addWidget(out_24, 4, 4, 1, 1);

        out_4 = new QPushButton(layoutWidget);
        out_4->setObjectName(QString::fromUtf8("out_4"));
        out_4->setMinimumSize(QSize(40, 20));
        out_4->setMaximumSize(QSize(30, 30));
        out_4->setCheckable(true);

        IO_grid->addWidget(out_4, 4, 0, 1, 1);

        in_29 = new QCheckBox(layoutWidget);
        in_29->setObjectName(QString::fromUtf8("in_29"));
        in_29->setEnabled(false);
        in_29->setStyleSheet(QString::fromUtf8(""));
        in_29->setIconSize(QSize(30, 30));
        in_29->setCheckable(true);

        IO_grid->addWidget(in_29, 9, 5, 1, 1);

        in_3 = new QCheckBox(layoutWidget);
        in_3->setObjectName(QString::fromUtf8("in_3"));
        in_3->setEnabled(false);
        in_3->setStyleSheet(QString::fromUtf8(""));
        in_3->setIconSize(QSize(30, 30));
        in_3->setCheckable(true);

        IO_grid->addWidget(in_3, 3, 1, 1, 1);

        out_20 = new QPushButton(layoutWidget);
        out_20->setObjectName(QString::fromUtf8("out_20"));
        out_20->setMinimumSize(QSize(40, 20));
        out_20->setMaximumSize(QSize(30, 30));
        out_20->setCheckable(true);

        IO_grid->addWidget(out_20, 10, 2, 1, 1);

        out_16 = new QPushButton(layoutWidget);
        out_16->setObjectName(QString::fromUtf8("out_16"));
        out_16->setMinimumSize(QSize(40, 20));
        out_16->setMaximumSize(QSize(30, 30));
        out_16->setCheckable(true);

        IO_grid->addWidget(out_16, 6, 2, 1, 1);

        in_23 = new QCheckBox(layoutWidget);
        in_23->setObjectName(QString::fromUtf8("in_23"));
        in_23->setEnabled(false);
        in_23->setStyleSheet(QString::fromUtf8(""));
        in_23->setIconSize(QSize(30, 30));
        in_23->setCheckable(true);

        IO_grid->addWidget(in_23, 3, 5, 1, 1);

        out_22 = new QPushButton(layoutWidget);
        out_22->setObjectName(QString::fromUtf8("out_22"));
        out_22->setMinimumSize(QSize(40, 20));
        out_22->setMaximumSize(QSize(30, 30));
        out_22->setCheckable(true);

        IO_grid->addWidget(out_22, 2, 4, 1, 1);

        in_16 = new QCheckBox(layoutWidget);
        in_16->setObjectName(QString::fromUtf8("in_16"));
        in_16->setEnabled(false);
        in_16->setStyleSheet(QString::fromUtf8(""));
        in_16->setIconSize(QSize(30, 30));
        in_16->setCheckable(true);

        IO_grid->addWidget(in_16, 6, 3, 1, 1);

        out_32 = new QPushButton(layoutWidget);
        out_32->setObjectName(QString::fromUtf8("out_32"));
        out_32->setMinimumSize(QSize(40, 20));
        out_32->setMaximumSize(QSize(30, 30));
        out_32->setCheckable(true);

        IO_grid->addWidget(out_32, 2, 6, 1, 1);

        out_25 = new QPushButton(layoutWidget);
        out_25->setObjectName(QString::fromUtf8("out_25"));
        out_25->setMinimumSize(QSize(40, 20));
        out_25->setMaximumSize(QSize(30, 30));
        out_25->setCheckable(true);

        IO_grid->addWidget(out_25, 5, 4, 1, 1);

        in_20 = new QCheckBox(layoutWidget);
        in_20->setObjectName(QString::fromUtf8("in_20"));
        in_20->setEnabled(false);
        in_20->setStyleSheet(QString::fromUtf8(""));
        in_20->setIconSize(QSize(30, 30));
        in_20->setCheckable(true);

        IO_grid->addWidget(in_20, 10, 3, 1, 1);

        in_5 = new QCheckBox(layoutWidget);
        in_5->setObjectName(QString::fromUtf8("in_5"));
        in_5->setEnabled(false);
        in_5->setStyleSheet(QString::fromUtf8(""));
        in_5->setIconSize(QSize(30, 30));
        in_5->setCheckable(true);

        IO_grid->addWidget(in_5, 5, 1, 1, 1);

        in_4 = new QCheckBox(layoutWidget);
        in_4->setObjectName(QString::fromUtf8("in_4"));
        in_4->setEnabled(false);
        in_4->setStyleSheet(QString::fromUtf8(""));
        in_4->setIconSize(QSize(30, 30));
        in_4->setCheckable(true);

        IO_grid->addWidget(in_4, 4, 1, 1, 1);

        in_46 = new QCheckBox(layoutWidget);
        in_46->setObjectName(QString::fromUtf8("in_46"));
        in_46->setEnabled(false);
        in_46->setStyleSheet(QString::fromUtf8(""));
        in_46->setIconSize(QSize(30, 30));
        in_46->setCheckable(true);

        IO_grid->addWidget(in_46, 6, 9, 1, 1);

        out_3 = new QPushButton(layoutWidget);
        out_3->setObjectName(QString::fromUtf8("out_3"));
        out_3->setMinimumSize(QSize(40, 20));
        out_3->setMaximumSize(QSize(30, 30));
        out_3->setCheckable(true);

        IO_grid->addWidget(out_3, 3, 0, 1, 1);

        in_47 = new QCheckBox(layoutWidget);
        in_47->setObjectName(QString::fromUtf8("in_47"));
        in_47->setEnabled(false);
        in_47->setStyleSheet(QString::fromUtf8(""));
        in_47->setIconSize(QSize(30, 30));
        in_47->setCheckable(true);

        IO_grid->addWidget(in_47, 7, 9, 1, 1);

        in_9 = new QCheckBox(layoutWidget);
        in_9->setObjectName(QString::fromUtf8("in_9"));
        in_9->setEnabled(false);
        in_9->setStyleSheet(QString::fromUtf8(""));
        in_9->setIconSize(QSize(30, 30));
        in_9->setCheckable(true);

        IO_grid->addWidget(in_9, 9, 1, 1, 1);

        in_19 = new QCheckBox(layoutWidget);
        in_19->setObjectName(QString::fromUtf8("in_19"));
        in_19->setEnabled(false);
        in_19->setStyleSheet(QString::fromUtf8(""));
        in_19->setIconSize(QSize(30, 30));
        in_19->setCheckable(true);

        IO_grid->addWidget(in_19, 9, 3, 1, 1);

        in_26 = new QCheckBox(layoutWidget);
        in_26->setObjectName(QString::fromUtf8("in_26"));
        in_26->setEnabled(false);
        in_26->setStyleSheet(QString::fromUtf8(""));
        in_26->setIconSize(QSize(30, 30));
        in_26->setCheckable(true);

        IO_grid->addWidget(in_26, 6, 5, 1, 1);

        out_28 = new QPushButton(layoutWidget);
        out_28->setObjectName(QString::fromUtf8("out_28"));
        out_28->setMinimumSize(QSize(40, 20));
        out_28->setMaximumSize(QSize(30, 30));
        out_28->setCheckable(true);

        IO_grid->addWidget(out_28, 8, 4, 1, 1);

        in_34 = new QCheckBox(layoutWidget);
        in_34->setObjectName(QString::fromUtf8("in_34"));
        in_34->setEnabled(false);
        in_34->setStyleSheet(QString::fromUtf8(""));
        in_34->setIconSize(QSize(30, 30));
        in_34->setCheckable(true);

        IO_grid->addWidget(in_34, 4, 7, 1, 1);

        in_7 = new QCheckBox(layoutWidget);
        in_7->setObjectName(QString::fromUtf8("in_7"));
        in_7->setEnabled(false);
        in_7->setStyleSheet(QString::fromUtf8(""));
        in_7->setIconSize(QSize(30, 30));
        in_7->setCheckable(true);

        IO_grid->addWidget(in_7, 7, 1, 1, 1);

        out_21 = new QPushButton(layoutWidget);
        out_21->setObjectName(QString::fromUtf8("out_21"));
        out_21->setMinimumSize(QSize(40, 20));
        out_21->setMaximumSize(QSize(30, 30));
        out_21->setCheckable(true);

        IO_grid->addWidget(out_21, 1, 4, 1, 1);

        in_21 = new QCheckBox(layoutWidget);
        in_21->setObjectName(QString::fromUtf8("in_21"));
        in_21->setEnabled(false);
        in_21->setStyleSheet(QString::fromUtf8(""));
        in_21->setIconSize(QSize(30, 30));
        in_21->setCheckable(true);

        IO_grid->addWidget(in_21, 1, 5, 1, 1);

        in_25 = new QCheckBox(layoutWidget);
        in_25->setObjectName(QString::fromUtf8("in_25"));
        in_25->setEnabled(false);
        in_25->setStyleSheet(QString::fromUtf8(""));
        in_25->setIconSize(QSize(30, 30));
        in_25->setCheckable(true);

        IO_grid->addWidget(in_25, 5, 5, 1, 1);

        out_7 = new QPushButton(layoutWidget);
        out_7->setObjectName(QString::fromUtf8("out_7"));
        out_7->setMinimumSize(QSize(40, 20));
        out_7->setMaximumSize(QSize(30, 30));
        out_7->setCheckable(true);

        IO_grid->addWidget(out_7, 7, 0, 1, 1);

        in_30 = new QCheckBox(layoutWidget);
        in_30->setObjectName(QString::fromUtf8("in_30"));
        in_30->setEnabled(false);
        in_30->setStyleSheet(QString::fromUtf8(""));
        in_30->setIconSize(QSize(30, 30));
        in_30->setCheckable(true);

        IO_grid->addWidget(in_30, 10, 5, 1, 1);

        out_27 = new QPushButton(layoutWidget);
        out_27->setObjectName(QString::fromUtf8("out_27"));
        out_27->setMinimumSize(QSize(40, 20));
        out_27->setMaximumSize(QSize(30, 30));
        out_27->setCheckable(true);

        IO_grid->addWidget(out_27, 7, 4, 1, 1);

        out_38 = new QPushButton(layoutWidget);
        out_38->setObjectName(QString::fromUtf8("out_38"));
        out_38->setMinimumSize(QSize(40, 20));
        out_38->setMaximumSize(QSize(30, 30));
        out_38->setCheckable(true);

        IO_grid->addWidget(out_38, 8, 6, 1, 1);

        in_36 = new QCheckBox(layoutWidget);
        in_36->setObjectName(QString::fromUtf8("in_36"));
        in_36->setEnabled(false);
        in_36->setStyleSheet(QString::fromUtf8(""));
        in_36->setIconSize(QSize(30, 30));
        in_36->setCheckable(true);

        IO_grid->addWidget(in_36, 6, 7, 1, 1);

        out_9 = new QPushButton(layoutWidget);
        out_9->setObjectName(QString::fromUtf8("out_9"));
        out_9->setMinimumSize(QSize(40, 20));
        out_9->setMaximumSize(QSize(30, 30));
        out_9->setCheckable(true);

        IO_grid->addWidget(out_9, 9, 0, 1, 1);

        in_44 = new QCheckBox(layoutWidget);
        in_44->setObjectName(QString::fromUtf8("in_44"));
        in_44->setEnabled(false);
        in_44->setStyleSheet(QString::fromUtf8(""));
        in_44->setIconSize(QSize(30, 30));
        in_44->setCheckable(true);

        IO_grid->addWidget(in_44, 4, 9, 1, 1);

        in_42 = new QCheckBox(layoutWidget);
        in_42->setObjectName(QString::fromUtf8("in_42"));
        in_42->setEnabled(false);
        in_42->setStyleSheet(QString::fromUtf8(""));
        in_42->setIconSize(QSize(30, 30));
        in_42->setCheckable(true);

        IO_grid->addWidget(in_42, 2, 9, 1, 1);

        in_2 = new QCheckBox(layoutWidget);
        in_2->setObjectName(QString::fromUtf8("in_2"));
        in_2->setEnabled(false);
        in_2->setStyleSheet(QString::fromUtf8(""));
        in_2->setIconSize(QSize(30, 30));
        in_2->setCheckable(true);

        IO_grid->addWidget(in_2, 2, 1, 1, 1);

        out_19 = new QPushButton(layoutWidget);
        out_19->setObjectName(QString::fromUtf8("out_19"));
        out_19->setMinimumSize(QSize(40, 20));
        out_19->setMaximumSize(QSize(30, 30));
        out_19->setCheckable(true);

        IO_grid->addWidget(out_19, 9, 2, 1, 1);

        in_17 = new QCheckBox(layoutWidget);
        in_17->setObjectName(QString::fromUtf8("in_17"));
        in_17->setEnabled(false);
        in_17->setStyleSheet(QString::fromUtf8(""));
        in_17->setIconSize(QSize(30, 30));
        in_17->setCheckable(true);

        IO_grid->addWidget(in_17, 7, 3, 1, 1);

        out_14 = new QPushButton(layoutWidget);
        out_14->setObjectName(QString::fromUtf8("out_14"));
        out_14->setMinimumSize(QSize(40, 20));
        out_14->setMaximumSize(QSize(30, 30));
        out_14->setCheckable(true);

        IO_grid->addWidget(out_14, 4, 2, 1, 1);

        out_33 = new QPushButton(layoutWidget);
        out_33->setObjectName(QString::fromUtf8("out_33"));
        out_33->setMinimumSize(QSize(40, 20));
        out_33->setMaximumSize(QSize(30, 30));
        out_33->setCheckable(true);

        IO_grid->addWidget(out_33, 3, 6, 1, 1);

        out_6 = new QPushButton(layoutWidget);
        out_6->setObjectName(QString::fromUtf8("out_6"));
        out_6->setMinimumSize(QSize(40, 20));
        out_6->setMaximumSize(QSize(30, 30));
        out_6->setCheckable(true);

        IO_grid->addWidget(out_6, 6, 0, 1, 1);

        in_15 = new QCheckBox(layoutWidget);
        in_15->setObjectName(QString::fromUtf8("in_15"));
        in_15->setEnabled(false);
        in_15->setStyleSheet(QString::fromUtf8(""));
        in_15->setIconSize(QSize(30, 30));
        in_15->setCheckable(true);

        IO_grid->addWidget(in_15, 5, 3, 1, 1);

        out_17 = new QPushButton(layoutWidget);
        out_17->setObjectName(QString::fromUtf8("out_17"));
        out_17->setMinimumSize(QSize(40, 20));
        out_17->setMaximumSize(QSize(30, 30));
        out_17->setCheckable(true);

        IO_grid->addWidget(out_17, 7, 2, 1, 1);

        out_35 = new QPushButton(layoutWidget);
        out_35->setObjectName(QString::fromUtf8("out_35"));
        out_35->setMinimumSize(QSize(40, 20));
        out_35->setMaximumSize(QSize(30, 30));
        out_35->setCheckable(true);

        IO_grid->addWidget(out_35, 5, 6, 1, 1);

        out_41 = new QPushButton(layoutWidget);
        out_41->setObjectName(QString::fromUtf8("out_41"));
        out_41->setMinimumSize(QSize(40, 20));
        out_41->setMaximumSize(QSize(30, 30));
        out_41->setCheckable(true);

        IO_grid->addWidget(out_41, 1, 8, 1, 1);

        out_43 = new QPushButton(layoutWidget);
        out_43->setObjectName(QString::fromUtf8("out_43"));
        out_43->setMinimumSize(QSize(40, 20));
        out_43->setMaximumSize(QSize(30, 30));
        out_43->setCheckable(true);

        IO_grid->addWidget(out_43, 3, 8, 1, 1);

        out_44 = new QPushButton(layoutWidget);
        out_44->setObjectName(QString::fromUtf8("out_44"));
        out_44->setMinimumSize(QSize(40, 20));
        out_44->setMaximumSize(QSize(30, 30));
        out_44->setCheckable(true);

        IO_grid->addWidget(out_44, 4, 8, 1, 1);

        out_48 = new QPushButton(layoutWidget);
        out_48->setObjectName(QString::fromUtf8("out_48"));
        out_48->setMinimumSize(QSize(40, 20));
        out_48->setMaximumSize(QSize(30, 30));
        out_48->setCheckable(true);

        IO_grid->addWidget(out_48, 8, 8, 1, 1);

        out_45 = new QPushButton(layoutWidget);
        out_45->setObjectName(QString::fromUtf8("out_45"));
        out_45->setMinimumSize(QSize(40, 20));
        out_45->setMaximumSize(QSize(30, 30));
        out_45->setCheckable(true);

        IO_grid->addWidget(out_45, 5, 8, 1, 1);

        out_47 = new QPushButton(layoutWidget);
        out_47->setObjectName(QString::fromUtf8("out_47"));
        out_47->setMinimumSize(QSize(40, 20));
        out_47->setMaximumSize(QSize(30, 30));
        out_47->setCheckable(true);

        IO_grid->addWidget(out_47, 7, 8, 1, 1);

        out_46 = new QPushButton(layoutWidget);
        out_46->setObjectName(QString::fromUtf8("out_46"));
        out_46->setMinimumSize(QSize(40, 20));
        out_46->setMaximumSize(QSize(30, 30));
        out_46->setCheckable(true);

        IO_grid->addWidget(out_46, 6, 8, 1, 1);

        out_42 = new QPushButton(layoutWidget);
        out_42->setObjectName(QString::fromUtf8("out_42"));
        out_42->setMinimumSize(QSize(40, 20));
        out_42->setMaximumSize(QSize(30, 30));
        out_42->setCheckable(true);

        IO_grid->addWidget(out_42, 2, 8, 1, 1);

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
        bu_TEST = new QPushButton(SITIPEMaster);
        bu_TEST->setObjectName(QString::fromUtf8("bu_TEST"));
        bu_TEST->setGeometry(QRect(760, 20, 61, 51));
        bu_TEST->setFont(font);
        bu_TEST->setStyleSheet(QString::fromUtf8(""));
        bu_TEST->setIconSize(QSize(106, 49));
        bu_TEST->setFlat(false);
        lw_PTMserverLog = new QListWidget(SITIPEMaster);
        lw_PTMserverLog->setObjectName(QString::fromUtf8("lw_PTMserverLog"));
        lw_PTMserverLog->setGeometry(QRect(10, 80, 301, 291));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Calibri")});
        font2.setPointSize(10);
        lw_PTMserverLog->setFont(font2);
        lw_PTMserverLog->setAutoScroll(true);
        lw_PTMserverLog->setItemAlignment(Qt::AlignRight);
        cb_ptmonline = new QCheckBox(SITIPEMaster);
        cb_ptmonline->setObjectName(QString::fromUtf8("cb_ptmonline"));
        cb_ptmonline->setGeometry(QRect(440, 40, 111, 30));
        cb_ptmonline->setStyleSheet(QString::fromUtf8(""));
        cb_ptmonline->setIconSize(QSize(41, 30));
        gb_ioUpdate = new QGroupBox(SITIPEMaster);
        gb_ioUpdate->setObjectName(QString::fromUtf8("gb_ioUpdate"));
        gb_ioUpdate->setGeometry(QRect(560, 0, 181, 71));
        rb_singleTransmit = new QRadioButton(gb_ioUpdate);
        rb_singleTransmit->setObjectName(QString::fromUtf8("rb_singleTransmit"));
        rb_singleTransmit->setGeometry(QRect(10, 25, 101, 20));
        rb_singleTransmit->setChecked(true);
        rb_groupTransmit = new QRadioButton(gb_ioUpdate);
        rb_groupTransmit->setObjectName(QString::fromUtf8("rb_groupTransmit"));
        rb_groupTransmit->setGeometry(QRect(10, 45, 101, 20));
        bu_setGroup = new QPushButton(gb_ioUpdate);
        bu_setGroup->setObjectName(QString::fromUtf8("bu_setGroup"));
        bu_setGroup->setEnabled(false);
        bu_setGroup->setGeometry(QRect(122, 24, 51, 41));
        bu_setGroup->setStyleSheet(QString::fromUtf8(""));
        bu_setGroup->setIconSize(QSize(106, 49));
        bu_setGroup->setFlat(false);
        tabWidget->addTab(SITIPEMaster, QString());
        SITIPESlave = new QWidget();
        SITIPESlave->setObjectName(QString::fromUtf8("SITIPESlave"));
        tabWidget->addTab(SITIPESlave, QString());
        IEC104 = new QWidget();
        IEC104->setObjectName(QString::fromUtf8("IEC104"));
        bu_open104Server = new QPushButton(IEC104);
        bu_open104Server->setObjectName(QString::fromUtf8("bu_open104Server"));
        bu_open104Server->setGeometry(QRect(79, 42, 110, 30));
        bu_open104Server->setFont(font);
        cb_clientConnected = new QCheckBox(IEC104);
        cb_clientConnected->setObjectName(QString::fromUtf8("cb_clientConnected"));
        cb_clientConnected->setGeometry(QRect(13, 43, 60, 29));
        cb_clientConnected->setStyleSheet(QString::fromUtf8(""));
        cb_clientConnected->setIconSize(QSize(41, 30));
        lw_104serverLog = new QListWidget(IEC104);
        lw_104serverLog->setObjectName(QString::fromUtf8("lw_104serverLog"));
        lw_104serverLog->setGeometry(QRect(10, 79, 301, 290));
        lw_104serverLog->setFont(font2);
        lw_104serverLog->setAutoScroll(true);
        lw_104serverLog->setItemAlignment(Qt::AlignRight);
        bu_close104Server = new QPushButton(IEC104);
        bu_close104Server->setObjectName(QString::fromUtf8("bu_close104Server"));
        bu_close104Server->setGeometry(QRect(200, 42, 110, 30));
        bu_close104Server->setFont(font);
        bu_close104Server->setFlat(false);
        label_2 = new QLabel(IEC104);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 12, 81, 30));
        label_2->setFont(font1);
        tb_104port = new QLineEdit(IEC104);
        tb_104port->setObjectName(QString::fromUtf8("tb_104port"));
        tb_104port->setGeometry(QRect(97, 15, 71, 21));
        tb_104port->setFont(font);
        tb_104port->setCursorPosition(5);
        tb_104port->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        tabWidget->addTab(IEC104, QString());
        SIM = new QWidget();
        SIM->setObjectName(QString::fromUtf8("SIM"));
        tabWidget->addTab(SIM, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 848, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);
        bu_disconnect->setDefault(false);
        bu_close104Server->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "SITIPE Master - MMS-Server", nullptr));
        bu_connect->setText(QCoreApplication::translate("MainWindow", "connect", nullptr));
        tb_ptmServerIp->setText(QCoreApplication::translate("MainWindow", "192.168.238.1", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Server IP:", nullptr));
        tb_ptmServerPort->setInputMask(QString());
        tb_ptmServerPort->setText(QCoreApplication::translate("MainWindow", "23000", nullptr));
        tb_ptmServerPort->setPlaceholderText(QCoreApplication::translate("MainWindow", "33333", nullptr));
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
        out_13->setText(QCoreApplication::translate("MainWindow", "13", nullptr));
        out_30->setText(QCoreApplication::translate("MainWindow", "30", nullptr));
        out_8->setText(QCoreApplication::translate("MainWindow", "08", nullptr));
        out_12->setText(QCoreApplication::translate("MainWindow", "12", nullptr));
        out_34->setText(QCoreApplication::translate("MainWindow", "34", nullptr));
        out_26->setText(QCoreApplication::translate("MainWindow", "26", nullptr));
        out_23->setText(QCoreApplication::translate("MainWindow", "23", nullptr));
        out_36->setText(QCoreApplication::translate("MainWindow", "36", nullptr));
        out_11->setText(QCoreApplication::translate("MainWindow", "11", nullptr));
        out_37->setText(QCoreApplication::translate("MainWindow", "37", nullptr));
        out_18->setText(QCoreApplication::translate("MainWindow", "18", nullptr));
        out_15->setText(QCoreApplication::translate("MainWindow", "15", nullptr));
        out_2->setText(QCoreApplication::translate("MainWindow", "02", nullptr));
        out_1->setText(QCoreApplication::translate("MainWindow", "01", nullptr));
        out_40->setText(QCoreApplication::translate("MainWindow", "40", nullptr));
        out_10->setText(QCoreApplication::translate("MainWindow", "10", nullptr));
        out_39->setText(QCoreApplication::translate("MainWindow", "39", nullptr));
        out_29->setText(QCoreApplication::translate("MainWindow", "29", nullptr));
        out_31->setText(QCoreApplication::translate("MainWindow", "31", nullptr));
        out_5->setText(QCoreApplication::translate("MainWindow", "05", nullptr));
        out_24->setText(QCoreApplication::translate("MainWindow", "24", nullptr));
        out_4->setText(QCoreApplication::translate("MainWindow", "04", nullptr));
        out_20->setText(QCoreApplication::translate("MainWindow", "20", nullptr));
        out_16->setText(QCoreApplication::translate("MainWindow", "16", nullptr));
        out_22->setText(QCoreApplication::translate("MainWindow", "22", nullptr));
        out_32->setText(QCoreApplication::translate("MainWindow", "32", nullptr));
        out_25->setText(QCoreApplication::translate("MainWindow", "25", nullptr));
        out_3->setText(QCoreApplication::translate("MainWindow", "03", nullptr));
        out_28->setText(QCoreApplication::translate("MainWindow", "28", nullptr));
        out_21->setText(QCoreApplication::translate("MainWindow", "21", nullptr));
        out_7->setText(QCoreApplication::translate("MainWindow", "07", nullptr));
        out_27->setText(QCoreApplication::translate("MainWindow", "27", nullptr));
        out_38->setText(QCoreApplication::translate("MainWindow", "38", nullptr));
        out_9->setText(QCoreApplication::translate("MainWindow", "09", nullptr));
        out_19->setText(QCoreApplication::translate("MainWindow", "19", nullptr));
        out_14->setText(QCoreApplication::translate("MainWindow", "14", nullptr));
        out_33->setText(QCoreApplication::translate("MainWindow", "33", nullptr));
        out_6->setText(QCoreApplication::translate("MainWindow", "06", nullptr));
        out_17->setText(QCoreApplication::translate("MainWindow", "17", nullptr));
        out_35->setText(QCoreApplication::translate("MainWindow", "35", nullptr));
        out_41->setText(QCoreApplication::translate("MainWindow", "41", nullptr));
        out_43->setText(QCoreApplication::translate("MainWindow", "43", nullptr));
        out_44->setText(QCoreApplication::translate("MainWindow", "44", nullptr));
        out_48->setText(QCoreApplication::translate("MainWindow", "48", nullptr));
        out_45->setText(QCoreApplication::translate("MainWindow", "45", nullptr));
        out_47->setText(QCoreApplication::translate("MainWindow", "47", nullptr));
        out_46->setText(QCoreApplication::translate("MainWindow", "46", nullptr));
        out_42->setText(QCoreApplication::translate("MainWindow", "42", nullptr));
        tb_ptmID->setInputMask(QString());
        tb_ptmID->setText(QString());
        tb_ptmID->setPlaceholderText(QCoreApplication::translate("MainWindow", "00000", nullptr));
        cb_online->setText(QCoreApplication::translate("MainWindow", "TCP OK", nullptr));
        bu_TEST->setText(QCoreApplication::translate("MainWindow", "TEST", nullptr));
        cb_ptmonline->setText(QCoreApplication::translate("MainWindow", "PTM connected", nullptr));
        gb_ioUpdate->setTitle(QCoreApplication::translate("MainWindow", "IO update settings", nullptr));
        rb_singleTransmit->setText(QCoreApplication::translate("MainWindow", "single Transmit", nullptr));
        rb_groupTransmit->setText(QCoreApplication::translate("MainWindow", "group Transmit", nullptr));
        bu_setGroup->setText(QCoreApplication::translate("MainWindow", "SET", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(SITIPEMaster), QCoreApplication::translate("MainWindow", "SITIPE-Master - Client", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(SITIPESlave), QCoreApplication::translate("MainWindow", "SITIPE-Slave - Server", nullptr));
        bu_open104Server->setText(QCoreApplication::translate("MainWindow", "open", nullptr));
        cb_clientConnected->setText(QCoreApplication::translate("MainWindow", "TCP OK", nullptr));
        bu_close104Server->setText(QCoreApplication::translate("MainWindow", "close", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Server Port:", nullptr));
        tb_104port->setInputMask(QString());
        tb_104port->setText(QCoreApplication::translate("MainWindow", "23000", nullptr));
        tb_104port->setPlaceholderText(QCoreApplication::translate("MainWindow", "33333", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(IEC104), QCoreApplication::translate("MainWindow", "IEC61870-5-104 - Server", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(SIM), QCoreApplication::translate("MainWindow", "Simulation", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAINWINDOWQLQQSW_H
