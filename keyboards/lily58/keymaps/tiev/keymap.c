#include QMK_KEYBOARD_H
#include <stdio.h>

enum layer_number {
  _DVORAK = 0,
  _WORKMAN,
  _LOWER,
  _RAISE,
};

enum custom_keycodes {
  DVORAK = SAFE_RANGE,
  TGLAYOUT,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* DVORAK
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  \   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   '  |   ,  |   .  |   P  |   Y  |                    |   F  |   G  |   C  |   R  |   L  |  /   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   A  |   O  |   E  |   U  |   I  |-------.    ,-------|   D  |   H  |   T  |   N  |   S  |  -   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   ;  |   Q  |   J  |   K  |   X  |-------|    |-------|   B  |   M  |   W  |   V  |   Z  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |LCTRL | LAlt |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_DVORAK] = LAYOUT( \
  KC_BSLS, KC_1,    KC_2,    KC_3,   KC_4, KC_5,                   KC_6, KC_7,   KC_8,   KC_9, KC_0, KC_EQL,  \
  KC_TAB,  KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y,                   KC_F, KC_G,   KC_C,   KC_R, KC_L, KC_SLSH, \
  KC_ESC,  KC_A,    KC_O,    KC_E,   KC_U, KC_I,                   KC_D, KC_H,   KC_T,   KC_N, KC_S, KC_MINS, \
  KC_LSFT, KC_SCLN, KC_Q,    KC_J,   KC_K, KC_X, KC_LBRC, KC_RBRC, KC_B, KC_M,   KC_W,   KC_V, KC_Z, KC_RSFT, \
                     KC_LCTRL, KC_LALT, MO(_LOWER), KC_SPC,       KC_ENT, MO(_RAISE), KC_BSPC, KC_LGUI \
),

/* WORKMAN
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  \   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   D  |   R  |   W  |   B  |                    |   J  |   F  |   U  |   P  |   ;  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   A  |   S  |   H  |   T  |   G  |-------.    ,-------|   Y  |   N  |   E  |   O  |   I  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   M  |   C  |   V  |-------|    |-------|   K  |   L  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |LCTRL | LAlt |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_WORKMAN] = LAYOUT( \
  KC_BSLS, KC_1, KC_2, KC_3, KC_4, KC_5,                   KC_6, KC_7, KC_8,    KC_9,   KC_0,    KC_EQL,  \
  KC_TAB,  KC_Q, KC_D, KC_R, KC_W, KC_B,                   KC_J, KC_F, KC_U,    KC_P,   KC_SCLN, KC_MINS, \
  KC_ESC,  KC_A, KC_S, KC_H, KC_T, KC_G,                   KC_Y, KC_N, KC_E,    KC_O,   KC_I,    KC_QUOT, \
  KC_LSFT, KC_Z, KC_X, KC_M, KC_C, KC_V, KC_LBRC, KC_RBRC, KC_K, KC_L, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, \
                KC_LCTRL, KC_LALT, MO(_LOWER), KC_SPC, KC_ENT, MO(_RAISE), KC_BSPC, KC_LGUI \
),

/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   _  |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |   ~  | Menu | Cut  | Copy |Paste | C-j  |-------|    |-------|      |   |  |   +  |   {  |   }  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |LCTRL | LAlt |LOWER | /Space  /       \Enter \  |TGLAYOUT |BackSP| LGUI |
 *                   |      |      |      |/       /         \      \ |         |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT( \
  _______,   _______, _______, _______, _______, _______,                   _______, _______, _______,_______, _______, _______,\
  KC_F1,     KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
  KC_GRV,    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS, \
  S(KC_GRV), KC_APP,  C(KC_X), C(KC_C), KC_PSTE, C(KC_J), _______, _______, XXXXXXX, KC_PIPE, KC_PLUS, KC_LCBR, KC_RCBR, _______, \
                               _______, _______, _______, _______, _______, _______, _______, TGLAYOUT\
),

/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |Sleep |BriDn |BriUp | Prev | |>|| | Next |                    | Mute |VolDn |VolUp |      |      |PwrDn |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   (  |   7  |   8  |   9  |   )  |                    | PScr | Home | PgDn | PgUp | End  |Insert|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |   4  |   5  |   6  |   .  |-------.    ,-------|      | Left | Down |  Up  |Right |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |   0  |   1  |   2  |   3  |   ,  |-------|    |-------|   +  |   -  |   *  |   /  |   =  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |LCTRL | LAlt |LOWER | /Space  /       \Enter \  |RAISE |Delete| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_RAISE] = LAYOUT( \
  KC_SLEP, KC_BRID, KC_BRIU, KC_MPRV, KC_MPLY, KC_MNXT,                   KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX, KC_PWR, \
  _______, KC_LPRN, KC_7,    KC_8,    KC_9,    KC_RPRN,                   KC_PSCR, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS,
  _______, XXXXXXX, KC_4,    KC_5,    KC_6,    KC_DOT,                    XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, \
  _______, KC_0,    KC_1,    KC_2,    KC_3,    KC_COMM, _______, _______, KC_PLUS, KC_MINS, KC_PAST, KC_SLSH, KC_EQL, _______, \
                             _______, _______, _______, _______, _______, _______, KC_DEL,  _______ \
)
};

/* layer_state_t layer_state_set_user(layer_state_t state) { */
/*   return update_tri_layer_state(state, _LOWER, _RAISE, _WORKMAN); */
/* } */

// Custom layer state names
#define LAYR_DVORAK 0
#define LAYR_WORKMAN (1 << 1)
#define LAYR_DLOWER (1 << 2)
#define LAYR_DRAISE (1 << 3)
#define LAYR_WLOWER (1 << 2) + 2
#define LAYR_WRAISE (1 << 3) + 2

char layer_state_str[24];

const char *read_layer_state(void) {
  switch (layer_state) {
    case LAYR_DVORAK:
      snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Dvorak");
      break;
    case LAYR_WORKMAN:
      snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Workman");
      break;
    case LAYR_DLOWER:
    case LAYR_WLOWER:
      snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Lower");
      break;
    case LAYR_DRAISE:
    case LAYR_WRAISE:
      snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Raise");
      break;
    default:
      snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%ld", layer_state);
  }

  return layer_state_str;
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
/* const char *read_layer_state(void); */
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }

  switch (keycode) {
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
        layer_off(_WORKMAN);
      }
      return false;
      break;
    case TGLAYOUT:
      if (record->event.pressed) {
        layer_invert(_WORKMAN);
      }
      return false;
      break;
  }
  return true;
}
