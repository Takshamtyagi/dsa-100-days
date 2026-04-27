#include <stdio.h>

// Function to find integer square root using Binary Search
int mySqrt(int x) {
    if (x == 0) return 0;
    
    long left = 1;
    long right = x;
    int ans = 0;
    
    while (left <= right) {
        long mid = left + (right - left) / 2;
        
        if (mid * mid <= x) {
            ans = (int)mid;      // This is a valid candidate
            left = mid + 1;      // Try larger values
        } else {
            right = mid - 1;     // Try smaller values
        }
    }
    
    return ans;
}

int main() {
    int x;
    
    // Input from user
    printf("Enter a non-negative integer: ");
    scanf("%d", &x);
    
    // Validate input
    if (x < 0) {
        printf("Error: Number must be non-negative!\n");
        return 1;
    }
    
    // Find and print the square root
    int result = mySqrt(x);
    printf("Integer square root of %d is %d\n", x, result);
    
    return 0;
}
