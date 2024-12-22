#include <iostream>
#include <vector>
#include <math.h>

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

unsigned int extractBits(unsigned int num, unsigned int pos, unsigned int k)
{
    unsigned int shifted = num >> pos;
    unsigned int mask = (1 << k) - 1;

    return shifted & mask;
}

int main()
{

    unsigned int num = 214;
    unsigned int pos = 2;
    unsigned int k = 3;
    unsigned int result = extractBits(num, pos, k);

    printf("Extracted bits: %d\n", result);
    return 0;
}

