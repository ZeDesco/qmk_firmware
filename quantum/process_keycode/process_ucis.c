/* Copyright 2017 Jack Humbert
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

#include "process_ucis.h"

qk_ucis_state_t qk_ucis_state;

void qk_ucis_start(void) {
  qk_ucis_state.count = 0;
  qk_ucis_state.in_progress = true;

  qk_ucis_start_user();
}

<<<<<<< HEAD
__attribute__((weak))
void qk_ucis_start_user(void) {
  unicode_input_start();
  register_hex(0x2328);
  unicode_input_finish();
=======
__attribute__((weak)) void qk_ucis_start_user(void) {
    unicode_input_start();
    register_hex(0x2328);  // ⌨
    unicode_input_finish();
>>>>>>> upstream/master
}

__attribute__((weak))
void qk_ucis_success(uint8_t symbol_index) {
}

static bool is_uni_seq(char *seq) {
<<<<<<< HEAD
  uint8_t i;

  for (i = 0; seq[i]; i++) {
    uint16_t code;
    if (('1' <= seq[i]) && (seq[i] <= '0'))
      code = seq[i] - '1' + KC_1;
    else
      code = seq[i] - 'a' + KC_A;

    if (i > qk_ucis_state.count || qk_ucis_state.codes[i] != code)
      return false;
  }

  return (qk_ucis_state.codes[i] == KC_ENT ||
          qk_ucis_state.codes[i] == KC_SPC);
}

__attribute__((weak))
void qk_ucis_symbol_fallback (void) {
  for (uint8_t i = 0; i < qk_ucis_state.count - 1; i++) {
    uint8_t code = qk_ucis_state.codes[i];
    register_code(code);
    unregister_code(code);
    wait_ms(UNICODE_TYPE_DELAY);
  }
=======
    uint8_t i;
    for (i = 0; seq[i]; i++) {
        uint16_t keycode;
        if ('1' <= seq[i] && seq[i] <= '0') {
            keycode = seq[i] - '1' + KC_1;
        } else {
            keycode = seq[i] - 'a' + KC_A;
        }
        if (i > qk_ucis_state.count || qk_ucis_state.codes[i] != keycode) {
            return false;
        }
    }
    return qk_ucis_state.codes[i] == KC_ENT || qk_ucis_state.codes[i] == KC_SPC;
}

__attribute__((weak)) void qk_ucis_symbol_fallback(void) {
    for (uint8_t i = 0; i < qk_ucis_state.count - 1; i++) {
        uint8_t keycode = qk_ucis_state.codes[i];
        register_code(keycode);
        unregister_code(keycode);
        wait_ms(UNICODE_TYPE_DELAY);
    }
>>>>>>> upstream/master
}

__attribute__((weak))
void qk_ucis_cancel(void) {
}

<<<<<<< HEAD
void register_ucis(const char *hex) {
  for(int i = 0; hex[i]; i++) {
    uint8_t kc = 0;
    char c = hex[i];

    switch (c) {
    case '0':
      kc = KC_0;
      break;
    case '1' ... '9':
      kc = c - '1' + KC_1;
      break;
    case 'a' ... 'f':
      kc = c - 'a' + KC_A;
      break;
    case 'A' ... 'F':
      kc = c - 'A' + KC_A;
      break;
=======
void register_ucis(const uint32_t *code_points) {
    for (int i = 0; i < UCIS_MAX_CODE_POINTS && code_points[i]; i++) {
        register_unicode(code_points[i]);
        wait_ms(UNICODE_TYPE_DELAY);
>>>>>>> upstream/master
    }

    if (kc) {
      register_code (kc);
      unregister_code (kc);
      wait_ms (UNICODE_TYPE_DELAY);
    }
  }
}

<<<<<<< HEAD
bool process_ucis (uint16_t keycode, keyrecord_t *record) {
  uint8_t i;

  if (!qk_ucis_state.in_progress)
    return true;

  if (qk_ucis_state.count >= UCIS_MAX_SYMBOL_LENGTH &&
      !(keycode == KC_BSPC || keycode == KC_ESC || keycode == KC_SPC || keycode == KC_ENT)) {
    return false;
  }

  if (!record->event.pressed)
    return true;

  qk_ucis_state.codes[qk_ucis_state.count] = keycode;
  qk_ucis_state.count++;

  if (keycode == KC_BSPC) {
    if (qk_ucis_state.count >= 2) {
      qk_ucis_state.count -= 2;
      return true;
    } else {
      qk_ucis_state.count--;
      return false;
=======
bool process_ucis(uint16_t keycode, keyrecord_t *record) {
    if (!qk_ucis_state.in_progress || !record->event.pressed) {
        return true;
    }

    bool special = keycode == KC_SPC || keycode == KC_ENT || keycode == KC_ESC || keycode == KC_BSPC;
    if (qk_ucis_state.count >= UCIS_MAX_SYMBOL_LENGTH && !special) {
        return false;
>>>>>>> upstream/master
    }
  }

<<<<<<< HEAD
  if (keycode == KC_ENT || keycode == KC_SPC || keycode == KC_ESC) {
    bool symbol_found = false;

    for (i = qk_ucis_state.count; i > 0; i--) {
      register_code (KC_BSPC);
      unregister_code (KC_BSPC);
      wait_ms(UNICODE_TYPE_DELAY);
    }

    if (keycode == KC_ESC) {
      qk_ucis_state.in_progress = false;
      qk_ucis_cancel();
      return false;
    }

    unicode_input_start();
    for (i = 0; ucis_symbol_table[i].symbol; i++) {
      if (is_uni_seq (ucis_symbol_table[i].symbol)) {
        symbol_found = true;
        register_ucis(ucis_symbol_table[i].code + 2);
        break;
      }
    }
    if (!symbol_found) {
      qk_ucis_symbol_fallback();
    }
    unicode_input_finish();

    if (symbol_found) {
      qk_ucis_success(i);
    }

    qk_ucis_state.in_progress = false;
    return false;
  }
  return true;
=======
    qk_ucis_state.codes[qk_ucis_state.count] = keycode;
    qk_ucis_state.count++;

    switch (keycode) {
        case KC_BSPC:
            if (qk_ucis_state.count >= 2) {
                qk_ucis_state.count -= 2;
                return true;
            } else {
                qk_ucis_state.count--;
                return false;
            }

        case KC_SPC:
        case KC_ENT:
        case KC_ESC:
            for (uint8_t i = 0; i < qk_ucis_state.count; i++) {
                register_code(KC_BSPC);
                unregister_code(KC_BSPC);
                wait_ms(UNICODE_TYPE_DELAY);
            }

            if (keycode == KC_ESC) {
                qk_ucis_state.in_progress = false;
                qk_ucis_cancel();
                return false;
            }

            uint8_t i;
            bool    symbol_found = false;
            for (i = 0; ucis_symbol_table[i].symbol; i++) {
                if (is_uni_seq(ucis_symbol_table[i].symbol)) {
                    symbol_found = true;
                    register_ucis(ucis_symbol_table[i].code_points);
                    break;
                }
            }
            if (symbol_found) {
                qk_ucis_success(i);
            } else {
                qk_ucis_symbol_fallback();
            }

            qk_ucis_state.in_progress = false;
            return false;

        default:
            return true;
    }
>>>>>>> upstream/master
}
