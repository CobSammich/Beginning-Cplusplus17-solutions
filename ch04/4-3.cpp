/*
exercise 4-3. Create a program that prompts for input of a number (nonintegral numbers
are allowed) between 1 and 100. Use a nested if, first to verify that the number is within
this range and then, if it is, to determine whether it is greater than, less than, or equal to
50. The program should output information about what was found.
*/

#include <iostream>

int main (int argc, char *argv[]) {
    float value;

    std::cout << "Enter a value between 1 and 100: ";
    std::cin >> value;

    // problem requires a nested if statement, this would be better as an OR
    if (value < 1 || value > 100) {
        printf("Please enter a value between 1 and 100\n");
        return -1;
    }

    if (value == 50) {
        printf("value is 50!\n");
    }
    else if (value < 50) {
        printf("Value is in the range [1, 50)\n");
    }
    else if (value > 50) {
        printf("Value is in the range (50, 100]\n");
    }

    return 0;
}
