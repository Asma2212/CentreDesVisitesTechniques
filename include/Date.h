#include <iostream>
#include <fstream>
#include<string>
using namespace std;
#ifndef DATE_H
#define DATE_H


class Date
{
    int jour,mois,annee;
    public:
        Date();
        friend istream& operator>>(istream& in,Date& D);
        friend ostream& operator<<(ostream& out,Date& D);
        virtual ~Date();
};

#endif // DATE_H
