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
    0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0x18, 0x08, 0x04, 0x04, 0x06, 0x02, 0x02, 0x02, 0x02, 
	0x02, 0x02, 0x02, 0x02, 0x06, 0x04, 0x04, 0x08, 0x18, 0x10, 0x20, 0xc0, 0x80, 0x00, 0x00, 0x00, 
	0x80, 0xfc, 0x0f, 0x0f, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x0f, 0x0f, 0xff, 0xff, 0xfe, 0xfe, 0xfc, 
	0x00, 0xfc, 0xfe, 0xfe, 0xff, 0x0f, 0x0f, 0x0f, 0x3e, 0x3e, 0x3f, 0x3f, 0x0f, 0x07, 0xfc, 0x00, 
	0x01, 0x3f, 0xe0, 0x80, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xe0, 0xe0, 0xff, 0xff, 0xff, 0xff, 0x7f, 
	0x00, 0x7f, 0xff, 0xff, 0xff, 0xf0, 0xe0, 0xe0, 0xf8, 0xf8, 0xf8, 0xf8, 0xe0, 0xe0, 0x3f, 0x00, 
	0x00, 0x00, 0x00, 0x01, 0x03, 0x05, 0x09, 0x11, 0x31, 0x21, 0x61, 0x41, 0x41, 0x40, 0x40, 0x40, 
	0x40, 0x40, 0x40, 0x40, 0x41, 0x61, 0x21, 0x31, 0x11, 0x09, 0x05, 0x03, 0x01, 0x00, 0x00, 0x00
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
        oled_write_ln_P(PSTR("SOFLE"), false);
		oled_set_cursor(0,7);
        render_logo();
        oled_set_cursor(0,13);
        oled_write_P(PSTR("WPM: "), false);
        oled_write(get_u8_str(get_current_wpm(), ' '), false);
    }
    return false;
}

#endif
