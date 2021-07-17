#include QMK_KEYBOARD_H

enum custom_keycodes {
  TALKIE = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case TALKIE:
      SEND_STRING(SS_TAP(X_F20));
      return false;
    default:
      return true;
  };
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT(TALKIE, _______, KC_AUDIO_VOL_UP,
               _______, _______, KC_AUDIO_VOL_DOWN,
               LT(1, KC_MEDIA_PLAY_PAUSE), LT(2, KC_F13), KC_AUDIO_MUTE),

  [1] = LAYOUT(KC_F20, _______, KC_F14,
               _______, _______, KC_F15,
               KC_TRNS, _______, KC_F16),

  [2] = LAYOUT(RGB_RMOD, RGB_VAI, RGB_MOD,
               RGB_HUI, RGB_VAD, RGB_SAI,
               RGB_HUD, KC_TRNS, RGB_SAD),

};
