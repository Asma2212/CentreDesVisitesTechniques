#ifndef ADMIN_H
#define ADMIN_H
#include "CentreVT.h"
#include <vector>
#include "Personne.h"
#include "Travailleur.h"
using namespace std;

class Admin: public Personne , public Travailleur
{
    vector<string*> roles;
    public:
        Admin();
        virtual ~Admin();
        void consulterVisite(CentreVT&);
        void affecterAgentsVisites(CentreVT&);
        void ajouterAgent(CentreVT&);
        void afficherAgents(CentreVT&);
        int nombreAgents(CentreVT&);
        void sinscrire(CentreVT&);
        void authentifier(CentreVT&);
        void modifierD(CentreVT&){}

    protected:

    private:
};

#endif // ADMIN_H
