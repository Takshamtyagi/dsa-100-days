#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char str[100];
    bool isPalindrome = true;

   
    if (scanf("%s", str) != 1) return 0;

    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            isPalindrome = false;
            break; 
        }
        left++;
        right--;
    }

  
    if (isPalindrome) {
        printf("Palindrome\n");
    } else {
        printf("Not a Palindrome\n");
    }

    return 0;
}