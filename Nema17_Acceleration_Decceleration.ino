
#include <AccelStepper.h>
// Define the stepper motor and the pins that is connected to
AccelStepper stepper1(1, 2, 5); // (Typeof driver: with 2 pins, STEP, DIR)

void setup() {
  stepper1.setMaxSpeed(800); // Set maximum speed value (Optimal) - Beyond 1000 motor stops
  stepper1.setAcceleration(800); // Set acceleration value (Optimal) - Noted some difference interms of noise.
  stepper1.setCurrentPosition(0); // Set the current position to 0 steps - Will have to research futher.
}

void loop() {

  stepper1.moveTo(2400); // Set desired move: 800 steps (in quater-step resolution that's one rotation)
  stepper1.runToPosition(); // Moves the motor to target position w/ acceleration/ deceleration and it blocks until is in position
  delay(200);
  stepper1.moveTo(0); // Set desired move: 800 steps (in quater-step resolution that's one rotation)
  stepper1.runToPosition(); // Moves the motor to target position w/ acceleration/ deceleration and it blocks until is in position
  delay(200);
  
// Move back to position 0, using run() which is non-blocking - both motors will move at the same time
//  stepper1.moveTo(0);
//  while (stepper1.currentPosition() != 0) {
//    stepper1.run();  // Move or step the motor implementing accelerations and decelerations to achieve the target position. Non-blocking function
//  }

// Yet to be convinced to use the non blocking mode which is still blocking since we loop here till our condition is complete. Will simply confirm by a blink led operation afterwards.
}
