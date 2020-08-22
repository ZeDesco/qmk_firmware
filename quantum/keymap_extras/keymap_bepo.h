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

// Normal characters
// First row (on usual keyboards)
#define BP_DOLLAR           KC_GRAVE            // $
#define BP_DLR              BP_DOLLAR
#define BP_DOUBLE_QUOTE     KC_1                // "
#define BP_DQOT             BP_DOUBLE_QUOTE
#define BP_LEFT_GUILLEMET   KC_2                // «
#define BP_LGIL             BP_LEFT_GUILLEMET
#define BP_RIGHT_GUILLEMET  KC_3                // »
#define BP_RGIL             BP_RIGHT_GUILLEMET
#define BP_LEFT_PAREN       KC_4                // (
#define BP_LPRN             BP_LEFT_PAREN
#define BP_RIGHT_PAREN      KC_5                // )
#define BP_RPRN             BP_RIGHT_PAREN
#define BP_AT               KC_6                // @
#define BP_PLUS             KC_7                // +
#define BP_MINUS            KC_8                // -
#define BP_MINS             BP_MINUS
#define BP_SLASH            KC_9                // /
#define BP_SLSH             BP_SLASH
#define BP_ASTERISK         KC_0                // *
#define BP_ASTR             BP_ASTERISK
#define BP_EQUAL            KC_MINUS            // =
#define BP_EQL              BP_EQUAL
#define BP_PERCENT          KC_EQUAL            // %
#define BP_PERC             BP_PERCENT

// Second row
#define BP_B                KC_Q
#define BP_E_ACUTE          KC_W        // é
#define BP_ECUT             BP_E_ACUTE
#define BP_P                KC_E
#define BP_O                KC_R
#define BP_E_GRAVE          KC_T        // è
#define BP_EGRV             BP_E_GRAVE
#define BP_DEAD_CIRCUMFLEX  KC_Y        // dead ^
#define BP_DCRC             BP_DEAD_CIRCUMFLEX
#define BP_V                KC_U
#define BP_D                KC_I
#define BP_L                KC_O
#define BP_J                KC_P
#define BP_Z                KC_LBRACKET
#define BP_W                KC_RBRACKET

// Third row
#define BP_A            KC_A
#define BP_U            KC_S
#define BP_I            KC_D
#define BP_E            KC_F
#define BP_COMMA        KC_G        // ,
#define BP_COMM         BP_COMMA
#define BP_C            KC_H
#define BP_T            KC_J
#define BP_S            KC_K
#define BP_R            KC_L
#define BP_N            KC_SCOLON
#define BP_M            KC_QUOTE
#define BP_C_CEDILLA    KC_BSLASH   // ç
#define BP_CCED         BP_C_CEDILLA

// Fourth row
#define BP_E_CIRCUMFLEX     KC_NONUS_BSLASH // ê
#define BP_ECRC             BP_E_CIRCUMFLEX
#define BP_A_GRAVE          KC_Z            // à
#define BP_AGRV             BP_A_GRAVE
#define BP_Y                KC_X
#define BP_X                KC_C
#define BP_DOT              KC_V            // .
#define BP_K                KC_B
#define BP_APOSTROPHE       KC_N
#define BP_APOS             BP_APOSTROPHE   // '
#define BP_Q                KC_M
#define BP_G                KC_COMMA
#define BP_H                KC_DOT
#define BP_F                KC_SLASH

// Shifted characters
// First row
#define BP_HASH     LSFT(BP_DOLLAR)     // #
#define BP_1        LSFT(KC_1)
#define BP_2        LSFT(KC_2)
#define BP_3        LSFT(KC_3)
#define BP_4        LSFT(KC_4)
#define BP_5        LSFT(KC_5)
#define BP_6        LSFT(KC_6)
#define BP_7        LSFT(KC_7)
#define BP_8        LSFT(KC_8)
#define BP_9        LSFT(KC_9)
#define BP_0        LSFT(KC_0)
#define BP_DEGREE   LSFT(BP_EQUAL)      // °
#define BP_DEGR     BP_DEGREE
#define BP_GRAVE    LSFT(BP_PERCENT)    // `
#define BP_GRV      BP_GRAVE

// Second row
#define BP_EXCLAIM  LSFT(BP_DEAD_CIRCUMFLEX)    // !
#define BP_EXLM     BP_EXCLAIM

// Third row
#define BP_SCOLON   LSFT(BP_COMMA)  // ;
#define BP_SCLN     BP_SCOLON

