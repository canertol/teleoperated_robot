int solenoidPin = 9;                    //This is the output pin on the Arduino
int r = 1;
void setup() 
{
  Serial.begin(9600);
  pinMode(solenoidPin, OUTPUT);          //Sets that pin as an output
}

void loop() 
{
  if(Serial.available()){ 
    r = r * (Serial.read() - '0');
    if(r==1)
    { Serial.println(" K I C K L E N D I N I Z !");
      digitalWrite(solenoidPin, HIGH);      //Switch Solenoid ON
      delay(200);                          //Wait 1 Second
      digitalWrite(solenoidPin, LOW);       //Switch Solenoid OFF
      delay(1000);     
    }//Wait 1 Second
  }
}
