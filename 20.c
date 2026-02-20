#include <stdio.h>

int main() {
    int n, count = 0;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i < n; i++) {
        int sum = 0;

        for(int j = i; j < n; j++) {
            sum += arr[j];

            if(sum == 0) {
                count++;
            }
        }
    }

    printf("Number of zero sum subarrays = %d\n", count);

    return 0;
}