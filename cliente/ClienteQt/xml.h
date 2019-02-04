#ifndef XML_H
#define XML_H

#include <QObject>
#include <QString>

class XML
{
public:
    XML();
    QString generarConsultaDispositivos(QString consulta);
    QString generarOrden(QString tienda,QString cliente,QString dispositivo);
    QString devolverNodo(QString *archivoXML, QString nodo);
    QStringList devolverNodos(QString *archivoXML, QString nodos);
    QStringList procesarXML(QString *archivoXML);
};

#endif // XML_H
