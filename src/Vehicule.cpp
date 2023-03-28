#include "Vehicule.h"



ostream& operator<<(ostream& out, Vehicule& v)
{
    cout<<"matricule: ";
    out<<v.matricule<<endl;
    cout<<"marque: ";
    out<<v.marque<<endl;
    cout<<"age: ";
    out<<v.age<<endl;
    cout<<"Type de consommation : ";
    out<<v.typeCons<<endl;
    cout<<"Tarif: ";
    out<<v.tarif<<endl;
    cout<<"nombre de roues: ";
    out<<v.nbRoues<<endl;
}
istream& operator>>(istream& in, Vehicule& v)
{
    int t;
    cout<<"entrer votre matricule"<<endl;
    in>>v.matricule;
    cout<<"entrer votre marque"<<endl;
    in>>v.marque;
    cout<<"entrer l'age du vehicule"<<endl;
    in>>v.age;
    cout<<"entrer le nombre des roues"<<endl;
    in>>v.nbRoues;
    cout<<"entrer le type de consommation"<<endl;
    do{
        cout<<"\t 1 : Diesel "<<endl;
        cout<<"\t 2 : Electrique "<<endl;
        cout<<"\t 3 : Essence "<<endl;
        cout<<"\t 4 : Hybride "<<endl;
        cin>>t;
        switch(t)
        {
            case 1 : v.typeCons=Diesel;
            case 2 : v.typeCons=Electrique;
            case 3 : v.typeCons=Essence;
            case 4 : v.typeCons=Hybride;
        }
    }while(t <0 || t>4);
}

Vehicule::~Vehicule()
{
    //dtor
}
