/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
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
#include "bk_pointing_modes.h"
#include "macros.h"

#define SFT_S   MT(MOD_LSFT, KC_S)
#define ALT_D   MT(MOD_LALT, KC_D)
#define CTL_F   MT(MOD_LCTL, KC_F)

#define WIN_SC  MT(MOD_RGUI, KC_SCLN)
#define SFT_L   MT(MOD_RSFT, KC_L)
#define ALT_K   MT(MOD_LALT, KC_K)
#define CTL_J   MT(MOD_RCTL, KC_J)

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
#    include "timer.h"
#endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

enum charybdis_keymap_layers {
	BASE = 0,
	NUM,
	SYM,
	ALT,
	POINTER,
	SIZE,
};

/*
 * Layers used on the Charybdis Nano.
 *
 * These layers started off heavily inspired by the Miryoku layout, but trimmed
 * down and tailored for a stock experience that is meant to be fundation for
 * further personalization.
 *
 * See https://github.com/manna-harbour/miryoku for the original layout.
 */

const uint16_t PROGMEM keymaps[SIZE][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_charybdis_3x5(
    //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
           KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
           KC_A,   SFT_S,   ALT_D,   CTL_F,    KC_G,                         KC_H,   CTL_J,   ALT_K,   SFT_L,  WIN_SC,
    //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
           KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,
    //|--------+--------+--------+--------+--------+--------|  |--------|--------+--------+--------+--------+--------|
                       MO(POINTER), LT(SYM, KC_ESC), KC_BSPC,     KC_ENT,    LT(NUM, KC_SPC)
                               //|--------+--------+--------|  |--------+--------|
    ),
    [NUM] = LAYOUT_charybdis_3x5(
    //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
           KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
        KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
          KC_F1,   KC_F2,   KC_F3,  KC_F4,    KC_F5,                         KC_F6,   KC_F7,   KC_F8,  KC_F9,  KC_F10,
    //|--------+--------+--------+--------+--------+--------|  |--------|--------+--------+--------+--------+--------|
                                   _______, MO(ALT), _______,    _______, _______
                               //|--------+--------+--------|  |--------+--------|
    ),
    [SYM] = LAYOUT_charybdis_3x5(
    //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
         KC_TAB, KC_LABK, KC_RABK, KC_UNDS,  KC_DEL,                      KC_ASTR,  KC_EQL, KC_LPRN, KC_RPRN, KC_QUOT,
    //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
        KC_TILD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_PIPE, KC_PLUS, KC_LCBR, KC_RCBR, KC_DQUO,
    //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_BSLS, KC_MINS, KC_LBRC, KC_RBRC,  KC_GRV,
    //|--------+--------+--------+--------+--------+--------|  |--------|--------+--------+--------+--------+--------|
                                   _______, _______, _______,    _______, MO(ALT)
                               //|--------+--------+--------|  |--------+--------|
    ),
    [ALT] = LAYOUT_charybdis_3x5(
    //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_VOLD, KC_MUTE, KC_MPLY, KC_VOLU,  EE_CLR,
    //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
        KC_MPRV, KC_MPLY, KC_MPLY, KC_MNXT, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX,
    //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
        UG_TOGG, UG_NEXT, UG_PREV, XXXXXXX, XXXXXXX,                      KC_HOME, KC_PGDN, KC_PGUP,  KC_END, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|  |--------|--------+--------+--------+--------+--------|
                                   _______, _______, _______,    _______, _______
                               //|--------+--------+--------|  |--------+--------|
    ),
    [POINTER] = LAYOUT_charybdis_3x5(
    //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
        DRGSCRL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+---------+--------+-------+--------|                    |--------+--------+--------+--------+--------|
        DRGSCRL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, MS_BTN1, MS_BTN3, MS_BTN2, XXXXXXX,
    //|--------+---------+--------+-------+--------|                    |--------+--------+--------+--------+--------|
        DRGSCRL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|  |--------|--------+--------+--------+--------+--------|
                                   _______, _______, _______,    MS_BTN1, MS_BTN2
                               //|--------+--------+--------|  |--------+--------|
    )
};
