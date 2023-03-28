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
        bool validerEtatVisite(VisiteTech);
        void EnregistreVisite(VisiteTech);
        void ConsulterEq(CentreVT&);
        Equipement& rechEq(string,CentreVT&);
        virtual ~Agent();
};

#endif // AGENT_H