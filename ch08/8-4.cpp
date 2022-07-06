/*
* exercise 8-4. Create a function, plus(), that adds two values and returns their sum.
* provide overloaded versions to work with int, double, and strings, and test that they
* work with the following calls:
* const int n {plus(3, 4)};
* const double d {plus(3.2, 4.2)};
* const string s {plus("he", "llo")};
* const string s1 {"aaa"};
* const string s2 {"bbb"};
* const string s3 {plus(s1, s2)};
*
* Can you explain why the following doesn’t work?
* const auto d {plus(3, 4.2)};
*
* This doesn't work because it is using two different data types. it could only work if we have a
* function:
* double plus(int a, double b);
*/

#include <iostream>

int plus(int a, int b) { return a + b; }
double plus(double a, double b) { return a + b; }
std::string plus(const std::string& a, const std::string& b) { return a + b; }

int main (int argc, char *argv[]) {

    std::cout << plus(3, 4) << std::endl;
    std::cout << plus(3.2, 4.2) << std::endl;
    std::cout << plus("he", "llo") << std::endl;

    std::string s1 = "aaa";
    std::string s2 = "bbb";
    std::cout << plus(s1, s2) << std::endl;

    return 0;
}
