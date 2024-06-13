#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// void affiche_vache_normale() {
//     printf("        \\   ^__^\n");
//     printf("         \\  (oo)\\_______\n");
//     printf("            (__)\\       )\\/\\\n");
//     printf("                ||----w |\n");
//     printf("                ||     ||\n");
// }

// void affiche_vache_avec_cou_en_bas() {
//     printf("        \\      \n");
//     printf("        \\       ________\n");
//     printf("           ^__^/        )\\/\\\n");
//     printf("           (--)/||----w |\n");
//     printf("           (__) ||     ||\n");
//     printf("                         \n")
// }

void update() {
    printf("\033[H\033[J");
}

void gotoxy(int x, int y) {
    printf("\033[%d;%dH", x, y);
}

void affiche_vache_normale(char* eyes, char* tongue, int tail) {
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

void affiche_vache_avec_cou_en_bas(char* eyes, char* tongue, int tail) {
    printf("       \\       \n");
    printf("        \\       ________\n");

    if (tail != 0) {
        printf("           ^__^/        )");
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
        printf("           ^__^/        )\\/\\\n");
    }
    if (eyes != NULL) {
        printf("           (%s)/||----w |\n", eyes);
    } else {
        printf("           (--)/||----w |\n");
    }
    if (tongue != NULL) {
        printf("           (__) ||     ||\n");
        printf("            %s           \n", tongue);
    } else {
        printf("           (__) ||     ||\n");
        printf("                         \n");
    }
}


int main() {
    char* eyes_open = "oo";
    char* eyes_closed = "--";
    int blink_interval = 2; // intervalle en secondes entre chaque clignement
    int tail_length = 0;
    char* tongue = NULL;
    char *tongue_out = "U";

    int x = 0; // position x de la vache
    int y = 0; // position y de la vache
    int dir = 1; // direction de la marche, 1 = droite, -1 = gauche

    while (1) {
        update();

        // affiche la vache à la position courante
        gotoxy(x, y);
        if (dir == 1) {
            affiche_vache_normale(eyes_open, tongue , tail_length);
        } else {
            affiche_vache_avec_cou_en_bas(eyes_open, tongue , tail_length);
        }

        fflush(stdout); // vide le buffer de sortie pour que l'affichage soit immédiat
        sleep(blink_interval);

        // efface la vache à la position courante
        gotoxy(x, y);
        printf("                     ");

        // met à jour la position de la vache
        x += dir;
        if (x == 80 || x == 0) {
            dir = -dir;
        }

        // change la direction du regard de la vache
        if (x % 10 == 0) {
            eyes_open = NULL;
        } else {
            eyes_open = "oo";
        }

        update();

        // affiche la vache à la nouvelle position avec le cou baissé et les yeux fermés
        gotoxy(x, y);
        affiche_vache_avec_cou_en_bas(eyes_closed, tongue_out , tail_length);

        fflush(stdout);
        sleep(blink_interval);

        // efface la vache à la position courante
        gotoxy(x, y);
        printf("                     ");

        // remet les yeux et le cou à leur position normale
        eyes_open = "oo";
    }

    return 0;
}