/*
*
* exercise 8-7. the so-called fibonacci function is popular among lecturers in computer
* science and mathematics for introducing recursion. this function has to compute the
* nth number from the famous fibonacci sequence, named after italian mathematician
* Leonardo of pisa, known also as fibonacci. this sequence of positive integer numbers
* is characterized by the fact that every number after the first two is the sum of the two
* preceding ones. for n ≥ 1, the sequence is defined as follows:
*
* 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181…
*
* for convenience, computer scientists mostly define an additional zeroth fibonacci
* number as zero. Write a function to compute the nth fibonacci number recursively.
* test it with a simple program that prompts the user for how many numbers should be
* computed and then prints them out one by one, each on a different line.
*
* extra: While the naive recursive version of the fibonacci function is very elegant—the
* code matches nearly verbatim with common mathematical definitions—it is notorious
* for being very slow. if you ask the computer to compute, say, 100 fibonacci numbers,
* you’ll notice that it becomes noticeably slower and slower as n becomes larger. Do
* you think you can rewrite the function to use a loop instead of recursion? how many
* numbers can you correctly compute now?
*
* hint: in each iteration of the loop, you’ll naturally want to compute a next number. to do
* this, all you need are the previous two numbers. so, there should be no need to keep
* track of the full sequence in, for instance, a vector<>.
*/

#include <iostream>

typedef unsigned long long ull;

unsigned long long fibonacci(int depth, ull nMinus2, ull nMinus1) {

    ull currValue = nMinus2 + nMinus1;

    std::cout << currValue << std::endl;
    if (depth == 3)
        return currValue;

    return fibonacci(depth - 1, nMinus1, currValue);
}

int main (int argc, char *argv[]) {

    int nNums;
    do {
        std::cout << "How many fibonacci numbers do you want to compute? ";
        std::cin >> nNums;
    } while (nNums <= 2); // Must ask for the 3rd or more fib number

    ull value1 = 1;
    ull value2 = 1;
    std::cout << value1 << std::endl;
    std::cout << value2 << std::endl;

    ull fib = fibonacci(nNums, value1, value2);
    std::cout << "N = " << nNums << " fibonacci number is " << fib << std::endl;

    return 0;
}
