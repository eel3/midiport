/* ********************************************************************** */
/**
 * @brief   Command line tool to show MIDI port.
 * @author  eel3
 * @date    2014/06/15
 *
 * @par OS:
 *   - Ubuntu 12.04 LTS 32bit
 *
 * @par Compilers
 *   - GCC 4.6.3
 */
/* ********************************************************************** */


#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include <alloca.h>
#include <alsa/asoundlib.h>


/* ====================================================================== */
/**
 * @brief  print subdevice ID/name.
 *
 * @param[in] *ctl         ALSA controller handle.
 * @param[in] card         ALSA Raw MIDI card number.
 * @param[in] device       ALSA Raw MIDI device number.
 * @param[in] stream_type  ALSA Raw MIDI stream type (IN or OUT).
 */
/* ====================================================================== */
static void
print_subdev_info(snd_ctl_t *ctl,
                  const int card,
                  const int device,
                  const snd_rawmidi_stream_t stream_type)
{
	snd_rawmidi_info_t* info;
	int err;
	unsigned int nsubs, i;
	const char *stype, *subdev_name, *dev_name;

	assert((ctl != NULL) && (card >= 0) && (device >= 0));

	snd_rawmidi_info_alloca(&info);
	snd_rawmidi_info_set_device(info, device);
	snd_rawmidi_info_set_stream(info, stream_type);
	err = snd_ctl_rawmidi_info(ctl, info);
	if (err < 0) {
		return;
	}
	nsubs = snd_rawmidi_info_get_subdevices_count(info);

	stype = (stream_type == SND_RAWMIDI_STREAM_INPUT) ? "in" : "out";

	for (i = 0; i < nsubs; i++) {
		snd_rawmidi_info_set_subdevice(info, i);
		err = snd_ctl_rawmidi_info(ctl, info);
		if (err < 0) {
			break;
		}

		(void) printf("%s\thw:%d,%d,%d\t", stype, card, device, i);

		subdev_name = snd_rawmidi_info_get_subdevice_name(info);
		if (subdev_name[0] == '\0') {
			dev_name = snd_rawmidi_info_get_name(info);
			(void) printf("%s %d\n", dev_name, i);
		} else {
			(void) printf("%s\n", subdev_name);
		}
	}
}

/* ====================================================================== */
/**
 * @brief  print MIDI device ID/name.
 *
 * @param[in] stream_type  ALSA Raw MIDI stream type (IN or OUT).
 */
/* ====================================================================== */
static void
print_dev_info(const snd_rawmidi_stream_t stream_type)
{
	int card, err;
	char name[32];
	snd_ctl_t *ctl;
	int device;

	/* for each sound card */
	card = -1;
	for (;;) {
		err = snd_card_next(&card);
		if ((err < 0) || (card < 0)) {
			break;
		}

		(void) snprintf(name, sizeof(name), "hw:%d", card);
		err = snd_ctl_open(&ctl, name, 0);
		if (err < 0) {
			break;
		}

		/* for each device in sound card */
		device = -1;
		for (;;) {
			err = snd_ctl_rawmidi_next_device(ctl, &device);
			if ((err < 0) || (device < 0)) {
				break;
			}
			print_subdev_info(ctl, card, device, stream_type);
		}
		snd_ctl_close(ctl);
	}
}

/* ====================================================================== */
/**
 * @brief  print MIDI IN ports.
 */
/* ====================================================================== */
static void
show_midi_in(void)
{
	print_dev_info(SND_RAWMIDI_STREAM_INPUT);
}

/* ====================================================================== */
/**
 * @brief  print MIDI OUT ports.
 */
/* ====================================================================== */
static void
show_midi_out(void)
{
	print_dev_info(SND_RAWMIDI_STREAM_OUTPUT);
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
