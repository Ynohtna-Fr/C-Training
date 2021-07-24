#include <stdio.h>
#include <stdlib.h>
typedef struct Personnes Personnes;

struct Personnes {
    char nom[100];
    char prenom[100];
};

int main() {
    Personnes utilisateurs[2];

    for (int i = 0; i < 2; i++) {
        printf("Merci de rentrer votre nom joueur : %d \n", i);
        scanf("%s", utilisateurs[i].nom);
        printf("Merci de rentrer votre prenom joueur : %d \n", i);
        scanf("%s", utilisateurs[i].prenom);
        printf("Bienvenue %s %s !", utilisateurs[i].nom, utilisateurs[i].prenom);
    }
    return 0;
}
