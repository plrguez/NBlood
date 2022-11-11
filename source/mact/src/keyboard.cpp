/*
 * keyboard.c
 * MACT library -to- JonoF's Build Port Keyboard Glue
 *
 * by Jonathon Fowler
 *
 * Since we don't have the source to the MACT library I've had to
 * concoct some magic to glue its idea of controllers into that of
 * my Build port.
 *
 */
//-------------------------------------------------------------------------
/*
Duke Nukem Copyright (C) 1996, 2003 3D Realms Entertainment

This file is part of Duke Nukem 3D version 1.5 - Atomic Edition

Duke Nukem 3D is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/
//-------------------------------------------------------------------------

#include "compat.h"

#include "keyboard.h"
#include "control.h"

#ifdef __OPENDINGUX__
#include <string>
#endif

kb_scancode KB_LastScan;

// this is horrible!
const char *KB_ScanCodeToString(kb_scancode scancode)
{
    for (auto &s : sctokeylut)
        if (s.sc == scancode)
            return s.key;

    return "";
}

#ifdef __OPENDINGUX__
// Only used for print menu
const char *KB_ScanCodeToODString(kb_scancode scancode)
{
    std::string strsc = std::string(KB_ScanCodeToString(scancode));
    if (strsc == "Escape")
        return "Select";
    else if (strsc == "Enter")
        return "Start";
    else if (strsc == "BakSpc")
        return "R1";
    else if (strsc == "Tab")
        return "L1";
    else if (strsc == "PgDn")
        return "R2";
    else if (strsc == "PgUp")
        return "L2";
    else if (strsc == "Kpad.")
        return "R3";
    else if (strsc == "Kpad/")
        return "L3";
    else if (strsc == "LCtrl")
        return "Button A";
    else if (strsc == "LAlt")
        return "Button B";
    else if (strsc == "Space")
        return "Button X";
    else if (strsc == "LShift")
        return "Button Y";
#ifdef __RETROFW__
    else if (strsc == "End")
#else
    else if (strsc == "Home")
#endif
        return "Power";
    else
        return Bstrdup(strsc.c_str());
}
#endif

kb_scancode KB_StringToScanCode(const char * string)
{
    for (auto &s : sctokeylut)
        if (!Bstrcasecmp(s.key, string))
            return s.sc;

    return 0;
}
