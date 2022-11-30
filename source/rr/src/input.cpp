//-------------------------------------------------------------------------
/*
Copyright (C) 2010 EDuke32 developers and contributors

This file is part of EDuke32.

EDuke32 is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License version 2
as published by the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/
//-------------------------------------------------------------------------

#include "global.h"
#include "game.h"
#include "function.h"
#include "keyboard.h"
#include "mouse.h"
#include "joystick.h"
#include "control.h"
#include "input.h"
#include "menus.h"

int32_t I_CheckAllInput(void)
{
    return
        KB_KeyWaiting()
        || MOUSE_GetButtons()
        || JOYSTICK_GetButtons()
#if defined EDUKE32_IOS
        || g_mouseClickState == MOUSE_PRESSED
#endif
        ;
}
void I_ClearAllInput(void)
{
    KB_FlushKeyboardQueue();
    KB_ClearKeysDown();
    MOUSE_ClearAllButtons();
    JOYSTICK_ClearAllButtons();
    CONTROL_ClearAllButtons();
    mouseAdvanceClickState();
}

void I_ClearLast(void) { CONTROL_ClearUserInput(nullptr); }

int32_t I_TextSubmit(void)
{
    // FIXME: this is needed because the menu code does some weird shit.
    // for some reason, if the mouse cursor is hidden, activating menu items is handled immediately on button press,
    // but if the mouse cursor is visible, activating menu items is handled on button release instead...
    // ...except for the right mouse button, which is handled immediately on button press in both cases.
    if (!MOUSEINACTIVECONDITIONAL(1) || !MOUSEACTIVECONDITIONAL(1))
        MOUSE_ClearButton(M_LEFTBUTTON);

    return CONTROL_GetUserInput(nullptr)->b_advance;
}
int32_t I_ReturnTrigger(void) { return CONTROL_GetUserInput(nullptr)->b_return; }
int32_t I_AdvanceTrigger(void) { return I_TextSubmit() || KB_KeyPressed(sc_Space); }


void I_TextSubmitClear(void) { I_ClearAllInput(); }

void I_AdvanceTriggerClear(void)
{
    I_ClearLast();
    KB_ClearKeyDown(sc_Space);
}

int32_t I_GeneralTrigger(void)
{
    return I_AdvanceTrigger() || I_ReturnTrigger() || I_EscapeTrigger()
#if !defined GEKKO
        || BUTTON(gamefunc_Open)
# if !defined EDUKE32_TOUCH_DEVICES
        || MOUSEINACTIVECONDITIONAL(BUTTON(gamefunc_Fire))
# else
        || BUTTON(gamefunc_Fire)
# endif
#endif
        ;

}

void I_GeneralTriggerClear(void)
{
    I_AdvanceTriggerClear();
//    I_ReturnTriggerClear();

#if !defined GEKKO
    CONTROL_ClearButton(gamefunc_Open);
    CONTROL_ClearButton(gamefunc_Fire);
#endif
}


int32_t I_EscapeTrigger(void) { return CONTROL_GetUserInput(nullptr)->b_escape; }

int32_t I_MenuUp(void)
{
    return CONTROL_GetUserInput(nullptr)->dir == dir_Up || BUTTON(gamefunc_Move_Forward);
}

int32_t I_MenuDown(void)
{
    return CONTROL_GetUserInput(nullptr)->dir == dir_Down || BUTTON(gamefunc_Move_Backward);
}

int32_t I_MenuLeft(void) { return CONTROL_GetUserInput(nullptr)->dir == dir_Left || BUTTON(gamefunc_Turn_Left) || BUTTON(gamefunc_Strafe_Left); }
int32_t I_MenuRight(void) { return CONTROL_GetUserInput(nullptr)->dir == dir_Right || BUTTON(gamefunc_Turn_Right) || BUTTON(gamefunc_Strafe_Right); }

int32_t I_SliderLeft(void) { return I_MenuLeft() || /*MOUSEACTIVECONDITIONAL*/(MOUSE_GetButtons() & M_WHEELDOWN); }
int32_t I_SliderRight(void) { return I_MenuRight() || /*MOUSEACTIVECONDITIONAL*/(MOUSE_GetButtons() & M_WHEELUP); }

int32_t I_PanelUp(void) { return I_MenuUp() || I_MenuLeft() || KB_KeyPressed(sc_PgUp); }
int32_t I_PanelDown(void) { return I_MenuDown() || I_MenuRight() || KB_KeyPressed(sc_PgDn); }

void I_PanelUpClear(void)
{
    I_ClearLast();
    KB_ClearKeyDown(sc_PgUp);
}

