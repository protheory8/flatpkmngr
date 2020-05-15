/*
    Flatpkmngr - GUI Flatpak manager.
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

#include <gtk/gtk.h>
#include "window.h"
#include "flatpak.h"

// Invoked when the window is closed.
static void on_window_close() {
    gtk_main_quit();
}

// Adds app rows to app list box.
void add_rows(GtkListBox *app_list, GPtrArray *apps) {
    GtkWidget *global_row = gtk_list_box_row_new();
    gtk_container_add(GTK_CONTAINER(global_row), gtk_label_new("Global"));
    gtk_list_box_insert(app_list, global_row, -1);

    for (guint i = 0; i < apps->len; i++) {
        GtkWidget *row = gtk_list_box_row_new();
        GtkWidget *text = gtk_label_new(flatpak_installed_ref_get_appdata_name(g_ptr_array_index(apps, i)));
        gtk_container_add(GTK_CONTAINER(row), text);
        gtk_list_box_insert(app_list, row, -1);
    }
}

// Starts up Flatpkmngr
void init(int argc, char **argv) {
    FlatpakInstallation *flatpak_installation = get_flatpak_system_installation();
    GPtrArray *apps = get_flatpak_apps(flatpak_installation);

    gtk_init(&argc, &argv);

    GtkBuilder *builder = gtk_builder_new_from_file("flatpkmngr_window.ui");
    GtkWidget *window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));
    GtkWidget *app_list = GTK_WIDGET(gtk_builder_get_object(builder, "app_list"));

    gtk_window_set_default_size(GTK_WINDOW(window), 600, 300);

    add_rows(GTK_LIST_BOX(app_list), apps);

    g_signal_connect(window, "delete_event", G_CALLBACK(on_window_close), NULL);

    gtk_widget_show_all(window);
}

// A function which is running when the entire programs lifetime.
void run(int argc, char **argv) {
    init(argc, argv);
    gtk_main();
}
