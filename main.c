#include <stdio.h>
#include "color.c"

void C_print(struct Color c);
struct Color C_new(int r, int g, int b);
int clamp(int n);
struct Color C_multiply(struct Color c, float coef);
struct Color C_negative(struct Color c);

int main() {
    Color selectedColor = C_new(255,25,0);
    Color multipliedColor = C_negative(selectedColor);

    printf("Hello, World!\n");

    C_print(multipliedColor);
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

struct Color C_multiply(struct Color c, float coef) {
    struct Color tmp;
    tmp.red = clamp(c.red * coef);
    tmp.green = clamp(c.green * coef);
    tmp.blue = clamp(c.blue * coef);

    return tmp;
}

struct Color C_negative(struct Color c) {
    struct Color tmp;
    tmp.red = 255 - c.red;
    tmp.green = 255 - c.green;
    tmp.blue = 255 - c.blue;

    return tmp;
}