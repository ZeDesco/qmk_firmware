/* Copyright 2017 Potiguar Faga
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

#include "keymap_common.h"

// clang-format off

<<<<<<< HEAD
#define BR_CCDL KC_SCLN      //  Ç   same scancode as ;: on US layout
#define BR_SCLN KC_SLSH      //  ;:  same scancode as /? on US layout
#define BR_QUOT KC_GRV       //  '"  same scancode as `~ on US layout
#define BR_TILD KC_QUOT      //  ~^  dead keys, same scancode as '" on US layout
#define BR_ACUT KC_LBRC      //  ´`  dead keys, same scancode as [{ on US layout
#define BR_LBRC KC_RBRC      //  [{  same scancode as ]} on US layout
#define BR_RBRC KC_BSLS      //  ]}  same scancode as \| on US layout
#define BR_BSLS KC_NUBS      //  \|  uses the non-US hash scancode (#~, sometimes §±)
#define BR_SLSH KC_INT1      //  /?  uses the INTL1 scancode

#define BR_COLN LSFT(BR_SCLN)   // shifted :
#define BR_DQT  LSFT(BR_QUOT)   // shifted "
#define BR_CIRC LSFT(BR_TILD)   // shifted ^ (dead key)
#define BR_GRAV LSFT(BR_ACUT)   // shifted ` (dead key)
#define BR_LCBR LSFT(BR_LBRC)   // shifted {
#define BR_RCBR LSFT(BR_RBRC)   // shifted }
#define BR_PIPE LSFT(BR_BSLS)   // shifted |
#define BR_QUES LSFT(BR_SLSH)   // shifted ?
#define BR_TRMA LSFT(KC_6)      // shifted ¨ (dead key - trema accent)

// On the ABNT2 the keypad comma and the keypad dot scancodes are switched
// (presumably because in Brazil comma is used as the decimal separator)
#define BR_KPDT KC_KP_COMMA  //  keypad .
#define BR_KPCM KC_KP_DOT    //  keypad ,

#define BR_1UP    LALT(KC_1)      // 1 superscript                    ¹   alt+1
#define BR_2UP    LALT(KC_2)      // 2 superscript                    ²   alt+2
#define BR_3UP    LALT(KC_3)      // 3 superscript                    ³   alt+3
#define BR_PND    LALT(KC_4)      // Pound sign                       £   alt+4
#define BR_CENT   LALT(KC_5)      // Cent sign                        ¢   alt+5
#define BR_NOT    LALT(KC_6)      // Not sign                         ¬   alt+6
#define BR_SECT   LALT(KC_EQL)    // Section sign                     §   alt+=
#define BR_FORD   LALT(BR_LBRC)   // Feminine Ordinal Sign            ª   alt+[
#define BR_MORD   LALT(BR_RBRC)   // Masculine Ordinal Sign           º   alt+]
#define BR_DGRE   LALT(BR_SLSH)   // Degree sign                      °   alt+/

#define BR_EURO   LALT(KC_E)      // Euro sign                        €   alt+e
#define BR_NDTD   LALT(BR_TILD)   // Non-dead key tilde               ~   alt+~
#define BR_NDAC   LALT(BR_ACUT)   // Non-dead key acute accent        ´   alt+´
#define BR_NDGV   LALT(BR_QUOT)   // Non-dead key grave accent        `   alt+'
#define BR_NDCR   LALT(BR_CIRC)   // Non-dead key circumflex accent   ^   alt+^ (alt+shift+~)
#define BR_NDTR   LALT(BR_TRMA)   // Non-dead key trema accent        ¨   alt+¨ (alt+shift+6)

// For 101-key keyboard layouts, the ABNT2 layout allows
// the slash and question mark to be typed using alt+q and alt+w.
// The shortcuts are provided here for completeness' sake,
// but it's recommended to use BR_SLSH and BR_QUES instead
#define BR_ASLS   LALT(KC_Q)
#define BR_AQST   LALT(KC_W)
=======
/*
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
 * │ ' │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │       │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
 * │     │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ ´ │ [ │     │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    │
 * │      │ A │ S │ D │ F │ G │ H │ J │ K │ L │ Ç │ ~ │ ] │    │
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┤
 * │    │ \ │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ ; │ / │      │
 * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬──┴─┬────┤
 * │    │    │    │                        │    │    │    │    │
 * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
 */
// Row 1
#define BR_QUOT KC_GRV  // '
#define BR_1    KC_1    // 1
#define BR_2    KC_2    // 2
#define BR_3    KC_3    // 3
#define BR_4    KC_4    // 4
#define BR_5    KC_5    // 5
#define BR_6    KC_6    // 6
#define BR_7    KC_7    // 7
#define BR_8    KC_8    // 8
#define BR_9    KC_9    // 9
#define BR_0    KC_0    // 0
#define BR_MINS KC_MINS // -
#define BR_EQL  KC_EQL  // =
// Row 2
#define BR_Q    KC_Q    // Q
#define BR_W    KC_W    // W
#define BR_E    KC_E    // E
#define BR_R    KC_R    // R
#define BR_T    KC_T    // T
#define BR_Y    KC_Y    // Y
#define BR_U    KC_U    // U
#define BR_I    KC_I    // I
#define BR_O    KC_O    // O
#define BR_P    KC_P    // P
#define BR_ACUT KC_LBRC // ´ (dead)
#define BR_LBRC KC_RBRC // [
// Row 3
#define BR_A    KC_A    // A
#define BR_S    KC_S    // S
#define BR_D    KC_D    // D
#define BR_F    KC_F    // F
#define BR_G    KC_G    // G
#define BR_H    KC_H    // H
#define BR_J    KC_J    // J
#define BR_K    KC_K    // K
#define BR_L    KC_L    // L
#define BR_CCED KC_SCLN // Ç
#define BR_TILD KC_QUOT // ~ (dead)
#define BR_RBRC KC_BSLS // ]
// Row 4
#define BR_BSLS KC_NUBS // (backslash)
#define BR_Z    KC_Z    // Z
#define BR_X    KC_X    // X
#define BR_C    KC_C    // C
#define BR_V    KC_V    // V
#define BR_B    KC_B    // B
#define BR_N    KC_N    // N
#define BR_M    KC_M    // M
#define BR_COMM KC_COMM // ,
#define BR_DOT  KC_DOT  // .
#define BR_SCLN KC_SLSH // ;
#define BR_SLSH KC_INT1 // /
// Numpad
#define BR_PDOT KC_PCMM    // .
#define BR_PCMM KC_PDOT    // ,

/* Shifted symbols
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
 * │ " │ ! │ @ │ # │ $ │ % │ ¨ │ & │ * │ ( │ ) │ _ │ + │       │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
 * │     │   │   │   │   │   │   │   │   │   │   │ ` │ { │     │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    │
 * │      │   │   │   │   │   │   │   │   │   │   │ ^ │ } │    │
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┤
 * │    │ | │   │   │   │   │   │   │   │ < │ > │ : │ ? │      │
 * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬──┴─┬────┤
 * │    │    │    │                        │    │    │    │    │
 * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
 */
// Row 1
#define BR_DQUO S(BR_QUOT) // "
#define BR_EXLM S(BR_1)    // !
#define BR_AT   S(BR_2)    // @
#define BR_HASH S(BR_3)    // #
#define BR_DLR  S(BR_4)    // $
#define BR_PERC S(BR_5)    // %
#define BR_DIAE S(BR_6)    // ¨ (dead)
#define BR_AMPR S(BR_7)    // &
#define BR_ASTR S(BR_8)    // *
#define BR_LPRN S(BR_9)    // (
#define BR_RPRN S(BR_0)    // )
#define BR_UNDS S(BR_MINS) // _
#define BR_PLUS S(BR_EQL)  // +
// Row 2
#define BR_GRV  S(BR_ACUT) // ` (dead)
#define BR_LCBR S(BR_LBRC) // {
// Row 3
#define BR_CIRC S(BR_TILD) // ^ (dead)
#define BR_RCBR S(BR_RBRC) // }
// Row 4
#define BR_PIPE S(BR_BSLS) // |
#define BR_LABK S(BR_COMM) // <
#define BR_RABK S(BR_DOT)  // >
#define BR_COLN S(BR_SCLN) // :
#define BR_QUES S(BR_SLSH) // ?

/* AltGr symbols
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
 * │   │ ¹ │ ² │ ³ │ £ │ ¢ │ ¬ │   │   │   │   │   │ § │       │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
 * │     │   │   │ ° │   │   │   │   │   │   │   │   │ ª │     │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    │
 * │      │   │   │   │   │   │   │   │   │   │   │   │ º │    │
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┤
 * │    │   │   │   │ ₢ │   │   │   │   │   │   │   │   │      │
 * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬──┴─┬────┤
 * │    │    │    │                        │    │    │    │    │
 * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
 */
// Row 1
#define BR_SUP1 ALGR(BR_1)    // ¹
#define BR_SUP2 ALGR(BR_2)    // ²
#define BR_SUP3 ALGR(BR_3)    // ³
#define BR_PND  ALGR(BR_4)    // £
#define BR_CENT ALGR(BR_5)    // ¢
#define BR_NOT  ALGR(BR_6)    // ¬
#define BR_SECT ALGR(BR_EQL)  // §
// Row 2
#define BR_DEG  ALGR(BR_E)    // °
#define BR_FORD ALGR(BR_LBRC) // ª
// Row 3
#define BR_MORD ALGR(BR_RBRC) // º
// Row 4
#define BR_CRUZ ALGR(BR_C)    // ₢

// DEPRECATED
#define BR_CCDL BR_CCED
#define BR_DQT  BR_DQUO
#define BR_TRMA BR_DIAE
#define BR_GRAV BR_GRV
#define BR_KPDT BR_PDOT
#define BR_KPCM BR_PCMM
#define BR_1UP  BR_SUP1
#define BR_2UP  BR_SUP2
#define BR_3UP  BR_SUP3
#define BR_ASLS BR_SLSH
#define BR_AQST BR_QUES
>>>>>>> upstream/master

// Not present on Windows 10?
#define BR_NDTD ALGR(BR_TILD)   // ~
#define BR_NDAC ALGR(BR_ACUT)   // ´
#define BR_NDGV ALGR(BR_QUOT)   // `
#define BR_NDCR ALGR(BR_CIRC)   // ^
#define BR_NDTR ALGR(BR_DIAE)   // ¨
