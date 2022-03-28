/*
exercise 2-4. For your birthday you’ve been given a long tape measure and an
instrument that measures angles (the angle between the horizontal and a line to the top
of a tree, for instance). If you know the distance, d, you are from a tree, and the height,
h, of your eye when peering into your angle-measuring device, you can calculate the
height of the tree with the formula h + d*tan(angle). Create a program to read h in
inches, d in feet and inches, and angle in degrees from the keyboard, and output the
height of the tree in feet.
*/

#include <iostream>
#include <cmath>

int main (int argc, char *argv[]) {
    const double INCHES_PER_FEET = 12;
    const double PI = 3.141592653589793238;
    const double PI_DEGREES = 180;


    double distance_feet; // distance you are from the tree in feet
    double distance_inches; // distance you are from the tree in inches on top of feet
    double eye_level_height; // inches your eye level is from the ground
    double angle; // degrees from the keyboard

    std::cout << "Enter your height in inches as an integer: ";
    std::cin >> eye_level_height;

    std::cout << "Enter your distance to the tree in feet and inches both as integers: ";
    std::cin >> distance_feet;
    std::cin >> distance_inches;

    std::cout << "Enter the angle from the horizontal that you're looking at the top of the tree: ";
    std::cin >> angle;

    // Make necessary conversions
    double distance = distance_feet * INCHES_PER_FEET + distance_inches;
    // convert from degrees to radians
    angle *= PI / PI_DEGREES;

    double tree_height = eye_level_height + distance*std::tan(angle);


    std::cout << "The height of the tree is: " << tree_height << " inches" << std::endl;

    return 0;

}
