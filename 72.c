char repeatedCharacter(char* s) {
    int freq[26] = {0};  // for 'a' to 'z'

    for (int i = 0; s[i] != '\0'; i++) {
        int index = s[i] - 'a';

        freq[index]++;

        // if character appears second time → return it
        if (freq[index] == 2) {
            return s[i];
        }
    }

    return '\0'; // in case no repetition (though problem guarantees one)
}
