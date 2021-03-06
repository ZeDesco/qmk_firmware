#pragma once

// Keyboard reports
#define FORCE_NKRO
#define USB_POLLING_INTERVAL_MS 1

// Mouse keys
#define MOUSEKEY_DELAY             0
#define MOUSEKEY_INTERVAL          10
#define MOUSEKEY_MAX_SPEED         4
#define MOUSEKEY_TIME_TO_MAX       100
#define MOUSEKEY_WHEEL_DELAY       0
#define MOUSEKEY_WHEEL_INTERVAL    50
#define MOUSEKEY_WHEEL_MAX_SPEED   4
#define MOUSEKEY_WHEEL_TIME_TO_MAX 50

// RGB lighting
#undef  RGBLIGHT_ANIMATIONS
#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_SNAKE

// Tapping
#define PERMISSIVE_HOLD
<<<<<<< HEAD
#define TAPPING_TERM        200
#define TAPPING_TOGGLE      2
#define TAP_HOLD_CAPS_DELAY 50
=======
#define TAPPING_TERM    200
#define TAPPING_TOGGLE  3
>>>>>>> upstream/master

// Unicode
#define UNICODE_CYCLE_PERSIST  false
#define UNICODE_SELECTED_MODES UC_WINC, UC_WIN, UC_LNX
#define UNICODE_KEY_WINC       KC_RGUI
<<<<<<< HEAD
=======

// Firmware size reduction
#undef  LOCKING_SUPPORT_ENABLE
#define NO_ACTION_FUNCTION
#define NO_ACTION_MACRO
#define NO_ACTION_ONESHOT
>>>>>>> upstream/master
