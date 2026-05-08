#include <iostream>
#include <fstream>
#include "FileFunctions.h"
#include "Statistics.h"
using namespace std;

//declares header
int * DoubleAndReverse (int *, int);

int main()
{
    //initialize
    const char *file = "numbers.txt";

    int *arr = new int[1000];
    int size = 0;

        ReadData(file, size, arr);

        cout << "Writing file: " << file << endl;
        cout << "Reading file: " << file << endl;
        cout << "Array size is: " << size << endl;
        cout << "Doubled and reversed is ";

        int *doubleandrevarr = DoubleAndReverse(arr, size);
        cout << "[";
        for(int x = 0; x<(size*2); x++)
        {
            cout << doubleandrevarr[x];
            if(x != (size*2)-1)
            {
                cout << " ";
            }
        }
        cout << "]" << endl;

        cout << "Median is: " <<  getMedian(size, arr) << endl;
        cout << "Largest is: " << getLargest(size, arr) << endl;

    return 0;
}
//function that returns an int array pointer double the length that displays the sequence of the array values and reverses it
int * DoubleAndReverse (int *list, int size)
{
    int *reverseArr = new int[(2*size)];

    for(int x = 0; x<size; x++)
    {
        reverseArr[x] = list[x];
        reverseArr[x + size] = list[(size-1) - x];
    }

    return reverseArr;
}

