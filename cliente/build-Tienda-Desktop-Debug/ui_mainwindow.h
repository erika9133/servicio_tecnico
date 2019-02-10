/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab1;
    QLabel *label_7;
    QPushButton *buscar;
    QLabel *label_3;
    QListWidget *listaDispositivos;
    QPushButton *orden;
    QLabel *label_5;
    QLineEdit *dispositivo;
    QLabel *label_4;
    QLabel *label;
    QLineEdit *lineaDispositovos;
    QLineEdit *tienda;
    QLabel *label_6;
    QLabel *label_2;
    QLineEdit *cliente;
    QFrame *exito;
    QLabel *label_16;
    QPushButton *aceptarError;
    QWidget *tab2;
    QListWidget *cambiosRecientes;
    QLabel *label_8;
    QLineEdit *buscarOrden;
    QLabel *label_9;
    QListWidget *listWidget;
    QLabel *label_10;
    QLineEdit *clienteBuscar;
    QLineEdit *idBuscar;
    QLabel *label_11;
    QLabel *label_12;
    QLineEdit *idSimpleBuscar;
    QLabel *label_13;
    QLabel *label_14;
    QLineEdit *estadoBuscar;
    QListWidget *listWidget_2;
    QLabel *label_15;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(774, 582);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 641, 431));
        tab1 = new QWidget();
        tab1->setObjectName(QStringLiteral("tab1"));
        label_7 = new QLabel(tab1);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(320, 230, 121, 18));
        buscar = new QPushButton(tab1);
        buscar->setObjectName(QStringLiteral("buscar"));
        buscar->setGeometry(QRect(20, 80, 181, 34));
        label_3 = new QLabel(tab1);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(240, 135, 81, 20));
        listaDispositivos = new QListWidget(tab1);
        listaDispositivos->setObjectName(QStringLiteral("listaDispositivos"));
        listaDispositivos->setGeometry(QRect(20, 120, 181, 241));
        orden = new QPushButton(tab1);
        orden->setObjectName(QStringLiteral("orden"));
        orden->setGeometry(QRect(320, 250, 191, 34));
        label_5 = new QLabel(tab1);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 60, 181, 18));
        QFont font;
        font.setPointSize(6);
        label_5->setFont(font);
        dispositivo = new QLineEdit(tab1);
        dispositivo->setObjectName(QStringLiteral("dispositivo"));
        dispositivo->setGeometry(QRect(320, 130, 191, 32));
        label_4 = new QLabel(tab1);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 10, 151, 18));
        label = new QLabel(tab1);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(260, 40, 58, 18));
        lineaDispositovos = new QLineEdit(tab1);
        lineaDispositovos->setObjectName(QStringLiteral("lineaDispositovos"));
        lineaDispositovos->setGeometry(QRect(20, 30, 181, 31));
        tienda = new QLineEdit(tab1);
        tienda->setObjectName(QStringLiteral("tienda"));
        tienda->setGeometry(QRect(320, 80, 191, 32));
        label_6 = new QLabel(tab1);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(320, 10, 151, 18));
        label_2 = new QLabel(tab1);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(260, 90, 58, 18));
        cliente = new QLineEdit(tab1);
        cliente->setObjectName(QStringLiteral("cliente"));
        cliente->setGeometry(QRect(320, 30, 191, 32));
        exito = new QFrame(tab1);
        exito->setObjectName(QStringLiteral("exito"));
        exito->setGeometry(QRect(240, 90, 191, 131));
        exito->setAutoFillBackground(true);
        exito->setFrameShape(QFrame::StyledPanel);
        exito->setFrameShadow(QFrame::Raised);
        label_16 = new QLabel(exito);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(30, 30, 241, 20));
        aceptarError = new QPushButton(exito);
        aceptarError->setObjectName(QStringLiteral("aceptarError"));
        aceptarError->setGeometry(QRect(20, 60, 151, 34));
        tabWidget->addTab(tab1, QString());
        tab2 = new QWidget();
        tab2->setObjectName(QStringLiteral("tab2"));
        QFont font1;
        font1.setPointSize(12);
        tab2->setFont(font1);
        cambiosRecientes = new QListWidget(tab2);
        cambiosRecientes->setObjectName(QStringLiteral("cambiosRecientes"));
        cambiosRecientes->setGeometry(QRect(10, 30, 151, 231));
        label_8 = new QLabel(tab2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 0, 151, 31));
        QFont font2;
        font2.setPointSize(10);
        label_8->setFont(font2);
        buscarOrden = new QLineEdit(tab2);
        buscarOrden->setObjectName(QStringLiteral("buscarOrden"));
        buscarOrden->setGeometry(QRect(180, 30, 191, 41));
        label_9 = new QLabel(tab2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(180, 10, 58, 18));
        label_9->setFont(font2);
        listWidget = new QListWidget(tab2);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(180, 90, 191, 171));
        label_10 = new QLabel(tab2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(180, 70, 181, 18));
        label_10->setFont(font);
        clienteBuscar = new QLineEdit(tab2);
        clienteBuscar->setObjectName(QStringLiteral("clienteBuscar"));
        clienteBuscar->setGeometry(QRect(240, 270, 131, 31));
        clienteBuscar->setFont(font2);
        idBuscar = new QLineEdit(tab2);
        idBuscar->setObjectName(QStringLiteral("idBuscar"));
        idBuscar->setGeometry(QRect(30, 270, 151, 31));
        QFont font3;
        font3.setPointSize(7);
        idBuscar->setFont(font3);
        label_11 = new QLabel(tab2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(190, 274, 58, 18));
        label_11->setFont(font2);
        label_12 = new QLabel(tab2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(10, 274, 58, 18));
        label_12->setFont(font2);
        idSimpleBuscar = new QLineEdit(tab2);
        idSimpleBuscar->setObjectName(QStringLiteral("idSimpleBuscar"));
        idSimpleBuscar->setGeometry(QRect(30, 310, 91, 31));
        idSimpleBuscar->setFont(font3);
        label_13 = new QLabel(tab2);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(7, 315, 58, 18));
        label_13->setFont(font2);
        label_14 = new QLabel(tab2);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(130, 315, 58, 18));
        label_14->setFont(font2);
        estadoBuscar = new QLineEdit(tab2);
        estadoBuscar->setObjectName(QStringLiteral("estadoBuscar"));
        estadoBuscar->setGeometry(QRect(180, 310, 191, 31));
        estadoBuscar->setFont(font3);
        listWidget_2 = new QListWidget(tab2);
        listWidget_2->setObjectName(QStringLiteral("listWidget_2"));
        listWidget_2->setGeometry(QRect(390, 30, 191, 311));
        label_15 = new QLabel(tab2);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(390, 10, 151, 18));
        label_15->setFont(font2);
        tabWidget->addTab(tab2, QString());
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setEnabled(false);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "3 Crear orden", Q_NULLPTR));
        buscar->setText(QApplication::translate("MainWindow", "Buscar dispositivo", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Dispositivos", Q_NULLPTR));
        orden->setText(QApplication::translate("MainWindow", "Crear orden", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "*Dejar vacio = ver todos", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "1 Dispositovo a buscar", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Cliente", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "2 Rellenar datos", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Tienda", Q_NULLPTR));
        label_16->setText(QApplication::translate("MainWindow", "Orden creada con exito", Q_NULLPTR));
        aceptarError->setText(QApplication::translate("MainWindow", "Aceptar", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab1), QApplication::translate("MainWindow", "Crear Orden", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "Cambios recientes", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "Buscar", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "*Dejar vacio = ver todos", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "Cliente", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "ID", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "ID2", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "Estado", Q_NULLPTR));
        label_15->setText(QApplication::translate("MainWindow", "Ordenes de mi tienda", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab2), QApplication::translate("MainWindow", "Buscar Orden", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
