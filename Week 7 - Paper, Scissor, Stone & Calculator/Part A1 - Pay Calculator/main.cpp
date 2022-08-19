#include <iostream>
//L00690656
//Lab6A_Q1

using namespace std;

/*
 * double get_pay_rate()
 *  get the pay rate of the user
 *  double payRate under data validation (check for value type and > 0)
 *  return payRate
*/

double get_pay_rate()
{
    double payRate;
    bool valid;
    const int BIG_NUM = INT_MAX;
    const char END_LINE = '\n';

    do
    {
        //preset as valid input
        valid = true;
        cin >> payRate;

        //check if it is a value type input and > 0
        if (cin.fail() || payRate <= 0.0)
        {
            if (cin.fail())
                cout << "Please enter a positive number: ";
            else
                cout << "Please enter a positive value greater than 0: ";

            //flush cin input buffer
            cin.clear();
            cin.ignore(BIG_NUM, END_LINE);

            //invalid input spotted
            valid = false;
        }
    } while (!valid);

    return payRate;
}

/*
 * double get_hours_worked()
 *  get the working hours of the user
 *  double workHours under data validation (check for value type and > 0)
 *  return workHours
*/

double get_hours_worked()
{
    double workHours;
    bool valid;
    const int BIG_NUM = INT_MAX;
    const char END_LINE = '\n';

    do
    {
        valid = true;
        cin >> workHours;

        if (cin.fail() || workHours <= 0.0)
        {
            if (cin.fail())
                cout << "Please enter a positive number: ";
            else
                cout << "Please enter a positive value greater than 0: ";

            cin.clear();
            cin.ignore(BIG_NUM, END_LINE);
            valid = false;
        }
    } while (!valid);

    return workHours;
}

/*
 * double calculate_gross_pay(double workHours, double payRate)
 *  calculate the gross pay of the user, if OT is spotted (workHours > 40, extra pay (1.5x of the payRate will be added))
 *  parameters (double workHours, double payRate)
 *  return grossPay
*/

double calculate_gross_pay (double workHours, double payRate)
{
    double grossPay;
    //constant for OT extra rate (x1.5) and normal working time (40 hours)
    const double extraRate = 1.5;
    const double normalTime = 40;

    if (workHours <= 40)

        grossPay = payRate * workHours;

    else

        grossPay = payRate * normalTime + payRate*(workHours - normalTime)*extraRate;

    return grossPay;
}

int main()
{

    //program instructions
    cout << "This program will calculate the gross pay!" << endl;
    cout << endl;

    cout << "Please enter the total working hours: ";
    //store the return workHours from function to the variable within main() : double workHours
    double workHours = get_hours_worked();
    cout << endl;

    cout << "Please enter the hourly pay rate: $";
    //store the return workHours from function to the variable within main() : double payRate
    double payRate = get_pay_rate();
    cout << endl;

    //store the return grossPay from function to the variable within main() : double grossPay
    double grossPay = calculate_gross_pay(workHours, payRate);
    cout << "Your gross pay is: $" << grossPay << "!" << endl;

    return 0;
}
