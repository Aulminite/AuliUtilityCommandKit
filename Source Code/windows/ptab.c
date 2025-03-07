#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// @author  Aulminite
// @date    March 6, 2025
// @brief   This program is designed to report basic info on elements from the periodic table.

// Define a structure to store the periodic table element data
typedef struct {
    int atomic_number;
    char symbol[3];
    char name[20];
    int melting_point;  // in Celsius
    int boiling_point;  // in Celsius
    char natural_state[10];
    char element_type[20];
} Element;

// Define an array of elements in the periodic table (simplified version)
Element elements[] = {
    {1, "H", "Hydrogen", -259, -253, "Gas", "Non-metal"},
    {2, "He", "Helium", -272, -269, "Gas", "Noble Gas"},
    {3, "Li", "Lithium", 180, 1342, "Solid", "Alkali Metal"},
    {4, "Be", "Beryllium", 1287, 2471, "Solid", "Alkaline Earth Metal"},
    {5, "B", "Boron", 2076, 4000, "Solid", "Metalloid"},
    {6, "C", "Carbon", 3550, 4027, "Solid", "Non-metal"},
    {7, "N", "Nitrogen", -210, -196, "Gas", "Non-metal"},
    {8, "O", "Oxygen", -218, -183, "Gas", "Non-metal"},
    {9, "F", "Fluorine", -219, -188, "Gas", "Halogen"},
    {10, "Ne", "Neon", -248, -246, "Gas", "Noble Gas"},
    {11, "Na", "Sodium", 97.8, 883, "Solid", "Alkali Metal"},
    {12, "Mg", "Magnesium", 650, 1090, "Solid", "Alkaline Earth Metal"},
    {13, "Al", "Aluminum", 660, 2470, "Solid", "PostTrans Metal"},
    {14, "Si", "Silicon", 1414, 2900, "Solid", "Metalloid"},
    {15, "P", "Phosphorus", 44.1, 280, "Solid", "Non-metal"},
    {16, "S", "Sulfur", 115, 444.6, "Solid", "Non-metal"},
    {17, "Cl", "Chlorine", -101, -34, "Gas", "Halogen"},
    {18, "Ar", "Argon", -189.3, -185.7, "Gas", "Noble Gas"},
    {19, "K", "Potassium", 63.5, 759, "Solid", "Alkali Metal"},
    {20, "Ca", "Calcium", 842, 1484, "Solid", "Alkaline Earth Metal"},
    {21, "Sc", "Scandium", 1541, 2836, "Solid", "Transition Metal"},
    {22, "Ti", "Titanium", 1668, 3287, "Solid", "Transition Metal"},
    {23, "V", "Vanadium", 1910, 3407, "Solid", "Transition Metal"},
    {24, "Cr", "Chromium", 1907, 2671, "Solid", "Transition Metal"},
    {25, "Mn", "Manganese", 1244, 2095, "Solid", "Transition Metal"},
    {26, "Fe", "Iron", 1538, 2862, "Solid", "Transition Metal"},
    {27, "Co", "Cobalt", 1495, 2927, "Solid", "Transition Metal"},
    {28, "Ni", "Nickel", 1455, 2913, "Solid", "Transition Metal"},
    {29, "Cu", "Copper", 1085, 2562, "Solid", "Transition Metal"},
    {30, "Zn", "Zinc", 419, 907, "Solid", "Transition Metal"},
    {31, "Ga", "Gallium", 29.8, 2204, "Solid", "PostTrans Metal"},
    {32, "Ge", "Germanium", 938, 2833, "Solid", "Metalloid"},
    {33, "As", "Arsenic", 817, 613, "Solid", "Metalloid"},
    {34, "Se", "Selenium", 221, 684, "Solid", "Non-metal"},
    {35, "Br", "Bromine", -7.2, 58.8, "Liquid", "Halogen"},
    {36, "Kr", "Krypton", -157.4, -153.2, "Gas", "Noble Gas"},
    {37, "Rb", "Rubidium", 39.3, 688, "Solid", "Alkali Metal"},
    {38, "Sr", "Strontium", 777, 1382, "Solid", "Alkaline Earth Metal"},
    {39, "Y", "Yttrium", 1526, 3338, "Solid", "Transition Metal"},
    {40, "Zr", "Zirconium", 1855, 4377, "Solid", "Transition Metal"},
    {41, "Nb", "Niobium", 2477, 4744, "Solid", "Transition Metal"},
    {42, "Mo", "Molybdenum", 2623, 4639, "Solid", "Transition Metal"},
    {43, "Tc", "Technetium", 2157, 4265, "Solid", "Transition Metal"},
    {44, "Ru", "Ruthenium", 2334, 4135, "Solid", "Transition Metal"},
    {45, "Rh", "Rhodium", 1964, 3695, "Solid", "Transition Metal"},
    {46, "Pd", "Palladium", 1554, 2963, "Solid", "Transition Metal"},
    {47, "Ag", "Silver", 961.8, 2162, "Solid", "Transition Metal"},
    {48, "Cd", "Cadmium", 321, 767, "Solid", "PostTrans Metal"},
    {49, "In", "Indium", 156.6, 2080, "Solid", "PostTrans Metal"},
    {50, "Sn", "Tin", 231.9, 2602, "Solid", "PostTrans Metal"},
    {51, "Sb", "Antimony", 630.6, 1587, "Solid", "Metalloid"},
    {52, "Te", "Tellurium", 449.5, 988, "Solid", "Metalloid"},
    {53, "I", "Iodine", 113.7, 184.3, "Solid", "Halogen"},
    {54, "Xe", "Xenon", -111.8, -108.1, "Gas", "Noble Gas"},
    {55, "Cs", "Cesium", 28.4, 671, "Solid", "Alkali Metal"},
    {56, "Ba", "Barium", 727, 1640, "Solid", "Alkaline Earth Metal"},
    {57, "La", "Lanthanum", 920, 3464, "Solid", "Lanthanide"},
    {58, "Ce", "Cerium", 798, 3257, "Solid", "Lanthanide"},
    {59, "Pr", "Praseodymium", 931, 3520, "Solid", "Lanthanide"},
    {60, "Nd", "Neodymium", 1010, 3141, "Solid", "Lanthanide"},
    {61, "Pm", "Promethium", 1100, 3000, "Solid", "Lanthanide"},
    {62, "Sm", "Samarium", 1072, 1900, "Solid", "Lanthanide"},
    {63, "Eu", "Europium", 1527, 1597, "Solid", "Lanthanide"},
    {64, "Gd", "Gadolinium", 1312, 3273, "Solid", "Lanthanide"},
    {65, "Tb", "Terbium", 1356, 3230, "Solid", "Lanthanide"},
    {66, "Dy", "Dysprosium", 1412, 2567, "Solid", "Lanthanide"},
    {67, "Ho", "Holmium", 1474, 2720, "Solid", "Lanthanide"},
    {68, "Er", "Erbium", 1529, 2868, "Solid", "Lanthanide"},
    {69, "Tm", "Thulium", 1818, 2223, "Solid", "Lanthanide"},
    {70, "Yb", "Ytterbium", 824, 1196, "Solid", "Lanthanide"},
    {71, "Lu", "Lutetium", 1663, 3315, "Solid", "Lanthanide"},
    {72, "Hf", "Hafnium", 2233, 4603, "Solid", "Transition Metal"},
    {73, "Ta", "Tantalum", 3017, 5458, "Solid", "Transition Metal"},
    {74, "W", "Tungsten", 3422, 5555, "Solid", "Transition Metal"},
    {75, "Re", "Rhenium", 3186, 5596, "Solid", "Transition Metal"},
    {76, "Os", "Osmium", 3045, 5027, "Solid", "Transition Metal"},
    {77, "Ir", "Iridium", 2446, 4130, "Solid", "Transition Metal"},
    {78, "Pt", "Platinum", 1768, 3825, "Solid", "Transition Metal"},
    {79, "Au", "Gold", 1064, 2856, "Solid", "Transition Metal"},
    {80, "Hg", "Mercury", -38.83, 356.73, "Liquid", "Transition Metal"},
    {81, "Tl", "Thallium", 304, 1473, "Solid", "PostTrans Metal"},
    {82, "Pb", "Lead", 327.5, 1749, "Solid", "PostTrans Metal"},
    {83, "Bi", "Bismuth", 271.3, 1564, "Solid", "PostTrans Metal"},
    {84, "Po", "Polonium", 254, 962, "Solid", "Metalloid"},
    {85, "At", "Astatine", 302, 337, "Solid", "Halogen"},
    {86, "Rn", "Radon", -71, -62, "Gas", "Noble Gas"},
    {87, "Fr", "Francium", 27, 680, "Solid", "Alkali Metal"},
    {88, "Ra", "Radium", 700, 1413, "Solid", "Alkaline Earth Metal"},
    {89, "Ac", "Actinium", 1050, 3273, "Solid", "Actinide"},
    {90, "Th", "Thorium", 1750, 4820, "Solid", "Actinide"},
    {91, "Pa", "Protactinium", 1568, 4131, "Solid", "Actinide"},
    {92, "U", "Uranium", 1132, 4131, "Solid", "Actinide"},
    {93, "Np", "Neptunium", 640, 3902, "Solid", "Actinide"},
    {94, "Pu", "Plutonium", 640, 3228, "Solid", "Actinide"},
    {95, "Am", "Americium", 1176, 2870, "Solid", "Actinide"},
    {96, "Cm", "Curium", 1340, 3140, "Solid", "Actinide"},
    {97, "Bk", "Berkelium", 986, 2270, "Solid", "Actinide"},
    {98, "Cf", "Californium", 900, 1470, "Solid", "Actinide"},
    {99, "Es", "Einsteinium", 860, 1600, "Solid", "Actinide"},
    {100, "Fm", "Fermium", 1527, 2607, "Solid", "Actinide"},
    {101, "Md", "Mendelevium", 827, 1100, "Solid", "Actinide"},
    {102, "No", "Nobelium", 827, 1447, "Solid", "Actinide"},
    {103, "Lr", "Lawrencium", 1627, 3327, "Solid", "Actinide"},
    {104, "Rf", "Rutherfordium", 2410, 5500, "Solid", "Transition Metal"},
    {105, "Db", "Dubnium", 2820, 5800, "Solid", "Transition Metal"},
    {106, "Sg", "Seaborgium", 2860, 5165, "Solid", "Transition Metal"},
    {107, "Bh", "Bohrium", 2700, 5000, "Solid", "Transition Metal"},
    {108, "Hs", "Hassium", 2800, 5000, "Solid", "Transition Metal"},
    {109, "Mt", "Meitnerium", 2800, 5000, "Solid", "Transition Metal"},
    {110, "Ds", "Darmstadtium", 2800, 5000, "Solid", "Transition Metal"},
    {111, "Rg", "Roentgenium", 2800, 5000, "Solid", "Transition Metal"},
    {112, "Cn", "Copernicium", 2850, 4700, "Solid", "PostTrans Metal"},
    {113, "Nh", "Nihonium", 313, 1610, "Solid", "PostTrans Metal"},
    {114, "Fl", "Flerovium", 300, 520, "Solid", "PostTrans Metal"},
    {115, "Mc", "Moscovium", 200, 500, "Solid", "PostTrans Metal"},
    {116, "Lv", "Livermorium", 100, 500, "Solid", "PostTrans Metal"},
    {117, "Ts", "Tennessine", 100, 500, "Solid", "Halogen"},
    {118, "Og", "Oganesson", -218, -131, "Gas", "Noble Gas"}
    // Add more elements as needed
};

