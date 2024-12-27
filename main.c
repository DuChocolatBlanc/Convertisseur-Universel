#include <gtk/gtk.h>
#include "callbacks.h"

int main(int argc, char *argv[]) {
    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *length_button, *temperature_button, *currency_button, *quit_button;

    gtk_init(&argc, &argv);

    // Créer la fenêtre principale
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Convertisseur Universel");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Créer une grille pour organiser les widgets
    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    // Boutons pour les conversions
    length_button = gtk_button_new_with_label("Convertir des longueurs");
    g_signal_connect(length_button, "clicked", G_CALLBACK(on_length_conversion_clicked), NULL);
    gtk_grid_attach(GTK_GRID(grid), length_button, 0, 0, 1, 1);

    temperature_button = gtk_button_new_with_label("Convertir des températures");
    g_signal_connect(temperature_button, "clicked", G_CALLBACK(on_temperature_conversion_clicked), window);
    gtk_grid_attach(GTK_GRID(grid), temperature_button, 0, 1, 1, 1);

    currency_button = gtk_button_new_with_label("Convertir des devises");
    g_signal_connect(currency_button, "clicked", G_CALLBACK(on_currency_conversion_clicked), window);
    gtk_grid_attach(GTK_GRID(grid), currency_button, 0, 2, 1, 1);

    // Bouton Quitter
    quit_button = gtk_button_new_with_label("Quitter");
    g_signal_connect(quit_button, "clicked", G_CALLBACK(on_quit_clicked), NULL);
    gtk_grid_attach(GTK_GRID(grid), quit_button, 0, 3, 1, 1);

    // Afficher la fenêtre
    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
