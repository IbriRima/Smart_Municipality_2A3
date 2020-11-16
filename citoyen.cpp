#include "citoyen.h"

Citoyen::Citoyen()
{

}
Citoyen::Citoyen(int id,QString nom,QString prenom,QString sexe,QString date,QString lieu ,QString mail ,int tel)
{
    this->Id_cit=id;
    this->Nom_cit=nom;
    this->Prenom_cit=prenom;
    this->Sexe_cit=sexe;
    this->Date_cit=date;
    this->Lieu_cit=lieu;
    this->Mail_cit=mail;
    this->Tel_cit=tel;
}
bool Citoyen::ajouter()
{
    QSqlQuery query;
    QString res = QString::number(Id_cit);

    query.prepare("insert into citoyen (identifiant,Nom,Prenom,Sexe,Date_naissance,Lieu_naissance,adresse_mail,numéro_Tel"" values :Id_cit, :Nom_cit, :Prenom_cit, :Sexe_cit,:Date_cit,:Lieu_cit,:Mail_cit,:Tel_cit");
    query.bindValue(":Id_cit",res);
    query.bindValue(":Nom_cit",Nom_cit);
    query.bindValue(":Prenom_cit",Prenom_cit);
    query.bindValue(":Sexe_cit",Sexe_cit);
    query.bindValue(":Date_cit",Date_cit);
    query.bindValue(":Lieu_cit",Lieu_cit);
    query.bindValue(":Mail_cit",Mail_cit);
    query.bindValue(":Tel_cit",Tel_cit);
    return query.exec();

}

