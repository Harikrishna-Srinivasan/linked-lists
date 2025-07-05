#include <iostream>
#include <vector> // To use std::vector

#include "singly_linked_list.hpp"

/**
 * @file initialize_example.cpp
 * @brief Demonstrates usage of singly_linked_list constructors.
 * 
 * This program provides examples of initializing singly linked lists with various data types,
 * including integers, characters, and custom classes. It showcases the use of default constructors,
 * copy constructors, initializer lists, arrays, vectors, and move constructors.
 *
 * @sa append_example.cpp for appending a value to the list.
 *
 * @author Harikrishna Srinivasan
 * @date 05 July 2025
 * @version 0.9
 */

// Create a custom class
// Reference for std::vector usage: https://en.cppreference.com/w/cpp/language/operators.html
class my_class
{
    private:
        int my_var;
    public:
        // Default Constructor
        my_class() = default;

        // Parametrized Costructor
        my_class(int var)
        {
            this->my_var = var;
        }

        // Compulsory to define operator=, operator<, operator==, etc... to compare
        bool operator<(const my_class &obj)
        {
            return this->my_var < obj.my_var;
        }

        bool operator>(const my_class &obj)
        {
            return this->my_var > obj.my_var;
        }

        bool operator<=(const my_class &obj)
        {
            return this->my_var <= obj.my_var;
        }

        bool operator>=(const my_class &obj)
        {
            return this->my_var >= obj.my_var;
        }

        bool operator==(const my_class &obj)
        {
            return this->my_var == obj.my_var;
        }

        bool operator!=(const my_class &obj)
        {
            return this->my_var != obj.my_var;
        }

        // To display (print) the output using << (extraction) operator
        friend std::ostream &operator<<(std::ostream &out, const my_class &obj); // Decalre as friend to access private my_var of other object
};

std::ostream &operator<<(std::ostream &out, const my_class &obj)
{
    out << obj.my_var;

    return out;
}

int main()
{
    // Default Constructor: Initializes with default values
    singly_linked_list<int> list1;

    // Print the list1 object
    std::cout << "list1: " << list1 << std::endl; // list1: [] - Empty list

    // Constructor from an initializer list
    singly_linked_list<int> list2 = {21,45,37,64,72};
    singly_linked_list<char> char_list1 = {'a','r','r','a','y'};

    // Or, singly_linked_list<int> list3({21,45,37,64,72});
    // Or, singly_linked_list<int> list4 {21,45,37,64,72};

    // Similarly, singly_linked_list<char> char_list2({'a','r','r','a','y'});
    // Or, singly_linked_list<char> char_list3 {'a','r','r','a','y'};

    std::cout << "list2: " << list2 << std::endl; // list2: [21, 45, 37, 64, 72]
    std::cout << "char_list1: " << char_list1 << std::endl; // char_list1: [a, r, r, a, y]

    // Shared Object Constructor: Pass the object
    singly_linked_list<char> char_list2(char_list1); // Now, both char_list1 and char_list2 refers same object (like alias)

    // Modify charlist2
    // Reference for append usage: [append_example.cpp]
    char_list2.append('s');

    std::cout << "char_list1: " << char_list1 << std::endl; // char_list1: [a, r, r, a, y, s] - char_list1 is also modified
    std::cout << "char_list2: " << char_list2 << std::endl; // char_list2: [a, r, r, a, y, s]

    // Shared Object Constructor: Using braces "{}", can also use "()" or "="
    singly_linked_list<int> list3{list2}; // Using reference (&) is similar to this
    singly_linked_list<int> &list4 = list3;

    list4.append(108);
    std::cout << "list2: " << list2 << std::endl  // list2: [21, 45, 37, 64, 72, 108] - list2 is also modified
              << "list3: " << list3 << std::endl  // list3: [21, 45, 37, 64, 72, 108] - same as list2 and list4
              << "list4: " << list4 << std::endl; // list3: [21, 45, 37, 64, 72, 108]

    // Create copy for the object using copy() method
    // Reference for copy usage: [copy_example.cpp]
    singly_linked_list<int> list5;
    list5 = list2.copy(); // Or, list3.copy() or list4.copy()
    list5.append(120);
    
    std::cout << "list2: " << list2 << std::endl  // list2: [21, 45, 37, 64, 72, 108] - no change
              << "list3: " << list3 << std::endl  // list3: [21, 45, 37, 64, 72, 108] - no change
              << "list4: " << list4 << std::endl  // list4: [21, 45, 37, 64, 72, 108] - no change
              << "list5: " << list5 << std::endl; // list5: [21, 45, 37, 64, 72, 108, 120] - only the copy is changed

    // Create a string array
    std::string str_array[] = {"One","Two","Three"};

    // Constructor from std::string static array - similar to initializer_list
    singly_linked_list<std::string> str_arr_list = str_array; // !Note: Class can be used as template (e.g., std::string)
    std::cout << "str_arr_list: " << str_arr_list << std::endl; // str_arr_list: [One, Two, Three]

    // !Note: Constructor from dynamic array is not currently supported

    // Create a std::vector of my_class objects
    // Reference for std::vector usage: https://en.cppreference.com/w/cpp/container/vector/
    std::vector<my_class> my_class_vector = {my_class(1),my_class(2),my_class(3)};
    my_class_vector.push_back(my_class(4));

    // Constructor from std::vector with custom class (user-defined) template - similar to initializer_list
    singly_linked_list<my_class> my_class_list = my_class_vector;
    std::cout << "my_class_list: " << my_class_list << std::endl; // my_class_list: [1, 2, 3, 4]

    // Move constructor from list2 to list6, and makes list2 as Empty list
    singly_linked_list<int> list6 = std::move(list2); // Moves (shifts) elements from list2 to list6
    std::cout << "list6: " << list6 << std::endl  // list6: [21, 45, 37, 64, 72, 108]
              << "list2: " << list2 << std::endl; // list2: [] - Empty list

    // Move constructor invoked (called) using static_cast<Destination_Type>(expression_to_be_converted)
    // Reference for static_cast<T>(expr) usage: https://en.cppreference.com/w/cpp/language/static_cast/
    singly_linked_list<int> list7 = static_cast<singly_linked_list<int> &&>(list3); // !NOTE: list2 = [] but list3 is not
    std::cout << "list7: " << list7 << std::endl  // list7: [21, 45, 37, 64, 72, 108]
              << "list3: " << list3 << std::endl; // list3: [] - Empty list after moving to list7

    // !NOTE: list5 becomes Empty, as list4 shared its location with list3
    // Reference for & (reference operator) usage:  https://en.cppreference.com/w/cpp/language/reference
    std::cout << "list4: " << list4 << std::endl; // list4: [] - because list3 is Empty

    // !Note: Move contructor will not clear the sharing lists
    // But the references created by reference operator & will be cleared, since it is just an alias (that's why list4 is also emptied)

    // Now, list6 & list7 share the same list
    list6.append(133);
    std::cout << "list6: " << list6 << std::endl  // list6: [21, 45, 37, 64, 72, 108, 133]
              << "list7: " << list7 << std::endl; // list7: [21, 45, 37, 64, 72, 108, 133]
}
