#include <iostream>
//ID: L00690656
//Week4_Lab4B_Q1

int main()
{
    //variable declaration
    int num, count, preference;

    //program instructions
    std::cout << "This program will display the factors of a positive integer!" << std::endl;

    //outermost do-while loop: check if user wants to continue or quit the program (0:quit; 1:continue)
    do
    {
        //inner do-while loop: validate user input: num is > 0.
        do
        {
            std::cout << "Please enter a positive integer: ";
            std::cin >> num;
        } while (num == 0 || num < 0);

        //variable initialization: important when user opts to continue the program, such that the variable will be initialized again to prevent unwanted previous data
        count = 1;

        std::cout << "The factors of " << num << " are ";

        //while loop to repeat the process from 1 to num of times
        while (count <= num)
        {
            //check if num%count == 0, which implies cout is the factor of num
            if (num % count == 0)

                //if count is the factor of num, display count as the factor of num
                if (count == num)

                    std::cout << count << "." ;

                else

                    std::cout << count << ", ";

            count++;
        }

        //print an empty line
        std::cout << std::endl;

        //ask if the user wants to continue
        std::cout << "Do you want to calculate the other numbers? (0 for exit, 1 for continue): ";
        std::cin >> preference;

        //check if user's input is a valid input or not
        while (preference !=0 && preference!=1)
        {
            std::cout << "Invalid input! Please enter again (0 for exit, 1 for continue): ";
            std::cin >> preference;
        }

    } while (preference!= 0);

    std::cout << "See you next time!" << std::endl;


    return 0;
}
