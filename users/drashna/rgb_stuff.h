#pragma once
#include "quantum.h"

<<<<<<< HEAD
=======
#if defined(RGBLIGHT_TWINKLE)
>>>>>>> upstream/master
typedef struct {
    bool     enabled;
    uint8_t  hue;
    uint16_t timer;
    uint8_t  life;
} rgblight_fadeout;

<<<<<<< HEAD
bool          process_record_user_rgb(uint16_t keycode, keyrecord_t *record);
void          scan_rgblight_fadeout(void);
void          keyboard_post_init_rgb(void);
void          matrix_scan_rgb(void);
layer_state_t layer_state_set_rgb(layer_state_t state);
layer_state_t default_layer_state_set_rgb(layer_state_t state);
void          rgblight_sethsv_default_helper(uint8_t index);
void          rgb_matrix_set_color_all(uint8_t red, uint8_t green, uint8_t blue);

void rgb_matrix_layer_helper(uint8_t hue, uint8_t sat, uint8_t val, uint8_t mode, uint8_t speed, uint8_t led_type);
=======
bool          process_record_user_rgb_light(uint16_t keycode, keyrecord_t *record);
void          keyboard_post_init_rgb_light(void);
void          matrix_scan_rgb_light(void);
layer_state_t layer_state_set_rgb_light(layer_state_t state);
layer_state_t default_layer_state_set_rgb_light(layer_state_t state);
void          rgblight_sethsv_default_helper(uint8_t index);

#if defined(RGBLIGHT_TWINKLE)
void scan_rgblight_fadeout(void);
#endif
>>>>>>> upstream/master
