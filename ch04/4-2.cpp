/*
exercise 4-2. Write another program that prompts for two integers to be entered.
this time, any negative number or zero is to be rejected. next, check whether one
of the (strictly positive) numbers is an exact multiple of the other. For example, 63 is
a multiple of 1, 3, 7, 9, 21, or 63. note that the user should be allowed to enter the
numbers in any order. that is, it does not matter whether the user enters the largest
number first or the smaller one; both should work correctly!
*/

#include <iostream>

int main (int argc, char *argv[]) {
    int value1;
    int value2;

    std::cout << "Enter two integers: ";
    std::cin >> value1 >> value2;

    // check the two values are valid:
    if (value1 <= 0 || value2 <= 0) {
        printf("Please specify positive integers.\n");
        return -1;
    }

    int larger_value = (value1 >= value2) ? value1 : value2;
    int smaller_value = (larger_value == value1) ? value2 : value1;

    if (larger_value % smaller_value == 0) {
        printf("%d is an exact multiple of %d\n", larger_value, smaller_value);
        return 0;
    }
    printf("%d is NOT an exact multiple of %d\n", larger_value, smaller_value);

    return 0;
}
