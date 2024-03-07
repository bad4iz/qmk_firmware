/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum layer_names {
    _QWERTY,
_LOWER,
_RAISE,
};


#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

#define ONE_GRV LT(1,KC_GRAVE)
#define CTL_Z LCTL_T(KC_Z)
#define ALT_SHFT LALT(KC_LSFT)
#define ALT_MENU LALT_T(KC_MENU)
#define LG_QUOT LGUI_T(KC_QUOT)
#define CTL_ESC LCTL_T(KC_ESC)
#define CTL_SLS LCTL_T(KC_SLSH)
#define LT2_COL LT(_RAISE, KC_SCLN)


enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
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
    }
    return true;
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_5x6_5(
        KC_EQL , KC_2  ,KC_2   , KC_3  , KC_4  , KC_5  ,                                        KC_6   , KC_7  , KC_8  , KC_9  , KC_0  ,KC_BSPC,
        KC_GRV , KC_Q  ,KC_W   , KC_F  , KC_P  , KC_B  ,                                        KC_J   , KC_L  , KC_U  , KC_Y  ,KC_SCLN,KC_LBRC,
        KC_ESC , KC_A  ,KC_R   , KC_S  , KC_T  , KC_G  ,                                        KC_M   , KC_N  , KC_E  , KC_I  , KC_O  ,KC_QUOT,
        _______, CTL_Z ,KC_X   , KC_C  , KC_D  , KC_V  ,                                        KC_K   , KC_H  ,KC_COMM, KC_DOT,KC_SLSH,KC_RBRC,
                                               KC_TAB  ,KC_2,KC_ENT ,       KC_6,KC_7, KC_BSPC,
                                                        KC_3,KC_4,          KC_8,KC_9

    ),
    [_LOWER] = LAYOUT_5x6_5(
        _______,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,                                       KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,
        _______,KC_EXLM,KC_AT  ,KC_LBRC,KC_RBRC,KC_PIPE,                                       KC_UP  ,KC_P7  ,KC_P8  ,KC_P9  ,KC_PAST,KC_F12 ,
        _______,KC_HASH,KC_DLR ,KC_LPRN,KC_RPRN,KC_GRV ,                                       KC_DOWN,KC_P4  ,KC_P5  ,KC_P6  ,KC_PPLS,_______,
        _______,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,                                       KC_AMPR,KC_P1  ,KC_P2  ,KC_P3  ,KC_PSLS,_______,
                                                _______,_______,_______,       _______,_______,_______,
                                                        _______,_______,       _______,_______

    ),
    [_RAISE] = LAYOUT_5x6_5(
        _______,_______,_______,_______,_______,_______,                                       _______,_______,_______,_______,_______,_______,
        _______,_______,_______,KC_MS_U,_______,_______,                                       _______,_______,_______,_______,_______,_______,
        _______,_______,KC_MS_L,KC_MS_D,KC_MS_R,_______,                                       _______,_______,_______,_______,_______,KC_MPLY,
        _______,_______,_______,_______,_______,_______,                                       _______,_______,KC_MPRV,KC_MNXT,_______,_______,
                                                _______,_______,_______,       _______,_______,_______,
                                                        _______,_______,       _______,_______
    )
};
