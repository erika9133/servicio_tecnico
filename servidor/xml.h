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
    QString generarRespuestaSimple(QString action, QString respuesta);
    QString generarDispositivos(QStringList *dispositivos);
    QString generarLogin(bool verificacion);
    QStringList procesarOrden(QStringList *orden);
    bool validaXML(QString *archivoXML);
    QString devolverNodo(QString *archivoXML, QString nodo);
    QStringList devolverNodos(QString *archivoXML, QString nodos);
    QStringList procesarXML(QString *archivoXML);
};

#endif // XML_H
