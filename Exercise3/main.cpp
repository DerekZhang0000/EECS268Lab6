/* -----------------------------------------------------------------------------
 *
 * File Name:  main.cpp
 * Author: Derek Zhang 
 * Assignment:   EECS-268/269 Lab 6
 * Description:  This program will use recursion to solve problems.
 * Date: 10/25/2021
 *
 ---------------------------------------------------------------------------- */
//Start your program.

#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
void run(std::string command, int input);
void ith(int input);
void verify(int input);
int fib(int input);

int main(int argc, char** argv)
{   //takes input from command line
    int input = 0;
    if (argc > 2)
    {   //if there is more than 2 arguments
        std::string command = (std::string)argv[1];    //records input from command line
        std::string string = (std::string)argv[2];
        std::stringstream inputString(string);  //converts character pointer to string to integer
        inputString >> input;
        try
        {
            run(command, input);
        }
        catch(std::runtime_error& e)
        {
            std::cout << e.what();
        }
        
    }
    else
    {
        std::cout << "Invalid arguments.\n";
    }
}
void run(std::string command, int input)
{
    if (command == "-i")
    {
        ith(input);
    }
    else if (command == "-v")
    {
        verify(input);
    }
    else
    {   //if unknown command is entered
        throw(std::runtime_error("Invalid command: " + command + "\n"));
    }
}
int fib(int input)
{   //returns Fibonacci sequence
    if (input == 0)
    {
        return 0;
    }
    else if (input == 1)
    {
        return 1;
    }
    else
    {
        return fib(input - 1) + fib(input - 2);
    }
}
void ith(int input)
{   //Fibonacci index method
    if (input < 0)
    {
        throw(std::runtime_error("Invalid index.\n"));
    }
    std::cout << fib(input) << "\n";
}
void verify(int input)
{
    bool ver = false;
    int fibIt = 0;
    for(int x = 0; fibIt <= input; x++)
    {   //while Fibonacci iterator is less than or equal to the input
        fibIt = fib(x);
        if (fibIt == input)
        {   //sets bool to true if sequence contains input
            ver = true;
            break;
        }
    }
    if (ver == true)
    {   
        std::cout << input << " is in the sequence.\n";
    }
    else
    {
        std::cout << input << " is not in the sequence.\n";
    }
}