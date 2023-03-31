#include "Vehicule.h"

Vehicule::Vehicule(string matricule,string marque ,int age ,TypeConsommation typeCons ,int nbRoues,bool etatFeux,bool etatFrein,bool etatCarosserie,bool etatDirection)
{
    this->matricule=matricule;
    this->marque=marque ;
    this->age=age ;
    this->typeCons=typeCons ;
    this->nbRoues=nbRoues ;
    this->tarif=10.0;
}
void Vehicule::saisie(){
cin>>*this ;
}
void Vehicule::affiche(){
cout<<*this;
}
ostream& operator<<(ostream& out, Vehicule& v)
{
    out<<"matricule: ";
    out<<v.matricule<<endl;
    out<<"marque: ";
    out<<v.marque<<endl;
    out<<"age: ";
    out<<v.age<<endl;
    out<<"Type de consommation : ";
    switch(v.typeCons){
    case Diesel : out<<"Diesel"<<endl;break;
    case Electrique : out<<"Electrique"<<endl;break;
    case Essence : out<<"Essence"<<endl;break;
    case Hybride : out<<"Hybride"<<endl;break;
    }
    out<<"Tarif: ";
    out<<v.tarif<<endl;
    out<<"nombre de roues: ";
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
            case 1 : v.typeCons=Diesel;break;
            case 2 : v.typeCons=Electrique;break;
            case 3 : v.typeCons=Essence;break;
            case 4 : v.typeCons=Hybride;break;
        }
    }while(t <0 || t>4);
}

Vehicule::~Vehicule()
{
    //dtor
}
