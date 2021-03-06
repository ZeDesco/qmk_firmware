/*
 * Copyright 2018 Jack Humbert <jack.humb@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "encoder.h"
#ifdef SPLIT_KEYBOARD
  #include "split_util.h"
#endif

// for memcpy
#include <string.h>


#ifndef ENCODER_RESOLUTION
  #define ENCODER_RESOLUTION 4
#endif

#if !defined(ENCODERS_PAD_A) || !defined(ENCODERS_PAD_B)
  #error "No encoder pads defined by ENCODERS_PAD_A and ENCODERS_PAD_B"
#endif


#define NUMBER_OF_ENCODERS (sizeof(encoders_pad_a)/sizeof(pin_t))
static pin_t encoders_pad_a[] = ENCODERS_PAD_A;
static pin_t encoders_pad_b[] = ENCODERS_PAD_B;

<<<<<<< HEAD
static int8_t encoder_LUT[] = { 0, -1, 1, 0, 1, 0, 0, -1, -1, 0, 0, 1, 0, 1, -1, 0 };

static uint8_t encoder_state[NUMBER_OF_ENCODERS] = {0};
=======
#ifndef ENCODER_DIRECTION_FLIP
#    define ENCODER_CLOCKWISE true
#    define ENCODER_COUNTER_CLOCKWISE false
#else
#    define ENCODER_CLOCKWISE false
#    define ENCODER_COUNTER_CLOCKWISE true
#endif
static int8_t encoder_LUT[] = {0, -1, 1, 0, 1, 0, 0, -1, -1, 0, 0, 1, 0, 1, -1, 0};

static uint8_t encoder_state[NUMBER_OF_ENCODERS]  = {0};
static int8_t  encoder_pulses[NUMBER_OF_ENCODERS] = {0};
>>>>>>> upstream/master

#ifdef SPLIT_KEYBOARD
// slave half encoders come over as second set of encoders
static int8_t encoder_value[NUMBER_OF_ENCODERS * 2] = {0};
#else
static int8_t encoder_value[NUMBER_OF_ENCODERS] = {0};
#endif

__attribute__ ((weak))
void encoder_update_user(int8_t index, bool clockwise) { }

__attribute__ ((weak))
void encoder_update_kb(int8_t index, bool clockwise) {
  encoder_update_user(index, clockwise);
}

void encoder_init(void) {
#if defined(SPLIT_KEYBOARD) && defined(ENCODERS_PAD_A_RIGHT) && defined(ENCODERS_PAD_B_RIGHT)
  if (!isLeftHand) {
    const pin_t encoders_pad_a_right[] = ENCODERS_PAD_A_RIGHT;
    const pin_t encoders_pad_b_right[] = ENCODERS_PAD_B_RIGHT;
    for (uint8_t i = 0; i < NUMBER_OF_ENCODERS; i++) {
      encoders_pad_a[i] = encoders_pad_a_right[i];
      encoders_pad_b[i] = encoders_pad_b_right[i];
    }
  }
#endif

  for (int i = 0; i < NUMBER_OF_ENCODERS; i++) {
    setPinInputHigh(encoders_pad_a[i]);
    setPinInputHigh(encoders_pad_b[i]);

<<<<<<< HEAD
    encoder_state[i] = (readPin(encoders_pad_a[i]) << 0) | (readPin(encoders_pad_b[i]) << 1);
  }
=======
#ifdef SPLIT_KEYBOARD
    thisHand = isLeftHand ? 0 : NUMBER_OF_ENCODERS;
    thatHand = NUMBER_OF_ENCODERS - thisHand;
#endif
}

static void encoder_update(int8_t index, uint8_t state) {
    uint8_t i = index;
#ifdef SPLIT_KEYBOARD
    index += thisHand;
#endif
    encoder_pulses[i] += encoder_LUT[state & 0xF];
    if (encoder_pulses[i] >= ENCODER_RESOLUTION) {
        encoder_value[index]++;
        encoder_update_kb(index, ENCODER_COUNTER_CLOCKWISE);
    }
    if (encoder_pulses[i] <= -ENCODER_RESOLUTION) {  // direction is arbitrary here, but this clockwise
        encoder_value[index]--;
        encoder_update_kb(index, ENCODER_CLOCKWISE);
    }
    encoder_pulses[i] %= ENCODER_RESOLUTION;
>>>>>>> upstream/master
}

void encoder_read(void) {
  for (int i = 0; i < NUMBER_OF_ENCODERS; i++) {
    encoder_state[i] <<= 2;
    encoder_state[i] |= (readPin(encoders_pad_a[i]) << 0) | (readPin(encoders_pad_b[i]) << 1);
    encoder_value[i] += encoder_LUT[encoder_state[i] & 0xF];
    if (encoder_value[i] >= ENCODER_RESOLUTION) {
        encoder_update_kb(i, false);
    }
    if (encoder_value[i] <= -ENCODER_RESOLUTION) { // direction is arbitrary here, but this clockwise
        encoder_update_kb(i, true);
    }
    encoder_value[i] %= ENCODER_RESOLUTION;
  }
}

#ifdef SPLIT_KEYBOARD
void encoder_state_raw(uint8_t* slave_state) {
  memcpy(slave_state, encoder_state, sizeof(encoder_state));
}

void encoder_update_raw(uint8_t* slave_state) {
<<<<<<< HEAD
  for (int i = 0; i < NUMBER_OF_ENCODERS; i++) {
    encoder_value[NUMBER_OF_ENCODERS + i] += encoder_LUT[slave_state[i] & 0xF];
    if (encoder_value[NUMBER_OF_ENCODERS + i] >= ENCODER_RESOLUTION) {
        encoder_update_kb(NUMBER_OF_ENCODERS + i, false);
    }
    if (encoder_value[NUMBER_OF_ENCODERS + i] <= -ENCODER_RESOLUTION) { // direction is arbitrary here, but this clockwise
        encoder_update_kb(NUMBER_OF_ENCODERS + i, true);
=======
    for (uint8_t i = 0; i < NUMBER_OF_ENCODERS; i++) {
        uint8_t index = i + thatHand;
        int8_t  delta = slave_state[i] - encoder_value[index];
        while (delta > 0) {
            delta--;
            encoder_value[index]++;
            encoder_update_kb(index, ENCODER_COUNTER_CLOCKWISE);
        }
        while (delta < 0) {
            delta++;
            encoder_value[index]--;
            encoder_update_kb(index, ENCODER_CLOCKWISE);
        }
>>>>>>> upstream/master
    }
    encoder_value[NUMBER_OF_ENCODERS + i] %= ENCODER_RESOLUTION;
  }
}
#endif
