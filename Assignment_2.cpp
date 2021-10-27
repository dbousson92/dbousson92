
//I personally like more space between pieces of code. I find it easier to put into chucks that 
//seem to fit together



//pulling string fuction and manipulate functions into the program to allow for easier 
//work on strings and numbers
#include <iostream>
#include <string>
#include <iomanip>
//googled how to always round up a float, this was needed to use the command ceil()
#include <tgmath.h>

using namespace std;


//constants given for calculation. These are made as global variables as requested in the assignment directions
const float container = 2.76;
const float cost = 4.12;
const float profit = 1.45;


int main()
{
    //Header to the program
    //I dont know why but I could not get the fill to produce the * without them being between characters
    cout << "*" << setw(81) << setfill('*') << "*" << endl;
    cout << "*" << setw(8) << setfill('*') << "*" << " This Program Demonstrates use of Manipulators and Calculations " << "*" << setw(8) << setfill('*') << "*" << endl;
    cout << "*" << setw(81) << setfill('*') << "*" << endl;
    
    //blank line between the header and the data entry and calculations
    cout << '\n' << endl;


    //This is declaring the local variables for calculations and the variable where the input will be stored
    //They are floats so decimals can be carried to make calculations more precise
    float input;
    float calc_container;
    float calc_cost;
    float calc_profit;


    //collecting the input
    cout << "Please enter the total number of kilograms of cheese produced: ";
    cin >> input;
    //This seems like a great place to make a small loop and if statement to satisfy the loop insuring a number is entered
    //This is outside my coding skill and the assignment so i will just leave the idea as a comment


    
    //These are all the calculations. I am putting them into one chunk, then I will format and print all outputs
    calc_container = input / container;
    calc_container = ceil(calc_container);
    int output_container = static_cast<int>(calc_container);
    //the amount of containers is rounded up becuase any decimal value would mean you need another container
    //I made a static cast of the variable so I would stop getting decimals in my strings
    calc_cost = calc_container * cost;
    calc_profit = calc_container * profit;


    //This is turning the outline into a string. This makes it easier to put into a line that
    //will have multiple manipulators on it
    string s1 = "The number of containers to hold the cheese is: ";
    string s2 = "The cost of producing " + to_string(output_container) + " container(s) of cheese is: ";
    string s3 = "The profit from producing " + to_string(output_container) + " container(s) of cheese is: ";


    //These are all the output lines to print the calculations done
    cout << setw(48) << left << setfill(' ') << s1 << setw(34) << right << output_container << endl;
    cout << setw(53) << left << setfill(' ') << s2 << setw(23) << right << '$' << setprecision(2) << fixed << calc_cost << endl;
    cout << setw(58) << left << setfill(' ') << s3 << setw(18) << right << '$' << setprecision(2) << fixed << calc_profit << endl;
    //I ran into an issue with the number of characters the containers has. 
    //This is built and lined up when there are 3 digits in the container number, for example 100 containers
    //the spacing is off by the number of digits away from 3. so a single container digit would shift the spacing by 2
    //I think to get it right i need a part of the program to count the digits in the input, then have setw be
    //the total characters in the string plus that counted value for left, setw on the right be the remaining spaces to where
    //I want the line of data minus the counted value




    //This was my original attempt at the outputs
    
    //cout << "The number of containers to hold the cheese is: " << right << calc_container << endl;
    //cout << "The cost of producing " << calc_container << " container(s) of cheese is: ";
    //cout << right << "$" << setprecision(2) << calc_cost << endl;
    //cout << "The profit from producing " << setprecision(0) << calc_container << " container(s) of cheese is: ";
    //cout << right << "$" << setprecision(2) << calc_profit << endl;
   

    //As mentioned in the last program this is to prevent the program from closing as it completes
    //And C++ must return a value, moving forward I wont comment this in
    system("pause");
    return 0;
}

//One final note. When i built the program it gave me the warnings of double to float.. I never had any doubles anywhere
//in the program. I couldnt figure out how to remove that warning. I have no issues with testing or running the program


