#include <stdio.h>
#include <string.h>

int issubset(char *s, char j) {
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == j) {
            printf("Repetitive found: %c => %c\n", s[i], j);
            return 1;
        } else {
            printf("Not repetitive found: %c => %c\n", s[i], j);
        }
    }
    return 0;
}

int lengthOfLongestSubstring(char* s) {
    int current_max = 0; 
    int max_length = 0;
    int char_index = 0;
    char present_char[100]; 

    if (strlen(s) == 0) {
        return 0;
    } else {
        printf("Size of the string: %ld\n", strlen(s));
        for (int i = 0; i < strlen(s); i++) {
            if (issubset(present_char, s[i]) == 1) {
                printf("Found a repetitive character %c\n", s[i]);
                memset(present_char, '\0', sizeof(present_char)); 
                char_index = 0; 
                current_max = 1; 
            } else {
                present_char[char_index] = s[i];
                printf("Current letter: %c \n", s[i]);
                printf("Present char: %s \n", present_char);
                if (s[i] == s[i - 1] && s[i] == s[i + 1]) {
                    current_max--;
                }
                char_index++;
                current_max++;
                printf("s[i-1] %c: s[i] %c: s[i+1] %c \n", s[i-1], s[i], s[i+1]);
                if (current_max > max_length) {
                    max_length = current_max; 
                }
            }
        }
    }
    return max_length;
}

int main() {
    char name[20] = "abb";
    printf("The largest substring number is: %d\n", lengthOfLongestSubstring(name));
    return 0;
}
