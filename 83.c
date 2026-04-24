#include <stdio.h>

// Function to perform selection sort on an array
// Time Complexity: O(n^2) in all cases (worst, average, best)
// Space Complexity: O(1)
void selectionSort(int arr[], int n) {
    // Iterate through each position i (up to second last element)
    for (int i = 0; i < n - 1; i++) {
        // Assume current i is the index of minimum element
        int min_idx = i;
        
        // Find the actual minimum in the unsorted subarray (from i+1 to n-1)
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;  // Update minimum index if smaller element found
            }
        }
        
        // Swap the minimum element with the first unsorted element
        if (min_idx != i) {
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
    }
}

// Helper function to print the array (useful for testing)
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Test array
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: ");
    printArray(arr, n);
    
    selectionSort(arr, n);
    
    printf("Sorted array: ");
    printArray(arr, n);
    
    return 0;
}
