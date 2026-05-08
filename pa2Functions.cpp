#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <istream>

using namespace std;

void readDataHelper(const char *b);
void masterConsole(istream& in, char command, bool& globalrecord, string& fileNameWrite);

extern const int ENTRIES = 10;

void initialize()
{
    cout << "EC327: Introduction to Software Engineering" << endl << "Spring 2026" << endl << "Programming Assignment 2" << endl << "Value of Entries is: " << ENTRIES << endl;

}

string initializePrint() //this function allows for the intiailization of returning a string when called
{
    return ("EC327: Introduction to Software Engineering \n Spring 2026 \n Programming Assignment 2 \n Value of Entries is: " + to_string(ENTRIES));

}

string formatDouble(double value){
    stringstream stream;
    stream << fixed << setprecision(2) << value;
    return stream.str();
}

bool checkCode(char command)
{
    return (command == 'F' || command == 'B' || command == 'R' || command == 'U' || command == 'C' || command == 'E' || command == 'K' || command == 'S' || command == 'N' || command == 'X' || command == 'L' || command == 'Y' || command == 'D' || command == 'I' || command == 'O' || command == 'Q'); //if valid command, true
}

void writeDataToFile(const char *b)//acts as a initialization function to writeToFile
{
    ofstream output;
    output.open(b);

    output.close();

}

void writerAssist(const char *b, string out) //assists in writing data to file, records the output of the commands
{
    ofstream output;
    if (!output.is_open()) //write data check, if file is open, proceed, if not, throw exception
    {
    cerr << "Error: Could not open the file." << endl;
    }
    output.open(b, ios::app);

    //output is written to the file
    output << out << endl;

    output.close();
}


void readDataFromFile(const char *b)
{
    readDataHelper(b);
}


int factorial(int input)
{
    int ans = input;
    int factor = input-1;

    while(factor>0)
    {
        ans = ans * factor;
        factor--;
    }
    return ans;
}

int fibonacci(int input)
{
    int fibSum = 0;
    int fibprev = 0;
    int fibfor = 1;

    for(int x = 0; x<input; x++)
    {
        fibSum = fibprev + fibfor;
        fibprev = fibfor;
        fibfor = fibSum;
    }
    return fibprev;
}

double findSqrtValue(double input)
{
    return sqrt(input);
}

double naturalLog(double input)
{
    return log(input);
}

double areaCircle(double input)
{
    return  (3.14 * input * input);
}

double areaSquare(double input)
{
    return (input * input);
}

int findNextOddValue(int input)
{
    int ans = input;

    if(input % 2 == 0)
    {
        ans++;
    }
    else
    {
        ans+=2;
    }
    return ans;
}

int findNextEvenValue(int input)
{
    int ans = input;

    if(input % 2 == 0)
    {
        ans+=2;
    }
    else
    {
        ans++;
    }
    return ans;
}

double findNyanCatValue(double input)
{
    double myNum = input;
    double nyanCat = pow((4 * myNum), myNum) + myNum + 10;

    return nyanCat;
}

double doMath(double input, char command)
{
    command = (char) toupper(command);
    double ans = 0;

    if(command == 'S')
    {
        ans = sin(input);
    }
    else if(command == 'N')
    {
        ans = cos(input);
    }
    else if (command == 'X')
    {
        ans = exp(input);
    }
    else
    {
        cout << "INVALID/UNKNOWN COMMAND" << endl;
    }

    return ans;
}

double lucky(double input)
{
   unsigned int randomSeed = static_cast<unsigned int>(time(nullptr)) + static_cast<unsigned int>(input);
   srand(randomSeed);

   return (double)rand();
}

void readDataHelper(const char *b)
{
    ifstream inputFile(b);
    string reader = "";
    //read data check, if file is open, proceed, if not, throw exception
    if (!inputFile.is_open()) {
    cerr << "Error: Could not open the file." << endl;
    }
    else
    {
        bool runtime = true; //while loop for function to run
        char command; //command character
        bool globalrecord = false; //"global" variable in main that determines whether the command outputs should be written to a separate file indicated by the user.
        string fileNameWrite = "";

        while (inputFile >> command)
        {
            command = (char)toupper(command); //accounts for both upper and lower case chars and converts characters to uppercase
            if(checkCode(command))
            {
                if(command == 'Q')
                {
                    globalrecord = false; //stops recording of data if "I" was called initially
                    runtime = false; //runtime is set to false, terminates the loop
                    cout << "--Program terminated." << endl;
                }
                else
                {
                    cout << "Please enter command parameters:" << endl;
                    masterConsole(inputFile, command, globalrecord, fileNameWrite);
                }
            }
            else
            {
                cout << "Invalid command code" << endl;
            }
        }
    }
    inputFile.close();
}

