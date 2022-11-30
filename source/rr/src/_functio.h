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

// _functio.h

// file created by makehead.exe
// these headers contain default key assignments, as well as
// default button assignments and game function names
// axis defaults are also included

#include "_control.h"
#include "control.h"

#ifndef function_private_h_
#define function_private_h_
#ifdef __cplusplus
extern "C" {
#endif
// KEEPINSYNC lunatic/con_lang.lua
char gamefunctions[NUMGAMEFUNCTIONS][MAXGAMEFUNCLEN] =
   {
   "Move_Forward",
   "Move_Backward",
   "Turn_Left",
   "Turn_Right",
   "Strafe",
   "Fire",
   "Open",
   "Run",
   "AutoRun",
   "Jump",
   "Crouch",
   "Look_Up",
   "Look_Down",
   "Look_Left",
   "Look_Right",
   "Strafe_Left",
   "Strafe_Right",
   "Aim_Up",
   "Aim_Down",
   "Weapon_1",
   "Weapon_2",
   "Weapon_3",
   "Weapon_4",
   "Weapon_5",
   "Weapon_6",
   "Weapon_7",
   "Weapon_8",
   "Weapon_9",
   "Weapon_10",
   "Inventory",
   "Inventory_Left",
   "Inventory_Right",
   "Holo_Duke",
   "Jetpack",
   "NightVision",
   "MedKit",
   "TurnAround",
   "SendMessage",
   "Map",
   "Shrink_Screen",
   "Enlarge_Screen",
   "Center_View",
   "Holster_Weapon",
   "Show_Opponents_Weapon",
   "Map_Follow_Mode",
   "See_Coop_View",
   "Mouse_Aiming",
   "Toggle_Crosshair",
   "Steroids",
   "Quick_Kick",
   "Next_Weapon",
   "Previous_Weapon",
   "Show_Console",
   "Show_DukeMatch_Scores",
   "Dpad_Select",
   "Dpad_Aiming",
   "Alt_Weapon",
   "Last_Used_Weapon",
   "Quick_Save",
   "Quick_Load",
   "Alt_Fire",
   "Third_Person_View",
   "Toggle_Crouch",
   };

#ifdef __SETUP__

char keydefaults[NUMGAMEFUNCTIONS*2][MAXGAMEFUNCLEN] =
   {
#ifdef __OPENDINGUX__
   // Movement
   "Up", "",
   "Down", "",
   "Left", "",
   "Right", "",
   // Strafe
   "", "", // Strafe
   "LCtrl", "", // Fire - A
   "LShift", "", // Open - Y
   "", "", // Run
   "Tab", "Up", // Autorun - L1 + Up
   "Space", "", // Jump - X
   "LAlt", "", // Crouch - B
   "PgUp", "", // Look Up - L2
   "PgDn", "", // Look Down - R2
   "", "", // Look Left
   "", "", // Look Right
   "BakSpc", "Left", // Strafe_Left - R1 + Left
   "BakSpc", "Right", // Strafe_Right - R1 + Right   
   "BakSpc", "Up", // Aim Up - Power - R1 + Up
   "BakSpc", "Down", // Aim Down - R1 + Down
   "1", "", // Weapon 1
   "2", "",
   "3", "",
   "4", "",
   "5", "",
   "6", "",
   "7", "",
   "8", "",
   "9", "",
   "0", "", // Weapon 10
   "Enter", "", // Inventory - Start
   "LShift", "Left", // Inventory_Left - Y + Left
   "LShift", "Right", // Inventory_Right - Y + Right
   "", "", // Holo_Duke
   "", "", // Jetpack",
   "", "", // NightVision",
   "", "", // MedKit",
   "Tab", "Down", //TurnAround - L1 + Down
   "", "", // SendMessage",   
#ifdef __RETROFW__
   "End", "", // Map_Toggle - Power
#else
   "LShift", "Enter", // Map_Toggle - Y + Enter
#endif   
   "LShift", "Down", // Shrink_Screen - Y + Down
   "LShift", "Up", // Enlarge_Screen - Y + Up   
   "BakSpc", "Tab", // Center View - R1 + L1   
   "", "", // Holster_Weapon",
   "", "", // Show_Opponents_Weapon",
   "", "", // Map_Follow_Mode",
   "", "", // See_Coop_View",   
   "BakSpc", "LCtrl", // Mouse_Aiming - R1 + A
   "", "", // Toggle_Crosshair",
   "", "", // Steroids",
   "", "", // Quick_Kick",
   "Tab", "Right", // Next_Weapon -L1 + Right
   "Tab", "Left", // Previous_Weapon - L1 + Left
   "", "", // Show_Console",
   "", "", // Show_DukeMatch_Scores",
   "", "", // Dpad_Select",
   "", "", // Dpad_Aiming",
   "", "", // Alt_Weapon",
   "", "", // Last_Used_Weapon",
   "", "", // Quick_Save",
   "", "", // Quick_Load",
   "", "", // Alt_Fire",
   "", "", // Third_Person_View",
   "", "", // Toggle_Crouch",   
#else
   "W", "Kpad8",
   "S", "Kpad2",
   "Left", "Kpad4",
   "Right", "KPad6",
   "LAlt", "RAlt",
   "RCtrl", "",
   "E", "",
   "LShift", "RShift",
   "CapLck", "",
   "Space", "/",
   "LCtrl", "",
   "PgUp", "Kpad9",
   "PgDn", "Kpad3",
   "Insert", "Kpad0",
   "Delete", "Kpad.",
   "A", "",
   "D", "",
   "Home", "KPad7",
   "End", "Kpad1",
   "1", "",
   "2", "",
   "3", "",
   "4", "",
   "5", "",
   "6", "",
   "7", "",
   "8", "",
   "9", "",
   "0", "",
   "Enter", "KpdEnt",
   "[", "",
   "]", "",
   "H", "",
   "J", "",
   "N", "",
   "M", "",
   "BakSpc", "",
   "T", "",
   "Tab", "",
   "-", "Kpad-",
   "=", "Kpad+",
   "KPad5", "",
   "ScrLck", "",
   "Y", "",
   "F", "",
   "K", "",
   "", "",
   "", "",
   "R", "",
   "Q", "",
   "'", "",
   ";", "",
   "`", "",
   "", "",
   "", "",
   "", "",
   "", "",
   "X", "",
   "F6", "",
   "F9", "",
   "F7", "",
   "", "",
#endif
   };

char oldkeydefaults[NUMGAMEFUNCTIONS*2][MAXGAMEFUNCLEN] =
   {
   "Up", "Kpad8",
   "Down", "Kpad2",
   "Left", "Kpad4",
   "Right", "KPad6",
   "LAlt", "RAlt",
   "LCtrl", "RCtrl",
   "Space", "",
   "LShift", "RShift",
   "CapLck", "",
   "A", "/",
   "Z", "",
   "PgUp", "Kpad9",
   "PgDn", "Kpad3",
   "Insert", "Kpad0",
   "Delete", "Kpad.",
   ",", "",
   ".", "",
   "Home", "KPad7",
   "End", "Kpad1",
   "1", "",
   "2", "",
   "3", "",
   "4", "",
   "5", "",
   "6", "",
   "7", "",
   "8", "",
   "9", "",
   "0", "",
   "Enter", "KpdEnt",
   "[", "",
   "]", "",
   "H", "",
   "J", "",
   "N", "",
   "M", "",
   "BakSpc", "",
   "T", "",
   "Tab", "",
   "-", "Kpad-",
   "=", "Kpad+",
   "KPad5", "",
   "ScrLck", "",
   "W", "",
   "F", "",
   "K", "",
   "U", "",
   "I", "",
   "R", "",
   "`", "",
   "'", "",
   ";", "",
   "C", "",
   "", "",
   "", "",
   "", "",
   "", "",
   "", "",
   "F6", "",
   "F9", "",
   "F7", "",
   "", "",
   };

static const char * mousedefaults[MAXMOUSEBUTTONS] =
   {
   "Fire",
   "Jetpack",
   "MedKit",
   "",
   "Previous_Weapon",
   "Next_Weapon",
   };


static const char * mouseclickeddefaults[MAXMOUSEBUTTONS] =
   {
   };


static const char * mouseanalogdefaults[MAXMOUSEAXES] =
   {
   "analog_turning",
   "analog_moving",
   };

#if defined(GEKKO)
static const char * joystickdefaults[MAXJOYBUTTONSANDHATS] =
   {
   "Open", // A
   "Fire", // B
   "Run", // 1
   "Map", // 2
   "Previous_Weapon", // -
   "Next_Weapon", // +
   "", // Home
   "Jump", // Z
   "Crouch", // C
   "Map", // X
   "Run", // Y
   "Jump", // L
   "Quick_Kick", // R
   "Crouch", // ZL
   "Fire", // ZR
   "Quick_Kick", // D-Pad Up
   "Inventory_Right", // D-Pad Right
   "Inventory", // D-Pad Down
   "Inventory_Left", // D-Pad Left
   };


static const char * joystickclickeddefaults[MAXJOYBUTTONSANDHATS] =
   {
   "",
   "",
   "",
   "",
   "",
   "",
   "",
   "",
   "",
   "",
   "",
   "",
   "Inventory",
   };


static const char * joystickanalogdefaults[MAXJOYAXES] =
   {
   "analog_strafing",
   "analog_moving",
   "analog_turning",
   "analog_lookingupanddown",
   };


static const char * joystickdigitaldefaults[MAXJOYDIGITAL] =
   {
   };
#else
static const char * joystickdefaults[MAXJOYBUTTONSANDHATS] =
   {
   "Fire",
   "Strafe",
   "Run",
   "Open",
   "",
   "",
   "",
   "",
   "",
   "",
   "",
   "",
   "",
   "",
   "",
   "",
   "",
   "",
   "",
   "",
   "",
   "",
   "",
   "",
   "",
   "",
   "",
   "",
   "",
   "",
   "",
   "",
   "Aim_Down",
   "Look_Right",
   "Aim_Up",
   "Look_Left",
   };


static const char * joystickclickeddefaults[MAXJOYBUTTONSANDHATS] =
   {
   "",
   "Inventory",
   "Jump",
   "Crouch",
   };


static const char * joystickanalogdefaults[MAXJOYAXES] =
   {
   "analog_turning",
   "analog_moving",
   "analog_strafing",
   };


static const char * joystickdigitaldefaults[MAXJOYDIGITAL] =
   {
   "",
   "",
   "",
   "",
   "",
   "",
   "Run",
   };
#endif

#endif
#ifdef __cplusplus
}
#endif
#endif
