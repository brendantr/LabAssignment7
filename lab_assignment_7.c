#include <stdio.h>

void bubbleSort(int arr[], int n, int swaps[]) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swaps[arr[j]]++;
                swaps[arr[j+1]]++;
            }
        }
    }
}

void selectionSort(int arr[], int n, int swaps[]) {
    int i, j, min_idx, temp;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) { // Only count swaps if a swap occurs
            temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
            swaps[arr[min_idx]]++; // Update swap count for the swapped elements
            swaps[arr[i]]++;
        }
    }
}


int main() {

    // Arrays to be sorted
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};

    int array1Cpy[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2Cpy[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};

    // size of arrays are both 9
    int size = 9;

    int swaps1[101] = {0}; // Index 0-100 for values 1-100
    int swaps2[101] = {0}; // Index 0-100 for values 1-100
    int swaps3[101] = {0}; // Index 0-100 for values 1-100
    int swaps4[101] = {0}; // Index 0-100 for values 1-100

    /////////////////
    // BUBBLE SORT //
    /////////////////

    printf("array1 bubble sort:\n");

    bubbleSort(array1, size, swaps1);
    
    for (int i = 0; i < size; i++) {
        printf("%d: %d\n", array1[i], swaps1[array1[i]]);
    }
    
    int total_swaps1 = 0;
    
    for (int i = 0; i < 101; i++) {
        total_swaps1 += swaps1[i];
    }
    
    printf("%d\n\n", total_swaps1 / 2);

    printf("array2 bubble sort:\n");

    bubbleSort(array2, size, swaps2);
    
    for (int i = 0; i < size; i++) {
        printf("%d: %d\n", array2[i], swaps2[array2[i]]);
    }
    
    int total_swaps2 = 0;
    
    for (int i = 0; i < 101; i++) {
        total_swaps2 += swaps2[i];
    }
    
    printf("%d\n\n", total_swaps2 / 2);
    

    for(int i = 0; i < size; i++){     /////////////////  
        array1[i] = array1Cpy[i];      // reset arrays /
        array2[i] = array2Cpy[i];      /////////////////
    }
    

    ////////////////////
    // SELECTION SORT //
    ////////////////////

    printf("array1 selection sort:\n");

    selectionSort(array1, size, swaps3);
    
    for (int i = 0; i < size; i++) {
        printf("%d: %d\n", array1[i], swaps3[array1[i]]);
    }
    
    int total_swaps3 = 0;
    
    for (int i = 0; i < 101; i++) {
        total_swaps3 += swaps3[i];
    }
    
    printf("%d\n\n", total_swaps3 / 2);

    printf("array2 selection sort:\n");

    selectionSort(array2, size, swaps4);
    
    for (int i = 0; i < size; i++) {
        printf("%d: %d\n", array2[i], swaps4[array2[i]]);
    }
    
    int total_swaps4 = 0;
    
    for (int i = 0; i < 101; i++) {
        total_swaps4 += swaps4[i];
    }
    
    printf("%d\n\n", total_swaps4 / 2);

    return 0;
}