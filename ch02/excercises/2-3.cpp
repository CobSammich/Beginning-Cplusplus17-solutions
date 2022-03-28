/*
exercise 2-3. Create a program that converts inches to feet and inches. In case
you’re unfamiliar with imperial units: 1 foot equals 12 inches. an input of 77 inches,
for instance, should thus produce an output of 6 feet and 5 inches. prompt the user
to enter an integer value corresponding to the number of inches and then make the
conversion and output the result.
*/

#include <iostream>

int main (int argc, char *argv[]) {
    const int INCHES_PER_FEET = 12;
    int height_in_inches;

    std::cout << "Enter your height in inches as an integer: ";
    std::cin >> height_in_inches;

    int feet = height_in_inches / INCHES_PER_FEET;
    int inches = height_in_inches % INCHES_PER_FEET;

    std::cout << "Your height is " << feet << " feet "
        << inches << " inches" << std::endl;

    return 0;

}
