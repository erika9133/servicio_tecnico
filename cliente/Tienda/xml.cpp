#include "xml.h"
#include <QDebug>
#include <QDomComment>

XML::XML()
{

}

QString XML::generarLogin(QString user, QString pass)
{
    QString devolver = {"<?xml version='1.0' encoding='UTF-8'?>"
                        "<!DOCTYPE servicio_tecnico SYSTEM 'http://www.3r1k4.com/dtd/login.dtd'>"
                        "<servicio_tecnico>"
                        "<action>"
                        "login"
                        "</action>"
                        "<user>"
                        +user+""
                        "</user>"
                        "<pass>"
                        +pass+""
                        "</pass>"
                        "</servicio_tecnico>"
                       };
    devolver.replace(0x27,0x22);
    return devolver;

}

QString XML::generarActionConsulta(QString action, QString consulta)
{
    QString devolver = {"<?xml version='1.0' encoding='UTF-8'?>"
                        "<!DOCTYPE servicio_tecnico SYSTEM 'http://www.3r1k4.com/dtd/consulta.dtd'>"
                        "<servicio_tecnico>"
                        "<action>"
                        +action+
                        "</action>"
                        "<consulta>"
                        +consulta+
                        "</consulta>"
                        "</servicio_tecnico>"
                       };
    devolver.replace(0x27,0x22);
    return devolver;

}

QString XML::generarOrden(QString tienda,QString cliente,QString dispositivo)
{
    QString devolver = {"<?xml version='1.0' encoding='UTF-8'?>"
                        "<!DOCTYPE servicio_tecnico SYSTEM 'http://www.3r1k4.com/dtd/orden.dtd'>"
                        "<servicio_tecnico>"
                        "<action>"
                        "orden"
                        "</action>"
                        "<tienda>"
                        +tienda+""
                        "</tienda>"
                        "<cliente>"
                        +cliente+
                        "</cliente>"
                        "<dispositivo>"
                        +dispositivo+
                        "</dispositivo>"
                        "</servicio_tecnico>"
                       };
    devolver.replace(0x27,0x22);
    return devolver;
}
//Devuelve el contenido de un nodo
QString XML::devolverNodo(QString *archivoXML, QString nodo)
{
    QString devolver = "";

    QString xmlText = *archivoXML;
    QDomDocument doc;
    doc.setContent(xmlText);
    QDomNodeList list = doc.elementsByTagName(nodo);
    devolver = list.at(0).toElement().text();
    return devolver;
}

//Devuelve el contenido de un conjunto de nodos
QStringList XML::devolverNodos(QString *archivoXML, QString nodos)
{
    QStringList devolver;
    QString xmlText = *archivoXML;
    QDomDocument doc;
    doc.setContent(xmlText);
    QDomNodeList list = doc.elementsByTagName(nodos);
    for(int i = 0 ; i < list.size() ; i++)
    {
        devolver.append(list.at(i).toElement().text());
    }
    return devolver;
}
/*
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
    QStringList devolver = { "null"};
      //QStringList devolver = archivoXML->split("\n");
      for(auto i : *archivoXML)
      {
          devolver << i;
      }
      return devolver;
}*/
