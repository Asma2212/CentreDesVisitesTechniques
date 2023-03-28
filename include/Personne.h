#ifndef PERSONNE_H
#define PERSONNE_H
#include "MyExceptions.h"
#include <iostream>
#include <fstream>
#include<string>
#include"CentreVT.h"
#include"Date.h"
using namespace std;

class Personne
{
    protected :
    int cn;
    string nom;
    string prenom;
    int numTel;
    Date dateNaiss;
    string email;
    string mdp;
    public:
        Personne(){};
        void inscrire(CentreVT&);
        void authentifier(CentreVT&);
        void modifierD(CentreVT&);
        friend ostream& operator<<(ostream& out, Personne& P);
        friend istream& operator>>(istream& in, Personne& P);
        virtual ~Personne();
};

#endif // PERSONNE_H
