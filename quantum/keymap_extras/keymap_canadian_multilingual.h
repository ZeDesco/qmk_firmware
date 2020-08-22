/* Copyright 2020
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

<<<<<<< HEAD
#include "keymap.h"

#ifndef GR2A
#define GR2A(kc)    RCTL(kc)
#endif

// Normal characters
// First row
#define CSA_SLASH   KC_GRV      // /
#define CSA_SLSH    CSA_SLASH

// Second row
#define CSA_DEAD_CIRCUMFLEX     KC_LBRACKET         // dead ^
#define CSA_DCRC                CSA_DEAD_CIRCUMFLEX
#define CSA_C_CEDILLA           KC_RBRACKET         // Ç
#define CSA_CCED                CSA_C_CEDILLA

// Third row
#define CSA_E_GRAVE     KC_QUOT     // è
#define CSA_EGRV        CSA_E_GRAVE
#define CSA_A_GRAVE     KC_BSLASH   // à
#define CSA_AGRV        CSA_A_GRAVE

// Fourth row
#define CSA_U_GRAVE     KC_NONUS_BSLASH     // ù
#define CSA_UGRV        CSA_U_GRAVE
#define CSA_E_ACUTE     KC_SLSH             // é
#define CSA_ECUT        CSA_E_ACUTE

// Shifted characters
// First row
#define CSA_BACKSLASH   LSFT(CSA_SLASH) /* \ */
#define CSA_BSLS        CSA_BACKSLASH
#define CSA_QUESTION    LSFT(KC_6)      // ?
#define CSA_QEST        CSA_QUESTION

// Second row
#define CSA_DEAD_TREMA  LSFT(CSA_DEAD_CIRCUMFLEX)    // dead trema/umlaut/diaresis for ä ë ï ö ü
#define CSA_DTRM        CSA_DEAD_TREMA

// Third row
// all same as US-QWERTY, or capitalised character of the non-shifted key

// Fourth row
#define CSA_APOSTROPHE      LSFT(KC_COMMA)  // '
#define CSA_APOS            CSA_APOSTROPHE
#define CSA_DOUBLE_QUOTE    LSFT(KC_DOT)    // "
#define CSA_DQOT            CSA_DOUBLE_QUOTE

// Alt Gr-ed characters
// First row
#define CSA_PIPE                ALGR(CSA_SLASH)         // |
#define CSA_CURRENCY            ALGR(KC_4)              // ¤
#define CSA_CURR                CSA_CURRENCY
#define CSA_LEFT_CURLY_BRACE    ALGR(KC_7)              // {
#define CSA_LCBR                CSA_LEFT_CURLY_BRACE
#define CSA_RIGHT_CURLY_BRACE   ALGR(KC_8)              // }
#define CSA_RCBR                CSA_RIGHT_CURLY_BRACE
#define CSA_LBRACKET            ALGR(KC_9)              // [
#define CSA_LBRC                CSA_LBRACKET
#define CSA_RBRACKET            ALGR(KC_0)              // ]
#define CSA_RBRC                CSA_RBRACKET
#define CSA_NEGATION            ALGR(KC_EQUAL)          // ¬
#define CSA_NEGT                CSA_NEGATION

// Second row
// euro symbol not available on Linux? (X.org)
#define CSA_EURO        ALGR(KC_E)                  // €
#define CSA_DEAD_GRAVE  ALGR(CSA_DEAD_CIRCUMFLEX)
#define CSA_DGRV        CSA_DEAD_GRAVE              // dead `
#define CSA_DEAD_TILDE  ALGR(CSA_C_CEDILLA)         // ~
#define CSA_DTLD        CSA_DEAD_TILDE

// Third row
#define CSA_DEGREE  ALGR(KC_SCOLON)     // °
#define CSA_DEGR    CSA_DEGREE

// Fourth row
#define CSA_LEFT_GUILLEMET      ALGR(KC_Z)          // «
#define CSA_LGIL                CSA_LEFT_GUILLEMET
#define CSA_RIGHT_GUILLEMET     ALGR(KC_X)          // »
#define CSA_RGIL                CSA_RIGHT_GUILLEMET
#define CSA_LESS                ALGR(KC_COMMA)      // <
#define CSA_GREATER             ALGR(KC_DOT)        // >
#define CSA_GRTR                CSA_GREATER

