/*
 * exercise 8-2. Write a function that reads a string or array of characters as input and
 * reverses it. Justify your choice of parameter type? provide a main() function to test
 * your function that prompts for a string of characters, reverses them, and outputs the
 * reversed string.
 */

#include <iostream>
#include <iterator>
#include <string>

void reverse(std::string& str) {
    // copy string to local variable
    std::string temp = str;
    // reverse the characters
    for (int i = 0; i < str.length(); ++i)
        str[i] = temp[str.length() - 1 - i];
}

int main (int argc, char *argv[]) {
    std::string value;
    std::cout << "Enter a string: ";
    std::cin >> value;

    printf("You entered %s\n", value.c_str());
    reverse(value);
    printf("Reversed %s\n", value.c_str());

    return 0;
}

