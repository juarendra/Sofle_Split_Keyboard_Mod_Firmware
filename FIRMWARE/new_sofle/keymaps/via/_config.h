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

#pragma once

/* By default left side is selected as master, 
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options. */


// Add RGB underglow and top facing lighting
#    define WS2812_DI_PIN D3
#    define RGBLED_NUM 24
#    define RGBLED_SPLIT {12,12}
#        define RGBLIGHT_EFFECT_BREATHING
#        define RGBLIGHT_EFFECT_RAINBOW_MOOD
//#        define RGBLIGHT_EFFECT_RAINBOW_SWIRL
//#        define RGBLIGHT_EFFECT_SNAKE