// Space bar
#define CSA_NON_BREAKING_SPACE  ALGR(KC_SPACE)
#define CSA_NBSP                CSA_NON_BREAKING_SPACE

// GR2A-ed characters
// First row
#define CSA_SUPERSCRIPT_ONE     GR2A(KC_1)  // ¹
#define CSA_SUP1                CSA_SUPERSCRIPT_ONE
#define CSA_SUPERSCRIPT_TWO     GR2A(KC_2)  // ²
#define CSA_SUP2                CSA_SUPERSCRIPT_TWO
#define CSA_SUPERSCRIPT_THREE   GR2A(KC_3)  // ³
#define CSA_SUP3                CSA_SUPERSCRIPT_THREE
#define CSA_ONE_QUARTER         GR2A(KC_4)  // ¼
#define CSA_1QRT                CSA_ONE_QUARTER
#define CSA_ONE_HALF            GR2A(KC_5)  // ½
#define CSA_1HLF                CSA_ONE_HALF
#define CSA_THREE_QUARTERS      GR2A(KC_6)  // ¾
#define CSA_3QRT                CSA_THREE_QUARTERS
// nothing on 7-0 and -
#define CSA_DEAD_CEDILLA        GR2A(KC_EQUAL)  // dead ¸
#define CSA_DCED                CSA_DEAD_CEDILLA

// Second row
#define CSA_OMEGA           GR2A(KC_Q)  // ω
#define CSA_OMEG            CSA_OMEGA
#define CSA_L_STROKE        GR2A(KC_W)  // ł
#define CSA_LSTK            CSA_L_STROKE
#define CSA_OE_LIGATURE     GR2A(KC_E)  // œ
#define CSA_OE              CSA_OE_LIGATURE
#define CSA_PARAGRAPH       GR2A(KC_R)  // ¶
#define CSA_PARG            CSA_PARAGRAPH
#define CSA_T_STROKE        GR2A(KC_T)  // ŧ
#define CSA_LEFT_ARROW      GR2A(KC_Y)  // ←
#define CSA_LARW            CSA_LEFT_ARROW
#define CSA_DOWN_ARROW      GR2A(KC_U)  // ↓
#define CSA_DARW            CSA_DOWN_ARROW
#define CSA_RIGHT_ARROW     GR2A(KC_I)  // →
#define CSA_RARW            CSA_RIGHT_ARROW
#define CSA_O_STROKE        GR2A(KC_O)  // ø
#define CSA_OSTK            CSA_O_STROKE
#define CSA_THORN           GR2A(KC_P)  // þ
#define CSA_THRN            CSA_THORN
// nothing on ^
#define CSA_TILDE           GR2A(CSA_C_CEDILLA)  // dead ~
#define CSA_TILD            CSA_TILDE

// Third row
#define CSA_AE_LIGATURE     GR2A(KC_A)      // æ
#define CSA_AE              CSA_AE_LIGATURE
#define CSA_SHARP_S         GR2A(KC_S)      // ß
#define CSA_SRPS            CSA_SHARP_S
#define CSA_ETH             GR2A(KC_D)      // ð
// nothing on F
#define CSA_ENG             GR2A(KC_G)      // ŋ
#define CSA_H_SRTOKE        GR2A(KC_H)      // ħ
#define CSA_HSTK            CSA_H_SRTOKE
#define CSA_IJ_LIGATURE     GR2A(KC_J)      // ĳ
#define CSA_IJ              CSA_IJ_LIGATURE
#define CSA_KRA             GR2A(KC_K)      // ĸ
#define CSA_L_FLOWN_DOT     GR2A(KC_L)      // ŀ
#define CSA_LFLD            CSA_L_FLOWN_DOT
#define CSA_DEAD_ACUTE      GR2A(KC_SCLN)   // dead acute accent
#define CSA_DACT            CSA_DEAD_ACUTE
// nothing on È & À

