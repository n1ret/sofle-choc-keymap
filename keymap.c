/* Copyright 2023 Brian Low
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
#include "color.h"
#include <stdint.h>
#include QMK_KEYBOARD_H
#include "transactions.h"

enum layer_names {
  _QUERTY,
  _GAMING,
  _ONESHOTS,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌──────┬───┬──────┬──────┬──────┬──────┐                 ┌────────────────┬───┬───┬─────┬───┬──────┐
//    │  `   │ 1 │  2   │  3   │  4   │  5   │                 │       6        │ 7 │ 8 │  9  │ 0 │  -   │
//    ├──────┼───┼──────┼──────┼──────┼──────┤                 ├────────────────┼───┼───┼─────┼───┼──────┤
//    │ esc  │ q │  w   │  e   │  r   │  t   │                 │       y        │ u │ i │  o  │ p │ bspc │
//    ├──────┼───┼──────┼──────┼──────┼──────┤                 ├────────────────┼───┼───┼─────┼───┼──────┤
//    │ tab  │ a │  s   │  d   │  f   │  g   │                 │       h        │ j │ k │  l  │ ; │  '   │
//    ├──────┼───┼──────┼──────┼──────┼──────┼──────┐   ┌──────┼────────────────┼───┼───┼─────┼───┼──────┤
//    │ lsft │ z │  x   │  c   │  v   │  b   │ mute │   │ mply │       n        │ m │ , │  .  │ / │  =   │
//    └──────┴───┼──────┼──────┼──────┼──────┼──────┤   ├──────┼────────────────┼───┼───┼─────┼───┴──────┘
//               │ lalt │ home │ lgui │ lctl │ ent  │   │ spc  │ OSL(_ONESHOTS) │ [ │ ] │ end │
//               └──────┴──────┴──────┴──────┴──────┘   └──────┴────────────────┴───┴───┴─────┘
[_QUERTY] = LAYOUT(
  KC_GRV  , KC_1 , KC_2    , KC_3    , KC_4    , KC_5    ,                         KC_6           , KC_7    , KC_8    , KC_9   , KC_0    , KC_MINS,
  KC_ESC  , KC_Q , KC_W    , KC_E    , KC_R    , KC_T    ,                         KC_Y           , KC_U    , KC_I    , KC_O   , KC_P    , KC_BSPC,
  KC_TAB  , KC_A , KC_S    , KC_D    , KC_F    , KC_G    ,                         KC_H           , KC_J    , KC_K    , KC_L   , KC_SCLN , KC_QUOT,
  KC_LSFT , KC_Z , KC_X    , KC_C    , KC_V    , KC_B    , KC_MUTE ,     KC_MPLY , KC_N           , KC_M    , KC_COMM , KC_DOT , KC_SLSH , KC_EQL ,
                   KC_LALT , KC_HOME , KC_LCMD , KC_LCTL , KC_ENT  ,     KC_SPC  , OSL(_ONESHOTS) , KC_LBRC , KC_RBRC , KC_END
),

//    ┌──────┬───┬──────┬─────┬─────┬──────┐                 ┌────────────────┬───┬───┬─────┬───┬──────┐
//    │  `   │ 1 │  2   │  3  │  4  │  5   │                 │       6        │ 7 │ 8 │  9  │ 0 │  -   │
//    ├──────┼───┼──────┼─────┼─────┼──────┤                 ├────────────────┼───┼───┼─────┼───┼──────┤
//    │ esc  │ q │  w   │  e  │  r  │  t   │                 │       y        │ u │ i │  o  │ p │ bspc │
//    ├──────┼───┼──────┼─────┼─────┼──────┤                 ├────────────────┼───┼───┼─────┼───┼──────┤
//    │ lsft │ a │  s   │  d  │  f  │  g   │                 │       h        │ j │ k │  l  │ ; │  '   │
//    ├──────┼───┼──────┼─────┼─────┼──────┼──────┐   ┌──────┼────────────────┼───┼───┼─────┼───┼──────┤
//    │ lctl │ z │  x   │  c  │  v  │  b   │ mute │   │ mply │       n        │ m │ , │  .  │ / │  =   │
//    └──────┴───┼──────┼─────┼─────┼──────┼──────┤   ├──────┼────────────────┼───┼───┼─────┼───┴──────┘
//               │ lalt │ tab │ spc │ home │ ent  │   │ lgui │ OSL(_ONESHOTS) │ [ │ ] │ end │
//               └──────┴─────┴─────┴──────┴──────┘   └──────┴────────────────┴───┴───┴─────┘
[_GAMING] = LAYOUT(
  KC_GRV  , KC_1 , KC_2    , KC_3   , KC_4   , KC_5    ,                         KC_6           , KC_7    , KC_8    , KC_9   , KC_0    , KC_MINS,
  KC_ESC  , KC_Q , KC_W    , KC_E   , KC_R   , KC_T    ,                         KC_Y           , KC_U    , KC_I    , KC_O   , KC_P    , KC_BSPC,
  KC_LSFT , KC_A , KC_S    , KC_D   , KC_F   , KC_G    ,                         KC_H           , KC_J    , KC_K    , KC_L   , KC_SCLN , KC_QUOT,
  KC_LCTL , KC_Z , KC_X    , KC_C   , KC_V   , KC_B    , KC_MUTE ,     KC_MPLY , KC_N           , KC_M    , KC_COMM , KC_DOT , KC_SLSH , KC_EQL ,
                   KC_LALT , KC_TAB , KC_SPC , KC_HOME , KC_ENT  ,     KC_LCMD , OSL(_ONESHOTS) , KC_LBRC , KC_RBRC , KC_END
),

//    ┌──────┬─────────┬─────────┬─────────┬─────────┬─────────┐               ┌──────┬─────────────┬─────────────┬──────┬──────┬─────────┐
//    │ calc │ RM_TOGG │ RM_PREV │ RM_NEXT │ RM_VALD │ RM_VALU │               │      │             │             │      │      │         │
//    ├──────┼─────────┼─────────┼─────────┼─────────┼─────────┤               ├──────┼─────────────┼─────────────┼──────┼──────┼─────────┤
//    │  f1  │   f2    │   f3    │   f4    │   f5    │   f6    │               │      │             │             │      │ pgup │   del   │
//    ├──────┼─────────┼─────────┼─────────┼─────────┼─────────┤               ├──────┼─────────────┼─────────────┼──────┼──────┼─────────┤
//    │  f7  │   f8    │   f9    │   f10   │   f11   │   f12   │               │ left │    down     │     up      │ rght │ pgdn │         │
//    ├──────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────┐   ┌─────┼──────┼─────────────┼─────────────┼──────┼──────┼─────────┤
//    │      │         │         │         │         │         │     │   │     │      │             │             │      │  \   │ QK_LOCK │
//    └──────┴─────────┼─────────┼─────────┼─────────┼─────────┼─────┤   ├─────┼──────┼─────────────┼─────────────┼──────┼──────┴─────────┘
//                     │         │         │         │         │     │   │     │      │ DF(_QUERTY) │ DF(_GAMING) │      │
//                     └─────────┴─────────┴─────────┴─────────┴─────┘   └─────┴──────┴─────────────┴─────────────┴──────┘
[_ONESHOTS] = LAYOUT(
  KC_CALC , RM_TOGG , RM_PREV , RM_NEXT , RM_VALD , RM_VALU ,                         KC_TRNS , KC_TRNS     , KC_TRNS     , KC_TRNS , KC_TRNS , KC_TRNS,
  KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   ,                         KC_TRNS , KC_TRNS     , KC_TRNS     , KC_TRNS , KC_PGUP , KC_DEL ,
  KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_F12  ,                         KC_LEFT , KC_DOWN     , KC_UP       , KC_RGHT , KC_PGDN , KC_TRNS,
  KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,     KC_TRNS , KC_TRNS , KC_TRNS     , KC_TRNS     , KC_TRNS , KC_BSLS , QK_LOCK,
                      KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,     KC_TRNS , KC_TRNS , DF(_QUERTY) , DF(_GAMING) , KC_TRNS
)
};
// clang-format on

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_QUERTY] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MFFD, KC_MRWD)},
    [_GAMING] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MFFD, KC_MRWD)},
    [_ONESHOTS] = {ENCODER_CCW_CW(KC_BRID, KC_BRIU), ENCODER_CCW_CW(KC_MNXT, KC_MPRV)},
};

// Custom keys processing and RGB Matrix settings
static bool is_gaming(void) { return get_highest_layer(default_layer_state) == _GAMING; }

#define MAX_LOCKED 6
#define MAX_HELD 12

typedef struct {
  bool caps;
  bool os_down;
  uint8_t locked[MAX_LOCKED]; // keycodes held by Key Lock, 0 = unused
} led_state_t;
static led_state_t led_state, led_state_sent;

typedef struct {
  uint8_t kc, row, col;
} held_t;
static held_t held[MAX_HELD];

static void track_held(uint16_t kc, keyrecord_t *record) {
  if (kc < KC_A || kc > 0xFF)
    return; // Key Lock only handles basic keycodes
  if (record->event.pressed) {
    for (uint8_t i = 0; i < MAX_HELD; i++) {
      if (!held[i].kc) {
        held[i] = (held_t){kc, record->event.key.row, record->event.key.col};
        return;
      }
    }
  } else {
    for (uint8_t i = 0; i < MAX_HELD; i++)
      if (held[i].kc == kc)
        held[i].kc = 0;
  }
}

static uint32_t shift_timer;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  track_held(keycode, record);

  if (keycode == KC_LSFT && record->event.pressed && !is_gaming()) {
    if (timer_elapsed32(shift_timer) < TAPPING_TERM) {
      caps_word_on();
      return false;
    }
    shift_timer = timer_read32();
  }
  return true;
}

static void led_sync_handler(uint8_t in_len, const void *in, uint8_t out_len, void *out) {
  if (in_len == sizeof(led_state))
    memcpy(&led_state, in, sizeof(led_state));
}

void keyboard_post_init_user(void) { transaction_register_rpc(USER_SYNC_LED, led_sync_handler); }

void housekeeping_task_user(void) {
  if (!is_keyboard_master())
    return;

  led_state_t s = {.caps = is_caps_word_on()};

  const uint8_t dl = get_highest_layer(default_layer_state);
  for (uint8_t row = 0; row < MATRIX_ROWS; row++)
    for (uint8_t col = 0; col < MATRIX_COLS; col++)
      if (matrix_is_on(row, col) && keymap_key_to_keycode(dl, (keypos_t){.row = row, .col = col}) == OSL(_ONESHOTS))
        s.os_down = true;

  uint8_t n = 0;
  for (uint8_t i = 0; i < MAX_HELD; i++)
    if (held[i].kc && !matrix_is_on(held[i].row, held[i].col) && n < MAX_LOCKED)
      s.locked[n++] = held[i].kc;

  led_state = s;
  if (memcmp(&s, &led_state_sent, sizeof(s)) && transaction_rpc_send(USER_SYNC_LED, sizeof(s), &s))
    led_state_sent = s;
}

#define DEFAULT_COLOR RGB_WHITE
#define DEFAULT_ACCENT RGB_PURPLE
#define DEFAULT_LOCK RGB_RED
#define GAMING_COLOR RGB_BLACK
#define GAMING_ACCENT RGB_PURPLE
#define GAMING_LOCK RGB_PURPLE
#define GAMING_WASD RGB_RED

#define FLASH_MS 800
#define FLASH_SPEED (65535u / FLASH_MS)
#define FLASH_MAX (65535u / FLASH_SPEED)

static void set_rgb(uint8_t i, uint8_t r, uint8_t g, uint8_t b) {
  const uint16_t v = rgb_matrix_get_val() + 1u;
  rgb_matrix_set_color(i, (r * v) >> 8, (g * v) >> 8, (b * v) >> 8);
}

// t = 0 gives a, t = 255 gives b exactly
static uint8_t mix8(uint8_t a, uint8_t b, uint8_t t) {
  return b >= a ? a + (((uint16_t)(b - a) * (t + 1u)) >> 8) : a - (((uint16_t)(a - b) * (t + 1u)) >> 8);
}

static void set_mix(uint8_t i, uint8_t r1, uint8_t g1, uint8_t b1, uint8_t r2, uint8_t g2, uint8_t b2, uint8_t t) {
  set_rgb(i, mix8(r1, r2, t), mix8(g1, g2, t), mix8(b1, b2, t));
}

static uint8_t flash_amount(uint8_t led) {
  uint16_t tick = FLASH_MAX;
  for (uint8_t j = 0; j < g_last_hit_tracker.count; j++)
    if (g_last_hit_tracker.index[j] == led && g_last_hit_tracker.tick[j] < tick)
      tick = g_last_hit_tracker.tick[j];

  const uint8_t offset = (uint16_t)(tick * FLASH_SPEED) >> 8;
  const uint8_t sq = ((uint16_t)offset * (offset + 1u)) >> 8;
  const uint8_t cu = ((uint16_t)sq * (offset + 1u)) >> 8;
  return 255 - cu;
}

static bool is_locked(uint16_t kc) {
  if (kc == 0)
    return false;
  for (uint8_t i = 0; i < MAX_LOCKED; i++)
    if (led_state.locked[i] == kc)
      return true;
  return false;
}

static void paint_base(uint8_t led_min, uint8_t led_max, bool gaming) {
  for (uint8_t i = led_min; i < led_max; i++) {
    if (gaming) {
      const uint8_t amt = flash_amount(i);
      if (amt)
        set_mix(i, GAMING_COLOR, GAMING_ACCENT, amt);
      else
        set_rgb(i, GAMING_COLOR);
    } else {
      set_rgb(i, DEFAULT_COLOR);
    }
  }
}

static void paint_keys(uint8_t led_min, uint8_t led_max, uint8_t dl, bool gaming) {
  const bool os_on = layer_state_is(_ONESHOTS) || led_state.os_down;

  for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
    for (uint8_t col = 0; col < MATRIX_COLS; col++) {
      uint8_t led;
      if (!rgb_matrix_map_row_column_to_led(row, col, &led) || led < led_min || led >= led_max)
        continue;
      const uint16_t kc = keymap_key_to_keycode(dl, (keypos_t){.row = row, .col = col});

      if (is_locked(kc)) {
        if (gaming)
          set_rgb(led, GAMING_LOCK);
        else
          set_rgb(led, DEFAULT_LOCK);
      } else if ((os_on && kc == OSL(_ONESHOTS)) || (led_state.caps && kc == KC_LSFT)) {
        if (gaming)
          set_rgb(led, GAMING_ACCENT);
        else
          set_rgb(led, DEFAULT_ACCENT);
      } else if (gaming && (kc == KC_W || kc == KC_A || kc == KC_S || kc == KC_D)) {
        set_rgb(led, GAMING_WASD);
      }
    }
  }
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
  if (rgb_matrix_get_mode() != RGB_MATRIX_CUSTOM_STATUS_LAYER)
    return true;

  const uint8_t dl = get_highest_layer(default_layer_state);
  const bool gaming = (dl == _GAMING);

  paint_base(led_min, led_max, gaming);
  paint_keys(led_min, led_max, dl, gaming);
  return false;
}

// vim: shiftwidth=2:
