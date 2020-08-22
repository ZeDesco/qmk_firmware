/* Copyright 2016 Artyom Mironov
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

#pragma once

#include "keymap.h"

<<<<<<< HEAD
// Normal characters
#define DP_DLR	KC_GRV
#define DP_AMPR	KC_1
#define DP_LBRC	KC_2
#define DP_LCBR	KC_3
#define DP_RCBR	KC_4
#define DP_LPRN	KC_5
#define DP_EQL	KC_6
#define DP_ASTR	KC_7
#define DP_RPRN	KC_8
#define DP_PLUS	KC_9
#define DP_RBRC	KC_0
#define DP_EXLM	KC_MINS
#define DP_HASH	KC_EQL

#define DP_SCLN	KC_Q
#define DP_COMM	KC_W
#define DP_DOT	KC_E
#define DP_P	KC_R
#define DP_Y	KC_T
#define DP_F	KC_Y
#define DP_G	KC_U
#define DP_C	KC_I
#define DP_R	KC_O
#define DP_L	KC_P
#define DP_SLSH	KC_LBRC
#define DP_AT	KC_RBRC
#define DP_BSLS	KC_BSLS

#define DP_A	KC_A
#define DP_O	KC_S
#define DP_E	KC_D
#define DP_U	KC_F
#define DP_I	KC_G
#define DP_D	KC_H
#define DP_H	KC_J
#define DP_T	KC_K
#define DP_N	KC_L
#define DP_S	KC_SCLN
#define DP_MINS	KC_QUOT

#define DP_QUOT	KC_Z
#define DP_Q	KC_X
#define DP_J	KC_C
#define DP_K	KC_V
#define DP_X	KC_B
#define DP_B	KC_N
#define DP_M	KC_M
#define DP_W	KC_COMM
#define DP_V	KC_DOT
#define DP_Z	KC_SLSH

// Shifted characters
#define DP_TILD	LSFT(DP_DLR)
#define DP_PERC	LSFT(DP_AMPR)
#define DP_7	LSFT(DP_LBRC)
#define DP_5	LSFT(DP_LCBR)
#define DP_3	LSFT(DP_RCBR)
#define DP_1	LSFT(DP_LPRN)
#define DP_9	LSFT(DP_EQL)
#define DP_0	LSFT(DP_ASTR)
#define DP_2	LSFT(DP_RPRN)
#define DP_4	LSFT(DP_PLUS)
#define DP_6	LSFT(DP_RBRC)
#define DP_8	LSFT(DP_EXLM)
#define DP_GRV	LSFT(DP_HASH)

#define DP_COLN	LSFT(DP_SCLN)
#define DP_LABK	LSFT(DP_COMM)
#define DP_RABK	LSFT(DP_DOT)
#define DP_QUES	LSFT(DP_SLSH)
#define DP_CIRC	LSFT(DP_AT)
#define DP_PIPE	LSFT(DP_BSLS)
#define DP_UNDS	LSFT(DP_MINS)
#define DP_DQUO	LSFT(DP_QUOT)
=======
// clang-format off

/*
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
 * │ $ │ & │ [ │ { │ } │ ( │ = │ * │ ) │ + │ ] │ ! │ # │       │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
 * │     │ ; │ , │ . │ P │ Y │ F │ G │ C │ R │ L │ / │ @ │  \  │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
 * │      │ A │ O │ E │ U │ I │ D │ H │ T │ N │ S │ - │        │
 * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤
 * │        │ ' │ Q │ J │ K │ X │ B │ M │ W │ V │ Z │          │
 * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
 * │    │    │    │                        │    │    │    │    │
 * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
 */
// Row 1
#define DP_DLR  KC_GRV  // $
#define DP_AMPR KC_1    // &
#define DP_LBRC KC_2    // [
#define DP_LCBR KC_3    // {
#define DP_RCBR KC_4    // }
#define DP_LPRN KC_5    // (
#define DP_EQL  KC_6    // =
#define DP_ASTR KC_7    // *
#define DP_RPRN KC_8    // )
#define DP_PLUS KC_9    // +
#define DP_RBRC KC_0    // ]
#define DP_EXLM KC_MINS // !
#define DP_HASH KC_EQL  // #
// Row 2
#define DP_SCLN KC_Q    // ;
#define DP_COMM KC_W    // ,
#define DP_DOT  KC_E    // .
#define DP_P    KC_R    // P
#define DP_Y    KC_T    // Y
#define DP_F    KC_Y    // F
#define DP_G    KC_U    // G
#define DP_C    KC_I    // C
#define DP_R    KC_O    // R
#define DP_L    KC_P    // L
#define DP_SLSH KC_LBRC // /
#define DP_AT   KC_RBRC // @
#define DP_BSLS KC_BSLS // (backslash)
// Row 3
#define DP_A    KC_A    // A
#define DP_O    KC_S    // O
#define DP_E    KC_D    // E
#define DP_U    KC_F    // U
#define DP_I    KC_G    // I
#define DP_D    KC_H    // D
#define DP_H    KC_J    // H
#define DP_T    KC_K    // T
#define DP_N    KC_L    // N
#define DP_S    KC_SCLN // S
#define DP_MINS KC_QUOT // -
// Row 4
#define DP_QUOT KC_Z    // '
#define DP_Q    KC_X    // Q
#define DP_J    KC_C    // J
#define DP_K    KC_V    // K
#define DP_X    KC_B    // X
#define DP_B    KC_N    // B
#define DP_M    KC_M    // M
#define DP_W    KC_COMM // W
#define DP_V    KC_DOT  // V
#define DP_Z    KC_SLSH // Z
>>>>>>> upstream/master

/* Shifted symbols
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
 * │ ~ │ % │ 7 │ 5 │ 3 │ 1 │ 9 │ 0 │ 2 │ 4 │ 6 │ 8 │ ` │       │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
 * │     │ : │ < │ > │   │   │   │   │   │   │   │ ? │ ^ │  |  │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
 * │      │   │   │   │   │   │   │   │   │   │   │ _ │        │
 * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤
 * │        │ " │   │   │   │   │   │   │   │   │   │          │
 * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
 * │    │    │    │                        │    │    │    │    │
 * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
 */
// Row 1
#define DP_TILD S(DP_DLR)  // ~
#define DP_PERC S(DP_AMPR) // %
#define DP_7    S(DP_LBRC) // 7
#define DP_5    S(DP_LCBR) // 5
#define DP_3    S(DP_RCBR) // 3
#define DP_1    S(DP_LPRN) // 1
#define DP_9    S(DP_EQL)  // 9
#define DP_0    S(DP_ASTR) // 0
#define DP_2    S(DP_RPRN) // 2
#define DP_4    S(DP_PLUS) // 4
#define DP_6    S(DP_RBRC) // 6
#define DP_8    S(DP_EXLM) // 8
#define DP_GRV  S(DP_HASH) // `
// Row 2
#define DP_COLN S(DP_SCLN) // :
#define DP_LABK S(DP_COMM) // <
#define DP_RABK S(DP_DOT)  // >
#define DP_QUES S(DP_SLSH) // ?
#define DP_CIRC S(DP_AT)   // ^
#define DP_PIPE S(DP_BSLS) // |
// Row 3
#define DP_UNDS S(DP_MINS) // _
// Row 4
#define DP_DQUO S(DP_QUOT) // "
