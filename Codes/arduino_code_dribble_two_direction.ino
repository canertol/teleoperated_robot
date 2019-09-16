#define PI 3.1415926535897932384626433832795
// defines sensor pin numbers
const int trigPin1 = 32;
const int echoPin1 = 33;
const int trigPin2 = 34;
const int echoPin2 = 35;
const int trigPin3 = 36;
const int echoPin3 = 37;
const int trigPin4 = 38;
const int echoPin4 = 39;
// define motor pin numbers
const int m1a = 22;
const int m1b = 23;
const int m2a = 24;
const int m2b = 25;
const int m3a = 26;
const int m3b = 27;
const int m4a = 28;
const int m4b = 29;
const int pwm1 = 2;
const int pwm2 = 3;
const int pwm3 = 4;
const int pwm4 = 5;
// define kicker pin number
const int kick = 42;
// define dribble pin number
const int drib = 7;
// define dribble enable pin number
const int driben1 = 50;
const int driben2 = 51;

// defines variables
long duration1;
long duration2;
long duration3;
long duration4;
int distance1;
int distance2;
int distance3;
int distance4;
int prev1 = 0;
int prev2 = 0;
int prev3 = 0;
int prev4 = 0;
int a,b;
int raspberry_out[2];
int theta = -1;
int mag = -1;
int ind = -1;
int index = -1;
int value = -1;
int flag = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
  pinMode(trigPin2, OUTPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(trigPin4, OUTPUT);
  
  pinMode(echoPin1, INPUT); // Sets the echoPin as an Input
  pinMode(echoPin2, INPUT);
  pinMode(echoPin3, INPUT);
  pinMode(echoPin4, INPUT);

  pinMode(m1a, OUTPUT); // Sets motor pins as Output
  pinMode(m1b, OUTPUT);
  pinMode(m2a, OUTPUT);
  pinMode(m2b, OUTPUT);
  pinMode(m3a, OUTPUT);
  pinMode(m3b, OUTPUT);
  pinMode(m4a, OUTPUT);
  pinMode(m4b, OUTPUT);

  //pinMode(drib, OUTPUT); // Sets dribble pin as Output
  pinMode(driben1, OUTPUT);
  pinMode(driben2, OUTPUT);

  pinMode(kick, OUTPUT); // Set kicker pin as Output  
  //pinMode(pwm1, OUTPUT);
  //pinMode(pwm2, OUTPUT);
  //pinMode(pwm3, OUTPUT);
  //pinMode(pwm4, OUTPUT);
}

