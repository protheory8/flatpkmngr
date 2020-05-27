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

#include "utils.h"
#include "flatpak.h"

void add_app_to_list_box(GtkListBox *list_box, FlatpakInstalledRef *app, FlatpakRefSystemOrUser system_or_user_app) {
    const char *app_name = get_flatpak_app_name(app);
    const char *app_system_or_user = NULL;

    if (system_or_user_app == FLATPAK_REF_SYSTEM_APP) {
        app_system_or_user = "\n(System)";
    } else {
        app_system_or_user = "\n(User)";
    }

    char *app_row_text_str = calloc(strlen("<b>") + strlen(app_name) + strlen("</b>") + strlen(app_system_or_user) + 1, sizeof(char));
    strcpy(app_row_text_str, "<b>");
    strcat(app_row_text_str, app_name);
    strcat(app_row_text_str, "</b>");
    strcat(app_row_text_str, app_system_or_user);

    GtkWidget *row = gtk_list_box_row_new();

    GtkWidget *app_row_text = gtk_label_new(NULL);
    gtk_label_set_markup(GTK_LABEL(app_row_text), app_row_text_str);
    gtk_label_set_xalign(GTK_LABEL(app_row_text), 0.0);
    gtk_widget_set_margin_start(app_row_text, 10);
    gtk_widget_set_margin_end(app_row_text, 20);

    GtkWidget *app_row_icon = gtk_image_new_from_icon_name(flatpak_ref_get_name(FLATPAK_REF(app)), GTK_ICON_SIZE_BUTTON);

    GtkWidget *app_row_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);

    gtk_box_pack_start(GTK_BOX(app_row_box), app_row_icon, gtk_true(), gtk_true(), 0);
    gtk_box_pack_start(GTK_BOX(app_row_box), app_row_text, gtk_true(), gtk_true(), 0);

    gtk_container_add(GTK_CONTAINER(row), app_row_box);
    gtk_list_box_insert(list_box, row, -1);
}

void add_apps_to_list_box(GtkListBox *list_box, GPtrArray *system_apps, GPtrArray *user_apps) {
    for (guint i = 0; i < system_apps->len; i++) {
        add_app_to_list_box(list_box, g_ptr_array_index(system_apps, i), FLATPAK_REF_SYSTEM_APP);
    }

    for (guint i = 0; i < user_apps->len; i++) {
        add_app_to_list_box(list_box, g_ptr_array_index(user_apps, i), FLATPAK_REF_USER_APP);
    }
}
