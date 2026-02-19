#include <stdio.h>
#include <stdbool.h>

int main() {
    int rows, cols;

    // 1. Input dimensions
    printf("Enter rows and columns: ");
    scanf("%d %d", &rows, &cols);

    // Condition 1: Must be square
    if (rows != cols) {
        printf("Not a square matrix, so it cannot be symmetric.\n");
        return 0;
    }

    int matrix[rows][cols];
    bool isSymmetric = true;

    // 2. Input matrix elements
    printf("Enter matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

   
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < i; j++) { 
            if (matrix[i][j] != matrix[j][i]) {
                isSymmetric = false;
                break;
            }
        }
        if (!isSymmetric) break;
    }

   
    if (isSymmetric) {
        printf("The matrix is Symmetric.\n");
    } else {
        printf("The matrix is Not Symmetric.\n");
    }

    return 0;
}