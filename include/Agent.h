#ifndef AGENT_H
#define AGENT_H
#include<vector>
#include <iostream>
#include <fstream>
#include<string>
#include "Personne.h"
#include"VisiteTech.h"
#include"CentreVT.h"
#include"Equipement.h"
using namespace std;

class Agent : public Personne
{
    string poste;
    vector <VisiteTech*> listVisites;
    public:
        Agent();
        void validerEtatVisite(VisiteTech,Vehicule*);
        void EnregistreVisite(VisiteTech);
        void authentifier(CentreVT&);
        void sinscrire(CentreVT&);
        void modifierD(CentreVT&);
        void ConsulterEq(CentreVT&);
        Equipement& rechEq(string,CentreVT&);
        friend istream& operator>>(istream& ,Agent&);
        friend ostream& operator<<(ostream&, Agent&);
        virtual ~Agent();
};

#endif // AGENT_H
