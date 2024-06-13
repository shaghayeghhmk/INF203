#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constantes pour les états de santé de la vache
#define BYEBYELIFE 0
#define LIFESUCKS 1
#define LIFEROCKS 2

// Constantes pour les valeurs minimales et maximales des variables stock et fitness
#define STOCK_MIN 0
#define STOCK_MAX 10
#define FITNESS_MIN 0
#define FITNESS_MAX 10

// Variables globales
int stock = 5;
int fitness = 5;
int duree_de_vie = 0;

// Fonctions pour mettre à jour les variables stock et fitness
int stock_update(int lunchfood) {
    // Met à jour la variable stock en fonction du niveau de forme de la vache et de la quantité de nourriture
    int crop = rand() % 3;
    int digestion = rand() % 3;
    int stock_update = lunchfood - crop - digestion;
    if (stock + stock_update < STOCK_MIN) {
        stock = STOCK_MIN;
    } else if (stock + stock_update > STOCK_MAX) {
        stock = STOCK_MAX;
    } else {
        stock += stock_update;
    }
    return stock_update;
}

int fitness_update(int lunchfood) {
    // Met à jour la variable fitness en fonction du niveau de forme de la vache et de la quantité de nourriture
    int mood = rand() % 3;
    int fitness_update = lunchfood - mood;
    if (fitness + fitness_update < FITNESS_MIN) {
        fitness = FITNESS_MIN;
    } else if (fitness + fitness_update > FITNESS_MAX) {
        fitness = FITNESS_MAX;
    } else {
        fitness += fitness_update;
    }
    return fitness_update;
}

int main() {
    // Initialisation du générateur de nombres aléatoires
    time_t t;
    srand((unsigned) time(&t));
    
    // Boucle principale du jeu
    int etat_sante = LIFEROCKS;
    while (etat_sante != BYEBYELIFE) {
        // Affichage de la vache dans son état actuel
        switch (etat_sante) {
            case BYEBYELIFE:
                printf("La vache est morte. RIP.\n");
                break;
            case LIFESUCKS:
                printf("La vache ne se sent pas bien.\n");
                break;
            case LIFEROCKS:
                printf("La vache est en pleine forme !\n");
                break;
        }
        
        // Affichage de l'état de la variable stock
        printf("Etat de la reserve de nourriture : %d\n", stock);
        
        // Demande de la quantité de nourriture allouée à la vache
        int lunchfood;
        printf("Entrez la quantite de nourriture allouee a la vache : ");
        scanf("%d", &lunchfood);
        while (lunchfood < 0 || lunchfood > stock) {
            printf("Erreur : quantite invalide. Entrez une valeur entre 0 et %d : ", stock);
            scanf("%d", &lunchfood);
        }
        
        // Mise à jour des variables stock et fitness ainsi que des états de la réserve et de la vache
        
        int stock_update_value = stock_update(lunchfood);
        int fitness_update_value = fitness_update(lunchfood);
        // Affichage des mises à jour des variables stock et fitness
        printf("Mise a jour de la reserve de nourriture : %d\n", stock_update_value);
        printf("Mise a jour de la forme de la vache : %d\n", fitness_update_value);
        
        // Mise à jour de l'état de santé de la vache en fonction de ses variables stock et fitness
        if (stock <= 2 || fitness <= 2) {
            etat_sante = BYEBYELIFE;
        } else if (stock <= 5 || fitness <= 5) {
            etat_sante = LIFESUCKS;
        } else {
            etat_sante = LIFEROCKS;
        }
        
        // Incrémentation de la durée de vie de la vache
        duree_de_vie++;
        
        // Affichage de la durée de vie de la vache
        printf("Duree de vie de la vache : %d\n", duree_de_vie);
    }

    // Affichage de la durée de vie de la vache à la fin du jeu
    printf("La vache a vecu %d jours.\n", duree_de_vie);

    return 0;
}

// FIN DU PROGRAMME