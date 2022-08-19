#include <iostream>
#include "CALCULATEAREA.H"

using namespace std;

//global constant for clearing input buffer
const int BIG_NUM = INT_MAX;
const char END_LINE = '\n';

//main function
int main()
{
    float area, length, width, radius, height, perimeter, circumference;
    char choice;
    bool valid, calAgain;

    /*  do-while loop: determine continue the whole program or not
     *  calAgain = true (as default)
     *  if choice != 'e' && 'E' --> call function calculateAgain() to ask continue [y/n, if [n], calAgain = false
     *  continue the program while (choice != 'e' && choice != 'E' && calAgain == true)
     */
    do
    {
        //clear screen
        system("cls");

        //variable initialization
        float area = 0; length = 0; width = 0; radius = 0; height = 0; perimeter = 0; circumference = 0;
        calAgain = false;

        //function call from calculateArea.h
        displayInstructions();

        /*  do-while loop: switch function to ask the input from [C,R,S,T,E] or in lowercase
         *  perform different calculation based on the input
         *  if enter out of [C,R,S,T,E] or in lowercase, error message will be prompted and valid = false, user has to input a new choice until valid input is found
         */

        do
        {
            //ask for choice
            cin >> choice;

            //clear input buffer to prevent the case of "ca", which the program will go to case 'c' but error message will be prompted in getNumber()
            cin.ignore(BIG_NUM, END_LINE);

            valid = true;

            //switch case to choose the process respectively based on choice
            switch (choice)
            {
                case 'c':
                case 'C':
                         {
                            system("cls");
                            cout << "Please enter the radius of the circle: ";
                            //function call from "calculateArea.h"
                            radius = getNumber();
                            circle(radius, area, circumference);

                            //result output
                            cout << "The area of the circle: " << area << "." << endl;
                            cout << "The circumference of the circle: " << circumference << "." << endl;
                            cout << endl;
                            break;
                         }
                case 'r':
                case 'R':
                         {
                             system("cls");
                             cout << "Please enter the length of the rectangle: ";

                             //function call from "calculateArea.h"
                             length = getNumber();
                             cout << "Please enter the width of the rectangle: ";
                             width = getNumber();

                             //result output
                             rectangle(length, width, area, perimeter);
                             cout << "The area of the rectangle: " << area << "." << endl;
                             cout << "The perimeter of the rectangle: " << perimeter << "." << endl;
                             cout << endl;
                             break;
                         }
                case 's':
                case 'S':
                         {
                             system("cls");
                             cout << "Please enter the length of the square: ";

                             //function call from "calculateArea.h"
                             length = getNumber();
                             square(length, area, perimeter);

                             //result output
                             cout << "The area of the square: " << area << "." << endl;
                             cout << "The perimeter of the square: " << perimeter << "." << endl;
                             cout << endl;
                             break;
                         }
                case 't':
                case 'T':
                         {
                             system("cls");
                             cout << "Please enter the length of the triangle: ";

                             //function call from "calculateArea.h"
                             length = getNumber();
                             cout << "Please enter the height of the triangle: ";
                             height = getNumber();
                             triangle(length, height, area);

                             //result output
                             cout << "The area of the triangle: " << area << "." << endl;
                             cout << endl;
                             break;
                         }

                case 'e': //case to exit the program
                case 'E':
                         {
                             system("cls");
                             break;
                         }

                default:
                         {
                             //case for input out of the above valid input
                             cout << "Invalid input! Please enter [C,R,S,T,E]: ";

                             //invalid input spotted
                             valid = false;
                             break;
                         }

            }

        // continue the whole switch function if invalid input is spotted
        } while (!valid);

        //function call calculateAgain() if choice != 'e' && 'E', [y]: calAgain = true, [n]: calAgain = false
        if (choice != 'e' && choice != 'E')

            calAgain = calculateAgain();

    // continue the program when choice != 'e' && 'E' && calAgain == true
    } while (choice != 'e' && choice != 'E' && calAgain == true);

    //output bye message
    if (calAgain == false)

        cout << "See you next time! Bye!" << endl;

    return 0;
}
