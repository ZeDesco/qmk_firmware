#include "drashna.h"
#include "rgb_stuff.h"
#include "eeprom.h"

<<<<<<< HEAD
#if defined(RGBLIGHT_ENABLE)
extern rgblight_config_t rgblight_config;
bool                     has_initialized;
#endif

#ifdef RGBLIGHT_ENABLE
void rgblight_sethsv_default_helper(uint8_t index) { rgblight_sethsv_at(rgblight_config.hue, rgblight_config.sat, rgblight_config.val, index); }
#endif  // RGBLIGHT_ENABLE

#ifdef INDICATOR_LIGHTS
void set_rgb_indicators(uint8_t this_mod, uint8_t this_led, uint8_t this_osm) {
    if (userspace_config.rgb_layer_change && biton32(layer_state) == 0) {
        if ((this_mod | this_osm) & MOD_MASK_SHIFT || this_led & (1 << USB_LED_CAPS_LOCK)) {
#    ifdef SHFT_LED1
            rgblight_sethsv_at(120, 255, 255, SHFT_LED1);
#    endif  // SHFT_LED1
#    ifdef SHFT_LED2
            rgblight_sethsv_at(120, 255, 255, SHFT_LED2);
#    endif  // SHFT_LED2
        } else {
#    ifdef SHFT_LED1
            rgblight_sethsv_default_helper(SHFT_LED1);
#    endif  // SHFT_LED1
#    ifdef SHFT_LED2
            rgblight_sethsv_default_helper(SHFT_LED2);
#    endif  // SHFT_LED2
        }
        if ((this_mod | this_osm) & MOD_MASK_CTRL) {
#    ifdef CTRL_LED1
            rgblight_sethsv_at(0, 255, 255, CTRL_LED1);
#    endif  // CTRL_LED1
#    ifdef CTRL_LED2
            rgblight_sethsv_at(0, 255, 255, CTRL_LED2);
#    endif  // CTRL_LED2
        } else {
#    ifdef CTRL_LED1
            rgblight_sethsv_default_helper(CTRL_LED1);
#    endif  // CTRL_LED1
#    ifdef CTRL_LED2
            rgblight_sethsv_default_helper(CTRL_LED2);
#    endif  // CTRL_LED2
        }
        if ((this_mod | this_osm) & MOD_MASK_GUI) {
#    ifdef GUI_LED1
            rgblight_sethsv_at(51, 255, 255, GUI_LED1);
#    endif  // GUI_LED1
#    ifdef GUI_LED2
            rgblight_sethsv_at(51, 255, 255, GUI_LED2);
#    endif  // GUI_LED2
        } else {
#    ifdef GUI_LED1
            rgblight_sethsv_default_helper(GUI_LED1);
#    endif  // GUI_LED1
#    ifdef GUI_LED2
            rgblight_sethsv_default_helper(GUI_LED2);
#    endif  // GUI_LED2
        }
        if ((this_mod | this_osm) & MOD_MASK_ALT) {
#    ifdef ALT_LED1
            rgblight_sethsv_at(240, 255, 255, ALT_LED1);
#    endif  // ALT_LED1
#    ifdef GUI_LED2
            rgblight_sethsv_at(240, 255, 255, ALT_LED2);
#    endif  // GUI_LED2
        } else {
#    ifdef GUI_LED1
            rgblight_sethsv_default_helper(ALT_LED1);
#    endif  // GUI_LED1
#    ifdef GUI_LED2
            rgblight_sethsv_default_helper(ALT_LED2);
#    endif  // GUI_LED2
        }
    }
}

void matrix_scan_indicator(void) {
    if (has_initialized) {
        set_rgb_indicators(get_mods(), host_keyboard_leds(), get_oneshot_mods());
    }
}
#endif  // INDICATOR_LIGHTS
=======
bool    has_initialized;

void rgblight_sethsv_default_helper(uint8_t index) { rgblight_sethsv_at(rgblight_get_hue(), rgblight_get_sat(), rgblight_get_val(), index); }
>>>>>>> upstream/master

#ifdef RGBLIGHT_TWINKLE
static rgblight_fadeout lights[RGBLED_NUM];

