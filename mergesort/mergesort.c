/* MERGESORT */
/*
 * 1. find the middlepoint & divide array in 2 halves
 * 2. call mergesort for the first half
 * 3. call mergesort for the second half
 * 4. merge the two halves sorted in step 2 & 3
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// declarations
void printarray(double arr[], int len);
void merge(double arr[], int l, int r);
void mergesort(double arr[], int l, int r);

void merge(double arr[], int l, int r) {
    int len = r - l + 1;
    int m = (len + 1) / 2; // find middle of unsorted tmp_arr
    int i = 0;             // l-side placement counter
    int j = m;             // r-side placement tracker

    // temp array to hold unsorted result
    double tmp_arr[len];
    for (int t = 0; t < len; ++t) {
        tmp_arr[t] = arr[l + t];
    }

    // compare the current iteration for each half, pick the biggest.
    // if one side has reached the end, insert the remaining from the other side
    for (int k = l; k < r + 1; k++) {
        double insert;
        if (i < m && j < len) {
            if (tmp_arr[i] < tmp_arr[j]) {
                insert = tmp_arr[i];
                i++;
            } else {
                insert = tmp_arr[j];
                j++;
            }
        } else if (i < m) {
            insert = tmp_arr[i];
            i++;
        } else {
            insert = tmp_arr[j];
            j++;
        }

        arr[k] = insert;
    }
}

void mergesort(double arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);
        merge(arr, l, r);
    }
}

void printarray(double arr[], int len) {
    for (int i = 0; i < len; i++) {
        printf("\t[%d] %f\n", i, arr[i]);
    }
}

bool testarray(double arr[], int len) {
    double n = arr[0];
    for (int i = 1; i < len; i++) {
        if (arr[i] < n) {
            return false;
        }
        n = arr[i];
    }
    return true;
}

int main(void) {
    double my_arr[5] = {
        [0] = 9.0, [1] = 2.0, [2] = 5.3, [3] = 1.2, [4] = 6.1,
    };

    mergesort(my_arr, 0, 4);
    printf("IS SORTED: %d\n", testarray(my_arr, 5));
    return EXIT_SUCCESS;
}
