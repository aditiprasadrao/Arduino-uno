#include <Servo.h>

// Define pins for traffic light modules
const int red1 = 2, yellow1 = 3, green1 = 4;
const int red2 = 5, yellow2 = 6, green2 = 7;
const int red3 = 8, yellow3 = 9, green3 = 10;
const int red4 = 11, yellow4 = 12, green4 = 13;

// Define servo motor pins
const int servoPin1 = A0;
const int servoPin2 = A1;
const int servoPin3 = A2;
const int servoPin4 = A3;

// Create Servo objects
Servo gateServo1, gateServo2, gateServo3, gateServo4;

// Function to turn off all traffic lights
void turnOffAllLights() {
  digitalWrite(red1, HIGH); digitalWrite(yellow1, LOW); digitalWrite(green1, LOW);
  digitalWrite(red2, HIGH); digitalWrite(yellow2, LOW); digitalWrite(green2, LOW);
  digitalWrite(red3, HIGH); digitalWrite(yellow3, LOW); digitalWrite(green3, LOW);
  digitalWrite(red4, HIGH); digitalWrite(yellow4, LOW); digitalWrite(green4, LOW);
}

// Function to close all gates
void closeAllGates() {
  gateServo1.write(0);
  gateServo2.write(0);
  gateServo3.write(0);
  gateServo4.write(0);
}

// Function to activate a traffic signal and control the gate
void activateTrafficLight(int redPin, int yellowPin, int greenPin, Servo &servo) {
  turnOffAllLights();  // Ensure all other signals are red
  closeAllGates();     // Ensure all gates are closed

  // Turn on Green Light and Open Gate
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, HIGH);
  servo.write(90);  // Open gate
  delay(4000);      // Green light duration

  // Transition to Yellow Light and Close Gate
  digitalWrite(greenPin, LOW);
  digitalWrite(yellowPin, HIGH);
  servo.write(0);   // Close gate
  delay(2000);      // Yellow light duration

  // Turn on Red Light
  digitalWrite(yellowPin, LOW);
  digitalWrite(redPin, HIGH);
  delay(2000);      // Red light duration before switching to next signal
}

void setup() {
  // Set traffic light pins as OUTPUT
  pinMode(red1, OUTPUT); pinMode(yellow1, OUTPUT); pinMode(green1, OUTPUT);
  pinMode(red2, OUTPUT); pinMode(yellow2, OUTPUT); pinMode(green2, OUTPUT);
  pinMode(red3, OUTPUT); pinMode(yellow3, OUTPUT); pinMode(green3, OUTPUT);
  pinMode(red4, OUTPUT); pinMode(yellow4, OUTPUT); pinMode(green4, OUTPUT);

  // Attach servo motors to pins
  gateServo1.attach(servoPin1);
  gateServo2.attach(servoPin2);
  gateServo3.attach(servoPin3);
  gateServo4.attach(servoPin4);

  // Initialize all lights to red and all gates closed
  turnOffAllLights();
  closeAllGates();
}

void loop() {
  // Activate traffic signals one by one
  activateTrafficLight(red1, yellow1, green1, gateServo1);
  activateTrafficLight(red2, yellow2, green2, gateServo2);
  activateTrafficLight(red3, yellow3, green3, gateServo3);
  activateTrafficLight(red4, yellow4, green4, gateServo4);
}