int num_elements = sizeof(elements) / sizeof(elements[0]);

// Function to find element by atomic number
Element* find_by_atomic_number(int atomic_number) {
    for (int i = 0; i < num_elements; i++) {
        if (elements[i].atomic_number == atomic_number) {
            return &elements[i];
        }
    }
    return NULL;
}

// Function to find element by atomic symbol
Element* find_by_symbol(const char* symbol) {
    for (int i = 0; i < num_elements; i++) {
        if (strcmp(elements[i].symbol, symbol) == 0) {
            return &elements[i];
        }
    }
    return NULL;
}

void print_element_info(Element* element) {
    if (element == NULL) {
        printf("Element not found!\n");
        return;
    }
    
    printf("Element Information:\n");
    printf("Atomic Number: %d\n", element->atomic_number);
    printf("Symbol: %s\n", element->symbol);
    printf("Name: %s\n", element->name);
    printf("Melting Point: %dC\n", element->melting_point);
    printf("Boiling Point: %dC\n", element->boiling_point);
    printf("Natural State: %s\n", element->natural_state);
    printf("Element Type: %s\n", element->element_type);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: /ptab <atomic number or symbol>\n");
        return 1;
    }

    // Get the argument passed (atomic number or symbol)
    char *input = argv[1];

    // Try to process the input as an atomic number (integer)
    int atomic_number = atoi(input);

    Element* element = NULL;

    if (atomic_number > 0) {
        // If input is a valid atomic number, search by number
        element = find_by_atomic_number(atomic_number);
    } else {
        // Otherwise, assume input is a symbol and search by symbol
        element = find_by_symbol(input);
    }

    // Print the element information
    print_element_info(element);

    return 0;
}