#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// @author  Aulminite
// @date    March 6, 2025
// @brief   This program is designed to convert strings to ascii, or ascii to string.

// Function to convert a string of ASCII values to characters
void convert_to_characters(char* input) {
    int ascii_value;
    char* token = strtok(input, " ");
    
    while (token != NULL) {
        ascii_value = atoi(token);  // Convert the string to an integer (ASCII value)
        printf("%c", (char)ascii_value);  // Print the corresponding character
        token = strtok(NULL, " ");
    }
    printf("\n");
}

// Function to convert a string to ASCII values
void convert_to_ascii(char* str) {
    for (int i = 0; i < strlen(str); i++) {
        printf("%d ", str[i]);  // Print the ASCII value of each character
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    // Check for the correct number of arguments
    if (argc < 2) {
        printf("Usage: %s <string or space-separated ASCII values>\n", argv[0]);
        return 1;
    }

    // Case 1: If 2 arguments are given, convert string to ASCII values (like 'ascii')
    if (argc == 2) {
        convert_to_ascii(argv[1]);  // Convert the input string to ASCII values
    }
    // Case 2: If more than 2 arguments, assume they are space-separated ASCII values (like 'asciir')
    else {
        // Combine all arguments into a single string with spaces
        char input[1024] = "";
        for (int i = 1; i < argc; i++) {
            strcat(input, argv[i]);
            if (i < argc - 1) {
                strcat(input, " ");  // Add spaces between arguments
            }
        }

        // Convert the space-separated ASCII values to characters
        convert_to_characters(input);
    }

    return 0;
}
