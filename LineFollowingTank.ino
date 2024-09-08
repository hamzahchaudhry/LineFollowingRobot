// define IR sensor pins
#define rightIR1 11
#define leftIR1 12
#define rightIR2 4
#define leftIR2 13

// define speeds
#define turningspeed1 225
#define turningspeed2 255
#define leftmotorpower 160
#define rightmotorpower 160

// define motor pins
int rightmotordriver = 6;
int rightmotor1 = 7;
int rightmotor2 = 8;
int leftmotordriver = 5;
int leftmotor1 = 9;
int leftmotor2 = 10;


void setup() {
  // set pin modes for motor and IR sensor pins
  pinMode(rightmotordriver, OUTPUT);
  pinMode(rightmotor1, OUTPUT);
  pinMode(rightmotor2, OUTPUT);
  pinMode(leftmotordriver, OUTPUT);
  pinMode(leftmotor1, OUTPUT);
  pinMode(leftmotor2, OUTPUT);

  pinMode(rightIR1, INPUT);
  pinMode(leftIR1, INPUT);
  pinMode(rightIR2, INPUT);
  pinMode(leftIR2, INPUT);

  // initialize motors to stop
  rotatemotor(0, 0);
}

void loop() {
  // read values from IR sensors
  int rightIR1value = digitalRead(rightIR1);
  int leftIR1value = digitalRead(leftIR1);
  int rightIR2value = digitalRead(rightIR2);
  int leftIR2value = digitalRead(leftIR2);

  // if no black line detected, go straight
  if (rightIR1value == LOW && leftIR1value == LOW && rightIR2value == LOW && leftIR2value == LOW) {
    rotatemotor(leftmotorpower, rightmotorpower);
  }
  // if right IR detects black line, turn right
  else if ((rightIR1value == LOW || rightIR2value == LOW) && (leftIR1value == HIGH || leftIR2value == HIGH)) {
    digitalWrite(leftmotor1, LOW);
    digitalWrite(leftmotor2, HIGH);
    analogWrite(leftmotordriver, turningspeed1);
    digitalWrite(rightmotor1, HIGH);
    digitalWrite(rightmotor2, LOW);
    analogWrite(rightmotordriver, turningspeed2);
  }
  // if left IR detects black line, turn left
  else if ((leftIR1value == LOW || leftIR2value == LOW) && (rightIR1value == HIGH || rightIR2value == HIGH)) {
    digitalWrite(leftmotor1, HIGH);
    digitalWrite(leftmotor2, LOW);
    analogWrite(leftmotordriver, turningspeed2);
    digitalWrite(rightmotor1, LOW);
    digitalWrite(rightmotor2, HIGH);
    analogWrite(rightmotordriver, turningspeed1);
  }
  // if both front IR sensors detect black line, stop
  else if (leftIR2value == LOW && rightIR2value == LOW) {
    rotatemotor(0, 0);
  }
  else {
    rotatemotor(0, 0);
  }
}

//function for going forward and backward
void rotatemotor(int rightmotorspeed, int leftmotorspeed) {
  // set direction of right motor
  if (rightmotorspeed > 0) {
    digitalWrite(rightmotor1, LOW);
    digitalWrite(rightmotor2, HIGH);
  } else if (rightmotorspeed > 0) {
    digitalWrite(rightmotor1, HIGH);
    digitalWrite(rightmotor2, LOW);
  } else {
    digitalWrite(rightmotor1, LOW);
    digitalWrite(rightmotor2, LOW);
  }

  // set direction of left
  if (leftmotorspeed > 0) {
    digitalWrite(leftmotor1, LOW);
    digitalWrite(leftmotor2, HIGH);
  } else if (leftmotorspeed > 0) {
    digitalWrite(leftmotor1, HIGH);
    digitalWrite(leftmotor2, LOW);
  } else {
    digitalWrite(leftmotor1, LOW);
    digitalWrite(leftmotor2, LOW);
  }
  analogWrite(rightmotordriver, (rightmotorspeed));
  analogWrite(leftmotordriver, (leftmotorspeed));
}