#include <stdio.h>

// Helper function to reverse a portion of the array
void reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main() {
    int n, k;
    printf("Enter array size and k: ");
    scanf("%d %d", &n, &k);

    int arr[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    
    k = k % n;

   
    reverse(arr, 0, n - 1);
    
    reverse(arr, 0, k - 1);
    
    reverse(arr, k, n - 1);

    printf("Rotated array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}