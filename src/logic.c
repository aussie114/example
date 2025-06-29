#include <gtk/gtk.h>
#include "main.h"

gboolean on_key_pressed(GtkEventControllerKey * controller, guint keyval, guint keycode, GdkModifierType state, gpointer user_data)
{
    (void)controller;
    (void)keycode;
    (void)state;
	if (keyval == GDK_KEY_Escape) 
	{
		gtk_window_destroy(GTK_WINDOW(user_data));
		return TRUE;
	}
		return FALSE;
}

void connect_signals(GtkEventController * controller)
{
	g_signal_connect(controller, "key-pressed", G_CALLBACK(on_key_pressed), widgets.window);
}
