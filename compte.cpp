#include "compte.h"
#include"connection.h"
#include<QDebug>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QMessageBox>

#include<QSqlQueryModel>
compte::compte()
{

}

compte::compte(QString Type,QString Identifiant,QString cin,QString mdp)
{
    this->Type=Type;
    this->Identifiant=Identifiant;
    this->cin=cin;
    this->mdp=mdp;
}

bool compte::ajouter()
{

      QSqlQuery query;



      query.prepare("insert into compte (ID,MDP,TYPE,CIN)" "values (:ID,:MDP,:TYPE,:CIN)");
      query.bindValue(":ID",Identifiant);
      query.bindValue(":MDP",mdp);
      query.bindValue(":TYPE",Type);
      query.bindValue(":CIN",cin);

      return query.exec();

}

QSqlQueryModel * compte::load()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select ID from compte");
    query.exec();
    model->setQuery(query);
    return model;
}

QSqlQueryModel * compte::read(QString info)
{

    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from compte where ID='"+info+"'");
   model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
   model->setHeaderData(1,Qt::Horizontal,QObject::tr("MDP"));
   model->setHeaderData(2,Qt::Horizontal,QObject::tr("TYPE"));

   model->setHeaderData(3,Qt::Horizontal,QObject::tr("CIN"));
   return model;

}

bool compte::Delete(QString info)
{
    QSqlQuery query;
    query.prepare("Delete from compte where ID='"+info+"'");
    return query.exec();
}

bool compte::Update()
{

    QSqlQuery query;

    query.prepare("update compte set ID='"+Identifiant+"',MDP='"+mdp+"',TYPE='"+Type+"',CIN='"+cin+"' where ID='"+ Identifiant+"'");


    //Creation des variables liées
    query.bindValue(":ID",Identifiant);
    query.bindValue(":MDP",mdp);
    query.bindValue(":TYPE",Type);
    query.bindValue(":CIN",cin);

    //exec() envoie la requete pour l'executer
    return query.exec();
}

QSqlQuery compte::editview(QString info)

{

    QSqlQuery query;

    query.prepare("select * from compte where ID='"+info+"'");

    if(query.exec())

    {

        return query;

    }

}

QSqlQueryModel * compte::chercher(QString info)
{

    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select id from compte where ID='"+info+"'");
    query.exec();
    model->setQuery(query);
    return model;
}