// Fourth row
#define BP_COLON    LSFT(BP_DOT)    // :
#define BP_COLN     BP_COLON
#define BP_QUESTION LSFT(BP_APOS)  // ?
#define BP_QEST     BP_QUESTION

// Space bar
#define BP_NON_BREAKING_SPACE   LSFT(KC_SPACE)
#define BP_NBSP                 BP_NON_BREAKING_SPACE

// AltGr-ed characters
// First row
#define BP_EN_DASH          ALGR(BP_DOLLAR)     // –
#define BP_NDSH             BP_EN_DASH
#define BP_EM_DASH          ALGR(KC_1)          // —
#define BP_MDSH             BP_EM_DASH
#define BP_LESS             ALGR(KC_2)          // <
#define BP_GREATER          ALGR(KC_3)          // >
#define BP_GRTR             BP_GREATER
#define BP_LBRACKET         ALGR(KC_4)          // [
#define BP_LBRC             BP_LBRACKET
#define BP_RBRACKET         ALGR(KC_5)          // ]
#define BP_RBRC             BP_RBRACKET
#define BP_CIRCUMFLEX       ALGR(KC_6)          // ^
#define BP_CIRC             BP_CIRCUMFLEX
#define BP_PLUS_MINUS       ALGR(KC_7)          // ±
#define BP_PSMS             BP_PLUS_MINUS
#define BP_MATH_MINUS       ALGR(KC_8)          // −
#define BP_MMNS             BP_MATH_MINUS
#define BP_OBELUS           ALGR(KC_9)          // ÷
#define BP_OBEL             BP_OBELUS
// more conventional name of the symbol
#define BP_DIVISION_SIGN    BP_OBELUS
#define BP_DVSN             BP_DIVISION_SIGN
#define BP_TIMES            ALGR(KC_0)          // ×
#define BP_TIMS             BP_TIMES
#define BP_DIFFERENT        ALGR(BP_EQUAL)      // ≠
#define BP_DIFF             BP_DIFFERENT
#define BP_PERMILLE         ALGR(BP_PERCENT)    // ‰
#define BP_PMIL             BP_PERMILLE

// Second row
#define BP_PIPE                 ALGR(BP_B)          // |
#define BP_DEAD_ACUTE           ALGR(BP_E_ACUTE)    // dead ´
#define BP_DACT                 BP_DEAD_ACUTE
#define BP_AMPERSAND            ALGR(BP_P)          // &
#define BP_AMPR                 BP_AMPERSAND
#define BP_OE_LIGATURE          ALGR(BP_O)          // œ
#define BP_OE                   BP_OE_LIGATURE
#define BP_DEAD_GRAVE           ALGR(BP_E_GRAVE)    // `
#define BP_DGRV                 BP_DEAD_GRAVE
#define BP_INVERTED_EXCLAIM     ALGR(BP_DEAD_CIRCUMFLEX)    // ¡
#define BP_IXLM                 BP_INVERTED_EXCLAIM
#define BP_DEAD_CARON           ALGR(BP_V)          // dead ˇ
#define BP_DCAR                 BP_DEAD_CARON
#define BP_ETH                  ALGR(BP_D)          // ð
#define BP_DEAD_SLASH           ALGR(BP_L)          // dead /
#define BP_DSLH                 BP_DEAD_SLASH
#define BP_IJ_LIGATURE          ALGR(BP_J)          // ĳ
#define BP_IJ                   BP_IJ_LIGATURE
#define BP_SCHWA                ALGR(BP_Z)          // ə
#define BP_SCWA                 BP_SCHWA
#define BP_DEAD_BREVE           ALGR(BP_W)          // dead ˘
#define BP_DBRV                 BP_DEAD_BREVE

// Third row
#define BP_AE_LIGATURE              ALGR(BP_A)          // æ
#define BP_AE                       BP_AE_LIGATURE
#define BP_U_GRAVE                  ALGR(BP_U)          // ù
#define BP_UGRV                     BP_U_GRAVE
#define BP_DEAD_TREMA               ALGR(BP_I)          // dead ¨ (trema/umlaut/diaresis)
#define BP_DTRM                     BP_DEAD_TREMA
#define BP_EURO                     ALGR(BP_E)          // €
#define BP_TYPOGRAPHICAL_APOSTROPHE ALGR(BP_COMMA)      // ’
#define BP_TAPO                     BP_TYPOGRAPHICAL_APOSTROPHE
#define BP_COPYRIGHT                ALGR(BP_C)          // ©
#define BP_CPRT                     BP_COPYRIGHT
#define BP_THORN                    ALGR(BP_T)          // þ
#define BP_THRN                     BP_THORN
#define BP_SHARP_S                  ALGR(BP_S)          // ß
#define BP_SRPS                     BP_SHARP_S
#define BP_REGISTERED_TRADEMARK     ALGR(BP_R)          // ®
#define BP_RTM                      BP_REGISTERED_TRADEMARK
#define BP_DEAD_TILDE               ALGR(BP_N)          // dead ~
#define BP_DTLD                     BP_DEAD_TILDE
#define BP_DEAD_MACRON              ALGR(BP_M)          // dead ¯
#define BP_DMCR                     BP_DEAD_MACRON
#define BP_DEAD_CEDILLA             ALGR(BP_C_CEDILLA)  // dead ¸
#define BP_DCED                     BP_DEAD_CEDILLA

