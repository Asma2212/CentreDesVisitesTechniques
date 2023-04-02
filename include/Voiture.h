#ifndef VOITURE_H
#define VOITURE_H

#include <Vehicule.h>


class Voiture : public Vehicule
{
    bool etatCarrosserie;
    bool etatRoueAvG = true;
    bool etatRoueAvD = true;
    bool etatRoueArG = true;
    bool etatRoueArD = true;
    public:
        Voiture();
        void affiche();
        void saisie();
        virtual ~Voiture();


    protected:

    private:
};

#endif // VOITURE_H
