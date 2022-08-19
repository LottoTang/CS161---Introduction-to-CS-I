#include <iostream>
#include <fstream>
//ID: L00690656
//Lab9A_Q1


using namespace std;

int main()
{
    //reading and writing files using fstream
    //variable reader: read the file "w9_lab9a_q1.txt"
    //variable writer: write the file "w9_lab9a_q1_output.txt"
    fstream reader ("w9_lab9a_q1.txt", ios::in);
    fstream writer ("w9_lab9a_q1_output.txt", ios::out);

    //check if both reader and writer can open successfully
    if (!reader.good() && !writer.good())
        cout << "Failed to open" << endl;
    else
    {
        //variable declaration
        int value;
        int sum = 0;
        int counter = 0;
        int total = 0;
        int number;

        //do-while loop: read all the elements within the file "w9_lab9a_q1.txt"
        // check if the 1st number of each line is 0 or not, if 0, the do-while loop will terminate
        do
        {
            //read the 1st number and store in variable number
            reader >> number;
            sum = 0;
            // if the 1st number of each line != 0, then there are some numbers to be read
            if (number != 0)
            {
                counter++;
                //program instruction and output to console
                cout << "For the " << counter << " line, there are " << number << " values to read and to be summed up!" << endl;
                //output to the file "w9_lab9a_q1_output.txt"
                writer << "For the " << counter << " line, there are " << number << " values to read and to be summed up!" << endl;
            }
            //to read the 2nd number to the end of the line, add the total of the numbers and output each numbers to console and file
            for (int i = 0; i < number; i++)
            {
                reader >> value;
                sum += value;
                cout << value << " ";
                writer << value << " ";
            }
            // to output the sum of the line to console and file
            if (number != 0)
            {
                cout << " = " << sum << endl << endl;
                writer << " = " << sum << endl << endl;
            }

            //after reading the entire line, total stores the sum for each line and calculate the overall sum of the file
            total += sum;

        } while (number != 0);

        // to output the sum of all numbers to console and file
        if (counter > 1)

            cout << "The total sum of the " << counter << " lines are: " << total << endl;

         else

            cout << "The total sum of the " << counter << " line is: " << total << endl;

        //close the reader and writer
        reader.close();
        writer.close();
    }

    return 0;
}
