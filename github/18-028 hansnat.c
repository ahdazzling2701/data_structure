
#include <stdio.h>

// Function prototypes
int linearSearch(int arr[], int n, int key);
void bubbleSort(int arr[], int n);
int binarySearch(int arr[], int low, int high, int key);
void insertionSort(int arr[], int n);

int main() {
    int choice, key, result;

    int arr[50] = {9, 5, 7, 3, 1, 8, 6, 2, 4, 0};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("1. Linear Search\n");
    printf("2. Bubble Sort\n");
    printf("3. Binary Search\n");
    printf("4. Insertion Sort\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the element to search: ");
            scanf("%d", &key);
            result = linearSearch(arr, size, key);
            if (result != -1)
                printf("Element found at index %d\n", result);
            else
                printf("Element not found\n");
            break;

        case 2:
            bubbleSort(arr, size);
            printf("Array after Bubble Sort:\n");
            for (int i = 0; i < size; i++)
                printf("%d ", arr[i]);
            printf("\n");
            break;

        case 3:
            printf("Enter the element to search: ");
            scanf("%d", &key);
            result = binarySearch(arr, 0, size - 1, key);
            if (result != -1)
                printf("Element found at index %d\n", result);
            else
                printf("Element not found\n");
            break;

        case 4:
            insertionSort(arr, size);
            printf("Array after Insertion Sort:\n");
            for (int i = 0; i < size; i++)
                printf("%d ", arr[i]);
            printf("\n");
            break;

        default:
            printf("Invalid choice\n");
    }

    return 0;
}

// Linear search function
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

// Bubble sort function
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Binary search function
int binarySearch(int arr[], int low, int high, int key) {
    if (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;

        if (arr[mid] > key)
            return binarySearch(arr, low, mid - 1, key);

        return binarySearch(arr, mid + 1, high, key);
    }

    return -1;
}

// Insertion sort function
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
