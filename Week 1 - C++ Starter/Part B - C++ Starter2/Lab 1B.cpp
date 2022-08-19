#include <iostream>

int main()
{
    std::string name; //String as a variable for holding user's name (one word).
    int age;

    std::cout << "What is your name?" <<std::endl; //Ask for name input.
    std::cin >> name;

    std::cout << "What is your age?" <<std::endl; //Ask for age input.
    std::cin >> age;

    std::cout << "Your name is " << name << " and your age is " << age << "." << std::endl; //Output the name and age as user's input.

    return 0;
}
