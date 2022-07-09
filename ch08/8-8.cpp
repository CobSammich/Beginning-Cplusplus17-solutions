/*
* exercise 8-8. if written using a more mathematical notation, the power() functions we
* wrote in Ex8_01 and especially Ex8_17 both essentially compute a power(x,n) for n >
* 0, as follows:
*
* SHOW RECURSIVE FUNCTION OF power(x, n-1)
*
* Clearly, this method requires exactly n-1 multiplications. it may surprise you, but there
* is another, much more effective way. suppose n is even; then you know the following:
* power(x,n) = power(x,n/2) * power(x,n/2)
*
* as both operands of this multiplication are identical, you need to compute this value
* only once. that is, you have just reduced the computation of power(x,n) to that
* of power(x,n/2), which obviously at most requires half as many multiplications.
* Moreover, because you can now apply this formula recursively, you’ll need even far
* fewer multiplications than that—only something in the order of log2(n) to be exact.
* to give you an idea, this means that for n in the order of 1000, you only need in the
* order of 10 multiplications! Can you apply this idea to create a more efficient recursive
* version of power()? You can start from the program in Ex8_17.cpp.
*
* note: this principle is something you’ll often see in recursive algorithms. in each
* recursive call, you reduce a problem to a problem of half the size. if you think back,
* you’ll realize that we applied the same principle in the quicksort algorithm as well, for
* instance. Because this solution strategy is that common, it also has a name; it’s called
* divide and conquer, after the famous phrase of Julius Caesar.
*
*/


/*
*
* let's say we want to look at 2^8
* 2^8 = 256 = 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2
*           = power(2, 4) * power(2, 4)
*           = (power(2, 2) * power(2, 2)) * (power(2, 2) * power(2, 2))
*
* 2^6 = 64 = 2 * 2 * 2 * 2 * 2 * 2
*          = 2^3 * 2^3
*          = (2^1 * 2^2) +
*
*
* 3^7 = 2187 = 3 * 3 * 3 * 3 * 3 * 3 * 3
*            = 3 * 3
*
*/

#include <iostream>

typedef unsigned long long ull;

ull power(ull x, ull n) {
    printf("power(%llu, %llu)\n", x, n);
    if (n == 2)
        return x * x;
    else if (n == 1)
        return x;
    else if (n == 0)
        return 1;
    // n is even
    if (n % 2 == 0)
        return power(x, n / 2) * power(x, n / 2);
    // n is odd
    else
        return power(x, n / 2 + 1) * power(x, n / 2);
}


int main (int argc, char *argv[]) {
    ull x;
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
