#ifndef CONVERTION_H
#define CONVERTION_H

#define API_URL "https://api.exchangerate-api.com/v4/latest/EUR"

// Prototypes des fonctions de conversion

// Longueurs
double meters_to_kilometers(double meters);
double kilometers_to_meters(double kilometers);
double kilometers_to_miles(double kilometers);
double inches_to_centimeters(double inches);
double centimeters_to_inches(double centimeters);

// Températures
double celsius_to_fahrenheit(double celsius);
double fahrenheit_to_celsius(double fahrenheit);
double celsius_to_kelvin(double celsius);
double kelvin_to_celsius(double kelvin);

// Devises
double euros_to_dollars(double euros);
double dollars_to_euros(double dollars);
double fetch_conversion_rate(const char *from_currency, const char *to_currency);
double convert_currency(double amount, const char *from_currency, const char *to_currency);

#endif // CONVERTION_H
