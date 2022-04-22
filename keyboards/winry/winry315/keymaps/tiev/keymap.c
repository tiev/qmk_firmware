// Copyright 2022 Sergey Vlasov (@sigprof)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_keycodes {
    TALKIE = SAFE_RANGE,
};

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _NUMPAD,
    _ETS,
    _RGB,
    _LAYERS,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT_right(
        KC_ESC,  KC_BSPC,  KC_PENT,   KC_MPLY,
        KC_P7,   KC_P8,    KC_P9,          
        KC_P4,   KC_P5,    KC_P6,     KC_MUTE,
        KC_P1,   KC_P2,    KC_P3,          
        MO(_LAYERS), LSG(KC_A), TALKIE, KC_HOME
    ),

    /* Numpad */
    [_NUMPAD] = LAYOUT_right(
        KC_PSLS,   KC_PAST,   KC_PMNS,   KC_NUMLOCK,
        KC_KP_7,   KC_KP_8,   KC_KP_9,
        KC_KP_4,   KC_KP_5,   KC_KP_6,   KC_ESC,
        KC_KP_1,   KC_KP_2,   KC_KP_3,
        LT(_LAYERS, KC_KP_0), KC_PDOT, KC_PPLS, KC_KP_ENTER
    ),

    /* Euro Truck Simulator 2 */
    [_ETS] = LAYOUT_right(
        KC_ESC,   KC_ENTER,   KC_M,        KC_F8,
        KC_F5,    KC_F6,      KC_F7,
        KC_L,     KC_P,       KC_F1,       KC_F9,
        KC_E,     KC_SPACE,   KC_SCRL,
        LT(_LAYERS, KC_1),  KC_2,  KC_3,   KC_F2
    ),

    /* RGB configuration */
    [_RGB] = LAYOUT_right(
        KC_TRNS, RGB_SPD, RGB_SPI, RGB_M_R,
        RGB_TOG, RGB_HUD, RGB_HUI,        
        RGB_M_P, RGB_SAD, RGB_SAI, RGB_M_B,
        KC_NO,   RGB_VAD, RGB_VAI,        
        LT(_LAYERS, KC_NLCK), RGB_RMOD, RGB_MOD, RGB_M_P
    ),

    /* Layers */
    [_LAYERS] = LAYOUT_right(
        KC_TRNS, KC_TRNS, DF(_RGB), KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        DF(_BASE), DF(_NUMPAD), DF(_ETS),
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case TALKIE:
      SEND_STRING(SS_LGUI(SS_LSFT("a"))); // Windows with PowerToys installed
      return false;
    default:
      return true;
  };
};

// clang-format on

bool encoder_update_user(uint8_t index, bool clockwise) {
    uint8_t layer = get_highest_layer(layer_state | default_layer_state);

    switch (index) {
        case 0:
            // Top encoder (right in the default orientation)
            if (layer == _RGB) {
                if (clockwise) {
                    rgblight_increase_val();
                } else {
                    rgblight_decrease_val();
                }
            } else {
                tap_code_delay(clockwise ? KC_MNXT : KC_MPRV, 10);
            }
            break;

        case 1:
            // Center encoder
            if (layer == _RGB) {
                if (clockwise) {
                    rgblight_increase_sat();
                } else {
                    rgblight_decrease_sat();
                }
            } else {
                tap_code_delay(clockwise ? KC_VOLU : KC_VOLD, 10);
            }
            break;

        case 2:
            // Bottom encoder (left in the default orientation)
            if (layer == _RGB) {
                if (clockwise) {
                    rgblight_increase_hue();
                } else {
                    rgblight_decrease_hue();
                }
            } else if (layer == _ETS) {
                if (clockwise) {
                    tap_code_delay(KC_PAST, 5);
                } else {
                    tap_code_delay(KC_PSLS, 5);
                }
            } else {
                tap_code(clockwise ? KC_PGDN : KC_PGUP);
            }
            break;
    }
    return false;
}
