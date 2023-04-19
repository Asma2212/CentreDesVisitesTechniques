#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <fstream>
#include<string>

using namespace std;

class Test
{
    public:
        Test();
        friend ostream& operator<<(ostream& out, Test& T);
        virtual ~Test();
};

#endif // TEST_H
