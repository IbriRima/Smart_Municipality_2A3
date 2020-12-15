#include "connection.h"
#include<QSqlDatabase>
Connection::Connection()
{

}
bool Connection::TestConnection()
{

    bool test=false;

QSqlDatabase db=QSqlDatabase ::addDatabase("QODBC");
db.setDatabaseName("Projet_2A");
db.setUserName("Rima");
db.setPassword("rima");

if(db.open())
return true;
return test;

}
