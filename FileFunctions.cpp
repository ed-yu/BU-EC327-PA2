#include <iostream>
using namespace std;
#include <fstream>
#include <ctime>
#include <cstdlib>

void WriteRandomData(int N, int M, const char *filename)
{

    ofstream outFile(filename);
    if (!outFile.is_open()) { //write data check, if file is open, proceed, if not, throw exception
    cerr << "Error: Could not open the file." << endl;
    }
    else
    {
        srand(static_cast<unsigned int>(std::time(nullptr))); //randomized with seed and time
        
        for(int x = 0; x<N; x++)
        {
            int random = (rand() % M); //generates a value between 0 and M

            outFile << "" << random << endl; //write the generated random integer onto the outFile
        }
        outFile.close(); //close to prevent memory leak
    }
}
void ReadData(const char *filename, int &size, int myArray[])
{
    ifstream inputFile(filename);

    int counter = 0;
    int *pointer = &size; // or size = counter directly without pointer
    string reader = "";
    //read data check, if file is open, proceed, if not, throw exception
    if (!inputFile.is_open()) {
    cerr << "Error: Could not open the file." << endl;
    }
    else
    {
        while (getline(inputFile, reader)) 
        {
            myArray[counter] = stoi(reader);
            counter++;
        }

        *pointer = counter;
    }
}