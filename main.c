#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

char readLetter();
void arrayPush(char *array, size_t length, char value);
char printHint(char result[], const char letters[]);
void initGame(char **result, char **rightLetters);

int main() {
    srand(time(0));
    char *result = NULL;
    char *rightLetters = NULL; // this table store each good answer
    int errorLeft = 10; // number of error before the use lose
    int status = 0; // Status of the game : 0 not ended, 1 ended;
    char lastLetter[] = ""; // the last letter the user prompt

    initGame(&result, &rightLetters);

    printf("Le pendu !\n"
           "VOici le mot initial :\n");

    printHint(result, rightLetters);

    do {
        printf("\n Rentre une lettre : ");
        lastLetter[0] = readLetter();

        if (strchr(result, lastLetter[0])) {
            printf("Ohhhh, c'est une bonne lettre ! Voici le mot : \n");
            arrayPush(rightLetters, strlen(result),  lastLetter[0]);
        } else {
            printf("OUCH, dommage !");
            errorLeft -= 1;
        }

        status = (unsigned char)printHint(result, rightLetters);

        if (status) {
            printf("\n Felicitation, tu as termine le jeux ! :)");
        } else if (errorLeft == 0) {
            printf("\n Tu as perdu ! Le resultat est : \n");
            printf("%s", result);
            status = 1;
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
void arrayPush(char *array, size_t length, char value) {
    printf("%d", length);
    for (int i = 0; i < length; i++) {
        if (array[i] == 0) {
            array[i] = value;
            break;
        }
    }
}

// this will print the hint message. And return if they got all letters.
char printHint(char result[], const char letters[]) {
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

void initGame(char **result, char **rightLetters) {
    int lineNumber = 0;
    int randomLine = 0;
    char randomText[26] = {""};
    char buf[26];
    FILE *file = NULL;
    file = fopen("dictionary.txt", "r+");

    if (file == NULL) {
        printf("ERROR");
        return;
    }

    while (fgets(buf, sizeof buf, file) != NULL) {
        lineNumber++;
    }
    rewind(file);

    randomLine = rand() % (lineNumber + 1);
    printf("\n randomLine = %d \n", randomLine);

    lineNumber = 0;
    while (fgets(buf, sizeof buf, file) != NULL) {
        if (lineNumber == randomLine) {
            sscanf(buf,"%s \n", randomText);
            break;
        }
        lineNumber++;
    }

    *result = calloc(strlen(randomText) + 1, sizeof(char));
    *rightLetters = calloc(strlen(randomText) + 2, sizeof(char));
    strcpy(*result, randomText);
}