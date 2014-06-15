midiport
========

Command line tool to show MIDI port.

License
-------

zlib License.

Target environments
-------------------

Windows, Mac OS X.

Set up
------

All you have to do is compile midiport.c/midiport.m. Use make and Makefile.

| toolset                       | Makefile          | notes                               |
|:------------------------------|:------------------|:------------------------------------|
| Mac OS X (Xcode)              | Makefile          | Using ARC (Need Xcode 4.2 or later) |
| MinGW/TDM-GCC (with GNU make) | Makefile_mingw    |                                     |
| Microsoft Visual C++          | Makefile_vc_nmake |                                     |

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
