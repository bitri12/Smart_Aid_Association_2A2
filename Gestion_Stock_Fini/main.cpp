#include "menugestionstock.h"

#include <QApplication>
#include "connection.h"
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    menuGestionStock w;
    w.show();
    connection c;
    bool test = c.createconnect();
    if(test){
        QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Done"),QMessageBox::Cancel);

    }
    return a.exec();
}
