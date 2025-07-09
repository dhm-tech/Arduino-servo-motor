#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

unsigned long startTime;
int sweepDelay = 15;
bool sweepDone = false;

void setup() {
  servo1.attach(3);  // Connect to appropriate pins
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(9);

  startTime = millis();
}

void loop() {
  if (!sweepDone) {
    // Sweep for 2 seconds
    if (millis() - startTime < 2000) {
      for (int pos = 0; pos <= 180; pos += 1) {
        servo1.write(pos);
        servo2.write(pos);
        servo3.write(pos);
        servo4.write(pos);
        delay(sweepDelay);
      }
      for (int pos = 180; pos >= 0; pos -= 1) {
        servo1.write(pos);
        servo2.write(pos);
        servo3.write(pos);
        servo4.write(pos);
        delay(sweepDelay);
      }
    } else {
      sweepDone = true;
      // Hold all servos at 90°
      servo1.write(90);
      servo2.write(90);
      servo3.write(90);
      servo4.write(90);
    }
  }
}
