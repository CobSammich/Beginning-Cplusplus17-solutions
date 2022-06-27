/*
* exercise 8-1. Write a function, validate_input(), that accepts two integer arguments
* that represent the upper and lower limits for an integer that is to be entered. it should
* accept a third argument that is a string describing the input, with the string being used
* in the prompt for input to be entered. the function should prompt for input of the value
* within the range specified by the first two arguments and include the string identifying the
* type of value to be entered. the function should check the input and continue to prompt
* for input until the value entered by the user is valid. use the validate_input() function
* in a program that obtains a user’s date of birth and outputs it in the form of this example:
* November 21, 2012
* the program should be implemented so that separate functions, month(), year(),
* and day(), manage the input of the corresponding numerical values. Don’t forget leap
* years -- February 29, 2017 is not allowed!
*/

#include <cstdlib>
#include <locale>
#include <iostream>
#include <string>
#include <string.h>

int validate_input(int lower, int upper, std::string description) {
    int value;
    while (value < lower || value > upper) {
        printf("Please enter a valid value between %d and %d\n", lower, upper);
        std::cout << description << ": ";
        std::cin >> value;
    }
    return value;
}

int month(std::string& monthString) {
    int thisMonth = validate_input(1, 12, "Enter the month you were born");
    switch (thisMonth) {
    case 1:
        monthString = "January";
        break;
    case 2:
        monthString = "February";
        break;
    case 3:
        monthString = "March";
        break;
    case 4:
        monthString = "April";
        break;
    case 5:
        monthString = "May";
        break;
    case 6:
        monthString = "June";
        break;
    case 7:
        monthString = "July";
        break;
    case 8:
        monthString = "August";
        break;
    case 9:
        monthString = "September";
        break;
    case 10:
        monthString = "October";
        break;
    case 11:
        monthString = "November";
        break;
    case 12:
        monthString = "December";
        break;
    }
    return thisMonth;
}

int year() {
    const int TM_YEAR_CONST = 1900;
    std::time_t t = std::time(nullptr);
    std::tm *const pTInfo = std::localtime(&t);
    std::cout << "Current year: " << TM_YEAR_CONST + pTInfo->tm_year << '\n';
    int thisYear = validate_input(TM_YEAR_CONST, TM_YEAR_CONST + pTInfo->tm_year, "Enter the Year you were born");
    return thisYear;
}

int day(int theMonth, int theYear, const std::string& monthString) {
    std::string monthBasedDescription = "Enter the day you were born in " + monthString + " " +
        std::to_string(theYear);

    switch (theMonth) {
    case 1:
        return validate_input(1, 31, monthBasedDescription);
    case 2:
        // if the year is divisible by 4, then we are in a leap year -- there can be 29 days
        switch (theYear % 4) {
        case 0:
            return validate_input(1, 29, monthBasedDescription);
        default:
            return validate_input(1, 28, monthBasedDescription);
        }
    case 3:
        return validate_input(1, 31, monthBasedDescription);
    case 4:
        return validate_input(1, 30, monthBasedDescription);
    case 5:
        return validate_input(1, 31, monthBasedDescription);
    case 6:
        return validate_input(1, 30, monthBasedDescription);
    case 7:
        return validate_input(1, 31, monthBasedDescription);
    case 8:
        return validate_input(1, 31, monthBasedDescription);
    case 9:
        return validate_input(1, 30, monthBasedDescription);
    case 10:
        return validate_input(1, 31, monthBasedDescription);
    case 11:
        return validate_input(1, 30, monthBasedDescription);
    case 12:
        return validate_input(1, 31, monthBasedDescription);
    }
    return 0;
}

void printBirthdate(const std::string& m, int d, int y) {
    std::string dayString = std::to_string(d);
    std::string yearString = std::to_string(y);
    std::cout << m + ", " + dayString + " " + yearString << std::endl;
}

int main (int argc, char *argv[]) {
    std::cout << "What is your birthday?" << std::endl;

    std::string monthString;
    int monthValue = month(monthString);
    int yearValue = year();
    int dayValue = day(monthValue, yearValue, monthString);


    printBirthdate(monthString, dayValue, yearValue);


    return 0;
}

