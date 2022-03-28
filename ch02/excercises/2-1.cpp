/*
* exercise 2-1. Write a program that will compute the area of a circle. the program should prompt
* for the radius of the circle to be entered from the keyboard, calculate the
*/

#include <iostream>

int main (int argc, char *argv[]) {
    const double PI = 3.141592653589793238;
    double radius;

    std::cout << "Enter the radius of the circle: ";
    std::cin >> radius;

    double area = PI * radius * radius;

    std::cout << "Area of the circle: " << area << std::endl;

    return 0;
}
