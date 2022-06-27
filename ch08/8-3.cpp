/*
 * exercise 8-3. Write a program that accepts from two to four command-line arguments.
 * if it is called with less than two or more than four arguments, output a message telling
 * the user what they should do and then exit. if the number of arguments is correct,
 * output them, each on a separate line.
 */

#include <iostream>

bool validArguments(int nArgs) {
    return (nArgs >= 2 && nArgs <= 4);
}

/*
* NOTE: Another way to do this is a switch statement on (argc - 1) with default being what I have in
* the if statement.
*/
int main (int argc, char *argv[]) {

    if (!validArguments(argc - 1)) {
        printf("Please enter between 2 and 4 arguments... You entered %d arguments\n", argc - 1);
        return -1;
    }

    for (int i = 0; i < argc; ++i)
        std::cout << argv[i] << std::endl;

    return 0;
}
