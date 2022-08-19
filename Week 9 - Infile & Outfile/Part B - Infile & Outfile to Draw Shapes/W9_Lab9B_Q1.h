#ifndef W9_LAB9B_Q1_H_INCLUDED
#define W9_LAB9B_Q1_H_INCLUDED
#include <sstream>
#include <iostream>
#include <fstream>

using namespace std;

string makeRectangle(char symbol, int length, int width);
string makeSquare(char symbol, int side);
string makeTriangle(char symbol, int height);
string makeDiamond(char symbol, int width);
void writeShape (fstream &writer, string outString);


#endif // W9_LAB9B_Q1_H_INCLUDED
