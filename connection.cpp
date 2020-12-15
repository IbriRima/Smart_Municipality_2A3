#include "connection.h"
#include<QSqlDatabase>
Connection::Connection()
{

}
bool Connection::TestConnection()
{

    bool test=false;

QSqlDatabase db=QSqlDatabase ::addDatabase("QODBC");
db.setDatabaseName("wassim");
db.setUserName("wassim");
db.setPassword("wassim");

if(db.open())
return true;
return test;

}
