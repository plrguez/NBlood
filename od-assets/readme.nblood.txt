NBlood for OpenDingux Beta (JZ4770/Lepus) and RetroFW 2.3
=========================================================

Game files
----------

Copy the game data files in the '$HOME/.config/nblood' directory
or in 'nblood' directory at the root of the external SD Card.

Video
-----

OD port try to detect the resolution to use, if it is not detected then
320x240 resolution is used.

For RetroFW a 320x240 resolution is used by default.

Sound
-----

By default the CD Audio is enabled for RetroFW and Lepus (Redbook Audio option). 
OPL3/Adlib or SF2 Midi can be used but probably you need to reduce the
sample rate and the number of voices.

CD Audio needs the audio tacks in OGG format. JZ4770 devices also support
FLAC audio format.
Tracks must be named 'bloodxx.ogg' or 'bloodxx.flac', where 'xx' is the
CD track number (from 02 to 09).
(see details in https://github.com/nukeykt/NBlood)

Save game
---------

From game press 'Select' button to open menu, then select Save.
With D-PAD select an slot and press the 'Start' button. 

To introduce a name use the D-Pad Up/Down to change characters and
the D-Pad Right/A button to confirm selected character.

To confirm save name and save use the 'Start' button.

Keys in Menus
-------------

        Movement                        D-PAD
        Enter in menu entry selected    Start
        Change value                    Left/Right or Start
        Exit to previous menu or game   Select


Default in-game keys:
---------------------

        Movement                        D-PAD
        Weapon fire                     A
        Weapon Special Fire             R1 + A
        Crouch                          B
        Jump                            X
        Open                            Y

        Turn around                     L1 + Down
        Autorun                         L1 + Up
        Next Weapon                     L1 + Right
        Previous Weapon                 L1 + Left

        Strafe Left                     R1 + Left
        Strafe Right                    R1 + Right
        Aim Up                          R1 + Up
        Aim Down                        R1 + Down
        Aim center                      R1 + L1

        Look Up                         L2
        Look Down                       R2

        Inventory Use                   Start
        Inventory Left                  Y + Left
        Inventory_Right                 Y + Right

        Map Toggle                      Power

        Shrink Screen                   Y + Down
        Enlarge Screen                  Y + Up

        Show menu                       Select

If joystick axises are detected then by default the left axis is used for
moving and strafing and right axis for looking up/down and turning on.

Remap keys
----------

You can remap the keys from menu:
    Options -> Control Setup -> Keyboard Setup -> Configure keys.

With the R1 you clear previous map for the selected game function.
With the Start button you map a new key for the selected game function.

To use the combination of two keys for a game function:
  - Select the game function to remap
  - Use R1 to clear previous mapping
  - Use Start to enter the first button
  - Use again Start to enter the second button

Don't map the Select button, it is reserved to bring up the Menu options
from in-game.

How to build
------------

1- Put your toolchain in path. If it is installed in /opt/toolchain then
   you can execute

    PATH=/opt/toolchain/usr/bin:$PATH

2- From nblood directory execute

    For RetroFW 2.3:

    make -f GNUmakefile RENDERTYPE=SDL SDL_TARGET=1 CROSS=mipsel-RetroFW-linux-uclibc- RELEASE=1 OPTOPT='-mips32' PLATFORM=RETROFW blood

    For Opendingux beta:

    make -f GNUmakefile RENDERTYPE=SDL SDL_TARGET=1 CROSS=mipsel-gcw0-linux-uclibc- RELEASE=1 OPTOPT='-mips32r2' PLATFORM=GCW blood

    For Opendingux beta for Lepus devices:

    make -f GNUmakefile RENDERTYPE=SDL SDL_TARGET=1 CROSS=mipsel-lepus-linux-musl- RELEASE=1 OPTOPT='-mips32' PLATFORM=LEPUS blood

3- Create the opk file running make_opk_blood.sh shell

    For RetroFW 2.3:

    TARGET=retrofw ./make_opk_blood.sh

    For Opendingux beta:

    ./make_opk_blood.sh

    For Opendingux beta for Lepus:

    TARGET=lepus ./make_opk_blood.sh

4- To clean the build
    make -f GNUmakefile RENDERTYPE=SDL PLATFORM=RETROFW clean
    make -f GNUmakefile RENDERTYPE=SDL PLATFORM=GCW clean
    make -f GNUmakefile RENDERTYPE=SDL PLATFORM=LEPUS clean
