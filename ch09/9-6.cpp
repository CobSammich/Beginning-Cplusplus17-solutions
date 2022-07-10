/*
* exercise 9-6. in the previous chapter, you studied a quicksort algorithm that worked
* for pointers-to-strings. Generalize the implementation of Ex8_18.cpp so that it works
* for vectors of any type (any type for which the < operator exists, that is). Write a
* main() function that uses this to sort some vectors with different element types and
* outputs both the unsorted and unsorted element lists. naturally, you should do this by
* also creating a function template that streams vectors with arbitrary element types to
* std::cout.
*/

#include <iostream>
#include <vector>

template <typename T>
void swap(std::vector<T>& grades, size_t first, size_t second) {
    auto temp = grades.at(first);
    grades[first] = grades[second];
    grades[second] = temp;
}

template <typename T>
void sort(std::vector<T>& grades, size_t start, size_t end) {
    // start index must be less than end index for 2 or more elements
    if (!(start < end))
        return;
    // Choose middle address to partition set
    swap(grades, start, (start + end) / 2);          // Swap middle address with start
    // Check grades against chosen word
    size_t current {start};
    for (size_t i {start + 1}; i <= end; i++)
    {
        if (grades[i] < grades[start])                // Is word less than chosen word?
        swap(grades, ++current, i);                  // Yes, so swap to the left
    }
    swap(grades, start, current);                    // Swap chosen and last swapped grades
    if (current > start) sort(grades, start, current - 1);   // Sort left subset if exists
    if (end > current + 1) sort(grades, current + 1, end);   // Sort right subset if exists
}


template <typename T>
void printVector(const std::vector<T>& v) {
    std::cout <<  "Values in vector:" << std::endl;
    for (T element : v)
        std::cout << element << " ";
    std::cout << std::endl;
}


int main (int argc, char *argv[]) {

    std::vector<int> v1 = {10,5,3,54,34,6654,53,32, -42, -342};
    std::vector<double> v2 = {0.32,-1003.32,38922.2342423,-384.0,112.4,0.0};
    std::vector<std::string> v3 = {"A", "B", "Z", "F", "?"};

    sort(v1, 0, v1.size() - 1);
    sort(v2, 0, v2.size() - 1);
    sort(v3, 0, v3.size() - 1);

    printVector(v1);
    printVector(v2);
    printVector(v3);


    return 0;
}
