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

#include <stdio.h>
#include "flatpak.h"

// Gets a system installation of Flatpak, which is needed to get access to apps installed in system directories.
//
// Returns:
// FlatpakInstallation.
FlatpakInstallation *get_flatpak_system_installation() {
    GError *err = NULL;
    FlatpakInstallation *flatpak_installation = NULL;

    flatpak_installation = flatpak_installation_new_system(NULL, &err);
    if (err != NULL) {
        fprintf(stderr, "Failed to get Flatpak installation: %s\n", err->message);
        g_error_free(err);
        exit(EXIT_FAILURE);
    }

    return flatpak_installation;
}

// Gets a user installation of Flatpak, which is needed to get access to apps installed in user directories.
//
// Returns:
// FlatpakInstallation.
FlatpakInstallation *get_flatpak_user_installation() {
    GError *err = NULL;
    FlatpakInstallation *flatpak_installation = NULL;

    flatpak_installation = flatpak_installation_new_user(NULL, &err);
    if (err != NULL) {
        fprintf(stderr, "Failed to get Flatpak installation: %s\n", err->message);
        g_error_free(err);
        exit(EXIT_FAILURE);
    }

    return flatpak_installation;
}

// Gets flatpak apps, either using a system or user Flatpak installation.
//
// Args:
// flatpak_installation - installation of flatpak which you can get by using get_flatpak_user_installation or get_flatpak_system_installation.
//
// Returns:
// GPtrArray which contains FlatpakInstalledRef.
GPtrArray *get_flatpak_apps(FlatpakInstallation *flatpak_installation) {
    GError *err = NULL;
    GPtrArray *arr = NULL;
    arr = flatpak_installation_list_installed_refs_by_kind(flatpak_installation, FLATPAK_REF_KIND_APP, NULL, &err);

    return arr;
}
