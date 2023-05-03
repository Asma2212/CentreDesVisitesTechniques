#ifndef VOITURE_H
#define VOITURE_H
#include<stack>
#include <Vehicule.h>

class VisiteTech;
class Voiture : public Vehicule
{
    stack<int*> visiteEff;
    public:
        Voiture();
        virtual ~Voiture();
        Voiture& operator=(const Voiture&);
        Voiture(const Voiture&);
        void affiche();
        void saisie();

        friend istream& operator>>(istream&, Voiture&);
        friend ostream& operator<<(ostream&, Voiture&);
        stack<int*> getVE();
      /*  void changeEtatRoueAvG(){etatRoueAvG = false;}
        void changeEtatRoueAvD(){etatRoueAvD = false ;}
        void changeEtatRoueArG(){etatRoueAvG = false;}
        void changeEtatRoueArD(){etatRoueAvD = false ;}*/

};

#endif // VOITURE_H
