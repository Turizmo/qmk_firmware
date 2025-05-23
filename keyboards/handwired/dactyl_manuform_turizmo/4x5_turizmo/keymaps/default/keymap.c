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

    [0] = LAYOUT(  //   QWERTY layer

        KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,                               KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,
        KC_A,       KC_S,       KC_D,       KC_F,       KC_G,                               GUI_H,      GUI_J,      GUI_K,      GUI_L,      KC_N,
        KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,                               NO_AE,      KC_M,       KC_COMM,    KC_DOT,     KC_QUOT,
                    NO_QUES,    NO_EXLM,                                                                            NO_OSTR,    NO_ARNG,
                                            KC_SPC,     LT(1,KC_ENT), KC_LCTL,  KC_LALT,    LT(2,KC_ESC),KC_BSPC,
                                            NO_QUOT,    KC_LGUI,    NO_DQUO,    KC_RCTL,    KC_LSFT,    NO_AT
    ),

    [1] = LAYOUT(  //   Navigation layer

        KC_HOME,    KC_PGDN,    KC_PGUP,    KC_END,     KC_INS,                             R_WH_L,     R_WH_D,     R_WH_U,     R_WH_R,     KC_DEL,
        R_SET_1,    R_SET_2,    R_SET_3,    R_SET_4,    MS_BTN4,                            R_LEFT,     R_DOWN,     R_UP,       R_RIGHT,    KC_TAB,
        R_TL_ACL,   MS_BTN3,    MS_BTN2,    MS_BTN1,    MS_BTN5,                            R_MS_L,     R_MS_D,     R_MS_U,     R_MS_R,     KC_APP,
                    XXXXXXX,    XXXXXXX,                                                                            XXXXXXX,    XXXXXXX,
                                            _______,    _______,    _______,    _______,    MO(3),      _______,
                                            _______,    _______,    _______,    _______,    _______,    _______
    ),

    [2] = LAYOUT(  //   Number and symbols layer
                 //
        NO_LBRC,    NO_LCBR,    NO_LPRN,    NO_SLSH,    NO_LABK,                            NO_RABK,    NO_BSLS,    NO_RPRN,    NO_RCBR,    NO_RBRC,
        KC_1,       KC_2,       KC_3,       KC_4,       KC_5,                               KC_6,       KC_7,       KC_8,       KC_9,       KC_0,
        KC_PERC,    NO_EQL,     NO_ASTR,    NO_PLUS,    NO_HASH,                            NO_AMPR,    NO_MINS,    KC_COMM,    KC_DOT,     NO_UNDS,
                    NO_DLR,     NO_PIPE,                                                                            NO_CIRC,    XXXXXXX,
                                            _______,    MO(3),      _______,    _______,    _______,    _______,
                                            _______,    _______,    _______,    _______,    _______,    _______
    ),

    [3] = LAYOUT(  //   Function layer

        QK_BOOT,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                            KC_MPRV,    KC_VOLD,    KC_VOLU,    KC_MNXT,    KC_MPLY,
        KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,                              KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,
        KC_F11,     KC_F12,     XXXXXXX,    DM_PLY1,    DM_REC1,                            DM_REC2,    DM_PLY2,    XXXXXXX,    XXXXXXX,    XXXXXXX,
                    XXXXXXX,    XXXXXXX,                                                                            XXXXXXX,    XXXXXXX,
                                            _______,    _______,    _______,    _______,    _______,    _______,
                                            _______,    _______,    _______,    _______,    _______,    _______
    )
};