// Fourth row
#define CSA_CENT                GR2A(KC_C)  // ¢
#define CSA_LEFT_DOUBLE_QUOTE   GR2A(KC_V)  // “
#define CSA_LDQT                CSA_LEFT_DOUBLE_QUOTE
#define CSA_RIGHT_DOUBLE_QUOTE  GR2A(KC_B)  // ”
#define CSA_RDQT                CSA_RIGHT_DOUBLE_QUOTE
#define CSA_N_APOSTROPHE        GR2A(KC_N)  // ŉ (deprecated unicode codepoint)
#define CSA_NAPO                CSA_N_APOSTROPHE
#define CSA_MU                  GR2A(KC_M)  // μ
#define CSA_HORIZONTAL_BAR      GR2A(KC_COMMA)  // ―
#define CSA_HZBR                CSA_HORIZONTAL_BAR
#define CSA_DEAD_DOT_ABOVE      GR2A(KC_DOT)    // dead ˙
#define CSA_DDTA                CSA_DEAD_DOT_ABOVE

// GR2A-shifted characters (different from capitalised GR2A-ed characters)
// First row
#define CSA_SOFT_HYPHEN         GR2A(LSFT(CSA_SLASH))   // soft-hyphen, appears as a hyphen in wrapped word
#define CSA_SHYP                CSA_SOFT_HYPHEN
#define CSA_INVERTED_EXCLAIM    GR2A(KC_EXCLAIM)    // ¡
#define CSA_IXLM                CSA_INVERTED_EXCLAIM
// nothing on 2
#define CSA_POUND               GR2A(LSFT(KC_3))    // £
#define CSA_GBP                 CSA_POUND_SIGN
// already on ALGR(KC_E)
#define CSA_EURO_BIS            GR2A(LSFT(KC_4))    // €
#define CSA_EURB                CSA_EURO_BIS
#define CSA_THREE_EIGHTHS       GR2A(LSFT(KC_5))    // ⅜
#define CSA_3ON8                CSA_THREE_EIGHTHS
#define CSA_FIVE_EIGHTHS        GR2A(LSFT(KC_6))    // ⅝
#define CSA_5ON8                CSA_FIVE_EIGHTHS
#define CSA_SEVEN_EIGHTHS       GR2A(LSFT(KC_7))    // ⅞
#define CSA_7ON8                CSA_SEVEN_EIGHTHS
#define CSA_TRADEMARK           GR2A(LSFT(KC_8))    // ™
#define CSA_TM                  CSA_TRADEMARK
#define CSA_PLUS_MINUS          GR2A(LSFT(KC_9))    // ±
#define CSA_PSMS                CSA_PLUS_MINUS
// nothing on 0
#define CSA_INVERTED_QUESTION   GR2A(LSFT(KC_MINUS))    // ¿
#define CSA_IQST                CSA_INVERTED_QUESTION
#define CSA_DEAD_OGONEK         GR2A(LSFT(KC_EQUAL))    // dead ˛
#define CSA_DOGO                CSA_DEAD_OGONEK

// Second row
#define CSA_REGISTERED_TRADEMARK    GR2A(LSFT(KC_R))        // ®
#define CSA_RTM                     CSA_REGISTERED_TRADEMARK
#define CSA_YEN                     GR2A(LSFT(KC_Y))        // ¥
#define CSA_YUAN                    CSA_YEN
#define CSA_UP_ARROW                LSFT(CSA_DOWN_ARROW)    // ↑
#define CSA_DOTLESS_I               GR2A(LSFT(KC_I))        // ı
#define CSA_DLSI                    CSA_DOTLESS_I
#define CSA_DEAD_RING               GR2A(LSFT(CSA_DCRC))    // dead °
#define CSA_DRNG                    CSA_DEAD_RING
#define CSA_DEAD_MACRON             GR2A(LSFT(CSA_C_CEDILLA))   // dead ¯
#define CSA_DMCR                    CSA_DEAD_MACRON

// Third row
#define CSA_SECTION                 GR2A(LSFT(KC_S))        // §
#define CSA_SECT                    CSA_SECTION
#define CSA_ORDINAL_INDICATOR_A     GR2A(LSFT(KC_F))        // ª
#define CSA_ORDA                    CSA_ORDINAL_INDICATOR_A
#define CSA_DEAD_DOUBLE_ACUTE       LSFT(CSA_DEAD_ACUTE)    // ˝
#define CSA_DDCT                    CSA_DEAD_DOUBLE_ACUTE
#define CSA_DEAD_CARON              GR2A(LSFT(CSA_E_GRAVE)) // dead ˇ
#define CSA_DCAR                    CSA_DEAD_CARON
#define CSA_DEAD_BREVE              GR2A(LSFT(CSA_A_GRAVE)) // dead ˘
#define CSA_DBRV                    CSA_DEAD_BREVE

