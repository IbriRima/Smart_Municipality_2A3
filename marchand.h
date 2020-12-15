#ifndef marchant_H
#define marchant_H
#include<QString>
#include <QSqlQuery>
#include <memory>
#include <QSqlQueryModel>
#include <QDate>

class marchant
{
private:
    int id;
    QString nom;
    QString prenom;
    QString empl;
    QString num;
public:
    marchant();
    marchant(int,QString,QString,QString,QString);

    int getId();
    QString getNom();
    QString getPrenom();
    QString getEmpl();
    QString getNum();

    void setId(int);
    void setNom(QString);
    void setPrenom(QString);
    void setEmpl(QString);
    void setNum(QString);

    bool ajouter_marchant(marchant);
    int creat_ID();
    QSqlQueryModel *afficherAll();
    bool supprimerMarchant(int id);
    bool modifierMarchant(int id , QString nom , QString prenom , QString empl , QString num);
    bool trouverMarchant(int id);
};

#endif // marchant_H
