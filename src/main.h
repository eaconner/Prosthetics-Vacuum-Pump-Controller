/**
 * @file main.h
 * 
 * @author Eric Conner (Eric@EricConner.net)
 * @copyright Copyright (c) 2021
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify,
 * merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished
 * to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR
 * ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH
 * THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#pragma once

#include <Arduino.h>
#include <avr/wdt.h>
#include "Adafruit_MPRLS.h"

const bool DEBUG = true;  // Set to true for serial output
const int pumpPin = 5;  // Microcontroller pin that the pump is connected to
const float hPa = 33.8638462;
const float setPressure = 13 * hPa;  // Set point to maintain in hPa
const float setMinPressure = 13 * hPa;  // Min set point to maintain in hPa
const float setMaxPressure = 15 * hPa;  // Max set point to maintain in hPa

void setup();
void loop();
float getPressure();