<<<<<<< HEAD
__attribute__((weak)) bool rgblight_twinkle_is_led_used_keymap(uint8_t index) { return false; }

bool rgblight_twinkle_is_led_used(uint8_t index) {
    switch (index) {
#    ifdef INDICATOR_LIGHTS
#        ifdef SHFT_LED1
        case SHFT_LED1:
            return true;
#        endif  // SHFT_LED1
#        ifdef SHFT_LED2
        case SHFT_LED2:
            return true;
#        endif  // SHFT_LED2
#        ifdef CTRL_LED1
        case CTRL_LED1:
            return true;
#        endif  // CTRL_LED1
#        ifdef CTRL_LED2
        case CTRL_LED2:
            return true;
#        endif  // CTRL_LED2
#        ifdef GUI_LED1
        case GUI_LED1:
            return true;
#        endif  // GUI_LED1
#        ifdef GUI_LED2
        case GUI_LED2:
            return true;
#        endif  // GUI_LED2
#        ifdef ALT_LED1
        case ALT_LED1:
            return true;
#        endif  // ALT_LED1
#        ifdef ALT_LED2
        case ALT_LED2:
            return true;
#        endif  // ALT_LED2
#    endif      // INDICATOR_LIGHTS
        default:
            return rgblight_twinkle_is_led_used_keymap(index);
    }
}

=======
/* Handler for fading/twinkling effect */
>>>>>>> upstream/master
void scan_rgblight_fadeout(void) {  // Don't effing change this function .... rgblight_sethsv is supppppper intensive
    bool litup = false;

    for (uint8_t light_index = 0; light_index < RGBLED_NUM; ++light_index) {
        if (lights[light_index].enabled && timer_elapsed(lights[light_index].timer) > 10) {
            rgblight_fadeout *light = &lights[light_index];
            litup                   = true;

            if (light->life) {
                light->life -= 1;
                if (biton32(layer_state) == 0) {
                    sethsv(light->hue + rand() % 0xF, 255, light->life, (LED_TYPE *)&led[light_index]);
                }
                light->timer = timer_read();
            } else {
                if (light->enabled && biton32(layer_state) == 0) {
                    rgblight_sethsv_default_helper(light_index);
                }
                litup = light->enabled = false;
            }
        }
    }
    if (litup && biton32(layer_state) == 0) {
        rgblight_set();
    }
}

void start_rgb_light(void) {
    uint8_t indices[RGBLED_NUM];
    uint8_t indices_count  = 0;
    uint8_t min_life       = 0xFF;
    uint8_t min_life_index = -1;

    for (uint8_t index = 0; index < RGBLED_NUM; ++index) {
        if (lights[index].enabled) {
            if (min_life_index == -1 || lights[index].life < min_life) {
                min_life       = lights[index].life;
                min_life_index = index;
            }
            continue;
        }

        indices[indices_count] = index;
        ++indices_count;
    }

    uint8_t light_index;
    if (!indices_count) {
        light_index = min_life_index;
    } else {
        light_index = indices[rand() % indices_count];
    }

    rgblight_fadeout *light = &lights[light_index];
    light->enabled          = true;
    light->timer            = timer_read();
    light->life             = 0xC0 + rand() % 0x40;

    light->hue = rgblight_get_hue() + (rand() % 0xB4) - 0x54;

    rgblight_sethsv_at(light->hue, 255, light->life, light_index);
}
#endif

