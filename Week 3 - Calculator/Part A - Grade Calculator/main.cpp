#include <iostream>
#include <iomanip>
//ID: L00690656
//Lab3A Q3 (Based on Q2 for addition of new features)

int main()
{
    //variable declaration
    int score1, score2, score3;
    double average, percentage;

    //basic program explanation
    std::cout << "The program will calculate the average of the 3 quiz scores!" << std::endl;

    //ask for user 1st input
    std::cout << "Enter the 1st Test Score (out of 50): ";

    //to check whether user has typed the valid value (0-50 marks)
    do
    {
        std::cin >> score1;
        if ((score1 > 50) || (score1 < 0)) //either statement is true will execute the following codes
        {
            std::cout << "Please enter a valid score again!" << std::endl;
            std::cout << "Enter the 1st Test Score (out of 50): "; //ask the user input again
        }
    } while ((score1 > 50) || (score1 <0));

    //ask for 2nd input
    std::cout << "Enter the 2nd Test Score (out of 50): ";
    do
    {
        std::cin >> score2;
        if ((score2 > 50) || (score2 < 0))
        {
            std::cout << "Please enter a valid score again!" << std::endl;
            std::cout << "Enter the 2nd Test Score (out of 50): ";
        }
    } while ((score2 > 50) || (score2 <0));

    //ask for 3rd input
    std::cout << "Enter the 3rd Test Score (out of 50): ";
    do
    {
        std::cin >> score3;
        if ((score3 > 50) || (score3 < 0))
        {
            std::cout << "Please enter a valid score again!" << std::endl;
            std::cout << "Enter the 3rd Test Score (out of 50): ";
        }
    } while ((score3 > 50) || (score3 <0));

    //average and percentage calculation
    average = (score1 + score2 + score3)/3.0;
    percentage = average / 50.0 * 100;

    //output score and percentage
    std::cout << "The average score is: " << std::setprecision(2) << std::fixed << average << std::endl;
    std::cout << "The percentage is: " << percentage << "%" << std::endl;

    //check what grade the student get
    if (percentage >= 90)

        std::cout << "Very Good! You get an A!";

    else

        if ((percentage >= 80) && (percentage <90))

            std::cout << "Good! You get a B!";

        else

            if ((percentage >= 70) && (percentage <80))

                std::cout << "Not Bad! You get a C!";

            else

                std::cout << "Try Harder! You get an F!";

    return 0;
}
