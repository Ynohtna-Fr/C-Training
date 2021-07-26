#include <stdio.h>
#include "color.c"

void C_print(struct Color c);

int main() {
    Color selectedColor;
    selectedColor.red = 255;
    selectedColor.green = 255;
    selectedColor.blue = 255;

    printf("Hello, World!\n");

    C_print(selectedColor);
    return 0;
}

void C_print(struct Color c) {
    printf("(%d, %d, %d)", c.red, c.green, c.blue);
}