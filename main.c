#include <stdio.h>
#include "color.c"

void C_print(Color c);
Color C_new(int r, int g, int b);
int clamp(int n);
Color C_multiply(Color c, float coef);
Color C_negative(Color c);
Color C_permute(Color c);
int C_intensity(Color c);
Color C_grayScale(Color c);
int C_threshold(Color c, int th);

int main() {
    Color selectedColor = C_new(255,25,0);
    Color multipliedColor = C_grayScale(selectedColor);
    int threshold = C_threshold(selectedColor, 93);

    printf("Threshold : %d \n", threshold);

    C_print(multipliedColor);
    return 0;
}

void C_print(Color c) {
    printf("(%d, %d, %d)", c.red, c.green, c.blue);
}

Color C_new(int r, int g, int b) {
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

Color C_multiply(Color c, float coef) {
    Color tmp;
    tmp.red = clamp(c.red * coef);
    tmp.green = clamp(c.green * coef);
    tmp.blue = clamp(c.blue * coef);

    return tmp;
}

Color C_negative(Color c) {
    Color tmp;
    tmp.red = 255 - c.red;
    tmp.green = 255 - c.green;
    tmp.blue = 255 - c.blue;

    return tmp;
}

Color C_permute(Color c) {
    Color tmp = {c.green, c.blue, c.red};
    return tmp;
}

int C_intensity(Color c) {
    return (c.red + c.green + c.blue) / 3;
}

Color C_grayScale(Color c) {
    int intensity = C_intensity(c);
    Color tmp = {intensity, intensity, intensity};
    return tmp;
}

int C_threshold(Color c, int th) {
    if (C_intensity(c) > th) {
        return 255;
    }

    return 0;
}