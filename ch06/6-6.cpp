/*
exercise 6-6. revisit exercise 6-4 and replace any raw pointers with smart pointers
there as well.
*/

#include <iostream>
#include <cmath>
#include <memory>
#include <vector>

int main (int argc, char *argv[]) {
    int array_size;
    std::cout << "Enter the size of the array: ";
    std::cin >> array_size;

    // make smart pointer of vector
    // specifies a vector of size `array_size` all initialized to 0.0
    auto values = std::make_unique<std::vector<float>>(array_size);
    // specifies an empty vector
    //auto values = std::make_unique<std::vector<float>>();

    // fill with 1 / (n + 1)^2
    for (int n = 0; n < array_size; ++n)
        // assign the value a `n` -- size is inited already, no need to append (push_back)
        values->at(n) = 1.0 / std::pow(n + 1.0, 2.0);

    // sum values in array
    float sum = 0.0;
    for (int i = 0; i < array_size; ++i)
        sum += values->at(i);

    float finalValue = std::pow(sum * 6, 0.5);
    std::cout << "Final Value: " << finalValue << std::endl;

    // no need to free memory now
}
