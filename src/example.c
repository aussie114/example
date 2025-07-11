#include <gtk/gtk.h>
#include "create.h"

static GtkWidget * input;
static GtkWidget * button;
static GtkWidget * output;

static void on_button_pressed(GtkWidget * caller, gpointer data)
{
	(void)caller;
	(void)data;
	const gchar * input_text = gtk_editable_get_text(GTK_EDITABLE(input));
	gtk_editable_set_text(GTK_EDITABLE(output),  input_text);
}

void create_example()
{
	input  = create(gtk_entry_new(),                     0, 0, 1, 1);
	button = create(gtk_button_new_with_label("Print"),  0, 1, 1, 1);
	output = create(gtk_entry_new(),                     0, 2, 1, 1);

	gtk_editable_set_text(GTK_EDITABLE(input),  "Hello, World!");

	g_signal_connect(button,  "clicked",  G_CALLBACK(on_button_pressed), NULL); 
}
