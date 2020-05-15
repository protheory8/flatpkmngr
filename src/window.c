/*
    Flatpkmngr - a flatpak manager.
    Copyright © 2020 The Flatpkmngr Contributors

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "window.h"
#include <gtk/gtk.h>

static void on_window_close() {
    gtk_main_quit();
}

void run(int argc, char **argv) {
    gtk_init(&argc, &argv);

    GtkBuilder *builder = gtk_builder_new_from_file("flatpkmngr_window.ui");
    GtkWidget *window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));

    gtk_window_set_default_size(GTK_WINDOW(window), 600, 300);

    g_signal_connect(window, "delete_event", G_CALLBACK(on_window_close), NULL);

    gtk_widget_show_all(window);
    gtk_main();
}