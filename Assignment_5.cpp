// Assignment_5.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cassert>

using namespace std;


//This is the beginning of the functions declared
//This first one explains how to operate the program and the cost/size of a board
//To be honest I did not download the example. I based this off the picture of your running program on canvas
//I am not 100% sure this is what you meant by show the user how this program works
void show_usage()
{
    cout << "This is a program to purchase surfbaords" << endl;
    cout << "You can use upper or lowercase entries when making a selection" << endl;
    cout << "An inproper selection will bring you back to the main menu" << endl;
    cout << "Small boards are 2 meters in size, medium boards are 3 meters in size, and large boards are 4 meters in size" << endl;
    cout << "The cost of a small board is $175.00. The cost of a medium board is $190.00. The cost of a large board is $200.00" << endl;
    cout << "We now offer a squirrel size board for just $25" << endl;
    cout << '\n';
}


//This function passes in a count for sizes and increments variables in the scope of the main function
//I had a bit of trouble with passing in a variable. I believe the & lets the varibale be ended inside the function
//and those edits effect the varibale in the local main function
void make_purchase(int& total_small, int& total_med, int& total_large, int& total_squirrel)
{
    int quantity;
    char board_type;

    cout << "Please enter the quantity and type (s=small, m=medium, l=large, x=squirrel)" << endl;
    cin >> quantity;
    cin >> board_type;
    cout << endl;

    board_type = tolower(board_type);

    //As you can see I still am not entirely comfortable with switch statements. If branches just come naturally to me
    if (board_type == 's')
        total_small = total_small + quantity;

    else if (board_type == 'm')
        total_med = total_med + quantity;

    else if (board_type == 'l')
        total_large = total_large + quantity;

    else if (board_type == 'x')
        total_squirrel = total_squirrel + quantity;

    else
        cout << "Invlaid entry, returning to main menu" << endl;
}


//This function passes in a total number of boards and outputs what is in the users shopping cart
void display_purchase(const int total_small, const int total_med, const int total_large, const int total_squirrel)
{
    //All of these are if statements to make sure each one is checked since they are independant of each other
    //I think maybe a switch could have done this since it will keep checking each branch of it??
    //I did it this way because i knew it would work
    if (total_small > 0)
        cout << "The total number of small surfboards is " << total_small << endl;

    if (total_med > 0)
        cout << "The total number of meduim surfboards is " << total_med << endl;

    if (total_large > 0)
        cout << "The total number of large surfboards is " << total_large << endl;

    if (total_squirrel > 0)
        cout << "The total number of squirrel surfboards is " << total_squirrel << endl;

    if (total_large + total_med + total_small + total_squirrel == 0)
        cout << "No purchases made yet" << endl;
}


//This function passes in a total number of boards in the shopping cart and outputs a cost
void display_total(const int total_small, const int total_med, const int total_large, const int total_squirrel)
{
    //I have been reading the feedback. Doubles since this is money
    const double sm_price = 175.00;
    const double md_price = 190.00;
    const double lg_price = 200.00;
    const double sq_price = 25.00;

    if (total_small > 0)
        cout << "The total number of small surfboards is " << total_small << " at a total price of $" << total_small * sm_price << endl;

    if (total_med > 0)
        cout << "The total number of medium surfboards is " << total_med << " at a total price of $" << total_med * md_price << endl;

    if (total_large > 0)
        cout << "The total number of large surfboards is " << total_large << " at a total price of $" << total_large * lg_price << endl;

    if (total_squirrel > 0)
        cout << "The total number of squirrel surfboards is " << total_squirrel << " at a total price of $" << total_squirrel * sq_price << endl;

    //This got so much uglier when the squirrel size was added. It was kinda bad without but this.... ew. but it works!
    if ((total_large > 0 && total_med > 0) or (total_large > 0 && total_small > 0) or (total_small > 0 and total_med > 0) or (total_squirrel > 0 and total_small > 0) or (total_squirrel > 0 and total_med > 0) or (total_squirrel > 0 and total_large > 0))
        cout << "Amount due: $" << (total_med * md_price) + (total_small * sm_price) + (total_large * lg_price) + (total_squirrel * sq_price) << endl;

    if (total_large + total_med + total_small + total_squirrel == 0)
        cout << "No purchases made yet" << endl;
}




int main()
{
    cout << setw(80) << setfill('*') << '*' << endl;
    cout << setw(7) << setfill('*') << '*' << "Welcome to Johnny Utah's PointBreak Surf Shop" << setw(7) << setfill('*') << '*' << endl;
    cout << setw(80) << setfill('*') << '*' << endl;

    //not sure where to intialize these. once you remove these comments its basically right above the loop where they start
    //my other thought was right before the first function that they get passed into
    int total_small = 0;
    int total_med = 0;
    int total_large = 0;
    int total_squirrel = 0;


    //After makig this I realized this was one of the times a do while loop would have worked well
    //I need the menu to run at least once and then continue to loop until the user quits
    //This works just fine, I also could have made this menu a function and had the loop call it at the start. Hindsight is 20/20
    
    //I had an issue entering my loop that seemed to be resolved by making input a random input that is not q
    char user_input = 1;

    while (user_input != 'q')
    {
        cout << '\n';
        cout << "To show program usage \'s\' " << endl;
        cout << "To purchase a surfboard \'p\' " << endl;
        cout << "To display current purchase \'c\' " << endl;
        cout << "To display total amount due \'t\' " << endl;
        cout << "To quit the program \'q\' " << endl;

        cout << "Please enter selection: ";
        cin >> user_input;
        cout << endl;
        user_input = tolower(user_input);

        //I started with this because it was the easiest
        if (user_input == 'q')
            break;

        else if (user_input == 's')
            show_usage();

        else if (user_input == 'p')
            make_purchase(total_small, total_med, total_large, total_squirrel);

        else if (user_input == 'c')
            display_purchase(total_small, total_med, total_large, total_squirrel);

        else if (user_input == 't')
            display_total(total_small, total_med, total_large, total_squirrel);

        else
            cout << "Invalid entry, please try again" << endl;
    }


    cout << "Thank you" << endl;

    system("pause");
    return 0;
}


