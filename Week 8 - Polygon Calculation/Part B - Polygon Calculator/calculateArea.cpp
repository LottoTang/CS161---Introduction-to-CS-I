#include <iostream>
#include "calculateArea.h"

using namespace std;

const int BIG_NUM = INT_MAX;
const char END_LINE = '\n';

float getNumber()
{
    bool valid;
    float number;

    //check number is int type
    do
    {
        valid = true;
        cin >> number;

        //detect if it is not int type
        if (cin.fail())
        {
            cout << "Please enter an integer: ";
            //invalid input spotted and valid = false
            valid = false;
        }
        //flush cin input buffer
        cin.clear();
        cin.ignore(BIG_NUM, END_LINE);

    } while (!valid);

    cout << endl;

    return number;
}

void circle (float radius, float &area, float &circumference)
{
    float const PI = 3.14159;

    area = PI * radius * radius;
    circumference = 2.0 * PI * radius;

}

void rectangle (float length, float width, float &area, float &perimeter)
{

    area = length * width;
    perimeter = 2.0 * (length + width);

}

void square (float length, float &area, float &perimeter)
{

    area = length * length;
    perimeter = 4.0 * length;

}

void triangle (float length, float height, float &area)
{

    area = length * height / 2.0;

}

void displayInstructions()
{
    cout << "This program will calculate the area, perimeter or circumference of the polygon!" << endl;
    cout << endl;
    cout << "C: Circle (area & circumference)" << endl;
    cout << "R: Rectangle (area & perimeter)" << endl;
    cout << "S: Square (area & perimeter)" << endl;
    cout << "T: Triangle (area & perimeter)" << endl;
    cout << "E: End Program" << endl;
    cout << "-------------------" << endl;
    cout << "Please type ONE of the above characters [C,R,S,T,E]: ";
}

bool calculateAgain()
{
    char choice;
    bool valid, nextCal;
    const char YES = 'y';
    const char NO = 'n';

    cout << "Do you want to calculate other polygon? [y/n]: ";

    do
    {
        cin >> choice;
        //convert the choice into lowercase for checking
        choice = tolower(choice);
        valid = true;
        //check if choice is not either YES or NO
        if (choice != YES && choice != NO)
        {
            cout << "Please enter [y/n]: ";
            //invalid input spotted
            valid = false;
        }
        //clear input buffer
        cin.clear();
        cin.ignore(BIG_NUM, END_LINE);

    } while (!valid);

    cout << endl;

    //assignment of nextGame
    if (choice == YES)
        nextCal = true;
    else
        nextCal = false;

    return nextCal;
}

