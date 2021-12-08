// Assignment_7.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cassert>
using namespace std;

//constants here remove magic numbers in opperations with the arrays
const int Listsize = 10; 
const int Games_Played = 5; 

//This is to define our data. This will replace the multiple arrays declared at the beggining of the main
struct Bowling
{
    string bowlerNames[Listsize];
    int scores[Listsize][Games_Played] = { 0 };
    int averages[Listsize] = { 0 };
};

// Removed a couple arrays and replaced with the structure
bool GetBowlingData(string fileName, Bowling& player_scores)
{
    ifstream fs;
    fs.open(fileName);
    if (!fs)
    {
        cout << "Error could not open file" << endl;
        system("pause");
        return false;
    }

 
    
    for (int row = 0; row < Listsize; row++)
    {
        //using the dot operator to store in specific locations of the structure
        fs >> player_scores.bowlerNames[row];

        for (int col = 0; col < Games_Played; col++)
            fs >> player_scores.scores[row][col];
    }

    return true;
   
}

//only the structure needs to be passed now. the & lets the program know it is a specific structure to modify
void GetAverageScore(Bowling& player_scores)
{
    //using the dot operator to store in specific locations of the structure
    for (int row = 0; row < Listsize; row++)
    {
        int total = 0;
        for (int col = 0; col < Games_Played; col++)
            total += player_scores.scores[row][col];

        player_scores.averages[row] = total / Games_Played;
        
    }

}

//again only need the structre passed into the function. much cleaner looking code
void PrettyPrintResults(Bowling& player_scores)
{
    for (int row = 0; row < Listsize; row++) 
    {
        cout << "Bowler " << player_scores.bowlerNames[row] << " scored";

        for (int col = 0; col < Games_Played; col++)
            cout << " " << player_scores.scores[row][col];
        
        cout << " and averaged a score of " << player_scores.averages[row] << endl;
        
    }

}

int main(int argc, char* argv[])
{
 //this is the old method commented out
    //string bowlerNames[Listsize];
    //int scores[Listsize][Games_Played] = { 0 };
    //int averages[Listsize] = { 0 };

    //this is the structure being declared, not defined
    Bowling player_scores;

    //file and structure passed into function
    int test = GetBowlingData(argv[1], player_scores);
    if (test == false) 
    {
        cout << "Failed to retrieve the data" << endl;
        system("pause");
        return -1;
    }
    if (test == true)
        cout << "Data successfully input" << endl;

    GetAverageScore(player_scores);

    PrettyPrintResults(player_scores);

    system("pause");
    return 0;
}

//overall this is a much cleaner looking file than what I turned in last week. I had a much easier time modifying the program
//The main function itself is very clean. i wanted to leave the old way in there commented out to show i understand the change