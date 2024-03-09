#define TRIG_FRONT 2  
#define ECHO_FRONT 3  
#define TRIG_RIGHT 4  
#define ECHO_RIGHT 5  
#define TRIG_LEFT 6   
#define ECHO_LEFT 7   
#define TRIG_BACK 8  
#define ECHO_BACK 9   

#define MOTOR_FRONT 10 
#define MOTOR_RIGHT 11 
#define MOTOR_LEFT 12  
#define MOTOR_BACK 13 

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_FRONT, OUTPUT);
  pinMode(ECHO_FRONT, INPUT);
  pinMode(TRIG_RIGHT, OUTPUT);
  pinMode(ECHO_RIGHT, INPUT);
  pinMode(TRIG_LEFT, OUTPUT);
  pinMode(ECHO_LEFT, INPUT);
  pinMode(TRIG_BACK, OUTPUT);
  pinMode(ECHO_BACK, INPUT);

  pinMode(MOTOR_FRONT, OUTPUT);
  pinMode(MOTOR_RIGHT, OUTPUT);
  pinMode(MOTOR_LEFT, OUTPUT);
  pinMode(MOTOR_BACK, OUTPUT);
}

void loop() {
  int distanceFront = getDistance(TRIG_FRONT, ECHO_FRONT);
  int distanceRight = getDistance(TRIG_RIGHT, ECHO_RIGHT);
  int distanceLeft = getDistance(TRIG_LEFT, ECHO_LEFT);
  int distanceBack = getDistance(TRIG_BACK, ECHO_BACK);

  if (distanceFront < 20) {
    activateMotor(MOTOR_FRONT);
  } else {
    deactivateMotor(MOTOR_FRONT);
  }

  if (distanceRight < 20) {
    activateMotor(MOTOR_RIGHT);
  } else {
    deactivateMotor(MOTOR_RIGHT);
  }

  if (distanceLeft < 20) {
    activateMotor(MOTOR_LEFT);
  } else {
    deactivateMotor(MOTOR_LEFT);
  }

  if (distanceBack < 20) {
    activateMotor(MOTOR_BACK);
  } else {
    deactivateMotor(MOTOR_BACK);
  }
}

int getDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  return pulseIn(echoPin, HIGH) * 0.034 / 2;
}

void activateMotor(int motorPin) {
  digitalWrite(motorPin, HIGH);
}

void deactivateMotor(int motorPin) {
  digitalWrite(motorPin, LOW);
}
