#include <stdio.h>

int main() {
    int p, q;

   
    printf("Enter number of entries in Log 1: ");
    scanf("%d", &p);
    int log1[p];
    printf("Enter Log 1 entries: ");
    for (int i = 0; i < p; i++) scanf("%d", &log1[i]);

   
    printf("Enter number of entries in Log 2: ");
    scanf("%d", &q);
    int log2[q];
    printf("Enter Log 2 entries: ");
    for (int i = 0; i < q; i++) scanf("%d", &log2[i]);

    int combined[p + q];
    int i = 0, j = 0, k = 0;

  
    while (i < p && j < q) {
        if (log1[i] < log2[j]) {
            combined[k++] = log1[i++];
        } else {
            combined[k++] = log2[j++];
        }
    }

   
    while (i < p) combined[k++] = log1[i++];

  
    while (j < q) combined[k++] = log2[j++];

    
    printf("Combined Chronological Log: ");
    for (int x = 0; x < p + q; x++) {
        printf("%d ", combined[x]);
    }
    printf("\n");

    return 0;
}