# @brief   midiport Makefile for Mac OS X Objective-C.
# @author  eel3
# @date    2014/06/12
#
# @note
# - LLVM 4.2 (clang-425.0.27, Xcode 4.6.1) on Mac OS X 10.8.4

app            := midiport
CFLAGS         := -Wall -std=gnu99 -pedantic -fobjc-arc
CPPFLAGS       := -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.8.sdk/
LDLIBS         := -framework Foundation -framework CoreMIDI
TARGET_ARCH    := -mmacosx-version-min=10.6 -arch x86_64

.PHONY: all
all: $(app)

.PHONY: clean
clean:
	$(RM) $(app)
