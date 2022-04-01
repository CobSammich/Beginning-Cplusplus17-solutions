/*
exercise 5-4. Use std::cin.getline(…) to obtain a C-style string of maximum 1,000
characters from the user. Count the number of characters the user entered using an
appropriate loop. next, write a second loop that prints out all characters, one by one,
but in a reverse order.

Exercise 5-5. Write a program equivalent to that of Exercise 5-4, except for the following:

if before you used a for loop to count the characters, now use while, or vice versa

This time you should firest reverse the characters in the array, before printing them out left to
right.

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
    // check for null character
    for (int i = 0; i < MAX_INPUT_LENGTH; i++){
        if (text[i] == '\0') {
            break;
        }
        charCounter++;
    }
    printf("Number of characters: %d\n", charCounter);

    // First reverse the array:
    for (int i = 0; i < charCounter; i++) {
        char temp = text[charCounter - i - 1];
        text[charCounter - i - 1] = text[i];
        text[i] = temp;
    }

    for (int i = 0; i < charCounter; i++) {
        std::cout << text[i];
    }
    std::cout << std::endl;

    return 0;
}
