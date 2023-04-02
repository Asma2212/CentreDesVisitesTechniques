#include <iostream>
#include <fstream>
#include <time.h>
#include<string>
using namespace std;
#ifndef DATE_H
#define DATE_H


class Date
{
    public:
    int jour,mois,annee;
    public:
        Date(int j,int m,int a)
        {
            jour=j;mois=m;annee=a;
        }
        Date();
        void affiche();
        friend istream& operator>>(istream& in,Date& D);
        friend ostream& operator<<(ostream& out,Date& D);
        friend istream& operator>>(istream& in,Date* D);
        friend ostream& operator<<(ostream& out,Date* D);
        friend bool operator==(Date&,Date&);
        Date dateCourante();
        bool verifDate(Date);
        virtual ~Date();
};

#endif // DATE_H
