# 🤖 Arduino Pot-Controlled Servos

A hands-on demo that maps **four potentiometers** to **four SG90 servo motors** using an **Arduino Uno**.  
Rotate a knob → watch the matching servo move in real time. Perfect for learning the basics of analog input, PWM output, and multi-servo wiring.

---

## 🎯 What can Learn
- Read analog values with `analogRead()`  
- Map 0–1023 pot readings to 0–180 ° servo angles  
- Drive multiple servos simultaneously with Arduino’s `Servo.h`  
- Build clean, shared power/ground rails on a breadboard  
- Record and embed demo media in a GitHub project  

---

## 🔧 Components
| Qty | Part                               |
|----:|------------------------------------|
| 1   | Arduino Uno (or compatible)        |
| 4   | SG90 micro-servo motors            |
| 4   | 10 kΩ potentiometers               |
| 1   | Breadboard + jumper wires          |
| 1   | External 5 V / 2 A supply <sup>＊</sup> |

<sup>＊ USB power is fine for quick tests, but an external supply is safer when all servos move together.</sup>

---

## ⚙️ How It Works
1. Each potentiometer is wired to an **analog pin** (`A0 … A3`).  
2. The matching servo signal goes to a **PWM-capable digital pin** (`3, 5, 6, 9`).  
3. In the loop, we:
   ```cpp
   int potVal = analogRead(A0);             // 0–1023
   int angle  = map(potVal, 0, 1023, 0, 180);
   servo1.write(angle);                     // set servo
    ```
4. Repeat for all four channels every ~20 ms → buttery-smooth motion.

---

## 🚀 Getting Started
Hardware

Follow the media/wiring.png diagram.

Tie all GNDs together (Arduino + external 5 V if used).

Plug the external 5 V into the servos’ Vcc rail.

Software

Open Arduino IDE → File ▸ Examples ▸ Servo ▸ Sweep (as reference).

Load src/ServoPotControl.ino from this repo.

Select your board/port → Upload.

Twist a knob and enjoy the immediate servo response!
