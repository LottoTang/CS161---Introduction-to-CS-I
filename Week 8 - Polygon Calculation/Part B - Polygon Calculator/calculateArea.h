#ifndef CALCULATEAREA_H_INCLUDED
#define CALCULATEAREA_H_INCLUDED

float getNumber();

void circle (float radius, float &area, float &circumference);

void rectangle (float length, float width, float &area, float &perimeter);

void square (float length, float &area, float &perimeter);

void triangle (float length, float height, float &area);

void displayInstructions();

bool calculateAgain();

#endif // CALCULATEAREA_H_INCLUDED
