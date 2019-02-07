#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "xml.h"
#include "cliente.h"
#include "mainwindow.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
     MainWindow(QWidget *parent = 0, Cliente *cliente = nullptr, XML *xml = nullptr, QString tienda = nullptr);
    ~MainWindow();
     void reciveMessageApplicacion(QString &message);
private slots:
    void on_buscar_clicked();
    void on_orden_clicked();
    void on_cliente_textChanged(const QString &arg1);
    void on_tienda_textChanged(const QString &arg1);
    void on_listaDispositivos_itemClicked(QListWidgetItem *item);
private:
    Ui::MainWindow *ui;
    Cliente *m_cliente;
    XML *m_xml;
    bool m_dispositivoVerificacion;
    bool m_clienteVerificacion;
    bool m_tiendaVerificacion;

    void comprobarBotonOrden();
};

#endif // MAINWINDOW_H