// Fourth row
#define BP_NONUS_SLASH          ALGR(BP_E_CIRCUMFLEX)   // / on non-us backslash key (102nd key, ê in bépo)
#define BP_NUSL                 BP_NONUS_SLASH
#define BP_BACKSLASH            ALGR(BP_A_GRAVE)        /* \ */
#define BP_BSLS                 BP_BACKSLASH
#define BP_LEFT_CURLY_BRACE     ALGR(BP_Y)              // {
#define BP_LCBR                 BP_LEFT_CURLY_BRACE
#define BP_RIGHT_CURLY_BRACE    ALGR(BP_X)              // }
#define BP_RCBR                 BP_RIGHT_CURLY_BRACE
#define BP_ELLIPSIS             ALGR(BP_DOT)            // …
#define BP_ELPS                 BP_ELLIPSIS
#define BP_TILDE                ALGR(BP_K)              // ~
#define BP_TILD                 BP_TILDE
#define BP_INVERTED_QUESTION    ALGR(BP_QUESTION)       // ¿
#define BP_IQST                 BP_INVERTED_QUESTION
#define BP_DEAD_RING            ALGR(BP_Q)              // dead °
#define BP_DRNG                 BP_DEAD_RING
#define BP_DEAD_GREEK           ALGR(BP_G)              // dead Greek key (following key will make a Greek letter)
#define BP_DGRK                 BP_DEAD_GREEK
#define BP_DAGGER               ALGR(BP_H)              // †
#define BP_DAGR                 BP_DAGGER
#define BP_DEAD_OGONEK          ALGR(BP_F)              // dead ˛
#define BP_DOGO                 BP_DEAD_OGONEK

// Space bar
#define BP_UNDERSCORE   ALGR(KC_SPACE)      // _
#define BP_UNDS         BP_UNDERSCORE

// AltGr-Shifted characters (different from capitalised AltGr-ed characters)
// First row
#define BP_PARAGRAPH            ALGR(BP_HASH)       // ¶
#define BP_PARG                 BP_PARAGRAPH
#define BP_LOW_DOUBLE_QUOTE     ALGR(BP_1)          // „
#define BP_LWQT                 BP_LOW_DOUBLE_QUOTE
#define BP_LEFT_DOUBLE_QUOTE    ALGR(BP_2)          // “
#define BP_LDQT                 BP_LEFT_DOUBLE_QUOTE
#define BP_RIGHT_DOUBLE_QUOTE   ALGR(BP_3)          // ”
#define BP_RDQT                 BP_RIGHT_DOUBLE_QUOTE
#define BP_LESS_OR_EQUAL        ALGR(BP_4)          // ≤
#define BP_LEQL                 BP_LESS_OR_EQUAL
#define BP_GREATER_OR_EQUAL     ALGR(BP_5)          // ≥
#define BP_GEQL                 BP_GREATER_OR_EQUAL
// nothing on ALGR(BP_6)
#define BP_NEGATION             ALGR(BP_7)          // ¬
#define BP_NEGT                 BP_NEGATION
#define BP_ONE_QUARTER          ALGR(BP_8)          // ¼
#define BP_1QRT                 BP_ONE_QUARTER
#define BP_ONE_HALF             ALGR(BP_9)          // ½
#define BP_1HLF                 BP_ONE_HALF
#define BP_THREE_QUARTERS       ALGR(BP_0)          // ¾
#define BP_3QRT                 BP_THREE_QUARTERS
#define BP_MINUTES              ALGR(BP_DEGREE)     // ′
#define BP_MNUT                 BP_MINUTES
#define BP_SECONDS              ALGR(BP_GRAVE)      // ″
#define BP_SCND                 BP_SECONDS

