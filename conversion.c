#include "conversion.h"

// Longueur
double meters_to_kilometers(double meters) {
    return meters / 1000.0;
}

double kilometers_to_meters(double kilometers) {
    return kilometers * 1000.0;
}

// Température
double celsius_to_fahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

// Devises
double euros_to_dollars(double euros) {
    return euros * 1.1; // Exemple : 1€ = 1.1$
}

double dollars_to_euros(double dollars) {
    return dollars / 1.1; // Exemple : 1.1$ = 1€
}