void I_PanelDownClear(void)
{
    I_ClearLast();
    KB_ClearKeyDown(sc_PgDn);
}

#ifdef __OPENDINGUX__
#define NUM_CHARS 40
char ascii_accepted[NUM_CHARS] = { 
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
    'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
    'U', 'V', 'W', 'X', 'Y', 'Z', ' ', '-', '_', '.',
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', };
int current_ascii_char = 0;
char odch = 0;
char odnch = ascii_accepted[current_ascii_char];
#define SET_CURRENT_ASCII_CHAR(ascii, current) { for (int i=0;i<NUM_CHARS;i++) { if (ascii == ascii_accepted[i]) { current = i; break; } } }
bool advance = false;
#endif

int32_t I_EnterText(char *t, int32_t maxlength, int32_t flags)
{
    char ch;
    int32_t inputloc = Bstrlen(typebuf);

#ifdef __OPENDINGUX__
    if (!inputloc)
        memset(t,0,maxlength);
    if (inputloc && !advance)
        inputloc--;
    advance = false;
    // Restore last input character in new position
    if (odnch && inputloc < maxlength)
    {
        *(t+inputloc) = odnch;
        odch = odnch;
        odnch = 0;
        SET_CURRENT_ASCII_CHAR(odch, current_ascii_char)
    }
    // Up: next char, Down: previous character
    if (KB_KeyDown[sc_UpArrow] || KB_KeyDown[sc_DownArrow])
    {
        if (KB_KeyDown[sc_UpArrow])
        {
            if (current_ascii_char < NUM_CHARS - 1)
                current_ascii_char++;
            else
                current_ascii_char = 0;
            KB_KeyDown[sc_UpArrow] = 0;
        }
        if (KB_KeyDown[sc_DownArrow])
        {
            if (current_ascii_char > 0)
                current_ascii_char--;
            else
                current_ascii_char = NUM_CHARS - 1;
            KB_KeyDown[sc_DownArrow] = 0;
        }
        odch = ascii_accepted[current_ascii_char];

        if (inputloc < maxlength) // n chars per slot name
            *(t+inputloc) = odch;
    }
    // Right cursor or A button: confirm character.
    if ((KB_KeyDown[sc_RightArrow] || KB_KeyDown[sc_LeftControl]) && odch)
    {
        advance = true;
        // Emulate keystroke
        if (odch)
        {
            keyBufferInsert(odch);
            odnch = odch;
        }
        odch = 0;
        if (KB_KeyDown[sc_RightArrow])
            KB_KeyDown[sc_RightArrow] = 0;
        if (KB_KeyDown[sc_LeftControl])
            KB_KeyDown[sc_LeftControl] = 0;
    }
    // Backspace
    if (KB_KeyDown[sc_BackSpace] && inputloc < maxlength && inputloc > 0)
    {
        advance = true;
        *(t+inputloc) = 0;
        odnch = *(t+inputloc-1);
        odch = 0;
        KB_KeyDown[sc_BackSpace] = 0;
    }
    // Include current selected char into the name
    if (KB_KeyDown[sc_Enter] && inputloc < maxlength)
    {
        inputloc++;
        *(t+inputloc) = '\0';
        
        current_ascii_char = 0;
        odch = 0;
        odnch = ascii_accepted[current_ascii_char];
    }
    if (KB_KeyDown[sc_Escape])
    {
        current_ascii_char = 0;
        odch = 0;
        odnch = ascii_accepted[current_ascii_char];
    }
#endif

    while ((ch = KB_GetCh()) != 0)
    {
        if (ch == asc_BackSpace)
        {
            if (inputloc > 0)
            {
                inputloc--;
                *(t+inputloc) = 0;
            }
        }
        else
        {
            if (ch == asc_Enter)
            {
                I_AdvanceTriggerClear();
                return 1;
            }
            else if (ch == asc_Escape)
            {
                I_ReturnTriggerClear();
                return -1;
            }
            else if (ch >= 32 && inputloc < maxlength && ch < 127)
            {
                if (!(flags & INPUT_NUMERIC) || (ch >= '0' && ch <= '9'))
                {
                    // JBF 20040508: so we can have numeric only if we want
                    *(t+inputloc) = ch;
                    *(t+inputloc+1) = 0;
                    inputloc++;
                }
            }
        }
    }

    if (I_TextSubmit())
    {
        I_TextSubmitClear();
        return 1;
    }
    if (I_ReturnTrigger())
    {
        I_ReturnTriggerClear();
        return -1;
    }

    return 0;
}
