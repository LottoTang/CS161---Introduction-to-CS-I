#include <iostream>
//ID: L00690656
//Week4_Lab4B_Q2

int main()
{
    //variable declaration
    int min, max, num;
    //constant to set up the range of the program, the range can be easily modified if necessary
    const int LOWER_RANGE = 0;
    const int UPPER_RANGE = 100;

    //program instructions
    std::cout << "The program will show the smallest and largest numbers you have entered!" << std::endl;

    //ask for user's input
    std::cout << "Enter a positive integer (1 - 100): ";
    std::cin >> num;
    std::cout << std::endl;

    //data validation: restrict entry from 1 - 100
    //num <=0 to ensure that there is at least 1 positive integer entered for comparison
    while (num <= LOWER_RANGE || num > UPPER_RANGE)
    {
        std::cout << "Invalid input! Enter again (1 - 100): ";
        std::cin >> num;
        std::cout << std::endl;
    }

    //variable initialization
    //considering the case that user may enter only 1 input, thus both max and min = num for output
    max = num;
    min = num;

    //if the entered a valid input (1-100) then execute the following block of codes
    while (num > LOWER_RANGE && num <= UPPER_RANGE)

    {
        //comparison of user input with min and max value
        //if only 1 input and user terminate the program, max && min = num; otherwise, 2 or more input will allow comparison of data
        if (num > max)
            max = num;
        else
            if (num < min)
                min = num;

        //ask for user input a positive integer again or 0 to display the result
        std::cout << "Enter other positive integer (1 - 100) or 0 to display the result: ";
        std::cin >> num;
        std::cout << std::endl;

        //data validation to ensure the input is within 0-100
        while (num < LOWER_RANGE || num > UPPER_RANGE)
        {
            std::cout << "Invalid input! Enter again (1 - 100) or 0 to display the result: ";
            std::cin >> num;
            std::cout << std::endl;
        }
    }

    //result output
    std::cout << "Max is: " << max << std::endl;
    std::cout << "Min is: " << min << std::endl;

    return 0;
}
