#include <iostream>
#include <vector>

int binary_search(const std::vector<int>& array, int target) {
    int left = 0;
    int right = array.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (array[mid] == target) {
            return mid;
        }

        if (array[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return -1;
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
    int target;
    std::cout << "Enter the size of the array: ";
    std::cin >> array_size;

    std::cout << "Enter the target element";
    std::cin >> target;

    std::vector<int> array(array_size);

    input_array(array, array_size);
    print_array(array, array_size);
    int result = binary_search(array, target);

    if (result == -1) {
        std::cout << "Element is not present in the array";
    }
    else
    {
        std::cout << "Element is present at the index " << result;
    }

    return 0;
}

