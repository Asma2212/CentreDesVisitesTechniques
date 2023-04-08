#ifndef INTERIEUR_H
#define INTERIEUR_H

#include<Vehicule.h>
#include<Moto.h>
#include<Camion.h>
#include<Voiture.h>
#include<Exterieur.h>
#include <Test.h>


class Interieur : public Test
{
    public:
        Interieur();
        bool testDirection(Vehicule* V);
        bool testFrein(Vehicule* V);
        virtual ~Interieur();
};

#endif // INTERIEUR_H
