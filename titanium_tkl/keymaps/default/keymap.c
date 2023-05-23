
#include QMK_KEYBOARD_H


enum layer_names {
    _BASE,
    _FN,
};

enum custom_keycodes {
  KC_WINLCK = SAFE_RANGE,
  PSTIT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*  Row:        0           1           2           3        4           5        6        7           8           9           10          11          12          13          14          15          16          */
    [_BASE] = { {   KC_ESC,     KC_F1,      KC_F2,      KC_F3,   KC_F4,      KC_F5,   KC_F6,   KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_NO,      KC_PSCR,    KC_SLCK,    KC_PAUSE },
                {   KC_GRV,     KC_1,       KC_2,       KC_3,    KC_4,       KC_5,    KC_6,    KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,     KC_BSPC,    KC_INS,     PSTIT,    KC_PGUP  },
                {   KC_TAB,     KC_Q,       KC_W,       KC_E,    KC_R,       KC_T,    KC_Y,    KC_U,       KC_I,       KC_O,       KC_P,       KC_LBRC,    KC_RBRC,    KC_BSLS,    KC_DEL,     KC_END,     KC_PGDN  },
                {   KC_CAPS,    KC_A,       KC_S,       KC_D,    KC_F,       KC_G,    KC_H,    KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,    KC_NUHS,    KC_ENT,     KC_NO,      KC_NO,      KC_NO    },
                {   KC_LSFT,    KC_NUBS,    KC_Z,       KC_X,    KC_C,       KC_V,    KC_B,    KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_INT1,    KC_RSFT,    KC_NO,      KC_UP,      KC_NO    },
                {   KC_LCTL,    KC_LGUI,    KC_LALT,    KC_NO,   KC_NO,      KC_NO,   KC_SPC,  KC_A,       KC_B,       KC_ALGR,    MO(_FN),    KC_APP,     KC_APP,     KC_RCTL,    KC_LEFT,    KC_DOWN,    KC_RIGHT }
              },
    [_FN]   = { {   RESET,      KC_MSEL,    KC_VOLD,    KC_VOLU, KC_MUTE,    KC_MSTP, KC_MPRV, KC_MPLY,    KC_MNXT,    KC_MAIL,    KC_WHOM,    KC_CALC,    RGB_TOG,    _______,    _______,    _______,    KC_SLEP  },
                {   _______,    _______,    _______,    _______, _______,    _______, _______, _______,    _______,    _______,    _______,    RGB_SPD,    RGB_SPI,    _______,    RGB_MOD,    RGB_M_B,    RGB_M_R  },
                {   _______,    _______,    _______,    _______, _______,    _______, _______, _______,    _______,    _______,    _______,    _______,    _______,    _______,   RGB_M_SW,    RGB_MOD,   RGB_RMOD  },
                {   _______,    _______,    _______,    _______, _______,    _______, _______, _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______  },
                {   _______,    _______,    _______,    _______, _______,    _______, _______, _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    RGB_VAI,    _______  },
                {   _______,    KC_WINLCK,  _______,    _______, _______,    _______, _______, _______,    _______,    _______,    _______,    _______,    _______,    _______,    RGB_HUD,    RGB_VAD,    RGB_HUI  }
             }
};

void rgb_matrix_indicators_user(void) {
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(50, 217, 71, 115);
    }
	if (host_keyboard_led_state().scroll_lock) {
        rgb_matrix_set_color(14, 217, 71, 115);
    }
	if (keymap_config.no_gui){ 
        rgb_matrix_set_color(80, 217, 71, 115); 
 }
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
		case PSTIT:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("v"));
            }
   			break;	
        case KC_WINLCK:
            if (record->event.pressed) {
                keymap_config.no_gui = !keymap_config.no_gui; //toggle status
            }
            break;
	    }
        return true;
}