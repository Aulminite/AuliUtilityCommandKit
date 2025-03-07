#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// @author  Aulminite
// @date    March 6, 2025
// @brief   This program is designed to convert si prefixes to eachother along with a value input.

// Function to get the power of 10 for a given SI prefix
int get_prefix_power(const char *prefix) {
    if (strcmp(prefix, "Y") == 0) return 24;  // Yotta
    if (strcmp(prefix, "Z") == 0) return 21;  // Zetta
    if (strcmp(prefix, "E") == 0) return 18;  // Exa
    if (strcmp(prefix, "P") == 0) return 15;  // Peta
    if (strcmp(prefix, "T") == 0) return 12;  // Tera
    if (strcmp(prefix, "G") == 0) return 9;   // Giga
    if (strcmp(prefix, "M") == 0) return 6;   // Mega
    if (strcmp(prefix, "k") == 0) return 3;   // Kilo
    if (strcmp(prefix, "h") == 0) return 2;   // Hecto
    if (strcmp(prefix, "da") == 0) return 1;  // Deka
    if (strcmp(prefix, "b") == 0) return 0;   // No prefix (base unit)
    if (strcmp(prefix, "d") == 0) return -1;  // Deci
    if (strcmp(prefix, "c") == 0) return -2;  // Centi
    if (strcmp(prefix, "m") == 0) return -3;  // Milli
    if (strcmp(prefix, "u") == 0) return -6;  // Micro
    if (strcmp(prefix, "n") == 0) return -9;  // Nano
    if (strcmp(prefix, "p") == 0) return -12; // Pico
    if (strcmp(prefix, "f") == 0) return -15; // Femto
    if (strcmp(prefix, "a") == 0) return -18; // Atto
    if (strcmp(prefix, "z") == 0) return -21; // Zepto
    if (strcmp(prefix, "y") == 0) return -24; // Yocto

    return 0; // Return 0 for unrecognized prefix
}

// Function to convert between SI prefixes
float convert_with_prefix(float value, const char *from_prefix, const char *to_prefix) {
    int from_power = get_prefix_power(from_prefix);
    int to_power = get_prefix_power(to_prefix);

    // Convert value to base unit (SI base unit)
    float value_in_base = value * pow(10, from_power);

    // Convert value from base unit to the target prefix
    return value_in_base / pow(10, to_power);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: unitcv <value> <from_prefix> <to_prefix>\n");
        return 1;
    }

    float value = atof(argv[1]);
    char *from_prefix = argv[2];
    char *to_prefix = argv[3];

    // Perform the conversion
    float converted_value = convert_with_prefix(value, from_prefix, to_prefix);

    // Print the result
    printf("%.6f%s\n", converted_value, to_prefix);

    return 0;
}
