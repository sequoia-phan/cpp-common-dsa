#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
using namespace std;

/**
 * In C++, arrays and pointers are closely related to each other.
 * The array name is treated as a pointer that stored the memory address of the first element of the array.
 * As we have discussed earlier, In array elements are stored at contiguous memory locations,
 * that’s why we can access all the elements of an array using the array name.
 */
void regular_array(int size)
{
}

/**
 * We generally access and print the array elements using indexing.
 * For example to access the first element we use array_name[0].
 * We have discussed above that the array name is a pointer that stored the address of the first element,
 * and array elements are stored at contiguous locations.
 * Now, we are going to access the elements of an array using the array name only.
 */
void accessing_without_index()
{
    int arr[] = {11, 22, 33, 44};
    cout << "first element: " << *arr << endl;
    cout << "second element: " << *(arr + 1) << endl;
}

/**
 * Example: Illustrating Different Ways to Pass Arrays to a Function
 */
void print_array_sized(int arr[3], int n)
{
    cout << "Array as sized array argument" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

void print_array_unsized(int arr[], int n)
{
    cout << "Array as unsigned array argument: ";
    for (int i = 0; i < n; i++)
    {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

void print_array_pointer(int *ptr, int n)
{
    cout << "Array as pointer argument: ";
    for (int i = 0; i < n; i++)
    {
        cout << ptr[i] << " ";
    }
    cout << endl;
}

void array_as_argument_exec()
{
    int arr[] = {10, 20, 30};

    print_array_sized(arr, 3);
    print_array_unsized(arr, 3);
    print_array_pointer(arr, 3);
}

void two_dimension_arr()
{
    int arr[4][4];

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            arr[i][j] = i + j;
        }
    }

    // Printing the element of 2D array
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void three_dimension_arr()
{
    // declaring 3d array
    int arr[3][3][3];
    // initializing the array
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                arr[i][j][k] = i + j + k;
            }
        }
    }

    // printing the array
    for (int i = 0; i < 3; i++)
    {
        // cout << i << "st layer:" << endl;
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                cout << arr[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}



#endif