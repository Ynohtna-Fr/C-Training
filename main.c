#include <stdio.h>
#include <string.h>
#include <ctype.h>

char readLetter();
void arrayPush(char *array, int length, char value);
char printHint(char result[], char letters[]);

int main() {
    char result[] = "PIZZA";
    int errorLeft = 10; // number of error before the use lose
    char rightLetters[4] = {0}; // this table store each good answer
    int status = 0; // Status of the game : 0 not ended, 1 ended;
    char lastLetter[] = ""; // the last letter the user prompt

    printf("Le pendu !\n"
           "VOici le mot initial :\n");
    printHint(result, rightLetters);

    do {
        printf("\n Rentre une lettre : ");
        lastLetter[0] = readLetter();

        if (strchr(result, lastLetter[0])) {
            printf("Ohhhh, c'est une bonne lettre ! Voici le mot : \n");
            arrayPush(rightLetters, 4, lastLetter[0]);
        } else {
            printf("OUCH, dommage !");
            errorLeft -= 1;
        }

        status = (unsigned char)printHint(result, rightLetters);

        if (status) {
            printf("\n Felicitation, tu as termine le jeux ! :)");
        } else {
            printf("\n Il te reste %d coups ! \n", errorLeft);
        }
    } while (!status);

    return 0;
}

char readLetter() {
    char letter = 0;
    letter = getchar();
    letter = toupper(letter);

    while (getchar() != '\n');

    return letter;
}

// push data at the end of the array;
void arrayPush(char *array, int length, char value) {
    for (int i = 0; i < length; i++) {
        if (array[i] == 0) {
            array[i] = value;
            break;
        }
    }
}

// this will print the hint message. And return if they got all letters.
char printHint(char result[], char letters[]) {
    char asAll = 1;
    for (int i = 0; i < strlen(result); i++) {
        char isFound = 0;

        for (int k = 0; k < (sizeof(letters) / sizeof(letters[0])); k++) {
            if (result[i] == letters[k]) {
                isFound = 1;
                break;
            }
        }

        if (isFound) {
            printf("%c", result[i]);
        } else {
            asAll = 0;
            printf("*");
        }
    }

    return asAll;
}