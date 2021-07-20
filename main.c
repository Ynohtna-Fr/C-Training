#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // var init
    const int MIN = 0;
    const int MAX = 100;
    int retry, gameType = 0;
    int randomNumber, userNumber, round = 0;
    srand(time(NULL));

    do {
        printf("0 : Solo \n"
               "1 : 2 joueurs \n");
        scanf_s("%d", &gameType);

        if (gameType) {
            printf("Rentrez une nombre compris entre 1 et 100 \n");
            scanf_s("%d", &randomNumber);
        } else {
            randomNumber = (rand() % (MAX - MIN + 1)) + MIN;
            printf("%d \n", randomNumber);
        }

        printf("Arriverez vous a trouver le bon nombre ?\n");
        printf("Compris entre 0 et 100\n");

        do {
            round++;
            printf("Nombre :");
            scanf_s("%d", &userNumber);
            printf("\n");
            printf("Coup numero %d : \n", round);
            if (userNumber == randomNumber) {
                printf("Bien joue ! Cetais bien le bon nombre :)\n");
            } else {
                printf("Eh non ! Retente ta chance !\n");
            }
        } while (userNumber != randomNumber);
        printf("On rejoue ?");
        scanf_s("%d", &retry);
        round = 0;
    } while (retry);

    return 0;
}
