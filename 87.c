#include <stdio.h>

int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    
    // Iterative binary search
    while (left <= right) {
        int mid = left + (right - left) / 2;  // Prevents overflow
        
        if (arr[mid] == target) {
            return mid;  // Target found, return index
        } else if (arr[mid] < target) {
            left = mid + 1;  // Search right half
        } else {
            right = mid - 1;  // Search left half
        }
    }
    
    return -1;  // Target not found
}

// Example usage
int main() {
    int arr[] = {2, 4, 7, 10, 15, 23, 42, 56, 89};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 23;
    
    int result = binarySearch(arr, size, target);
    
    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found\n");
    }
    
    return 0;
}
