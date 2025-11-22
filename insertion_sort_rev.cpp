#include <iostream>
#include <vector>

void insertion_sort(std::vector<int>& array, int size) {
	for (int j = size - 2; j >= 0; j--) {
		int key = array[j];
		int i = j + 1;
		while (i < size - 1 && key < array[i]) {
			array[i - 1] = array[i];
			i = i + 1;
		}
		array[i - 1] = key;
	}
}

void output_array(std::vector<int>& array, int size) {
	for (int i = 0; i < size; i++) {
		std::cout << array[i];
	}
}

void input_array(std::vector<int>& array,int size) {
	for (int i = 0; i < size; i++) {
		std::cout << "Input the element at index " << i << ": ";
		std::cin >> array[i];
	}
}

void main() {
	int array_size;
	std::cout << "Input the length of the array: ";
	std::cin >> array_size;

	std::vector<int> array(array_size);

	input_array(array, array_size);
	std::cout << "The array before sorting is: ";
	output_array(array, array_size);
	insertion_sort(array, array_size);
	std::cout << "The array after sorting is: ";
	output_array(array, array_size);
}
