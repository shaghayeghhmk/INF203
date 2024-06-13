#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// exo1
// void affiche_vache() {
//     printf("        \\   ^__^\n");
//     printf("         \\  (oo)\\_______\n");
//     printf("            (__)\\       )\\/\\\n");
//     printf("                ||----w |\n");
//     printf("                ||     ||\n");
// }

// int main() {
//     affiche_vache();
//     return 0;
// }

// exo 2 et 3
void affiche_vache(char* eyes, char* tongue, int tail) {

    printf("        \\   ^__^\n");

    if (eyes != NULL) {
        printf("         \\  (%s)\\_______\n", eyes);
    } else {
        printf("         \\  (oo)\\_______\n");
    }
    if (tail != 0) {
        printf("            (__)\\       )");
        int i;
        for (i = 0; i < tail; i++) {
            if (i % 2 == 0) {
                printf("\\");
            } else {
                printf("/");
            }
        }
        printf("\n");
    } else {
        printf("            (__)\\       )\\/\\\n");
    }
    if (tongue != NULL) {
        printf("             %s  ||----w |\n", tongue);
        printf("                ||     ||\n");
    } else {
        printf("                ||----w |\n");
        printf("                ||     ||\n");
    }
}

int main(int argc, char** argv) {
    // Définition des arguments par défaut
    char* eyes = "oo";
    char* tongue = NULL;
    int tail = 0;
    int num_cows = 1; // nombre de vaches à afficher

    // Boucle pour traiter les arguments de ligne de commande
    int i;
    for (i = 1; i < argc; i++) {
        // "-e" suivi d'une chaîne de caractères pour les yeux de la vache
        if (strcmp(argv[i], "-e") == 0) {
            i++;
            eyes = argv[i];
        // "-T" suivi d'une chaîne de caractères pour la langue de la vache
        } else if (strcmp(argv[i], "-T") == 0) {
            i++;
            tongue = argv[i];
        // "--tail" suivi d'un entier pour la longueur de la queue de la vache
        } else if (strcmp(argv[i], "--tail") == 0) {
            i++;
            tail = atoi(argv[i]);
        // "-b" pour afficher une vache avec des yeux égaux ("==")
        } else if (strcmp(argv[i], "-b") == 0) {
            eyes = "==";
        // "-d" pour afficher une vache avec des yeux en forme de "xx" et une langue "U"
        } else if (strcmp(argv[i], "-d") == 0) {
            eyes = "xx";
            tongue = "U";
        // "-n" suivi d'un entier pour le nombre de vaches à afficher
        } else if (strcmp(argv[i], "-n") == 0) {
            i++;
            num_cows = atoi(argv[i]);
        }
    }
    // Appel de la fonction affiche_vache plusieurs fois avec des arguments différents
    int j;
    for (j = 0; j < num_cows; j++) {
        affiche_vache(eyes, tongue, tail);
    }

    return 0;
}


