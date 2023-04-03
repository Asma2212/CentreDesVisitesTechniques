#ifndef TEST_H
#define TEST_H
#include <iostream>
#include <fstream>
#include<string>
#include"VisiteTech.h"

using namespace std;

class Test
{
    bool etatInt;
    bool etatExt;
    public:
        Test();
        friend ostream& operator<<(ostream& out, Test& T);
        virtual ~Test();
};

#endif // TEST_H
