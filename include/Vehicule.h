#ifndef VEHICULE_H
#define VEHICULE_H
#include <iostream>
#include "TypeConsommation.h"
#include"string"
using namespace std;

class Vehicule
{
    protected:
    string matricule;
    string marque ;
    int age ;
    bool etatFeux = true;
    int nbRoues ;
    float tarif=10.0;
    TypeConsommation typeCons ;
    public:
        Vehicule(){};
        virtual ~Vehicule();
        friend ostream& operator<<(ostream&, Vehicule&);
        friend istream& operator>>(istream&, Vehicule&);
        void affiche();
        void saisie();

    protected:

    private:
};

#endif // VEHICULE_H
