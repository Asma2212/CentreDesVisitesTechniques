#ifndef RESERVATION_H
#define RESERVATION_H
#include <time.h>
#include"Date.h"
#include"Vehicule.h"
#include"Moto.h"
#include"Voiture.h"
#include"Camion.h"
using namespace std;

class Reservation
{
    static int codeR;
    Date dateR;
    int heure;
    float paiement;
    Vehicule *v ;
    bool payee = false ;
    public:
        Reservation();
        friend ostream& operator<<(ostream&, Reservation&);
        friend istream& operator>>(istream&, Reservation&);
        friend istream& operator>>(istream&, Reservation*);
        friend ostream& operator<<(ostream&, Reservation*);
        void saisieRes();
        void setPayee(){ payee = true ;}
        void setVehicule(Vehicule&);
        Date getDate(){return dateR;}
        int getHeure(){return heure;}
        virtual ~Reservation(){}

    protected:

    private:
};

#endif // RESERVATION_H
