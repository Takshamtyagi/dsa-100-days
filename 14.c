#include <stdio.h>
#include <stdbool.h>

int main() {
    int n;

    printf("Enter the size of the square matrix (n x n): ");
    scanf("%d", &n);

    int matrix[n][n];
    bool isIdentity = true;

   
    printf("Enter matrix elements:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                
                if (matrix[i][j] != 1) {
                    isIdentity = false;
                    break;
                }
            } else {
                if (matrix[i][j] != 0) {
                    isIdentity = false;
                    break;
                }
            }
        }
        if (!isIdentity) break;
    }

    
    if (isIdentity) {
        printf("The matrix is an Identity Matrix.\n");
    } else {
        printf("The matrix is NOT an Identity Matrix.\n");
    }

    return 0;
}