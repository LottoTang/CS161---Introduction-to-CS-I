#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
//L00690656
//Week 2 Lab1B_Q1

int main()
{
    //seed random number generator to generate unique number

    unsigned int seed = static_cast<unsigned int>(time(nullptr));
    srand(seed);

    //variable declaration for holding 2 random numbers
    int num1, num2, sum, ans;

    num1 = rand() % 19 + 1; //generate number from 1 - 19
    num2 = rand() % 19 + 1;
    sum = num1 + num2; //calculate for the sum of num1 and num2

    std::cout << "What is the sum of " << num1 << " and " << num2 << "?" <<std::endl;
    std::cin >> ans;
    std::cout << "\n"; //print an empty line as requested in question

    std::cout << std::setw(3)<< std::setiosflags(std::ios::right)<< num1 << std::endl; //there are 3 columns, and set the output in the right side
    std::cout << std::setw(1)<< "+" << std::setw(2) << num2 << std::endl;
    std::cout << "---" << std::endl;
    std::cout << std::setw(3) << sum << std::endl; //the output will keep in right side due to line 24

    return 0;
}
