#ifndef utilisateur_H
#define utilisateur_H
#include<QString>


class utilisateur
{
    QString Type;
    QString mdp;
    QString Identifiant;
    QString cin;

public:
    utilisateur();

    QString getType()
    {return Type;}
    QString getmdp()
    {return mdp;}
    QString getIdentifiant()
    {return Identifiant;}
    QString getcin()
    {return cin; }

    void setType(QString t)
    {Type=t;}
    void setmdp(QString m)
    {mdp=m;}
    void setIdentifiant(QString id)
    { Identifiant=id;}
    void secin(QString c)
    {cin=c; }
    void ajouter();

};

#endif // utilisateur_H
