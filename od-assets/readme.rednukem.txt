Rednukem for OpenDingux Beta (JZ4770/Lepus) and RetroFW 2.3
===========================================================

Supported games
---------------

    Duke Nukem 3D: Atomic Edition
    Redneck Rampage
    Redneck Rampage: Rides Again
    NAM
    NAPALM
    World War II GI

Game files
----------

Copy the game data files in the '$HOME/.config/rednukem/{game}' directory
or in 'rednukem/{game}' directory at the root of the external SD Card.

Where {game} possible values are:

  - duke3d	for Duke Nukem 3D: Atomic Edition
  - rr		for Redneck Rampage
  - rrra	for Redneck Rampage: Rides Again
  - nam		for NAM
  - napalm	for NAPALM
  - ww2gi	for World War II GI
  
You can also put files directly in '$HOME/.config/rednukem' directory or in
'rednukem' directory at root of external SD Card but to in some cases you
can get file naming conflicts.

Video
-----

OD port try to detect the resolution to use, if it is not detected then
320x240 resolution is used.

For RetroFW a 320x240 resolution is used by default.

Sound
-----

CD Audio for Redneck Rampage and Redneck Rampage: Rides Again needs the audio tracks in
OGG format (OD and RetroFW) with the game data files. OD for JZ4770 also soported FLAC
audio format.

Tracks must be named 'trackxx.ogg' (or 'trackxx.flac') where 'xx' is the track
number (from 02 to 10).

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

If joystick axises are detected then by default the left axis is used for
moving and strafing and right axis for looking up/down and turning on.

If a game function is mapped to two different keys then the game funtion is
triggered when both keys are pressed at the same time.

How to build
------------

1- Put your toolchain in path. If it is installed in /opt/toolchain then
   you can execute

    PATH=/opt/toolchain/usr/bin:$PATH

2- From nblood directory execute

    For RetroFW 2.3:

    make -f GNUmakefile RENDERTYPE=SDL SDL_TARGET=1 CROSS=mipsel-RetroFW-linux-uclibc- RELEASE=1 OPTOPT='-mips32' PLATFORM=RETROFW rr

    For Opendingux beta:

    make -f GNUmakefile RENDERTYPE=SDL SDL_TARGET=1 CROSS=mipsel-gcw0-linux-uclibc- RELEASE=1 OPTOPT='-mips32r2' PLATFORM=GCW rr

    For Opendingux beta for Lepus devices:

    make -f GNUmakefile RENDERTYPE=SDL SDL_TARGET=1 CROSS=mipsel-lepus-linux-musl- RELEASE=1 OPTOPT='-mips32' PLATFORM=LEPUS rr

3- Create the opk file running make_opk_rednukem.sh shell

    For RetroFW 2.3:

    TARGET=retrofw ./make_opk_rednukem.sh

    For Opendingux beta:

    ./make_opk_rednukem.sh

    For Opendingux beta for Lepus:

    TARGET=lepus ./make_opk_rednukem.sh

    This create one opk file with all launchers in it.
    
    If you want independent opk files use 'SPLIT=yes'
    
    SPLIT=yes ./make_opk_rednukem.sh

4- To clean the build
    make -f GNUmakefile RENDERTYPE=SDL PLATFORM=RETROFW clean
    make -f GNUmakefile RENDERTYPE=SDL PLATFORM=GCW clean
    make -f GNUmakefile RENDERTYPE=SDL PLATFORM=LEPUS clean
