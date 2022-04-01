/*
exercise 5-4. Use std::cin.getline(…) to obtain a C-style string of maximum 1,000
characters from the user. Count the number of characters the user entered using an
appropriate loop. next, write a second loop that prints out all characters, one by one,
but in a reverse order.
*/

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <cmath>

int main (int argc, char *argv[])
{
    const int MAX_INPUT_LENGTH = 1000;
    char text[MAX_INPUT_LENGTH] {};

    std::cout << "Enter a string: ";
    std::cin.getline(text, MAX_INPUT_LENGTH);

    int charCounter = 0;
    int i = 0;
    // check for null character
    while (text[i] != '\0' || i < MAX_INPUT_LENGTH) {
        charCounter++;
        i++;
    }
    printf("Number of characters: %d\n", charCounter);

    // we know the number of characters, let's use this to our advantage
    for (int i=charCounter - 1; i >= 0; i--) {
        std::cout << text[i];
    }
    std::cout << std::endl;

    return 0;
}
