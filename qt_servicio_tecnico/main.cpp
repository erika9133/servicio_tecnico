#include <QCoreApplication>
#include "controlador.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Controlador * ctl = new Controlador();
    ctl->iniciarBBDD();
    ctl->iniciarWS();


    return a.exec();

}
