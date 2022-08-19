#include <iostream>
#include <iomanip>
//ID: L00690656
//Week 2 Lab1A Question1

int main()
{
    //declaration of variables; double for holding decimal values if necessary
    double price, total, tipAmount;
    int tip;

    //display instructions of the program
    std::cout << "The program will calculate the total amount you should pay for the meal (meal price & tips)!" << std::endl;

    //ask for user input
    std::cout << "Please enter the price of the meal: $ ";
    std::cin >> price;

    std::cout << "Tip percentage (Enter 10 for 10%): ";
    std::cin >> tip;

    //calculation for the total meal price
    tipAmount = price * (tip / 100.0);
    total = price + tipAmount;

    //output the total price by rounding into 2 decimal places
    std::cout << "The price of the meal is $" << std::setprecision(2) << std::fixed << price << "." << std::endl;
    std::cout << "The amount of tip is $" << tipAmount << "." << std::endl;
    std::cout << "The total amount you should pay is : $" << total << "." << std::endl;

    return 0;
}
