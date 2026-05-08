# BU-EC327-PA2

*C++ code for solving problems relating to Functions, Header Files, File I/O, Arrays, Random Numbers, and Recursion. Developed as part of EC327: Introduction to Software Engineering at Boston University.*

## Q1: Functions, Header Files, File I/O
A C++ program that interactively accepts commands from the user via console. Each command is a single character followed by either one, two, or three parameters and specifies a function that needs to be performed.

A global program constant is established in this program to limit the maximum calculations performed inside any function recursively. This default value is set at 10.

**extern const int ENTRIES = 10**

The following table lists all the commands in this program:
| Command | Description |
| :--- | :--- |
| F or f | Compute the factorial value |
| B or b | Compute the fibonacci |
| R or r | Compute the square roots |
| U or u | Compute the area of square values |
| C or c | Compute the area of circle values |
| E or e | Compute even numbers |
| K or k | Compute lucky numbers |
| S or s | Computer sin values |
| N or n | Compute cosine values |
| X or x | Compute exponentials |
| L or l | Compute natural logs |
| Y or y | Compute NyanCat value |
| D or d | Compute odd numbers |
| I or i | Read from input file |
| O or o | Write to output file |
| Q or q | Quit program |

## Q2: File I/O, Arrays, Random Numbers, and Functions
Program that when given a input file (default: numbers.txt) in the same folder as the code files, reads that file, calculates the size of an array, calls the DoubleAndReverse function, prints that array, and calculates the median and largest values.

## Q3: Array of Pointers and Dynamic Memory Allocation
Program that requests the size of an original array and then allows for user input of array values. The program should then print out the original array, ReverseMultiply array, ReverseAdd array, and addresses of the zero element in each array. See below for array details.

*ReverseMultiply - doubles the size of an integer array and fills the second half with a copy of the first half in reverse order and adds a final additional location for the product of all numbers.*

*ReverseAdd - creates an array with the original values and adds new entries that are the sum of sets of number in the array starrting from the original "end" moving forward.*
