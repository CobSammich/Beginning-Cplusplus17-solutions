/*
exercise 5-6. Create a vector<> container with elements containing the integers from
1 to an arbitrary upper bound entered by the user. output the elements from the vector
that contain values that are not multiples of 7 or 13. output them 10 on a line, aligned
in columns.
*/

#include <iostream>
#include <iomanip>
#include <vector>

int main (int argc, char *argv[])
{
    const int NUM_WIDTH = 7;

    int value;

    std::cout << "Enter an upper bound: ";
    std::cin >> value;

    std::vector<int> values(value);

    for (int i = 1; i < value; i++) {
        values.push_back(i);
    }

    int line_counter = 0;
    for (int val : values) {
        if (val % 7 != 0 && val % 13 != 0) {
            std::cout << std::setw(NUM_WIDTH) << val;

            line_counter++;
        }
        // reset the line counter
        if (line_counter >= 10) {
            line_counter = 0;
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;

    return 0;
}
