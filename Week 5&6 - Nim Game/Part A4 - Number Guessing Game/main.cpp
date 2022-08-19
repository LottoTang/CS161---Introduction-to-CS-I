#include <iostream>
#include <limits>
#include <stdlib.h>
#include <time.h>
//ID:L00690656
//Lab5A Q4

//global variable declaration for cin.ignore function
const unsigned long BIG_NUM = std::numeric_limits<std::streamsize>::max();
const char END_LINE = '\n';


int main()
{
    //variable declaration
    int player = 1;
    int number, gen_num, num_lower, num_upper;
    bool valid = true, playing = true;
    //constant for game range (1-100)
    const int MAX = 100;
    const int MIN = 1;
    unsigned int seed = static_cast <unsigned int>(time(nullptr));

    //program instructions
    std::cout << "The program will generate a number [1 - 100]." << std::endl;
    std::cout << "2 players will take turn to guess the number." << std::endl;
    std::cout << "The first person to guess it wins!" << std::endl;
    std::cout << "----------------------------------------------" <<std::endl;
    std::cout << END_LINE;

    //random number generator
    srand(seed);
    gen_num = rand() % (MAX-MIN) + MIN;

    //for dynamic game range; initialize with the MIN and MAX and change according to user input
    num_lower = MIN;
    num_upper = MAX;

    //once either users guest the number successfully, the flag will turn false to exit the loop
    do

    {
        std::cout << "Now is Player " << player << "'s turn: ";

        do

        {
            //ask for player 1/2 input and set valid = true to indicate a valid input, invalid input as false
            std::cin >> number;
            valid = true;

            //check if the input is in valid type or range
            if (std::cin.fail() || number < num_lower || number > num_upper)
            {
                //if invalid type then prompt an error message
                if (std::cin.fail())
                    std::cout << "Please enter an positive integer [" << num_lower << " - " << num_upper << "]: ";

                else

                    //if not within range then prompt the other error message
                    std::cout << "The input should within the range [" << num_lower << " - " << num_upper << "]: ";

                //clear the error flag and flush the input buffer for next input
                std::cin.clear();
                std::cin.ignore(BIG_NUM, END_LINE);
                //set valid = false to indicate user entered an invalid input for the do-while loop
                valid = false;
            }

        } while (!valid);

        //once input is valid, check if input = generated number
        if (number == gen_num)

        {
            std::cout << "Congratulations! Player " << player << " wins! The number is: " << gen_num << std::endl;
            //either users win the game, playing will set as false, the outermost do-while loop will terminate
            playing = false;
        }

        else

        {
            //if user's input <= generated number, set the effective range from (num_lower + 1 - num_upper)
            if (number <= gen_num)

            {
                num_lower = number + 1;
                std::cout << "It's too low! The effective range is now from: [" << num_lower << " - " << num_upper << "]" << std::endl;
                std::cout << END_LINE;
            }

            else

            {
                //if user's input <= generated number, set the effective range from (num_lower - num_upper - 1)
                num_upper = number - 1;
                std::cout << "It's too high! The effective range is now from: [" << num_lower << " - " << num_upper << "]" << std::endl;
                std::cout << END_LINE;
            }

        }

        //switch turn
        if (player == 1)

            player = 2;

        else

            player = 1;

    } while (playing);

    return 0;
}
