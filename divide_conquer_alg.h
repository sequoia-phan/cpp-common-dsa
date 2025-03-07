#ifndef DIVIDE_CONQUER_ALG
#define DIVIDE_CONQUER_ALG

#include <iostream>
using namespace std;

// Create a recursive function for Tower of Hanoi
void towerOfHanoi(int n, char s_rod, char d_rod, char a_rod)
{
    // if there's only one disk
    if (n == 1)
    {
        // Print the move for the single disk
        cout << "Move disk 1 from rod " << s_rod << " to rod " << d_rod << endl;
        return;
    }
    towerOfHanoi(n - 1, s_rod, a_rod, d_rod);
    // Print the move for the nth disk from the source rod
    // to the destination rod
    cout << "Move disk " << n << " from rod " << s_rod
         << " to rod " << d_rod << endl;

    // Call the towerOfHanoi function to move n-1 disks from
    // the auxiliary rod to the destination rod using the
    // source rod
    towerOfHanoi(n - 1, a_rod, d_rod, s_rod);
}

#endif