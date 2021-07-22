#include <stdio.h>
#include <stdlib.h>

float moyenneTableau(const int tableau[], int tailleTableau);

int main() {
    float tableResult = 0;
    int tableau[2] = {10, 20};

    tableResult = moyenneTableau(tableau, 2);
    printf("la moyenne du tableau est : %f", tableResult);

    return 0;
}

float moyenneTableau(const int tableau[], int tailleTableau) {
    float result = 0;

    for (int i = 0; i < tailleTableau; i++) {
        result += tableau[i];
    }

    return result / tailleTableau;
}