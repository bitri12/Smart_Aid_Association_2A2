#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>

class Connection1
{
    QSqlDatabase db1;
public:
    Connection1();
    bool createconnect1();
    void closeConnection1();
};

#endif // CONNECTION_H
