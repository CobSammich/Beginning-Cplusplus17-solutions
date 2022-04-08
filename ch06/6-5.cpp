/*
exercise 6-5. revisit exercise 6-3, but this time use a smart pointer to store the array,
that is, if you haven’t already done so from the start. a good student should’ve known
not to use the low-level memory allocation primitives….
*/

#include <iostream>
#include <iomanip>
#include <cmath>

int main (int argc, char *argv[]) {
    int array_size;
    std::cout << "Enter the size of the array: ";
    std::cin >> array_size;

    // dynamically allocate array
    auto values = std::make_unique<float[]>(array_size);
    // fill with 1 / (n + 1)^2
    for (int n = 0; n < array_size; ++n)
        values[n] = 1.0 / std::pow(n + 1.0, 2.0);

    float sum = 0.0;
    for (int i = 0; i < array_size; ++i)
        sum += values[i];

    float finalValue = std::pow(sum * 6, 0.5);
    std::cout << "Final Value: " << finalValue << std::endl;

    // Smart pointer now handles freeing the memory itself.
}
