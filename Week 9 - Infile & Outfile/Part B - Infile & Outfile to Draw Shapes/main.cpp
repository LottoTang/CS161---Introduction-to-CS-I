#include <iostream>
#include <fstream>
#include <sstream>
#include "W9_Lab9B_Q1.h"

using namespace std;

int main()
{
    char choice, symbol;
    int parameter1;
    string textLine;
    stringstream lineBuffer;

    fstream reader ("infile.txt", ios::in);
    fstream writer ("outfile.txt", ios::out);


    //check if both reader and writer can open successfully
    if (!reader.good() && !writer.good())

        cout << "Failed to open" << endl;

    else
    {

        do
        {

            getline(reader, textLine);

            lineBuffer.clear();
            lineBuffer.str(textLine);

            lineBuffer >> choice;
            lineBuffer >> symbol;
            lineBuffer >> parameter1;

            switch (choice)
            {

                case 'D':
                    {
                        cout << makeDiamond(symbol, parameter1);
                        writeShape(writer, makeDiamond(symbol, parameter1));
                        cout << endl;
                        break;
                    }

                 case 'R':
                    {
                        int parameter2;
                        lineBuffer >> parameter2;
                        cout << makeRectangle(symbol, parameter1, parameter2);
                        writeShape(writer, makeRectangle(symbol, parameter1, parameter2));
                        cout << endl;
                        break;
                    }

                case 'S':
                    {
                        cout << makeSquare(symbol, parameter1);
                        writeShape(writer, makeSquare(symbol, parameter1));
                        cout << endl;
                        break;
                    }

                case 'T':
                    {
                        cout << makeTriangle(symbol, parameter1);
                        writeShape(writer, makeTriangle(symbol, parameter1));
                        cout << endl;
                        break;
                    }

                case 'E':
                    {
                        break;
                    }

                default:

                    {
                        cout << "Invalid code! Please ensure the code should within [D,R,S,T,E]!";
                        break;
                    }

            }

        } while (!reader.eof() || choice != 'E');

    }

    reader.close();
    writer.close();

    return 0;
}
