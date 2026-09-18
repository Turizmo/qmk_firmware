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
    LANG_TG, // Toggle between Norwegian and US OS keyboard layout
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(  //   QWERTY layer

        KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,                               KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,
        KC_A,       KC_S,       KC_D,       KC_F,       KC_G,                               GUI_H,      GUI_J,      GUI_K,      GUI_L,      KC_N,
        KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,                               NO_AE,      KC_M,       KC_COMM,    KC_DOT,     NO_QUES,
                    NO_GRV,     NO_TILD,                                                                            NO_OSTR,    NO_ARNG,
                                            KC_SPC,     LT(1,KC_ENT), KC_LCTL,  KC_LALT,    LT(2,KC_ESC),KC_BSPC,
                                            NO_QUOT,    KC_LGUI,    NO_DQUO,    KC_RCTL,    KC_LSFT,    NO_EXLM
    ),

    [1] = LAYOUT(  //   Navigation layer

        KC_HOME,    KC_PGDN,    KC_PGUP,    KC_END,     KC_INS,                             R_WH_L,     R_WH_D,     R_WH_U,     R_WH_R,     KC_DEL,
        R_SET_1,    R_SET_2,    R_SET_3,    R_SET_4,    MS_BTN4,                            R_LEFT,     R_DOWN,     R_UP,       R_RIGHT,    KC_TAB,
        R_TL_ACL,   MS_BTN3,    MS_BTN2,    MS_BTN1,    MS_BTN5,                            R_MS_L,     R_MS_D,     R_MS_U,     R_MS_R,     KC_APP,
                    XXXXXXX,    XXXXXXX,                                                                            KC_PSCR,    KC_PAUSE,
                                            _______,    _______,    _______,    _______,    _______,    _______,
                                            _______,    _______,    _______,    _______,    _______,    _______
    ),

    [2] = LAYOUT(  //   Number and symbols layer
                 //
        NO_LBRC,    NO_LCBR,    NO_LPRN,    NO_SLSH,    NO_LABK,                            NO_RABK,    NO_BSLS,    NO_RPRN,    NO_RCBR,    NO_RBRC,
        KC_1,       KC_2,       KC_3,       KC_4,       KC_5,                               KC_6,       KC_7,       KC_8,       KC_9,       KC_0,
        KC_PERC,    NO_EQL,     NO_ASTR,    NO_PLUS,    NO_HASH,                            NO_AMPR,    NO_MINS,    KC_COMM,    KC_DOT,     NO_UNDS,
                    NO_DLR,     NO_PIPE,                                                                            NO_CIRC,    NO_AT,
                                            _______,    _______,    _______,    _______,    _______,    _______,
                                            _______,    _______,    _______,    _______,    _______,    _______
    ),

    [3] = LAYOUT(  //   Function layer

        QK_BOOT,    XXXXXXX,    XXXXXXX,    XXXXXXX,    LANG_TG,                            KC_MPRV,    KC_VOLD,    KC_VOLU,    KC_MNXT,    KC_MPLY,
        KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,                              KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,
        KC_F11,     KC_F12,     KC_F13,     KC_F14,     KC_F15,                             KC_F16,     KC_F17,     KC_F18,     KC_F19,     KC_F20,
                    DM_REC1,    DM_PLY1,                                                                            DM_PLY2,    DM_REC2,
                                            _______,    _______,    _______,    _______,    _______,    _______,
                                            _______,    _______,    _______,    _______,    _______,    _______
    )
};

// When true the OS is set to a US layout, so symbol keys are translated to US keycodes
static bool us_layout = false;

typedef struct {
    uint16_t no;      // Keycode in the keymap (Norwegian layout)
    uint16_t us;      // US keycode for the same character
    uint16_t us_shft; // US keycode when Shift is held, 0 to keep Shift + us
} lang_map_t;

