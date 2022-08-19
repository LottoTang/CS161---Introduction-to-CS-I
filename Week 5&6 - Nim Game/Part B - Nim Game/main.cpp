#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
//ID: L00690656
//Lab5B Q1

//global variable declaration for cin.ignore function
const unsigned long BIG_NUM = std::numeric_limits<std::streamsize>::max();
const char END_LINE = '\n';

int main()
{
    //variable declaration
    int choice, stick_row, stick_remaining, stick_takeout, stick_random_pick;
    int round, player;
    int stick_takeout_lower, stick_takeout_upper;
    char answer;

    //constant variable
    const int CHOICE_MIN = 1;
    const int CHOICE_MAX = 3;
    const int STICK_MAX = 11;
    const int STICK_TAKEOUT_MIN = 1;
    const int STICK_TAKEOUT_MAX = 3;
    const char YES = 'y';
    const char NO = 'n';

    //boolean as the flag to check for looping conditions
    bool valid;
    bool playing;

    //random number generator for "Play with Bot" mode
    unsigned int seed = static_cast<unsigned int>(time(nullptr));
    srand(seed);

    //program instructions
    std::cout << "Welcome to Nim!" << std::endl;
    std::cout << END_LINE;
    std::cout << "Players will take turns removing 1,2 or 3 sticks from the initial 11." << std::endl;
    std::cout << "The player removing the last sticks wins!" << std::endl;
    std::cout << END_LINE;
    std::cout <<"Please select a mode: " << std::endl;
    std::cout <<"----------------------" << std::endl;
    std::cout << "1) 2 Players mode " << std::endl;
    std::cout << "2) Play with Bot " << std::endl;
    std::cout << "3) Exit " << std::endl;
    std::cout << END_LINE;
    std::cout << "Your choice is: ";

    //do-while loop: validate choice as int type and within [1-3]
    do
    {
        std::cin >> choice;
        valid = true;

        //check if user entered outside int type or out of range [1-3]
        if (std::cin.fail()|| choice < CHOICE_MIN || choice > CHOICE_MAX)
        {
            //case for not int type entry
            if (std::cin.fail())

                std::cout << "Please enter an integer [1-3]: ";

            else

                //case for out of range [1-3]
                std::cout << "Please enter within [1-3]: ";

            //set valid as false to indicate invalid input
            valid = false;

            //input buffer clear
            std::cin.clear();
            std::cin.ignore(BIG_NUM, END_LINE);
        }

    } while (!valid);

    //switch case as the menu of the program
    switch (choice)
    {
       //2 players mode
       case 1:
        {
           do
           {
               //clear the screen
               system("CLS");
               std::cout << "How many row(s) of sticks do you want?: ";

               //inner do-while loop: ask for user to enter number of row(s) and validate the input
               do
               {
                   std::cin >> stick_row;

                   valid = true;

                   //check if not int type or < 1
                   if(std::cin.fail() || stick_row < 1)
                   {
                    //case for not int type
                    if (std::cin.fail())

                        std::cout << "Please enter a positive integer: ";

                    else
                        //ensure must have at least 1 row for operation
                        std::cout << "Please enter an integer > 0: ";

                    valid = false;

                    std::cin.clear();
                   }

                   std::cin.ignore(BIG_NUM,END_LINE);

               } while (!valid);


               //variable initialization
               stick_remaining = STICK_MAX * stick_row; //count how many sticks left
               stick_takeout_lower = STICK_TAKEOUT_MIN; //fixed at 1 (STICK_TAKEOUT_MIN)
               stick_takeout_upper = STICK_TAKEOUT_MAX; //check how many sticks user can take out (for the case <= 2 sticks left)
               round = 1; //count how many rounds used
               player = 1; //count for players 1&2

               //inner do-while loop: check if the game is still playing, end the loop while !playing
               do
               {
                   std::cout << "Round " << round << " sticks remaining: " << stick_remaining << std::endl;

                   std::cout << END_LINE;

                        for (int i = 1; (i <= stick_remaining); i++)
                        {
                            std::cout << "| ";

                            if (i % STICK_MAX == 0)

                                std::cout << END_LINE;
                        }

                  //for formatting uses
                  std::cout << END_LINE;
                  std::cout << END_LINE;

                  //inner do-while loop: validate the number of sticks to take out (not for int type or out of range)
                  do
                  {

                       std::cout << "Player " << player << "'s turn! How many sticks would you like to remove? [" << stick_takeout_lower << " - " << stick_takeout_upper << "]: ";

                       playing = true;

                       std::cin >> stick_takeout;

                       valid = true;

                       //check for not int type or out of range (possible cases: [1-3] or [1-2] or [1-1]]
                       if(std::cin.fail() || stick_takeout < stick_takeout_lower || stick_takeout > stick_takeout_upper)

                       {
                            //not for int type
                            if (std::cin.fail())

                            {
                                std::cout << "Please enter a positive integer! " << std::endl;

                                std::cout << END_LINE;
                            }

                            else
                            {

                                //out of range
                                std::cout << "Please enter within range [" << stick_takeout_lower << " - " << stick_takeout_upper << "]! " << std::endl;

                                std::cout << END_LINE;
                            }

                            valid = false;

                            std::cin.clear();

                      }

                      std::cin.ignore(BIG_NUM,END_LINE);

                 } while (!valid);

                 std::cout << END_LINE;

                 //count the remaining sticks after the user input
                 stick_remaining = stick_remaining - stick_takeout;

                 //check if all sticks are taken out
                 if (stick_remaining == 0)
                 {
                    std::cout << "Congratulations! Player " << player << " wins!" << std::endl;

                    //playing = false indicates the game has finished
                    playing = false;

                    std::cout << END_LINE;

                    //ask if users want to play again
                    std::cout << "Do you want to play again? [y/n]: ";

                    do
                    {
                        //set initial valid = true
                        valid = true;

                        std::cin >> answer;

                        //convert any possible input to lowercase to match with variable YES NO
                        answer = std::tolower(answer);

                        //validate if input is out of 'y' and 'n'
                        if (answer != YES && answer != NO)
                        {
                            std::cout << "Please enter a character [y/n]: ";

                            valid = false;

                        }

                        std::cin.ignore(BIG_NUM,END_LINE);

                    } while (!valid);
                 }

                 //check if the case the remaining sticks < max number of take out sticks
                 if (stick_remaining < STICK_TAKEOUT_MAX)

                    //update the max take out input as stick_remaining
                    stick_takeout_upper = stick_remaining;

                 //update rounds
                 round++;

                 //switch player
                 if (player == 1)

                    player = 2;

                 else

                    player = 1;

              } while (playing);

              if (answer == NO);

                    std::cout << "See you next time!" << std::endl;

           //echo with line 87 do-while, the game will restart if answer == YES
           } while (answer == YES);

           break;
        }

        //2 players mode; codes are the same as case 1, comments will be made specially for bot features
       case 2:
        {
           do
           {
               system("CLS");
               std::cout << "How many row(s) of sticks do you want?: ";

               do
               {
                   std::cin >> stick_row;

                   valid = true;

                   if(std::cin.fail() || stick_row < 1)
                   {
                    if (std::cin.fail())

                        std::cout << "Please enter a positive integer: ";

                    else
                        std::cout << "Please enter an integer > 0: ";

                    valid = false;

                    std::cin.clear();
                   }

                   std::cin.ignore(BIG_NUM,END_LINE);

               } while (!valid);

               stick_remaining = STICK_MAX * stick_row;
               stick_takeout_lower = STICK_TAKEOUT_MIN;
               stick_takeout_upper = STICK_TAKEOUT_MAX;
               round = 1;
               player = 1;

               do
               {
                   std::cout << "Round " << round << " sticks remaining: " << stick_remaining << std::endl;

                   std::cout << END_LINE;

                        for (int i = 1; (i <= stick_remaining); i++)
                        {
                            std::cout << "| ";

                            if (i % STICK_MAX == 0)

                                std::cout << END_LINE;
                        }

                  std::cout << END_LINE;
                  std::cout << END_LINE;

                  do
                  {

                       //assume player 1 as user, player 2 as bot.  Only user is required to enter the stick_takeout value
                       if (player == 1)
                       {
                           std::cout << "Player " << player << "'s turn! How many sticks would you like to remove? [" << stick_takeout_lower << " - " << stick_takeout_upper << "]: ";

                           playing = true;

                           std::cin >> stick_takeout;

                           valid = true;
                       }

                       else // for bot to choose how many sticks to take out
                       {
                           //restrict the bot to take out [1-3] sticks
                           stick_takeout = rand() % stick_takeout_upper + stick_takeout_lower;

                           std::cout << "Bot's turn! He has chosen: " << stick_takeout << " stick(s)." << std::endl;
                       }

                       //both user and bot will undergo the data validation process
                       if(std::cin.fail() || stick_takeout < stick_takeout_lower || stick_takeout > stick_takeout_upper)

                       {
                            if (std::cin.fail())

                            {
                                std::cout << "Please enter a positive integer! " << std::endl;

                                std::cout << END_LINE;
                            }

                            else
                            {
                                //only user will required to enter the number within range, while bot will auto generate a in-range value within the loop
                                if (player == 1)
                                {
                                    std::cout << "Please enter within range [" << stick_takeout_lower << " - " << stick_takeout_upper << "]! " << std::endl;

                                    std::cout << END_LINE;
                                }

                            }

                            valid = false;

                            std::cin.clear();

                            std::cin.ignore(BIG_NUM,END_LINE);
                      }

                 } while (!valid);

                 std::cout << END_LINE;

                 stick_remaining = stick_remaining - stick_takeout;

                 if (stick_remaining == 0)
                 {
                    //output who is the winner
                    if (player == 1)

                       std::cout << "Congratulations! Player " << player << " wins!" << std::endl;

                    else

                        //else case indicates bot's turn and the bot wins
                        std::cout << "Bot wins!" << std::endl;

                    playing = false;

                    std::cout << END_LINE;

                    std::cout << "Do you want to play again? [y/n]: ";

                    do
                    {
                        valid = true;

                        std::cin >> answer;

                        answer = std::tolower(answer);

                        if (answer != YES && answer != NO)
                        {
                            std::cout << "Please enter a character [y/n]: ";

                            valid = false;
                        }

                        std::cin.ignore(BIG_NUM,END_LINE);

                    } while (!valid);
                 }

                 if (stick_remaining < STICK_TAKEOUT_MAX)

                    stick_takeout_upper = stick_remaining;

                 round++;

                 if (player == 1)

                    player = 2;

                 else

                    player = 1;

              } while (playing);

              if (answer == NO);

                    std::cout << "See you next time!" << std::endl;

           } while (answer == YES);

           break;
        }

       //Exit
       case 3:
        {
            //if user entered '3' as the choice, output "Bye!" and terminate the program
            std::cout << "Bye!" << std::endl;
            break;
        }

    }

    return 0;
}
