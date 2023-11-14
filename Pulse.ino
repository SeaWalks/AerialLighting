#include <Adafruit_NeoPixel.h>

#define LED_PIN 6
#define NUM_LEDS 144
//Define pulse length
#define PULSE_LENGTH 8
//Define pulse color (default blue)
#define PULSE_COLOR_R 0
#define PULSE_COLOR_G 0
#define PULSE_COLOR_B 255
//Define background color (default blue)
#define BG_COLOR_R 0
#define BG_COLOR_G 0
#define BG_COLOR_B 255
//Define pulse timing
#define MIN_PULSE_DELAY 50
#define MAX_PULSE_DELAY 50
#define NUM_PULSES 5
Adafruit_NeoPixel strip(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

struct Pulse {
  int position;
  int delay;
  unsigned long previousMillis;
};

Pulse pulses[NUM_PULSES];

void setup() {
  strip.begin();
  strip.show();  // Initialize all pixels to "off"

  // Initialize the pulses
  int gap = NUM_LEDS / NUM_PULSES;  // Calculate the gap between each pulse
  for (int i = 0; i < NUM_PULSES; i++) {
    pulses[i].position = i * gap;
    pulses[i].delay = random(MIN_PULSE_DELAY, MAX_PULSE_DELAY);
    pulses[i].previousMillis = 0;
  }
}

void loop() {
  // Update the positions of the pulses
  unsigned long currentMillis = millis();
  for (int i = 0; i < NUM_PULSES; i++) {
    if (currentMillis - pulses[i].previousMillis >= pulses[i].delay) {
      // Set the LEDs at the previous position to the background color
      for (int j = pulses[i].position; j < pulses[i].position + PULSE_LENGTH; j++) {
        strip.setPixelColor(j, strip.Color(BG_COLOR_R, BG_COLOR_G, BG_COLOR_B));
      }
      // Move the pulse position
      pulses[i].position++;
      // Check if the pulse reached the end, reset to the beginning
      if (pulses[i].position >= NUM_LEDS) {
        pulses[i].position = 0;
      }
      // Set the LEDs at the new position to the pulse color
      for (int j = pulses[i].position; j < pulses[i].position + PULSE_LENGTH; j++) {
        strip.setPixelColor(j, strip.Color(PULSE_COLOR_R, PULSE_COLOR_G, PULSE_COLOR_B));
      }
      strip.show();
      pulses[i].previousMillis = currentMillis;
      pulses[i].delay = random(MIN_PULSE_DELAY, MAX_PULSE_DELAY);
    }
  }
}
