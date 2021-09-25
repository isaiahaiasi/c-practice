#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// QUICKSORT
// - pick an index of array (in this case, last)
// - partition around that "pivot" index:
//      - everything less -> left, greater -> right
//      - this step should be O(n)
// - repeat for each remaining half of the array

void quicksort(double arr[], int l, int r);
int partition(double arr[], int l, int r);
void swap(double arr[], int i, int j);
bool testsort(double arr[], int len);
void printarr(double arr[], int len);

void quicksort(double arr[], int l, int r) {
    if (l < r) {
        // pi = partition index
        int pi = partition(arr, l, r);
        quicksort(arr, l, pi - 1);
        quicksort(arr, pi + 1, r);
    }
}

void swap(double arr[], int i, int j) {
    double tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

int partition(double arr[], int l, int r) {
    double pivot = arr[r];
    int i = l - 1;
    for (int j = l; j <= r; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr, i, j);
        }
    }
    return i;
}

void printarr(double arr[], int len) {
    for (int i = 0; i < len; i++) {
        printf("[%d] - %f\n", i, arr[i]);
    }
}

bool testsort(double arr[], int len) {
    double a = arr[0];
    for (int i = 1; i < len; i++) {
        if (a > arr[i]) {
            return false;
        }
    }
    return true;
}

int main(void) {
    double arr[] = {
        [0] = 10, [1] = 100, [2] = 2.5, [3] = 55, [4] = 40, [5] = 50, [6] = 35};

    double arr2[] = {[0] = 2.015, [1] = 27.20, [2] = 0.012};
    // partition(arr, 0, 6);
    quicksort(arr, 0, 6);
    quicksort(arr2, 0, 2);
    printf("test array 1: Sorted? - %d\n", testsort(arr, 7));
    printf("test array 1: Sorted? - %d\n", testsort(arr2, 3));

    return EXIT_SUCCESS;
}
