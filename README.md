# 🚦 Arduino Smart City Traffic Light & Gate Control System

A creative and interactive **smart traffic light system** built with Arduino! This project simulates a real-world traffic intersection using **LED signals**, **servo-controlled gates**, and programmable logic — perfect for educational demos, smart city prototypes, and STEM learning.

---

## 📸 Overview

This project controls a **4-way traffic intersection** using:
- Traffic lights (Red, Yellow, Green)
- Servo motors for gates (to simulate barriers)
- Sequential logic to mimic realistic traffic flow

You can easily expand it into a **Miniature Smart City Simulation** by adding sensors, pedestrian buttons, emergency vehicle priority, or even AI-based traffic analysis.

---

## 🛠 Features

- 🔁 Automated traffic light cycling for 4 directions
- 🎮 Servo motors simulate gates that open with green light and close with yellow
- 🧠 Modular code: easy to integrate sensors, buttons, and new logic
- 📚 Perfect for classrooms, exhibitions, and smart city mock-ups

---

## 🔌 Hardware Components

- Arduino Uno / Mega / Nano
- 12x LEDs (4 red, 4 yellow, 4 green)
- 4x Servo motors
- Jumper wires
- Breadboard or custom PCB
- Resistors (220Ω for LEDs)
- Optional: IR/Ultrasonic sensors, push buttons, buzzer, LCD

---





## 💻 Code Logic Summary

The system cycles through four directions:
- Each direction turns **green**, gate opens (servo to 90°)
- Then turns **yellow**, gate closes (servo to 0°)
- Returns to **red** before switching to the next direction

```cpp
void activateTrafficLight(int redPin, int yellowPin, int greenPin, Servo &servo) {
  turnOffAllLights();
  closeAllGates();

  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, HIGH);
  servo.write(90);  // Open gate
  delay(4000);

  digitalWrite(greenPin, LOW);
  digitalWrite(yellowPin, HIGH);
  servo.write(0);  // Close gate
  delay(2000);

  digitalWrite(yellowPin, LOW);
  digitalWrite(redPin, HIGH);
  delay(2000);
}
