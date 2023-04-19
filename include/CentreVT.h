#ifndef CENTREVT_H
#define CENTREVT_H
#include<Reservation.h>
#include<string>
#include <vector>
#include"VisiteTech.h"

using namespace std;
class Equipement;
class Personne;
class Agent;
class VisiteTech;

class CentreVT
{
    string nom="Centre Abir et Asma";
    vector <VisiteTech*> visites;
    vector <Personne*> personnes;
    vector <Equipement*> equipements;
    public:
        CentreVT();
        virtual ~CentreVT();
        static void creer(fstream&);
        friend ostream& operator<<(ostream& out,CentreVT& C);
        friend ostream& operator<<(ostream& out,CentreVT* C);
        friend istream& operator>>(istream& in,CentreVT* C);
        void ajouterVisite(Reservation* r);
        void consulterVisite();
        void affecterAgentsVisites();

    friend class Equipement;
    friend class Personne;
    friend class Agent;
    friend class Client;
    friend class VisiteTech;

};

#endif // CENTREVT_H
