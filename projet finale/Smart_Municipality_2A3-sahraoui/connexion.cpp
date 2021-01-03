
#include "connexion.h"

connexion::connexion()
{

};

bool connexion::ouvrircnx(){
      QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
      db.setDatabaseName("Source_Projet2A");
      db.setUserName("Sahraoui");//inserer nom de l'utilisateur
      db.setPassword("esprit20");//inserer mot de passe de cet utilisateur
if(db.open())
    return  true;
    return false;
}
void connexion::fermercnx(){
    db.close();


}
