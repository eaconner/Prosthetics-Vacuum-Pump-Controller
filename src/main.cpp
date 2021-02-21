/**
 * @file main.cpp
 * 
 * @author Eric Conner (Eric@EricConner.net)
 * @version 2021.0219.0
 * @copyright Copyright (c) 2021
 * 
 * @mainpage Prosthetics Vacuum Pump Controller
 * 
 * @section intro_sec Introduction
 * 
 * Designed to maintain a set vacuum pressure for prosthetic arms and legs.
 * 
 * @section dependencies Dependencies
 * 
 * [Adafruit MPRLS Library] (https://github.com/adafruit/Adafruit_MPRLS)
 * 
 * @section author Author
 * 
 * Written by Eric Conner for EricConner.net.
 * 
 * @section license License
 *
 * ###MIT license###
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
 * 
 * @section changes Changes
 * 
 * 2021.0218.0 - Initial release
 * 2021.0218.1 - Added destructor for Pump class
 * 2021.0219.0 - Added option to specify on and off times for Pump
 */

#include "main.h"
#include "pump.h"

Adafruit_MPRLS mpr = Adafruit_MPRLS();  // Initilize the Pressure Sensor
Pump pump = Pump(10000,5000);

/**
 * @brief Standard Arduino setup function, this initilizes everything and then jumps to loop().
 */
void setup() {
    if (DEBUG) {
        Serial.begin(115200);  // Setup serial connection for displaying text if we are in debug mode
        Serial.println("Prosthetic Vacuum Pump - v2021.0219.0");
    }

    // Start the MPRLS pressure sensor
    if(! mpr.begin()) {
        // Wait for sensor to connect
        while(1) {
            delay(10);
        }
    }

   delay(2500);

   wdt_reset();
   wdt_enable(WDTO_2S);
}

/**
 * @brief Standard Arduino loop fuction, this is our main code loop.
 */
void loop() {
    if (getPressure() > setPressure) {
        pump.On();
    } else {
        pump.Off();
    }

    delay(1000);
    wdt_reset();
}

/**
 * @brief Get the Pressure value from the Pressure Sensor in hPa.
 * 
 * @return float 
 */
float getPressure() {
    float pressure_hPa = mpr.readPressure();

    if (DEBUG) {
        Serial.print("Pressure (hPa): ");
        Serial.println(pressure_hPa);
    }

    return pressure_hPa;  // Return the pressure value
}
