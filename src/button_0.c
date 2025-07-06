#include <gtk/gtk.h>
#include "grid.h"

GtkWidget * button_0;

void on_button_0_pressed(GtkWidget * caller, gpointer data)
{
	(void)caller;
	(void)data;
	g_print("Hello, World!\n");
}

void create_button_0()
{
	button_0 = gtk_button_new_with_label("Hello, World!");
	gtk_grid_attach(GTK_GRID(grid), button_0, 0,0,1,1);
	g_signal_connect(button_0, "clicked", G_CALLBACK(on_button_0_pressed), NULL);
	
}
