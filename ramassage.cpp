#include "ramassage.h"
#include"connection.h"

#include<QDebug>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QModelIndex>
#include <QVector>
Ramassage::Ramassage()
{}


bool Ramassage::ajouter()
{



      QSqlQuery query;


      query.prepare("insert into RAMASSAGE (ID_RAMASSAGE,MATRICULE_CAMION,DATE_RAMASSAGE,"
                          "NOMBRE_POUBELLE,DUREE,NOM_CARTIER,HEURE_DEBUT) values(:id,:Matricule,:date,:nb_p,:duree,:cartier,:heure)");
query.bindValue(":id",getId_Ramassage());
query.bindValue(":Matricule",getMatricule());

query.bindValue(":date",getDate());
query.bindValue(":nb_p",getNbPoubelle());
query.bindValue(":duree",getDuree().toString("HH:mm"));
query.bindValue(":cartier",getNom_cartier());
query.bindValue(":heure", getHdepart().toString());
/*
query.bindValue(":ID_chauffeur",getIdchauffeur());
query.bindValue(":ID_empl1",getId_empl1());
query.bindValue(":ID_empl2",getId_empl2());
 */
return query.exec();

}
bool Ramassage::affectation(QString ch)
{
    QSqlQuery query;


query.prepare("insert into EMPLOYE_RAMASSAGE (ID_RAMASSAGE,CIN) values(:id,:CIN)");
qDebug()<<"id "<<getId_Ramassage();
qDebug()<<"CIN "<<ch;
query.bindValue(":id",getId_Ramassage());
query.bindValue(":CIN",ch);



return query.exec();
}


QSqlQueryModel * Ramassage ::afficher()
{
    QSqlQueryModel *model= new QSqlQueryModel();
    model->setQuery("SELECT ID_RAMASSAGE FROM RAMASSAGE ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("IDENTIFIANT"));


return model;
}

 QVector<QString> Ramassage::afficheremploye(QString* ID)
{

    QSqlQuery q;
QString ch;

   q.prepare("select * from EMPLOYE_RAMASSAGE where ID_RAMASSAGE='"+*ID+"' ");
   if(q.exec())
   {
       while(q.next())
       {
           ch= q.value(0).toString();
           *ID=q.value(1).toString();
          tab.push_back(ch);
       }

   }
for(int i=0;i<tab.size();i++)
    qDebug()<<tab[i];
return tab;
}


void Ramassage::Remplissage(QString* ID,QString*Matricule,QString*Date,QString*Nb_poubelle,QString*Nom_Cartier,QString*Duree,QString*Heure)
{
//QVector<Ramassage> tabR;
    QSqlQuery q;

   q.prepare("select * from RAMASSAGE where ID_RAMASSAGE='"+*ID+"'");

    if(q.exec())
    {
        while(q.next())
        {
*ID= q.value(0).toString();
*Matricule=q.value(1).toString();
*Date   =q.value(2).toString();
*Nb_poubelle  =q.value(3).toString();
*Duree  =q.value(4).toString();
*Nom_Cartier  =q.value(5).toString();
*Heure=q.value(6).toString();

}
    }

/*Id_chauffeur=q.value(2).toString();
*id_empl1=q.value(3).toString();
*id_empl2=q.value(4).toString();*/

}

bool Ramassage::Supprimer(QString ID)
{

    QSqlQuery query;
    query.prepare("Delete from RAMASSAGE where ID_RAMASSAGE = :ID");
    query.bindValue(":ID",ID);
    return query.exec();
}

bool Ramassage::SupprimerEmploye(QString ID)
{

    QSqlQuery query;
    query.prepare("Delete from EMPLOYE_RAMASSAGE where ID_RAMASSAGE = :ID");
    query.bindValue(":ID",ID);
    return query.exec();
}

bool Ramassage::Modifier(QString ID, QString Matricule, QString Date, QString Nb_poubelle, QString Nom_cartier, QString Duree, QString Heure)
{
    QSqlQuery query;



query.prepare("update RAMASSAGE set MATRICULE_CAMION= :Matricule,DATE_RAMASSAGE= :date,NOMBRE_POUBELLE= :nb_p,DUREE= :duree,NOM_CARTIER= :cartier,HEURE_DEBUT= :heure where ID_RAMASSAGE= :ID");

query.bindValue(":ID",ID);
query.bindValue(":Matricule",Matricule);

query.bindValue(":date",Date);
query.bindValue(":nb_p",Nb_poubelle);
query.bindValue(":duree",Duree);
query.bindValue(":cartier",Nom_cartier);
query.bindValue(":heure", Heure);

/*
query.bindValue(":ID_chauffeur",Id_chauffeur);
query.bindValue(":id_empl1",id_empl1);
query.bindValue(":id_empl2",id_empl2);
*/

return   query.exec();

}
/*QVector<QString> Ramassage::ModifierEmploye(QString ID,QString CIN_Chauffeur)
{


QSqlQuery q;
qDebug()<<"CIN? "<<CIN_Chauffeur;

q.prepare("update EMPLOYE_RAMASSAGE set CIN= :CIN where ID_RAMASSAGE= :ID");
q.bindValue(":CIN",CIN_Chauffeur);
q.bindValue(":ID",ID);
q.exec();
//  tab.push_back(CIN_Chauffeur);

return tab;
}*/

QSqlQueryModel* Ramassage::Recherche(int indice,QString ch)
{



QSqlQueryModel *model= new QSqlQueryModel();
if(indice==1)
{
    model->setQuery("select ID_RAMASSAGE from RAMASSAGE where  ID_RAMASSAGE='"+ch+"'");
}
    else if (indice==2)
{
     model->setQuery("select ID_RAMASSAGE from RAMASSAGE where Matricule_Camion= '"+ch+"' ");
}
else if (indice==3)
{
 model->setQuery("select ID_RAMASSAGE from RAMASSAGE where DATE_RAMASSAGE= '"+ch+"' ");
}
else if (indice==4)
{
 model->setQuery("select ID_RAMASSAGE from RAMASSAGE where NOMBRE_POUBELLE= '"+ch+"' ");
}
else if (indice==5)
{
 model->setQuery("select ID_RAMASSAGE from RAMASSAGE where DUREE= '"+ch+"' ");
}
else if (indice==6)
{
 model->setQuery("select ID_RAMASSAGE from RAMASSAGE where HEURE_DEBUT= '"+ch+"' ");
}
else if (indice==7)
{
 model->setQuery("select ID_RAMASSAGE from RAMASSAGE where NOM_CARTIER= '"+ch+"' ");
}

model->setHeaderData(0,Qt::Horizontal,QObject::tr("IDENTIFIANT"));


return model;
}

QSqlQueryModel * Ramassage ::afficherSTAT()
{
    QSqlQueryModel *model= new QSqlQueryModel();
    model->setQuery("SELECT ID_RAMASSAGE,NOMBRE_POUBELLE,DATE_RAMASSAGE FROM RAMASSAGE ORDER BY DATE_RAMASSAGE ASC");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nombre de poubelle"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("Date"));
return model;
}
