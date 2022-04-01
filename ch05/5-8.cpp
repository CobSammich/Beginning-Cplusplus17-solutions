/*
exercise 5-8. the famous Fibonacci series is a sequence of integers with the first
two values as 1 and the subsequent values as the sum of the two preceding values.
so, it begins 1, 1, 2, 3, 5, 8, 13, and so on. this is not just a mathematical curiosity.
the sequence also regularly appears in biological settings, for instance. It relates to
the way shells grow in a spiral, and the number of petals on many flowers is a number
from this sequence. Create an array<> container with 93 elements. store the first 93
numbers in the Fibonacci series in the array and then output them one per line.
any idea why we’d be asking you to generate 93 Fibonacci numbers and not, say, 100

Answer: Computing fibonacci numbers greate than 93 results in overflow even with datatype unsigned long long
*/

#include <iostream>
#include <array>

int main (int argc, char *argv[]) {
    const int N_VALUES = 93;

    std::array<unsigned long long, N_VALUES> values {};
    // put in the base cases
    values[0] = 1;
    values[1] = 1;

    for (int i = 2; i < N_VALUES; i++) {
        values[i] = values[i - 1] + values[i - 2];
    }

    for (int i = 0; i < std::size(values); i++)
        std::cout << "index: " << i + 1 << ": "<< values[i] << std::endl;

    return 0;
}
