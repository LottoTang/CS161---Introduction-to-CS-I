#include <iostream>
//Lab7 Q1 Swap
//ID: L00690656

using namespace std;

/*
 * void swapAB (int &num1, int &num2)
 *   swap the number passed from main() and return the swapped value to main()
 *   int &num1, int &num2: pass by reference to change the value from main() directly
*/

void swapAB (int &num1, int &num2)
{
    int temp;
    temp = num1;
    num1 = num2;
    num2 = temp;
}

/*
 * int get_int ()
 *   get an integer input (number) from user, validation to reject char type input
 *   return number
*/

int get_int ()
{
    bool valid;
    int number;

    const int BIG_NUM = INT_MAX;
    const char END_LINE = '\n';

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

int main()
{
    int num1, num2;

    //program instructions
    cout << "This program will swap the 2 values you have entered!" << endl;
    cout << endl;

    cout << "Please enter the 1st number: ";
    num1 = get_int();

    cout << "Please enter the 2nd number: ";
    num2 = get_int();

    //output before swap
    cout << "Before swap, 1st number: " << num1 << ", 2nd number: " << num2 << "!" << endl;
    cout << endl;

    swapAB(num1, num2);
    //output after swap
    cout << "After swap, 1st number: " << num1 << ", 2nd number: " << num2 << "!" << endl;

    return 0;
}
