#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void affiche_vache(char* eyes, char* tongue, int tail, char* text) {
    int text_len = strlen(text);
    // Affichage de la ligne horizontale supérieure
    printf(" ");
    for (int i = 0; i < text_len + 5; i++) {
        printf("-");
    }
    printf("\n");
    printf("  <%s>\n", text);
    // Affichage de la ligne horizontale inférieure
    printf(" ");
    for (int i = 0; i < text_len + 5; i++) {
        printf("-");
    }
    printf("\n");
    printf("        \\   ^__^\n");

    if (eyes != NULL) {
        printf("         \\  (%s)\\________\n", eyes);
    } else {
        printf("         \\  (oo)\\________\n");
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
        printf("            (__)\\        )\\/\\\n");
    }
    if (tongue != NULL) {
        printf("             %c   ||----w |\n", *tongue);
        printf("                 ||     ||\n");
    } else {
        printf("                  ||----w |\n");
        printf("                ||     ||\n");
    }
}

int main(int argc, char** argv) {
    // Définition des arguments par défaut
    char* eyes = "oo";
    char* tongue = NULL;
    int tail = 0;
    int num_cows = 1; // nombre de vaches à afficher

    FILE* fp;

    if (argc < 2) {
        fp = stdin; // utilise l'entrée standard si aucun fichier n'est spécifié en ligne de commande
    } else {
        fp = fopen(argv[1], "r");
        if (fp == NULL) {
            printf("Erreur lors de l'ouverture du fichier.\n");
            return 1;
        }
    }

    char c;
    char text[100] = "";
    int i = 0;
    while ((c = fgetc(fp)) != EOF) {
        text[i++] = c;
        text[i] = '\0'; // ajoute le caractère dans la chaîne de texte et ajoute le caractère de fin de chaîne
        system("clear"); // Efface l'affichage précédent avant d'afficher la nouvelle vache
        affiche_vache(eyes, &text[i-1], tail, text);
        sleep(1); // Attend 1 seconde avant de lire le prochain caractère
    }
    
    tongue = "  "; // Met la langue à une valeur fixe après la fin de la boucle while
    if (i > 0 && text[i-1] == '\n') {
        i--;
        text[i] = '\0'; // Supprime le caractère de saut de ligne de la chaîne de texte
    }

    system("clear"); // Efface l'affichage précédent avant d'afficher la dernière vache
    affiche_vache(eyes, tongue, tail, text);

    if (fp != stdin) {
        fclose(fp); // ferme le fichier si un fichier a été spécifié en ligne de commande
    }

    return 0;
}


