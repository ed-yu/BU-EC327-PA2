#include <iostream>

using namespace std;

int * sorttheArray(int &size, int myArray[]);

//calls sorttheArray function to get a sorted array and determine the median from the array via the half of the size and determine modulo of 2
double getMedian(int &size, int myArray[])
{
int *arr = sorttheArray(size, myArray);
double median = 0;

    if(size % 2 != 0)
    {
        median = arr[size/2];
    }
    else
    {
        int middle = size/2;
        median = (double) arr[middle] + arr[middle+1];
        median = median/2.0;
    }

    return median;
}
//calls the sorttheArray function to get a sorted array and retrieve the pointer value at the end of the sorted array
int getLargest(int &size, int myArray[])
{
    
    int largest =  sorttheArray(size, myArray)[size-1];
    return largest;

}
//sorts the array via bubble sort and returns a sorted array
int * sorttheArray(int &size, int myArray[])
{
    int *sortArray = new int[size];
    bool notsorted = true;
    int counter = 0;

    for(int x = 0; x<size; x++)
    {
        sortArray[x] = myArray[x];
    }

    while(notsorted) //a custom way of bubble sort
    {
        for(int x = 0; x< size-1; x++)
        {
            counter = 0;
            if(sortArray[x] > sortArray[x+1])
            {
                int temp = sortArray[x+1];
                sortArray[x+1] = sortArray[x];
                sortArray[x] = temp;
                counter++;
            }


        }
        if(counter==0)
        {
            notsorted = false;
        }
    }
    return sortArray;
}