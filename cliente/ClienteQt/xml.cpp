#include "xml.h"
#include <QDebug>

XML::XML()
{

}

QString XML::generarConsultaDispositivos(QString consulta)
{
    //Espacio separa las cadenas
    QString devolver = {"<?xml version='1.0' encoding='UTF-8'?>\n"
                        "<!DOCTYPE servicio_tecnico SYSTEM 'http://www.3r1k4.com/dtd/dispositivos.dtd'>\n"
                        "<servicio_tecnico>\n"
                        "<action>\n"
                        "dispositivos\n"
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
             qDebug() << "entra" << i << nodos;
             devolver.append(xml.at(i+1));
         }
    }
    return devolver;
}

//Limpia la tabulacion y devuelve el string en una lista
QStringList XML::procesarXML(QString *archivoXML)
{
    QStringList devolver = archivoXML->split("\n");
    for(auto i : devolver)
    {
        qDebug() << i;
    }
    return devolver;
}
