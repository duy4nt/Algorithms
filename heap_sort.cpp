#include <iostream>
#include <vector>


void heapify(std::vector<int>& array, int size, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && array[left] > array[largest]) {
        largest = left;
    }

    if (right < size && array[right] > array[largest]) {
        largest = right;
    }

    if (largest != i) {
        std::swap(array[i], array[largest]);

        heapify(array, size, largest);
    }
}

void heap_sort(std::vector<int>& array, int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(array, size, i);
    }

    for (int i = size - 1; i > 0; i--) {
        std::swap(array[0], array[i]);

        heapify(array, i, 0);
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
    heap_sort(array, array_size);
    print_array(array, array_size);

    return 0;
}

