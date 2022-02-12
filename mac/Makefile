# @brief   midiport Makefile for Mac OS X Objective-C.
# @author  eel3
# @date    2022-02-09
#
# @note
# - Apple LLVM 6.0 (clang-600.0.57, Xcode 6.2) on Mac OS X 10.9.5

app            := midiport
CC             := xcrun cc
CFLAGS         := -Wall -std=gnu99 -pedantic -fobjc-arc
SDKROOT        := $(shell xcodebuild -version -sdk macosx | sed -n '/^Path: /s///p')
CPPFLAGS        = -isysroot "$(SDKROOT)"
LDLIBS         := -framework Foundation -framework CoreMIDI
TARGET_ARCH    := -mmacosx-version-min=10.15 -arch x86_64 -arch arm64

.PHONY: all
all: $(app)

.PHONY: clean
clean:
	$(RM) $(app)
