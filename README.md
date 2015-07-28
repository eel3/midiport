midiport
========

Command line tool to show MIDI port.

License
-------

zlib License.

Target environments
-------------------

Windows, Linux, Mac OS X.

Set up
------

All you have to do is compile midiport.c/midiport.m. Use make and Makefile.

| toolset                        | Makefile                 | notes                                                     |
|:-------------------------------|:-------------------------|:----------------------------------------------------------|
| Linux                          | Makefile                 | Need libasound2-dev (debian) / alsa-lib-devel (CentOS)    |
| Mac OS X (Xcode)               | Makefile                 | Using ARC (Need Xcode 4.2 or later. NOT work on 32bit OS) |
| MinGW/TDM-GCC (with GNU make)  | Makefile\_mingw          |                                                           |
| MinGW-w64/TDM64 (32bit binary) | Makefile\_mingw64\_32bit |                                                           |
| Microsoft Visual C++           | Makefil\e_vc\_nmake      |                                                           |

Output format of midiport is machine-readable.

Use midiportf if you want to convert it into human-readable format.
midiportf is written in AWK.

Usage
-----

See \`Example'. midiport has no option.

Example
-------

    > rem Example on Windows 7
    
    > midiport
    # MIDI IN : "in\t<ID>\t<device name>"
    
    # MIDI OUT : "out\t<ID>\t<device name>"
    out     0       Microsoft GS Wavetable Synth [0x01, 0x1b]
    
    > midiport | gawk -f midiportf
     [MIDI IN]
     Not found.
    
     [MIDI OUT]
     0 | Microsoft GS Wavetable Synth [0x01, 0x1b]
    
    > _
