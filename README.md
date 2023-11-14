# NeoPixel Pulse Animation

This Arduino sketch creates a pulsating animation using Adafruit NeoPixel LEDs. Multiple pulses move along the LED strip, with customizable pulse color and background brightness.

## Hardware Requirements

- Programmable RGB LED strip
- Arduino board
- [Adafruit_NeoPixel](https://github.com/adafruit/Adafruit_NeoPixel) library

## Installation

1. Make sure you have the [Adafruit_NeoPixel](https://github.com/adafruit/Adafruit_NeoPixel) library installed.
2. Copy the provided sketch (`Pulse.ino`) to your Arduino IDE.
3. Connect your Adafruit NeoPixel LED strip to the specified pin (default is PIN 6).
4. Upload the sketch to your Arduino board.

## Configuration

- `LED_PIN`: Pin to which the NeoPixel strip is connected.
- `NUM_LEDS`: Number of LEDs in the strip.
- `PULSE_LENGTH`: Length of each pulsating pulse.
- `PULSE_COLOR_R`, `PULSE_COLOR_G`, `PULSE_COLOR_B`: RGB values for the pulse color.
- `MIN_PULSE_DELAY`, `MAX_PULSE_DELAY`: Minimum and maximum delay between pulse movements.
- `NUM_PULSES`: Number of simultaneous pulses.
- `BACKGROUND_BRIGHTNESS`: Background brightness (0-255 range) when pulses are not present. The default color is set to blue because i'm lazy; this can be changed on line 47.

## Usage

Run the uploaded sketch on your Arduino board.

Feel free to modify the configuration parameters to customize the animation to your liking.

