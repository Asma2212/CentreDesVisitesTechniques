#ifndef RESERVATION_H
#define RESERVATION_H
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
    Vehicule v ;
    bool payee = false ;
    public:
        Reservation();
        friend istream& operator>>(istream&, Reservation&);
        virtual ~Reservation();

    protected:

    private:
};

#endif // RESERVATION_H