void loop() { 
  // put your main code here, to run repeatedly:
  int data = 0;
  int stick_data = 0;
  // set dribble input pins
  if(stick_data == 1)
  {
    digitalWrite( driben1, HIGH); 
    digitalWrite( driben2, LOW);  
  }
  if(stick_data == 2)
  {
    digitalWrite( driben1, LOW);
    digitalWrite( driben2, HIGH);
  }
  // send sensor data
  sensors(trigPin1,trigPin2,trigPin3, trigPin4, echoPin1, echoPin2, echoPin3, echoPin4 );
 
  while (Serial.available() > 0)
  {
    //analogWrite(pwm1, 50);
    //analogWrite(pwm2, 50);
    //analogWrite(pwm3, 50);
    //analogWrite(pwm4, 50);

    int pwm11 = 255;
    int pwm22 = 255;
    int pwm33 = 255;
    int pwm44 = 255;
    int pwm11s = 150;
    int pwm22s = 150;
    int pwm33s = 150;
    int pwm44s = 150;

    data = Serial.read();

    if(ind < 0){
      ind = (int)data; //indicator, first element of data
      continue;
    }
    
   // data = int(data);
   // Serial.println(data);
   
    if(ind == 1 || ind == 0){
      
      if(theta < 0){
      theta = (int)data;
      //Serial.println(theta);
      continue;
      }

      if(mag < 0){
      mag = (int)data;
      //Serial.println(mag);
      }
    }
    
    if(ind == '2'){
      
      if(index < 0){
      index = (int)data;
      //Serial.println(index);
      continue;
      }

      if(value < 0){
      value = (int)data;
      //Serial.println(value);
      }

      if( index == 6 ){
          if (value == 1)
            digitalWrite( drib, HIGH);
          else if (value == 0)
            digitalWrite( drib, LOW);
      }
      else if (index == 'A'){
          if (value == 'B'){
            digitalWrite( kick, HIGH);
            flag = 1;
            Serial.println("high");
            }
          else if (value == 'C'){
            digitalWrite( kick, LOW);
            Serial.println("low");
            flag = 0;
            }            
        }
    }    
    Serial.println(ind);
    Serial.println(index);
    Serial.println(value);
    
    if(ind == 0)
       stick_data = acibolge(theta, mag);
       //Serial.write(stick_data); 
    else if(ind == 1){
       theta = (theta * 2 * PI) / 127; // convert into the RAD        
       if(mag * cos(theta) > 50){
        stick_data = 10;
        analogWrite(drib, 0);}
       else if(mag * cos(theta) < -50){
        stick_data = 5;
        analogWrite(drib, 0); }
       else if(mag * sin(theta) > 50){
        stick_data = 0;
        analogWrite(drib, 0); 
        digitalWrite( kick, HIGH);
        delay(200);
        digitalWrite( kick, LOW);
       }
       else if(mag * sin(theta) < -50){
        stick_data = 0;
        analogWrite(drib, 155);        
       }
       else analogWrite(drib, 0); 
    }
        
    if (stick_data == 1)
    { 
      analogWrite(pwm1, pwm11);
      analogWrite(pwm2, pwm22);
      analogWrite(pwm3, pwm33);
      analogWrite(pwm4, pwm44);
      digitalWrite(m1a, HIGH);
      digitalWrite(m1b, LOW);
      digitalWrite(m2a, LOW);
      digitalWrite(m2b, LOW);
      digitalWrite(m3a, LOW);
      digitalWrite(m3b, HIGH);
      digitalWrite(m4a, LOW);
      digitalWrite(m4b, LOW);
    }

    if (stick_data == 11)
    { 
      analogWrite(pwm1, pwm11s);
      analogWrite(pwm2, pwm22s);
      analogWrite(pwm3, pwm33s);
      analogWrite(pwm4, pwm44s);
      digitalWrite(m1a, HIGH);
      digitalWrite(m1b, LOW);
      digitalWrite(m2a, LOW);
      digitalWrite(m2b, LOW);
      digitalWrite(m3a, LOW);
      digitalWrite(m3b, HIGH);
      digitalWrite(m4a, LOW);
      digitalWrite(m4b, LOW);
    }
    
    if (stick_data == 2)
    {
      analogWrite(pwm1, pwm11);
      analogWrite(pwm2, pwm22);
      analogWrite(pwm3, pwm33);
      analogWrite(pwm4, pwm44);
      digitalWrite(m1a, HIGH);
      digitalWrite(m1b, LOW);
      digitalWrite(m2a, LOW);
      digitalWrite(m2b, HIGH);
      digitalWrite(m3a, LOW);
      digitalWrite(m3b, HIGH);
      digitalWrite(m4a, HIGH);
      digitalWrite(m4b, LOW);
    }  

    if (stick_data == 12)
    {
      analogWrite(pwm1, pwm11s);
      analogWrite(pwm2, pwm22s);
      analogWrite(pwm3, pwm33s);
      analogWrite(pwm4, pwm44s);
      digitalWrite(m1a, HIGH);
      digitalWrite(m1b, LOW);
      digitalWrite(m2a, LOW);
      digitalWrite(m2b, HIGH);
      digitalWrite(m3a, LOW);
      digitalWrite(m3b, HIGH);
      digitalWrite(m4a, HIGH);
      digitalWrite(m4b, LOW);
    }  
    
    if (stick_data == 3)
    {
      analogWrite(pwm1, pwm11);
      analogWrite(pwm2, pwm22);
      analogWrite(pwm3, pwm33);
      analogWrite(pwm4, pwm44);
      digitalWrite(m1a, LOW);
      digitalWrite(m1b, LOW);
      digitalWrite(m2a, LOW);
      digitalWrite(m2b, HIGH);
      digitalWrite(m3a, LOW);
      digitalWrite(m3b, LOW);
      digitalWrite(m4a, HIGH);
      digitalWrite(m4b, LOW);
    }

    if (stick_data == 13)
    {
      analogWrite(pwm1, pwm11s);
      analogWrite(pwm2, pwm22s);
      analogWrite(pwm3, pwm33s);
      analogWrite(pwm4, pwm44s);
      digitalWrite(m1a, LOW);
      digitalWrite(m1b, LOW);
      digitalWrite(m2a, LOW);
      digitalWrite(m2b, HIGH);
      digitalWrite(m3a, LOW);
      digitalWrite(m3b, LOW);
      digitalWrite(m4a, HIGH);
      digitalWrite(m4b, LOW);
    }
    
    if (stick_data == 4)
    {
      analogWrite(pwm1, pwm11);
      analogWrite(pwm2, pwm22);
      analogWrite(pwm3, pwm33);
      analogWrite(pwm4, pwm44);
      digitalWrite(m1a, HIGH);
      digitalWrite(m1b, LOW);
      digitalWrite(m2a, HIGH);
      digitalWrite(m2b, LOW);
      digitalWrite(m3a, LOW);
      digitalWrite(m3b, HIGH);
      digitalWrite(m4a, LOW);
      digitalWrite(m4b, HIGH);
    }  

    if (stick_data == 14)
    {
      analogWrite(pwm1, pwm11s);
      analogWrite(pwm2, pwm22s);
      analogWrite(pwm3, pwm33s);
      analogWrite(pwm4, pwm44s);
      digitalWrite(m1a, HIGH);
      digitalWrite(m1b, LOW);
      digitalWrite(m2a, HIGH);
      digitalWrite(m2b, LOW);
      digitalWrite(m3a, LOW);
      digitalWrite(m3b, HIGH);
      digitalWrite(m4a, LOW);
      digitalWrite(m4b, HIGH);
    }  
    
    if (stick_data == 5)
    {
      analogWrite(pwm1, pwm11);
      analogWrite(pwm2, pwm22);
      analogWrite(pwm3, pwm33);
      analogWrite(pwm4, pwm44);
      digitalWrite(m1a, HIGH);
      digitalWrite(m1b, LOW);
      digitalWrite(m2a, LOW);
      digitalWrite(m2b, HIGH);
      digitalWrite(m3a, HIGH);
      digitalWrite(m3b, LOW);
      digitalWrite(m4a, LOW);
      digitalWrite(m4b, HIGH);
    }
    
    if (stick_data == 6)
    {
      analogWrite(pwm1, pwm11);
      analogWrite(pwm2, pwm22);
      analogWrite(pwm3, pwm33);
      analogWrite(pwm4, pwm44);
      digitalWrite(m1a, LOW);
      digitalWrite(m1b, HIGH);
      digitalWrite(m2a, LOW);
      digitalWrite(m2b, HIGH);
      digitalWrite(m3a, HIGH);
      digitalWrite(m3b, LOW);
      digitalWrite(m4a, HIGH);
      digitalWrite(m4b, LOW);
    }  

    if (stick_data == 16)
    {
      analogWrite(pwm1, pwm11s);
      analogWrite(pwm2, pwm22s);
      analogWrite(pwm3, pwm33s);
      analogWrite(pwm4, pwm44s);
      digitalWrite(m1a, LOW);
      digitalWrite(m1b, HIGH);
      digitalWrite(m2a, LOW);
      digitalWrite(m2b, HIGH);
      digitalWrite(m3a, HIGH);
      digitalWrite(m3b, LOW);
      digitalWrite(m4a, HIGH);
      digitalWrite(m4b, LOW);
    }  
    
    if (stick_data == 7)
    {
      analogWrite(pwm1, pwm11);
      analogWrite(pwm2, pwm22);
      analogWrite(pwm3, pwm33);
      analogWrite(pwm4, pwm44);
      digitalWrite(m1a, LOW);
      digitalWrite(m1b, LOW);
      digitalWrite(m2a, HIGH);
      digitalWrite(m2b, LOW);
      digitalWrite(m3a, LOW);
      digitalWrite(m3b, LOW);
      digitalWrite(m4a, LOW);
      digitalWrite(m4b, HIGH);
    }

    if (stick_data == 17)
    {
      analogWrite(pwm1, pwm11s);
      analogWrite(pwm2, pwm22s);
      analogWrite(pwm3, pwm33s);
      analogWrite(pwm4, pwm44s);
      digitalWrite(m1a, LOW);
      digitalWrite(m1b, LOW);
      digitalWrite(m2a, HIGH);
      digitalWrite(m2b, LOW);
      digitalWrite(m3a, LOW);
      digitalWrite(m3b, LOW);
      digitalWrite(m4a, LOW);
      digitalWrite(m4b, HIGH);
    }
    
    if (stick_data == 8)
    {
      analogWrite(pwm1, pwm11);
      analogWrite(pwm2, pwm22);
      analogWrite(pwm3, pwm33);
      analogWrite(pwm4, pwm44);
      digitalWrite(m1a, LOW);
      digitalWrite(m1b, HIGH);
      digitalWrite(m2a, HIGH);
      digitalWrite(m2b, LOW);
      digitalWrite(m3a, HIGH);
      digitalWrite(m3b, LOW);
      digitalWrite(m4a, LOW);
      digitalWrite(m4b, HIGH);
    } 

    if (stick_data == 18)
    {
      analogWrite(pwm1, pwm11s);
      analogWrite(pwm2, pwm22s);
      analogWrite(pwm3, pwm33s);
      analogWrite(pwm4, pwm44s);
      digitalWrite(m1a, LOW);
      digitalWrite(m1b, HIGH);
      digitalWrite(m2a, HIGH);
      digitalWrite(m2b, LOW);
      digitalWrite(m3a, HIGH);
      digitalWrite(m3b, LOW);
      digitalWrite(m4a, LOW);
      digitalWrite(m4b, HIGH);
    } 
    
    if (stick_data == 9)
    {
      analogWrite(pwm1, pwm11);
      analogWrite(pwm2, pwm22);
      analogWrite(pwm3, pwm33);
      analogWrite(pwm4, pwm44);
      digitalWrite(m1a, LOW);
      digitalWrite(m1b, HIGH);
      digitalWrite(m2a, LOW);
      digitalWrite(m2b, LOW);
      digitalWrite(m3a, HIGH);
      digitalWrite(m3b, LOW);
      digitalWrite(m4a, LOW);
      digitalWrite(m4b, LOW);
    }

    if (stick_data == 19)
    {
      analogWrite(pwm1, pwm11s);
      analogWrite(pwm2, pwm22s);
      analogWrite(pwm3, pwm33s);
      analogWrite(pwm4, pwm44s);
      digitalWrite(m1a, LOW);
      digitalWrite(m1b, HIGH);
      digitalWrite(m2a, LOW);
      digitalWrite(m2b, LOW);
      digitalWrite(m3a, HIGH);
      digitalWrite(m3b, LOW);
      digitalWrite(m4a, LOW);
      digitalWrite(m4b, LOW);
    }
    
    if (stick_data == 10)
    {
      analogWrite(pwm1, pwm11);
      analogWrite(pwm2, pwm22);
      analogWrite(pwm3, pwm33);
      analogWrite(pwm4, pwm44);
      digitalWrite(m1a, LOW);
      digitalWrite(m1b, HIGH);
      digitalWrite(m2a, HIGH);
      digitalWrite(m2b, LOW);
      digitalWrite(m3a, LOW);
      digitalWrite(m3b, HIGH);
      digitalWrite(m4a, HIGH);
      digitalWrite(m4b, LOW);
    }
    
    if (stick_data == 0)
    {
      analogWrite(pwm1, pwm11);
      analogWrite(pwm2, pwm22);
      analogWrite(pwm3, pwm33);
      analogWrite(pwm4, pwm44);
      digitalWrite(m1a, LOW);
      digitalWrite(m1b, LOW);
      digitalWrite(m2a, LOW);
      digitalWrite(m2b, LOW);
      digitalWrite(m3a, LOW);
      digitalWrite(m3b, LOW);
      digitalWrite(m4a, LOW);
      digitalWrite(m4b, LOW);
    }
    if (flag <1){
       ind = -1;
      }
    mag = -1;
    theta = -1;
    index = -1;
    value = -1;
    //Serial.println(theta);
    //Serial.println(mag);
  }  
}

