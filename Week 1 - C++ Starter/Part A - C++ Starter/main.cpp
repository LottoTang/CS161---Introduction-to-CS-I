#include <iostream>

int main()
{
    int year;
    std::string flavor;

    std::cout << "Hello world!" << std::endl; //Print "Hello World" and for Lab 1 Part 1 requirement.

    std::cout << "Please enter the current year: "; //Ask for user's input for current year and echo with the input.
    std::cin >> year;
    std::cout << "The current year is " << year << "." << std::endl;

    std::cout << "What is your favorite flavor of ice cream?: "; //Ask for user's input for the favorite ice cream flavor and echo with the input.
    std::cin >> flavor;
    std::cout << "Great! " << flavor << " is your favorite ice cream!" <<std::endl;

    return 0;
}
