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
db.setUserName("wasim");
db.setPassword("wassim");

if(db.open())
return true;
return test;

}
