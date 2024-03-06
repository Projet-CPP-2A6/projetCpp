#include "connection.h"

Connection::Connection()
{
}
bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("projet_gallery");
db.setUserName("rihemm");
db.setPassword("zoghlami");

if (db.open())
test=true;

    return  test;
}
