#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "xml.h"
#include "cliente.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void on_buscar_clicked();
    void reciveMessage(QString message);
    void on_orden_clicked();
    void comprobarBotonOrden();
    void on_cliente_textChanged(const QString &arg1);
    void on_tienda_textChanged(const QString &arg1);
    void on_listaDispositivos_itemClicked(QListWidgetItem *item);

private:
    Ui::MainWindow *ui;
    Cliente *m_cliente;
    XML *m_xml;
    bool dispositivo;
    bool cliente;
    bool tienda;
};

#endif // MAINWINDOW_H
