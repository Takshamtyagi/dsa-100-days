#include <stdio.h>
#include <string.h>

int main() {
    char codeName[100];

   
    if (scanf("%s", codeName) != 1) return 0;

    int left = 0;
    int right = strlen(codeName) - 1;

    
    while (left < right) {
       
        char temp = codeName[left];
        codeName[left] = codeName[right];
        codeName[right] = temp;

        left++;
        right--;
    }

  
    printf("%s\n", codeName);

    return 0;
}