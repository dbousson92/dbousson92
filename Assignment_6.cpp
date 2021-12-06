// Assignment_6.cpp : This file contains the 'main' function. Program execution begins and ends there.


//I left all your comments in and responded to some. Thank you for the help, I had a friend explain my original code was
//trying to write the name of the txt file instead of the things on the file itself. However he could not help me without vectors
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cassert>
using namespace std;

//constants here remove magic numbers in opperations with the arrays
const int Listsize = 10; // Make this uppercase and they will be easier to see in the code
const int Games_Played = 5; // Make this uppercase and they will be easier to see in the code

// Return false if failuer. Otherwise success.
bool GetBowlingData(string fileName, string bowlerNames[], int scores[][Games_Played])
{
    ifstream fs;
    fs.open(fileName);
    if (!fs)
    {
        cout << "Error could not open file" << endl;
        system("pause");
        return false;
    }

    // 2D array means 2 loops...
    // For each row of data....

    //This does look somewhat like what I was trying to do in the for loops. I still don't exactly understand why it didnt work
    for (int row = 0; row < Listsize; row++)// Does this look familiar?? 2D array, 2 loops.
    {
        // Bowler's name..
        //This puts the bowlers name first
        fs >> bowlerNames[row];

        // Bowler's scores..
        //This loops to fill in all their scores
        for (int col = 0; col < Games_Played; col++)// Does this look familiar?? 2D array, 2 loops.
            fs >> scores[row][col];
    }

    return true;
    //Should I include something to close the file here?
    
    /*for (int i = 0; i < listsize; i++)
        name[i] = data[i][0];

    for (int i = 0; i < listsize; i++)
        for (int j = 1; j < games_played + 1; j++)
            score[i][j] = stoi(data[i][j]);


    if (score == 0)
        return -1;
    else
         return 0;*/
}

void GetAverageScore(int scores[][Games_Played], int average[])
{
    //int avg;
    //int i = 0; // Use row as it will be the index.
    for (int row = 0; row < Listsize; row++)// Does this look familiar?? 2D array, 2 loops.
    {
        int total = 0;
        for (int col = 0; col < Games_Played; col++)// Does this look familiar?? 2D array, 2 loops.
            total += scores[row][col];

        // Declare where used. Easier to see and cleaner code that way.
        // int avg = total / games_played; // Don't need this extra variable. Less is more. It will already be complexe enough :(
        average[row] = total / Games_Played;
        //avg = 0; don't need to do this. Set above
        // 
        // This was to reset the variable used to try to fill everything in
        // 
        //i++;
    }

}

void PrettyPrintResults(string name[], int score[][Games_Played], int average[])
{
    //int j = 0; Not needed. Already have row index
    for (int row = 0; row < Listsize; row++) // Does this look familiar?? 2D array, 2 loops.
    {
        cout << "Bowler " << name[row] << " scored";

        // Use meaningful names. e.g row, col. i and j work but only after you have written 1,000,000 lines of code.
        //I like i and j for the unit vectors I associate them with due to the math I have taken.
        //Moving forward I will make this easier to read code with row and col
        for (int col = 0; col < Games_Played; col++)// Does this look familiar?? 2D array, 2 loops.
        // { Don't need { } if only one statement to execute.
            cout << " " << score[row][col];
        //}
        cout << " and averaged a score of " << average[row] << endl;
        //j++;
    }

}

int main(int argc, char* argv[])
{
    //This puts the txt file into an array, from what i read online this is the more complicated method
    //The assignment explictly stated to use loops and this type of coding instead of vectors
    //this is all borrowed from my assignment 4
    //ifstream fs;
    //fs.open(argv[1]);
    //if (!fs)
    //{
    //    cout << "Error could not open file" << endl;
    //    system("pause");
    //    return -1;
    //}


    // string data[listsize][games_played + 1]; ??? Not sure what this is?

    // Always make arrays plural (add an 's' on the end, e.g. score becomes scores)

    // Is the plural to help keep track of multiple Items are stored in it?
    string bowlerNames[Listsize]; // These are objects so they initialize themselves.
    //Does that mean I shouldnt include [Listsize] and it should just be []?
    int scores[Listsize][Games_Played] = { 0 }; // Always initialize these primitive data types
    //Would it automatically fill them as all 0 or hold them as empty?
    int averages[Listsize] = { 0 };// Always initialize these primitive data types


    //int i = 0;
    //for (int row = 0; row < listsize; row++)
    //{

    //    for (int col = 0; col < games_played + 1; col++)
    //    {
    //        data[row][col] = argv[i];
    //        i = i + 1;
    //    }
    //}

  
    //test = GetBowlingData(data, name, score);
    //Argv[1] is the data in this case right? The file gets opened in the function
    int test = GetBowlingData(argv[1], bowlerNames, scores);
    if (test == false) // Use bools
    {
        cout << "Failed to retrieve the data" << endl;
        system("pause");
        return -1;
    }
    if (test == true)
        cout << "Data successfully input" << endl;

    GetAverageScore(scores, averages);

    PrettyPrintResults(bowlerNames, scores, averages);

    system("pause");
    return 0;
}