#ifndef VEHICULE_H
#define VEHICULE_H
#include <iostream>
#include "TypeConsommation.h"
#include"string"
#include "MyExceptions.h"
using namespace std;

class Vehicule
{
    protected:
    string matricule;
    string marque ;
    int age ;
    TypeConsommation typeCons ;
    int nbRoues ;
    float tarif=10.0;
    bool etatFeux;
    bool etatFrein;
    bool etatCarosserie;
    bool etatDirection;
    public:
        Vehicule(){};
        Vehicule(string matricule,string marque ,int age ,TypeConsommation typeCons ,int nbRoues,bool etatFeux=true,bool etatFrein=true,bool etatCarosserie=true,bool etatDirection=true);
        virtual ~Vehicule();
        friend ostream& operator<<(ostream&, Vehicule&);
        friend istream& operator>>(istream&, Vehicule&);
        friend istream& operator>>(istream&, Vehicule*);
        friend ostream& operator<<(ostream&, Vehicule*);
        virtual void affiche();
        virtual void saisie();
        void changeEtatCarosserie(){etatCarosserie = false;}
        void changeEtatFeux(){etatFeux = false;}
        void changeEtatFrein(){etatFrein = false;}
        void changeEtatDirection(){etatDirection = false;}

    protected:

    private:
};

#endif // VEHICULE_H
