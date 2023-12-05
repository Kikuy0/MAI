#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>

void interface(int argc, char argv[]) {
  gtk_init(&argc, &argv);
  GtkWidget *window;

  gtk_main();
}
