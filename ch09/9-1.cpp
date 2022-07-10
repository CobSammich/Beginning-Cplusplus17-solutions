/*
* exercise 9-1. in C++17, the standard library algorithm header gained the handy std::clamp() function
* template. the expression clamp(a,b,c) is used to clamp the value a to a given closed interval [b,c].
* that is, if a is less than b, the result of the expression will be b; and if a is greater than c,
* the result will be c; otherwise, if a lies within the interval [b,c], clamp() simply returns a.
* Write your own my_clamp() function template and try it with a little test program.
*/

#include <iostream>
#include <algorithm>


template <typename T>
const T& clamp(const T& a, const T& b, const T& c) {
    if (a < b)
        return b;
    else if (a > c)
        return c;
    return a;
}

int main (int argc, char *argv[]) {

    std::cout << std::clamp(0.9, 0.0, 1.0) << std::endl;
    std::cout << std::clamp(-0.9, 0.0, 1.0) << std::endl;
    std::cout << std::clamp(1.9, 0.0, 1.0) << std::endl;

    std::cout << clamp(0.9, 0.0, 1.0) << std::endl;
    std::cout << clamp(-0.9, 0.0, 1.0) << std::endl;
    std::cout << clamp(1.9, 0.0, 1.0) << std::endl;

    std::cout << std::clamp(90, 20, 120) << std::endl;
    std::cout << std::clamp(20, 20, 120) << std::endl;
    std::cout << std::clamp(120, 20, 120) << std::endl;

    std::cout << clamp(90, 20, 120) << std::endl;
    std::cout << clamp(20, 20, 120) << std::endl;
    std::cout << clamp(120, 20, 120) << std::endl;

    return 0;
}
