#ifndef MOTO_H
#define MOTO_H

#include <Vehicule.h>


class Moto : public Vehicule
{
    bool etatRoueAv = true;
    bool etatRoueAr = true;
    public:
        Moto();
        virtual ~Moto();
        void affiche();
        void saisie();

    protected:

    private:
};

#endif // MOTO_H
