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

#ifndef __FLATPKMNGR_FLATPAK_H__
#define __FLATPKMNGR_FLATPAK_H__

#include <flatpak/flatpak.h>

typedef enum FlatpakRefSystemOrUser {
    FLATPAK_REF_SYSTEM_APP,
    FLATPAK_REF_USER_APP
} FlatpakRefSystemOrUser;

FlatpakInstallation *get_flatpak_system_installation();
FlatpakInstallation *get_flatpak_user_installation();
GPtrArray *get_flatpak_apps(FlatpakInstallation *flatpak_installation);

#endif // __FLATPKMNGR_FLATPAK_H__
