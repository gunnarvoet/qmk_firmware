/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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
#include <stdio.h>

#define _COLEMAK 0
#define _NAVIGATE 1
#define _SYMR 2
#define _SYML 3
#define _NUM 4
#define _SPECIAL 5
#define _FUN 6
#define _SETTINGS 7


// Tap Dance declarations
enum {
    TD_OS_CAPS,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Shift, twice for Caps Lock
    [TD_OS_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, KC_CAPS),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* [0] = LAYOUT_split_3x6_3( */
  /* //,-----------------------------------------------------.                    ,-----------------------------------------------------. */
  /*      KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC, */
  /* //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------| */
  /*     KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT, */
  /* //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------| */
  /*     KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC, */
  /* //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------| */
  /*                                         KC_LGUI,   MO(1),  KC_SPC,     KC_ENT,   MO(2), KC_RALT */
  /*                                     //`--------------------------'  `--------------------------' */

  /* ), */
	[_COLEMAK] = LAYOUT_split_3x6_3(
        KC_TAB, KC_Q, KC_W, LCTL_T(KC_F), MT(MOD_LCTL | MOD_LGUI, KC_P), KC_G,
        KC_J, MT(MOD_LCTL | MOD_LGUI, KC_L), LCTL_T(KC_U), KC_Y, KC_SCLN, KC_BSPC,

        LCTL_T(KC_ESC), LSFT_T(KC_A), LGUI_T(KC_R), LT(1,KC_S), LT(2,KC_T), KC_D,
        KC_H, LT(3,KC_N), LT(5,KC_E), LGUI_T(KC_I), LSFT_T(KC_O), KC_QUOT,

        MO(7), KC_Z, LALT_T(KC_X), LCTL_T(KC_C), LT(6, KC_V), KC_B,
        KC_K, KC_M, LCTL_T(KC_COMM), LALT_T(KC_DOT), KC_SLSH, RSFT_T(KC_ENT),

        /* LT(9,KC_NO), KC_NO, KC_NO, KC_LGUI, LT(10,KC_ENT), KC_BSPC, */
        /* LCTL(KC_SCLN), LT(8,KC_SPC), TD(TD_OS_CAPS), KC_NO, KC_NO, KC_LGUI */
        KC_LGUI, LT(4,KC_ENT), KC_BSPC,
        LCTL(KC_SCLN), LT(5,KC_SPC), TD(TD_OS_CAPS)
        ),
  /* [_COLEMAK] = LAYOUT_split_3x6_3( */
  /*       KC_TAB, KC_Q, LGUI_T(KC_W), LCTL_T(KC_F), MT(MOD_LCTL | MOD_LGUI, KC_P), KC_G, */
  /*       KC_J, KC_L, LCTL_T(KC_U), LGUI_T(KC_Y), KC_SCLN, KC_BSPC, */

  /*       LCTL_T(KC_ESC), LSFT_T(KC_A), LT(6,KC_R), LT(1,KC_S), LT(2,KC_T), KC_D, */
  /*       KC_H, LT(5,KC_N), LT(2,KC_E), LT(7,KC_I), LSFT_T(KC_O), KC_QUOT, */

  /*       MO(7), KC_Z, LALT_T(KC_X), LCTL_T(KC_C), KC_V, KC_B, */
  /*       KC_K, KC_M, LCTL_T(KC_COMM), LALT_T(KC_DOT), KC_SLSH, RSFT_T(KC_ENT), */

  /*       KC_LGUI, LT(4,KC_ENT), KC_BSPC, */
  /*       LCTL(KC_SCLN), LT(5,KC_SPC), TD(TD_OS_CAPS) */
  /*       ), */

	[_NAVIGATE] = LAYOUT_split_3x6_3(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_PGUP, KC_HOME, KC_TRNS, KC_TRNS, KC_TRNS,

        KC_TRNS, KC_LSFT, KC_LCTL, KC_NO, KC_LGUI, KC_TRNS,
        KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_TRNS, KC_TRNS,

        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_PGDN, KC_END, KC_TRNS, KC_TRNS, KC_TRNS,
        
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

  [_SYMR] = LAYOUT_split_3x6_3(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_PIPE, KC_UNDS, KC_PLUS, KC_DQUO, KC_EQL, KC_TRNS,

        KC_TRNS, KC_CIRC, KC_ASTR, KC_AMPR, KC_NO, KC_TRNS,
        KC_HASH, KC_MINS, KC_SLSH, KC_QUOT, KC_DLR, KC_TRNS,
        
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TILD, KC_BSLS, KC_GRV, KC_TRNS, KC_TRNS,

        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
        ),

	[_SYML] =  LAYOUT_split_3x6_3(
        KC_TRNS, KC_TRNS, KC_COLN, KC_LT, KC_GT, KC_SCLN,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

        KC_TRNS, KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_AT,
        KC_TRNS, KC_NO, KC_EQL, KC_PLUS, KC_PERC, KC_TRNS,

        KC_TRNS, KC_TRNS, KC_EXLM, KC_LBRC, KC_RBRC, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	[_NUM] = LAYOUT_split_3x6_3(
        KC_TRNS, LCTL(KC_1), LCTL(KC_2), LCTL(KC_3), LCTL(KC_4), LCTL(KC_5),
        LCTL(KC_6), LCTL(KC_7), LCTL(KC_8), LCTL(KC_9), KC_TRNS, KC_TRNS,

        KC_TRNS, KC_1, KC_2, KC_3, KC_4, KC_5,
        KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRNS,

        KC_TRNS, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,
        KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TRNS,

        KC_TRNS, KC_NO,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
        ),

    [_FUN] =  LAYOUT_split_3x6_3(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_F7, KC_F8, KC_F9, KC_F10, KC_TRNS,

        KC_TRNS, KC_TRNS, KC_NO, KC_LCTL, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_F4, KC_F5, KC_F6, KC_F11, KC_TRNS,

        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F12, KC_TRNS,

        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
        ),

	[_SPECIAL] = LAYOUT_split_3x6_3(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_COLN, KC_ESC, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL, KC_BSPC,

        KC_TRNS, LCTL(KC_B), KC_PERC, KC_SLSH, KC_ENT, KC_TRNS,
        KC_TRNS, KC_LGUI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_EXLM, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

        KC_TRNS, KC_TAB, KC_TRNS, KC_TRNS, KC_NO, KC_TRNS
        ),


	[_SETTINGS] = LAYOUT_split_3x6_3(
        RESET, DEBUG, KC_NO, KC_NO, RGB_TOG, RGB_HUD,
        RGB_HUI, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, RGB_MOD,

        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_VOLD, KC_VOLU, KC_NO, KC_NO, KC_NO,

        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_BRID, KC_BRIU, KC_NO, KC_NO, KC_NO,

        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO)


  /* [1] = LAYOUT_split_3x6_3( */
  /* //,-----------------------------------------------------.                    ,-----------------------------------------------------. */
  /*      KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC, */
  /* //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------| */
  /*     KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, XXXXXXX, */
  /* //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------| */
  /*     KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, */
  /* //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------| */
  /*                                         KC_LGUI, _______,  KC_SPC,     KC_ENT,   MO(3), KC_RALT */
  /*                                     //`--------------------------'  `--------------------------' */
  /* ), */

  /* [2] = LAYOUT_split_3x6_3( */
  /* //,-----------------------------------------------------.                    ,-----------------------------------------------------. */
  /*      KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, */
  /* //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------| */
  /*     KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV, */
  /* //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------| */
  /*     KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD, */
  /* //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------| */
  /*                                         KC_LGUI,   MO(3),  KC_SPC,     KC_ENT, _______, KC_RALT */
  /*                                     //`--------------------------'  `--------------------------' */
  /* ), */

  /* [3] = LAYOUT_split_3x6_3( */
  /* //,-----------------------------------------------------.                    ,-----------------------------------------------------. */
  /*       RESET, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, */
  /* //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------| */
  /*     RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, */
  /* //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------| */
  /*     RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, */
  /* //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------| */
  /*                                         KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT */
  /*                                     //`--------------------------'  `--------------------------' */
  /* ) */
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case _COLEMAK:
            oled_write_ln_P(PSTR("default"), false);
            break;
        case _SYMR:
            oled_write_ln_P(PSTR("symbol right"), false);
            break;
        case _SYML:
            oled_write_ln_P(PSTR("symbol left"), false);
            break;
        /* case L_ADJUST: */
        /* case L_ADJUST|L_LOWER: */
        /* case L_ADJUST|L_RAISE: */
        /* case L_ADJUST|L_LOWER|L_RAISE: */
        /*     oled_write_ln_P(PSTR("Adjust"), false); */
        /*     break; */
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_ENABLE
