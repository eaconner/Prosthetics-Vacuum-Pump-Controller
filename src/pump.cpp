/**
 * @file pump.cpp
 * 
 * @author Eric Conner (Eric@EricConner.net)
 * @version 2021.0218.1
 * @copyright Copyright (c) 2021
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the
 * Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software,
 * and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR
 * ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH
 * THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include "pump.h"

/**
 * @brief Construct a new Pump:: Pump object
 */
Pump::Pump() {
    pinMode(PUMP_PIN, OUTPUT);  // Setup the output pin for Pump
    digitalWrite(PUMP_PIN, LOW);  // Seting the Pump output pin LOW turns the Pump off
    Pump::status = STOPPED;
}

/**
 * @brief Destroy the Pump:: Pump object
 */
Pump::~Pump() {
    digitalWrite(PUMP_PIN, LOW);  // Seting the Pump output pin LOW turns the Pump off
    Pump::status = STOPPED;
}

/**
 * @brief Call for the pump to turn on, will only turn on if it has been off for at least 5 seconds
 */
void Pump::On() {
    // If the pump is off and cooled down turn the pump on, set the status to running and start the running timer
    if (Pump::status == STOPPED) {
        digitalWrite(PUMP_PIN, HIGH);
        Pump::status = RUNNING;
        Pump::OnTime = millis();
    }
    
    if (Pump::status == RUNNING) {
        // If the pump has been running for 10 seconds turn it off to prevent overheating
        if (millis() - Pump::OnTime >= Pump::maxOnTime) {
            Pump::Off();
        }
    }

    if (Pump::status == COOLDOWN) {
        // If the pump has been cooled down for 5 seconds set the status to stopped
        if (millis() - Pump::OffTime >= Pump::minOffTime) {
            Pump::status = STOPPED;
        }
    }
}

/**
 * @brief Call for the pump to instantly turn off
 */
void Pump::Off() {
    // If the pump is running turn it off and start the cooldown timer
    if (Pump::status == RUNNING) {
        digitalWrite(PUMP_PIN, LOW);
        Pump::OffTime = millis();
        Pump::status = COOLDOWN;
    }
    
    if (Pump::status == COOLDOWN) {
        // If the pump has been cooled down for 5 seconds set the status to stopped
        if (millis() - Pump::OffTime >= Pump::minOffTime) {
            Pump::status = STOPPED;
        }
    }
}
