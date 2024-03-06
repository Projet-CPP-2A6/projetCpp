#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlError>
#include <QSqlQuery>
#include<QSqlDatabase>
class Connection
{
public:
    Connection();
    bool createconnect();
};

#endif // CONNECTION_H
