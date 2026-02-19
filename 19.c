#include <stdio.h>

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[1000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Sort array
    qsort(arr, n, sizeof(int), cmp);
    
    // Two pointers to find closest sum to zero
    int left = 0, right = n - 1;
    int closest_sum = arr[0] + arr[n-1];
    int best_left = 0, best_right = n-1;
    
    while (left < right) {
        int curr_sum = arr[left] + arr[right];
        
        // Update if closer to zero
        if (abs(curr_sum) < abs(closest_sum)) {
            closest_sum = curr_sum;
            best_left = left;
            best_right = right;
        }
        
        // Move pointers based on sum
        if (curr_sum < 0) {
            left++;
        } else if (curr_sum > 0) {
            right--;
        } else {
            // Exact zero found
            printf("%d %d\n", arr[left], arr[right]);
            return 0;
        }
    }
    
    // Print the pair (original order doesn't matter per problem)
    printf("%d %d\n", arr[best_left], arr[best_right]);
    
    return 0;
}
