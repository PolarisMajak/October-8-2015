int sensorValues[5];
bool sensorOn[5];
bool lineFound[5];

int ledPin = 13;

int leftMotor1 = 6;
int leftMotor2= 7;
int rightMotor1 = 4;
int rightMotor2= 5;

void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  //led for sensors
  pinMode (leftMotor1, OUTPUT);
  pinMode(leftMotor2, OUTPUT);
  pinMode(rightMotor1, OUTPUT);
  pinMode(rightMotor2, OUTPUT);
  
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  
//  digitalWrite(leftEnabler, HIGH);
//  digitalWrite(rightEnabler, HIGH);
}

void leftForward(){
  digitalWrite(leftMotor1, HIGH);
  digitalWrite(leftMotor2, LOW);
}

void rightForward(){
  digitalWrite(rightMotor1, HIGH);
  digitalWrite(rightMotor2, LOW);
}



void goStraight(){
  leftForward();
  rightForward();
}


void loop() {
  // put your main code here, to run repeatedly:
  //taking sensor input
  for (int i = 0; i< 5; i++){
      
    sensorValues[i] = analogRead(i);
    //Serial.println(analogRead(i));
    if (sensorValues[i] < 500){
      sensorOn[i] = 0;
      lineFound[i] = 1;
    } else{
      sensorOn[i] = 1;
      lineFound[i] = 0;
    }
    
    if (lineFound[i])
      digitalWrite(i+9, HIGH);
     else
       digitalWrite(i+9, LOW);
  }
  
  if (lineFound[2]){   //go straight
    Serial.println("go straight.");
    goStraight();
  } 
  if (lineFound[1]){   //go  left
    Serial.println("go left.");
    
  } 
  
  
}
