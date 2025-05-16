/*
This is the c configuration file for the keymap

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
#include "keymap_norwegian.h"

#define _BASE 0
#define _RAISE 1
#define _LOWER 2

#define SFT_ESC  SFT_T(KC_ESC)
#define CTL_BSPC CTL_T(KC_BSPC)
#define ALT_SPC  ALT_T(KC_SPC)
#define SFT_ENT  SFT_T(KC_ENT)

#define KC_ML KC_MS_LEFT
#define KC_MR KC_MS_RIGHT
#define KC_MU KC_MS_UP
#define KC_MD KC_MS_DOWN
#define KC_MB1 KC_MS_BTN1
#define KC_MB2 KC_MS_BTN2

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

enum custom_keycodes {
    GUI_H = SAFE_RANGE, // Remap GUI directions because GUI+L cannot be remapped in windows
    GUI_J,
    GUI_K,
    GUI_L,
    R_SET_1,
    R_SET_2,
    R_SET_3,
    R_SET_4,
    R_WH_L,
    R_WH_D,
    R_WH_U,
    R_WH_R,
    R_LEFT,
    R_DOWN,
    R_UP,
    R_RIGHT,
    R_MS_L,
    R_MS_D,
    R_MS_U,
    R_MS_R,
    R_TL_ACL,

};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(  //   QWERY layer

        KC_Q,       KC_W,       KC_E,      KC_R,       KC_T,                    KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,
        KC_A,       KC_S,       KC_D,      KC_F,       KC_G,                    GUI_H,      GUI_J,      GUI_K,      GUI_L,      KC_N,
        KC_Z,       KC_X,       KC_C,      KC_V,       KC_B,                    NO_AE,      KC_M,       KC_COMM,    KC_DOT,     KC_QUOT,
                    NO_QUES,    NO_EXLM,                                                                NO_OSTR,    NO_ARNG,
                                                KC_SPC,LT(1,KC_ENT),        LT(2, KC_ESC),KC_BSPC,
                                                KC_LCTL,    KC_LGUI,        KC_LSFT,    KC_LALT,
                                                NO_QUOT,    NO_DQUO,        NO_AT,      KC_RCTL
    ),


    [1] = LAYOUT(  //   Navigation layer

        KC_HOME,    KC_PGDN,    KC_PGUP,    KC_END,     KC_INS,                 R_WH_L,     R_WH_D,     R_WH_U,     R_WH_R,     KC_DEL,
        R_SET_1,    R_SET_2,    R_SET_3,    R_SET_4,    MS_BTN4,                R_LEFT,     R_DOWN,     R_UP,       R_LEFT,     KC_TAB,
        R_TL_ACL,   MS_BTN3,    MS_BTN2,    MS_BTN1,    MS_BTN5,                R_MS_L,     R_MS_D,     R_MS_U,     R_MS_R,     KC_APP,
                    XXXXXXX,    XXXXXXX,                                                                XXXXXXX,    XXXXXXX,
                                                _______,    _______,        MO(3),      _______,
                                                _______,    _______,        _______,    _______,
                                                XXXXXXX,    XXXXXXX,        XXXXXXX,    _______
    ),

    [2] = LAYOUT(  //   Number and symbols layer
                 //
        NO_LBRC,    NO_LCBR,    NO_LPRN,    NO_SLSH,    NO_LABK,                NO_RABK,    NO_BSLS,    NO_RPRN,    NO_RCBR,    NO_RBRC,
        KC_1,       KC_2,       KC_3,       KC_4,       KC_5,                   KC_6,       KC_7,       KC_8,       KC_9,       KC_0,
        KC_PERC,    KC_EQL,     NO_ASTR,    NO_PLUS,    NO_HASH,                NO_AMPR,    NO_MINS,    KC_COMM,    KC_DOT,     KC_UNDS,
                    NO_DLR,     NO_PIPE,                                                                NO_CIRC,    XXXXXXX,
                                                _______,    MO(3),          _______,    _______,
                                                _______,    _______,        _______,    _______,
                                                XXXXXXX,    XXXXXXX,        XXXXXXX,    _______
    ),

    [3] = LAYOUT(  //   Function layer

        QK_BOOT,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                KC_MPREV,   KC_VOLD,    KC_VOLU,    KC_MNXT,    KC_MPLY,
        KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,                  KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,
        KC_F11,     KC_F12,     XXXXXXX,    XXXXXXX,    XXXXXXX,                XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
                    XXXXXXX,    XXXXXXX,                                                                XXXXXXX,    XXXXXXX,
                                                _______,    _______,        _______,    _______,
                                                _______,    _______,        _______,    _______,
                                                XXXXXXX,    XXXXXXX,        XXXXXXX,    _______
    )
}
