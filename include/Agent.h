#ifndef AGENT_H
#define AGENT_H
#include<vector>
//#include"CentreVT.h"
#include "Personne.h"
//#include"Test.h"
#include "Equipement.h"
#include "VisiteTech.h"
using namespace std;
class VisiteTech;
class Equipement;

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
        void ajouterVisite(VisiteTech* v){listVisites.push_back(v);}
        int getNbVisites(){return listVisites.size();}
        Equipement& rechEq(string,CentreVT&);
        friend istream& operator>>(istream& ,Agent&);
        friend ostream& operator<<(ostream&, Agent&);
        virtual ~Agent();
};

#endif // AGENT_H
