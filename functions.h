#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

void printResults(Face myFace);

float getEyeWidth(float shavedLeft, float shavedRight);

XCoPoints getEyePoints(float shavedLeft, float eyeWidth);

void printEyePoints(float shavedLeft, float shavedRight, XCoPoints eyePoints);

#endif // FUNCTIONS_H_INCLUDED
