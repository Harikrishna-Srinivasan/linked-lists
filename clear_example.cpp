#include <iostream>

#include "singly_linked_list.hpp"

/**
 * @file clear_example.cpp
 * @brief Demonstrates the usage of the `clear` method in a singly linked list.
 *
 * @sa initialize_example.cpp for initializing the list.
 * 
 * @author Harikrishna Srinivasan
 * @date 05 July 2025
 * @version 0.9
 */

int main()
{
    // Create a list of some numbers
    singly_linked_list<int> list1 = {1, 2, 3, 4, 5};

    // Let both lists point to same location
    singly_linked_list<int> list2 = list1;

    // list3 containing only copy of list1 (or list2)
    singly_linked_list<int> list3 = list1.copy();

    // list4 is the C++ reference variable for list1
    singly_linked_list<int> &list4 = list1;

    // Display the lists
    std::cout << "list1: " << list1 << std::endl // list1: [1, 2, 3, 4, 5]
              << "list2: " << list2 << std::endl // list2: [1, 2, 3, 4, 5]
              << "list3: " << list3 << std::endl // list3: [1, 2, 3, 4, 5]
              << "list4: " << list4 << std::endl << std::endl; // list4: [1, 2, 3, 4, 5]

    // Display lists' locations
    // list1 & list4 will have same address (they are just an alias for each other)
    std::cout << "list1: " << &list1 << std::endl  // list1: 0x7ffe45a82fd0 (just a sample, will get different address each time)
              << "list2: " << &list2 << std::endl  // list2: 0x7ffe45a83000
              << "list3: " << &list3 << std::endl  // list3: 0x7ffe45a83030
              << "list4: " << &list4 << std::endl << std::endl; // list4: 0x7ffe45a82fd0 (same as &list1, list1's address)

    for (int i=0; i < list1.size(); i++)
        std::cout << "Address of list1[" << i << "]: " << &list1[i] << std::endl // same
                  << "Address of list2[" << i << "]: " << &list2[i] << std::endl // same
                  << "Address of list3[" << i << "]: " << &list3[i] << std::endl // not same as other 3
                  << "Address of list4[" << i << "]: " << &list4[i] << std::endl << std::endl; // same

    // Clear list1's content
    list1.clear();

    // Display the lists
    std::cout << "list1: " << list1 << std::endl  // list1: []
              << "list2: " << list2 << std::endl  // list2: [] (list2 also got cleared, beacause the contents have same reference)
              << "list3: " << list3 << std::endl  // list3: [1, 2, 3, 4, 5] (not affected by list1)
              << "list4: " << list4 << std::endl; // list4: []

    // Assign the list to {1, 2, 3}
    list1 = {1, 2, 3};

    // Display the lists
    std::cout << "list1: " << list1 << std::endl  // list1: [1, 2, 3]
              << "list2: " << list2 << std::endl  // list2: [1, 2, 3] (list2 shares same memory with list1)
              << "list3: " << list3 << std::endl  // list3: [1, 2, 3, 4, 5] (no effect)
              << "list4: " << list4 << std::endl; // list4: [1, 2, 3]
}
