/* ********************************************************************** */
/**
 * @brief   Command line tool to show MIDI port.
 * @author  eel3
 * @date    2014/06/13
 *
 * @par OS:
 *   - Mac OS X 10.8.5
 *
 * @par Compilers
 *   - LLVM 4.2 (clang-425.0.27, Xcode 4.6.1)
 */
/* ********************************************************************** */


#import <Foundation/Foundation.h>
#import <CoreMIDI/CoreMIDI.h>

#include <stdio.h>


/* ====================================================================== */
/**
 * @brief  print MIDI IN ports.
 */
/* ====================================================================== */
static void
show_midi_in(void)
{
	ItemCount ndevs, i;
	MIDIEndpointRef ep;
	CFStringRef devname;
	OSStatus status;

	ndevs = MIDIGetNumberOfSources();

	for (i = 0; i < ndevs; i++) {
		ep = MIDIGetSource(i);
		if (ep == (MIDIEndpointRef) NULL) {
			continue;
		}

		devname = NULL;
		status = MIDIObjectGetStringProperty(ep, kMIDIPropertyName, &devname);
		if ((status != errSecSuccess) || (devname == NULL)) {
			continue;
		}

		(void) printf("in\t%u\t%s\n", (unsigned) i, [(__bridge NSString *) devname UTF8String]);
		CFRelease(devname);
	}
}

/* ====================================================================== */
/**
 * @brief  print MIDI OUT ports.
 */
/* ====================================================================== */
static void
show_midi_out(void)
{
	ItemCount ndevs, i;
	MIDIEndpointRef ep;
	CFStringRef devname;
	OSStatus status;

	ndevs = MIDIGetNumberOfDestinations();

	for (i = 0; i < ndevs; i++) {
		ep = MIDIGetDestination(i);
		if (ep == (MIDIEndpointRef) NULL) {
			continue;
		}

		devname = NULL;
		status = MIDIObjectGetStringProperty(ep, kMIDIPropertyName, &devname);
		if ((status != errSecSuccess) || (devname == NULL)) {
			continue;
		}

		(void) printf("out\t%u\t%s\n", (unsigned) i, [(__bridge NSString *) devname UTF8String]);
		CFRelease(devname);
	}
}

/* ********************************************************************** */
/**
 * @brief  Main routine.
 *
 * @return  0
 */
/* ********************************************************************** */
int
main(void)
{
	@autoreleasepool {
		(void) puts("# MIDI IN : \"in\\t<ID>\\t<device name>\"");
		show_midi_in();

		(void) puts("");

		(void) puts("# MIDI OUT : \"out\\t<ID>\\t<device name>\"");
		show_midi_out();
	}
}
