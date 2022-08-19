#include <iostream>
#include <limits>
//ID:L00690656
//Lab5A Q1

//global variable declaration for cin.ignore function
const unsigned long BIG_NUM = std::numeric_limits<std::streamsize>::max();
const char END_LINE = '\n';

int main()
{
    //variable declaration
    int number;
    bool valid;
    //constant for game range (1-10)
    const int MIN = 0;
    const int MAX = 10;

    //program instructions
    std::cout << "Please enter an integer between 0 and 10: ";

    //do-while loop to check if valid is false, user have to enter a valid number again until valid = true
    do
    {

        //ask for user input
        std::cin >> number;

        valid = true;

        //check if user entered not a int type value or out of range value
        if (std::cin.fail() || number < MIN || number > MAX)
        {
            //if not a int type, prompt an error message to enter an integer
            if (std::cin.fail())

                std::cout << "Please enter an integer! Enter again: ";

            else

                //if not within range, prompt an error message to enter an integer
                std::cout << "Please enter within the range (0-10): ";

            //clear error flag and input buffer for next input
            std::cin.clear();

            std::cin.ignore(BIG_NUM, END_LINE);

            //to indicate user have entered a invalid value
            valid = false;

        }

    } while (!valid);

    //output value
    std::cout << "Great! You have entered: " << number << " !" << std::endl;

    return 0;
}
