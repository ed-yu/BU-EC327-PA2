#ifndef PA2FUNCTIONS_H
#define PA2FUNCTIONS_H

#include <string>
#include <iostream>

//functions go here
void initialize();
bool checkCode(char);
void writeDataToFile(const char *);
void writerAssist(const char *, std::string);
void readDataFromFile(const char *);
int factorial(int);
int fibonacci(int);
double findSqrtValue(double);
double naturalLog(double);
double areaCircle(double);
double areaSquare(double);
int findNextOddValue(int);
int findNextEvenValue(int);
double findNyanCatValue(double);
double doMath(double, char);
double lucky(double);
void runtimeFunction();
void readDataHelper(const char *b);

#endif