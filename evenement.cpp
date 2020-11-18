#include "evenement.h"

Evenement::Evenement()
{

}

Evenement::Evenement(int id,QString nom,QString type,QString date,QString horaire,QString empl ,QString etat )
{
    this->Id_event=id;
    this->Nom_event=nom;
    this->Type_event=type;
    this->Date_event=date;
    this->Horaire_event=horaire;
    this->Empl_event=empl;
    this->Etat_event=etat;

}

bool Evenement::ajouter()
{
    QSqlQuery query;
    QString id= QString::number(Id_event);
    query.prepare("INSERT INTO EVENEMENT (ID_EVENT,NOM_EVENT,TYPE_EVENT,DATE_EVENT,HORAIRE_EVENT,EMPL_EVENT,ETAT_EVENT)"" VALUES(:Id_event, :Nom_event, :Type_event, :Date_event,:Horaire_event,:Empl_event,:Etat_event)");
    query.bindValue(":Id_event",id);
    query.bindValue(":Nom_event",Nom_event);
    query.bindValue(":Type_event",Type_event);
    query.bindValue(":Date_event",Date_event);
    query.bindValue(":Horaire_event",Horaire_event);
    query.bindValue(":Empl_event",Empl_event);
    query.bindValue(":Etat_event",Etat_event);
    return query.exec();

}


bool Evenement::supprimer(int Id_event)
{
   QSqlQuery query;
   QString id= QString::number(Id_event);
   query.prepare("DELETE FROM EVENEMENT WHERE ID_EVENT= :id");
   query.bindValue(":id",id);
   return query.exec();

}

QSqlQueryModel * Evenement::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();

       model->setQuery("select *from Evenement");
       model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_EVENT"));
       model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM_EVENT"));
       model->setHeaderData(2,Qt::Horizontal,QObject::tr("TYPE_EVENT"));
       model->setHeaderData(3,Qt::Horizontal,QObject::tr("DATE_EVENT"));
       model->setHeaderData(4,Qt::Horizontal,QObject::tr("HORAIRE_EVENT"));
       model->setHeaderData(5,Qt::Horizontal,QObject::tr("EMPL_EVENT"));
       model->setHeaderData(6,Qt::Horizontal,QObject::tr("ETAT_EVENT"));

       return model;
}
