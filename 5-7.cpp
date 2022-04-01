/*
exercise 5-7. Write a program that will read and store an arbitrary sequence of records
relating to products. each record includes three items of data—an integer product
number, a quantity, and a unit price. For product number 1001, the quantity is 25,
and the unit price is $9.95. Because you do not know yet how to create compound
types, simply use three different array-like sequences to represent these records.
the program should output each product on a separate line and include the total cost.
the last line should output the total cost for all products. Columns should align, so the
output should be something like this:

Product     Quantity    Unit        Price Cost
1001        25          $9.95       $248.75
1003        10          $15.50      $155.00
                                    $403.75
*/

#include <iostream>
#include <iomanip>
#include <vector>


int main (int argc, char *argv[])
{

    const int COLUMN_WIDTH = 12;

    // we don't know about structs yet.. store each record value in four vectors for the four
    // columns
    std::vector<int> productNums;
    std::vector<int> quantities;
    std::vector<float> unitPrices;
    std::vector<float> costs;

    char anotherOne;

    do {

        int productNum;
        int quantity;
        float unitPrice;
        // store user input
        std::cout << "Enter the product Number (integer): ";
        std::cin >> productNum;
        std::cout << "Enter the Quantity (integer): ";
        std::cin >> quantity;
        std::cout << "Enter the unit price: (float): ";
        std::cin >> unitPrice;
        float cost = quantity * unitPrice;

        // store the record
        productNums.push_back(productNum);
        quantities.push_back(quantity);
        unitPrices.push_back(unitPrice);
        costs.push_back(cost);

        // check if user wants to enter another value and loop back
        std::cout << "Enter another product? [y/n]: ";
        std::cin >> anotherOne;
    } while (std::tolower(anotherOne) == 'y');


    std::cout << std::setw(COLUMN_WIDTH) << "Product";
    std::cout << std::setw(COLUMN_WIDTH) << "Quantity";
    std::cout << std::setw(COLUMN_WIDTH) << "Unit";
    std::cout << std::setw(COLUMN_WIDTH) << "Price Cost";
    std::cout << std::endl;

    int n_records = std::size(productNums);
    float total_cost = 0;
    for (int i = 0; i < n_records; i++) {
        std::cout << std::setw(COLUMN_WIDTH) << productNums[i];
        std::cout << std::setw(COLUMN_WIDTH) << quantities[i];
        std::cout << std::setw(COLUMN_WIDTH) << unitPrices[i];
        std::cout << std::setw(COLUMN_WIDTH) << costs[i];
        std::cout << std::endl;

        // add to the total cost
        total_cost += costs[i];
    }

    std::cout << std::setw(COLUMN_WIDTH * 4) << total_cost;


    std::cout << std::endl;
    return 0;
}
