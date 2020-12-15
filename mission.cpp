#include "mission.h"
#include <QSqlDatabase>

#include <QSql>

#include <QVector>

#include<QVariant>
#include<QDebug>
#include <memory>

 mission::mission(){}
 mission::mission(int id, int cin , QString horaire , QString type , QString emplacement , QString date){
     this->id=id;
     this->cin=cin;
     this->horaire=horaire;
     this->type=type;
     this->emplacement=emplacement;
     this->date=date;
 }
 int mission::getId(){
     return this->id;
 }
 int mission::getCin(){
     return this->cin;
 }
 QString mission::getHoraire(){
     return this->horaire;
 }
 QString mission::getEmplacement(){
     return this->emplacement;
 }
 QString mission::getType(){
     return this->type;
 }
 QString mission::getDate(){
     return this->date;
 }

 void mission::setId(int id){
     this->id=id;
 }
 void mission::setCin(int cin){
     this->cin=cin;
 }
 void mission::setType(QString type){
     this->type=type;
 }
 void mission::setEmplacement(QString emplacement){
     this->emplacement=emplacement;
 }
 void mission::setDate(QString date){
     this->date=date;
 }
 void mission::setHoraire(QString horaire){
     this->horaire=horaire;
 }

 bool mission::ajouter_mission(mission mission){
     QSqlQuery query;
         query.prepare("INSERT INTO mission (ID, CIN_AGENT, HORAIRE_DEPART, TYPE ,EMPLACEMENT ,DATE_EXECUT) "
                       "VALUES (:ID, :CIN, :HORAIRE, :TYPE , :EMPLACEMENT , :DATE)");

         query.bindValue(":ID", mission.getId());
         query.bindValue(":CIN", mission.getCin());
         query.bindValue(":HORAIRE", mission.getHoraire());
         query.bindValue(":EMPLACEMENT", mission.getEmplacement());
         query.bindValue(":TYPE", mission.getType());
         query.bindValue(":DATE", mission.getDate());


         query.exec();
 }

 bool mission::trouverMission(int id){
     QSqlQuery query;
     query.prepare("SELECT * FROM mission WHERE ID = :ID ");
     query.bindValue(":ID",id);
     query.exec();
     if(query.exec())
         while(query.next()){
                        return true;
                }
                return false;
 }

 bool mission::supprimerMission(int id){
     QSqlQuery  query;
    query.prepare("DELETE FROM mission WHERE ID = '" + QString::number(id) + "'");

     query.exec();
 }

 QSqlQueryModel * mission::afficherAll(){
     QSqlQueryModel * model= new QSqlQueryModel();

     model->setQuery("select * from mission");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("CIN"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("HORAIRE"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("EMPLACEMENT"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("TYPE"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("DATE"));
         return model;
 }
 bool mission::modifierMission(int id, QString horaire , QString type , QString emplacement){
     QSqlQuery query;
     query.prepare("update mission set horaire_depart=:horaire,type=:type,emplacement=:emplacement"
                       " where ID=:ID");

     query.bindValue(":ID", id);
     query.bindValue(":horaire", horaire);
     query.bindValue(":emplacement", emplacement);
     query.bindValue(":type", type);

        return query.exec();
 }
 int mission::creat_ID(){
     QSqlQuery query;
     query.prepare("select max(ID) from mission");
     query.exec();
     int i;
     while(query.next())
         {
             i=query.value(0).toInt()+1;
         }

     return i;
 }
