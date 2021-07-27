#include <stdio.h>
#include "color.h"

static int clamp(int n);
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

static int clamp(int n) {
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