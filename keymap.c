/* Copyright 2017 Wunder
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

// Layer shorthand
#define _QWERTY 0
#define _QWERTY2 2
#define _GAME 3
#define _ARROW 12
#define _LOWER 14
#define _RAISE 15
#define _ADJUST 16

// Macro name shortcuts
#define QWERTY M(_QWERTY)
#define QWERTY2 M(_QWERTY2)
#define GAME M(_GAME)
#define ARROW M(_ARROW)
#define LOWER M(_LOWER)
#define RAISE M(_RAISE)

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | `      | 1      | 2      | 3      | 4      | 5      | *      | -      | +      | 6      | 7      | 8      | 9      | 0      | BACKSP |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | E      | R      | T      | 7      | 8      | 9      | Y      | U      | I      | O      | P      | \      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | ESC    | A      | S      | D      | F      | G      | 4      | 5      | 6      | H      | J      | K      | L      | ;      | '      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | LSHIFT | Z      | X      | C      | V      | B      | 1      | 2      | 3      | N      | M      | ,      | .      | /      | ENTER  |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | LCTRL  | LGUI   | CAPS   | LALT   | Lower  | SPACE  | NMLK   | 0      | .      | SPACE  | Raise  | -      | =      | [      | ]      |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

  [_QWERTY] = LAYOUT_ortho_5x15( 
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_PAST, KC_PMNS,  KC_PPLS,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_P7,   KC_P8,    KC_P9,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLASH,
    LT(_RAISE, KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_P4,   KC_P5,    KC_P6,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_P1,   KC_P2,    KC_P3,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
    KC_LCTL, KC_LGUI, KC_CAPS, KC_LALT, LOWER,  LT(_RAISE, KC_SPC),  KC_NLCK, KC_P0, KC_PDOT, LT(_LOWER, KC_SPC),  RAISE,  KC_MINUS, KC_EQUAL, KC_LBRC,  KC_RBRC
  ),

/* QWERTY2
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | `      | 1      | 2      | 3      | 4      | 5      | -      | `      | =      | 6      | 7      | 8      | 9      | 0      | BACKSP |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | E      | R      | T      | [      | \      | ]      | Y      | U      | I      | O      | P      | \      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | ESC    | A      | S      | D      | F      | G      | HOME   | DEL    | PG UP  | H      | J      | K      | L      | ;      | '      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | LSHIFT | Z      | X      | C      | V      | B      | END    | UP     | PG DN  | N      | M      | ,      | .      | /      | ENTER  |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | LCTRL  | LGUI   | CAPS   | LALT   | Lower  | SPACE  | LEFT   | DOWN   | RIGHT  | SPACE  | Raise  | -      | =      | [      | ]      |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

  [_QWERTY2] = LAYOUT_ortho_5x15( 
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS, KC_GRV,  KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC, KC_BSLS, KC_RBRC,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLASH,
    LT(_RAISE, KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_HOME, KC_DEL,  KC_PGUP,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_END,  KC_UP,   KC_PGDN,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
    KC_LCTL, KC_LGUI, KC_CAPS, KC_LALT, LOWER,  LT(_RAISE, KC_SPC),  KC_LEFT, KC_DOWN, KC_RGHT, LT(_LOWER, KC_SPC),  RAISE,  KC_MINUS, KC_EQUAL, KC_LBRC,  KC_RBRC
  ),


/* GAME
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | ESC    | 1      | 2      | 3      | 4      | 5      | *      | -      | +      | 6      | 7      | 8      | 9      | 0      | BACKSP |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | E      | R      | T      | 7      | 8      | 9      | Y      | U      | I      | O      | P      | \      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | CAPS   | A      | S      | D      | F      | G      | 4      | 5      | 6      | H      | J      | K      | L      | ;      | '      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | LSHIFT | Z      | X      | C      | V      | B      | 1      | 2      | 3      | N      | M      | ,      | .      | /      | ENTER  |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | LCTRL  | LGUI   | CAPS   | LALT   | Lower  | SPACE  | NMLK   | 0      | .      | SPACE  | Raise  | -      | =      | [      | ]      |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

  [_GAME] = LAYOUT_ortho_5x15( 
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_PAST, KC_PMNS,  KC_PPLS,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_P7,   KC_P8,    KC_P9,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLASH,
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_P4,   KC_P5,    KC_P6,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_P1,   KC_P2,    KC_P3,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
    KC_LCTL, XXXXXXX, KC_CAPS, KC_LALT, LOWER,  KC_SPC,  KC_NLCK, KC_P0, KC_PDOT, KC_SPC,  RAISE,  KC_MINUS, KC_EQUAL, KC_LBRC,  KC_RBRC
  ),


/* LOWER
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | F1     | F2     | F3     | F4     | F5     | F6     | MWLeft | Refr   | MWRt   | F7     | F8     | F9     | F10    | F11    | F12    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | MUTE   | BkSpc  | UP     | DEL    |        | Forwd  | MBtn1  | MUp    | MBtn2  |        |        |        | PR SCR | SCR LK | PAUSE  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | LEFT   | DOWN   | RIGHT  |        | Refr   | MLeft  | MDown  | MRight |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | VOL+   | PREV   | PLAY   | NEXT   |        | Back   | MWDn   | MBtn3  | MWUp   |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | VOL-   |        |        |        |        |        |        |        |        |        |        | CALC   |  MAIL  |  MEDIA |  COMP  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

  [_LOWER] = LAYOUT_ortho_5x15( 
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_WH_L, KC_WWW_REFRESH, KC_WH_R, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    KC_MUTE, KC_BSPC, KC_UP, KC_DEL, _______, KC_WWW_FORWARD, KC_BTN1, KC_MS_U, KC_BTN2,   _______, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS,
    _______, KC_LEFT,  KC_DOWN, KC_RIGHT, _______, KC_WWW_REFRESH, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,   _______, _______, _______, _______,
    KC_VOLU, KC_MPRV,  KC_MPLY, KC_MNXT,  _______, KC_WWW_BACK, KC_WH_D, KC_BTN3, KC_WH_U,   _______, _______, _______, _______, _______, _______,
    KC_VOLD, _______, _______, _______, _______,_______, _______,   _______, _______, _______, _______, KC_CALC,  KC_MAIL, KC_MSEL,  KC_MYCM
  ),


/* RAISE
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | ~      | !      | @      | #      | $      | %      | MWLeft | Refr   | MWRt   | ^      | &      | *      | (      | )      | BkSpc  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | PAUSE  | SCR LK | PR SCR |        |        | Forwd  | MBtn1  | MUp    | MBtn2  |        |        | BkSpc  | UP     | DEL    | MUTE   |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        | Refr   | MLeft  | MDown  | MRight |        |        | LEFT   | DOWN   | RIGHT  |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        | Back   | MWDn   | MBtn3  | MWUp   |        |        | PREV   | PLAY   | NEXT   | VOL+   |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | CALC   |  MAIL  |  MEDIA |  COMP  |        |        |        |        |        |        |        |        |        |        | VOL-   |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

  [_RAISE] = LAYOUT_ortho_5x15( 
    KC_GRV, KC_EXLM, KC_AT,    KC_HASH, KC_DLR,  KC_PERC,   KC_WH_L, KC_WWW_REFRESH, KC_WH_R, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN,  KC_RPRN, KC_BSPC,
    KC_PAUS, KC_SLCK, KC_PSCR, _______, _______, KC_WWW_FORWARD, KC_BTN1, KC_MS_U, KC_BTN2,   _______, _______, KC_BSPC, KC_UP, KC_DEL, KC_MUTE,
    _______, _______,  _______, _______, _______, KC_WWW_REFRESH, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,   KC_LEFT,  KC_DOWN, KC_RIGHT, _______,
    _______, _______,  _______, _______,  _______, KC_WWW_BACK, KC_WH_D, KC_BTN3, KC_WH_U,   _______, _______, KC_MPRV,  KC_MPLY, KC_MNXT, KC_VOLU,
    KC_CALC,  KC_MAIL, KC_MSEL,  KC_MYCM, _______,_______, _______,   _______, _______, _______, _______, _______,  _______, _______,  KC_VOLD
  ),  

/* ADJUST (LOWER + RAISE)
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        | RGB HD | RGB HI | RGB TG |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        | RGB SD | RGB SI |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        | RGB VD | RGB VI |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        | RGB RMD| RGB MD | Sleep  | POWER  | Wake   |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        | RESET  |        |        |        | QWERTY | GAME   | QWERTY2| ARROW  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

  [_ADJUST] = LAYOUT_ortho_5x15( 
    _______, _______,  _______, _______, RGB_HUD, RGB_HUI, RGB_TOG,  _______, _______, _______, _______, _______,  _______, _______, _______,
    _______, _______,  _______, _______, RGB_SAD, RGB_SAI, _______,  _______, _______, _______, _______, _______,  _______, _______, _______,
    _______, _______,  _______, _______, RGB_VAD, RGB_VAI, _______,  _______, _______, _______, _______, _______,  _______, _______, _______,
    _______, _______,  _______, _______, RGB_RMOD,RGB_MOD, KC_SYSTEM_SLEEP,  KC_PWR, KC_SYSTEM_WAKE, _______, _______, _______,  _______, _______, _______,
    _______, _______,  _______, _______, _______, _______, _______,    RESET, _______, _______, _______, QWERTY,  GAME, QWERTY2,  ARROW
  )

};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case _QWERTY:
          if (record->event.pressed) {
            persistent_default_layer_set(1UL<<_QWERTY);
          }
          break;
        case _QWERTY2:
          if (record->event.pressed) {
            persistent_default_layer_set(1UL<<_QWERTY2);
          }
          break;
        case _GAME:
          if (record->event.pressed) {
            persistent_default_layer_set(1UL<<_GAME);
          }
          break;
        case _ARROW:
          if (record->event.pressed) {
            persistent_default_layer_set(1UL<<_LOWER);
          }
          break;
        case _LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          break;
        case _RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          break;
      }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QMKBEST:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("QMK is the best thing ever!");
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case QMKURL:
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        SEND_STRING("https://qmk.fm/" SS_TAP(X_ENTER));
      } else {
        // when keycode QMKURL is released
      }
      break;
  }
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
