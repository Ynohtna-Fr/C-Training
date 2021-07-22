#include <stdio.h>
#include <stdlib.h>

void orderTableau(int tableau[], int tailleTableau);

// Exo 5
int main() {
    int tailleTableau = 10;
    int tableau[10] = {20, 10, 5, 7, 50, 80, 1, 2, 6, 3};

    orderTableau(tableau, tailleTableau);

    for (int i = 0; i < tailleTableau; i++) {
        printf("%d \n", tableau[i]);
    }

    return 0;
}

void orderTableau(int tableau[], int tailleTableau) {
    int intermediate;
    for (int k = 0; k < tailleTableau; k++) {
        for (int i = 0; i < tailleTableau; i++) {
            if ((tableau[i] > tableau[i + 1]) && (i != tailleTableau - 1)) {
                intermediate = tableau[i];
                tableau[i] = tableau[i + 1];
                tableau[i + 1] = intermediate;
            }
        }
    }
}