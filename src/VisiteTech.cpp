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
    cout<<"code"<<endl;
    in>>V.codeV;
    char rep;
    cout<<"remplir le tableau tests"<<endl;
    do{Test *T=new Test();
        in>>*T;
        V.tests.push_back(T);
        cout<<"ajouter un test "<<endl;
        cin >> rep;
      } while(rep=='o' || rep == 'O');

}
void VisiteTech::modifierVisite(CentreVT C,string code)
{
    int i=0;
    bool trouver=false;
    cout<<"entrez le code de la visite a modifier "<<endl;
    cin>>this->codeV;
    while(i<C.visites.size())
    {
        if(this->codeV==C.visites[i]->codeV)
        {
            cin>>*C.visites[i];
            trouver=true;
            break;
        }
        i+=1;
    }
    if(trouver=false)
        cout<<"visite non trouve !"<<endl;

}
VisiteTech::~VisiteTech()
{
    //dtor
}
