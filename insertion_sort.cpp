#include <iostream>

void insertion_sort() {}

void print_array() {}

void main() {
    int array_size;
    std::cout << "Enter the size of the array";
    std::cin >> array_size;

    int array[array_size];

    for (int i= 0; i< array_size; i++) {
        std::cout << "Enter the " << i+1 << " th element".
        std::cin >> array[i];
    }

    std::cout << "The array elements are: ";
    for (int i= 0; i< array_size; i++) {
        cout << array[i] << " ";
    }

    return 0;
}   