int acibolge(int en_aci, int mag)
{    
   int aci =  en_aci;
   Serial.write(aci);

   if(mag <= 5)
   {
    return 0;
   }
   if(aci <= 8 || 118< aci && mag >60)
   {
    return 6;
   }
   if(aci <= 8 || 118< aci && mag <=60)
   {
    return 16;
   }
   if(8 < aci && aci <=24 && mag >60)
   {
    return 9;
   }
   if(8 < aci && aci <=24 && mag <=60)
   {
    return 19;
   }
   if(24 < aci && aci <=40 && mag >60)
   {
    return 8;
   }
   if(24 < aci && aci <=40 && mag <=60)
   {
    return 18;
   }
   if(40 < aci && aci <=55 && mag >60)
   {
    return 7;
   }
   if(40 < aci && aci <=55 && mag <=60)
   {
    return 17;
   }
   if(55 < aci && aci <=71 && mag >60)
   {
    return 4;
   }
   if(55 < aci && aci <=71 && mag <= 60)
   {
    return 14;
   }
   if(71 < aci && aci <=87 && mag >60)
   {
    return 1;
   }
   if(71 < aci && aci <=87 && mag <=60)
   {
    return 11;
   }
   if(87 < aci && aci <=103 && mag >60)
   {
    return 2;
   }
   if(87 < aci && aci <=103 && mag <=60)
   {
    return 12;
   }
   if(103 < aci && aci <=118 && mag >60)
   {
    return 3;
   }
   if(103 < aci && aci <=118 && mag <=60)
   {
    return 13;
   }
   
}
int sensors(int trigPin1,int trigPin2, int trigPin3, int trigPin4,int echoPin1, int echoPin2,int echoPin3,int echoPin4 )
{
    // Clears the trigPin
  digitalWrite(trigPin1, LOW);
  digitalWrite(trigPin2, LOW);
  digitalWrite(trigPin3, LOW);
  digitalWrite(trigPin4, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);  // Reads the echoPin, returns the sound wave travel time in microseconds
  delay(30);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  delay(30);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);
  duration3 = pulseIn(echoPin3, HIGH);
  delay(30);
  digitalWrite(trigPin4, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin4, LOW);
  duration4 = pulseIn(echoPin4, HIGH);
  delay(30);
  // Calculating the distance
  distance1 = duration1*0.034/2;
  distance2 = duration2*0.034/2;
  distance3 = duration3*0.034/2;
  distance4 = duration4*0.034/2;
  
  int delta1 = abs(distance1 - prev1);
  int delta2 = abs(distance2 - prev2);
  int delta3 = abs(distance3 - prev3);
  int delta4 = abs(distance4 - prev4);
  
  if(delta1>2 || delta2>2 || delta3>2 || delta4>2 ){
    //Serial.print("Distance4: ");
    //Serial.println(distance4);
    Serial.write(distance1);
    Serial.write(distance2);
    Serial.write(distance3);
    Serial.write(distance4);
  }
  
    prev1 = distance1;
    prev2 = distance2;
    prev3 = distance3;
    prev4 = distance4;
  
    return 0;
}
