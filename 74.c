#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* winner(char** votes, int votesSize) {
    if (votesSize == 0) return "";
    
    // Use map-like approach: sort to group same names
    // But since C lacks hashmap, naive O(n^2) count works for typical constraints
    
    int max_votes = 0;
    char* winner_name = votes[0];
    
    for (int i = 0; i < votesSize; i++) {
        int count = 0;
        for (int j = 0; j < votesSize; j++) {
            if (strcmp(votes[i], votes[j]) == 0) {
                count++;
            }
        }
        
        if (count > max_votes || 
            (count == max_votes && strcmp(votes[i], winner_name) < 0)) {
            max_votes = count;
            winner_name = votes[i];
        }
    }
    
    // Return duplicate since char* param
    char* result = malloc(strlen(winner_name) + 1);
    strcpy(result, winner_name);
    return result;
}
