#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H

#include <iostream>
#include <fstream>
#include<string>
#include"CentreVT.h"
using namespace std;

class Equipement
{
    string rf;
    string libelle;
    int quantite;
    public:
        Equipement();
        Equipement(string,string,int);
        friend istream& operator>>(istream& in,Equipement& E);
        friend ostream& operator<<(ostream& out,Equipement& E);
        void ajouterEq(CentreVT& );
        void suppEq(string,CentreVT&);
        void modifierEq(string,CentreVT&);
      //  string getref();
        virtual ~Equipement();
    friend class Agent;
};

#endif // EQUIPEMENT_H
