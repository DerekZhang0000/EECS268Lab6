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
void run(std::string input);
bool parseSequence(std::string input, int index, int length, char c, int opened, int closed, int remainder);
int count (std::string input, int index, int current, char p);

int main(int argc, char** argv)
{   //takes input from command line
    if (argc > 1)
    {   //if there is more than 1 argument
        std::string input = "";
        input = argv[1];    //records input from command line
        input.erase(input.begin(),input.begin());   //removes parentheses from sequence
        input.erase(input.end(),input.end());
        try
        {
            run(input);
        }
        catch(std::runtime_error& e)
        {
            std::cout << e.what();
        }
        
    }
}
void run(std::string input)
{
    if (input == "")
    {   //if sequence is empty
        throw(std::runtime_error("No sequence detected.\n"));
    }
    bool parse = true;
    parse = parseSequence(input, 0, input.length() - 1, input.at(0), 0, 0, input.length() % 2);
    if (parse == true)
    {
        std::cout << "Sequence is balanced.\n";
    }
    else if (parse == false)
    {
        std::cout << "Sequence is not balanced.\n";
    }
}
bool parseSequence(std::string input, int index, int length, char c, int opened, int closed, int remainder)
{
    opened = count(input, index, opened, '(');
    closed = count(input, index, closed, ')');
    if (closed > opened)
    {   //if at any point a closed bracket comes after a complete set
        return false;
    }
    else if (input.at(index) != '(' && input.at(index) != ')')
    {   //if non-bracket character is found
        throw(std::runtime_error("Non-parenthetical character in sequence.\n"));
    }
    else if (closed > opened || remainder != 0 || input.at(length) == '(')
    {   //failure conditions
        return false;
    }
    else if (index == length)
    {   //final check
        if (opened == closed)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return parseSequence(input, index + 1, length, input.at(index + 1), opened, closed, remainder); //recursion
    }
}
int count(std::string input, int index, int current, char p)
{   //parentheses counting method
    if (input.at(index) == p)
    {
        current++;
    }
    return current;
}