// Second row
#define BP_BROKEN_PIPE          LSFT(BP_PIPE)           // ¦
#define BP_BPIP                 BP_BROKEN_PIPE
#define BP_DEAD_DOUBLE_ACUTE    LSFT(BP_DEAD_ACUTE)     // ˝
#define BP_DDCT                 BP_DEAD_DOUBLE_ACUTE
#define BP_SECTION              ALGR(LSFT(BP_P))        // §
#define BP_SECT                 BP_SECTION
// LSFT(BP_DEAD_GRAVE) is actually the same character as LSFT(BP_PERCENT)
#define BP_GRAVE_BIS            LSFT(BP_DEAD_GRAVE)     // `
#define BP_GRVB                 BP_GRAVE_BIS

// Third row
#define BP_DEAD_DOT_ABOVE       LSFT(BP_DEAD_TREMA)     // dead ˙
#define BP_DDTA                 BP_DEAD_DOT_ABOVE
#define BP_DEAD_CURRENCY        LSFT(BP_EURO)           // dead ¤ (next key will generate a currency code like ¥ or £)
#define BP_DCUR                 BP_DEAD_CURRENCY
#define BP_DEAD_HORN            LSFT(ALGR(BP_COMMA))    // dead ̛
#define BP_DHRN                 BP_DEAD_HORN
#define BP_LONG_S               LSFT(ALGR(BP_C))        // ſ
#define BP_LNGS                 BP_LONG_S
#define BP_TRADEMARK            LSFT(BP_REGISTERED_TRADEMARK)   // ™
#define BP_TM                   BP_TRADEMARK
#define BP_ORDINAL_INDICATOR_O  LSFT(ALGR(BP_M))        // º
#define BP_ORDO                 BP_ORDINAL_INDICATOR_O
#define BP_DEAD_COMMA           LSFT(BP_DEAD_CEDILLA)   // dead ˛
#define BP_DCOM                 BP_DEAD_COMMA

// Fourth row
#define BP_LEFT_QUOTE           LSFT(ALGR(BP_Y))        // ‘
#define BP_LQOT                 BP_LEFT_QUOTE
#define BP_RIGHT_QUOTE          LSFT(ALGR(BP_X))        // ’
#define BP_RQOT                 BP_RIGHT_QUOTE
#define BP_INTERPUNCT           LSFT(ALGR(BP_DOT))      // ·
#define BP_IPCT                 BP_INTERPUNCT
#define BP_DEAD_HOOK_ABOVE      LSFT(ALGR(BP_QUESTION)) // dead ̉
#define BP_DHKA                 BP_DEAD_HOOK_ABOVE
#define BP_DEAD_UNDERDOT        LSFT(BP_DEAD_RING)      // dead ̣
#define BP_DUDT                 BP_DEAD_UNDERDOT
#define BP_DOUBLE_DAGGER        LSFT(BP_DAGGER)         // ‡
#define BP_DDGR                 BP_DOUBLE_DAGGER
#define BP_ORDINAL_INDICATOR_A  LSFT(ALGR(BP_F))        // ª
#define BP_ORDA                 BP_ORDINAL_INDICATOR_A

// Space bar
#define BP_NARROW_NON_BREAKING_SPACE    ALGR(BP_NON_BREAKING_SPACE)
#define BP_NNBS                         BP_NARROW_NON_BREAKING_SPACE
=======
#pragma once

#include "keymap.h"

// clang-format off

/*
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
 * │ $ │ " │ « │ » │ ( │ ) │ @ │ + │ - │ / │ * │ = │ % │       │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
 * │     │ B │ É │ P │ O │ È │ ^ │ V │ D │ L │ J │ Z │ W │     │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    │
 * │      │ A │ U │ I │ E │ , │ C │ T │ S │ R │ N │ M │ Ç │    │
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┤
 * │    │ Ê │ À │ Y │ X │ . │ K │ ' │ Q │ G │ H │ F │          │
 * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
 * │    │    │    │                        │    │    │    │    │
 * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
 */
