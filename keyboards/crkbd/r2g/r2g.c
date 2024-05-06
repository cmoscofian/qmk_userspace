#include "quantum.h"
#include "config.h"

#ifdef OLED_ENABLE

enum layer {
    BASE,
    NUM,
    SYM,
    ALT,
    SIZE,
};

static void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case BASE:
            oled_write_ln_P(PSTR("Base"), false);
            break;
        case NUM:
            oled_write_ln_P(PSTR("Numeric"), false);
            break;
        case SYM:
            oled_write_ln_P(PSTR("Symbols"), false);
            break;
        case ALT:
            oled_write_ln_P(PSTR("Other"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undefined"), false);
            break;
    }
}

static void oled_render_keylog(void) {
    oled_write_char('0' + last_row, false);
    oled_write_P(PSTR("x"), false);
    oled_write_char('0' + last_col, false);
    oled_write_P(PSTR(", k"), false);
    oled_write_P(PSTR(": "), false);
    oled_write_char(key_name, false);
    oled_advance_page(true);
    oled_advance_page(false);
}

bool oled_task_kb(void) {
    if (!oled_task_user()) {
        return false;
    }
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
        oled_write_ln_P(PSTR("Happy coding..."), false);
    } else {
        oled_render_logo();
    }
    return false;
}

#endif // OLED_ENABLE
