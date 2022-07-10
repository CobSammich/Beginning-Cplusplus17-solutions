/*
* exercise 9-4. Write your own version of the std::size() family of functions called
* my_size() that work not only for fixed-size arrays but also for std::vector<> and
* std::array<> objects. You are not allowed to use the sizeof() operator.
*/

#include <iostream>
#include <array>
#include <vector>

// Returns the size of a fixed-size array
template <typename T, size_t N>
int my_size(const T (&arr)[N]) { return N; }

// Overload for std::arrays
template <typename T, size_t N>
int my_size(const std::array<T, N> arr) { return N; }

// Overload for std::vectors
template <typename T>
int my_size(const std::vector<T> arr) { return arr.size(); }


int main (int argc, char *argv[]) {
    double doubleArray[] { 1.0, 2.0, 3.0, 4.0 };
    std::array<double, 6> doubleArray2 = { 1.0, 2.0, 3.0, 4.0, 5.0, 43.0};
    std::vector<int> v1 = {10, 20, 34};

    std::cout << my_size(doubleArray) << std::endl;
    std::cout << my_size(doubleArray2) << std::endl;
    std::cout << my_size(v1) << std::endl;

    return 0;
}


/*
From: https://github.com/Apress/beg-cplusplus17/blob/master/Beginning%20C%2B%2B%2017%20source%20code/Exercises/Chapter%2009/Soln9_04.cpp

Alternatively, you can create one template that would make my_size
accept any argument and call size() on it. This will make it work
for std::array<> and std::vector<>, as well as std::string and many other containers:

template <typename Collection>
inline size_t my_size(const Collection& collection) { return collection.size(); }

Potential downside is that this will instantiate for int and double type arguments
as well, which may result in somewhat verbose compiler errors.
*/
