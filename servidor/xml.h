#ifndef XML_H
#define XML_H

#include <QObject>
#include <QString>
#include <QStringList>
#include <QUuid>
#include <QFile>
#include <QXmlInputSource>
#include <QDomDocument>


class XML : public QObject
{
    Q_OBJECT

public:
    XML();
   ~XML();
    static QString generarRespuestaSimple(QString action, QString respuesta);
    static QString generarActionConsultas(QString action, QStringList *consultas);
    static QString generarLogin(bool verificacion);
    static QStringList procesarOrden(QStringList *orden);
    static bool validaXML(QString *archivoXML);
    static QString devolverNodo(QString *archivoXML, QString nodo);
    static QStringList devolverNodos(QString *archivoXML, QString nodos);
    static QStringList procesarXML(QString *archivoXML);
};

#endif // XML_H
