#ifndef CLIENT_H
#define CLIENT_H
#include <fstream>
#include <iostream>
#include<string>
#include <Personne.h>
#include"CentreVT.h"
#include"Reservation.h"
using namespace std;


class Client : public Personne
{
    vector<Reservation> listRes ;
    public:
        Client();
        virtual ~Client();
        void sinscrire(CentreVT&);
        void effectuerRes();
        void consulterRes();
        void menuClient(CentreVT);
        int getCin(){
        return this->cn ;
        }
        string getNomP(){
        return this->nom +" " + this->prenom ;
        }
    protected:

    private:
};

#endif // CLIENT_H
