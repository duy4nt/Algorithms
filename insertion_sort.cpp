#include <iostream>
#include <vector>

void insertion_sort(std::vector<int>& array, int size) {
    for (int i = 1; i < size; i++) {
        int key = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

void print_array(std::vector<int>& array, int size) {
    std::cout << "The elements of the array are: ";
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
}

void input_array(std::vector<int>& array, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << "Enter the element " << i + 1 << " ";
        std::cin >> array[i];
    }
}


int main() {
    int array_size;
    std::cout << "Enter the size of the array: ";
    std::cin >> array_size;

    std::vector<int> array(array_size);

    input_array(array, array_size);
    print_array(array, array_size);
    insertion_sort(array, array_size);
    print_array(array, array_size);

    return 0;
}
