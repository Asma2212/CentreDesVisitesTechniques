#include "Travailleur.h"

Travailleur::Travailleur()
{
    //ctor
}


Travailleur::Travailleur(const Travailleur& tr) {

        for (auto& spe : tr.specialites) {
            specialites.push_back(new string(*spe));
        }
    }

Travailleur& Travailleur::operator=(const Travailleur& tr) {
        if (this != &tr) {
        while (!specialites.empty()) {
            delete specialites.front();
            specialites.pop_front();
        }
        specialites.clear();
        for (auto& spe : tr.specialites) {
            specialites.push_back(new string(*spe));
        }
    }
}

void Travailleur::ajouter(string* sp){
specialites.push_back(sp);
}

void Travailleur::modifier(string* sp){
    list<string*>::iterator it;
    for (it = specialites.begin(); it != specialites.end(); ++it) {
        if(*it == sp)
            *it=sp;
    }
}
void Travailleur::supprimer(string* sp){
    specialites.remove(sp);
}

Travailleur::~Travailleur()
{
 {
        while (!specialites.empty()) {
            delete specialites.front();
            specialites.pop_front();
        }
    }
}
