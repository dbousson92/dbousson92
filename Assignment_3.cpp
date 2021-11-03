// Assignment_3.cpp : This file contains the 'main' function. Program execution begins and ends there.

//There are some libraries included I am not familiar with
//I had to google how to name a txt file and these were used
#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <fstream>
#include <cassert>
#include <cctype>
using namespace std;

//many more named global constants to remove "Magic numbers"
//I thought we didnt want a lot of global variables. The last assignment had us put the constants outside the main function
//That is why I continued to do so, I understand these could be created as local
const float charge_fragile = 2.00;
const float cheap_usa = 6.00;
const float med_usa = 9.00;
const float exp_usa = 12.00;
const float cheap_can = 8.00;
const float med_can = 12.00;
const float exp_can = 15.00;
const float cheap_aus = 10.00;
const float med_aus = 14.00;
const float exp_aus = 17.00;
const float cheap_jup = 50.00;
const float med_jup = 55.00;
const float exp_jup = 60.00;
const float free_ship = 0.00;
const float parameter_1 = 50.00;
const float parameter_2 = 100.00;
const float parameter_3 = 150.00;

int main()
{
    //This is the result of googling how to name a txt file
    ofstream file;
    file.open("Order.txt");

    //Some inputs to be taken and varibales for calculations
    char fragile;
    float total;
    char destination;
    float cost;

    //Header
    cout << setw(50) << setfill('.') << '.' << endl;
    cout << "ITCS 2531 - Programming assignment for week #3" << endl;
    cout << setw(50) << setfill('.') << '.' <<  endl;

    cout << '\n' << endl;

    //first inputs collected
    string item_name;
    cout << setw(50) << left << setfill('.') << "Please enter the item name (No spaces)";
    cout << ":";
    cin >> item_name;
    
    cout << setw(50) << left << setfill('.') << "Is the item fragile? (y=yes/n=no)";
    cout << ":";
    cin >> fragile;
    fragile = tolower(fragile);


    //This is to create an error message and end the program if not properly input
    //I put the Y or N in a lower case and just set up a dummy variable to equal 1 if correct
    //I spent over an hour trying to figure out how to put it all into one statement but the OR wont work with mutliple things you dont want
    //I dont belive these would be considered magic numbers, in an actual code you would just comment they are ASCII
    if (fragile == 121)
    {
        int entry;
        entry = 1;
    }
    else if (fragile == 110)
    {
        int entry;
        entry = 1;
    }
    else
    {
        cout << "Invalid entry, exiting" << endl;
        system("pause");
        return 0;
    }


    //Remaining inputs collected
    cout << left << setw(50) << setfill('.') << "Please enter the order total";
    cin >> total;

    cout << left << setw(50) << setfill('.') << "Please enter the destination (usa/can/aus/jup)";
    cin >> destination;
    destination = tolower(destination);


    //This is to create an error message and end the program if not properly input
    //This one I made the input lowercase since there are a lot of possible
    //input posibilities between upper and lower case than can be techincally correct
    // I found when I started debugging that only the first letter is being saved.... frustrating
    // I am very glad this is a simple assignment and I can choose a different location not starting with the same letter for github
    // Also if i read the gethub thing first I should have used a switch here
    //again i would comment these numbers corrilate the ASCII to the input
    if (destination == 117)
    {
        int entry;
        entry = 1;
    }
    else if (destination == 99)
    {
            int entry;
            entry = 1;
    }
    else if (destination == 97)
    {
        int entry;
        entry = 1;
    }
    else if (destination == 106)
    {
        int entry;
        entry = 1;
    }
    else
    {
        cout << "Invalid entry, exiting" << endl;
        system("pause");
        return 0;
    }
    cout << "\n" << endl;

    //I have sat here for awhile and I cannot come up with an easier way to avoid this massive nested branch....
    //This should get the proper shipping cost for location
    //Once again ASCII  
    if (destination == 117)
    { 
        if (total <= parameter_1)
            cost = cheap_usa;
        else if (total <= parameter_2)
            cost = med_usa;
        else if (total <= parameter_3)
            cost = exp_usa;
        else if (total > parameter_3)
            cost = free_ship;
    }
    else if (destination == 99)
    {
        if (total <= parameter_1)
            cost = cheap_can;
        else if (total <= parameter_2)
            cost = med_can;
        else if (total <= parameter_3)
            cost = exp_can;
        else if (total > parameter_3)
            cost = free_ship;
    }
    else if (destination == 97)
    {
        if (total <= parameter_1)
            cost = cheap_aus;
        else if (total <= parameter_2)
            cost = med_aus;
        else if (total <= parameter_3)
            cost = exp_aus;
        else if (total > parameter_3)
            cost = free_ship;
    }
    else if (destination == 106)
    {
        if (total <= parameter_1)
            cost = cheap_jup;
        else if (total <= parameter_2)
            cost = med_jup;
        else if (total <= parameter_3)
            cost = exp_jup;
        else if (total > parameter_3)
            cost = free_ship;
    }
    //Small note i was unsure about. according to the table $50.00 doesnt clearly fall into any of these, 
    //so i put it in the first. The table says less than 50 for the first but the next category specifies 50.01-100.00




    //This part was also a little unclear, I am not sure if we are suppose to charge for a fragile object if over $150
    //What I am writing will, to avoid it i would try something like the statement if((cost != free_ship) && (fragile == 121))
    //That is not perfect sytax but it is just to show you i would try to avoid charging all together
    if (fragile == 121)
        cost = cost + charge_fragile;

    
    //Now that calculations and branches are over here is an ugly fix to get the destination to print correct

    string destination_output;

    if (destination == 117)
        destination_output = "USA";
    else if (destination == 99)
        destination_output = "CAN";
    else if (destination == 97)
        destination_output = "AUS";
    else if (destination == 106)
    {
        destination_output = "JUP";
        cout << "Good News everyone, Planet express will take your package" << endl;
    }


    //the output
    cout << setw(40) << setfill('.') << "Your item is" << item_name << endl;
    cout << setw(40) << setfill('.') << "Your shipping cost is" << "$" << cost << endl;
    cout << setw(40) << setfill('.') << "You are shipping to" << destination_output << endl;
    cout << setw(40) << setfill('.') << "Your total cost is " << "$" << (cost + total) << endl;
    cout << "\n" << endl;
    cout << right << setw(40) << setfill('-') << "Thank you!" << endl;


    //this is all the output and writing it to the txt file
    file << "Your item is " << item_name << '\n' << endl;
    file << "Your shipping cost is $" << cost << '\n' << endl;
    file << "You are shipping to " << destination_output << '\n' << endl;
    file << "Your total cost is $" << (cost + total) << '\n' << endl;
    //the file is now closed
    file.close();

    system("pause");
    return 0;
}


//If I am off about this magic number concept please let me know when you grade this. My thought was if it is less lines
//of comments to just use a number than to make it a variable and comment then the number should stay
//only case I came across that was with parameters of shipping cost here