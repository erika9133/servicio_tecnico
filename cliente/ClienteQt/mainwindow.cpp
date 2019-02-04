#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_xml = new XML();
    m_cliente = new Cliente();
    connect(m_cliente, SIGNAL(enviarMainWindow(QString)),this,SLOT(reciveMessage(QString)));
    ui->orden->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_xml;
    delete m_cliente;
}

void MainWindow::on_pushButton_clicked()
{
      QString consulta = m_xml->generarConsultaDispositivos(ui->lineEdit->text());
      m_cliente->sendMessage(consulta);
}

void MainWindow::reciveMessage(QString message)
{
    QString tipoConsulta = m_xml->devolverNodo(&message,"action");
    if(tipoConsulta == "dispositivos")
    {
        ui->listWidget->clear();
        QStringList tipoDispositivos = m_xml->devolverNodos(&message,"consulta");
        if(!tipoDispositivos.empty())
        {
            qDebug() << "tipo dis" << tipoDispositivos.at(0);
            //QStringList devolverDispositivos = m_consultas->devolverDispositivosAceptados(tipoDispositivo);
            for(int i = 0; i < tipoDispositivos.size(); i++)
            {
                ui->listWidget->addItem(tipoDispositivos.at(i));
            }
        }
    }
}

void MainWindow::on_orden_clicked()
{
    QString orden = m_xml->generarOrden(ui->tienda->text(),ui->cliente->text(),ui->listWidget->selectedItems().at(0)->text());
    m_cliente->sendMessage(orden);
}

void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    dispositivo = true;
    comprobarBotonOrden();
}

void MainWindow::comprobarBotonOrden()
{
    if(dispositivo && tienda && cliente)
    {
        ui->orden->setEnabled(true);
    }else{
        ui->orden->setEnabled(false);
    }
}

void MainWindow::on_cliente_textChanged(const QString &arg1)
{
    QString texto = ui->cliente->text();
    if(QString::compare(texto, "", Qt::CaseInsensitive) !=0){
        cliente = true;
    }else{
        cliente = false;
    }
    comprobarBotonOrden();
}

void MainWindow::on_tienda_textChanged(const QString &arg1)
{
    QString texto = ui->tienda->text();
    if(QString::compare(texto, "", Qt::CaseInsensitive) !=0){
        tienda = true;
    }else{
        tienda = false;
    }
    comprobarBotonOrden();
}
