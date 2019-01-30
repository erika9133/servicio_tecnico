#include "mainwindow.h"
#include "ui_mainwindow.h"


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
}

void MainWindow::on_pushButton_clicked()
{
      QString consulta = m_xml->generarConsultaDispositivos(ui->lineEdit->text());
      m_cliente->sendMessage(consulta);
}

void MainWindow::reciveMessage(QString message)
{
    ui->listWidget->addItem(message);
}

void MainWindow::on_orden_clicked()
{
    QString orden = m_xml->enerarOrden(ui->tienda->text(),ui->cliente->text(),ui->listWidget->selectedItems().at(0));
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
