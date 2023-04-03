#include "Test.h"

Test::Test()
{
    //ctor
}
istream& operator>>(istream& in, Test& T)
 {
     cout<<"etat"<<endl;
     in>>T.etat;
     return in;
 }
ostream& operator<<(ostream& out, Test& T)
{
    out<<"etat :"<<T.etat;
}
Test::~Test()
{
    //dtor
}
