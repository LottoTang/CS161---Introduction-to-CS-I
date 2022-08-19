#include <iostream>
#include <ctime>
#include <cstdlib>
//ID: L00690656
//Lab7A Q2

using namespace std;

//type Elements including Rock(R), Paper(P), Scissors (S)
enum Elements {R,P,S};

//global constant
const int BIG_NUM = INT_MAX;
const char END_LINE = '\n';

/*
 * void displayInstructions()
 *  display the gaming instructions of the game
*/

void displayInstructions()
{
    cout << "This is a Rock, Paper and Scissors game with Bot!" << endl;
    cout << "Each players will choose either Rock (R), Paper (P) and Scissor (S)." << endl;
    cout << "A player who decides to play R beats S; P beats R; S beats P!" << endl;
    cout << "If both players choose the same element (e.g. R vs R), the game is tied." << endl;
    cout << endl;
    cout << "**  Bot will generate a random choice only! He will not see your choice and pick :)  **" << endl;
    cout << endl;
}

/*
 * enum Elements getMove()
 *  validate the user input ['r','R','p','P','S','s'] and return the corresponding enum Elements value
 *  return enum element1
*/

enum Elements getMove()
{
    char choice;
    bool valid;

    //declaration of enum element1
    Elements element1;

    const char ROCK = 'R';
    const char PAPER = 'P';
    const char SCISSORS = 'S';

    cout << "Please choose Rock (R), Paper (P) and Scissor (S): ";

    //check if user input is valid ['r','R','p','P','S','s']
    do
    {
        cin >> choice;
        //capitalized the input for checking
        choice = toupper(choice);
        valid = true;

        //if input is out of ['R','P' and 'S']
        if (choice != ROCK && choice != PAPER && choice != SCISSORS)
        {
            cout << "Please enter either Rock (R), Paper (P) and Scissor (S): ";
            //clear input buffer
            cin.clear();
            cin.ignore(BIG_NUM, END_LINE);
            //set valid as false to indicate invalid input
            valid = false;
        }

    } while (!valid);

    cout << endl;

    //output user's choice
    cout << "You have chosen: " << choice << endl;

    //assign element1 into corresponding value
    if (choice == ROCK)
        element1 = R;
    else
    {
        if (choice == PAPER)
            element1 = P;
        else
            element1 = S;
    }
    return element1;
}

/*
 * enum Elements getCompMove()
 *  get bot's choice by generating a random number [0 - 2] and switch case to decide the enum element2 value
 *  return enum element2
*/

enum Elements getCompMove()
{
    int bot_choice;

    //declaration of enum element1
    Elements element2;

    const char ROCK = 'R';
    const char PAPER = 'P';
    const char SCISSORS = 'S';

    //random number generator
    unsigned int seed = static_cast<unsigned int>(time(nullptr));
    srand(seed);

    //bot_choice will within [0-2]
    bot_choice = rand()%3;

    //switch case to decide the assignment value of element2 and output bot's choice
    switch (bot_choice)
    {
        case 0:
            element2 = R;
            cout << "Bot has chosen: " << ROCK << endl;
            break;

        case 1:
            element2 = P;
            cout << "Bot has chosen: " << PAPER << endl;
            break;

        case 2:
            element2 = S;
            cout << "Bot has chosen: " << SCISSORS << endl;
            break;
    }
    return element2;
}

/*
 * void getWinner (enum Elements elements1, enum Elements elements2, int& userScore, int& botScore))
 *  modified version 2
 *  compare the 2 parameters passed from the main() arguments to decide who is the winner, as well as counting the number of wins
 *  enum Elements elements1, enum Elements elements2 - copied from the main() with the integer range [0-2]
 * int& userScore, int& botScore - change the arguments from main (userScore and botScore) directly to count the wins
*/

void getWinner (enum Elements elements1, enum Elements elements2, int& userScore, int& botScore)
{

    //the case when user chose R and bot chose S || user chose S bot chose R
    if ((elements1 == 0 && elements2 == 2) || (elements1 == 2 && elements2 == 0))
    {
        //user chose R and bot chose S
        if (elements1 == 0 && elements2 == 2)
        {
           cout << "You win!" << endl;
           userScore++;
        }
        // user chose S bot chose R
        else
        {
            cout << "Bot wins!" << endl;
            botScore++;
        }
    }
    //to exclude the above exception cases, by comparing the elements1 > elements2 to find out the winner
    else
    {
        if (elements1 > elements2)
        {
              cout << "You win!" << endl;
              userScore++;
        }
        else
        {
            //the case for elements2 > elements1
            if (elements1 != elements2)
            {
                cout << "Bot wins!" << endl;
                botScore++;
            }
            //the case for both players chose the same choice
            else
                cout << "Tied game!" << endl;
        }
    }
}

/*
 * bool playAgain()
 *  ask the user to enter either [y/n] with validation, return nextGame is true if 'y' and false if 'n'
 *  return nextGame
*/

bool playAgain()
{
    char choice;
    bool valid, nextGame;
    const char YES = 'y';
    const char NO = 'n';

    cout << endl;

    cout << "Do you want to play again? [y/n]: ";

    do
    {
        cin >> choice;
        //convert the choice into lowercase for checking
        choice = tolower(choice);
        valid = true;
        //check if choice is not either YES or NO
        if (choice != YES && choice != NO)
        {
            cout << "Please enter [y/n]: ";
            //clear input buffer
            cin.clear();
            cin.ignore(BIG_NUM, END_LINE);
            //invalid input spotted
            valid = false;
        }
    } while (!valid);

    cout << endl;

    //assignment of nextGame
    if (choice == YES)
        nextGame = true;
    else
        nextGame = false;

    return nextGame;
}

int main()
{
    //declaration of enum Elements elements1 and elements2
    Elements elements1, elements2;

    int userScore = 0;
    int botScore = 0;

    //call function
    displayInstructions();

    do
    {
        elements1 = getMove();

        cout << endl;

        elements2 = getCompMove();

        cout << endl;

        getWinner(elements1, elements2, userScore, botScore);

        //output number of wins
        cout << "You have " << userScore << " win(s)" << " and Bot has " << botScore << " win(s).";

        cout << endl;

    // playAgain() will return either T/F value, while T the game will play again
    } while (playAgain());

    return 0;
}