// Fourth row
#define CSA_BROKEN_PIPE         GR2A(LSFT(CSA_U_GRAVE)) // ¦
#define CSA_BPIP                CSA_BROKEN_PIPE
#define CSA_COPYRIGHT           GR2A(LSFT(KC_C))        // ©
#define CSA_CPRT                CSA_COPYRIGHT
#define CSA_LEFT_QUOTE          GR2A(LSFT(KC_V))        // ‘
#define CSA_LQOT                CSA_LEFT_QUOTE
#define CSA_RIGHT_QUOTE         GR2A(LSFT(KC_B))        // ’
#define CSA_RQOT                CSA_RIGHT_QUOTE
#define CSA_EIGHTH_NOTE         GR2A(LSFT(KC_N))        // ♪
#define CSA_8NOT                CSA_EIGHTH_NOTE
#define CSA_ORDINAL_INDICATOR_O GR2A(LSFT(KC_M))        // º
#define CSA_ORDO                CSA_ORDINAL_INDICATOR_O
#define CSA_TIMES               GR2A(LSFT(KC_COMMA))    // ×
#define CSA_TIMS                CSA_TIMES
#define CSA_OBELUS              GR2A(LSFT(KC_DOT))      // ÷
#define CSA_OBEL                CSA_OBELUS
// more conventional name of the symbol
#define CSA_DIVISION_SIGN       CSA_OBELUS
#define CSA_DVSN                CSA_DIVISION_SIGN
// TODO GR2A(LSFT(CSA_E_ACUTE))
=======
#pragma once

#include "keymap.h"

// clang-format off

/*
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
 * │ / │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │       │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
 * │     │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ ^ │ Ç │     │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    │
 * │      │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ È │ À │    │
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┤
 * │    │ Ù │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ É │          │
 * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
 * │    │    │    │                        │    │    │    │    │
 * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
 */
// Row 1
#define CA_SLSH KC_GRV  // /
#define CA_1    KC_1    // 1
#define CA_2    KC_2    // 2
#define CA_3    KC_3    // 3
#define CA_4    KC_4    // 4
#define CA_5    KC_5    // 5
#define CA_6    KC_6    // 6
#define CA_7    KC_7    // 7
#define CA_8    KC_8    // 8
#define CA_9    KC_9    // 9
#define CA_0    KC_0    // 0
#define CA_MINS KC_MINS // -
#define CA_EQL  KC_EQL  // =
// Row 2
#define CA_Q    KC_Q    // Q
#define CA_W    KC_W    // W
#define CA_E    KC_E    // E
#define CA_R    KC_R    // R
#define CA_T    KC_T    // T
#define CA_Y    KC_Y    // Y
#define CA_U    KC_U    // U
#define CA_I    KC_I    // I
#define CA_O    KC_O    // O
#define CA_P    KC_P    // P
#define CA_CIRC KC_LBRC // ^ (dead)
#define CA_CCED KC_RBRC // Ç
// Row 3
#define CA_A    KC_A    // A
#define CA_S    KC_S    // S
#define CA_D    KC_D    // D
#define CA_F    KC_F    // F
#define CA_G    KC_G    // G
#define CA_H    KC_H    // H
#define CA_J    KC_J    // J
#define CA_K    KC_K    // K
#define CA_L    KC_L    // L
#define CA_SCLN KC_SCLN // ;
#define CA_EGRV KC_QUOT // É
#define CA_AGRV KC_NUHS // À
// Row 4
#define CA_UGRV KC_NUBS // Ù
#define CA_Z    KC_Z    // Z
#define CA_X    KC_X    // X
#define CA_C    KC_C    // C
#define CA_V    KC_V    // V
#define CA_B    KC_B    // B
#define CA_N    KC_N    // N
#define CA_M    KC_M    // M
#define CA_COMM KC_COMM // ,
#define CA_DOT  KC_DOT  // .
#define CA_EACU KC_SLSH // É

/* Shifted symbols
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
 * │ \ │ ! │ @ │ # │ $ │ % │ ? │ & │ * │ ( │ ) │ _ │ + │       │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
 * │     │   │   │   │   │   │   │   │   │   │   │ ¨ │   │     │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    │
 * │      │   │   │   │   │   │   │   │   │   │ : │   │   │    │
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┤
 * │    │   │   │   │   │   │   │   │   │ ' │ " │   │          │
 * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
 * │    │    │    │                        │    │    │    │    │
 * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
 */
