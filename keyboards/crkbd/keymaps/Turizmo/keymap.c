/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free softwareLAYOUT_split_3x6_3( you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <httpLAYOUT_split_3x6_3(//www.gnu.org/licenses/>.
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
    [0] = LAYOUT_split_3x6_3_ex2(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, DM_REC1,    DM_REC2,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, NO_ARNG,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_ESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G, DM_PLY1,    DM_PLY2,   GUI_H,   GUI_J,   GUI_K,   GUI_L,    KC_N,   NO_AE,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      NO_OSTR,    KC_M, KC_COMM,  KC_DOT, KC_LALT, KC_RCTL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                              KC_LGUI, LT(1,KC_SPC), LCTL_T(KC_ENT),  KC_LSFT, LT(2,KC_BSPC), KC_LALT
                                      //`--------------------------'  `--------------------------'

  ),

    [1] = LAYOUT_split_3x6_3_ex2(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, KC_HOME, KC_PGDN, KC_PGUP,  KC_END,  KC_APP, KC_PSCR,     NO_GRV,  R_WH_L,  R_WH_D,  R_WH_U,  R_WH_R,  KC_INS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, R_SET_1, R_SET_2, R_SET_3, R_SET_4, MS_BTN4, KC_PAUS,    NO_ACUT,  R_LEFT,  R_DOWN,    R_UP, R_RIGHT,  KC_DEL, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,R_TL_ACL, MS_BTN3, MS_BTN2, MS_BTN1, MS_BTN5,                       R_MS_L,  R_MS_D,  R_MS_U,  R_MS_R,  KC_APP, KC_RCTL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                   KC_LGUI, _______,  LCTL_T(KC_ENT),     KC_LSFT,   MO(3), KC_LALT
                                      //`--------------------------'  `--------------------------'
  ),
        // Symbols and numbers layer
    [2] = LAYOUT_split_3x6_3_ex2(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      NO_SECT, NO_QUOT, NO_DQUO,   NO_AT, NO_LBRC, NO_RBRC, NO_PIPE,    NO_LABK, NO_PLUS,    KC_7,    KC_8,    KC_9, NO_ASTR, NO_CIRC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      NO_HASH, NO_UNDS, NO_EXLM, NO_QUES, NO_LPRN, NO_RPRN, NO_TILD,    NO_RABK,  NO_EQL,    KC_4,    KC_5,    KC_6,    KC_0, NO_PERC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      NO_AMPR, NO_DLR, NO_SCLN, NO_COLN, NO_LCBR, NO_RCBR,                       NO_MINS,    KC_1,    KC_2,    KC_3, NO_SLSH, NO_BSLS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                 KC_LGUI,   MO(3),  LCTL_T(KC_ENT),     KC_LSFT, _______, KC_LALT
                                      //`--------------------------'  `--------------------------'
  ),

    [3] = LAYOUT_split_3x6_3_ex2(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, RGB_MOD, RM_HUEU, RM_SATU, RM_VALU, RGB_SPI, XXXXXXX,   KC_VOLU,  KC_MPRV,   KC_F7,   KC_F8,   KC_F9,  KC_F12, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_LSFT, RGB_RMOD, RM_HUED, RM_SATD, RM_VALD, RGB_SPD, XXXXXXX,   KC_VOLD,  KC_MPLY,   KC_F4,   KC_F5,   KC_F6,  KC_F11, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, KC_LALT, XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX,                       KC_MNXT,   KC_F1,   KC_F2,   KC_F3,  KC_F10, KC_RCTL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                    KC_LGUI, _______,LCTL_T(KC_ENT),     KC_LSFT, _______, KC_LALT
                                      //`--------------------------'  `--------------------------'
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

        case R_TL_ACL:
            if (record->event.pressed) {
                if (send_first_key) {
                    tap_code(MS_ACL0);  // Replace KC_A with the first key you want to send
                } else {
                    tap_code(MS_ACL1); // Replace KC_B with the second key you want to send
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

bool isRecording = false;

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (isRecording)
    for (uint8_t i = led_min; i < led_max; i++) {
         rgb_matrix_set_color(i, RGB_RED);
    }
    return false;
}

bool dynamic_macro_record_start_user(int8_t direction) {
  isRecording = true;
    return true;
}

bool dynamic_macro_record_end_user(int8_t direction) {
  isRecording = false;
    return true;
}

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
};
#endif
