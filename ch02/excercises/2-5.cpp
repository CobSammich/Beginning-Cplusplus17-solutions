/*
64
exercise 2-5. your body mass index (BmI) is your weight, w, in kilograms divided by
the square of your height, h, in meters (w/(h*h)). Write a program to calculate the BmI
from a weight entered in pounds and a height entered in feet and inches. a kilogram is
2.2 pounds, and a foot is 0.3048 meters.
*/

#include <iostream>
#include <cmath>

int main (int argc, char *argv[]) {
    const double POUNDS_TO_KILOGRAMS = 2.2;
    const double FEET_TO_METERS = 0.3048;
    const double INCHES_PER_FEET = 12;

    double weight_in_pounds; // pounds
    double height_feet;
    double height_inches;

    std::cout << "Enter your weight in pounds: ";
    std::cin >> weight_in_pounds;

    std::cout << "Enter your height in feet and inches both as integers: ";
    std::cin >> height_feet >> height_inches;

    double height = height_feet + height_inches / INCHES_PER_FEET;

    // convert height from feet to meters
    height *= FEET_TO_METERS;
    // convert pounds to kilograms
    double weight = weight_in_pounds / POUNDS_TO_KILOGRAMS;
    std::cout << "Weight in Kilograms: " << weight <<std::endl;
    std::cout << "Height in meters: " << height <<std::endl;

    double bmi = weight / (height * height);

    std::cout << "Your BMI is: " << bmi << std::endl;

}
