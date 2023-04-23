#ifndef CLIENT_H
#define CLIENT_H
#include <fstream>
#include <iostream>
#include<string>
#include <Personne.h>
#include<cctype>
#include<limits>
#include"Date.h"
#include <vector>
#include "CentreVT.h"
#include "ElementsMap.h"
using namespace std;


class Client : public Personne
{    vector<Reservation> listRes ;
     ElementsMap<int,VisiteTech> MapVisites;
    public:
        Client();
        virtual ~Client();
        void menuClient(CentreVT*);
        void sinscrire(CentreVT&);
        void authentifier(CentreVT&);
        void modifierD(CentreVT&);
        void effectuerRes(CentreVT*);
        void consulterRes();
        void supprimerRes();
        Reservation & operator[](int);
        int getCin(){
        return this->cn ;
        }
        bool existDate(Date,int);
        void ajouterRes(Reservation&);
        void enregistrer(Reservation);
        void recuperer(CentreVT*);
        void creer(fstream &);
        void reload();
        friend ostream& operator<<(ostream&, Client&);
        friend istream& operator>>(istream&, Client&);
    protected:

    private:
};

#endif // CLIENT_H