static uint8_t repeat_count = 1;
static bool send_first_key = true;


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint8_t set_r_1_held = 0;
    static uint8_t set_r_2_held = 0;
    static uint8_t set_r_3_held = 0;
    static uint8_t set_r_4_held = 0;

 // Remap GUI directions because GUI+L cannot be remapped in windows
    switch (keycode) {
        case GUI_H:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_GUI) {
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_H);
                }
            } else {
                unregister_code(KC_LEFT);
                unregister_code(KC_H);
            }
            return false;

        case GUI_J:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_GUI) {
                    register_code(KC_DOWN);
                } else {
                    register_code(KC_J);
                }
            } else {
                unregister_code(KC_DOWN);
                unregister_code(KC_J);
            }
            return false;

        case GUI_K:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_GUI) {
                    register_code(KC_UP);
                } else {
                    register_code(KC_K);
                }
            } else {
                unregister_code(KC_UP);
                unregister_code(KC_K);
            }
            return false;

        case GUI_L:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_GUI) {
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_L);
                }
            } else {
                unregister_code(KC_RIGHT);
                unregister_code(KC_L);
            }
            return false;

        // Functons that allows for repeating mouse keys
       case R_WH_L:
            if (record->event.pressed) {
                for (uint8_t i = 0; i < repeat_count; i++) {
                    tap_code(MS_WHLL);
                }
            }
            break;

       case R_WH_D:
            if (record->event.pressed) {
                for (uint8_t i = 0; i < repeat_count; i++) {
                    tap_code(MS_WHLD);
                }
            }
            break;

       case R_WH_U:
            if (record->event.pressed) {
                for (uint8_t i = 0; i < repeat_count; i++) {
                    tap_code(MS_WHLU);
                }
            }
            break;

       case R_WH_R:
            if (record->event.pressed) {
                for (uint8_t i = 0; i < repeat_count; i++) {
                    tap_code(MS_WHLR);
                }
            }
            break;


         case R_LEFT:
            if (record->event.pressed) {
                if (repeat_count == 1) {
                    register_code(KC_LEFT);
                } else {
                    for (uint8_t i = 0; i < repeat_count; i++) {
                        tap_code(KC_LEFT);
                        wait_ms(10);
                    }
                }
            } else {
                unregister_code(KC_LEFT);
            }
            break;

       case R_DOWN:
            if (record->event.pressed) {
                if (repeat_count == 1) {
                    register_code(KC_DOWN);
                } else {
                    for (uint8_t i = 0; i < repeat_count; i++) {
                        tap_code(KC_DOWN);
                        wait_ms(10);
                    }
                }
            } else {
                unregister_code(KC_DOWN);
            }
            break;

       case R_UP:
            if (record->event.pressed) {
                if (repeat_count == 1) {
                    register_code(KC_UP);
                } else {
                    for (uint8_t i = 0; i < repeat_count; i++) {
                        tap_code(KC_UP);
                        wait_ms(10);
                    }
                }
            } else {
                unregister_code(KC_UP);
            }
            break;

       case R_RIGHT:
            if (record->event.pressed) {
                if (repeat_count == 1) {
                    register_code(KC_RIGHT);
                } else {
                    for (uint8_t i = 0; i < repeat_count; i++) {
                        tap_code(KC_RIGHT);
                        wait_ms(10);
                    }
                }
            } else {
                unregister_code(KC_RIGHT);
            }
            break;

       case R_MS_L:
            if (record->event.pressed) {
                for (uint8_t i = 0; i < repeat_count; i++) {
                    tap_code(MS_LEFT);
                }
            }
            break;

       case R_MS_D:
            if (record->event.pressed) {
                for (uint8_t i = 0; i < repeat_count; i++) {
                    tap_code(MS_DOWN);
                }
            }
            break;

       case R_MS_U:
            if (record->event.pressed) {
                for (uint8_t i = 0; i < repeat_count; i++) {
                    tap_code(MS_UP);
                }
            }
            break;

       case R_MS_R:
            if (record->event.pressed) {
                for (uint8_t i = 0; i < repeat_count; i++) {
                    tap_code(MS_RGHT);
                }
            }
            break;

        case R_SET_1:
            if (record->event.pressed) {
                set_r_1_held = 40;
            } else {
                set_r_1_held = 0;
            }
            break;

        case R_SET_2:
            if (record->event.pressed) {
                set_r_2_held = 20;
            } else {
                set_r_2_held = 0;
            }
            break;

        case R_SET_3:
            if (record->event.pressed) {
                set_r_3_held = 10;
            } else {
                set_r_3_held = 0;
            }
            break;

        case R_SET_4:
            if (record->event.pressed) {
                set_r_4_held = 5;
            } else {
                set_r_4_held = 0;
            }
            break;

        case R_TL_ACL: // Toggle mouse precision
            if (record->event.pressed) {
                if (send_first_key) {
                    tap_code(MS_ACL0);
                } else {
                    tap_code(MS_ACL1);
                }
                send_first_key = !send_first_key;  // Toggle the state
            }
            return false;
    }
    repeat_count = set_r_1_held+set_r_2_held+set_r_3_held+set_r_4_held;
    if (repeat_count == 0) {
        repeat_count = 1;
    }

    return true;
}