// Row 1
#define BP_DLR  KC_GRV  // $
#define BP_DQUO KC_1    // "
#define BP_LDAQ KC_2    // «
#define BP_RDAQ KC_3    // »
#define BP_LPRN KC_4    // (
#define BP_RPRN KC_5    // )
#define BP_AT   KC_6    // @
#define BP_PLUS KC_7    // +
#define BP_MINS KC_8    // -
#define BP_SLSH KC_9    // /
#define BP_ASTR KC_0    // *
#define BP_EQL  KC_MINS // =
#define BP_PERC KC_EQL  // %
// Row 2
#define BP_B    KC_Q    // B
#define BP_EACU KC_W    // É
#define BP_P    KC_E    // P
#define BP_O    KC_R    // O
#define BP_EGRV KC_T    // È
#define BP_DCIR KC_Y    // ^ (dead)
#define BP_V    KC_U    // V
#define BP_D    KC_I    // D
#define BP_L    KC_O    // L
#define BP_J    KC_P    // J
#define BP_Z    KC_LBRC // Z
#define BP_W    KC_RBRC // W
// Row 3
#define BP_A    KC_A    // A
#define BP_U    KC_S    // U
#define BP_I    KC_D    // I
#define BP_E    KC_F    // E
#define BP_COMM KC_G    // ,
#define BP_C    KC_H    // C
#define BP_T    KC_J    // T
#define BP_S    KC_K    // S
#define BP_R    KC_L    // R
#define BP_N    KC_SCLN // N
#define BP_M    KC_QUOT // M
#define BP_CCED KC_BSLS // Ç
// Row 4
#define BP_ECIR KC_NUBS // Ê
#define BP_AGRV KC_Z    // À
#define BP_Y    KC_X    // Y
#define BP_X    KC_C    // X
#define BP_DOT  KC_V    // .
#define BP_K    KC_B    // K
#define BP_QUOT KC_N    // '
#define BP_Q    KC_M    // Q
#define BP_G    KC_COMM // G
#define BP_H    KC_DOT  // H
#define BP_F    KC_SLSH // F

/* Shifted symbols
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
 * │ # │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ ° │ ` │       │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
 * │     │   │   │   │   │   │ ! │   │   │   │   │   │   │     │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    │
 * │      │   │   │   │   │ ; │   │   │   │   │   │   │   │    │
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┤
 * │    │   │   │   │   │ : │   │ ? │   │   │   │   │          │
 * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
 * │    │    │    │                        │    │    │    │    │
 * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
 */
// Row 1
#define BP_HASH S(BP_DLR)  // #
#define BP_1    S(BP_DQUO) // 1
#define BP_2    S(BP_LDAQ) // 2
#define BP_3    S(BP_RDAQ) // 3
#define BP_4    S(BP_LPRN) // 4
#define BP_5    S(BP_RPRN) // 5
#define BP_6    S(BP_AT)   // 6
#define BP_7    S(BP_PLUS) // 7
#define BP_8    S(BP_MINS) // 8
#define BP_9    S(BP_SLSH) // 9
#define BP_0    S(BP_ASTR) // 0
#define BP_DEG  S(BP_EQL)  // °
#define BP_GRV  S(BP_PERC) // `
// Row 2
#define BP_EXLM S(BP_DCIR) // !
// Row 3
#define BP_SCLN S(BP_COMM) // ;
// Row 4
#define BP_COLN S(BP_DOT)  // :
#define BP_QUES S(BP_QUOT) // ?
// Row 5
#define BP_NBSP S(KC_SPC) // (non-breaking space)

/* AltGr symbols
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
 * │ – │ — │ < │ > │ [ │ ] │ ^ │ ± │ − │ ÷ │ × │ ≠ │ ‰ │       │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
 * │     │ | │ ´ │ & │ Œ │ ` │ ¡ │ ˇ │ Ð │ / │ Ĳ │ Ə │ ˘ │     │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    │
 * │      │ Æ │ Ù │ ¨ │ € │   │ © │ Þ │ ẞ │ ® │ ~ │ ¯ │ ¸ │    │
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┤
 * │    │   │ \ │ { │ } │ … │ ~ │ ¿ │ ° │   │ † │ ˛ │          │
 * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
 * │    │    │    │           _            │    │    │    │    │
 * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
 */
