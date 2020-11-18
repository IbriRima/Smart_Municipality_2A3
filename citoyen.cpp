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
    QString id= QString::number(Id_cit);
    QString tel= QString::number(Tel_cit);
    query.prepare("INSERT INTO CITOYEN (ID_CIT,NOM_CIT,PRENOM_CIT,SEXE_CIT,DATE_CIT,LIEU_CIT,MAIL_CIT,TEL_CIT)"" VALUES(:Id_cit, :Nom_cit, :Prenom_cit, :Sexe_cit,:Date_cit,:Lieu_cit,:Mail_cit,:Tel_cit)");
    query.bindValue(":Id_cit",id);
    query.bindValue(":Nom_cit",Nom_cit);
    query.bindValue(":Prenom_cit",Prenom_cit);
    query.bindValue(":Sexe_cit",Sexe_cit);
    query.bindValue(":Date_cit",Date_cit);
    query.bindValue(":Lieu_cit",Lieu_cit);
    query.bindValue(":Mail_cit",Mail_cit);
    query.bindValue(":Tel_cit",tel);
    return query.exec();

}
bool Citoyen::supprimer(int Id_cit)
{
   QSqlQuery query;
   QString id= QString::number(Id_cit);
   query.prepare("DELETE FROM CITOYEN WHERE ID_CIT= :id");
   query.bindValue(":id",id);
   return query.exec();

}

QSqlQueryModel * Citoyen::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();

       model->setQuery("select *from CITOYEN");
       model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_CIT"));
       model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM_CIT"));
       model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM_CIT"));
       model->setHeaderData(3,Qt::Horizontal,QObject::tr("SEXE_CIT"));
       model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATE_CIT"));
       model->setHeaderData(5,Qt::Horizontal,QObject::tr("LIEU_CIT"));
       model->setHeaderData(6,Qt::Horizontal,QObject::tr("MAIL_CIT"));
       model->setHeaderData(7,Qt::Horizontal,QObject::tr("TEL_CIT"));

       return model;
}
