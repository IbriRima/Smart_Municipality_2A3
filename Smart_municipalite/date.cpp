#include "date.h"

Date::Date()
{

}

int Date::getMois() const
{
    return mois;
}

void Date::setMois(int value)
{
    mois = value;
}

int Date::getJour() const
{
    return jour;
}

void Date::setJour(int value)
{
    jour = value;
}

int Date::getAn() const
{
    return an;
}

void Date::setAn(int value)
{
    an = value;
}
