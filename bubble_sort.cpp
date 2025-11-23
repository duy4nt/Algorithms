#include <iostream>
#include <vector>

void bubble_sort(std::vector<int>& array, int size) {
    for (int step = 0; step < size - 1; ++step) {
        for (int i = 0; i < size - step - 1; ++i) {
            if (array[i] > array[i + 1]) {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
}

void input_array(std::vector<int>& array, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << "Enter the element " << i + 1 << " ";
        std::cin >> array[i];
    }
}

void print_array(std::vector<int>& array, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << " " << array[i];
    }
    std::cout << "\n";
}

int main() {
    int array_size;
    std::cout << "Enter the size of the array: ";
    std::cin >> array_size;

    std::vector<int> array(array_size);

    input_array(array, array_size);
    print_array(array, array_size);
    bubble_sort(array, array_size);
    std::cout << "Sorted Array in Ascending Order:\n";
    print_array(array, array_size);
    return 0;
}
