#include <iostream>
//ID:L00690656
//Week4_Lab4A_Q3

int main()
{
    //variable declaration
    int num;

    //ask for user input from value 1 to 10
    //do-while as the body will execute at least once
    do
    {
        std::cout << "Please enter a number in between 1-10! : ";
        std::cin >> num;
    }
    while (num < 1 || num > 10); //validation: if the statement is True: num is not within 1-10, and False: num is within 1-10

    //output num that user has entered
    std::cout << "Great! You have entered: " << num << "." << std::endl;

    return 0;
}
