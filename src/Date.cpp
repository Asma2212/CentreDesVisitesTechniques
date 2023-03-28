#include <iostream>
#include <fstream>
#include<string>
using namespace std;
#include "Date.h"

Date::Date()
{
    //ctor
}
istream& operator>>(istream& in,Date& D)
{
    in>>D.jour;
    in>>D.mois;
    in>>D.annee;
    return in;
}
ostream& operator<<(ostream& out,Date& D)
{
    out<<D.jour<<"/";
    out<<D.mois<<"/";
    out<<D.annee<<endl;
    return out;
}
Date::~Date()
{
    //dtor
}
