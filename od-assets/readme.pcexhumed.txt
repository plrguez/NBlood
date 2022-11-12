PCExhumed for OpenDingux Beta (JZ4770/Lepus) and RetroFW 2.3
============================================================

Currently there is no menu in game options to change video options or keymap.

When the game require to introduce some text the only possibility is to 
introduce spaces with the 'X' button.

start a new game
----------------

To start a new game is required to create a new game file.

For this select "New game" option in main menu with 'Start' button
then select a slot and press the 'Start' button again.

Now is required to introduce a game name. Press the 'X' button 
to introduce at least one space character and confirm with 'Start' button. 

If a question about overwite existing game appears then
you can press 'Start' to confirm the overwrite or 'Select' to cancel.

Game files
----------

Put the game files in the '$HOME/.config/pcexhumed' directory or
in 'pcexhumed' directory directory at the root of the external SDC card.

Video
-----

OD port try to detect the resolution to use, if it is not detected then
320x240 resolution is used.

RetroFW a 320x240 resolution is used by default.

You can set the video resolution editing the file 
'$HOME/.config/pcexhumed/pcexhumed.cfg'.

Sound
-----

CD Audio needs the audio tracks in OGG format (OD and RetroFW)
with the game data files. OD for JZ4770 also soported FLAC audio format.

Track must be named 'exhumedxx.ogg' (or 'exhumedxx.flac') where 'xx' is
the track number (from 02 to 19).

Keys in Menu
------------

        Movement                        D-PAD
        Enter in menu entry selected    Start
        Change value                    Left/Right or Start
        Exit to previous menu or game   Select

Default in-game keys:
---------------------

        Movement                        D-PAD
        Fire                            A
        Crouch                          B
        Jump                            X
        Open                            Y

        Toggle_Crosshair                L1 + Down
        Autorun                         L1 + Up
        Next Weapon                     L1 + Right
        Previous Weapon                 L1 + Left

        Strafe Left                     R1 + Left
        Strafe Right                    R1 + Right
        Aim Up                          R1 + Up
        Aim Down                        R1 + Down
        Look Straight                   R1 + L1

        Mouse_Aiming                    L1 + Start 

        Third Person View               R1 + Y

        Look Up                         L2
        Look Down                       R2

        Inventory Use                   Start
        Inventory Left                  Y + Left
        Inventory_Right                 Y + Right

        Map Toggle                      Power (RetroFW) / Y + Start (OD)

        Shrink Screen                   Y + Down
        Enlarge Screen                  Y + Up

        Show menu                       Select

If joystick axis is detected then by default the left axis is used for moving
and strafing and right axis for looking up/down and turning on.

Mapped keys to game functions is saved in the 
'$HOME/.config/pcexhumed/pcexhumed_cvars.cfg' file.

If a game funtion is mapped to two different keys then the game funtion is
triggered when both keys are pressed at same time.
Keys are the correspond keyboard keys for each device.

I do not recommend to touch this file if you do not know exactly what to do.

How to build
------------

1- Put your toolchain in path. If it is installed in /opt/toolchain then
   you can execute

    PATH=/opt/toolchain/usr/bin:$PATH

2- From nblood directory execute

    For RetroFW 2.3:

    make -f GNUmakefile RENDERTYPE=SDL SDL_TARGET=1 CROSS=mipsel-RetroFW-linux-uclibc- RELEASE=1 OPTOPT='-mips32' PLATFORM=RETROFW exhumed

    For Opendingux beta:

    make -f GNUmakefile RENDERTYPE=SDL SDL_TARGET=1 CROSS=mipsel-gcw0-linux-uclibc- RELEASE=1 OPTOPT='-mips32r2' PLATFORM=GCW exhumed

    For Opendingux beta for Lepus devices:

    make -f GNUmakefile RENDERTYPE=SDL SDL_TARGET=1 CROSS=mipsel-lepus-linux-musl- RELEASE=1 OPTOPT='-mips32' PLATFORM=LEPUS exhumed

3- Create the opk file running make_opk_exhumed.sh shell

    For RetroFW 2.3:

    TARGET=retrofw ./make_opk_exhumed.sh

    For Opendingux beta:

    ./make_opk_blood.sh

    For Opendingux beta for Lepus:

    TARGET=lepus ./make_opk_exhumed.sh

4- To clean the build
    make -f GNUmakefile RENDERTYPE=SDL PLATFORM=RETROFW clean
    make -f GNUmakefile RENDERTYPE=SDL PLATFORM=GCW clean
    make -f GNUmakefile RENDERTYPE=SDL PLATFORM=LEPUS clean
