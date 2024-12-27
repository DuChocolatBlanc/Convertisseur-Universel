// callbacks.h
#ifndef CALLBACKS_H
#define CALLBACKS_H

#include <gtk/gtk.h>

void on_length_conversion_clicked(GtkWidget *widget, gpointer data);
void on_temperature_conversion_clicked(GtkWidget *widget, gpointer data);
void on_currency_conversion_clicked(GtkWidget *widget, gpointer data);
void on_quit_clicked(GtkWidget *widget, gpointer data);

#endif // CALLBACKS_H