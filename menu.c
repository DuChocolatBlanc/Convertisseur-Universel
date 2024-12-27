#include <stdio.h>
#include "menu.h"
#include "conversion.h"

void display_menu() {
    printf("=== Convertisseur Universel ===\n");
    printf("1. Convertir des longueurs\n");
    printf("2. Convertir des températures\n");
    printf("3. Convertir des devises\n");
    printf("4. Quitter\n");
    printf("Choisissez une option : ");
}

void handle_conversion(int choice) {
    double value;
    switch (choice) {
        case 1: {
            int sub_choice;
            printf("\n--- Convertir des Longueurs ---\n");
            printf("1. Mètres -> Kilomètres\n");
            printf("2. Kilomètres -> Miles\n");
            printf("3. Pouces -> Centimètres\n");
            printf("4. Centimètres -> Pouces\n");
            printf("Choisissez une option : ");
            scanf("%d", &sub_choice);
            printf("Entrez la valeur : ");
            scanf("%lf", &value);
            if (sub_choice == 1) {
                printf("%.2f mètres = %.2f kilomètres\n", value, meters_to_kilometers(value));
            } else if (sub_choice == 2) {
                printf("%.2f kilomètres = %.2f miles\n", value, kilometers_to_miles(value));
            } else if (sub_choice == 3) {
                printf("%.2f pouces = %.2f centimètres\n", value, inches_to_centimeters(value));
            } else if (sub_choice == 4) {
                printf("%.2f centimètres = %.2f pouces\n", value, centimeters_to_inches(value));
            } else {
                printf("Choix invalide.\n");
            }
            break;
        }
        case 2: {
            int sub_choice;
            printf("\n--- Convertir des Températures ---\n");
            printf("1. Celsius -> Fahrenheit\n");
            printf("2. Fahrenheit -> Celsius\n");
            printf("3. Celsius -> Kelvin\n");
            printf("4. Kelvin -> Celsius\n");
            printf("Choisissez une option : ");
            scanf("%d", &sub_choice);
            printf("Entrez la valeur : ");
            scanf("%lf", &value);
            if (sub_choice == 1) {
                printf("%.2f °C = %.2f °F\n", value, celsius_to_fahrenheit(value));
            } else if (sub_choice == 2) {
                printf("%.2f °F = %.2f °C\n", value, fahrenheit_to_celsius(value));
            } else if (sub_choice == 3) {
                printf("%.2f °C = %.2f K\n", value, celsius_to_kelvin(value));
            } else if (sub_choice == 4) {
                printf("%.2f K = %.2f °C\n", value, kelvin_to_celsius(value));
            } else {
                printf("Choix invalide.\n");
            }
            break;
        }
        case 3: {
            char from_currency[4], to_currency[4];
            printf("\n--- Convertir des Devises ---\n");
            printf("Entrez la devise source (par ex. EUR) : ");
            scanf("%s", from_currency);
            printf("Entrez la devise cible (par ex. USD) : ");
            scanf("%s", to_currency);
            printf("Entrez le montant : ");
            scanf("%lf", &value);
            double result = convert_currency(value, from_currency, to_currency);
            if (result >= 0) {
                printf("%.2f %s = %.2f %s\n", value, from_currency, result, to_currency);
            }
            break;
        }
        case 4:
            printf("Au revoir !\n");
            break;
        default:
            printf("Choix invalide. Veuillez réessayer.\n");
    }
}
