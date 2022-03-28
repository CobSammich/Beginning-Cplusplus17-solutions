/*
exercise 3-1. Create a program that prompts for input of an integer and store it
as an int. invert all the bits in the value and store the result. output the original
value, the value with the bits inverted, and the inverted value plus 1, each in
hexadecimal representation and on one line. on the next line, output the same
numbers in decimal representation. these two lines should be formatted such that
they look like a table, where the values in the same column are right aligned in
a suitable field width. all hexadecimal values should have leading zeros so eight
hexadecimal digits always appear.
*/

#include <ios>
#include <iostream>
#include <iomanip>
//#include <stdio.h>

int main (int argc, char *argv[]) {

    // 3 would be 0000 0011

    // Prompt the user to input an integer
    std::cout << "Enter an Integer: ";
    int input;
    std::cin >> input;

    // invert the bits of input
    int inverted_input = ~input;

    // one byte has two characters associated, and 0x is prefix so add 2
    unsigned int width = 2 * sizeof(int) + 2;


    // std::cout << std::hex << std::showbase << std::internal << std::setfill('0')
    // << "    " << std::setw(hex_value_width) << value
    // << "    " << std::setw(hex_value_width) << inverted_value
    // << "    " << std::setw(hex_value_width) << inverted_value + 1 << std::endl;

    std::cout << std::right << std::setw(width + 4) << "Value";
    std::cout << std::right << std::setw(width + 4) << "~Value";
    std::cout << std::right << std::setw(width + 4) << "~Value + 1" << std::endl;

    std::cout << std::hex << std::showbase << std::internal << std::setfill('0') << "    " << std::setw(width) << input;
    std::cout << std::hex << std::showbase << std::internal << std::setfill('0') << "    " << std::setw(width) << inverted_input;
    std::cout << std::hex << std::showbase << std::internal << std::setfill('0') << "    " << std::setw(width) << inverted_input + 1 << std::endl;

    std::cout << std::dec << std::right << std::setfill(' ') << "    " << std::setw(width) << input;
    std::cout << std::dec << std::right << std::setfill(' ') << "    " << std::setw(width) << inverted_input;
    std::cout << std::dec << std::right << std::setfill(' ') << "    " << std::setw(width) << inverted_input + 1 << std::endl;

    return 0;
}




