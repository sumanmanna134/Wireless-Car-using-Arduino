
#include <AFMotor.h> 
#define trigPin A4 
#define echoPin A5
AF_DCMotor left_motor1(1, MOTOR12_8KHZ);
AF_DCMotor left_motor2(2, MOTOR12_8KHZ);
AF_DCMotor right_motor1(3, MOTOR12_8KHZ);
AF_DCMotor right_motor2(4,MOTOR12_8KHZ); 
int tim;

String readString;

void setup() {
  Serial.begin(9600);
  right_motor1.setSpeed(250);
  right_motor2.setSpeed(250);
  left_motor1.setSpeed(250);
  left_motor2.setSpeed(250);
   pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  while(Serial.available()){
    delay(50);
    char c=Serial.read();
    readString+=c;
  }
  if(readString.length()>0){
    Serial.println(readString);
    if (readString =="FORWARD"){
      right_motor1.run (FORWARD);
      right_motor2.run (FORWARD);
      left_motor1.run (FORWARD);
      left_motor2.run (FORWARD);
      Serial.print("Running Forward");
      delay(500);
    }
    else if (readString =="BACKWARD"){
       right_motor1.run (BACKWARD);
      right_motor2.run (BACKWARD);
      left_motor1.run (BACKWARD);
      left_motor2.run (BACKWARD);
      Serial.print("Running backward");
      delay(500);
    }
    else if (readString =="LEFT"){
       right_motor1.run (FORWARD);
      right_motor2.run (FORWARD);
      left_motor1.run (BACKWARD);
      left_motor2.run (BACKWARD);
      Serial.print("Running left");
      delay(500);
    }
    else if (readString =="RIGHT"){
       right_motor1.run (BACKWARD);
      right_motor2.run (BACKWARD);
      left_motor1.run (FORWARD);
      left_motor2.run (FORWARD);
      Serial.print("running right");
      delay(500);
    }
    else if(readString=="OBS")
    {
      
       long duration, distance; 
       Serial.print(tim);
       Serial.print("\n");
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);

  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  for(tim=5000; tim>0 ; tim--)
      {
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) 
  if (distance < 2 ){ 
   Serial.println ("Close Obstacle detected!" );
  
   Serial.println ("Obstacle Details:");
   Serial.print ("Distance From Robot is " );
   Serial.print ( distance);
   Serial.print ( " CM!");

   Serial.println (" Turning !");
    right_motor1.run (FORWARD);
      right_motor2.run (FORWARD);
      left_motor1.run (BACKWARD);
      left_motor2.run (BACKWARD);  
}
  else {
    
      Serial.println ("No obstacle detected. going forward");
      right_motor1.run (FORWARD);
      right_motor2.run (FORWARD);
      left_motor1.run (FORWARD);
      left_motor2.run (FORWARD);
      Serial.print("Running Forward");
  }
      }
      Serial.print("End");
    }
    else if(readString =="STOP"){
      right_motor1.run (RELEASE);
      right_motor2.run (RELEASE);
      left_motor1.run (RELEASE);
      left_motor2.run (RELEASE);
      delay(500);
    }
    else
    {
      Serial.print("Wrong key Detected !! Car stopped");
      right_motor1.run (RELEASE);
      right_motor2.run (RELEASE);
      left_motor1.run (RELEASE);
      left_motor2.run (RELEASE);
      delay(500);
    }

    readString="";
  }
}
