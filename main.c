#include <stdio.h>
#include <stdlib.h>

void decompteTotal(int *hour, int *mins);

// by defining pointer
//int main() {
//    int hour, mins = 0;
//    int *pointerHour = &hour;
//    int *pointerMin = &mins;
//
//    printf("\n Mins : \n");
//    scanf("%d", &mins);
//
//    decompteTotal(pointerHour, pointerMin);
//
//    printf("%d Heures et %d minutes", hour, mins);
//}

// by reference
int main() {
    int hour, mins = 0;

    printf("\n Mins : \n");
    scanf("%d", &mins);

    decompteTotal(&hour, &mins);

    printf("%d Heures et %d minutes", hour, mins);
}
void decompteTotal(int *hour, int *mins) {
    *hour = *mins / 60;  // 90 / 60 = 1
    *mins = *mins % 60; // 90 % 60 = 30
}