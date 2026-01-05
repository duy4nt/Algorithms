#include <stdio.h>

int getmax(int array[], int len);
void countsort(int array[], int len, int exp);
void radixsort(int array[], int len);
void print(int array[], int len);

main() {
    int arr[];
    int n;

    arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    n = sizeof(arr) / sizeof(arr[0]);

    radixsort(arr, n);
    print(arr, n);
    
    return 0;
}

int getmax(int arr[], int n) {
    int mx = arr[0];
    
    for(int i = 1; i < n; i++) {
        if (arr[i] > mx) {
            mx = arr[i];
        }
    }
    
    return mx;
}

void countsort(int arr[], int n, int exp) {
    int output[n];
    int i, count[10] = {0};

    for (i = 1; i < n; i++) {
        count[i] += count[i-1];
    }

    for (i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void redixsort(int arr[], int n) {
    int m = getmax(arr, n);

    for (int exp = 1; m / exp > 0; exp *= 10) {
        countsort(arr, n, exp);
    }
}

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");
}
