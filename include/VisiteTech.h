#ifndef VISITETECH_H
#define VISITETECH_H
#include<string>
#include <vector>
#include <iostream>
#include <fstream>
#include"CentreVT.h"
#include"Vehicule.h"
#include"Exterieur.h"
#include "Reservation.h"

using namespace std;
class CentreVT;


class VisiteTech
{
    static int nbVisite;
    int codeV;
    Exterieur testExt;
    bool etatExt;
    bool etatInt;
    Reservation *res;
    public:
        VisiteTech();
        friend ostream& operator<<(ostream& out,const VisiteTech& V);
        friend istream& operator>>(istream& in, VisiteTech& V);
        void afficherVisite(Vehicule V);
        void modifierVisite(CentreVT,string);
        void saisiEtatInt(Vehicule*);
        void saisitEtatExt(Vehicule*);
        void setRes(Reservation* r){this->res=r;}
        virtual ~VisiteTech();
        friend class Test;
        friend class Reservation;

};

#endif // VISITETECH_H
