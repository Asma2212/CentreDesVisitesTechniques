#ifndef VISITETECH_H
#define VISITETECH_H
#include<string>
#include <vector>
#include <iostream>
#include <fstream>
#include"Test.h"
using namespace std;

class VisiteTech
{
    string codeV;
    vector <Test*> tests;
    public:
        VisiteTech();
        friend ostream& operator<<(ostream& out, VisiteTech& V);
        friend istream& operator>>(istream& in, VisiteTech& V);
        void modifierVisite(string);
        virtual ~VisiteTech();

};

#endif // VISITETECH_H
