# Prosthetics Vacuum Pump Controller

## Introduction

Designed to maintain a set vacuum pressure for prosthetic arms and legs.

![3D Printed Case](/Case/Case.png)

## Dependencies

[Adafruit MPRLS Library](https://github.com/adafruit/Adafruit_MPRLS)

## Author

Eric Conner (Eric@EricConner.net)

## License

### MIT license

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

## Changes

- 2021.0628.0 - Added min/max set points
- 2021.0221.0 - Revised Pump class to define pump pin when pump is initilized
- 2021.0220.0 - Set DEBUG to false and misc. other changes
- 2021.0219.0 - Added option to specify on and off times for Pump
- 2021.0218.1 - Added destructor for Pump class
- 2021.0218.0 - Initial release