// Row 1
#define CA_BSLS S(CA_SLSH) // (backslash)
#define CA_EXLM S(CA_1)    // !
#define CA_AT   S(CA_2)    // @
#define CA_HASH S(CA_3)    // #
#define CA_DLR  S(CA_4)    // $
#define CA_PERC S(CA_5)    // %
#define CA_QUES S(CA_6)    // ?
#define CA_AMPR S(CA_7)    // &
#define CA_ASTR S(CA_8)    // *
#define CA_LPRN S(CA_9)    // (
#define CA_RPRN S(CA_0)    // )
#define CA_UNDS S(CA_MINS) // _
#define CA_PLUS S(CA_EQL)  // +
// Row 2
#define CA_DIAE S(CA_CIRC) // ¨ (dead)
// Row 3
#define CA_COLN S(CA_SCLN) // :
// Row 4
#define CA_QUOT S(CA_COMM) // '
#define CA_DQUO S(CA_DOT)  // "

/* AltGr symbols
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
 * │ | │   │   │   │ ¤ │   │   │ { │ } │ [ │ ] │   │ ¬ │       │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
 * │     │   │   │ € │   │   │   │   │   │   │   │ ` │ ~ │     │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    │
 * │      │   │   │   │   │   │   │   │   │   │ ° │   │   │    │
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┤
 * │    │   │ « │ » │   │   │   │   │   │ < │ > │   │          │
 * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
 * │    │    │    │                        │    │    │    │    │
 * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
 */
// Row 1
#define CA_PIPE ALGR(CA_SLSH) // |
#define CA_CURR ALGR(CA_4)    // ¤
#define CA_LCBR ALGR(CA_7)    // {
#define CA_RCBR ALGR(CA_8)    // }
#define CA_LBRC ALGR(CA_9)    // [
#define CA_RBRC ALGR(CA_0)    // ]
#define CA_NOT  ALGR(CA_EQL)  // ¬
// Row 2
#define CA_EURO ALGR(CA_E)    // €
#define CA_GRV  ALGR(CA_CIRC) // ` (dead)
#define CA_DTIL ALGR(CA_CCED) // ~ (dead)
// Row 3
#define CA_DEG  ALGR(CA_SCLN) // °
// Row 4
#define CA_LDAQ ALGR(CA_X)    // «
#define CA_RDAQ ALGR(CA_C)    // »
#define CA_LABK ALGR(CA_DOT)  // <
#define CA_RABK ALGR(CA_COMM) // >

/* Right Ctrl symbols
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
 * │   │ ¹ │ ² │ ³ │ ¼ │ ½ │ ¾ │   │   │   │   │   │ ¸ │       │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
 * │     │ Ω │ Ł │ Œ │ ¶ │ Ŧ │ ← │ ↓ │ → │ Ø │ Þ │   │ ~ │     │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    │
 * │      │ Æ │ ß │ Ð │   │ Ŋ │ Ħ │ Ĳ │ ĸ │ Ŀ │ ´ │   │   │    │
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┤
 * │    │   │   │   │ ¢ │ “ │ ” │ ŉ │ μ │ ― │ ˙ │   │          │
 * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
 * │    │    │    │                        │    │    │    │    │
 * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
 */
