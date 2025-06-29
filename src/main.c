#include <gtk/gtk.h>
#include "main.h"
#include "config.h"
#include "logic.h"

Widgets widgets;

GtkWidget * create(GtkWidget * widget, int x, int y, int w, int h)
{
	gtk_grid_attach(GTK_GRID(widgets.grid), widget, x, y, w, h);
	return widget;
}

void activate(GtkApplication * app, gpointer user_data)
{
	(void)user_data;

	widgets.window   = gtk_application_window_new(app);
	widgets.grid     = gtk_grid_new();
	widgets.button_0 = create(gtk_button_new_with_label("Hello, World!"),       0,  0,  1,  1);

	GtkEventController * controller = gtk_event_controller_key_new();
	
	config(controller);
	connect_signals(controller);

	gtk_window_present (GTK_WINDOW (widgets.window));
}

int main (int argc, char ** argv)
{
	GtkApplication * program;
	int status;

	program = gtk_application_new ("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
	g_signal_connect (program, "activate", G_CALLBACK (activate), NULL);
	status = g_application_run (G_APPLICATION (program), argc, argv);
	g_object_unref (program);
	return status;
}


