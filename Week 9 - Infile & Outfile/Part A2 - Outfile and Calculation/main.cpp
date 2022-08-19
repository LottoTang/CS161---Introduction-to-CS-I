#include <iostream>
#include <fstream>
//ID: L00690656
//Lab9A_Q2

using namespace std;

/*
 *  bool readLine (fstream &reader, int &total, int &counter)
 *  read the 1st number of each line, if it is not 0, then add the remaining numbers to sum and display the sum of each line
 *  fstream &reader: pass by reference as it would change the file; int &total and int &counter: pass back the overall total and number of lines read to main()
 */

bool readLine (fstream &reader, int &total, int &counter)
{
    //variable declaration
    int value;
    int sum = 0;
    int number;

    //read the 1st number and store in variable number
    reader >> number;

    // if the 1st number of each line != 0, then there are some numbers to be read
    if (number != 0)
    {
        //to count how many lines read from the file and pass back to main()
        counter++;

        //program instruction and output to console
        cout << "For the " << counter << " line, there are " << number << " values to read and to be summed up!" << endl;

        //to read the 2nd number to the end of the line, add the total of the numbers and output each numbers to console
        for (int i = 0; i < number; i++)
        {
            reader >> value;
            sum += value;
            cout << value << " ";
        }

        //output the sum of each line
        cout << " = " << sum << endl << endl;

        //add all the sum of each line and pass back to main() for displaying the total sum
        total += sum;

        //indicating read line successfully (number!=0)
        return true;

    }

    else

        //indicating (number == 0)
        return false;
}

int main()
{
    //reading file using fstream
    //variable reader: read the file "w9_lab9a_q2.txt"
    fstream reader ("w9_lab9a_q2.txt", ios::in);

    //check if both reader and writer can open successfully
    if (!reader.good())
        cout << "Failed to open" << endl;
    else
    {
        bool valid;
        int total = 0;
        int counter = 0;

        do
        {
            //function call
            valid = readLine(reader, total, counter);

        //continue the do-while loop until valid = false (the case for number == 0)
        } while (valid);

        //output the total sum of the file
        if (counter > 1)

            cout << "The total sum of the " << counter << " lines are: " << total << endl;

         else

            cout << "The total sum of the " << counter << " line is: " << total << endl;

        //close the reader
        reader.close();
    }

    return 0;
}