static const lang_map_t lang_map[] = {
    {KC_COMM, KC_COMM, KC_SCLN},
    {KC_DOT,  KC_DOT,  KC_COLN},
    {KC_1,    KC_1,    KC_EXLM},
    {KC_2,    KC_2,    KC_DQUO},
    {KC_3,    KC_3,    KC_HASH},
    {KC_5,    KC_5,    KC_PERC},
    {KC_6,    KC_6,    KC_AMPR},
    {KC_7,    KC_7,    KC_SLSH},
    {KC_8,    KC_8,    KC_LPRN},
    {KC_9,    KC_9,    KC_RPRN},
    {KC_0,    KC_0,    KC_EQL},
    {NO_QUOT, KC_QUOT, KC_ASTR},
    {NO_PLUS, KC_PLUS, KC_QUES},
    {NO_MINS, KC_MINS, KC_UNDS},
    {NO_LABK, KC_LABK, KC_RABK},
    {NO_BSLS, KC_BSLS, KC_GRV},
    {NO_PIPE, KC_PIPE, 0},
    {NO_GRV,  KC_GRV,  0},
    {NO_TILD, KC_TILD, 0},
    {NO_CIRC, KC_CIRC, 0},
    {NO_QUES, KC_QUES, 0},
    {NO_DQUO, KC_DQUO, 0},
    {NO_EXLM, KC_EXLM, 0},
    {NO_LBRC, KC_LBRC, 0},
    {NO_RBRC, KC_RBRC, 0},
    {NO_LCBR, KC_LCBR, 0},
    {NO_RCBR, KC_RCBR, 0},
    {NO_LPRN, KC_LPRN, 0},
    {NO_RPRN, KC_RPRN, 0},
    {NO_SLSH, KC_SLSH, 0},
    {NO_RABK, KC_RABK, 0},
    {NO_EQL,  KC_EQL,  0},
    {NO_ASTR, KC_ASTR, 0},
    {NO_HASH, KC_HASH, 0},
    {NO_AMPR, KC_AMPR, 0},
    {NO_UNDS, KC_UNDS, 0},
    {NO_DLR,  KC_DLR,  0},
    {NO_AT,   KC_AT,   0},
};

static const lang_map_t *find_lang_map(uint16_t keycode) {
    for (uint8_t i = 0; i < ARRAY_SIZE(lang_map); i++) {
        if (lang_map[i].no == keycode) {
            return &lang_map[i];
        }
    }
    return NULL;
}

// Tap the US version of a Norwegian key
static void send_us_key(const lang_map_t *map) {
    uint8_t  mods = get_mods();
    uint16_t out  = map->us;
    if ((mods & MOD_MASK_SHIFT) && map->us_shft) {
        out = map->us_shft;
        del_mods(MOD_MASK_SHIFT);
    }
    tap_code16(out);
    set_mods(mods);
}

void eeconfig_init_user(void) {
    eeconfig_update_user(0);
}

void keyboard_post_init_user(void) {
    us_layout = eeconfig_read_user() & 1;
}

static uint8_t repeat_count = 1;
static bool send_first_key = true;


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint8_t set_r_1_held = 0;
    static uint8_t set_r_2_held = 0;
    static uint8_t set_r_3_held = 0;
    static uint8_t set_r_4_held = 0;

 // Remap GUI directions because GUI+L cannot be remapped in windows
    if (keycode == LANG_TG) {
        if (record->event.pressed) {
            us_layout = !us_layout;
            eeconfig_update_user(us_layout);
        }
        return false;
    }

    // In US mode translated keys are tapped on press, so skip their release too.
    // Shortcuts such as Ctrl+, are left untouched.
    if (us_layout && !(get_mods() & (MOD_MASK_CTRL | MOD_MASK_ALT | MOD_MASK_GUI))) {
        const lang_map_t *map = find_lang_map(keycode);
        if (map) {
            if (record->event.pressed) {
                send_us_key(map);
            }
            return false;
        }
    }

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


// Layer 3 = layers 1 and 2 held together; releasing either thumb leaves layer 3
layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, 1, 2, 3);
}
