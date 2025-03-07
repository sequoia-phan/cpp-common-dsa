#ifndef M_ALLOC_H
#define M_ALLOC_H

#include <iostream>
using namespace std;

void make_memory_leak()
{
    int *p = new int[10];
    cout << *p << endl;
    delete p;
}

#endif