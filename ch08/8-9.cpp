/*
 * exercise 8-9. Modify the solution of exercise 8-8 such that it counts the number of
 * times the call power(1.5,1000) performs a multiplication. Do so by replacing each
 * multiplication with a helper function mult() that takes two arguments, prints a
 * message of how many multiplications have been performed thus far, and then simply
 * returns the product of both arguments. Use at least one static variable.
 */

#include <iostream>

typedef unsigned long long ull;

inline long double mult(long double v1, long double v2) {
    static ull count = 0;
    count++;
    printf("%llu multiplications performed\n", count);
    return v1 * v2;
}

long double power(double x, ull n) {
    printf("power(%f, %llu)\n", x, n);
    if (n == 0)
        return 1.0;
    // n is even
    if (n % 2 == 0) {
        // this is the trick here -- compute this once instead of twice
        auto y = power(x, n / 2);
        return mult(y, y);
    }
    // n is odd
    else
        //return mult(power(x, n / 2 + 1), power(x, n / 2));
        return mult(x, power(x, n - 1));
}


int main (int argc, char *argv[]) {
    double x;
    ull n;

    std::cout << "x: ";
    std::cin >> x;
    std::cout << std::endl;

    std::cout << "n: ";
    std::cin >> n;
    std::cout << std::endl;

    ull result = power(x, n);
    std::cout << x << "^" << n << " = " << result << std::endl;

    return 0;
}
