#ifndef STRUCTS_H
#define STRUCTS_H

//Struct containing facial points
struct Face
{
    float midpoint;
    float hairLine;
    float browLine;
    float eyeLine;
    float noseLine;
    float chinLine;

};
//Struct of X coordinates
struct XCoPoints
{
    float point1;
    float point2;
    float point3;
    float point4;
};

//Initialize structs
Face myFace = {0.0, 0.0, 0.0, 0.0, 0.0};
XCoPoints eyePoints = {0.0, 0.0, 0.0, 0.0};

#endif // STRUCTS_H_INCLUDED
