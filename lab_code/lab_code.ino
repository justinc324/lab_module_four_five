#include <Stepper.h>
#include <ESP32Servo.h> 

// change this to the number of steps on your motor
#define STEPS 2038
#define SERVO 14

Servo myservo;

int pos = 0;



// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
// attached to
Stepper stepper(STEPS, 15, 2, 0, 4);

void setup()
{
   myservo.attach(SERVO);
}

void loop()
{
  // set the speed of the motor to 30 RPMs
  stepper.setSpeed(10);
  // move a number of steps equal to the change in the
  stepper.step(2038);

  // go 10 degrees
   myservo.write(pos + 10);
   pos += 10;              

  if (pos >= 180) {
    myservo.write(0);
    pos = 0;
    delay(15);
   }                    // waits 15ms for the servo to reach the position
}
