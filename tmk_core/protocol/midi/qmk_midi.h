#pragma once

#ifdef MIDI_ENABLE
<<<<<<< HEAD
  #include "midi.h"
  extern MidiDevice midi_device;
  void setup_midi(void);
  void send_midi_packet(MIDI_EventPacket_t* event);
  bool recv_midi_packet(MIDI_EventPacket_t* const event);
=======
#    include "midi.h"
#    include <LUFA/Drivers/USB/USB.h>
extern MidiDevice midi_device;
void              setup_midi(void);
void              send_midi_packet(MIDI_EventPacket_t* event);
bool              recv_midi_packet(MIDI_EventPacket_t* const event);
>>>>>>> upstream/master
#endif