void runtimeFunction()
{
    //intializers
    bool runtime = true; //while loop for function to run
    char command; //command character
    bool globalrecord = false; //"global" variable in main that determines whether the command outputs should be written to a separate file indicated by the user.
    string fileNameWrite = "";

    while(runtime)//runtime loop
    {
        cout << "Please enter command code:" << endl;
        cin >> command;
        command = (char)toupper(command); //accounts for both upper and lower case chars and converts characters to uppercase
        if(checkCode(command))
        {
            if(command == 'Q')
            {
                globalrecord = false; //stops recording of data if "I" was called initially
                runtime = false; //runtime is set to false, terminates the loop
                cout << "--Program terminated." << endl;
            }
            else
            {
                cout << "Please enter command parameters:" << endl;
                masterConsole(cin, command, globalrecord, fileNameWrite);
            }
        }
        else
        {
            cout << "Invalid command code" << endl;
        }
    }

}
void masterConsole(istream& in, char command, bool& globalrecord, string& fileNameWrite)
{
    //intializers
    double first; //first number
    double last; //last number
    double delta; //incrementation length
    double current; //current number between first and last
    int enter; //integer obtained via cin
    bool ran; //boolean that checks if the code successfully ran for first, last, and delta. If not then prints no computation is needed.
    //int entryCounter = 0; //entry counter, the amount of times commands are used, cannot exceed maxmimum ENTRIES as defined in pa2Functions.cpp
    const char *fileNameRead = NULL; //constant character pointer that points to a file name
    //const char *fileNameWrite = NULL; //constant character pointer that points to a file name
    string GLOBALANSWER = ""; //"global" tvariable in the main that resulting outputs are tied to.

            //GLOBALANSWER = ""; //resets globaloutput to nothing, ready to record for outputs during runtime
            first = 0; //init
            last = 0;
            delta = 0;
            current = 0;
            ran = false;
            if(command == 'R' || command == 'U' || command == 'C' || command == 'K' || command == 'L' || command == 'Y' || command == 'S' || command == 'N' || command == 'X' )
            { //double_run
                cout << "Please enter the following parameters: first last delta" << endl;
                in >> first >> last >> delta;
                if(delta > 0)
                {
                    for(int x = 0; (first+delta*x)<=last && x<ENTRIES; x++)
                    {
                        ran = true; //actually computed
                        if(command == 'R')
                        {
                            if(x==0)
                            {
                                GLOBALANSWER = "Square root of " + formatDouble(first) + " is: " + formatDouble(findSqrtValue(first));
                                cout << GLOBALANSWER << endl;
                            }
                            else
                            {
                                current = delta*x;
                                GLOBALANSWER = "Square root of " + formatDouble(first + current) + " is: " + formatDouble(findSqrtValue(first + current));
                                cout << GLOBALANSWER << endl;
                            }
                        }
                        else if(command == 'U')
                        {
                            if(x==0)
                            {
                                GLOBALANSWER = "Area square of " + formatDouble(first) + " is: " + formatDouble(areaSquare(first));
                                cout << GLOBALANSWER << endl;
                            }
                            else
                            {
                                current = delta*x;
                                GLOBALANSWER = "Area square of " + formatDouble((first + current)) + " is: " + formatDouble(areaSquare(first + current));
                                cout << GLOBALANSWER << endl;
                            }
                        }
                        else if(command == 'C')
                        {
                            if(x==0)
                            {
                                GLOBALANSWER = "Area circle of " + formatDouble(first) + " is: " + formatDouble(areaCircle(first));
                                cout << GLOBALANSWER << endl;
                            }
                            else
                            {
                                current = delta*x;
                                GLOBALANSWER = "Area circle of " + formatDouble(first + current) + " is: " + formatDouble(areaCircle(first + current));
                                cout << GLOBALANSWER << endl;
                            }
                        }
                        else if(command == 'K')
                        {
                            if(x==0)
                            {
                                GLOBALANSWER = "Lucky number of " + formatDouble(first) + " is: " + formatDouble(lucky(first));
                                cout << GLOBALANSWER << endl;
                            }
                            else
                            {
                                current = delta*x;
                                GLOBALANSWER = "Lucky number of " + formatDouble(first + current) + " is: " + formatDouble(lucky(first + current));
                                cout << GLOBALANSWER << endl;
                            }
                        }
                        else if(command == 'L')
                        {
                            if(x==0)
                            {
                                GLOBALANSWER = "Natural log of " + formatDouble(first) + " is: " + formatDouble(naturalLog(first));
                                cout << GLOBALANSWER << endl;
                            }
                            else
                            {
                                current = delta*x;
                                GLOBALANSWER = "Natural log of " + formatDouble(first + current) + " is: " + formatDouble(naturalLog(first + current));
                                cout << GLOBALANSWER << endl;
                            }
                        }
                        else if(command == 'Y')
                        {
                            if(x==0)
                            {
                                GLOBALANSWER = "Nyan cat of " + formatDouble(first) + " is: " + formatDouble(findNyanCatValue(first));
                                cout << GLOBALANSWER << endl;
                            }
                            else
                            {
                                current = delta*x;
                                GLOBALANSWER = "Nyan cat of " + formatDouble(first + current) + " is: " + formatDouble(findNyanCatValue(first + current));
                                cout << GLOBALANSWER << endl;
                            }
                        }
                        else if(command == 'S')
                        {
                            if(x==0)
                            {
                                GLOBALANSWER = "Sin value of " + formatDouble(first) + " is: " + formatDouble(doMath(first, command));
                                cout << GLOBALANSWER << endl;
                            }
                            else
                            {
                                current = delta*x;
                                GLOBALANSWER = "Sin value of " + formatDouble(first + current) + " is: " + formatDouble(doMath((first + current), command));
                                cout << GLOBALANSWER << endl;
                            }
                        }
                        else if(command == 'N')
                        {
                            if(x==0)
                            {
                                GLOBALANSWER = "Cosine value of " + formatDouble(first) + " is: " + formatDouble(doMath(first, command));
                                cout << GLOBALANSWER << endl;
                            }
                            else
                            {
                                current = delta*x;
                                GLOBALANSWER = "Cosine value of " + formatDouble(first + current) + " is: " + formatDouble(doMath((first + current), command));
                                cout << GLOBALANSWER << endl;
                            }
                        }
                        else if(command == 'X')
                        {
                            if(x==0)
                            {
                                GLOBALANSWER = "Exponential value of " + formatDouble(first) + " is: " + formatDouble(doMath(first, command));
                                cout << GLOBALANSWER << endl;
                            }
                            else
                            {
                                current = delta*x;
                                GLOBALANSWER = "Exponential value of " + formatDouble(first + current) + " is: " + formatDouble(doMath((first + current), command));
                                cout << GLOBALANSWER << endl;
                            }
                        }
                        if(globalrecord) //if recording state in main() is active, then proceed to write outputs to file
                            {
                                writerAssist(fileNameWrite.c_str(), GLOBALANSWER);
                            }
                    }

                    
                }
                if(ran == false)
                {
                    cout << "No computation needed." << endl;
                    if(globalrecord) //if recording state in main() is active, then proceed to write outputs to file
                            {
                                writerAssist(fileNameWrite.c_str(), "No computation needed.");
                            }
                }
            } // double_run
            else if(command == 'F' || command == 'B')
            {
                cout << "Please enter a single integer: " << endl;
                in >> enter;

                if(command == 'F')
                {
                    GLOBALANSWER = "Factorial of " + to_string(enter) + " is: " + to_string(factorial(enter));
                    cout << GLOBALANSWER << endl;
                }
                else
                {
                    GLOBALANSWER = "Fibonacci of " + to_string(enter) + " is: " + to_string(fibonacci(enter));
                    cout << GLOBALANSWER << endl;
                }

                if(globalrecord) //if recording state in main() is active, then proceed to write outputs to file
                        {
                            writerAssist(fileNameWrite.c_str(), GLOBALANSWER);
                        }

            }//int single run
            else if(command == 'E'  || command == 'D')
            {
                cout << "Please enter the following parameters as integers: first last" << endl;
                in >> first >> last;
                GLOBALANSWER = "";
                if(command == 'E')
                {
                    int firstEven = first;
                    int entrycount = 0;
                    if((firstEven % 2) != 0)
                    {
                        firstEven = first + 1;
                        GLOBALANSWER += to_string(firstEven);
                    }
                    else
                    {
                        GLOBALANSWER += to_string(firstEven);
                    }
                    for(int x = firstEven; x<findNextEvenValue(last)-2 && entrycount<ENTRIES; x = findNextEvenValue(x))
                    {
                        GLOBALANSWER += " " + to_string(findNextEvenValue(x));
                        entrycount++;
                    }
                    cout << GLOBALANSWER << endl;
                }
                else
                {
                    int firstOdd = first;
                    int entrycount = 0;
                    if((firstOdd % 2) == 0)
                    {
                        firstOdd = first+1;
                        GLOBALANSWER += to_string(firstOdd);
                    }
                    else
                    {
                        GLOBALANSWER += to_string(firstOdd);
                    }
                    for(int x = firstOdd; x<findNextOddValue(last)-2 && entrycount<ENTRIES; x = findNextOddValue(x))
                    {
                        GLOBALANSWER += " " + to_string(findNextOddValue(x));
                        entrycount++;
                    }
                    cout << GLOBALANSWER << endl;
                }

                if(globalrecord) //if recording state in main() is active, then proceed to write outputs to file
                        {
                            writerAssist(fileNameWrite.c_str(), GLOBALANSWER);
                        }
            }//int first last run
            else if(command == 'I' || command == 'O')
            {
                if(command == 'I')
                {
                    string filenaming = "";
                    cout << "Type in designated file name to read" << endl;
                    in >> filenaming;
                    fileNameRead = filenaming.c_str();
                    readDataFromFile(fileNameRead); //ok now run
                    

                }
                else
                {
                    globalrecord = true; //"recording" mode is active, will now both record in the output the designated document location
                    string filenaming = "";
                    cout << "Type in designated file name to write" << endl;
                    in >> filenaming;
                    fileNameWrite = filenaming.c_str();
                    writeDataToFile(fileNameWrite.c_str()); //ok now run
                }
            }//name run
}