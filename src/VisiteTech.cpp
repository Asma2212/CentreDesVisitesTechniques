#include "VisiteTech.h"

VisiteTech::VisiteTech()
{
    //ctor
}
ostream& operator<<(ostream& out, VisiteTech& V)
{
    out<<"code : ";
    out<<V.codeV;
    out<<"table des visites ";
    for(unsigned i=0;i<V.tests.size();i++)
          out<<V.tests[i]<<'\t';
          return out;
}
istream& operator>>(istream& in, VisiteTech& V)
{
    in>>V.codeV;

}
VisiteTech::~VisiteTech()
{
    //dtor
}
