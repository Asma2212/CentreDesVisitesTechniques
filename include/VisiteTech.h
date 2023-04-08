#ifndef VISITETECH_H
#define VISITETECH_H
#include<string>
#include <vector>
#include <iostream>
#include <fstream>
#include"CentreVT.h"
#include"Vehicule.h"
#include"Test.h"

using namespace std;
class CentreVT;
class Test;

class VisiteTech
{
    string codeV;
    bool etatExt;
    bool etatInt;
    public:
        VisiteTech();
        friend ostream& operator<<(ostream& out, VisiteTech& V);
        friend istream& operator>>(istream& in, VisiteTech& V);
        void afficherVisite(Vehicule V);
        void modifierVisite(CentreVT,string);
        void saisiEtatInt(Vehicule*);
        void saisitEtatExt(Vehicule*);
        virtual ~VisiteTech();
        friend class Test;

};

#endif // VISITETECH_H
