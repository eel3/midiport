/* ********************************************************************** */
/**
 * @brief   Command line tool to show MIDI port.
 * @author  eel3
 * @date    2014/06/13
 *
 * @par OS:
 *   - Microsoft Windows 7 (64bit) SP1
 *
 * @par Compilers
 *   - Microsoft(R) Visual Studio 2005 SP1
 *   - Microsoft(R) Visual Studio 2010 SP1
 *   - TDM-GCC 4.8.1
 */
/* ********************************************************************** */


#include <stdio.h>
#include <stdlib.h>

#include <windows.h>
#include <mmsystem.h>


/* ====================================================================== */
/**
 * @brief  print MIDI IN ports.
 */
/* ====================================================================== */
static void
show_midi_in(void)
{
	UINT ndevs, i;
	MIDIINCAPS mic;
	MMRESULT rc;

	ndevs = midiInGetNumDevs();

	for (i = 0; i < ndevs; i++) {
		rc = midiInGetDevCaps(i, &mic, sizeof(mic));
		if (rc != MMSYSERR_NOERROR) {
			break;
		}
		(void) printf("in\t%u\t%s [%#04x, %#04x]\n", i, mic.szPname, mic.wMid, mic.wPid);
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
	UINT ndevs, i;
	MIDIOUTCAPS moc;
	MMRESULT rc;

	ndevs = midiOutGetNumDevs();

	for (i = 0; i < ndevs; i++) {
		rc = midiOutGetDevCaps(i, &moc, sizeof(moc));
		if (rc != MMSYSERR_NOERROR) {
			break;
		}
		(void) printf("out\t%u\t%s [%#04x, %#04x]\n", i, moc.szPname, moc.wMid, moc.wPid);
	}
}

/* ********************************************************************** */
/**
 * @brief  Main routine.
 *
 * @return  EXIT_SUCCESS
 */
/* ********************************************************************** */
int
main(void)
{
	(void) puts("# MIDI IN : \"in\\t<ID>\\t<device name>\"");
	show_midi_in();

	(void) puts("");

	(void) puts("# MIDI OUT : \"out\\t<ID>\\t<device name>\"");
	show_midi_out();

	return EXIT_SUCCESS;
}
