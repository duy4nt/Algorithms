#include <iostream>
#include <vector>

void merge(std::vector<int>& array, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    std::vector<int> L(n1);
    std::vector<int> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = array[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = array[middle + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        }
        else {
            array[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(std::vector<int>& array, int left, int right) {
    if (left >= right) {
        return;
    }

    int middle = left + (right - left) / 2;

    merge_sort(array, left, middle);
    merge_sort(array, middle + 1, right); 

    merge(array, left, middle, right);

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
    merge_sort(array, 0, array_size - 1);
    print_array(array, array_size);

    return 0;
}

