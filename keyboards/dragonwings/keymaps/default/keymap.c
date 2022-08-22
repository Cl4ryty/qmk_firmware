#include QMK_KEYBOARD_H
#include "keymap_steno.h"


enum dragonwings_layers {
  _STENO,
  _NKRO
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     *                        ┌───┬───┬───┬───┬───┬───┐    ┌───┬───┬───┬───┬───┬───┐
     *            not used -> │ - │ S │ T │ P │ H │ * │    │ * │ F │ P │ L │ T │ D │
     *                        ├───┼───┼───┼───┼───┼───┤    ├───┼───┼───┼───┼───┼───┤
     * toggle qwerty steno -> │TG │ S │ K │ W │ R │ * │    │ * │ R │ B │ G │ S │ Z │
     *                        └───┴───┴───┴───┴───┴───┘    └───┴───┴───┴───┴───┴───┘
     *                                     ┌───┬───┬───┐  ┌───┬───┬───┐
     *                                     │ # │ A │ O │  │ E │ U │ # │
     *                                     └───┴───┴───┘  └───┴───┴───┘
     */
    [_STENO] = LAYOUT_dragonwings_grid(
        KC_NO,       STN_S1,   STN_TL,   STN_PL,   STN_HL,   STN_ST1,               STN_ST3,   STN_FR,   STN_PR,   STN_LR,   STN_TR,   STN_DR,
        TG(_NKRO),   STN_S2,   STN_KL,   STN_WL,   STN_RL,   STN_ST2,               STN_ST4,   STN_RR,   STN_BR,   STN_GR,   STN_SR,   STN_ZR,
                                              STN_N1,    STN_A,    STN_O,         STN_E,    STN_U,    STN_N2
    ),
    /*
     *                        ┌───┬───┬───┬───┬───┬───┐    ┌───┬───┬───┬───┬───┬───┐
     *           backspace -> │ <-│ S │ T │ P │ H │ * │    │ * │ F │ P │ L │ T │ D │
     *                        ├───┼───┼───┼───┼───┼───┤    ├───┼───┼───┼───┼───┼───┤
     * toggle qwerty steno -> │TG │ S │ K │ W │ R │ * │    │ * │ R │ B │ G │ S │ Z │
     *                        └───┴───┴───┴───┴───┴───┘    └───┴───┴───┴───┴───┴───┘
     *                                     ┌───┬───┬───┐  ┌───┬───┬───┐
     *                                     │ # │ A │ O │  │ E │ U │ # │
     *                                     └───┴───┴───┘  └───┴───┴───┘
     */
    [_NKRO] = LAYOUT_dragonwings_grid(
        KC_BSPC,     KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,               KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,      KC_LBRC,
        TG(_NKRO),   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,               KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,   KC_QUOT,
                                        KC_1,    KC_C,    KC_V,      KC_N,    KC_M,    KC_9
    )


};


 void matrix_init_user() {
    steno_set_mode(STENO_MODE_GEMINI);
 }