<<<<<<< HEAD
bool process_record_user_rgb(uint16_t keycode, keyrecord_t *record) {
=======
bool process_record_user_rgb_light(uint16_t keycode, keyrecord_t *record) {
    uint16_t temp_keycode = keycode;
    // Filter out the actual keycode from MT and LT keys.
>>>>>>> upstream/master
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
        keycode = keycode & 0xFF;
    }
<<<<<<< HEAD
    switch (keycode) {
=======

    switch (temp_keycode) {
>>>>>>> upstream/master
#ifdef RGBLIGHT_TWINKLE
        case KC_A ... KC_SLASH:
        case KC_F1 ... KC_F12:
        case KC_INSERT ... KC_UP:
        case KC_KP_SLASH ... KC_KP_DOT:
        case KC_F13 ... KC_F24:
        case KC_AUDIO_MUTE ... KC_MEDIA_REWIND:
            if (record->event.pressed) {
                start_rgb_light();
            }
            return true;
            break;
<<<<<<< HEAD
#endif                  // RGBLIGHT_TWINKLE
        case KC_RGB_T:  // This allows me to use underglow as layer indication, or as normal
#if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
            if (record->event.pressed) {
                userspace_config.rgb_layer_change ^= 1;
                xprintf("rgblight layer change [EEPROM]: %u\n", userspace_config.rgb_layer_change);
                eeconfig_update_user(userspace_config.raw);
                if (userspace_config.rgb_layer_change) {
                    layer_state_set(layer_state);  // This is needed to immediately set the layer color (looks better)
                }
            }
#endif  // RGBLIGHT_ENABLE
            return false;
            break;
#ifdef RGBLIGHT_ENABLE
        case RGB_MODE_FORWARD ... RGB_MODE_GRADIENT:  // quantum_keycodes.h L400 for definitions
            if (record->event.pressed) {              // This disables layer indication, as it's assumed that if you're changing this ... you want that disabled
                if (userspace_config.rgb_layer_change) {
                    userspace_config.rgb_layer_change = false;
                    xprintf("rgblight layer change [EEPROM]: %u\n", userspace_config.rgb_layer_change);
                    eeconfig_update_user(userspace_config.raw);
                }
            }
            return true;
            break;
#endif  // RGBLIGHT_ENABLE
=======
#endif  // RGBLIGHT_TWINKLE
>>>>>>> upstream/master
    }
    return true;
}

<<<<<<< HEAD
void keyboard_post_init_rgb(void) {
#if defined(RGBLIGHT_ENABLE) && defined(RGBLIGHT_STARTUP_ANIMATION)
    bool is_enabled = rgblight_config.enable;
=======
#if defined(RGBLIGHT_STARTUP_ANIMATION)
static bool is_enabled;
static bool is_rgblight_startup;
static uint8_t old_hue;
static uint16_t rgblight_startup_loop_timer;
#endif

void keyboard_post_init_rgb_light(void) {
#if defined(RGBLIGHT_STARTUP_ANIMATION)
    is_enabled = rgblight_is_enabled();
>>>>>>> upstream/master
    if (userspace_config.rgb_layer_change) {
        rgblight_enable_noeeprom();
    }
    if (rgblight_is_enabled()) {
        layer_state_set_rgb_light(layer_state);
        old_hue = rgblight_get_hue();
        rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
<<<<<<< HEAD
        for (uint16_t i = 255; i > 0; i--) {
            rgblight_sethsv_noeeprom((i + old_hue) % 255, 255, 255);
            matrix_scan();
            wait_ms(10);
        }
    }
    if (!is_enabled) {
        rgblight_disable_noeeprom();
    }

#endif
    layer_state_set_user(layer_state);
}

void matrix_scan_rgb(void) {
#ifdef RGBLIGHT_TWINKLE
=======
        is_rgblight_startup = true;
    }
#endif
    layer_state_set_rgb_light(layer_state);
}

void matrix_scan_rgb_light(void) {
#    ifdef RGBLIGHT_TWINKLE
>>>>>>> upstream/master
    scan_rgblight_fadeout();
#endif  // RGBLIGHT_ENABLE

<<<<<<< HEAD
#ifdef INDICATOR_LIGHTS
    matrix_scan_indicator();
#endif
}

layer_state_t layer_state_set_rgb(layer_state_t state) {
=======
#if defined(RGBLIGHT_STARTUP_ANIMATION)
    if (is_rgblight_startup && is_keyboard_master()) {
        if (timer_elapsed(rgblight_startup_loop_timer) > 10) {
            static uint8_t counter;
            counter++;
            rgblight_sethsv_noeeprom((counter + old_hue) % 255, 255, 255);
            rgblight_startup_loop_timer = timer_read();
            if (counter == 255) {
                is_rgblight_startup = false;
                if (!is_enabled) {
                    rgblight_disable_noeeprom();
                }
                if (userspace_config.rgb_layer_change) {
                    layer_state_set_rgb_light(layer_state);
                }
            }
        }
    }
#endif
}

void rgblight_set_hsv_and_mode(uint8_t hue, uint8_t sat, uint8_t val, uint8_t mode) {
    rgblight_sethsv_noeeprom(hue, sat, val);
    wait_us(175);  // Add a slight delay between color and mode to ensure it's processed correctly
    rgblight_mode_noeeprom(mode);
}

layer_state_t layer_state_set_rgb_light(layer_state_t state) {
>>>>>>> upstream/master
#ifdef RGBLIGHT_ENABLE
    if (userspace_config.rgb_layer_change) {
        switch (biton32(state)) {
            case _MACROS:
                rgblight_sethsv_noeeprom_orange();
                userspace_config.is_overwatch ? rgblight_mode_noeeprom(RGBLIGHT_MODE_SNAKE + 2) : rgblight_mode_noeeprom(RGBLIGHT_MODE_SNAKE + 3);
                break;
            case _MEDIA:
                rgblight_sethsv_noeeprom_chartreuse();
                rgblight_mode_noeeprom(RGBLIGHT_MODE_KNIGHT + 1);
                break;
            case _GAMEPAD:
                rgblight_sethsv_noeeprom_orange();
                rgblight_mode_noeeprom(RGBLIGHT_MODE_SNAKE + 2);
                break;
            case _DIABLO:
                rgblight_sethsv_noeeprom_red();
                rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 3);
                break;
            case _RAISE:
                rgblight_sethsv_noeeprom_yellow();
                rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 3);
                break;
            case _LOWER:
                rgblight_sethsv_noeeprom_green();
                rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 3);
                break;
            case _ADJUST:
                rgblight_sethsv_noeeprom_red();
                rgblight_mode_noeeprom(RGBLIGHT_MODE_KNIGHT + 2);
                break;
            default:  //  for any other layers, or the default layer
                switch (biton32(default_layer_state)) {
                    case _COLEMAK:
                        rgblight_sethsv_noeeprom_magenta();
                        break;
                    case _DVORAK:
                        rgblight_sethsv_noeeprom_springgreen();
                        break;
                    case _WORKMAN:
                        rgblight_sethsv_noeeprom_goldenrod();
                        break;
                    case _NORMAN:
                        rgblight_sethsv_noeeprom_coral();
                        break;
                    case _MALTRON:
                        rgblight_sethsv_noeeprom_yellow();
                        break;
                    case _EUCALYN:
                        rgblight_sethsv_noeeprom_pink();
                        break;
                    case _CARPLAX:
                        rgblight_sethsv_noeeprom_blue();
                        break;
                    default:
                        rgblight_sethsv_noeeprom_cyan();
                        break;
                }
                biton32(state) == _MODS ? rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING) : rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);  // if _MODS layer is on, then breath to denote it
                break;
        }
    }
