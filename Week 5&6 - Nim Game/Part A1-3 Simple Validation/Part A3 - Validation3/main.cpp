#include <iostream>
#include <limits>
#include <cctype>
//ID:L00690656
//Lab5A Q3

//global variable declaration for cin.ignore function
const unsigned long BIG_NUM = std::numeric_limits<std::streamsize>::max();
const char END_LINE = '\n';

int main()
{
    //variable declaration
    int number;
    bool valid;
    //constant for valid range (1-100)
    const int MIN = 1;
    const int MAX = 100;

    //program instructions
    std::cout << "Please enter an integer between [1 - 100]: ";

    //do-while loop to check if valid is false, user have to enter a valid number again until valid = true
    do
    {
        //ask for user input
        std::cin >> number;
        valid = true;

        //check if input is valid (out of int type or out of range)
        if (std::cin.fail() || number < MIN || number > MAX)
        {
            //if not int type, prompt an error message to enter an integer
            if (std::cin.fail())

                std::cout << "Invalid input, please enter an integer [1 - 100]: ";

            else

                //if out of range, prompt an error message to enter within range
                std::cout << "Invalid input, please enter within the range [1 - 100]: ";

            //within in if statement, valid = false to indicate invalid entry is spotted
            valid = false;

            //clear the error flag and flush the input buffer
            std::cin.clear();
            std::cin.ignore(BIG_NUM, END_LINE);
        }

    } while (!valid);

    //output the valid input
    std::cout << "The final number you have entered is: " << number << std::endl;

    return 0;
}
