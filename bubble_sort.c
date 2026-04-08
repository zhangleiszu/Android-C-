// 你好，这是注释
#include <stdio.h>

void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;  // If no swap happens, array is already sorted.
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void) {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = (int)(sizeof(arr) / sizeof(arr[0]));

    printf("Before sorting: ");
    print_array(arr, n);

    bubble_sort(arr, n);

    printf("After sorting:  ");
    print_array(arr, n);

    return 0;
}
