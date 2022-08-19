#include <iostream>
#include <iomanip>
//ID: L00690656
//Week 2_Lab1A_Q2

int main()
{
    //variable declaration
    int pounds, inches;
    double bmi;

    //basic program instruction and ask for user input
    std::cout << "The program will calculate your Body Mass Index (BMI)!" <<std::endl;
    std::cout << "Please enter your weight in pounds: ";
    std::cin >> pounds;

    std::cout << "Please enter your height in inches: ";
    std::cin >> inches;

    //BMI calculation
    bmi = (pounds * 703.0) / (inches * inches);

    //display the BMI in 2 decimal value
    std::cout << "Your BMI is: " << std::setprecision(2) << std::fixed << bmi << ". ";

    //if BMI is in certain value, display the health condition of the user
    if (bmi < 18.5)

        std::cout << "You are underweight!";

    else

        if (bmi >= 18.5 && bmi < 25)

        std::cout << "You are in normal weight!";

        else

            if  (bmi >= 25 && bmi < 30)

                std:: cout << "You are overweight!";

            else

                std::cout << "You are obese!";

    return 0;
}
