enum {GO_AHEAD, GO_BACK, GO_RIGHT, STOP, GO_POWERLEFT, GO_POWERRIGHT};
//Left Motor
const int controlPin1 = 2;
const int controlPin2 = 3;
const int enablePin1 =6;
//Right Motor
const int controlPin3 = 4;
const int controlPin4 = 5;
const int enablePin2 =7;

// Left UltraSonic Sensor
const int trigPin = 13; //GREEN
const int echoPin = 12; //BLUE
// Right UltraSonic Sensor;
const int btrigPin = 3; //GREEN 
const int bechoPin =2;//BLUE

void setup() {
  // put your setup code here, to run once:
  //Ultrasonic 1
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  //Ultrasonic 2

  pinMode(btrigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(bechoPin, INPUT); // Sets the echoPin as an Input
  //Left Motor
  pinMode(controlPin1, OUTPUT);
  pinMode(controlPin2, OUTPUT);
  pinMode(enablePin1, OUTPUT);
  //Right Motor
  pinMode(controlPin3, OUTPUT);
  pinMode(controlPin4, OUTPUT);
  pinMode(enablePin2, OUTPUT);

  
  digitalWrite(enablePin1,LOW);
  digitalWrite(enablePin2,LOW);
  Serial.begin(9600); // Starts the serial communication
}

void loop() {
  // put your main code here, to run repeatedly:
  byte goDirection;
  int duration, distance;
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  

  Serial.print("Distance L: ");
  Serial.println(distance);
  int bduration, bdistance;
  digitalWrite(btrigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(btrigPin, LOW);
  bduration = pulseIn(bechoPin, HIGH);
  bdistance = (bduration/2) / 29.1;
  

  Serial.print("Distance R: ");
  Serial.println(bdistance);



switch (goDirection)
  {
    case GO_AHEAD: 
      Serial.println("Go ahead");
      digitalWrite(enablePin1,HIGH);
      digitalWrite(enablePin2,HIGH);
      digitalWrite(controlPin1, HIGH);
      digitalWrite(controlPin2, LOW);
      digitalWrite(controlPin3, HIGH);
      digitalWrite(controlPin4, LOW);
      analogWrite(enablePin1, 255);
      analogWrite(enablePin2, 255);
      delay(10);
      break;
    case STOP:
      Serial.println("No line detected - STOP!");
      analogWrite(enablePin1, 0);
      analogWrite(enablePin2, 0);
      delay(10);
      break;
    case GO_BACK:
      Serial.println("No line detected - GO BACK!");
      Serial.println("Go ahead");
      digitalWrite(enablePin1,HIGH);
      digitalWrite(enablePin2,HIGH);
      digitalWrite(controlPin1, LOW);
      digitalWrite(controlPin2, HIGH);
      digitalWrite(controlPin3, LOW);
      digitalWrite(controlPin4, HIGH);
      analogWrite(enablePin1, 255);
      analogWrite(enablePin2, 255);
      delay(10);
      break;
  }  

}
