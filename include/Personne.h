#ifndef PERSONNE_H
#define PERSONNE_H
#include "MyExceptions.h"
#include <iostream>
#include <fstream>
#include<string>
#include"CentreVT.h"
#include"Date.h"
#include"Reservation.h"
#include"VisiteTech.h"
using namespace std;

class Personne
{
    protected:
    int cn;
    string nom;
    string prenom;
    int numTel;
    Date dateNaiss;
    string email;
    string mdp;
    public:
        Personne();
        virtual void sinscrire(CentreVT&)=0;
        virtual void authentifier(CentreVT&)=0;
        virtual void modifierD(CentreVT&)=0;
        int getcn(){return cn;};
        string getmdp(){return mdp;};
        string getEmail(){return email;};
        friend ostream& operator<<(ostream& out, Personne& P);
        friend istream& operator>>(istream& in, Personne& P);
        virtual ~Personne();
};

#endif // PERSONNE_H
