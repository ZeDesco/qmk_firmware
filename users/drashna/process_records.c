#include "drashna.h"

uint16_t copy_paste_timer;

__attribute__((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

__attribute__((weak))
bool process_record_secrets(uint16_t keycode, keyrecord_t *record) { return true; }

// Defines actions tor my global custom keycodes. Defined in drashna.h file
// Then runs the _keymap's record handier if not processed here
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef KEYLOGGER_ENABLE
#    if defined(KEYBOARD_ergodox_ez) || defined(KEYBOARD_keebio_iris_rev2)
    xprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.row, record->event.key.col, record->event.pressed);
#    else
    xprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
#    endif
#endif  // KEYLOGGER_ENABLE
#ifdef OLED_DRIVER_ENABLE
    process_record_user_oled(keycode, record);
#endif  // OLED

<<<<<<< HEAD
    switch (keycode) {
        case KC_QWERTY ... KC_CARPLAX:
            if (record->event.pressed) {
                set_single_persistent_default_layer(keycode - KC_QWERTY);
            }
            break;

        case KC_MAKE:  // Compiles the firmware, and adds the flash command based on keyboard bootloader
            if (!record->event.pressed) {
                uint8_t temp_mod = get_mods();
                uint8_t temp_osm = get_oneshot_mods();
                clear_mods();
                clear_oneshot_mods();
                send_string_with_delay_P(PSTR("make " QMK_KEYBOARD ":" QMK_KEYMAP), TAP_CODE_DELAY);
=======
    if (process_record_keymap(keycode, record) && process_record_secrets(keycode, record)
#ifdef RGB_MATRIX_ENABLE
        && process_record_user_rgb_matrix(keycode, record)
#endif
#ifdef RGBLIGHT_ENABLE
        && process_record_user_rgb_light(keycode, record)
#endif
    ) {
        switch (keycode) {
            case KC_QWERTY ... KC_WORKMAN:
                if (record->event.pressed) {
                    uint8_t mods = mod_config(get_mods() | get_oneshot_mods());
                    if (!mods) {
                        set_single_persistent_default_layer(keycode - KC_QWERTY);
                    } else if (mods & MOD_MASK_SHIFT) {
                        set_single_persistent_default_layer(keycode - KC_QWERTY + 4);
                    } else if (mods & MOD_MASK_CTRL) {
                        set_single_persistent_default_layer(keycode - KC_QWERTY + 8);
                    }
                }
                break;

            case KC_MAKE:  // Compiles the firmware, and adds the flash command based on keyboard bootloader
                if (!record->event.pressed) {
>>>>>>> upstream/master
#ifndef MAKE_BOOTLOADER
                    uint8_t temp_mod = mod_config(get_mods());
                    uint8_t temp_osm = mod_config(get_oneshot_mods());
                    clear_mods();
                    clear_oneshot_mods();
#endif
<<<<<<< HEAD
                {
#if defined(__arm__)
                    send_string_with_delay_P(PSTR(":dfu-util"), TAP_CODE_DELAY);
#elif defined(BOOTLOADER_DFU)
                    send_string_with_delay_P(PSTR(":dfu"), TAP_CODE_DELAY);
#elif defined(BOOTLOADER_HALFKAY)
                    send_string_with_delay_P(PSTR(":teensy"), TAP_CODE_DELAY);
#elif defined(BOOTLOADER_CATERINA)
                    send_string_with_delay_P(PSTR(":avrdude"), TAP_CODE_DELAY);
#endif  // bootloader options
                }
                if ((temp_mod | temp_osm) & MOD_MASK_CTRL) {
                    send_string_with_delay_P(PSTR(" -j8 --output-sync"), TAP_CODE_DELAY);
                }
=======
                    send_string_with_delay_P(PSTR("qmk"), TAP_CODE_DELAY);
#ifndef MAKE_BOOTLOADER
                    if ((temp_mod | temp_osm) & MOD_MASK_SHIFT)
#endif
                    {
                        send_string_with_delay_P(PSTR(" flash "), TAP_CODE_DELAY);
#ifndef MAKE_BOOTLOADER
                    } else {
                        send_string_with_delay_P(PSTR(" compile "), TAP_CODE_DELAY);
#endif
                    }
                    send_string_with_delay_P(PSTR("-kb " QMK_KEYBOARD " -km " QMK_KEYMAP), TAP_CODE_DELAY);
>>>>>>> upstream/master
#ifdef RGB_MATRIX_SPLIT_RIGHT
                    send_string_with_delay_P(PSTR(" RGB_MATRIX_SPLIT_RIGHT=yes"), TAP_CODE_DELAY);
#    ifndef OLED_DRIVER_ENABLE
                    send_string_with_delay_P(PSTR(" OLED_DRIVER_ENABLE=no"), TAP_CODE_DELAY);
#    endif
#endif
                    send_string_with_delay_P(PSTR(SS_TAP(X_ENTER)), TAP_CODE_DELAY);
                }

                break;

            case VRSN:  // Prints firmware version
                if (record->event.pressed) {
                    send_string_with_delay_P(PSTR(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION ", Built on: " QMK_BUILDDATE), TAP_CODE_DELAY);
                }
                break;

<<<<<<< HEAD
            // These are a serious of gaming macros.
            // Only enables for the viterbi, basically,
            // to save on firmware space, since it's limited.
#ifdef MACROS_ENABLED
        case KC_OVERWATCH:  // Toggle's if we hit "ENTER" or "BACKSPACE" to input macros
            if (record->event.pressed) {
                userspace_config.is_overwatch ^= 1;
                eeconfig_update_user(userspace_config.raw);
            }
#    ifdef RGBLIGHT_ENABLE
            userspace_config.is_overwatch ? rgblight_mode_noeeprom(17) : rgblight_mode_noeeprom(18);
#    endif  // RGBLIGHT_ENABLE
            break;
        case KC_SALT:
            return send_game_macro("Salt, salt, salt...", record, false);
        case KC_MORESALT:
            return send_game_macro("Please sir, can I have some more salt?!", record, false);
        case KC_SALTHARD:
            return send_game_macro("Your salt only makes me harder, and even more aggressive!", record, false);
        case KC_GOODGAME:
            return send_game_macro("Good game, everyone!", record, false);
        case KC_GLHF:
            return send_game_macro("Good luck, have fun!!!", record, false);
        case KC_SYMM:
            return send_game_macro("Left click to win!", record, false);
        case KC_JUSTGAME:
            return send_game_macro("It may be a game, but if you don't want to actually try, please go play AI, so that people that actually want to take the game seriously and \"get good\" have a place to do so without trolls like you throwing games.", record, false);
        case KC_TORB:
            return send_game_macro("That was positively riveting!", record, false);
        case KC_AIM:
            send_game_macro("That aim is absolutely amazing. It's almost like you're a machine!", record, true);
            return send_game_macro("Wait! That aim is TOO good!  You're clearly using an aim hack! CHEATER!", record, false);
        case KC_C9:
            return send_game_macro("OMG!!!  C9!!!", record, false);
        case KC_GGEZ:
            return send_game_macro("That was a fantastic game, though it was a bit easy. Try harder next time!", record, false);
#endif  // MACROS_ENABLED

        case KC_DIABLO_CLEAR:  // reset all Diablo timers, disabling them
=======
            case KC_DIABLO_CLEAR:  // reset all Diablo timers, disabling them
>>>>>>> upstream/master
#ifdef TAP_DANCE_ENABLE
                if (record->event.pressed) {
                    for (uint8_t index = 0; index < 4; index++) {
                        diablo_timer[index].key_interval = 0;
                    }
                }
#endif  // TAP_DANCE_ENABLE
                break;

            case KC_CCCV:  // One key copy/paste
                if (record->event.pressed) {
                    copy_paste_timer = timer_read();
                } else {
                    if (timer_elapsed(copy_paste_timer) > TAPPING_TERM) {  // Hold, copy
                        tap_code16(LCTL(KC_C));
                    } else {  // Tap, paste
                        tap_code16(LCTL(KC_V));
                    }
                }
                break;
#ifdef UNICODE_ENABLE
            case UC_FLIP:  // (ノಠ痊ಠ)ノ彡┻━┻
                if (record->event.pressed) {
                    send_unicode_string("(ノಠ痊ಠ)ノ彡┻━┻");
                }
                break;
            case UC_TABL:  // ┬─┬ノ( º _ ºノ)
                if (record->event.pressed) {
                    send_unicode_string("┬─┬ノ( º _ ºノ)");
                }
                break;
            case UC_SHRG:  // ¯\_(ツ)_/¯
                if (record->event.pressed) {
                    send_unicode_string("¯\\_(ツ)_/¯");
                }
                break;
            case UC_DISA:  // ಠ_ಠ
                if (record->event.pressed) {
                    send_unicode_string("ಠ_ಠ");
                }
                break;
#endif
            case KC_RGB_T:  // This allows me to use underglow as layer indication, or as normal
#if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
                if (record->event.pressed) {
                    userspace_config.rgb_layer_change ^= 1;
                    dprintf("rgblight layer change [EEPROM]: %u\n", userspace_config.rgb_layer_change);
                    eeconfig_update_user(userspace_config.raw);
                    if (userspace_config.rgb_layer_change) {
#    if defined(RGBLIGHT_ENABLE) && defined(RGB_MATRIX_ENABLE)
                        rgblight_enable_noeeprom();
#    endif
                        layer_state_set(layer_state);  // This is needed to immediately set the layer color (looks better)
#    if defined(RGBLIGHT_ENABLE) && defined(RGB_MATRIX_ENABLE)
                    } else {
                        rgblight_disable_noeeprom();
#    endif
                    }
                }
#endif  // RGBLIGHT_ENABLE
                break;

#if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
            case RGB_TOG:
                // Split keyboards need to trigger on key-up for edge-case issue
#    ifndef SPLIT_KEYBOARD
                if (record->event.pressed) {
#    else
                if (!record->event.pressed) {
#    endif
#    if defined(RGBLIGHT_ENABLE) && !defined(RGBLIGHT_DISABLE_KEYCODES)
                    rgblight_toggle();
#    endif
#    if defined(RGB_MATRIX_ENABLE) && !defined(RGB_MATRIX_DISABLE_KEYCODES)
                    rgb_matrix_toggle();
#    endif
                }
                return false;
                break;
            case RGB_MODE_FORWARD ... RGB_MODE_GRADIENT:  // quantum_keycodes.h L400 for definitions
                if (record->event.pressed) {
                    bool is_eeprom_updated;
#    if defined(RGBLIGHT_ENABLE) && !defined(RGBLIGHT_DISABLE_KEYCODES)
                    // This disables layer indication, as it's assumed that if you're changing this ... you want that disabled
                    if (userspace_config.rgb_layer_change) {
                        userspace_config.rgb_layer_change = false;
                        dprintf("rgblight layer change [EEPROM]: %u\n", userspace_config.rgb_layer_change);
                        is_eeprom_updated = true;
                    }
#    endif
#    if defined(RGB_MATRIX_ENABLE) && defined(RGB_MATRIX_FRAMEBUFFER_EFFECTS)
                    if (userspace_config.rgb_matrix_idle_anim) {
                        userspace_config.rgb_matrix_idle_anim = false;
                        dprintf("RGB Matrix Idle Animation [EEPROM]: %u\n", userspace_config.rgb_matrix_idle_anim);
                        is_eeprom_updated = true;
                    }
#    endif
                    if (is_eeprom_updated) {
                        eeconfig_update_user(userspace_config.raw);
                    }
                }

#    if defined(RGBLIGHT_DISABLE_KEYCODES) || defined(RGB_MATRIX_DISABLE_KEYCODES)
                if (keycode == RGB_MODE_FORWARD && record->event.pressed) {
                    uint8_t shifted = get_mods() & (MOD_MASK_SHIFT);
                    if (shifted) {
#        if defined(RGBLIGHT_ENABLE) && !defined(RGBLIGHT_DISABLE_KEYCODES)
                        rgblight_step_reverse();
#        endif
#        if defined(RGB_MATRIX_ENABLE) && !defined(RGB_MATRIX_DISABLE_KEYCODES)
                        rgb_matrix_step_reverse();
#        endif
                    } else {
#        if defined(RGBLIGHT_ENABLE) && !defined(RGBLIGHT_DISABLE_KEYCODES)
                        rgblight_step();
#        endif
#        if defined(RGB_MATRIX_ENABLE) && !defined(RGB_MATRIX_DISABLE_KEYCODES)
                        rgb_matrix_step();
#        endif
                    }
                } else if (keycode == RGB_MODE_REVERSE && record->event.pressed) {
                    uint8_t shifted = get_mods() & (MOD_MASK_SHIFT);
                    if (shifted) {
#        if defined(RGBLIGHT_ENABLE) && !defined(RGBLIGHT_DISABLE_KEYCODES)
                        rgblight_step();
#        endif
#        if defined(RGB_MATRIX_ENABLE) && !defined(RGB_MATRIX_DISABLE_KEYCODES)
                        rgb_matrix_step();
#        endif
                    } else {
#        if defined(RGBLIGHT_ENABLE) && !defined(RGBLIGHT_DISABLE_KEYCODES)
                        rgblight_step_reverse();
#        endif
#        if defined(RGB_MATRIX_ENABLE) && !defined(RGB_MATRIX_DISABLE_KEYCODES)
                        rgb_matrix_step_reverse();
#        endif
                    }
                } else if (keycode == RGB_HUI) {
#        ifndef SPLIT_KEYBOARD
                    if (record->event.pressed) {
#        else
                    if (!record->event.pressed) {
#        endif
#        if defined(RGBLIGHT_ENABLE) && !defined(RGBLIGHT_DISABLE_KEYCODES)
                        rgblight_increase_hue();
#        endif
#        if defined(RGB_MATRIX_ENABLE) && !defined(RGB_MATRIX_DISABLE_KEYCODES)
                        rgb_matrix_increase_hue();
#        endif
                    }
                } else if (keycode == RGB_HUD) {
#        ifndef SPLIT_KEYBOARD
                    if (record->event.pressed) {
#        else
                    if (!record->event.pressed) {
#        endif
#        if defined(RGBLIGHT_ENABLE) && !defined(RGBLIGHT_DISABLE_KEYCODES)
                        rgblight_decrease_hue();
#        endif
#        if defined(RGB_MATRIX_ENABLE) && !defined(RGB_MATRIX_DISABLE_KEYCODES)
                        rgb_matrix_decrease_hue();
#        endif
                    }
                } else if (keycode == RGB_SAI) {
#        ifndef SPLIT_KEYBOARD
                    if (record->event.pressed) {
#        else
                    if (!record->event.pressed) {
#        endif
#        if defined(RGBLIGHT_ENABLE) && !defined(RGBLIGHT_DISABLE_KEYCODES)
                        rgblight_increase_sat();
#        endif
#        if defined(RGB_MATRIX_ENABLE) && !defined(RGB_MATRIX_DISABLE_KEYCODES)
                        rgb_matrix_increase_sat();
#        endif
                    }
                } else if (keycode == RGB_SAD) {
#        ifndef SPLIT_KEYBOARD
                    if (record->event.pressed) {
#        else
                    if (!record->event.pressed) {
#        endif
#        if defined(RGBLIGHT_ENABLE) && !defined(RGBLIGHT_DISABLE_KEYCODES)
                        rgblight_decrease_sat();
#        endif
#        if defined(RGB_MATRIX_ENABLE) && !defined(RGB_MATRIX_DISABLE_KEYCODES)
                        rgb_matrix_decrease_sat();
#        endif
                    }
                } else if (keycode == RGB_VAI) {
#        ifndef SPLIT_KEYBOARD
                    if (record->event.pressed) {
#        else
                    if (!record->event.pressed) {
#        endif
#        if defined(RGBLIGHT_ENABLE) && !defined(RGBLIGHT_DISABLE_KEYCODES)
                        rgblight_increase_val();
#        endif
#        if defined(RGB_MATRIX_ENABLE) && !defined(RGB_MATRIX_DISABLE_KEYCODES)
                        rgb_matrix_increase_val();
#        endif
                    }
                } else if (keycode == RGB_VAD) {
#        ifndef SPLIT_KEYBOARD
                    if (record->event.pressed) {
#        else
                    if (!record->event.pressed) {
#        endif
#        if defined(RGBLIGHT_ENABLE) && !defined(RGBLIGHT_DISABLE_KEYCODES)
                        rgblight_decrease_val();
#        endif
#        if defined(RGB_MATRIX_ENABLE) && !defined(RGB_MATRIX_DISABLE_KEYCODES)
                        rgb_matrix_decrease_val();
#        endif
                    }
                } else if (keycode == RGB_SPI) {
                    if (record->event.pressed) {
#        if defined(RGBLIGHT_ENABLE) && !defined(RGBLIGHT_DISABLE_KEYCODES)
                        rgblight_increase_speed();
#        endif
#        if defined(RGB_MATRIX_ENABLE) && !defined(RGB_MATRIX_DISABLE_KEYCODES)
                        rgb_matrix_increase_speed();
#        endif
                    }
                } else if (keycode == RGB_SPD) {
                    if (record->event.pressed) {
#        if defined(RGBLIGHT_ENABLE) && !defined(RGBLIGHT_DISABLE_KEYCODES)
                        rgblight_decrease_speed();
#        endif
#        if defined(RGB_MATRIX_ENABLE) && !defined(RGB_MATRIX_DISABLE_KEYCODES)
                        rgb_matrix_decrease_speed();
#        endif
                    }
                }
                return false;
#    endif
#endif
        }
    }
    return true;
}
