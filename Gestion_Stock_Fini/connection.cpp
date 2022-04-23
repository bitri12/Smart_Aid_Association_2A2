#include "connection.h"

connection::connection()
{

}

bool connection::createconnect()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("");
    db.setDatabaseName("projet");
    db.setUserName("root");//inserer nom de l'utilisateur
    db.setPassword("");//inserer mot de passe de cet utilisateur*/
    return db.open();
}
