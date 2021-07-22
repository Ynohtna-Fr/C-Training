#include <stdio.h>
#include <stdlib.h>

void maxTableau(int tableau[], int tailleTableau, int max);

int main() {
    int max = 4;
    int tailleTableau = 2;
    int tableau[2] = {1, 20};

    maxTableau(tableau, tailleTableau, max);

    for (int i = 0; i < tailleTableau; i++) {
         printf("%d \n", tableau[i]);
    }

    return 0;
}

void maxTableau(int tableau[], int tailleTableau, int max) {

    for (int i = 0; i < tailleTableau; i++) {
        if (tableau[i] > max) {
            tableau[i] = 0;
        }
    }

}