// Row 1
#define CA_SUP1 RCTL(CA_1)    // ¹
#define CA_SUP2 RCTL(CA_2)    // ²
#define CA_SUP3 RCTL(CA_3)    // ³
#define CA_QRTR RCTL(CA_4)    // ¼
#define CA_HALF RCTL(CA_5)    // ½
#define CA_TQTR RCTL(CA_6)    // ¾
#define CA_CEDL RCTL(CA_EQL)  // ¸ (dead)
// Row 2
#define CA_OMEG RCTL(CA_Q)    // Ω
#define CA_LSTR RCTL(CA_W)    // Ł
#define CA_OE   RCTL(CA_E)    // Œ
#define CA_PARA RCTL(CA_R)    // ¶
#define CA_TSTR RCTL(CA_T)    // Ŧ
#define CA_LARR RCTL(CA_Y)    // ←
#define CA_DARR RCTL(CA_U)    // ↓
#define CA_RARR RCTL(CA_I)    // →
#define CA_OSTR RCTL(CA_O)    // Ø
#define CA_THRN RCTL(CA_P)    // Þ
#define CA_TILD RCTL(CA_CCED) // ~
// Row 3
#define CA_AE   RCTL(CA_A)    // Æ
#define CA_SS   RCTL(CA_S)    // ß
#define CA_ETH  RCTL(CA_D)    // Ð
#define CA_ENG  RCTL(CA_G)    // Ŋ
#define CA_HSTR RCTL(CA_H)    // Ħ
#define CA_IJ   RCTL(CA_J)    // Ĳ
#define CA_KRA  RCTL(CA_K)    // ĸ
#define CA_LMDT RCTL(CA_L)    // Ŀ
#define CA_ACUT RCTL(CA_SCLN) // ´ (dead)
// Row 4
#define CA_CENT RCTL(CA_C)    // ¢
#define CA_LDQU RCTL(CA_V)    // “
#define CA_RDQU RCTL(CA_B)    // ”
#define CA_APSN RCTL(CA_N)    // ŉ
#define CA_MICR RCTL(CA_M)    // μ
#define CA_HRZB RCTL(CA_COMM) // ―
#define CA_DOTA RCTL(CA_DOT)  // ˙ (dead)

/* Shift+Right Ctrl symbols
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
 * │ - │ ¡ │   │ £ │   │ ⅜ │ ⅝ │ ⅞ │ ™ │ ± │   │ ¿ │ ˛ │       │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
 * │     │   │   │   │ ® │   │ ¥ │ ↑ │ ı │   │   │ ° │ ¯ │     │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    │
 * │      │   │ § │   │ ª │   │   │   │   │   │ ˝ │ ˇ │ ˘ │    │
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┤
 * │    │ ¦ │   │   │ © │ ‘ │ ’ │ ♪ │ º │ × │ ÷ │   │          │
 * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
 * │    │    │    │                        │    │    │    │    │
 * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
 */
// Row 1
#define CA_SHYP RCTL(S(CA_SLSH)) // (soft hyphen)
#define CA_IEXL RCTL(S(CA_1))    // ¡
#define CA_PND  RCTL(S(CA_3))    // £
#define CA_TEIG RCTL(S(CA_5))    // ⅜
#define CA_FEIG RCTL(S(CA_6))    // ⅝
#define CA_SEIG RCTL(S(CA_7))    // ⅞
#define CA_TM   RCTL(S(CA_8))    // ™
#define CA_PLMN RCTL(S(CA_9))    // ±
#define CA_IQUE RCTL(S(CA_MINS)) // ¿
#define CA_OGON RCTL(S(CA_EQL))  // ˛ (dead)
// Row 2
#define CA_REGD RCTL(S(CA_R))    // ®
#define CA_YEN  RCTL(S(CA_Y))    // ¥
#define CA_UARR RCTL(S(CA_U))    // ↑
#define CA_DLSI RCTL(S(CA_I))    // ı
#define CA_RNGA RCTL(S(CA_CIRC)) // ° (dead)
#define CA_MACR RCTL(S(CA_CCED)) // ¯ (dead)
// Row 3
#define CA_SECT RCTL(S(CA_S))    // §
#define CA_FORD RCTL(S(CA_F))    // ª
#define CA_DACU RCTL(S(CA_SCLN)) // ˝ (dead)
#define CA_CARN RCTL(S(CA_EGRV)) // ˇ (dead)
#define CA_BREV RCTL(S(CA_AGRV)) // ˘ (dead)
// Row 4
#define CA_BRKP RCTL(S(CA_UGRV)) // ¦
#define CA_COPY RCTL(S(CA_C))    // ©
#define CA_LSQU RCTL(S(CA_V))    // ‘
#define CA_RSQU RCTL(S(CA_B))    // ’
#define CA_ENOT RCTL(S(CA_N))    // ♪
#define CA_MORD RCTL(S(CA_M))    // º
#define CA_MUL  RCTL(S(CA_COMM)) // ×
#define CA_DIV  RCTL(S(CA_DOT))  // ÷
>>>>>>> upstream/master

