#ifndef MISSION_H
#define MISSION_H
#include<QString>
#include <QSqlQuery>
#include <memory>
#include <QSqlQueryModel>
#include <QDate>


class mission
{
private:
    int id;
    int cin;
    QString horaire;
    QString type;
    QString emplacement;
    QString date;
public:
    mission();
    mission(int,int,QString,QString,QString,QString);

    int getId();
    int getCin();
    QString getHoraire();
    QString getType();
    QString getEmplacement();
    QString getDate();

    void setId(int);
    void setCin(int);
    void setHoraire(QString);
    void setType(QString);
    void setEmplacement(QString);
    void setDate(QString);

    bool ajouter_mission(mission);
    int creat_ID();
    QSqlQueryModel *afficherAll();
    bool supprimerMission(int id);
    bool modifierMission(int id,QString horaire , QString type , QString emplacement);
    bool trouverMission(int id);
};

#endif // MISSION_H
