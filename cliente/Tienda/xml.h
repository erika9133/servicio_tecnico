#ifndef XML_H
#define XML_H

#include <QObject>
#include <QString>

class XML
{
public:
    XML();
    static QString generarLogin(QString user, QString pass);
    static QString generarActionConsulta(QString action, QString consulta);
    static QString generarOrden(QString tienda,QString cliente,QString dispositivo);
    static QString devolverNodo(QString *archivoXML, QString nodo);
    static QStringList devolverNodos(QString *archivoXML, QString nodos);
    static QStringList procesarXML(QString *archivoXML);
};

#endif // XML_H
