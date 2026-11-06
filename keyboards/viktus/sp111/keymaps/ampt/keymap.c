/* Copyright 2020 blindassassin111
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN,
    _RST
};

/*
    KC_ESC,  KC_BSPC, KC_DEL,  KC_MNXT,      KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_MPLY, KC_VOLU, KC_VOLD,
    KC_NUM, KC_PSLS, KC_PAST, KC_PMNS,      KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_NO, KC_BSPC, KC_PGUP, KC_HOME,
    KC_P7,   KC_P8,  KC_P9,    KC_PPLS,      KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_PGDN, KC_END,
    KC_P4,   KC_P5,  KC_P6,    KC_NO,        KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_NO, KC_ENT, MO(1), KC_DEL,
    KC_P1,   KC_P2,  KC_P3,    KC_PENT,      KC_LSFT, KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_NO, KC_UP,
    KC_P0,   KC_P0,  KC_PDOT,  KC_NO,        KC_LCTL, KC_LGUI, KC_LALT, KC_NO, KC_SPC, KC_SPC, MO(1), KC_RALT, KC_RGUI, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
*/

#define MV_LFT LCTL(LALT(KC_2))
#define MV_RT LCTL(LALT(KC_1))
#define SH_MC LCTL(LALT(KC_3))
#define RS_ESC LT(_RST, KC_ESC)
// Superwhisper Toggle Recording; Hyper+F19 so no other app claims it
#define SW_TOG HYPR(KC_F19)
// Superwhisper Push to Talk; Hyper+F18 for the same reason
#define SW_PTT HYPR(KC_F18)
// Tap toggles recording, hold is push-to-talk; LT(0, ...) only supplies tap-hold detection
#define SW_KEY LT(0, KC_F19)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_all(
    RS_ESC,  KC_BSPC, KC_DEL,  KC_MNXT,      KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,           KC_MPLY, KC_SCRL, KC_PAUS,
    KC_NUM, KC_PSLS, KC_PAST, KC_PMNS,      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_NO,   KC_BSPC, KC_PGUP, KC_HOME,
    KC_P7,   KC_P8,   KC_P9,   KC_NO,        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGDN, KC_END,
    KC_P4,   KC_P5,   KC_P6,   KC_PPLS,      MO(_FN), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NO,   KC_ENT,           MO(_FN), KC_DEL,
    KC_P1,   KC_P2,   KC_P3,   KC_PENT,      KC_LSFT, KC_NO,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, MO(_FN),          KC_UP,
    SW_KEY,  KC_P0,   KC_PDOT, KC_NO,        KC_LCTL, KC_LGUI, KC_LALT, KC_NO,   KC_SPC,           KC_SPC,  MO(_RST), KC_RALT, KC_RGUI, KC_RCTL,                           KC_LEFT, KC_DOWN, KC_RIGHT),

    [_FN] = LAYOUT_all(
    _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
    _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______,      _______, MV_LFT,  SH_MC,   MV_RT,   _______, _______, _______, _______, KC_UP,   _______, _______, _______, _______, _______,          _______, _______,
    _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT,_______, _______, _______, _______,          _______, _______,
    _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    _______, _______, _______, _______,      _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______,                            _______, _______, _______),

    [_RST] = LAYOUT_all(
    _______, _______, _______, QK_BOOT,        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          QK_BOOT,   _______, _______,
    _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
    _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
    _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    _______, _______, _______, _______,      _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______,                            _______, _______, _______),
};

// Caps Lock LED doubles as a layer indicator: on whenever a non-base layer is active.
static void update_indicators(led_t led_state, layer_state_t layers) {
    led_state.caps_lock |= get_highest_layer(layers) != _BASE;
    led_update_ports(led_state);
}

bool led_update_user(led_t led_state) {
    update_indicators(led_state, layer_state);
    return false;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    update_indicators(host_keyboard_led_state(), state);
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SW_KEY:
            if (record->tap.count) {
                if (record->event.pressed) {
                    tap_code16(SW_TOG);
                }
            } else if (record->event.pressed) {
                register_code16(SW_PTT);
            } else {
                unregister_code16(SW_PTT);
            }
            return false;
    }
    return true;
}