// Row 1
#define BP_NDSH ALGR(BP_DLR)  // –
#define BP_MDSH ALGR(BP_DQUO) // —
#define BP_LABK ALGR(BP_LDAQ) // <
#define BP_RABK ALGR(BP_RDAQ) // >
#define BP_LBRC ALGR(BP_LPRN) // [
#define BP_RBRC ALGR(BP_RPRN) // ]
#define BP_CIRC ALGR(BP_AT)   // ^
#define BP_PLMN ALGR(BP_PLUS) // ±
#define BP_MMNS ALGR(BP_MINS) // −
#define BP_DIV  ALGR(BP_SLSH) // ÷
#define BP_MUL  ALGR(BP_ASTR) // ×
#define BP_NEQL ALGR(BP_EQL)  // ≠
#define BP_PERM ALGR(BP_PERC) // ‰
// Row 2
#define BP_PIPE ALGR(BP_B)    // |
#define BP_ACUT ALGR(BP_EACU) // ´ (dead)
#define BP_AMPR ALGR(BP_P)    // &
#define BP_OE   ALGR(BP_O)    // Œ
#define BP_DGRV ALGR(BP_EGRV) // ` (dead)
#define BP_IEXL ALGR(BP_DCIR) // ¡
#define BP_CARN ALGR(BP_V)    // ˇ (dead)
#define BP_ETH  ALGR(BP_D)    // Ð
#define BP_DSLS ALGR(BP_L)    // / (dead)
#define BP_IJ   ALGR(BP_J)    // Ĳ
#define BP_SCHW ALGR(BP_Z)    // Ə
#define BP_BREV ALGR(BP_W)    // ˘ (dead)
// Row 3
#define BP_AE   ALGR(BP_A)    // Æ
#define BP_UGRV ALGR(BP_U)    // Ù
#define BP_DIAE ALGR(BP_I)    // ¨ (dead)
#define BP_EURO ALGR(BP_E)    // €
#define BP_COPY ALGR(BP_C)    // ©
#define BP_THRN ALGR(BP_T)    // Þ
#define BP_SS   ALGR(BP_S)    // ẞ
#define BP_REGD ALGR(BP_R)    // ®
#define BP_DTIL ALGR(BP_N)    // ~ (dead)
#define BP_MACR ALGR(BP_M)    // ¯ (dead)
#define BP_CEDL ALGR(BP_CCED) // ¸ (dead)
// Row 4
#define BP_BSLS ALGR(BP_AGRV) // (backslash)
#define BP_LCBR ALGR(BP_Y)    // {
#define BP_RCBR ALGR(BP_X)    // }
#define BP_ELLP ALGR(BP_DOT)  // …
#define BP_TILD ALGR(BP_K)    // ~
#define BP_IQUE ALGR(BP_QEST) // ¿
#define BP_RNGA ALGR(BP_Q)    // ° (dead)
#define BP_DGRK ALGR(BP_G)    // µ (dead Greek key)
#define BP_DAGG ALGR(BP_H)    // †
#define BP_OGON ALGR(BP_F)    // ˛ (dead)
// Row 5
#define BP_UNDS ALGR(KC_SPC)  // _

/* Shift+AltGr symbols
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
 * │ ¶ │ „ │ “ │ ” │ ≤ │ ≥ │   │ ¬ │ ¼ │ ½ │ ¾ │ ′ │ ″ │       │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
 * │     │ ¦ │ ˝ │ § │   │   │   │   │   │   │   │   │   │     │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    │
 * │      │   │   │ ˙ │ ¤ │ ̛  │ ſ │   │   │ ™ │   │ º │ , │    │
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┤
 * │    │   │   │ ‘ │ ’ │ · │ ⌨ │ ̉  │ ̣  │   │ ‡ │ ª │          │
 * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
 * │    │    │    │                        │    │    │    │    │
 * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
 */
// Row 1
#define BP_PARA S(ALGR(BP_DLR))  // ¶
#define BP_DLQU S(ALGR(BP_DQUO)) // „
#define BP_LDQU S(ALGR(BP_LDAQ)) // “
#define BP_RDQU S(ALGR(BP_RDAQ)) // ”
#define BP_LEQL S(ALGR(BP_LPRN)) // ≤
#define BP_GEQL S(ALGR(BP_RPRN)) // ≥
#define BP_NOT  S(ALGR(BP_PLUS)) // ¬
#define BP_QRTR S(ALGR(BP_MINS)) // ¼
#define BP_HALF S(ALGR(BP_SLSH)) // ½
#define BP_TQTR S(ALGR(BP_ASTR)) // ¾
#define BP_PRIM S(ALGR(BP_EQL))  // ′
#define BP_DPRM S(ALGR(BP_PERC)) // ″
// Row 2
#define BP_BRKP S(ALGR(BP_B))    // ¦
#define BP_DACU S(ALGR(BP_EACU)) // ˝ (dead)
#define BP_SECT S(ALGR(BP_P))    // §
// Row 3
#define BP_DOTA S(ALGR(BP_I))    // ˙ (dead)
#define BP_CURR S(ALGR(BP_E))    // ¤ (dead)
#define BP_HORN S(ALGR(BP_COMM)) // ̛  (dead)
#define BP_LNGS S(ALGR(BP_C))    // ſ
#define BP_TM   S(ALGR(BP_R))    // ™
#define BP_MORD S(ALGR(BP_M))    // º
#define BP_DCMM S(ALGR(BP_CCED)) // , (dead)
// Row 4
#define BP_LSQU S(ALGR(BP_Y))    // ‘
#define BP_RSQU S(ALGR(BP_X))    // ’
#define BP_MDDT S(ALGR(BP_DOT))  // ·
#define BP_KEYB S(ALGR(BP_K))    // ⌨
#define BP_HOKA S(ALGR(BP_QUOT)) // ̉  (dead)
#define BP_DOTB S(ALGR(BP_Q))    // ̣  (dead)
#define BP_DDAG S(ALGR(BP_H))    // ‡
#define BP_FORD S(ALGR(BP_F))    // ª
// Row 5
#define BP_NNBS S(ALGR(BP_)) // (narrow non-breaking space)
>>>>>>> upstream/master

