/*
exercise 5-3. Create a program that uses a do-while loop to count the number of
nonwhitespace characters entered on a line. the count should end when the first
# character is found.
*/

#include <iostream>

int main (int argc, char *argv[])
{

    std::cout << "Count the number of nonwhitespace characters ending with '#': ";
    std::cout << "Enter a String (max 50 characters): ";

    int indexCounter = 0;
    int nonwhitespaceCounter = 0;

    char currChar;
    do
    {
        std::cin >> currChar;
        if (currChar != ' ' && currChar != '#') {
            nonwhitespaceCounter++;
        }

        indexCounter++;
    } while(currChar != '#');

    printf("Count nonwhitespace before #: %d\n", nonwhitespaceCounter);

    return 0;
}
