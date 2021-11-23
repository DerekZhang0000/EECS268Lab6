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
#include <stdexcept>
void run(int input);
int outbreak(int input);

int main(int argc, char** argv)
{   //takes input from command line
    int input = 0;
    std::cout << "OUTBREAK!\nWhat day do you want a sick count for?: ";
    std::cin >> input;
    try
    {
        run(input);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
void run(int input)
{
    if (input < 1)
    {
        throw(std::runtime_error("Invalid entry."));
    }
    std::cout << "Total people with the flu: " << outbreak(input) << "\n";
}
int outbreak(int input)
{
    if (input == 1)
    {
        return 1;
    }
    else if (input == 2)
    {
        return 8;
    }
    else if (input == 3)
    {
        return 22;
    }
    else
    {
        return (outbreak(input - 3) + outbreak(input - 2) + outbreak(input - 1));
    }
}