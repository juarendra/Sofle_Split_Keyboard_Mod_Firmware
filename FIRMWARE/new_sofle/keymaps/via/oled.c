 /* Copyright 2020 Josef Adamcik
  * Modification for VIA support and RGB underglow by Jens Bonk-Wiltfang
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

#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM raw_logo[] = {
        0,  0,128,192,224,240,248,252,252,254,254,254,255,127, 63, 63, 63, 63,127,255,254,254,254,252,156, 56,112,224,192,128,  0,  0,240,254,255,255,255,255,255,255,255,255,255,255,255,252,248,240,240,248,252,255,255,127, 63, 31,  3,  0,  0,  0,  3, 31,254,240, 15,127,255,255,255,255,255,255,255,255, 15,  7,  3,195,225,241,241,225,193,  0,  0,  0,  0,  0,  0,  0,  0,  0,192,248,127, 15,  0,  0,  1,  3,  7, 15, 31, 63, 63,127,124,112,224,224,195,195,195,195,192,224, 96, 96,112, 48, 56, 28, 14,  7,  3,  1,  0,  0,
    };
    oled_write_raw_P(raw_logo, sizeof(raw_logo));
}

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n\n"), false);

    switch (get_highest_layer(default_layer_state)) {
        case 0: // _QWERTY
            oled_write_ln_P(PSTR("Qwrt\n"), false);
            break;
        case 1: // _COLEMAK
            oled_write_ln_P(PSTR("Clmk\n"), false);
            break;
        default:
            oled_write_P(PSTR("Mod"), false);
            break;
    }
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case 0: // _QWERTY
        case 1: // _COLEMAK
            oled_write_P(PSTR("Base\n"), false);
            break;
        case 2:
            oled_write_P(PSTR("Lower"), false);
            break;
        case 3:
            oled_write_P(PSTR("Raise"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
		print_status_narrow();
    } else {
		oled_set_cursor(0,3);
	oled_write_P(PSTR("SOFLE"), false);
		oled_set_cursor(0,7);
        render_logo();
        oled_set_cursor(0,13);
        oled_write_P(PSTR("WPM: "), false);
        oled_write(get_u8_str(get_current_wpm(), ' '), false);
    }
    return false;
}

#endif
