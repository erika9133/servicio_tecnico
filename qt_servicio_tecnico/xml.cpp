#include <QDebug>

#include <QtXml>
#include <QXmlSimpleReader>
#include <QXmlDefaultHandler>
#include <iostream>
#include <libxml/parser.h>
#include <libxml/tree.h>

#include "xml.h"
#include "utils.h"

XML::XML()
{
    //std::string archivoXML = "test_external.xml";
   // validaXML(archivoXML.c_str());
}


XML::~XML(){}

void XML::GenerarOrden(QUuid id)
{
    QString nombre = "Orden_"+id.toString();
    QString archivo =nombre+".xml";

    Utils::crearArchivo(archivo);
    QStringList xmldoc = {"<documento>",
                          "<id>"+nombre+"</id>",
                          "</documento>"
                          ""};
   Utils::escribir(archivo,xmldoc);

}

void XML::RecibirOrden()
{

}


bool XML::validaXML(QString *archivoXML)
{

    bool result = false;

        /// Crea el contexto del analizador.
        xmlParserCtxtPtr ctxt = xmlNewParserCtxt();
        if (ctxt == NULL)
        {
            qDebug() << "Error al crear el contexto del analizador." ;
            return false;
        } // end if

        /// Analiza el archivo activando la opción de validación DTD.
        xmlDocPtr doc = xmlCtxtReadFile(ctxt, archivoXML->toStdString().c_str(), NULL, XML_PARSE_DTDVALID);
        if (doc == NULL)
        {
              qDebug() << "Error al analizar el archivo." ;
            return false;
        } // end if

        /// Comprueba la validez del XML.
        if (ctxt->valid == 0)
        {
              qDebug() << "El archivo XML no es valido." ;
        } else {
              qDebug() << "El archivo XML es valido." ;

        } // end if

        /// Libera memoria.
        xmlFreeDoc(doc);
        xmlFreeParserCtxt(ctxt);

        return result;

}

int XML::tipo(QString *archivoXML)

{