// DEPRECATED
#define GR2A(kc) RCTL(kc)
#define CSA_SLASH CA_SLSH
#define CSA_SLSH CA_SLSH
#define CSA_DEAD_CIRCUMFLEX CA_CIRC
#define CSA_DCRC CA_CIRC
#define CSA_C_CEDILLA CA_CCED
#define CSA_CCED CA_CCED
#define CSA_E_GRAVE CA_EGRV
#define CSA_EGRV CA_EGRV
#define CSA_A_GRAVE CA_AGRV
#define CSA_AGRV CA_AGRV
#define CSA_U_GRAVE CA_UGRV
#define CSA_UGRV CA_UGRV
#define CSA_E_ACUTE CA_EACU
#define CSA_ECUT CA_EACU
#define CSA_BACKSLASH CA_BSLS
#define CSA_BSLS CA_BSLS
#define CSA_QUESTION CA_QUES
#define CSA_QEST CA_QUES
#define CSA_DEAD_TREMA CA_DIAE
#define CSA_DTRM CA_DIAE
#define CSA_APOSTROPHE CA_QUOT
#define CSA_APOS CA_QUOT
#define CSA_DOUBLE_QUOTE CA_DQUO
#define CSA_DQOT CA_DQUO
#define CSA_PIPE CA_PIPE
#define CSA_CURRENCY CA_CURR
#define CSA_CURR CA_CURR
#define CSA_LEFT_CURLY_BRACE CA_LCBR
#define CSA_LCBR CA_LCBR
#define CSA_RIGHT_CURLY_BRACE CA_RCBR
#define CSA_RCBR CA_RCBR
#define CSA_LBRACKET CA_LBRC
#define CSA_LBRC CA_LBRC
#define CSA_RBRACKET CA_RBRC
#define CSA_RBRC CA_RBRC
#define CSA_NEGATION CA_NOT
#define CSA_NEGT CA_NOT
#define CSA_EURO CA_EURO
#define CSA_DEAD_GRAVE CA_GRV
#define CSA_DGRV CA_GRV
#define CSA_DEAD_TILDE CA_DTIL
#define CSA_DTLD CA_DTIL
#define CSA_DEGREE CA_DEG
#define CSA_DEGR CA_DEG
#define CSA_LEFT_GUILLEMET CA_LDAQ
#define CSA_LGIL CA_LDAQ
#define CSA_RIGHT_GUILLEMET CA_RDAQ
#define CSA_RGIL CA_RDAQ
#define CSA_LESS CA_LABK
#define CSA_GREATER CA_RABK
#define CSA_GRTR CA_RABK
#define CSA_NON_BREAKING_SPACE ALGR(KC_SPC)
#define CSA_NBSP ALGR(KC_SPC)
#define CSA_SUPERSCRIPT_ONE CA_SUP1
#define CSA_SUP1 CA_SUP1
#define CSA_SUPERSCRIPT_TWO CA_SUP2
#define CSA_SUP2 CA_SUP2
#define CSA_SUPERSCRIPT_THREE CA_SUP3
#define CSA_SUP3 CA_SUP3
#define CSA_ONE_QUARTER CA_QRTR
#define CSA_1QRT CA_QRTR
#define CSA_ONE_HALF CA_HALF
#define CSA_1HLF CA_HALF
#define CSA_THREE_QUARTERS CA_TQTR
#define CSA_3QRT CA_TQTR
#define CSA_DEAD_CEDILLA CA_CEDL
#define CSA_DCED CA_CEDL
#define CSA_OMEGA CA_OMEG
#define CSA_OMEG CA_OMEG
#define CSA_L_STROKE CA_LSTR
#define CSA_LSTK CA_LSTR
#define CSA_OE_LIGATURE CA_OE
#define CSA_OE CA_OE
#define CSA_PARAGRAPH CA_PARA
#define CSA_PARG CA_PARA
#define CSA_T_STROKE CA_TSTR
#define CSA_LEFT_ARROW CA_LARR
#define CSA_LARW CA_LARR
#define CSA_DOWN_ARROW CA_DARR
#define CSA_DARW CA_DARR
#define CSA_RIGHT_ARROW CA_RARR
#define CSA_RARW CA_RARR
#define CSA_O_STROKE CA_OSTR
#define CSA_OSTK CA_OSTR
#define CSA_THORN CA_THRN
#define CSA_THRN CA_THRN
#define CSA_TILDE CA_TILD
#define CSA_TILD CA_TILD
#define CSA_AE_LIGATURE CA_AE
#define CSA_AE CA_AE
#define CSA_SHARP_S CA_SS
#define CSA_SRPS CA_SS
#define CSA_ETH CA_ETH
#define CSA_ENG CA_ENG
#define CSA_H_SRTOKE CA_HSTR
#define CSA_HSTK CA_HSTR
#define CSA_IJ_LIGATURE CA_IJ
#define CSA_IJ CA_IJ
#define CSA_KRA CA_KRA
#define CSA_L_FLOWN_DOT CA_LMDT
#define CSA_LFLD CA_LMDT
#define CSA_DEAD_ACUTE CA_ACUT
#define CSA_DACT CA_ACUT
#define CSA_CENT CA_CENT
#define CSA_LEFT_DOUBLE_QUOTE CA_LDQU
#define CSA_LDQT CA_LDQU
#define CSA_RIGHT_DOUBLE_QUOTE CA_RDQU
#define CSA_RDQT CA_RDQU
#define CSA_N_APOSTROPHE CA_APSN
#define CSA_NAPO CA_APSN
#define CSA_MU CA_MICR
#define CSA_HORIZONTAL_BAR CA_HRZB
#define CSA_HZBR CA_HRZB
#define CSA_DEAD_DOT_ABOVE CA_DOTA
#define CSA_DDTA CA_DOTA
#define CSA_SOFT_HYPHEN CA_SHYP
#define CSA_SHYP CA_SHYP
#define CSA_INVERTED_EXCLAIM CA_IEXL
#define CSA_IXLM CA_IEXL
#define CSA_POUND CA_PND
#define CSA_GBP CA_PND
#define CSA_EURO_BIS CA_EURO
#define CSA_EURB CA_EURO
#define CSA_THREE_EIGHTHS CA_TEIG
#define CSA_3ON8 CA_TEIG
#define CSA_FIVE_EIGHTHS CA_FEIG
#define CSA_5ON8 CA_FEIG
#define CSA_SEVEN_EIGHTHS CA_SEIG
#define CSA_7ON8 CA_SEIG
#define CSA_TRADEMARK CA_TM
#define CSA_TM CA_TM
#define CSA_PLUS_MINUS CA_PLMN
#define CSA_PSMS CA_PLMN
#define CSA_INVERTED_QUESTION CA_IQUE
#define CSA_IQST CA_IQUE
#define CSA_DEAD_OGONEK CA_OGON
#define CSA_DOGO CA_OGON
#define CSA_REGISTERED_TRADEMARK CA_REGD
#define CSA_RTM CA_REGD
#define CSA_YEN CA_YEN
#define CSA_YUAN CA_YEN
#define CSA_UP_ARROW CA_UARR
#define CSA_DOTLESS_I CA_DLSI
#define CSA_DLSI CA_DLSI
#define CSA_DEAD_RING CA_RNGA
#define CSA_DRNG CA_RNGA
#define CSA_DEAD_MACRON CA_MACR
#define CSA_DMCR CA_MACR
#define CSA_SECTION CA_SECT
#define CSA_SECT CA_SECT
#define CSA_ORDINAL_INDICATOR_A CA_FORD
#define CSA_ORDA CA_FORD
#define CSA_DEAD_DOUBLE_ACUTE CA_DACU
#define CSA_DDCT CA_DACU
#define CSA_DEAD_CARON CA_CARN
#define CSA_DCAR CA_CARN
#define CSA_DEAD_BREVE CA_BREV
#define CSA_DBRV CA_BREV
#define CSA_BROKEN_PIPE CA_BRKP
#define CSA_BPIP CA_BRKP
#define CSA_COPYRIGHT CA_COPY
#define CSA_CPRT CA_COPY
#define CSA_LEFT_QUOTE CA_LSQU
#define CSA_LQOT CA_LSQU
#define CSA_RIGHT_QUOTE CA_RSQU
#define CSA_RQOT CA_RSQU
#define CSA_EIGHTH_NOTE CA_ENOT
#define CSA_8NOT CA_ENOT
#define CSA_ORDINAL_INDICATOR_O CA_MORD
#define CSA_ORDO CA_MORD
#define CSA_TIMES CA_MUL
#define CSA_TIMS CA_MUL
#define CSA_OBELUS CA_DIV
#define CSA_OBEL CA_DIV
#define CSA_DIVISION_SIGN CA_DIV
#define CSA_DVSN CA_DIV
