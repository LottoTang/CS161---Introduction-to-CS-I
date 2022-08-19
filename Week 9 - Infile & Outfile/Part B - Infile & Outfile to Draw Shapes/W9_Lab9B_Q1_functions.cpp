#include <iostream>
#include <fstream>
#include <sstream>
#include "W9_Lab9B_Q1.h"

using namespace std;

string makeRectangle(char symbol, int length, int width)
{

    stringstream outBuffer;

    for (int i = 1; i <= width; i++)
    {
        for (int j = 1; j <= length; j++)
        {
            outBuffer << symbol;
        }
        outBuffer << endl;
    }

    return outBuffer.str();
}

string makeSquare(char symbol, int side)
{

    stringstream outBuffer;

    for (int i = 1; i <= side; i++)
    {
        for (int j = 1; j <= side; j++)
        {
            outBuffer << symbol;
        }
        outBuffer << endl;
    }

    return outBuffer.str();
}

string makeTriangle(char symbol, int height)
{

    stringstream outBuffer;

    for (int i = 1; i <= height; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            outBuffer << symbol;
        }
        outBuffer << endl;
    }

    return outBuffer.str();
}

string makeDiamond(char symbol, int width)
{

    stringstream outBuffer;

    for (int i = 1; i < (width + 1)/2; i++)
    {
        for (int j = 1; j < (width + 1)/2 - i; j++)

            outBuffer << " ";

        for (int j = 1; j <= 2* i - 1; j++)

            outBuffer << symbol;

        outBuffer << endl;
    }

    for (int i = (width - 1)/2 ; i > 1; i--)
    {
        for (int j = 1; j <= (width + 1)/2 - i; j++)

            outBuffer << " ";

        for (int j = 1; j <= 2 * (i - 1) - 1; j++)

            outBuffer << symbol;

        outBuffer << endl;
    }

    return outBuffer.str();
}

void writeShape (fstream &writer, string outString)
{
    writer << outString;

    writer << endl;
}


