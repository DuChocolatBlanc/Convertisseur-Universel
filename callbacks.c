#include "callbacks.h"
#include "conversion.h"
#include <gtk/gtk.h>

void on_length_conversion_clicked(GtkWidget *widget, gpointer data) {
    GtkWidget *dialog;
    GtkWidget *content_area;
    GtkWidget *label;

    dialog = gtk_dialog_new_with_buttons("Conversion de Longueur",
                                         GTK_WINDOW(data),
                                         GTK_DIALOG_MODAL,
                                         "OK",
                                         GTK_RESPONSE_OK,
                                         NULL);

    content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
    label = gtk_label_new("Fonctionnalité de conversion de longueur à implémenter.");
    gtk_container_add(GTK_CONTAINER(content_area), label);

    gtk_widget_show_all(dialog);
    g_signal_connect(dialog, "response", G_CALLBACK(gtk_widget_destroy), NULL);
}

void on_temperature_conversion_clicked(GtkWidget *widget, gpointer data) {
    GtkWidget *dialog;
    GtkWidget *content_area;
    GtkWidget *label;

    dialog = gtk_dialog_new_with_buttons("Conversion de Température",
                                         GTK_WINDOW(data),
                                         GTK_DIALOG_MODAL,
                                         "OK",
                                         GTK_RESPONSE_OK,
                                         NULL);

    content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
    label = gtk_label_new("Fonctionnalité de conversion de température à implémenter.");
    gtk_container_add(GTK_CONTAINER(content_area), label);

    gtk_widget_show_all(dialog);
    g_signal_connect(dialog, "response", G_CALLBACK(gtk_widget_destroy), NULL);
}

void on_currency_conversion_clicked(GtkWidget *widget, gpointer data) {
    GtkWidget *dialog;
    GtkWidget *content_area;
    GtkWidget *label;

    dialog = gtk_dialog_new_with_buttons("Conversion de Devise",
                                         GTK_WINDOW(data),
                                         GTK_DIALOG_MODAL,
                                         "OK",
                                         GTK_RESPONSE_OK,
                                         NULL);

    content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
    label = gtk_label_new("Fonctionnalité de conversion de devise à implémenter.");
    gtk_container_add(GTK_CONTAINER(content_area), label);

    gtk_widget_show_all(dialog);
    g_signal_connect(dialog, "response", G_CALLBACK(gtk_widget_destroy), NULL);
}

void on_quit_clicked(GtkWidget *widget, gpointer data) {
    gtk_main_quit();
}
