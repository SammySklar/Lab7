//Samuel Sklar - Lab Assignment 7 - 3/7/24
#include <stdio.h>

void bubbleSort(int arr[], int n, int swaps[], int *totalSwaps) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps[arr[j]]++;
                swaps[arr[j + 1]]++;
                (*totalSwaps)++;
            }
        }
    }
}

void selectionSort(int arr[], int n, int swaps[], int *totalSwaps) {
    int i, j, minIndex, temp;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
            swaps[arr[i]]++;
            swaps[arr[minIndex]]++;
            (*totalSwaps)++;
        }
    }
}

#define ARRAY_SIZE 9

int main() {
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n = ARRAY_SIZE;

    int swaps1[100] = {0}; // Assuming numbers are between 0 and 99
    int swaps2[100] = {0}; // Assuming numbers are between 0 and 99
    int totalSwaps1 = 0;
    int totalSwaps2 = 0;

    bubbleSort(array1, n, swaps1, &totalSwaps1);
    bubbleSort(array2, n, swaps2, &totalSwaps2);

    printf("Array 1 (Bubble Sort):\n");
    printf("Value\tSwaps\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\n", array1[i], swaps1[array1[i]]);
    }
    printf("Total swaps: %d\n", totalSwaps1);

    printf("\nArray 2 (Bubble Sort):\n");
    printf("Value\tSwaps\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\n", array2[i], swaps2[array2[i]]);
    }
    printf("Total swaps: %d\n\n", totalSwaps2);

    // Reset arrays and swaps for selection sort
    for (int i = 0; i < n; i++) {
        array1[i] = 97 - i * 10;
        array2[i] = 90 - i * 10;
    }
    totalSwaps1 = 0;
    totalSwaps2 = 0;
    for (int i = 0; i < 100; i++) {
        swaps1[i] = 0;
        swaps2[i] = 0;
    }

    selectionSort(array1, n, swaps1, &totalSwaps1);
    selectionSort(array2, n, swaps2, &totalSwaps2);

    printf("Array 1 (Selection Sort):\n");
    printf("Value\tSwaps\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\n", array1[i], swaps1[array1[i]]);
    }
    printf("Total swaps: %d\n", totalSwaps1);

    printf("\nArray 2 (Selection Sort):\n");
    printf("Value\tSwaps\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\n", array2[i], swaps2[array2[i]]);
    }
    printf("Total swaps: %d\n", totalSwaps2);

    return 0;
}
