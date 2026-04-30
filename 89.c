#include <stdio.h>

// Check function
int isPossible(int arr[], int n, int m, int maxPages) {
    int students = 1;
    int pages = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxPages) return 0;

        if (pages + arr[i] <= maxPages) {
            pages += arr[i];
        } else {
            students++;
            pages = arr[i];
        }

        if (students > m) return 0;
    }

    return 1;
}

// Main function
int allocateBooks(int arr[], int n, int m) {
    if (m > n) return -1;

    int sum = 0, max = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (arr[i] > max) max = arr[i];
    }

    int low = max;
    int high = sum;
    int result = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(arr, n, m, mid)) {
            result = mid;
            high = mid - 1; // try smaller
        } else {
            low = mid + 1;
        }
    }

    return result;
}

// Driver code
int main() {
    int arr[] = {12, 34, 67, 90};
    int n = 4;
    int m = 2;

    int ans = allocateBooks(arr, n, m);
    printf("Minimum pages = %d\n", ans);

    return 0;
}
