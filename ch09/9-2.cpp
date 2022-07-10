/*
* exercise 9-2. alter the last lines of Ex9_01’s main() function as follows:
*   const auto a_string = "A", z_string = "Z";
*   std::cout << "Larger of " << a_string << " and " << z_string
*           << " is " << larger(a_string, z_string) << std::endl;
*
* if you now run the program, you may very well get the following output (if not, try
* rearranging the order in which a_string and z_string are delcared):
*
* ```
* Larger of 1.5 and 2.5 is 2.5
* Larger of 3.5 and 4.5 is 4.5
* Larger of 17011983 and and 10 is 17011983
* Larger of A and Z is A
* ```
*
* What’s that? "A" is larger than "Z"? Can you explain exactly what went wrong? Can
* you fix it?
*
* hint: to compare two character arrays, you could perhaps first convert them to another string
* representation.
*
*/

#include <iostream>
#include <string_view>

template <typename T>
T larger(T a, T b) {
    return a > b ? a : b;
}

/*
* Function specialization for larger to compute the larger value of string arrays
*/
template <>
const char* larger(const char* a, const char* b) {
    return std::string_view(a) > std::string_view(b) ? a : b;
}

int main (int argc, char *argv[]) {
    // Firstly you could just do this.. I guess it requires copying the string array so not ideal
    const auto a_string = "A", z_string = "Z";
        std::cout << "Larger of " << a_string << " and " << z_string
        << " is " << larger(std::string(a_string), std::string(z_string)) << std::endl;

    // Use the template function specialization for character arrays
    std::cout << "Larger of " << a_string << " and " << z_string
        << " is " << larger(a_string, z_string) << std::endl;

    return 0;
}
