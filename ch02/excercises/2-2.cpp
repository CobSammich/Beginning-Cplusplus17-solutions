/*
exercise 2-2. using your solution for exercise 2-1, improve the code so that the user
can control the precision of the output by entering the number of digits required. to
really show off how accurate floating-point numbers can be, you can perhaps switch
to double-precision floating-point arithmetic as well. you’ll need a more precise
approximation of π. 3.141592653589793238 will do fine.
*/

#include <iostream>
#include <iomanip>

int main (int argc, char *argv[]) {
    const double PI = 3.141592653589793238;
    double radius;
    int precision;

    std::cout << "Enter the radius of the circle: ";
    std::cin >> radius;
    std::cout << "Enter the floating-point precision you want: ";
    std::cin >> precision;

    double area = PI * radius * radius;

    std::cout << "Area of the circle: " << std::setprecision(precision) << area << std::endl;

    return 0;
}
