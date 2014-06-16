# @brief   midiport Makefile for Linux.
# @author  eel3
# @date    2014/06/13
#
# @note
# - GCC 4.6.3

app        := midiport
CFLAGS     := -Wall -std=c99 -pedantic
LDLIBS     := -lasound

.PHONY: all
all: $(app)

.PHONY: clean
clean:
	$(RM) $(app)
