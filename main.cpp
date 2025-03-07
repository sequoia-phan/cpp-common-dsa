#include <iostream>
#include <vector>
#include <math.h>
#include "bit-manip.h"
#include "array.h"
#include "matrix.h"
#include "String.h"
#include "m-alloc.h"
#include "linked-list.h"
#include "Stack.h"
#include "Queue.h"
#include "divide_conquer_alg.h"

using namespace std;

int search(vector<int> &arr, int x)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == x)
        {
            return i;
        }
    }
    return -1;
}

int getSome(const vector<int> &arr1)
{
    int n = arr1.size();
    if (n % 2 == 0)
    {
        return 0;
    }

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr1[i];
    }
    return sum;
}

void iteration(int n)
{
    int c = 3;
    // // quadratic time complexity
    // for (int i = 1; i <= n; i = i + c)
    // {
    //     for (int j = 1; j <= n; j += c)
    //     {
    //         cout << j << endl;
    //     }
    //     // cout << "time: " << i << endl;
    //     printf("time %d\n", i);
    //     // cout << i << endl;
    // }

    // logarithmic time complexcity
    for (int i = 1; i <= n; i *= c)
    {
        printf("log mul: %d\n", i);
    }

    // for (int i = 5; i <= n; i /= c)
    // {
    //     // printf("log mul: %.5f\n", i);
    // }
}

void recursion(int n)
{
    if (n <= 0)
    {
        return;
    }
    else
    {
        printf("%.2f\n", (float)n);
    }
    int c = 2;
    recursion(n / c);
}

void loglogn(int n)
{
    int c = 2;
    for (int i = 2; i <= n; i = pow(i, c))
    {
        printf("%d\n", i);
    }
}

int main()
{
    // Number of disks
    int n = 3;
    towerOfHanoi(n, 'A', 'B', 'C');
    return 0;
}