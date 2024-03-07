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

#define _QWERTY 0
#define _LOWER 1
#define _SYMBOLS 2

#define SYMBOLS MO(_SYMBOLS)
#define LOWER MO(_LOWER)

#define ONE_GRV LT(1,KC_GRAVE)
#define CTL_Z LCTL_T(KC_Z)
#define ALT_SHFT LALT(KC_LSFT)
#define ALT_MENU LALT_T(KC_MENU)
#define LG_QUOT LGUI_T(KC_QUOT)
#define CTL_ESC LCTL_T(KC_ESC)
#define CTL_SLS LCTL_T(KC_SLSH)
#define LT2_COL LT(_RAISE, KC_SCLN)

#define LANG LSFT_T(KC_T)




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
    case KC_ESC:
        if (record->event.pressed) {
            SEND_STRING(SS_LALT(")")); // Отправить строку "Alt+)"
        } else {

        }
        break;

    }
    return true;
};




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Del  |  '"  |   ,  |   .  |   P  |   Y  |                    |   F  |   G  |   C  |   R  |   L  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   A  |   O  |   E  |   U  |   I  |                    |   D  |   H  |   T  |   N  | S/L2 |//Cmd |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|;/Ctrl|   Q  |   J  |   K  |   X  |                    |   B  |   M  |   W  |   V  |Z/Ctrl|RShift|
 * |------+------+------+------+------+------'                    `------+------+------+------+------+------|
 * |Grv/L1|   =  |AltShf|Lef  | Right|                                  |  Up  | Down |   [  |   ]  | ~L1  |
 * `----------------------------------'                                  `----------------------------------'
 *                               | -----,-------------.  ,-------------.------.
 *                               |  5   |  4   | 1    |  |  8   |  0   |  9   |
 *                               ,------|------|------|  |------+------+------.
 *                               |      |      | 2    |  |  7   |
 *                               | Space|Backsp|------|  |------|
 *                               |      |ace   | 3    |  |  6   |
 *                               `--------------------'  `-------
 *
 *                               123                      678
 *                                45                      90
 */
    [_QWERTY] = LAYOUT_6x6(

        KC_EQL , KC_2  ,KC_2   , KC_3  , KC_4  , KC_5  ,                                        KC_6   , KC_7  , KC_8  , KC_9  , KC_0  ,KC_BSPC,
        KC_GRV , KC_Q  ,KC_W   , KC_F  , KC_P  , KC_B  ,                                        KC_J   , KC_L  , KC_U  , KC_Y  ,KC_SCLN,KC_LBRC,
        KC_ESC , KC_A  ,KC_R   , KC_S  , KC_T  , KC_G  ,                                        KC_M   , KC_N  , KC_E  , KC_I  , KC_O  ,KC_QUOT,
        _______, CTL_Z ,KC_X   , KC_C  , KC_D  , KC_V  ,                                        KC_K   , KC_H  ,KC_COMM, KC_DOT,KC_SLSH,KC_RBRC,
        _______,_______,_______,_______,_______,_______,                                        _______,_______,_______,_______,_______,_______,
                                                 KC_NO,LGUI(KC_SPC), KC_ENT,        KC_BSPC, KC_9 , KC_9   ,
                                                                     LOWER ,        SYMBOLS,
                                                                     KC_TAB,        KC_SPC
    ),
    [_LOWER] = LAYOUT_6x6(
        KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,                                       KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,
        _______,KC_NO  ,KC_NO  ,KC_NO  , KC_NO , KC_NO ,                                       KC_DOWN,KC_RGHT,KC_P8  ,KC_P9  ,KC_PAST,KC_F12 ,
        _______,KC_LGUI,KC_LALT,KC_LCTL,KC_LSFT, KC_NO ,                                       KC_DOWN,KC_P4  ,KC_P5  ,KC_P6  ,KC_PPLS,_______,
        _______, KC_NO , KC_NO , KC_NO , KC_NO , KC_NO ,                                       KC_UP  ,KC_LEFT,KC_P2  ,KC_P3  ,KC_PSLS,_______,
        _______,_______,_______,_______,_______,_______,                                       _______,_______,_______,_______  ,_______,_______,
                                                _______,_______,_______,       _______,_______,_______,
                                                                _______,       _______,
                                                                _______,       _______
    ),
    [_SYMBOLS] = LAYOUT_6x6(
        _______,_______,_______,_______ , _______     , _______     ,                                       _______,_______,_______,_______,_______,_______,
        _______,_______,_______, KC_MS_U,LSFT(KC_LBRC),LSFT(KC_RBRC),                                       _______,_______,_______,_______,_______,_______,
        _______,_______,KC_MS_L, KC_MS_D,LSFT(KC_9)   , LSFT(KC_0)  ,                                       _______,_______,_______,_______,_______,KC_MPLY,
        _______,_______,_______, _______, KC_LBRC     ,KC_RBRC      ,                                       _______,_______,KC_MPRV,KC_MNXT,_______,_______,
        _______,_______,_______, _______, _______     , _______     ,                                       KC_WBAK,KC_VOLU,KC_VOLD,KC_MUTE,_______,_______,
                                                _______,_______,_______,       _______,_______,_______,
                                                                _______,       _______,
                                                                _______,       _______
    )
};
