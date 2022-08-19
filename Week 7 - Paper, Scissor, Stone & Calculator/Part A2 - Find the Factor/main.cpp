#include <iostream>
#include <iomanip>
//ID:L00690656
//Lab6A Q2

using namespace std;

/*
 * int get_int(int min, int max)
 *  validate the number (check if it is a int type and within the range from parameters)
 *  int min, int max - copied from main() for the range of data validation
 *  return number
*/

int get_int (int min, int max)
{
    bool valid;
    int number, temp;

    const int BIG_NUM = INT_MAX;
    const char END_LINE = '\n';

    //swap min and max if necessary
    if (min > max)
    {
        temp = min;
        min = max;
        max = temp;
    }

    //instructions
    cout << "Enter an integer for showing the factors of it: ";

    //check number is int type and within the range set from the parameters
    do
    {
        valid = true;
        cin >> number;

        if (cin.fail() || number < min || number > max)
        {
            if (cin.fail())
                cout << "Please enter a positive integer [" << min << " - " << max << "]: ";
            else
                cout << "Please enter within the range [" << min << " - " << max << "]: ";

            //flush cin input buffer
            cin.clear();
            cin.ignore(BIG_NUM, END_LINE);
            valid = false;
        }

    } while (!valid);

    cout << endl;

    return number;
}

/*
 * void display_factors(int number)
 *  display the factors of the number
 *  int number - copied from number in the main() after the int get_int(int min, int max) function
 *  display all the factors
*/

void display_factors(int number)
{
    cout << "The factors of " << number << " are: ";
    //check from i to number to see whether number % i {the remaining} is even, indicating i is the factor of number
    for (int i = 1; i <= number; i++)
    {
        if (number % i == 0)
            cout << i << setw(4);
    }
    cout << endl;
    cout << endl;
}

/*
 * char get_do_again()
 *  ask for the input of either [y/n] and pass the char choice to main() for checking if repeating the program is needed
 *  tolower() to ensure capital letters are also accepted
 *  return choice
*/

char get_do_again()
{
    char choice;
    bool valid;
    const char YES = 'y';
    const char NO = 'n';
    const int BIG_NUM = INT_MAX;
    const char END_LINE = '\n';

    cout << "Do you want to check the factor again? [y/n]: ";

    do
    {
        cin >> choice;
        choice = tolower(choice);
        valid = true;
        //check if choice is not either YES or NO
        if (choice != YES && choice != NO)
        {
            cout << "Please enter [y/n]: ";
            cin.clear();
            cin.ignore(BIG_NUM, END_LINE);
            valid = false;
        }
    } while (!valid);

    cout << endl;

    return choice;
}

int main()
{
    int number;
    const char YES = 'y';
    const int MIN = 1;
    const int MAX = 100;

    //program instructions
    cout << "The program will display the factor of a integer within [1 - 100]!" << endl;
    cout << endl;

    //do-while loop to see the char value passed by get_do_again() is YES or NO, if yes then continue the program and vice versa
    do
    {
        //call functions
        number = get_int(MIN, MAX);
        display_factors(number);

    } while (get_do_again() == YES);

    return 0;
}
