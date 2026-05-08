#include <iostream>

using namespace std;

int *ReverseMultiply (int *, int); //declare functions
int *ReverseAdd(int *, int);

int main()
{
    int entries = 0; //size of array
    int *arr = nullptr; //array created via main()
    int *arrMulti = nullptr; //array for multi function
    int *arrRevAdd = nullptr; //array for reverse add function

    cout << "Enter the number of entries: " << endl;
    cin >> entries;
    arr = new int[entries]; //set array size

    for(int x = 0; x<entries; x++)
    {
    cout << "Entry " << x << " is: "; //config to set original array
    cin >> arr[x];
    }
    cout << "*****" << endl;

    cout << "Original array is: ";
    for(int x = 0; x<entries; x++)
    {
        cout << arr[x] << " "; //config to print out original array
    }

    cout << "and the address of the zero element is: " << &arr[0] << endl; //prints out address of array index 0
    cout << "One array is: ";

    arrMulti = ReverseMultiply(arr, entries); //config to assign arr pointer to reverse multiply function

    for(int x = 0; x< entries*2+1; x++)
    {
        cout << arrMulti[x] << " "; //config to print out arrMulti
    }
    cout << "and the address of zero element is: " << &arrMulti[0] << endl; //prints out address of array index 0

    cout << "Two array is: ";

    arrRevAdd = ReverseAdd(arr, entries); //config to assign arr pointer to reverse add function

    for(int x = 0; x< entries*2-1; x++)
    {
        cout << arrRevAdd[x] << " "; //config to print out arrRevAdd
    }
    cout << "and the address of zero element is: " << &arrRevAdd[0] << endl; //prints out address of array index 0

    return 0;
}

int *ReverseMultiply (int *list, int size)
{
    int *arrRev = new int[2*size+1];
    int sum = 0;

    for(int x = 0; x<size; x++)
    {
        arrRev[x] = list[x];
        arrRev[x+size] = list[(size-1)-x];
        if(x == 0)
        {
            sum = list[0] * list[0]; 
        }
        else
        {
            sum = sum * list[x] * list[x];
        }
        
    }

    arrRev[2*size] = sum;

    return arrRev;
}

int *ReverseAdd(int *list, int size)
{
    int *arrRevA = new int[size*2-1];

    for(int x = 0; x<size; x++)
    {
        arrRevA[x] = list[x];
    }
    for(int x = size*2 - 2; x>=size; x--)//loop add first to end point
    {
        arrRevA[x] = arrRevA[(size*2-2)-(x)] + arrRevA[(size*2-2)-(x)+1];
    }

    return arrRevA;

}