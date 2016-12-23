/* -*- mode: c++ -*-
 * Keyboardio-Borealis -- Borealis-inspired color scheme
 * Copyright (C) 2016  Gergely Nagy
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
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

#include "Keyboardio-Borealis.h"

BorealisEffect::BorealisEffect (void) {
  LEDControl.mode_add (this);
}

void
BorealisEffect::update (void) {
  static cRGB colors[] = {
    {0x67, 0x2d, 0x5f},
    {0x7e, 0x4b, 0x8e},
    {0x22, 0x5b, 0x90},
    {0x35, 0x86, 0xb5},
    {0x40, 0xad, 0xce},
    {0x8b, 0xfa, 0xe7},
  };

  // Update all the LEDs, each row with its own color.
  for (byte row = 0; row < ROWS; row++) {
    for (byte col = 0; col < COLS; col++) {
      led_set_crgb_at (row, col, colors[row]);
    }
  }

  // Override the thumb arcs, they should be treated as their own row.
  for (byte row = 0; row < 4; row++) {
    for (byte col = 7; col < 9; col++) {
      led_set_crgb_at (row, col, colors[4]);
    }
  }

  // Override the palm keys too, they are the final row.
  led_set_crgb_at (3, 6, colors[5]);
  led_set_crgb_at (3, 9, colors[5]);
}
