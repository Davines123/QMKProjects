#include QMK_KEYBOARD_H

// Enums defined:
enum {
    SUPER_F4,
    GUI_FILE,
    SFT_CAPS,
    ABOVE_SUS,
    ALT_TAP,
    PRINT_DEL
   
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,  KC_EQL,  KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,   KC_BSPC, 
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,  KC_LBRC,  KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,     KC_QUOT, KC_BSLS,
    KC_LCTL,   KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_RBRC,    KC_H,    KC_N,    KC_E,    KC_I, KC_O,                   KC_ENT,
    TD(SFT_CAPS), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_SLSH, KC_K,    KC_M,    KC_COMM, KC_DOT,            TD(SFT_CAPS),
    					TD(GUI_FILE), TD(ALT_TAP), LT(1,KC_SPC),          KC_GRV,           TD(ABOVE_SUS)        
  ),
  [1] = LAYOUT(
    RESET,     KC_F1,   KC_F2,   KC_F3,   TD(SUPER_F4),   KC_F5,   KC_F6, KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,    TD(PRINT_DEL), 
    KC_TRNS, KC_TRNS,    KC_UP,     KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,  G(C(KC_D)),  KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS,   KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, G(C(KC_LEFT)),    G(C(KC_F4)),    G(C(KC_RGHT)),          G(KC_TAB),
    KC_TRNS, KC_TRNS,    C(KC_X),    C(KC_C),    C(KC_V),    KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,          KC_TRNS,
    		         KC_HOME, KC_PGUP, KC_TRNS,          KC_PGDN,          KC_END
  )
};

// SUPER_F4 TAP DANCE
void dance_sf4_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code16(KC_F4);
    } else {
        register_code(KC_LALT);
        register_code(KC_F4);
    }
}
void dance_sf4_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code16(KC_F4);
    } else {
        unregister_code(KC_LALT);
        unregister_code(KC_F4);
    }
}

// GUI_FILE TAP DANCE
void dance_gfile_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code16(KC_LGUI);
    } else {
        register_code(KC_LGUI);
        register_code(KC_E);
    }
}
void dance_gfile_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code16(KC_LGUI);
    } else {
        unregister_code(KC_LGUI);
        unregister_code(KC_E);
    }
}

// SFT_CAPS TAP DANCE
void dance_scaps_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code16(KC_LSFT);
    } else {
        register_code(KC_CAPS);
    }
}
void dance_scaps_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code16(KC_LSFT);
    } else {
        unregister_code(KC_CAPS);
    }
     clear_mods();
}

// ABOVE_SUS TAP DANCE
void dance_asus_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(KC_LGUI);
        register_code(KC_D);
    } else {
        register_code(KC_LGUI);
        register_code(KC_L);
    }
}
void dance_asus_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code16(KC_LGUI);
        unregister_code16(KC_D);
    } else {
        unregister_code16(KC_LGUI);
        unregister_code16(KC_L);
    }
}

// ALT_TAP TAP DANCE
void dance_altab_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code16(KC_LALT);
    } else {
        register_code(KC_LALT);
        register_code(KC_TAB);
        unregister_code(KC_TAB);
    }
}
void dance_altab_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code16(KC_LALT);
    } else {
        unregister_code16(KC_LALT);
    }
    clear_mods();
}

// PRINT_DEL TAP DANCE
void dance_printdel_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code16(KC_PSCR);
    } else {
        register_code(KC_DEL);
    }
}
void dance_printdel_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code16(KC_PSCR);
    } else {
        unregister_code(KC_DEL);
    }
}

// All tap dance functions go here.
qk_tap_dance_action_t tap_dance_actions[] = {
    [SUPER_F4] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, dance_sf4_finished, dance_sf4_reset, 250),
    [GUI_FILE] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, dance_gfile_finished, dance_gfile_reset, 200),
    [SFT_CAPS] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, dance_scaps_finished, dance_scaps_reset, 15),
    [ABOVE_SUS] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, dance_asus_finished, dance_asus_reset, 200),
    [ALT_TAP] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, dance_altab_finished, dance_altab_reset, 200),
    [PRINT_DEL] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, dance_printdel_finished, dance_printdel_reset, 200),
};
