#ifndef TRAVAILLEUR_H
#define TRAVAILLEUR_H

#include "vector"
#include "string"
using namespace std;

class Travailleur
{
protected:
    vector<string*> specialites;
    public:
        Travailleur();
        virtual ~Travailleur();

    protected:

    private:
};

#endif // TRAVAILLEUR_H
