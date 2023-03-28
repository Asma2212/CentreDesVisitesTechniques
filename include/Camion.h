#ifndef CAMION_H
#define CAMION_H

#include <Vehicule.h>

class Camion : public Vehicule
{
    float charge;
    public:
        Camion();
        virtual ~Camion();
        friend ostream& operator<<(ostream&, Camion&);
        friend istream& operator>>(istream&, Camion&);

    protected:

    private:
};

#endif // CAMION_H
