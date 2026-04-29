#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort (ascending order)
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Function to check if we can place k cows with at least 'dist' distance apart
// Returns 1 (true) if possible, 0 (false) otherwise
int canPlaceCows(int stalls[], int n, int k, int dist) {
    int cowsPlaced = 1;           // Place first cow in the first stall
    int lastPosition = stalls[0];
    
    for (int i = 1; i < n; i++) {
        // If current stall is at least 'dist' away from last cow placement
        if (stalls[i] - lastPosition >= dist) {
            cowsPlaced++;
            lastPosition = stalls[i];
            
            // If we've placed all k cows, return true
            if (cowsPlaced >= k) {
                return 1;
            }
        }
    }
    return 0;
}

// Main function to find the maximum possible minimum distance
int maxMinDistance(int stalls[], int n, int k) {
    // Step 1: Sort the stall positions
    qsort(stalls, n, sizeof(int), compare);
    
    // Step 2: Binary search on the answer
    int left = 1;                                    // Minimum possible distance
    int right = stalls[n - 1] - stalls[0];           // Maximum possible distance
    int result = 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        // Check if we can place k cows with at least 'mid' distance apart
        if (canPlaceCows(stalls, n, k, mid)) {
            result = mid;        // This distance works, try for larger
            left = mid + 1;
        } else {
            right = mid - 1;     // This distance doesn't work, try smaller
        }
    }
    
    return result;
}

int main() {
    int n, k;
    
    // Input: number of stalls
    printf("Enter number of stalls: ");
    scanf("%d", &n);
    
    // Input: stall positions
    int *stalls = (int*)malloc(n * sizeof(int));
    printf("Enter stall positions (space-separated): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &stalls[i]);
    }
    
    // Input: number of cows
    printf("Enter number of cows: ");
    scanf("%d", &k);
    
    // Validate input
    if (k > n) {
        printf("Error: Cannot place %d cows in %d stalls!\n", k, n);
        free(stalls);
        return 1;
    }
    
    // Find and print the result
    int result = maxMinDistance(stalls, n, k);
    printf("The maximum possible minimum distance between cows is: %d\n", result);
    
    free(stalls);
    return 0;
}
