#ifndef COLOR
#define COLOR

typedef struct Color Color;
struct Color {
    int red, green, blue;
};

void C_print(Color c);
Color C_new(int r, int g, int b);
Color C_multiply(Color c, float coef);
Color C_negative(Color c);
Color C_permute(Color c);
int C_intensity(Color c);
Color C_grayScale(Color c);
int C_threshold(Color c, int th);

#endif