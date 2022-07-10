/*
* exercise 9-5. Can you think of a way to verify that the compiler generates only one
* instance of a function template for any given argument type? Do so for the larger()
* function in Ex9_01.cpp.
*/

// Do this by using static variables in the larger function. Then we can count how many times the
// function has been run for each argument type

#include <iostream>

template <typename T>
T larger(T a, T b) {
    static int count = 0;
    printf("Function template larger called %d times\n", ++count);
    return a > b ? a : b;
}

int main (int argc, char *argv[]) {

    larger(109, 110);
    larger(10.9, 11.2);
    larger("A", "Z");

    // Now we should see that each of these is being called for the second time
    larger(1, 2);
    larger(-0.32, 0.56);
    larger("?", "!");

    // and 3,4,5,6 times...
    larger(1, 2);
    larger(1, 2);
    larger(1, 2);
    larger(1, 2);

    return 0;
}
