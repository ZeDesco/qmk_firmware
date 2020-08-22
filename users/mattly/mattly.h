/* Copyright 2019 Matthew Lyon
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

#ifndef USERSPACE
#define USERSPACE

#include "quantum.h"

enum {
    _BASE_MAC,
    _OVER_WIN,
    _NAVNUM,
    _NAVNUM_WIN,
    _SYMBOL,
    _FUNCT,
    _FUNCT_WIN,
};

<<<<<<< HEAD
=======
// == System
#define TOG_WIN TG(_OVER_WIN)

// == Thumbs
>>>>>>> upstream/master
// left hand
#define ESC_HYP MT(MOD_HYPR, KC_ESC)
#define BSP_NUM LT(_NAVNUM, KC_BSPC)
#define ENT_SFT MT(MOD_LSFT, KC_ENT)
#define SPC_SFT MT(MOD_LSFT, KC_SPC)
<<<<<<< HEAD
=======
#define ENT_SYM LT(_SYMBOL, KC_ENT)
>>>>>>> upstream/master

// right hand
#define SPC_SFT MT(MOD_LSFT, KC_SPC)
#define TAB_SYM LT(_SYMBOL, KC_TAB)
#define DEL_WRP MT(MOD_LCTL | MOD_LALT | MOD_LGUI, KC_DEL)

#define NAVLOCK TG(_NAVNUM)
#define SYMLOCK TG(_SYMBOL)


<<<<<<< HEAD
// QWERTY

#define A_CTRL  MT(MOD_LCTL, KC_A)
#define S_ALT   MT(MOD_LALT, KC_S)
#define D_GUI   MT(MOD_LGUI, KC_D)
#define F_SHFT  MT(MOD_LSFT, KC_F)
#define J_SHFT  MT(MOD_RSFT, KC_J)
=======
// == QWERTY
// left hand home row
#define A_CTL  MT(MOD_LCTL, KC_A)
#define A_GUI  MT(MOD_LGUI, KC_A)
#define S_ALT  MT(MOD_LALT, KC_S)
#define D_GUI  MT(MOD_LGUI, KC_D)
#define D_CTL  MT(MOD_LCTL, KC_D)
#define F_SFT  MT(MOD_LSFT, KC_F)
// left hand aux
#define W_CTL  MT(MOD_LCTL, KC_W)
#define W_GUI  MT(MOD_LGUI, KC_W)
#define E_ALT  MT(MOD_LALT, KC_E)
#define R_GUI  MT(MOD_LGUI, KC_R)
#define R_CTL  MT(MOD_LCTL, KC_R)

// right hand home row
#define J_SFT   MT(MOD_RSFT, KC_J)
>>>>>>> upstream/master
#define K_GUI   MT(MOD_RGUI, KC_K)
#define K_CTL   MT(MOD_RCTL, KC_K)
#define L_ALT   MT(MOD_RALT, KC_L)
#define MINSCTL MT(MOD_RCTL, KC_MINS)
<<<<<<< HEAD

#define BWORD   LALT(KC_LEFT)
#define FWORD   LALT(KC_RIGHT)

// OS X default keys
#define NWIN    LGUI(KC_GRV)        // Next Window
#define PWIN    LGUI(LSFT(KC_GRV))  // Prev Window
#define NTAB    LGUI(LSFT(KC_RBRC)) // Next Tab
#define PTAB    LGUI(LSFT(KC_LBRC)) // Prev Tab
#define NAVBACK LGUI(KC_LBRC)       // Navigate Forward
#define NAVFWD  LGUI(KC_RBRC)       // Navigate Back

// my personal mappings to window manager commands
#define XALLWIN HYPR(KC_F14)
#define XDESKTP HYPR(KC_F15)
#define XNXTSPC HYPR(KC_F16)
#define XPRVSPC HYPR(KC_F17)
#define XNOTIFY HYPR(KC_F18)
=======
#define MINSGUI MT(MOD_RGUI, KC_MINS)
// right hand aux
#define U_GUI   MT(MOD_RGUI, KC_U)
#define U_CTL   MT(MOD_RCTL, KC_U)
#define I_ALT   MT(MOD_RALT, KC_I)
#define O_CTL   MT(MOD_RCTL, KC_O)
#define O_GUI   MT(MOD_RGUI, KC_O)

// == OS X default keys
// movement by word
#define M_BWORD LALT(KC_LEFT)
#define W_BWORD LCTL(KC_LEFT)
#define M_FWORD LALT(KC_RIGHT)
#define W_FWORD LCTL(KC_RIGHT)

// gui navigation
#define M_NXWIN  LGUI(KC_GRV)        // Next Window
#define W_NXWIN LALT(KC_TAB)
#define M_PVWIN  LGUI(LSFT(KC_GRV))  // Prev Window
#define W_PVWIN LALT(LSFT(KC_TAB))
#define M_NXTAB  LGUI(LSFT(KC_RBRC)) // Next Tab
#define W_NXTAB LCTL(KC_PGDN)
#define M_PVTAB  LGUI(LSFT(KC_LBRC)) // Prev Tab
#define W_PVTAB LCTL(KC_PGUP)
#define M_NAVBK LGUI(KC_LBRC)       // Navigate Forward
#define W_NAVBK LALT(KC_LEFT)
#define M_NAVFW LGUI(KC_RBRC)       // Navigate Back
#define W_NAVFW LALT(KC_RIGHT)
>>>>>>> upstream/master

#ifdef RGBLIGHT_ENABLE
<<<<<<< HEAD
#define HSV_CAPS     42, 255, 255
#define HSV_DEFAULT  30, 218, 255
#define HSV_SYMBOL   22, 255, 255
#define HSV_NAVNUM  245, 200, 255
#define HSV_FUNCT   233, 255, 255
=======
#define HSV_CAPS     55, 255, 255
#define HSV_ERR      30, 196, 196
#define HSV_MAC      20, 255, 128
#define HSV_WIN      10, 255, 128
#define HSV_SYMBOL  235, 255, 255
#define HSV_NAVNUM  250, 255, 255
#define HSV_FUNCT   210, 255, 255
>>>>>>> upstream/master
#define HSV_RESET   180, 255, 255
#endif

#endif

