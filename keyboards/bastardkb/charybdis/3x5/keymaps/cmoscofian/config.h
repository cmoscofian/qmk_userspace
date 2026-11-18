/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
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

// Configure the global tapping term (default: 200ms)
#define TAPPING_TERM 175

#ifdef VIA_ENABLE
/* VIA configuration. */
#    define DYNAMIC_KEYMAP_LAYER_COUNT 7
#endif // VIA_ENABLE

#ifndef __arm__
/* Disable unused features. */
#    define NO_ACTION_ONESHOT
#endif // __arm__

#ifdef AUTO_MOUSE_DEFAULT_LAYER
#undef AUTO_MOUSE_DEFAULT_LAYER
#endif
#define AUTO_MOUSE_DEFAULT_LAYER 4

#ifdef LED_DPI_INDICATOR_INDEX
#undef LED_DPI_INDICATOR_INDEX
#endif
#define LED_DPI_INDICATOR_INDEX 0

#ifdef RGBLIGHT_LED_COUNT
#undef RGBLIGHT_LED_COUNT
#endif
#define RGBLIGHT_LED_COUNT 35

#define CHARYBDIS_DEFAULT_DPI_CONFIG_STEP 300
#define CHARYBDIS_MINIMUM_DEFAULT_DPI 300

#define CHARYBDIS_AUTO_SNIPING_ON_LAYER POINTER

#ifdef CHARYBDIS_DRAGSCROLL_REVERSE_Y
#undef CHARYBDIS_DRAGSCROLL_REVERSE_Y
#endif

#ifdef POINTING_DEVICE_ENABLE
#define CHARYBDIS_DEFAULT_DPI_CONFIG_STEP 300
#define CHARYBDIS_MINIMUM_DEFAULT_DPI     300
#define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
#define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS 1000
#define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD 8
#endif // POINTING_DEVICE_ENABLE
