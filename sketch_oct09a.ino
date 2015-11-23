
int led = 12;
int sensorValue[5];
bool foundLine[5];
void setup() {
  // put your setup code here, to run once:
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 1; i<6; i++)
  {    sensorValue[i] = analogRead(i);
  }
  for ( int i=1;i<6;i++)
  {   if(sensorValue[i]<500)
           { foundLine[i] = true;
             digitalWrite(i+7,HIGH);
           }
       else 
        { foundLine[i] = true;
          digitalWrite(i+7,HIGH);
        }
  }
}
