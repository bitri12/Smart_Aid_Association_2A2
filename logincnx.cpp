#include "logincnx.h"
#include"connection.h"




Connection1::Connection1()
{

}

bool Connection1::createconnect1()
{bool test=false;
QSqlDatabase db1 = QSqlDatabase::addDatabase("QODBC");
db1.setDatabaseName("THA_2022");
db1.setUserName("med");//inserer nom de l'utilisateur
db1.setPassword("med");//inserer mot de passe de cet utilisateur

if (db1.open())
test=true;





    return  test;
}
void Connection1::closeConnection1(){db1.close();}
