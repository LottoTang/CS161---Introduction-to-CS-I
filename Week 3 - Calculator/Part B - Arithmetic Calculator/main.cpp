#include <iostream>
//ID: L00690656
//Week 3_Lab3B_Q1

int main()
{
    //variable declaration
    int num1, num2;
    char operators;

    //program instructions and ask for user input
    std::cout << "Enter two integers:" <<std::endl;
    std::cin >> num1 >> num2;
    std::cout << "Enter an operator from the list * / % + - " << std::endl;
    std::cin >> operators;

    //switch case to check the input of operators, and display specific output
    switch (operators)
    {
    case '*':
        std::cout << num1 << " * " << num2 << " = " << num1 * num2;
        break;

    case '/':
        if (num2 == 0) //check if num2 is 0
            std::cout << "You cannot divide by zero." << std::endl;
        else
            std::cout << num1 << " / " << num2 << " = " << num1 / num2;
        break;

    case '%':
        if (num2 == 0)
            std::cout << "You cannot divide by zero." << std::endl;
        else
            std::cout << num1 << " % " << num2 << " = " << num1 % num2;
        break;

    case '+':
        std::cout << num1 << " + " << num2 << " = " << num1 + num2;
        break;

    case '-':
        std::cout << num1 << " - " << num2 << " = " << num1 - num2;

    default: //output this statement if user entered operators out of the list.
        std::cout << "This is not a valid operator." << std::endl;
        break;
    }

    return 0;
}
