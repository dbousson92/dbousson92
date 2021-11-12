// Assignment_4.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cassert>

using namespace std;

//The argc declares a variables for the number of arguements passed into the program. C++ automatically does one
//As it passes in the name of the program. the argv is a list containting all arguements passed in.

int main(int argc, char* argv[])
{
    cout << setw(50) << setfill('*') << '*' << endl;
    cout << setw(7) << setfill('*') << '*' << " Welcome to my Letter Count Program " << setw(7) << setfill('*') << '*' << endl;
    cout << setw(50) << setfill('*') << '*' << endl;
    cout << "\n";




    //This will probably be pulled out, I kinda forgot about debugging tools so this was 
    //a simple way to print the input and seemed useful to the program user
    //I left it thinking it was good user interface so they can confirm the program ran on what was intended
    if (argc > 1)
    {
        cout << "The file you are trying to analyize is " << argv[1] << endl;
        cout << "\n";
    }

    ifstream fs;
    //This is my attempt to now have the input in the file
    fs.open(argv[1]);


    //here is the statement you used in the lecture video to end if an input is not properly loaded
    if (!fs)
    {
        cout << "Error could not open file" << endl;
        system("pause");
        return -1;
    }


    //variables declared. I like declaring them right before use, in python course we were asked to declare them at the start
    char c;
    int a_count = 0;
    int e_count = 0;
    int i_count = 0;
    int o_count = 0;
    int u_count = 0;
    int x_count = 0;
    int y_count = 0;
    int z_count = 0;

    //This is again borrowed from the video. I am not exactly sure was fs >>c means
    while (!fs.eof() && fs >> c)
    {
        //Here is the updated switch statement we talked about. This seems like a lot more code and complex than the
        //if else tree I have commented out in the bottom of this program
        switch (c)
        {

        case 'a':
        {a_count++;
        break; }

        case 'A':
        {a_count++;
        break; }

        case 'e':
        {e_count++;
        break; }

        case 'E':
        {e_count++;
        break; }

        case 'i':
        {i_count++;
        break; }

        case 'I':
        {i_count++;
        break; }

        case 'O':
        {o_count++;
        break; }

        case 'o':
        {o_count++;
        break; }

        case 'u':
        {u_count++;
        break; }

        case 'U':
        {u_count++;
        break; }

        case 'x':
        {x_count++;
        break; }

        case 'X':
        {x_count++;
        break; }

        case 'y':
        {y_count++;
        break; }

        case 'Y':
        {y_count++;
        break; }

        case 'z':
        {z_count++;
        break; }

        case 'Z':
        {z_count++;
        break; }
        }
    }

    int vowel;
    vowel = a_count + e_count + i_count + u_count + o_count;
    //Final print statements
    cout << "The Number of A's: " << setw(50) << setfill('.') << a_count << endl;
    cout << "The Number of E's: " << setw(50) << setfill('.') << e_count << endl;
    cout << "The Number of I's: " << setw(50) << setfill('.') << i_count << endl;
    cout << "The Number of O's: " << setw(50) << setfill('.') << o_count << endl;
    cout << "The Number of U's: " << setw(50) << setfill('.') << u_count << endl;
    cout << "The Vowel count is: " << setw(50) << setfill('.') << vowel << endl;
    cout << '\n';
    cout << "The Number of X's: " << setw(50) << setfill('.') << x_count << endl;
    cout << "The Number of Y's: " << setw(50) << setfill('.') << y_count << endl;
    cout << "The Number of Z's: " << setw(50) << setfill('.') << z_count << endl;

    fs.close();

    system("pause");
    return 0;
}



//I am sure there is an easier way to do this... I havent even made it this far to test this for logical errors
        //I considered a switch here. The reason I chose this structure was to hopefully speed up computing
        //My thought was if it happens to be an earlier vowel it will exit the if statement and start the loop again
//if (c == 'a' or c == 'A' or c == 'e' or c == 'E' or c == 'i' or c == 'I' or c == 'o' or c == 'O' or c == 'u' or c == 'U')
//{
  //  if (c == 'a' or c == 'A')
    //    a_count++;

    //else if (c == 'e' or c == 'E')
      //  e_count++;

   // else if (c == 'i' or c == 'I')
     //   i_count++;

    //else if (c == 'o' or c == 'O')
      //  o_count++;

   // else if (c == 'u' or c == 'U')
     //   u_count++;


