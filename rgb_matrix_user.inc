RGB_MATRIX_EFFECT(STATUS_LAYER)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS
static bool STATUS_LAYER(effect_params_t *params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    RGB c = hsv_to_rgb((HSV){0, 0, rgb_matrix_get_val()});
    for (uint8_t i = led_min; i < led_max; i++) rgb_matrix_set_color(i, c.r, c.g, c.b);
    return rgb_matrix_check_finished_leds(led_max);
}
#endif
