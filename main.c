#include <stdio.h>
#include "menu.h"

int main() {
    int choice;

    do {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                convert_length();
                break;
            case 2:
                convert_temperature();
                break;
            case 3:
                convert_currency();
                break;
            case 4:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }

        printf("\n"); // Ajoute un saut de ligne pour séparer les interactions
    } while (choice != 4);

    return 0;
}
