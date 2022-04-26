#include "connection.h"
#include<QSqlDatabase>
Connection::Connection(){}

bool Connection::createconnection()
{
    db = QSqlDatabase::addDatabase("QODBC");
    bool test=false;
    db.setDatabaseName("THA_2022");
    db.setUserName("med");
    db.setPassword("med");

    if (db.open())
    return true;
    return test;
}

void Connection::closeConnection(){ db.close();}
