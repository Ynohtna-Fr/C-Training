#include <stdio.h>
#include <stdlib.h>

void copyTableau(int tableauBase[], int tailleTableau, int newTableau[]);

int main() {
    int tailleTableau = 2;
    int tableau[2] = {10, 20};
    int newTableau[2] = {0};

    copyTableau(tableau, tailleTableau, newTableau);

    for (int i = 0; i < tailleTableau; i++) {
         printf("%d \n", newTableau[i]);
    }

    return 0;
}

void copyTableau(int tableauBase[], int tailleTableau, int newTableau[]) {

    for (int i = 0; i < tailleTableau; i++) {
        newTableau[i] = tableauBase[i];
    }

}