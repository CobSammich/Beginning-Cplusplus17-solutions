/*
exercise 5-2. Write a program that uses a while loop to accumulate the sum of an
arbitrary number of integers entered by the user. after every iteration, ask the user
whether he or she is done entering numbers. the program should output the total of all
the values and the overall average as a floating-point value.
*/

#include <iostream>
#include <vector>

int main (int argc, char *argv[])
{
    int sum = 0;
    int nValues = 0;

    std::cout << "This Program computes the sum of a user entered list\n";
    while (true) {
        int currValue;
        // enter a number and push it onto the vector
        std::cout << "Enter a number to the list: ";
        std::cin >> currValue;
        nValues++;

        // Check if user is done entering numbers
        char anotherOne;
        std::cout << "Are you done entering numbers? [Y/n]: ";
        std::cin >> anotherOne;

        sum += currValue;

        if (std::tolower(anotherOne) == 'y') {
            break;
        }
    }
    printf("Sum: %d\n", sum);
    printf("Mean: %f\n", (float)sum / (float)nValues);

    return 0;
}
