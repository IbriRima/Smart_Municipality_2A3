#include "marchant.h"
#include <QSqlDatabase>
#include <QSql>
#include <QVector>
#include<QVariant>
#include <memory>

marchant::marchant(){}
 marchant::marchant(int id,QString nom,QString prenom,QString empl,QString num){
     this->id=id;
     this->nom=nom;
     this->prenom=prenom;
     this->empl=empl;
     this->num=num;
 }
 int marchant::getId(){
     return this->id;
 }
 QString marchant::getNom(){
     return this->nom;
 }
 QString marchant::getPrenom(){
     return this->prenom;
 }
 QString marchant::getEmpl(){
     return this->empl;
 }
 QString marchant::getNum(){
     return this->num;
 }

 void marchant::setId(int id){
     this->id=id;
 }
 void marchant::setNom(QString nom){
     this->nom=nom;
 }
 void marchant::setPrenom(QString prenom){
     this->prenom=prenom;
 }
 void marchant::setEmpl(QString empl){
     this->empl=empl;
 }
 void marchant::setNum(QString num){
     this->num=num;
 }

 bool marchant::ajouter_marchant(marchant marchant){
     QSqlQuery query;
         query.prepare("INSERT INTO MARCHANT (ID, NOM, PRENOM ,EMPL ,NUM) "
                       "VALUES (:ID, :NOM, :PRENOM, :EMPL, :NUM)");

         query.bindValue(":ID", marchant.getId());
         query.bindValue(":NOM", marchant.getNom());
         query.bindValue(":PRENOM", marchant.getPrenom());
         query.bindValue(":EMPL", marchant.getEmpl());
         query.bindValue(":NUM", marchant.getPrenom());

         query.exec();
 }

 bool marchant::trouverMarchant(int id){
     QSqlQuery query;
     query.prepare("SELECT * FROM MARCHANT WHERE ID = :ID ");
     query.bindValue(":ID",id);
     query.exec();
     if(query.exec())
         while(query.next()){
                        return true;
                }
                return false;
 }

 bool marchant::supprimerMarchant(int id){
     QSqlQuery  query;
    query.prepare("DELETE FROM MARCHANT WHERE ID = '" + QString::number(id) + "'");

     query.exec();
 }

 QSqlQueryModel * marchant::afficherAll(){
     QSqlQueryModel * model= new QSqlQueryModel();

     model->setQuery("select * from marchant");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("EMPL"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("NUM"));
         return model;
 }
 bool marchant::modifierMarchant(int id , QString nom , QString prenom , QString empl , QString num){
     QSqlQuery query;
     query.prepare("update marchant set nom =:nom,prenom=:prenom,empl=:empl"
                       " where ID=:ID");

         query.bindValue(":nom",nom);
         query.bindValue(":prenom",prenom);
         query.bindValue(":empl",empl);
         query.bindValue(":num",num);
         query.bindValue(":ID",id);

        return query.exec();
 }
 int marchant::creat_ID(){
     QSqlQuery query;
     query.prepare("select max(ID) from MARCHANT");
     query.exec();
     int i;
     while(query.next())
         {
             i=query.value(0).toInt()+1;
         }

     return i;
 }
