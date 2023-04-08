#ifndef EXTERIEUR_H
#define EXTERIEUR_H

#include <Test.h>
#include<Vehicule.h>
#include<Moto.h>
#include<Camion.h>
#include<Voiture.h>
#include<Exterieur.h>

class Exterieur : public Test
{
    public:
        Exterieur();
        virtual ~Exterieur();
        bool testCarrosserie(Vehicule*);
        bool testFeux(Vehicule*);
        bool testRoues(Vehicule*);
};

#endif // EXTERIEUR_H
