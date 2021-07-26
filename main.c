#include <stdio.h>
#include "color.c"

void C_print(struct Color c);
struct Color C_new(int r, int g, int b);
int clamp(int n);

int main() {
    Color selectedColor = C_new(255,255,255);

    printf("Hello, World!\n");

    C_print(selectedColor);
    return 0;
}

void C_print(struct Color c) {
    printf("(%d, %d, %d)", c.red, c.green, c.blue);
}

struct Color C_new(int r, int g, int b) {
    Color c;
    c.red = clamp(r);
    c.green = clamp(g);
    c.blue = clamp(b);

    return c;
}

int clamp(int n) {
    if (n > 255) {
        return 255;
    } else if (n < 0) {
        return 0;
    }

    return n;
}