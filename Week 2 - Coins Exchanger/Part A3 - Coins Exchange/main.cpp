#include <iostream>
#include <iomanip>
//L00690656 Week2 Lab 1A Question 3

int main()
{
    double money;
    int moneyTemp, remaining, quarters, dimes, nickels, pennies;

    std::cout << "The program will show the fewest coins that is equivalent to the value you have entered!" << std::endl;

    do
    {
        std::cout << "Please enter the money (less than 1 dollar): ";
        std::cin >> money;
    }
    while (money >=1); // ensure user input a value < $1.

    moneyTemp = money * 100; //variable moneyTemp to store the <$1 dollar input to become an integer for % operation.

    // quarters, dimes, nickels, pennis calculation
    quarters = moneyTemp / 25;
    remaining = moneyTemp % 25; //variable remaining to store the result of remainder by moneyTemp % 25 {value of quarters*100}.
    dimes = remaining / 10;
    remaining = remaining % 10; //variable remaining will be assigned a new value by (remaining) % value of (dimes, nickels)*10 for ongoing calculation.
    nickels = remaining / 5;
    remaining = remaining % 5;
    pennies = remaining / 1;

    std::cout << "$" << money << " is equivalent to : ";

    // to decide whether the program should display quarters only if quarters > 0.
    if (quarters > 0)
    {
       std::cout << quarters;

       // to decide singular or plural form.

       if (quarters == 1)

        std::cout << " quarter; ";

       else

        std::cout << " quarters; ";
    }

    // to decide whether the program should display dimes only if dimes > 0.

    if (dimes > 0)
    {
       std::cout << dimes;

       // to decide singular or plural form.

       if (dimes == 1)

        std::cout << " dime; ";

       else

        std::cout << " dimes; ";
    }

    // to decide whether the program should display nickels only if nickels > 0.

    if (nickels > 0)
    {
       std::cout << nickels;

       // to decide singular or plural form.

       if (nickels == 1)

        std::cout << " nickel; ";

       else

        std::cout << " nickels; ";
    }

    // to decide whether the program should display pennies only if pennies > 0.
    if (pennies > 0)
    {
       std::cout << pennies;

       // to decide singular or plural form.

       if (pennies == 1)

        std::cout << " penny.";

       else

        std::cout << " pennies.";
    }

    return 0;
}
