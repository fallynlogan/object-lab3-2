#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// pin that the strip is connected to
#define PIN 8

Adafruit_NeoPixel strip = Adafruit_NeoPixel(5, PIN, NEO_GRB + NEO_KHZ800);

// define button pins
const int button1 = 7;
const int button2 = 4;

int button1State = 0; // changing from 0 and 1 (digital)
int button2State = 0; // changing from 0 and 1 (digital)

void setup() {
  // initialize the strip
  strip.begin();
  // sets all pixels to 'off'
  strip.show(); 
  // initialize buttons as input
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);

  Serial.begin(9600);
}

void loop() {
  button1State = digitalRead(button1);
  button2State = digitalRead(button2);
  
  //debugging
  Serial.print("button1: ");
  Serial.print(button1State);
  Serial.print("       button2: ");
  Serial.println(button2State);

  // if button 1 is pressed, turn LEDs magenta from bottom to top
  if((button1State == HIGH) && (button2State == LOW)){
    for(uint16_t i = 0; i < strip.numPixels(); i++){
      strip.setPixelColor(i, 255, 10, 255);
      strip.show();
      delay(500);
    }
  }
  
  // if button 2 is pressed, turn LEDs teal from bottom to top
  else if((button2State == HIGH) && (button1State == LOW)){
    for(uint16_t i = 0; i < strip.numPixels(); i++){
      strip.setPixelColor(i, 0, 255, 255);
      strip.show();
      delay(500);
    }
  }
  
  // if both are pressed, turn LEDs lavender from bottom to top
  else if((button1State == HIGH) && (button2State == HIGH)){
    for(uint16_t i = 0; i < strip.numPixels(); i++){
      strip.setPixelColor(i, 229, 102, 255);
      strip.show();
      delay(500);
    }
  }
  
  // else, all lights are off
  else if((button1State == LOW) && (button2State == LOW)){
    for(uint16_t i = 0; i < strip.numPixels(); i++){
      strip.setPixelColor(i, 0, 0, 0);
      strip.show();
      delay(500);
    }   
  }
}
