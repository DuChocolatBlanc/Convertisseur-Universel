#include <stdio.h>
#include "menu.h"
#include "conversion.h"

// Affichage du menu principal
void display_menu() {
    printf("=== Convertisseur Universel ===\n");
    printf("1. Convertir des longueurs\n");
    printf("2. Convertir des températures\n");
    printf("3. Convertir des devises\n");
    printf("4. Quitter\n");
    printf("Choisissez une option : ");
}

// Menu pour les longueurs
void convert_length() {
    int choice;
    double value;

    printf("\n--- Convertir des Longueurs ---\n");
    printf("1. Mètres -> Kilomètres\n");
    printf("2. Kilomètres -> Mètres\n");
    printf("Choisissez une option : ");
    scanf("%d", &choice);

    printf("Entrez la valeur : ");
    scanf("%lf", &value);

    if (choice == 1) {
        printf("%.2f mètres = %.2f kilomètres\n", value, meters_to_kilometers(value));
    } else if (choice == 2) {
        printf("%.2f kilomètres = %.2f mètres\n", value, kilometers_to_meters(value));
    } else {
        printf("Choix invalide.\n");
    }
}

// Menu pour les températures
void convert_temperature() {
    int choice;
    double value;

    printf("\n--- Convertir des Températures ---\n");
    printf("1. Celsius -> Fahrenheit\n");
    printf("2. Fahrenheit -> Celsius\n");
    printf("Choisissez une option : ");
    scanf("%d", &choice);

    printf("Entrez la valeur : ");
    scanf("%lf", &value);

    if (choice == 1) {
        printf("%.2f °C = %.2f °F\n", value, celsius_to_fahrenheit(value));
    } else if (choice == 2) {
        printf("%.2f °F = %.2f °C\n", value, fahrenheit_to_celsius(value));
    } else {
        printf("Choix invalide.\n");
    }
}

// Menu pour les devises
void convert_currency() {
    int choice;
    double value;

    printf("\n--- Convertir des Devises ---\n");
    printf("1. Euros -> Dollars\n");
    printf("2. Dollars -> Euros\n");
    printf("Choisissez une option : ");
    scanf("%d", &choice);

    printf("Entrez la valeur : ");
    scanf("%lf", &value);

    if (choice == 1) {
        printf("%.2f € = %.2f $\n", value, euros_to_dollars(value));
    } else if (choice == 2) {
        printf("%.2f $ = %.2f €\n", value, dollars_to_euros(value));
    } else {
        printf("Choix invalide.\n");
    }
}
