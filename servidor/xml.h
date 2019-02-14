#ifndef XML_H
#define XML_H

#include <QObject>
#include <QString>
#include <QStringList>
#include <QUuid>
#include <QFile>
#include <QXmlInputSource>
#include <QDomDocument>


class XML
{
public:
    XML();
   ~XML();
    //Validar
    static bool validaXML(const QString *archivoXML);

    //Generar respuestas A clientes
    static QString generarRespuestaSimple(const QString action, const QString respuesta);
    static QString generarActionConsultas(const QString action, const QStringList *consultas);
    static QString generarLogin(const bool verificacion);

    //Procesar respuestas DE clientes
    static QStringList procesarOrden(const QStringList *orden);
    static QStringList procesarXML(const QString *archivoXML);

    static QString devolverNodo(const QString *archivoXML, const QString nodo);
    static QStringList devolverNodos(const QString *archivoXML, const QString nodos);

    static void escribir(const QString archivo, const QString linea);
    static void escribir(const QString archivo, const QStringList lista);
    static void crearArchivo(const QString archivo);
};

#endif // XML_H
