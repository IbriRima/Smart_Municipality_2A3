#include "ressourcemateriels.h"
#include "ui_mainwindow.h"

#include<QString>
#include<QVector>


QString gen_random() {

    QString tmp_s;
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    //srand( (unsigned) time(NULL) * getpid());

    for (int i = 0; i < 5; ++i)
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];


    return tmp_s;

}

RessourceMateriels::RessourceMateriels()
{
    //id_composant=gen_random();
    etat_composant = 1;


}

QString RessourceMateriels::getId_composant() const
{
    return id_composant;
}

void RessourceMateriels::setId_composant(int value)
{
    id_composant = value;
}

QString RessourceMateriels::getType_composant() const
{
    return type_composant;
}

void RessourceMateriels::setType_composant(const QString &value)
{
    type_composant = value;
}

int RessourceMateriels::getEtat_composant() const
{
    return etat_composant;
}

void RessourceMateriels::setEtat_composant(int value)
{
    etat_composant = value;
}

double RessourceMateriels::getPosx_composant() const
{
    return posx_composant;
}

void RessourceMateriels::setPosx_composant(double value)
{
    posx_composant = value;
}

double RessourceMateriels::getPosy_composant() const
{
    return posy_composant;
}

void RessourceMateriels::setPosy_composant(double value)
{
    posy_composant = value;
}



QString RessourceMateriels::getNom_route() const
{
    return nom_route;
}

void RessourceMateriels::setNom_route(const QString &value)
{
    nom_route = value;
}

/////////Methodes ///

void RessourceMateriels::AfficherComposant(QVector<RessourceMateriels> RessourceMateriels){


}
