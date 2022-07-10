/*
* exercise 9-3. Write a function template plus() that takes two arguments of potentially
* different types and returns a value equal to the sum of both arguments. next, make
* sure that plus() can be used as well to add the values pointed to by two given
* pointers.
*
* extra: Can you now make it so that you can also concatenate two string literals using
* plus()? Warning: this may not be as easy as you think!
*/

#include <iostream>

template <typename T1, typename T2>
auto plus(T1 a, T2 b) {
    return a + b;
}

// Overload template for plus to accomodate for pointer types
template <typename T1, typename T2>
auto plus(T1* a, T2* b) {
    return *a + *b;
}

// Overload function to work with concatenating strings
std::string plus(const char* a, const char* b) {
    // NOTE: one of these has to be a std::string to be able to concatenate them like this.
    return std::string(a) + std::string(b);
}


int main (int argc, char *argv[]) {

    int v1 = 19;
    int v2 = 3;
    float v3 = 3.5;

    std::cout << plus(&v1, &v2) << std::endl;
    std::cout << plus(&v3, &v2) << std::endl;

    std::cout << plus(10.2, 1.4) << std::endl;
    std::cout << plus(10, 1.4) << std::endl;
    std::cout << plus(1.1, 2) << std::endl;
    std::cout << plus(1, 2) << std::endl;

    std::cout << plus("Hello, ", "World!") << std::endl;
    std::cout << plus("Solution ", "9-3 complete!") << std::endl;

    return 0;
}
