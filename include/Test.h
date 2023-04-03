#ifndef TEST_H
#define TEST_H
#include <iostream>
#include <fstream>
#include<string>
#include"VisiteTech.h"

using namespace std;

class Test
{
    bool etat;
    public:
        Test();
        friend istream& operator>>(istream& in, Test& T);
        friend ostream& operator<<(ostream& out, Test& T);
        virtual ~Test();
};

#endif // TEST_H
