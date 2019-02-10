#include "xml.h"
#include <QDebug>

XML::XML()
{

}

QString XML::generarLogin(QString user, QString pass)
{
    QString devolver = {"<?xml version='1.0' encoding='UTF-8'?>\n"
                        "<!DOCTYPE servicio_tecnico SYSTEM 'http://www.3r1k4.com/dtd/login.dtd'>\n"
                        "<servicio_tecnico>\n"
                        "<action>\n"
                        "login\n"
                        "</action>\n"
                        "<user>\n"
                        +user+"\n"
                        "</user>\n"
                        "<pass>\n"
                        +pass+"\n"
                        "</pass>\n"
                        "</servicio_tecnico>"
                       };
    devolver.replace(0x27,0x22);
    return devolver;

}

QString XML::generarActionConsulta(QString action, QString consulta)
{
    QString devolver = {"<?xml version='1.0' encoding='UTF-8'?>\n"
                        "<!DOCTYPE servicio_tecnico SYSTEM 'http://www.3r1k4.com/dtd/consulta.dtd'>\n"
                        "<servicio_tecnico>\n"
                        "<action>\n"
                        +action+"\n"
                        "</action>\n"
                        "<consulta>\n"
                        +consulta+"\n"
                        "</consulta>\n"
                        "</servicio_tecnico>"
                       };
    devolver.replace(0x27,0x22);
    return devolver;

}

QString XML::generarOrden(QString tienda,QString cliente,QString dispositivo)
{
    QString devolver = {"<?xml version='1.0' encoding='UTF-8'?>\n"
                        "<!DOCTYPE servicio_tecnico SYSTEM 'http://www.3r1k4.com/dtd/orden.dtd'>\n"
                        "<servicio_tecnico>\n"
                        "<action>\n"
                        "orden\n"
                        "</action>\n"
                        "<tienda>\n"
                        +tienda+"\n"
                        "</tienda>\n"
                        "<cliente>\n"
                        +cliente+"\n"
                        "</cliente>\n"
                        "<dispositivo>\n"
                        +dispositivo+"\n"
                        "</dispositivo>\n"
                        "</servicio_tecnico>\n"
                       };
    devolver.replace(0x27,0x22);
    return devolver;
}

//Devuelve el contenido de un nodo
QString XML::devolverNodo(QString *archivoXML, QString nodo)
{
    QString devolver;
    QStringList xml = procesarXML(archivoXML);
    for(int i = 0; i < xml.size(); i++)
    {
         if(xml.at(i) == "<"+nodo+">")
         {
             devolver = xml.at(i+1);
             break;
         }
    }
    return devolver;
}

//Devuelve el contenido de un conjunto de nodos
QStringList XML::devolverNodos(QString *archivoXML, QString nodos)
{
    QStringList devolver;
    QStringList xml = procesarXML(archivoXML);
    for(int i = 0; i < xml.size(); i++)
    {
         if(xml.at(i) == "<"+nodos+">")
         {
             //qDebug() << "entra" << i << nodos;
             devolver.append(xml.at(i+1));
         }
    }
    return devolver;
}

//Limpia la tabulacion y devuelve el string en una lista
QStringList XML::procesarXML(QString *archivoXML)
{
    QStringList devolver = archivoXML->split("\n");
    /*for(auto i : devolver)
    {
        qDebug() << i;
    }*/
    return devolver;
}
