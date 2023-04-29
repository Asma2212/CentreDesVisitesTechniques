#ifndef VOITURE_H
#define VOITURE_H

#include <Vehicule.h>


class Voiture : public Vehicule
{
    public:
        Voiture();
        void affiche();
        void saisie();
        virtual ~Voiture();
        friend istream& operator>>(istream&, Voiture&);
      /*  void changeEtatRoueAvG(){etatRoueAvG = false;}
        void changeEtatRoueAvD(){etatRoueAvD = false ;}
        void changeEtatRoueArG(){etatRoueAvG = false;}
        void changeEtatRoueArD(){etatRoueAvD = false ;}*/


    protected:

    private:
};

#endif // VOITURE_H
