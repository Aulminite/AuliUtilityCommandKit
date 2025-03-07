#include <stdio.h>

// @author  Aulminite
// @date    March 6, 2025
// @brief   This program is designed to attempt the printing of color grids using ANSI 16, ANSI 265, and RGB 24-bit methods to test the color space of a terminal.

// Function to print ANSI 16 basic colors
void print_ansi_16_colors() {
    printf("ANSI 16 Colors Test:\n");
    for (int i = 0; i < 16; i++) {
        printf("\033[48;5;%dm\033[38;5;%dm%3d\033[0m ", i, i, i);
        if ((i + 1) % 8 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

// Function to print 256 colors
void print_256_colors() {
    printf("256 Colors Test:\n");
    for (int i = 0; i < 256; i++) {
        printf("\033[48;5;%dm\033[38;5;%dm%3d\033[0m ", i, i, i);
        if ((i + 1) % 16 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

// Function to print RGB 24-bit color values
void print_rgb_colors() {
    printf("RGB 24-bit Colors Test (True Color):\n");
    for (int r = 0; r <= 255; r += 51) {  // Adjust the steps for better readability
        for (int g = 0; g <= 255; g += 51) {
            for (int b = 0; b <= 255; b += 51) {
                printf("\033[48;2;%d;%d;%dm\033[38;2;%d;%d;%dm  RGB(%3d,%3d,%3d)\033[0m ", r, g, b, r, g, b, r, g, b);
            }
            printf("\n");
        }
    }
    printf("\n");
}

// Function to test custom color (using RGB 24-bit)
void print_custom_color() {
    printf("Custom RGB Color Test:\n");
    printf("\033[48;2;255;165;0m\033[38;2;0;0;0m Custom RGB(255, 165, 0) color\033[0m\n");
    printf("\033[48;2;0;255;0m\033[38;2;255;255;255m Custom RGB(0, 255, 0) color\033[0m\n");
    printf("\033[48;2;0;0;255m\033[38;2;255;255;255m Custom RGB(0, 0, 255) color\033[0m\n");
    printf("\n");
}

int main() {
    // Print ANSI 16 basic colors
    print_ansi_16_colors();

    // Print 256 colors
    print_256_colors();

    // Print RGB 24-bit colors (True Color)
    print_rgb_colors();

    // Print custom RGB colors
    print_custom_color();

    return 0;
}
