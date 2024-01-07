/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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

enum layers {
    QWERTY = 0,
    SYMBOLS,
    NUMBERS,
    SWE,
    MEDIA,
};

#define VERSION_STRING "  Henrik's rev0.21\n\n"

// Aliases for readability
#define CTL_SEMI MT(MOD_RCTL, KC_SCLN)
#define CTL_A MT(MOD_RCTL, KC_A)
#define LSFT_ESC MT(MOD_LSFT, KC_ESC)
#define LSFT_SPC MT(MOD_LSFT, KC_SPC)
#define LSFT_BS MT(MOD_LSFT, KC_BSPC)
#define LALT_F MT(MOD_LALT, KC_F)
#define HYPR_ESC HYPR_T(KC_ESC)
#define SWE_A LT(SWE, KC_A)
#define SWE_S LT(SWE, KC_S)
#define SPC_SYM  LT(SYMBOLS, KC_SPC)
#define BS_NUM   LT(NUMBERS, KC_BSPC)
#define M_LBRC LT(MEDIA, KC_LBRC)
#define SWE_TAB LT(SWE, KC_TAB)

enum custom_keycodes {
  KC_ARRO = SAFE_RANGE,
  KC_ARING,
  KC_AUML,
  KC_OUML
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * TODO: ESC/SHIFT not really needed, and generally too many esc all over...
 * Layer 1: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * | Tab/Å  |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |Media [ |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |HYP/ESC |Ctrl_A|SWE_S |   D  |ALT/F |   G  |                              |   H  |   J  |   K  |   L  |Ctrl;:|   ' "  |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |  LCtl  |   Z  |   X  |   C  |   V  |   B  | Tab/Å| ESC  |  | - _  | =  + |   N  |   M  | ,  < | . >  | /  ? |   ?   |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | LCtl | LAlt | LGUI |  BS  |  BS  |  | Space| Space| RGUI | RAlt | RCtl |
 *                        |      |      |      | NUM  |LSHFT |  |   ?  | SYM  |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
  [QWERTY] = LAYOUT(
   SWE_TAB , KC_Q ,  KC_W   ,  KC_E   ,   KC_R ,   KC_T ,                                                 KC_Y,    KC_U   , KC_I   , KC_O  , KC_P   , M_LBRC,
   HYPR_ESC, CTL_A,  SWE_S  ,  KC_D   ,   LALT_F,  KC_G ,                                                 KC_H,    KC_J   , KC_K   , KC_L  , CTL_SEMI,KC_QUOT,
   KC_LCTL,  KC_Z ,  KC_X   ,  KC_C   ,   KC_V ,   KC_B ,    SWE_TAB ,  KC_ESC ,      KC_MINS , KC_EQUAL, KC_N,    KC_M   , KC_COMM, KC_DOT, KC_SLSH, KC_ENT ,
                               KC_LCTL,   KC_LALT, KC_LGUI,  BS_NUM  ,  LSFT_BS,      LSFT_SPC, SPC_SYM,  KC_RGUI ,KC_RALT, KC_RCTL
  ),

/*
 * Layer 2: Symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |    `   |  !   |  @   |  #   |  $   |  %   |                              |   ^  |   &  |  *   |  (   |  )   |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |    ~   |  F1  |  F2  |  F3  |  F4  |  F5  |                              |  ?   |   ?  |  ?   |  ?   |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |  |      |  =>  |      |      |      |      |      |   ?   |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | LCtl | LAlt | LGUI |  DEL | LSft |  |      | [L]  | RGUI | RAlt | RCtl |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
  [SYMBOLS] = LAYOUT(
   KC_GRV  , KC_EXLM,  KC_AT , KC_HASH, KC_DLR, KC_PERC,                                        KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN,  KC_RPRN, KC_PSCR,
   KC_TILD , KC_F1,    KC_F2 , KC_F3,   KC_F4,  KC_F5,                                          KC_LEFT, KC_DOWN, KC_UP  , KC_RIGHT, KC_NO,   KC_NO,
   KC_NO   , KC_F6,    KC_F7 , KC_F8,   KC_F9,  KC_F10,   KC_F11,  KC_F12,     KC_NO,  KC_ARRO, KC_NO,   KC_NO  , KC_NO, KC_NO   , KC_NO,   KC_ENT,
                               KC_LCTL, KC_LALT,KC_LGUI,  KC_DEL,  KC_LSFT,    KC_NO,  KC_NO,   KC_RGUI, KC_RALT, KC_RCTL
  ),

/*
 * Layer 3: Numbers
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |   (  |   )  |   \  |                              |   +  |   7  |   8  |   9  |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |   {  |   }  |   |  |                              |   -  |   4  |   5  |   6  |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |   [  |   ]  |      |      |      |  | -  _ | =  + |   *  |   1  |   2  |   3  |   /  | Enter  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |LCtl | LAlt  | LGUI |  [L] | LSft |  |   ?  |      |   0  |   ,  |   .  |
 *                        |     |       |      |      |      |  | Space| Space|      |      |      |
 *                        `----------------------------------'   `----------------------------------'
 */
  [NUMBERS] = LAYOUT(
  _______, _______, _______, KC_LPRN, KC_RPRN, KC_BSLS,                                          KC_PPLS, KC_7   , KC_8  , KC_9  , _______, _______,
  _______, _______, _______, KC_LCBR, KC_RCBR, KC_PIPE,                                          KC_PMNS, KC_4   , KC_5  , KC_6  , _______, _______,
  _______, _______, _______, KC_LBRC, KC_RBRC, _______, _______, _______,      KC_MINS,KC_EQUAL, KC_PAST, KC_1   , KC_2  , KC_3  , KC_PSLS, KC_ENT,
                             KC_LCTL, KC_LALT, KC_LGUI, KC_NO  , KC_LSFT,        LSFT_SPC, KC_SPC, KC_0   , KC_COMM, KC_DOT
  ),

/*
 * Layer 4: US Intl
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |   Å    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              |      |      |      |      |  Ö   |   Ä    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
  [SWE] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, KC_ARING,
  _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, KC_OUML, KC_AUML,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
           _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

/*
 * Layer 5: Media
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      | Back |                              |Vol ? |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      | Play |                              |Vol ? |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      | Next |      |      |  |      |      | Mute |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
  [MEDIA] = LAYOUT(
  _______, _______, _______, _______, _______, KC_MPRV,                                     KC_VOLU, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, KC_MPLY,                                     KC_VOLD, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, KC_MNXT, _______, _______, _______, _______, KC_MUTE, _______, _______, _______, _______, _______,
           _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),


// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_ARRO:
            if (record->event.pressed) {
                SEND_STRING("=> ");
            }
            break;
        case KC_ARING:
            if (record->event.pressed) {
                SEND_STRING(SS_RALT("w"));
            }
            break;
        case KC_AUML:
            if (record->event.pressed) {
                SEND_STRING(SS_RALT("q"));
            }
            break;
        case KC_OUML:
            if (record->event.pressed) {
                SEND_STRING(SS_RALT("p"));
            }
            break;
    }
    return true;
};

// Turn off Liatris LED
void keyboard_pre_init_user(void) {
  // Set our LED pin as output
  setPinOutput(24);
  // Turn the LED off
  // (Due to technical reasons, high is off and low is on)
  writePinHigh(24);
}
