#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

#define _QW 0
#define _L1 1
#define _L2 2
#define _L3 3

// Curly braces have their own keys. These are defined to make them not mess up
// the grid in layer 2.
#define L_CURBR LSFT(KC_LBRC)
#define R_CURBR LSFT(KC_RBRC)


// Some special definitions for brevity.
#define L1_SPC  LT(_L1, KC_SPC)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QW] = LAYOUT_arrow( /* Qwerty */
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
    LSFT_T(KC_ESC),  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_SLSH,
    KC_LCTL, KC_LALT, KC_LGUI,          L1_SPC,  KC_SPC,                    MO(_L2), KC_LEFT, KC_DOWN, KC_RGHT
  ),
  [_L1] = LAYOUT_arrow( /* LAYER 1 */
    KC_ESC,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
    _______, KC_BSL xS, KC_QUOT, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_DOWN, KC_UP,   KC_LEFT, KC_RGHT, _______,
    _______, KC_ESC,  RGB_TOG, KC_PSCR, _______, _______, _______, _______, _______, KC_MPLY, KC_VOLU, _______,
    _______, KC_LGUI, _______,                   _______, _______,          _______, KC_MPRV, KC_VOLD, KC_MNXT
  ),
  [_L2] = LAYOUT_arrow( /* LAYER 2 */
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    KC_ESC,  KC_PIPE, KC_DQUO, KC_UNDS, KC_PLUS, L_CURBR, R_CURBR, KC_4,    KC_5,    KC_6,    _______, _______,
    _______, _______, _______, _______, _______, _______, KC_0,    KC_1,    KC_2,    KC_3,    RGB_VAI, _______,
    _______, _______, _______,                   _______, _______,          _______, _______, RGB_VAD, _______
  ),
  [_L3] = LAYOUT_arrow( /* LAYER 3 */
    _______, _______, _______, _______, _______, _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______,
    KC_ESC,  _______, _______, _______, _______, _______, _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______,
    KC_LSFT, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,
    _______, KC_LSFT, KC_B,                      KC_SPC,  KC_C,             _______, _______, _______, _______
  )
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}
