#include <iostream>
//ID: L00690656
//Week4_Lab4A_Q2

int main()
{
    //variable declaration
    int num;

    //program instruction
    std::cout << "The Program will count down the number you have entered to 1!" << std::endl;

    //ask for user input a value > 0, such that countdown of the value can be executed down to 1.
    do
    {
        std::cout << "Please enter a number (Positive Integers exclude 0): ";
        std::cin >> num;
    } while (num <= 0);

    //output the countdown of the value down to 1.
    for (int i = num; i > 0; i--)
    {
        std::cout << i << std::endl;
    }

    return 0;
}
