#include <iostream>
#include "functions.h"
#include "structs.h"

//Originally written May 2015

//Declare the standard string namespace
using std::string;

//Get coordinates of initial circle from user
float inputCoordinates(string inputType)
{
   std::cout << "Enter the coordinate for the " << inputType << " point of the circle: ";
   float userInput;
   std::cin >> userInput;
   return userInput;
}

//Return the radius of the circle
float getRadius(float pointA, float pointB)
{
    float x(0), y(0);
    x = pointB - pointA;
    y = x / 2;
    return y;
}

//Divides the face into sections
float getSectionSize(float top, float bottom)
{
    float height = bottom - top;
    return (height / 8);
}

//Returns the Y coordinate for a section
float getLine(float sectionSize, int multiplier, float topY)
{
    float distance = (sectionSize * multiplier);
    return (distance + topY);
}

//Outputs the section data
void printResults(Face myFace)
{
    using std::cout;


    cout << "\nThe Y coordinate for the hairline is: " << myFace.hairLine << "\n";
    cout << "The X coordinate for the midpoint is: " << myFace.midpoint << "\n";
    cout << "The Y coordinate for the midpoint (browline) is: " << myFace.browLine << "\n";
    cout << "The Y coordinate for the eyeline is: " << myFace.eyeLine << "\n";
    cout << "The Y coordinate for the noseline is: " << myFace.noseLine << "\n";
    cout << "The Y coordinate for the chinline is: " << myFace.chinLine << "\n\n";
}

//Returns optimal eye width
float getEyeWidth(float shavedLeft, float shavedRight)
{
    return ((shavedRight - shavedLeft) / 5);
}

//Returns the coordinates for the width of the eye
XCoPoints getEyePoints(float shavedLeft, float eyeWidth)
{
    eyePoints.point1 = shavedLeft + eyeWidth;
    eyePoints.point2 = shavedLeft + (eyeWidth * 2);
    eyePoints.point3 = shavedLeft + (eyeWidth * 3);
    eyePoints.point4 = shavedLeft + (eyeWidth * 4);
    return eyePoints;
}

//Outputs the coordinates for the width of the eye
void printEyePoints(float shavedLeft, float shavedRight, XCoPoints eyePoints)
{
    std::cout << "\nThe X coordinate for the shaved left side is: " << shavedLeft << "\n";
    std::cout << "The X coordinate for the shaved right side is: " << shavedRight << "\n";
    std::cout << "\nThe X coordinate for Eye point 1 is: " << eyePoints.point1 << "\n";
    std::cout << "The X coordinate for Eye point 2 (Nose Point 1) is: " << eyePoints.point2 << "\n";
    std::cout << "The X coordinate for Eye point 3 (Nose Point 2) is: " << eyePoints.point3 << "\n";
    std::cout << "The X coordinate for Eye point 4 is: " << eyePoints.point4 << "\n";
}


int main()
{
    //Declare variables
    float leastX(0.0), mostX(0.0), topY(0.0), bottomY(0.0);
    string circleTop, circleBottom, circleLeft, circleRight;

    //Initialize string variables
    circleTop = "topmost";
    circleBottom = "bottommost";
    circleLeft = "leftmost";
    circleRight = "rightmost";

    //Initialize coordinate variables with user input
    leastX = inputCoordinates(circleLeft);
    mostX = inputCoordinates(circleRight);
    topY = inputCoordinates(circleTop);
    bottomY = inputCoordinates(circleBottom);

    //Analyze the input
    float radiusLength = getRadius(leastX, mostX);
    myFace.midpoint = radiusLength + leastX;

    float sectionSize = getSectionSize(topY, bottomY);

    myFace.hairLine = getLine(sectionSize, 1, topY);
    myFace.browLine = getLine(sectionSize, 4, topY);
    myFace.eyeLine = getLine(sectionSize, 5, topY);
    myFace.noseLine = getLine(sectionSize, 7, topY);
    myFace.chinLine = getLine(sectionSize, 10, topY);

    //Output first set of data
    printResults(myFace);

    //Declare variables for second analysis
    float amountToShave(0), shavedLeft(0), shavedRight(0);

    //Get additional user input
    amountToShave = inputCoordinates("amount you want to shave from each\nsidemost");

    //Process the additional user input
    shavedLeft = leastX + amountToShave;
    shavedRight = mostX - amountToShave;

    float eyeWidth = getEyeWidth(shavedLeft, shavedRight);

    eyePoints = getEyePoints(shavedLeft, eyeWidth);

    //Output the analyzed data
    printEyePoints(shavedLeft, shavedRight, eyePoints);

    //Stopping point for user to record data
    std::cout << "\nPress Enter to continue\n";

    std::cin.clear(); // reset any error flags
    std::cin.ignore(32767, '\n'); // ignore any characters in the input buffer until we find an enter character
    std::cin.get(); // get one more char from the user

    return 0;
}
