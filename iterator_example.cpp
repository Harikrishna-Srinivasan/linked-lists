#include <iostream>

#include "singly_linked_list.hpp"

/**
 * @file iterator_example.cpp
 * @brief Demonstrates usage of iterator methods like `iterator::begin`, `iterator::end`, `const_iterator::cbegin`, `const_iterator::cend`.
 *
 * @sa initialize_example.cpp for initializing the list.
 *
 * @author Harikrishna Srinivasan
 * @date 05 July 2025
 * @version 0.9
*/

int main()
{
    // Create a list of fruits using initializer list
    singly_linked_list<std::string> fruits = {"Banana","Apple","Orange","Mango"};

    // Iterating the fruits list
    std::cout << "Fruits: ";
    for (int i=0; i < len(fruits); i++)
        std::cout << fruits[i] << ' '; // Banana Apple Orange Mango
    std::cout << std::endl;

    // For each loop over fruits
    // It calls fruit.begin() & increments the iterator by 1,
    // till it is same as fruit.end()
    std::cout << "Fruits: ";
    for (auto fruit: fruits) // `auto` can automatically inference the datatype, instead of specifying std::string here (it is our choice)
        std::cout << fruit << ' '; // Banana Apple Orange Mango
    std::cout << std::endl;

    // Equivalent to this
    std::cout << "Fruits: ";
    for (linkedlist<std::string>::iterator iterator=fruits.begin(); iterator != fruits.end(); iterator++)
        std::cout << *iterator << ' '; // Dereferences the iterator: Banana Apple Orange Mango
    std::cout << std::endl;

    // This does not modify the fruits list
    for (std::string fruit: fruits)
        fruit = "Apple";
    std::cout << "Fruits: " << fruits << std::endl;

    // But we can modify the fruits list using the iterator
    for (auto iterator=fruits.begin(); iterator != fruits.end(); iterator++)
        *iterator = "Apple";
    std::cout << "Fruits: " << fruits << std::endl;

    // const_iterator prevents modifying the list
    // Uncomment the below 3 lines, to see a compilation error
    // for (linkedlist<std::string>::const_iterator iterator=fruits.cbegin(); iterator != fruits.cend(); iterator++)
    //     *iterator = "Banana";
    // std::cout << "Fruits: " << fruits << std::endl;
}