// DEPRECATED
#define BP_DOLLAR BP_DLR
#define BP_DOUBLE_QUOTE BP_DQUO
#define BP_DQOT BP_DQUO
#define BP_LEFT_GUILLEMET BP_LDAQ
#define BP_LGIL BP_LDAQ
#define BP_RIGHT_GUILLEMET BP_RDAQ
#define BP_RGIL BP_RDAQ
#define BP_LEFT_PAREN BP_LPRN
#define BP_RIGHT_PAREN BP_RPRN
#define BP_MINUS BP_MINS
#define BP_SLASH BP_SLSH
#define BP_ASTERISK BP_ASTR
#define BP_EQUAL BP_EQL
#define BP_PERCENT BP_PERC
#define BP_E_ACUTE BP_EACU
#define BP_ECUT BP_EACU
#define BP_E_GRAVE BP_EGRV
#define BP_DEAD_CIRCUMFLEX BP_DCIR
#define BP_DCRC BP_DCIR
#define BP_COMMA BP_COMM
#define BP_C_CEDILLA BP_CCED
#define BP_E_CIRCUMFLEX BP_ECIR
#define BP_ECRC BP_ECIR
#define BP_A_GRAVE BP_AGRV
#define BP_APOSTROPHE BP_QUOT
#define BP_APOS BP_QUOT
#define BP_DEGREE BP_DEG
#define BP_DEGR BP_DEG
#define BP_GRAVE BP_GRV
#define BP_EXCLAIM BP_EXLM
#define BP_SCOLON BP_SCLN
#define BP_COLON BP_COLN
#define BP_QUESTION BP_QUES
#define BP_QEST BP_QUES
#define BP_NON_BREAKING_SPACE BP_NBSP
#define BP_EN_DASH BP_NDSH
#define BP_EM_DASH BP_MDSH
#define BP_LESS BP_LABK
#define BP_GREATER BP_RABK
#define BP_GRTR BP_RABK
#define BP_LBRACKET BP_LBRC
#define BP_RBRACKET BP_RBRC
#define BP_CIRCUMFLEX CIRC
#define BP_PLUS_MINUS BP_PLMN
#define BP_PSMS BP_PLMN
#define BP_MATH_MINUS BP_MMNS
#define BP_OBELUS BP_DIV
#define BP_OBEL BP_DIV
#define BP_DIVISION_SIGN BP_DIV
#define BP_DVSN BP_DIV
#define BP_TIMES BP_MUL
#define BP_TIMS BP_MUL
#define BP_DIFFERENT BP_NEQL
#define BP_DIFF BP_NEQL
#define BP_PERMILLE BP_PERM
#define BP_PMIL BP_PERM
#define BP_DEAD_ACUTE BP_ACUT
#define BP_DACT BP_ACUT
#define BP_AMPERSAND BP_AMPR
#define BP_OE_LIGATURE BP_OE
#define BP_DEAD_GRAVE BP_DGRV
#define BP_INVERTED_EXCLAIM BP_IEXL
#define BP_IXLM BP_IEXL
#define BP_DEAD_CARON BP_CARN
#define BP_DCAR BP_CARN
#define BP_DEAD_SLASH BP_DSLS
#define BP_DSLH BP_DSLS
#define BP_IJ_LIGATURE BP_IJ
#define BP_SCHWA BP_SCHW
#define BP_SCWA BP_SCHW
#define BP_DEAD_BREVE BP_BREV
#define BP_DBRV BP_BREV
#define BP_AE_LIGATURE BP_AE
#define BP_U_GRAVE BP_UGRV
#define BP_DEAD_TREMA BP_DIAE
#define BP_DTRM BP_DIAE
#define BP_TYPOGRAPHICAL_APOSTROPHE BP_COMM
#define BP_TAPO BP_COMM
#define BP_COPYRIGHT BP_COPY
#define BP_CPRT BP_COPY
#define BP_THORN BP_THRN
#define BP_SHARP_S BP_SS
#define BP_SRPS BP_SS
#define BP_REGISTERED_TRADEMARK BP_REGD
#define BP_RTM BP_REGD
#define BP_DEAD_TILDE BP_DTIL
#define BP_DTLD BP_DTIL
#define BP_DEAD_MACRON BP_MACR
#define BP_DMCR BP_MACR
#define BP_DEAD_CEDILLA BP_CEDL
#define BP_DCED BP_CEDL
#define BP_NONUS_SLASH BP_SLSH
#define BP_NUSL BP_SLSH
#define BP_BACKSLASH BP_BSLS
#define BP_LEFT_CURLY_BRACE BP_LCBR
#define BP_RIGHT_CURLY_BRACE BP_RCBR
#define BP_ELLIPSIS BP_ELLP
#define BP_ELPS BP_ELLP
#define BP_TILDE BP_TILD
#define BP_INVERTED_QUESTION BP_IQUE
#define BP_IQST BP_IQUE
#define BP_DEAD_RING BP_RNGA
#define BP_DRNG BP_RNGA
#define BP_DEAD_GREEK BP_DGRK
#define BP_DAGGER BP_DAGG
#define BP_DAGR BP_DAGG
#define BP_DEAD_OGONEK BP_OGON
#define BP_DOGO BP_OGON
#define BP_UNDERSCORE BP_UNDS
#define BP_PARAGRAPH BP_PARA
#define BP_PARG BP_PARA
#define BP_LOW_DOUBLE_QUOTE BP_DLQU
#define BP_LWQT BP_DLQU
#define BP_LEFT_DOUBLE_QUOTE BP_RDQU
#define BP_RIGHT_DOUBLE_QUOTE BP_RDQU
#define BP_LESS_OR_EQUAL BP_LEQL
#define BP_GREATER_OR_EQUAL BP_GEQL
#define BP_NEGATION BP_NOT
#define BP_NEGT BP_NOT
#define BP_ONE_QUARTER BP_QRTR
#define BP_1QRT BP_QRTR
#define BP_ONE_HALF BP_HALF
#define BP_1HLF BP_HALF
#define BP_THREE_QUARTERS TQTR
#define BP_3QRT BP_TQTR
#define BP_MINUTES BP_PRIM
#define BP_MNUT BP_PRIM
#define BP_SECONDS BP_DPRM
#define BP_SCND BP_DPRM
#define BP_BROKEN_PIPE BP_BRKP
#define BP_BPIP BP_BRKP
#define BP_DEAD_DOUBLE_ACUTE BP_DACU
#define BP_DDCT BP_DACU
#define BP_SECTION BP_SECT
#define BP_GRAVE_BIS BP_GRV
#define BP_GRVB BP_GRV
#define BP_DEAD_DOT_ABOVE BP_DOTA
#define BP_DDTA BP_DOTA
#define BP_DEAD_CURRENCY BP_CURR
#define BP_DCUR BP_CURR
#define BP_DEAD_HORN BP_HORN
#define BP_DHRN BP_HORN
#define BP_LONG_S BP_LNGS
#define BP_TRADEMARK BP_TM
#define BP_ORDINAL_INDICATOR_O MORD
#define BP_ORDO BP_MORD
#define BP_DEAD_COMMA BP_DCMM
#define BP_DCOM BP_DCMM
#define BP_LEFT_QUOTE BP_LSQU
#define BP_LQOT BP_LSQU
#define BP_RIGHT_QUOTE BP_RSQU
#define BP_RQOT BP_RSQU
#define BP_INTERPUNCT BP_MDDT
#define BP_IPCT BP_MDDT
#define BP_DEAD_HOOK_ABOVE BP_HOKA
#define BP_DHKA BP_HOKA
#define BP_DEAD_UNDERDOT BP_DOTB
#define BP_DUDT BP_DOTB
#define BP_DOUBLE_DAGGER BP_DDAG
#define BP_DDGR BP_DDAG
#define BP_ORDINAL_INDICATOR_A BP_FORD
#define BP_ORDA BP_FORD
#define BP_NARROW_NON_BREAKING_SPACE BP_NNBS
