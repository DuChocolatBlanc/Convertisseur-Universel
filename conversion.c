#include "conversion.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

// Structure pour stocker les données CURL
struct MemoryStruct {
    char *memory;
    size_t size;
};

size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t total_size = size * nmemb;
    struct MemoryStruct *mem = (struct MemoryStruct *)userp;

    char *ptr = realloc(mem->memory, mem->size + total_size + 1);
    if (ptr == NULL) {
        printf("Not enough memory (realloc returned NULL)\n");
        return 0;
    }

    mem->memory = ptr;
    memcpy(&(mem->memory[mem->size]), contents, total_size);
    mem->size += total_size;
    mem->memory[mem->size] = 0;

    return total_size;
}

double fetch_conversion_rate(const char *from_currency, const char *to_currency) {
    (void)from_currency;
    CURL *curl;
    CURLcode res;
    struct MemoryStruct chunk;

    chunk.memory = malloc(1);
    chunk.size = 0;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (!curl) {
        fprintf(stderr, "curl initialization failed\n");
        return -1;
    }

    curl_easy_setopt(curl, CURLOPT_URL, API_URL);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);

    res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
    } else {
        char key[64];
        sprintf(key, "\"%s\":", to_currency);
        char *rate_pos = strstr(chunk.memory, key);
        if (rate_pos) {
            double rate;
            sscanf(rate_pos + strlen(key), "%lf", &rate);
            free(chunk.memory);
            curl_easy_cleanup(curl);
            curl_global_cleanup();
            return rate;
        }
    }

    free(chunk.memory);
    curl_easy_cleanup(curl);
    curl_global_cleanup();
    return -1;
}

double convert_currency(double amount, const char *from_currency, const char *to_currency) {
    double rate = fetch_conversion_rate(from_currency, to_currency);
    if (rate > 0) {
        return amount * rate;
    } else {
        printf("Erreur lors de la récupération du taux de conversion.\n");
        return -1;
    }
}

// Conversions de longueurs
double meters_to_kilometers(double meters) {
    return meters / 1000.0;
}

double kilometers_to_meters(double kilometers) {
    return kilometers * 1000.0;
}

double kilometers_to_miles(double kilometers) {
    return kilometers * 0.621371;
}

double inches_to_centimeters(double inches) {
    return inches * 2.54;
}

double centimeters_to_inches(double centimeters) {
    return centimeters / 2.54;
}

// Conversions de températures
double celsius_to_fahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

double celsius_to_kelvin(double celsius) {
    return celsius + 273.15;
}

double kelvin_to_celsius(double kelvin) {
    return kelvin - 273.15;
}

// Conversions de devises (statiques pour démonstration)
double euros_to_dollars(double euros) {
    return euros * 1.1; // Exemple fixe : 1€ = 1.1$
}

double dollars_to_euros(double dollars) {
    return dollars / 1.1; // Exemple fixe : 1.1$ = 1€
}
