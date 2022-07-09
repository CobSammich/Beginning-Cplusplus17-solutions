/*
*
* exercise 8-6. implement a program that queries the user for a number of grades. a
* grade is an integer number between 0 and 100 (both inclusive). the user can stop at
* any time by entering a negative number. once all grades have been collected, your
* program is to output the following statistics: the five highest grades, the five lowest
* grades, the average grade, the median grade, and the standard deviation and variance
* of the grades. of course, you’re to write a separate function to compute each of these
* statistics. also, you must write the code to print five values only once. to practice, use
* arrays to stroe any five extremes and not, for instance, vectors.
*
* hint: as a preprocessing step, you should first sort the grades the user enters; you’ll
* see that this will make writing the functions to compute the statistics much easier. You
* can adapt the quicksort algorithm from Ex8_18 to work with grade numbers.
*
* Caution: Make sure to do something sensible if the user enters less than five or even
* zero grades. anything is fine, as long as it does not crash. perhaps you can practice
* std::optional<> to deal with inputs such as an empty series of grades?
*
* note: the median is the value that appears in the middle position of a sorted list. if
* there is an even number of grades, there obviously is no single middle value—the
* median is then defined as the mean of the two middle values. the formulas to compute
* mean (μ) and standard deviation (σ) of a series of n grades xi are as follows:
*
* SEE BOOK for Equation of mean and standard deviation.
*
* the variance is then defined as σ2. the cmath header of the standard Library defines
* std::sqrt() to compute square roots.
*/

#include <cstdlib>
#include <iostream>
#include <vector>
#include <optional>
#include <cmath>

void gatherGrades(std::vector<int>& grades);
void printArray(const std::optional<int> (&arr)[5], const std::string header = "Highest Grades: ");

// stats computation functions
void fillLowestGrades(const std::vector<int>& grades, std::optional<int>(&lowest)[5]);
void fillHighestGrades(const std::vector<int>& grades, std::optional<int>(&lowest)[5]);
std::optional<float> computeAverage(const std::vector<int>& grades);
std::optional<float> computeMedian(const std::vector<int>& grades);
std::optional<float> computeVariance(const std::vector<int>& grades);

/// Sorting functions
void swap(std::vector<int>& grades, size_t first, size_t second);
void sort(std::vector<int>& grades, size_t start, size_t end);

int main (int argc, char *argv[]) {

    std::vector<int> grades;
    std::optional<int> extremes[5];


    gatherGrades(grades);

    // Sort the grades lowest to highest
    sort(grades, 0, grades.size() - 1);

    // compute, store, and print the highest grades
    fillHighestGrades(grades, extremes);
    printArray(extremes, "Highest Grades: ");

    // compute, store, and print the lowest grades
    fillLowestGrades(grades, extremes);
    printArray(extremes, "Lowest Grades: ");

    // compute the average, median, and variance values.
    std::optional<float> avgGrade = computeAverage(grades);
    if (avgGrade)
        std::cout << "Average grade: " << *avgGrade << std::endl;

    std::optional<float> medianGrade = computeMedian(grades);
    if (medianGrade)
        std::cout << "Median grade: " << *medianGrade << std::endl;

    std::optional<float> variance = computeVariance(grades);
    if (variance) {
        std::cout << "Variance: " << *variance << std::endl;
        float standardDeviation = std::sqrt(*variance);
        std::cout << "Standard Deviation: " << standardDeviation << std::endl;
    }

    return 0;
}

void swap(std::vector<int>& grades, size_t first, size_t second) {
    auto temp = grades.at(first);
    grades[first] = grades[second];
    grades[second] = temp;
}

void sort(std::vector<int>& grades, size_t start, size_t end) {
    // start index must be less than end index for 2 or more elements
    if (!(start < end))
        return;
    // Choose middle address to partition set
    swap(grades, start, (start + end) / 2);          // Swap middle address with start
    // Check grades against chosen word
    size_t current {start};
    for (size_t i {start + 1}; i <= end; i++)
    {
        if (grades[i] < grades[start])                // Is word less than chosen word?
        swap(grades, ++current, i);                  // Yes, so swap to the left
    }
    swap(grades, start, current);                    // Swap chosen and last swapped grades
    if (current > start) sort(grades, start, current - 1);   // Sort left subset if exists
    if (end > current + 1) sort(grades, current + 1, end);   // Sort right subset if exists
}


void gatherGrades(std::vector<int>& grades) {
    int currGrade;
    while (true) {
        std::cout << "Enter a grade between 0 and 100 (inclusive), enter a negative number if " <<
            "you're done entering grades: ";
        std::cin >> currGrade;
        if (currGrade < 0)
            break;
        else if (currGrade > 100)
            std::cout << "Number must be between 0 and 100" << std::endl;
        else
            grades.push_back(currGrade);
    }
}


void fillLowestGrades(const std::vector<int>& grades, std::optional<int>(&highest)[5]) {
    for (int i = 0; i < grades.size() && i < 5; ++i)
        highest[i] = grades.at(i);
}


void fillHighestGrades(const std::vector<int>& grades, std::optional<int>(&lowest)[5]) {
    int index = 0;
    for (int i = grades.size() - 1; i >= 0; --i) {
        lowest[index] = grades.at(i);
        index++;
        if (index == 5)
            break;
    }
}

std::optional<float> computeAverage(const std::vector<int>& grades) {
    if (grades.empty())
        return std::nullopt;

    float sum = 0.0;
    for (auto grade : grades)
        sum += grade;
    return sum / (float)grades.size();
}

std::optional<float> computeMedian(const std::vector<int>& grades) {
    if (grades.empty())
        return std::nullopt;

    // we have even number, compute mean of the middle two
    if (grades.size() % 2 == 0)
        return (grades.at(grades.size() / 2 - 1) + grades.at(grades.size() / 2)) / 2.0;
    else
        return grades.at(grades.size() / 2);
}

std::optional<float> computeVariance(const std::vector<int>& grades) {
    if (grades.empty())
        return std::nullopt;

    // This is safe to do, because we have already checked above that grades has some values in it.
    // Therefore we can safely assume when we "unwrap" the return value from this function there
    // will be a float within it.
    float mean = *computeAverage(grades);

    double stddev = 0.0;
    for (auto grade : grades)
        stddev += std::pow(grade - mean, 2.0);
    stddev /= grades.size();

    return stddev;
}

void printArray(const std::optional<int> (&arr)[5], const std::string header) {
    std::cout << header << std::endl;
    for (auto& val : arr) {
        if (val.has_value())
            std::cout << val.value() << " ";
        // NOTE: This also works -- check if address is valid, then get value at address
        //if (val) {
            //std::cout << *val << std::endl;
    }
    std::cout << std::endl;
}
