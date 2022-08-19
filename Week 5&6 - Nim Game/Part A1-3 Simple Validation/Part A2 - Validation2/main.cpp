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
    char answer;
    bool valid;
    const char YES = 'y';
    const char NO = 'n';

    //program instructions
    std::cout << "Do you want to play again? ('y' or 'n'): ";

    //do-while loop to check if input is valid
    do
    {
        //ask for user enter a char
        std::cin >> answer;

        //tolower function to ensure answer is in lowercase, 'Y/N' will be considered as valid input
        answer = std::tolower(answer);

        //true for valid input, false for invalid input
        valid = true;

        //check if input = 'y' or 'n'
        if (answer != YES && answer != NO)
        {
            std::cout << "Invalid input! Enter again! ('y' or 'n'): ";

            //invalid input as false
            valid = false;
        }

        //clear input buffer
        std::cin.ignore(BIG_NUM, END_LINE);

    } while (!valid);

    //output the answer, check whether is 'y' or 'n' to display the output correspondingly
    if (answer == YES)

        std::cout << "You have entered: " << answer << ".  Try harder this time!" << std::endl;

    else

        std:: cout << "You have entered: " << answer << ".  See you next time!" << std::endl;

    return 0;
}
