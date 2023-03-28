#ifndef CENTREVT_H
#define CENTREVT_H

#include<string>
#include <vector>
#include"VisiteTech.h"

using namespace std;
class Equipement;
class Personne;
class Agent;
class CentreVT
{
    string nom;
    vector <VisiteTech*> visites;
    vector <Personne*> personnes;
    vector <Equipement*> equipements;
    public:
        CentreVT();
        virtual ~CentreVT();
        friend ostream& operator<<(ostream& out,CentreVT& C);
    friend class Equipement;
    friend class Personne;
    friend class Agent;
    friend class Client;

};

#endif // CENTREVT_H
