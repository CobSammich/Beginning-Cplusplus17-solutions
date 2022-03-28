/*
exercise 3-2. Write a program to calculate how many square boxes can be contained
in a single layer on a rectangular shelf, with no overhang. the dimensions of the shelf
in feet and the dimension of a side of the box in inches are read from the keyboard.
use variables of type double for the length and depth of the shelf and type int for the
length of the side of a box. define and initialize an integer constant to convert from feet
to inches (1 foot equals 12 inches). Calculate the number of boxes that the shelf can
hold in a single layer of type long and output the result.
*/

#include <iostream>

int main (int argc, char *argv[]) {
    const double FEET_TO_INCHES = 12;

    double shelf_length;
    double shelf_depth;
    std::cout << "Length of Shelf in feet: ";
    std::cin >> shelf_length;
    std::cout << "Depth of Shelf in feet: ";
    std::cin >> shelf_depth;

    int box_length_inches;
    int box_depth_inches;
    std::cout << "Length of Box in inches: ";
    std::cin >> box_length_inches;
    std::cout << "Depth of Box in inches: ";
    std::cin >> box_depth_inches;

    // convert from feet to inches
    shelf_length *= FEET_TO_INCHES;
    shelf_depth *= FEET_TO_INCHES;

    // utilize integer division
    int n_boxes_length = shelf_length / box_length_inches;
    int n_boxes_depth = shelf_depth / box_depth_inches;

    int n_boxes = n_boxes_length * n_boxes_depth;

    std::cout << "Number of boxes we can fit on the shelf: " << n_boxes << std::endl;

    return 0;
}
