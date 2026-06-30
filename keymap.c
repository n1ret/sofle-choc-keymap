/* Copyright 2023 Brian Low
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

enum layer_names {
    _QUERTY,
    _ADDITIONALS,
    _CL,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌──────┬───┬──────┬──────┬──────┬──────┐                 ┌───┬───┬─────┬───────────────────┬───┬──────┐
//    │  `   │ 1 │  2   │  3   │  4   │  5   │                 │ 6 │ 7 │  8  │         9         │ 0 │  -   │
//    ├──────┼───┼──────┼──────┼──────┼──────┤                 ├───┼───┼─────┼───────────────────┼───┼──────┤
//    │ esc  │ q │  w   │  e   │  r   │  t   │                 │ y │ u │  i  │         o         │ p │ bspc │
//    ├──────┼───┼──────┼──────┼──────┼──────┤                 ├───┼───┼─────┼───────────────────┼───┼──────┤
//    │ tab  │ a │  s   │  d   │  f   │  g   │                 │ h │ j │  k  │         l         │ ; │  '   │
//    ├──────┼───┼──────┼──────┼──────┼──────┼──────┐   ┌──────┼───┼───┼─────┼───────────────────┼───┼──────┤
//    │ lsft │ z │  x   │  c   │  v   │  b   │ mute │   │ mply │ n │ m │  ,  │         .         │ / │  =   │
//    └──────┴───┼──────┼──────┼──────┼──────┼──────┤   ├──────┼───┼───┼─────┼───────────────────┼───┴──────┘
//               │ lalt │ home │ lgui │ lctl │ ent  │   │ spc  │ [ │ ] │ end │ OSL(_ADDITIONALS) │
//               └──────┴──────┴──────┴──────┴──────┘   └──────┴───┴───┴─────┴───────────────────┘
[_QUERTY] = LAYOUT(
  KC_GRV  , KC_1 , KC_2    , KC_3    , KC_4    , KC_5    ,                         KC_6    , KC_7    , KC_8    , KC_9              , KC_0    , KC_MINS,
  KC_ESC  , KC_Q , KC_W    , KC_E    , KC_R    , KC_T    ,                         KC_Y    , KC_U    , KC_I    , KC_O              , KC_P    , KC_BSPC,
  KC_TAB  , KC_A , KC_S    , KC_D    , KC_F    , KC_G    ,                         KC_H    , KC_J    , KC_K    , KC_L              , KC_SCLN , KC_QUOT,
  KC_LSFT , KC_Z , KC_X    , KC_C    , KC_V    , KC_B    , KC_MUTE ,     KC_MPLY , KC_N    , KC_M    , KC_COMM , KC_DOT            , KC_SLSH , KC_EQL ,
                   KC_LALT , KC_HOME , KC_LCMD , KC_LCTL , KC_ENT  ,     KC_SPC  , KC_LBRC , KC_RBRC , KC_END  , OSL(_ADDITIONALS)
),

//    ┌──────┬────┬──────┬──────┬─────┬──────┐                 ┌──────┬──────┬──────┬──────┬───┬──────┐
//    │  `   │ 1  │  2   │  3   │  4  │  5   │                 │  6   │  7   │  8   │  9   │ 0 │  -   │
//    ├──────┼────┼──────┼──────┼─────┼──────┤                 ├──────┼──────┼──────┼──────┼───┼──────┤
//    │  f1  │ f2 │  f3  │  f4  │ f5  │  f6  │                 │  y   │  u   │  i   │  o   │ p │ bspc │
//    ├──────┼────┼──────┼──────┼─────┼──────┤                 ├──────┼──────┼──────┼──────┼───┼──────┤
//    │  f7  │ f8 │  f9  │ f10  │ f11 │ f12  │                 │  h   │  j   │  k   │  l   │ ; │  '   │
//    ├──────┼────┼──────┼──────┼─────┼──────┼──────┐   ┌──────┼──────┼──────┼──────┼──────┼───┼──────┤
//    │ lsft │ z  │  x   │  c   │  v  │  b   │ mute │   │ mply │  n   │  m   │  ,   │  .   │ / │  =   │
//    └──────┴────┼──────┼──────┼─────┼──────┼──────┤   ├──────┼──────┼──────┼──────┼──────┼───┴──────┘
//                │ lalt │ lgui │ spc │ lctl │ ent  │   │ spc  │ ralt │ rgui │ rgui │ rctl │
//                └──────┴──────┴─────┴──────┴──────┘   └──────┴──────┴──────┴──────┴──────┘
[_ADDITIONALS] = LAYOUT(
  KC_GRV  , KC_1  , KC_2    , KC_3    , KC_4     , KC_5    ,                         KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_MINS,
  KC_F1   , KC_F2 , KC_F3   , KC_F4   , KC_F5    , KC_F6   ,                         KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    , KC_BSPC,
  KC_F7   , KC_F8 , KC_F9   , KC_F10  , KC_F11   , KC_F12  ,                         KC_H    , KC_J    , KC_K    , KC_L    , KC_SCLN , KC_QUOT,
  KC_LSFT , KC_Z  , KC_X    , KC_C    , KC_V     , KC_B    , KC_MUTE ,     KC_MPLY , KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , KC_EQL ,
                    KC_LALT , KC_LGUI , KC_SPACE , KC_LCTL , KC_ENT  ,     KC_SPC  , KC_RALT , KC_RCMD , KC_RGUI , KC_RCTL
)
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
};
#endif

// nvim: nodiagnostics
