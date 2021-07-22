#include <stdio.h>
#include <stdlib.h>

int sommeTableau(const int tableau[], int tailleTableau);

int main() {
    int tableResult = 0;
    int tableau[5] = {5,5,5,5,5};

    tableResult = sommeTableau(tableau, 5);
    printf("la somme du tableau est : %d", tableResult);

    return 0;
}

int sommeTableau(const int tableau[], int tailleTableau) {
    int result = 0;

    for (int i = 0; i < tailleTableau; i++) {
        result += tableau[i];
    }

    return result;
}