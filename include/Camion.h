#ifndef CAMION_H
#define CAMION_H

#include <Vehicule.h>

class Camion : public Vehicule
{
    float charge;
    int nbRouesSupp;
    bool etatRoueSupp=true;
    public:
        Camion();
        Camion(float charge,int nbRouesSupp,bool etatRoueSupp,string matricule,string marque ,int age ,TypeConsommation typeCons ,int nbRoues,bool etatFeux,bool etatFrein,bool etatCarosserie,bool etatDirection)
        :Vehicule(matricule,marque,age,typeCons ,nbRoues,etatFeux,etatFrein,etatCarosserie,etatDirection)
        {this->charge=charge;}
        virtual ~Camion();
        void affiche();
        void saisie();
        friend ostream& operator<<(ostream&, Camion&);
        friend istream& operator>>(istream&, Camion&);
        friend ostream& operator<<(ostream&, Camion*);
        friend istream& operator>>(istream&, Camion*);
        float getCharge(){return charge;}

    protected:

    private:
};

#endif // CAMION_H
