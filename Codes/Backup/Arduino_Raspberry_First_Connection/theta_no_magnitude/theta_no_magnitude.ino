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

int a,b;
int raspberry_out[2];

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
  int aci = 0;
  int magnitude;
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

    //for (int x = 0; x < 2; x = x+1) {
    //statement(s);
    //raspberry_out[x] = Serial.parseInt(); // veri dizisindeki tam sayıları oku
    //Serial.print(data[x]);
    //aci=raspberry_out[0];
    //magnitude=raspberry_out[1];
    //Serial.println("sikko gokhan2");
    //}  
    aci=Serial.read();
    data = acibolge(aci);    
    Serial.write(data);
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
    
    if (data == 3)
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
    
    if (data == 4)
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
    if (data == 5)
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
    
    if (data == 6)
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
    
    if (data == 7)
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
    
    if (data == 8)
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
    if (data == 9)
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
    
    if (data == 0)
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
int acibolge(int en_aci)
{
   int aci = 1.41 * en_aci;

   if(aci <= 23 && 338< aci)
   {
    return 6;
   }
   if(23 < aci && aci <=68)
   {
    return 9;
   }
   if(68 < aci && aci <=113)
   {
    return 8;
   }
   if(113 < aci && aci <=158)
   {
    return 7;
   }
   if(158 < aci && aci <=203)
   {
    return 4;
   }
   if(203 < aci && aci <=248)
   {
    return 1;
   }   if(248 < aci && aci <=293)
   {
    return 2;
   }
   if(293 < aci && aci <=338)
   {
    return 3;
   }
}
