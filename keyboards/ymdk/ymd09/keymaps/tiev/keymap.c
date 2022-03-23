#include QMK_KEYBOARD_H

enum custom_keycodes {
  TALKIE = SAFE_RANGE,
};

enum layer_names {
  _GENERAL,
  _NUMPAD,
  _NUMPAD_X,
  _ETS,
  _ETS_X,
  _RGB,
  _LAYERS,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case TALKIE:
      // SEND_STRING(SS_TAP(X_F20)); // Ubuntu
      SEND_STRING(SS_LGUI(SS_LSFT("a"))); // Windows
      return false;
    default:
      return true;
  };
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // General keys
  [_GENERAL] = LAYOUT(TALKIE, LSG(KC_A), LSG(KC_O),
               KC_AUDIO_MUTE, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP,
               LT(_LAYERS, KC_MEDIA_PLAY_PAUSE), KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK),

  // Numpad keys
  [_NUMPAD] = LAYOUT(KC_KP_7, KC_KP_8, KC_KP_9,
               KC_KP_4, KC_KP_5, KC_KP_6,
               LT(_LAYERS, KC_KP_1), KC_KP_2, LT(2, KC_KP_3)),

  // Numpad extra
  [_NUMPAD_X] =  LAYOUT(KC_KP_PLUS, KC_KP_MINUS, KC_KP_ENTER,
                KC_KP_ASTERISK, KC_KP_SLASH, KC_NUMLOCK,
                KC_KP_0, KC_KP_DOT, KC_TRNS),

  // Euro Truck Simulator 2
  [_ETS] = LAYOUT(KC_1, KC_2, KC_3,
               KC_TRNS, KC_TRNS, KC_TRNS,
               LT(_LAYERS, KC_ESC), KC_M, LT(4, KC_L)),

  // More ETS 2 keys
  [_ETS_X] = LAYOUT(KC_F5, KC_F6, KC_F7,
               KC_F1, KC_F8, KC_F9,
               KC_TRNS, KC_TRNS, KC_TRNS),

  // RGB Layer
  [_RGB] = LAYOUT(RGB_RMOD, RGB_VAI, RGB_MOD,
               RGB_HUI, RGB_VAD, RGB_SAI,
               LT(_LAYERS, RGB_HUD), KC_TRNS, RGB_SAD),
  
  // Default layer switches
  [_LAYERS] = LAYOUT(DF(_GENERAL), DF(_NUMPAD), DF(_ETS),
               KC_TRNS, KC_TRNS, KC_TRNS,
               KC_TRNS, DF(_RGB), KC_TRNS),

};
