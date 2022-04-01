/*
exercise 5-3. Create a program that uses a do-while loop to count the number of
nonwhitespace characters entered on a line. the count should end when the first
# character is found.
*/

#include <iostream>

int main (int argc, char *argv[])
{
    char input[50];

    std::cout << "Count the number of nonwhitespace characters until the first numeric value\n";
    std::cout << "Enter a String (max 50 characters): ";
    std::cin >> input;

    int indexCounter = 0;
    int nonwhitespaceCounter = 0;

    char currChar;
    do
    {
        currChar = input[indexCounter];
        if (currChar != ' ' && !std::isdigit(currChar)) {
            nonwhitespaceCounter++;
        }

        // this is redundant
        if (std::isdigit(currChar)) {
            break;
        }

        indexCounter++;
    } while(!std::isdigit(currChar));

    printf("Count nonwhitespace before #: %d\n", nonwhitespaceCounter);

    return 0;
}
