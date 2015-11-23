int led = 13; //cause it will be the output 
int sensorValue[5];
bool foundLine[5];
bool sensorOn[5];
int leftMotor1 = 4 ;
int leftMotor2 = 5 ;
int rightMotor1 = 6 ;
int rightMotor2 = 7 ;
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  //pinMode(led,OUTPUT); // led=13 , 13 will be here 
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT); 
  pinMode(6,OUTPUT); 
  pinMode(7,OUTPUT); 
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT); 
  pinMode(11,OUTPUT); 
  pinMode(12,OUTPUT); 
  pinMode(13,OUTPUT); 
}
void goStraight(){
  leftForward();
  rightForward();
}
void goLeft(){
  leftForward();
  rightForward();
}
void rightForward(){
  digitalWrite(rightMotor1,HIGH);
  digitalWrite(rightMotor2,LOW);
}
void leftForward(){
  digitalWrite(leftMotor1,HIGH);
  digitalWrite(leftMotor2,LOW);
}
void doNothing(){
  digitalWrite(rightMotor1,HIGH);
  digitalWrite(rightMotor2,HIGH);
  digitalWrite(leftMotor1,HIGH);
  digitalWrite(leftMotor2,HIGH);
}
void loop() {
  // put your main code here, to run repeatedly:
  // LED will be on here, to make it on, we have to supply 5v
 
    /*digitalWrite(led,HIGH); // high value will be set on LED
   delay(1000);
   digitalWrite(led,LOW);
   delay(1000);*/
  //int sensorValue=analogRead(A0); // we connected with A0pin    
// value will be of 0-1023
for(int i=0;i<5;i++)
{ 
  sensorValue[i]= analogRead(i);
}

 for(int i=0;i<5;i++){
   if (sensorValue[i]< 500)
   {
     sensorOn[i] = false;
   foundLine[i]=true;
  //digitalWrite(led,HIGH);
  digitalWrite(i+9,HIGH);
 }
else{ sensorOn[i]=true;
  foundLine[i]=false;
  //digitalWrite(led,LOW);
   digitalWrite(i+9,LOW);
 }
 if(foundLine[2]){
   Serial.print("Go Straight");
   goStraight();
 }
 else{
   doNothing() ;
 }
 if(foundLine[1]){
   Serial.print("Go left");
   goLeft();
 }
 }
}
