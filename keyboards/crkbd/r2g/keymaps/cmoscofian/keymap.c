/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H
#include "macros.h"

#define WIN_A    MT(MOD_LGUI, KC_A)
#define SFT_S    MT(MOD_LSFT, KC_S)
#define ALT_D    MT(MOD_LALT, KC_D)
#define CTL_F    MT(MOD_LCTL, KC_F)

#define WIN_SC   MT(MOD_RGUI, KC_SCLN)
#define SFT_L    MT(MOD_RSFT, KC_L)
#define ALT_K    MT(MOD_LALT, KC_K)
#define CTL_J    MT(MOD_RCTL, KC_J)

enum custom_keycodes {
    X_MCR_1 = SAFE_RANGE,
    X_MCR_2
};

enum layers {
    BASE,
    NUM,
    SYM,
    ALT,
    SIZE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case X_MCR_1:
            if (record->event.pressed) {
            } else {
                SEND_STRING(MCR_1);
            }
            break;
        case X_MCR_2:
            if (record->event.pressed) {
            } else {
                SEND_STRING(MCR_2);
            }
            break;
    }
    return true;
}

const uint16_t PROGMEM keymaps[SIZE][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_split_3x6_3(
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_TAB,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_MINS,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_ESC,     KC_A,   SFT_S,   ALT_D,   CTL_F,    KC_G,                         KC_H,   CTL_J,   ALT_K,   SFT_L,  WIN_SC, KC_QUOT,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------|--------+--------+--------+--------+--------+--------|
                                            MO(SYM), KC_BSPC,  KC_DEL,     KC_ENT,  KC_SPC, MO(NUM)
                                        //|--------+--------+--------|  |--------+--------+--------|
    ),
    [NUM] = LAYOUT_split_3x6_3(
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,    KC_F6,                        KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------|--------+--------+--------+--------+--------+--------|
                                            MO(ALT), _______, _______,    _______, _______, _______
                                        //|--------+--------+--------|  |--------+--------+--------|
    ),
    [SYM] = LAYOUT_split_3x6_3(
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, KC_QUOT, KC_LABK, KC_RABK, KC_DQUO,  KC_DOT,                      KC_AMPR, KC_AMPR, KC_LPRN, KC_RPRN, KC_PERC, _______,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, KC_EXLM, KC_MINS, KC_PLUS,  KC_EQL, KC_HASH,                      KC_PIPE, KC_COLN, KC_LCBR, KC_RCBR, KC_QUES, _______,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, KC_CIRC, KC_SLSH, KC_ASTR, KC_BSLS, KC_UNDS,                      KC_TILD,  KC_DLR, KC_LBRC, KC_RBRC,   KC_AT, _______,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------|--------+--------+--------+--------+--------+--------|
                                            _______, _______, _______,    _______, _______, MO(ALT)
                                        //|--------+--------+--------|  |--------+--------+--------|
    ),
    [ALT] = LAYOUT_split_3x6_3(
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, X_MCR_1, XXXXXXX,                      XXXXXXX, X_MCR_2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------|--------+--------+--------+--------+--------+--------|
                                            _______, _______, _______,    _______, _______, _______
                                        //|--------+--------+--------|  |--------+--------+--------|
    )
};
