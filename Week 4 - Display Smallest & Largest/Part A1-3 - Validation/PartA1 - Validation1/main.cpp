#include <iostream>
//ID: L00690656
//Lab4A Question1

int main()
{
    //variable declaration
    std::string name;
    int favoriteNum, count;

    //initialization of count
    count = 1;

    //program instructions
    std::cout << "What is your name? ";
    std::cin >> name;

    //ask for user input their favorite number
    //do-while loop to ensure there is at least 1 welcoming message (restrict the input in range of positive integers only)
    do
    {
        std::cout << "What is your favorite number? (Positive integer exclude 0) ";
        std::cin >> favoriteNum;
    } while (favoriteNum <= 0);

    //repeat the output of the welcoming message for favoriteNum time(s).
    while (count <= favoriteNum)
    {
        std::cout << "Hello " << name << "!" << std::endl;
        count++;
    }

    return 0;
}
