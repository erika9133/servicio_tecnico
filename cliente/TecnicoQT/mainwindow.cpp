#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent, Cliente *cliente, XML *xml, QString tienda, QString user) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_xml = xml;
    m_cliente = cliente;
    m_user = user;
    m_xml->generarOrdenesActivas(user,);
    ui->orden->setEnabled(false);
    ui->exito->hide();
    ui->dispositivo->setDisabled(true);
    ui->tienda->setDisabled(true);
    ui->tienda->setText(tienda);
    cargarOrdenesActivas();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_buscar_clicked()
{
      QString consulta = m_xml->generarConsultaDispositivos(ui->lineaDispositovos->text());
      m_cliente->sendMessage(consulta);
}

void MainWindow::recibirListaDispositivos(QString &message)
{    
    ui->listaDispositivos->clear();
    QStringList tipoDispositivos = m_xml->devolverNodos(&message,"consulta");
    if(!tipoDispositivos.empty())
    {
        for(int i = 0; i < tipoDispositivos.size(); i++)
        {
            ui->listaDispositivos->addItem(tipoDispositivos.at(i));
        }
    }
}

void MainWindow::recibirOrdenExito()
{

}

void MainWindow::on_orden_clicked()
{
    QString orden = m_xml->generarOrden(ui->tienda->text(),ui->cliente->text(),ui->listaDispositivos->selectedItems().at(0)->text());
    m_cliente->sendMessage(orden);
}

void MainWindow::comprobarBotonOrden()
{
    //refactor, pensado para elegir a mano cliente tienda y disp
    if(m_dispositivoVerificacion && m_tiendaVerificacion && m_clienteVerificacion)
    {
        ui->orden->setEnabled(true);
    }else{
        ui->orden->setEnabled(false);
    }
}

void MainWindow::on_cliente_textChanged(const QString &arg1)
{
    QString texto = arg1;
    if(QString::compare(texto, "", Qt::CaseInsensitive) !=0){
        m_clienteVerificacion = true;
    }else{
        m_clienteVerificacion = false;
    }
    comprobarBotonOrden();
}

void MainWindow::on_tienda_textChanged(const QString &arg1)
{
    QString texto = arg1;
    if(QString::compare(texto, "", Qt::CaseInsensitive) !=0){
        m_tiendaVerificacion = true;
    }else{
        m_tiendaVerificacion = false;
    }
    comprobarBotonOrden();
}

void MainWindow::on_listaDispositivos_itemClicked(QListWidgetItem *item)
{
    m_dispositivoVerificacion = true;
    ui->dispositivo->setText(item->text());
    comprobarBotonOrden();
}

void MainWindow::on_aceptarError_clicked()
{
    ui->exito->hide();
}

void MainWindow::cargarOrdenesActivas()
{
    QString consulta = m_xml->generarActionConsulta("ordenesActivas","Reparando");
    m_cliente->sendMessage(consulta);
}
