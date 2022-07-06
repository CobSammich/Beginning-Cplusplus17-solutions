/*
* exercise 8-5. Define a function that checks whether a given number is prime. Your
* primal check does not have to be efficient; any algorithm you can think of will do. in
* case you have forgotten, a prime number is a natural number strictly greater than
* 1 and with no positive divisors other than 1 and itself. Write another function that
* generates a vector<> with all natural numbers less or equal to a first number and
* starting from another. By default it should start from 1. Create a third function that
* given a vector<> of numbers outputs another vector<> containing all the prime
* numbers it found in its input. use these three functions to create a program that prints
* out all prime numbers less or equal to a number chosen by the user (print, for instance,
* 15 primes per line). note: in principle, you do not need any vectors to print these prime
* numbers; obviously, these extra functions have been added for the sake of the exercise.
*/

#include <iostream>
#include <vector>

// NOTE: This can be sped up using memoization

bool check_prime(int value) {
    if (value <= 0) {
        std::cout << "Value must be >= 1 to be prime" << std::endl;
        return false;
    }

    // handle base cases
    if (value == 1)
        return false;
    else if (value == 2)
        return true;

    // even numbers are always not prime
    if (value % 2 == 0)
        return false;

    // check every odd number between 3 and value / 3
    for (int i = 3; i < value / 3 + 1; i+=2) {
        if (value % i == 0)
            return false;
    }

    return true;
}

std::vector<int> list_primes(int upper_bound, int start_value = 1) {
    std::vector<int> primes;
    for (int curr_value = start_value; curr_value < upper_bound; ++curr_value) {
        if (check_prime(curr_value))
            primes.push_back(curr_value);
    }
    return primes;
}

std::vector<int> prime_subset(std::vector<int> in_primes) {
    std::vector<int> out_primes;
    for (int val : in_primes) {
        if (check_prime(val))
            out_primes.push_back(val);
    }
    return out_primes;
}

int main (int argc, char *argv[]) {

    int upper_bound;
    std::cout << "choose a number to find all primes less than: ";
    std::cin >> upper_bound;

    std::vector<int> primes = list_primes(upper_bound, 1);
    for (int val : primes)
        std::cout << val << std::endl;

    std::vector<int> primes2;
    for (int i=1; i< upper_bound; i++)
        primes2.push_back(i);

    primes2 = prime_subset(primes2);
    for (int val : primes2)
        std::cout << val << std::endl;

    return 0;
}
