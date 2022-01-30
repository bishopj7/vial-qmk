 /* Copyright 2021 Milan Düwel
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

#include QMK_KEYBOARD_H

enum custom_layers {
    PAD,
    _QW,
    NUM,
    DIR
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Single 4x4 board only
 * .-----------------------------------.
 * |   7    |   8    |   9    |   /    |
 * |--------+--------+--------+--------|
 * |   4    |   5    |   6    |   *    |
 * |--------+--------+--------+--------|
 * |   1    |   2    |   3    |   -    |
 * |--------+--------+--------+--------|
 * |   0    | QWERTY |   .    |   +    |
 * '-----------------------------------'
 */

  [PAD] = LAYOUT_ortho_4x16(
  KC_KP_7, KC_KP_8, KC_KP_9,   KC_PSLS, DF(_QW), DF(_QW), DF(_QW), DF(_QW), DF(_QW), DF(_QW), DF(_QW), DF(_QW), DF(_QW), DF(_QW), DF(_QW), DF(_QW),
  KC_KP_4, KC_KP_5, KC_KP_6,   KC_PAST, DF(_QW), DF(_QW), DF(_QW), DF(_QW), DF(_QW), DF(_QW), DF(_QW), DF(_QW), DF(_QW), DF(_QW), DF(_QW), DF(_QW),
  KC_KP_1, KC_KP_2, KC_KP_3,   KC_PMNS, DF(_QW), DF(_QW), DF(_QW), DF(_QW), DF(_QW), DF(_QW), DF(_QW), DF(_QW), DF(_QW), DF(_QW), DF(_QW), DF(_QW),
  KC_KP_0, MO(DIR), KC_KP_DOT, KC_PPLS, DF(_QW), DF(_QW), DF(_QW), DF(_QW), DF(_QW), DF(_QW), DF(_QW), DF(_QW), DF(_QW), DF(_QW), DF(_QW), DF(_QW)
  ),

/* QWERTY
 * .-----------------------------------------------------------------------------------------------------------------------------------------------.
 * | ESC    | Q      | W      | E      | R      | T      | Y      | U      | I      | O      | P      | BACKSP |   7    |   8    |   9    |   /    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | TAB    | A      | S      | D      | F      | G      | H      | J      | K      | L      | ;      | '      |   4    |   5    |   6    |   *    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | SHIFT  | Z      | X      | C      | V      | B      | N      | M      | ,      | .      | /      | ENT/SFT|   1    |   2    |   3    |   -    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | LCTRL  | LGUI   | ALT    | ALT    | NUM    | SHIFT  | SPACE  | DIR    | RGUI   | RALT   | DEL    | CTRL   |   0    |   0    |   .    |   +    |
 * '-----------------------------------------------------------------------------------------------------------------------------------------------'
 */

  [_QW] = LAYOUT_ortho_4x16(
  KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, KC_KP_7, KC_KP_8, KC_KP_9, KC_PSLS,
  KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_KP_4, KC_KP_5, KC_KP_6, KC_PAST,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_T(KC_ENT), KC_KP_1, KC_KP_2, KC_KP_3, KC_PMNS,
  KC_LCTL, KC_LGUI, KC_LALT, KC_LALT, MO(NUM), KC_LSFT, KC_SPC,  MO(DIR), KC_RGUI, KC_RALT, KC_DEL,  KC_RCTL, KC_KP_0, KC_KP_0, KC_KP_DOT, KC_PPLS
  ),

/* NUMBERS
 * .-----------------------------------------------------------------------------------------------------------------------------------------------.
 * |        | F1     | F2     | F3     | F4     | F5     | F6     | F7     | F8     | F9     | F10    | NUMLOCK|   /    |   *    |   -    |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |    `   | 1      | 2      | 3      | 4      | 5      | 6      | 7      | 8      | 9      | 0      |        |        |        |   +    |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | F11    | F12    |        |        |        | ENTER  | SHIFT  | RGUI   | ./ALT  | BKSC   |        |        |        | ENTER  |        |
 * |        |        |        |        |        |        |        |        |        |        |CTRLhold|		   |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        | ENTER  | SHIFT  |        |        |        |        |        |        |        |        |
 * '-----------------------------------------------------------------------------------------------------------------------------------------------'
 */

  [NUM] = LAYOUT_ortho_4x16(
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, _______,
   KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     _______, _______, _______, KC_PPLS, _______,
  _______, KC_F11,  KC_F12,  _______, _______, _______, KC_ENT,  KC_RSFT, KC_RGUI, ALT_T(KC_DOT), CTL_T(KC_BSPC), _______, _______, _______, KC_PENT, _______,
  _______, _______, _______, _______, _______, _______, KC_ENT,  KC_RSFT, _______, _______, _______,  _______, _______, _______, _______, _______
  ),

/* DIRECTIONS
 * .-----------------------------------------------------------------------------------------------------------------------------------------------.
 * | RESET  | TAB    |   up   |        | INS    | CTRL   | SHIFT  | PgUp   | Home   |   -    |   =    |  DEL   |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | CAPSLK | left   |  down  | right  | PrScr  | SHIFT  | CTRL   | PgDn   | End    |   [    |   ]    |   \    |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | P-Brk  |        |        |        |        |        |        | RGUI   | ALT    |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | KEYPAD |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * '-----------------------------------------------------------------------------------------------------------------------------------------------'
 */

  [DIR] = LAYOUT_ortho_4x16(
  RESET,   KC_TAB,  KC_UP,   _______, KC_INS,  KC_LCTL, KC_LSFT, KC_PGUP, KC_HOME, KC_MINS, KC_EQL,  KC_DEL,  _______, _______, _______, _______,
  KC_CAPS, KC_LEFT, KC_DOWN, KC_RGHT, KC_PSCR, KC_LSFT, KC_LCTL, KC_PGDN, KC_END,  KC_LBRC, KC_RBRC, KC_BSLS, _______, _______, _______, _______,
  _______, KC_PAUS, _______, _______, _______, _______, _______, _______, KC_RGUI, KC_RALT, _______, _______, _______, _______, _______, _______,
  DF(PAD), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

};