#endif  // RGBLIGHT_ENABLE

    return state;
}
<<<<<<< HEAD

#ifdef RGB_MATRIX_ENABLE
#    include "lib/lib8tion/lib8tion.h"
extern led_config_t g_led_config;
void rgb_matrix_layer_helper(uint8_t hue, uint8_t sat, uint8_t val, uint8_t mode, uint8_t speed, uint8_t led_type) {
    HSV hsv = {hue, sat, val};
    if (hsv.v > rgb_matrix_config.hsv.v) {
        hsv.v = rgb_matrix_config.hsv.v;
    }

    switch (mode) {
        case 1:  // breathing
        {
            uint16_t time = scale16by8(g_rgb_counters.tick, speed / 8);
            hsv.v         = scale8(abs8(sin8(time) - 128) * 2, hsv.v);
            RGB rgb       = hsv_to_rgb(hsv);
            for (uint8_t i = 0; i < DRIVER_LED_TOTAL; i++) {
                if (HAS_FLAGS(g_led_config.flags[i], led_type)) {
                    rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
                }
            }
            break;
        }
        default:  // Solid Color
        {
            RGB rgb = hsv_to_rgb(hsv);
            for (uint8_t i = 0; i < DRIVER_LED_TOTAL; i++) {
                if (HAS_FLAGS(g_led_config.flags[i], led_type)) {
                    rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
                }
            }
            break;
        }
    }
}
#endif
=======
>>>>>>> upstream/master
