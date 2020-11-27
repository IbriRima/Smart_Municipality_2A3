#ifndef DATE_H
#define DATE_H


class Date
{
public:
    Date();



    int getMois() const;
    void setMois(int value);

    int getJour() const;
    void setJour(int value);

    int getAn() const;
    void setAn(int value);

private:

    int jour;
    int mois;
    int an;


};

#endif // DATE_H
