#ifndef MOTO_H
#define MOTO_H

#include <Vehicule.h>


class Moto : public Vehicule
{
    public:
        Moto();
        virtual ~Moto();
        void affiche();
        void saisie();
        friend istream& operator>>(istream&, Moto&);
    protected:

    private:
};

#endif // MOTO_H
