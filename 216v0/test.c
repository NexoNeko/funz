#include <gtk/gtk.h>
#include <glib/gstdio.h>


static void activate (GtkApplication *app, gpointer user_data)
{
  GtkBuilder *builder = gtk_builder_new ();
  gtk_builder_add_from_file (builder, "uitest.ui", NULL);

  GObject *window = gtk_builder_get_object (builder, "window");
  gtk_window_set_application (GTK_WINDOW (window), app);

  GtkCssProvider *cssProvider = gtk_css_provider_new();
  gtk_css_provider_load_from_path(cssProvider, "style.css");
  gtk_style_context_add_provider_for_display(gdk_display_get_default(),
					    GTK_STYLE_PROVIDER(cssProvider),
					    GTK_STYLE_PROVIDER_PRIORITY_USER);


  /* Set window to unresizable and show it */
  gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
  gtk_widget_set_visible (GTK_WIDGET (window), TRUE);

  g_object_unref (builder);
}

int main (int argc, char *argv[])
{
#ifdef GTK_SRCDIR
  g_chdir (GTK_SRCDIR);
#endif

  GtkApplication *app = gtk_application_new ("org.gtk.example",
					     G_APPLICATION_DEFAULT_FLAGS);

  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);

  int status = g_application_run (G_APPLICATION (app), argc, argv);

  g_object_unref (app);

  return status;
}
