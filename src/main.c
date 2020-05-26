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
#include <stdlib.h>
#include "window.h"
#include "flatpak.h"
#include "utils.h"

void run(int argc, char **argv) {
    Window window = window_init(argc, argv);

    FlatpakInstallation *system_flatpak_installation = get_flatpak_system_installation();
    FlatpakInstallation *user_flatpak_installation = get_flatpak_user_installation();
    GPtrArray *system_flatpak_apps = get_flatpak_apps(system_flatpak_installation);
    GPtrArray *user_flatpak_apps = get_flatpak_apps(user_flatpak_installation);

    add_apps_to_list_box(GTK_LIST_BOX(window.app_list_box), system_flatpak_apps, user_flatpak_apps);

    gtk_widget_show_all(window.window);
    gtk_main();
}

int main(int argc, char **argv) {
    run(argc, argv);
    return EXIT_SUCCESS;
}
