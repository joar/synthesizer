/*

THIS DOC BE DEPRECATED
  Analog Input
 Demonstrates analog input by reading an analog sensor on analog pin 0 and
 turning on and off a light emitting diode(LED)  connected to digital pin 13. 
 The amount of time the LED will be on and off depends on
 the value obtained by analogRead(). 
 
 The circuit:
 * Potentiometer attached to analog input 0
 * center pin of the potentiometer to the analog pin
 * one side pin (either one) to ground
 * the other side pin to +5V
 * LED anode (long leg) attached to digital output 13
 * LED cathode (short leg) attached to ground
 
 * Note: because most Arduinos have a built-in LED attached 
 to pin 13 on the board, the LED is optional.
 
 
 Created by David Cuartielles
 modified 30 Aug 2011
 By Tom Igoe
 
 This example code is in the public domain.
 
 http://arduino.cc/en/Tutorial/AnalogInput
 
 */

int sensorPin = A0;    // select the input pin for the potentiometer
int ledPin = 12;      // select the pin for the LED
int buttonPin = 2;
int sensorValue = 0;  // variable to store the value coming from the sensor
float currentHertz = 261.63;
float tones[9] = {
  146.83,
  174.61,
  196.0,
  220.0,
  261.63,
  293.66,
  349.23,
  392.0,
  440.0};
float potNormalized = 0.0;
int potMax = 0.0;

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(38400);
}

float hertz_to_delay(float hertz) {
  // herts: 261.63
  float floatDelay = (1 / hertz) * 1000;
  return floatDelay;
}

void loop() {
  if (digitalRead(buttonPin) == HIGH) {
    return;
  }
  
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  
  potNormalized = (sensorValue - 62.0) / (1019.0 - 62.0);
  
  int toneIndex = (int)round(potNormalized * 9);
  
  Serial.println(toneIndex);
 
  currentHertz = tones[toneIndex];
    
  // turn the ledPin on
  digitalWrite(ledPin, HIGH);
  
  // stop the program for <sensorValue> milliseconds:
  delay(1);
  
  // turn the ledPin off:
  digitalWrite(ledPin, LOW);
  
  delay(hertz_to_delay(currentHertz));
}
