const int m1a = 54;
const int m1b = 55;
const int m2a = 56;
const int m2b = 57;
const int m3a = 58;
const int m3b = 59;
const int m4a = 60;
const int m4b = 61;
const int pwm1 = 2;
const int pwm2 = 3;
const int pwm3 = 4;
const int pwm4 = 5;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(m1a, OUTPUT);
  pinMode(m1b, OUTPUT);
  pinMode(m2a, OUTPUT);
  pinMode(m2b, OUTPUT);
  pinMode(m3a, OUTPUT);
  pinMode(m3b, OUTPUT);
  pinMode(m4a, OUTPUT);
  pinMode(m4b, OUTPUT);
  //pinMode(pwm1, OUTPUT);
  //pinMode(pwm2, OUTPUT);
  //pinMode(pwm3, OUTPUT);
  //pinMode(pwm4, OUTPUT);
}

void loop() { 
  // put your main code here, to run repeatedly:
  int data = 0;
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

    
    //Serial input it saved to data
    if(Serial.available()){
      //int data = Serial.parseInt();
      data = (Serial.read()-'0');
      Serial.print(data);
    }
    if (data == 1)
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
    
    if (data == 2)
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
    
    if (data == '3')
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
    
    if (data == '4')
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
    if (data == '5')
    {
      analogWrite(pwm1, pwm11);
      analogWrite(pwm2, pwm22);
      analogWrite(pwm3, pwm33);
      analogWrite(pwm4, pwm44);
      digitalWrite(m1a, HIGH);
      digitalWrite(m1b, LOW);
      digitalWrite(m2a, HIGH);
      digitalWrite(m2b, LOW);
      digitalWrite(m3a, HIGH);
      digitalWrite(m3b, LOW);
      digitalWrite(m4a, HIGH);
      digitalWrite(m4b, LOW);
    }
    
    if (data == '6')
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
    
    if (data == '7')
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
    
    if (data == '8')
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
    if (data == '9')
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
    
    if (data == '0')
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
  }  
}
