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
    //The QDomDocument class represents an XML document.
    QDomDocument xmlBOM;
    // Load xml file as raw data
    QFile f(*archivoXML);
    if (!f.open(QIODevice::ReadOnly ))
    {
        // Error while loading file
        std::cerr << "Error while loading file" << std::endl;
        return 0;
    }
    // Set data into the QDomDocument before processing
    xmlBOM.setContent(&f);
    f.close();


    // Extract the root markup
    QDomElement root=xmlBOM.documentElement();

    // Get root names and attributes
    QString Type=root.tagName();
    //QString Board=root.attribute("BOARD","No name");
    //int Year=root.attribute("YEAR","1900").toInt();

    // Display root data
    std::cout << "Type  = " << Type.toStdString().c_str() << std::endl;
    //std::cout << "Board = " << Board.toStdString().c_str() << std::endl;
    //std::cout << "Year  = " << Year << std::endl;
    std::cout << std::endl;

    // Get the first child of the root (Markup COMPONENT is expected)
    QDomElement Component=root.firstChild().toElement();

    // Loop while there is a child
    while(!Component.isNull())
    {
        // Check if the child tag name is COMPONENT
        if (Component.tagName()=="Orden")
        {

            // Read and display the component ID
            QString ID=Component.attribute("ID","No ID");

            // Get the first child of the component
            QDomElement Child=Component.firstChild().toElement();

            QString Name;
            double Value;

            // Read each child of the component node
            while (!Child.isNull())
            {
                // Read Name and value
                if (Child.tagName()=="NAME") Name=Child.firstChild().toText().data();
                if (Child.tagName()=="VALUE") Value=Child.firstChild().toText().data().toDouble();

                // Next child
                Child = Child.nextSibling().toElement();
            }

            // Display component data
            std::cout << "Component " << ID.toStdString().c_str() << std::endl;
            std::cout << "   Name  = " << Name.toStdString().c_str() << std::endl;
            std::cout << "   Value = " << Value << std::endl;
            std::cout << std::endl;
        }

        // Next component
        Component = Component.nextSibling().toElement();
    }





}
