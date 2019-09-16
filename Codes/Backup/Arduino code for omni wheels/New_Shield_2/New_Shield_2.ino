/* Soccer Robot Code */
/* Author Shahrukh Saleem*/

const int m1a = 12; //upper left 1st motor
const int m1b = 11;
const int m2a = 6; //upper right 2nd motor
const int m2b = 7;
const int m3a = 8; //lower left 3rd motor
const int m3b = 13;
const int m4a = 4; //lower right 4th motor
const int m4b = 2;
const int m1P = 9; //Enable PWM pin for 1st motor
const int m2P = 5;  //Enable PWM pin for 2nd motor
const int m3P = 10;  //Enable PWM pin for 3rd motor
const int m4P = 3;  //Enable PWM pin for 4th motor
/*const int k1 = 50;  //kicking circuit pin 1
const int k2 = 51;  //kicking circuit pin 2*/

int i = 0;

char data, data2;

void setup() {
  Serial.begin(9600);    //initialize serial @ 9600 baudrate
  pinMode(m1a, OUTPUT);  //defining pins
  pinMode(m1b, OUTPUT);
  pinMode(m2a, OUTPUT);
  pinMode(m2b, OUTPUT);
  pinMode(m3a, OUTPUT);
  pinMode(m3b, OUTPUT);
  pinMode(m4a, OUTPUT);
  pinMode(m4b, OUTPUT);
  /*pinMode(k1, OUTPUT);
  pinMode(k2, OUTPUT);*/

  //initially turn both pins of kicking circuit to low
  /*digitalWrite(k1, LOW);
  digitalWrite(k2, LOW);*/
}

void loop() {

  //if serial value is received
  while (Serial.available() > 0) 
  {
    //save it to character 'data'
    data = Serial.read();
    //print it on serial monitor
    Serial.println(data);
    //if 'F' is recieved go forward
    if (data == 'F' && i != 1)
    {
      //at full speed
      analogWrite(m1P, 255);
      analogWrite(m2P, 255);
      analogWrite(m3P, 255);
      analogWrite(m4P, 255);
      digitalWrite(m1a, HIGH);
      digitalWrite(m1b, LOW);
      digitalWrite(m2a, HIGH);
      digitalWrite(m2b, LOW);
      digitalWrite(m3a, HIGH);
      digitalWrite(m3b, LOW);
      digitalWrite(m4a, HIGH);
      digitalWrite(m4b, LOW);
    }
    //backward
    if (data == 'B' && i != 1)
    {
      analogWrite(m1P, 255);
      analogWrite(m2P, 255);
      analogWrite(m3P, 255);
      analogWrite(m4P, 255);
      digitalWrite(m1a, LOW);
      digitalWrite(m1b, HIGH);
      digitalWrite(m2a, LOW);
      digitalWrite(m2b, HIGH);
      digitalWrite(m3a, LOW);
      digitalWrite(m3b, HIGH);
      digitalWrite(m4a, LOW);
      digitalWrite(m4b, HIGH);
    }
    //left
    if (data == 'L' && i != 1)
    {
      analogWrite(m1P, 255);
      analogWrite(m2P, 255);
      analogWrite(m3P, 255);
      analogWrite(m4P, 255);
      digitalWrite(m1a, LOW);
      digitalWrite(m1b, HIGH);
      digitalWrite(m2a, HIGH);
      digitalWrite(m2b, LOW);
      digitalWrite(m3a, HIGH);
      digitalWrite(m3b, LOW);
      digitalWrite(m4a, LOW);
      digitalWrite(m4b, HIGH);
    }
    //right
    if (data == 'R' && i != 1)
    {
      analogWrite(m1P, 255);
      analogWrite(m2P, 255);
      analogWrite(m3P, 255);
      analogWrite(m4P, 255);
      digitalWrite(m1a, HIGH);
      digitalWrite(m1b, LOW);
      digitalWrite(m2a, LOW);
      digitalWrite(m2b, HIGH);
      digitalWrite(m3a, LOW);
      digitalWrite(m3b, HIGH);
      digitalWrite(m4a, HIGH);
      digitalWrite(m4b, LOW);
    }
    //forward left
    if (data == 'G' && i != 1)
    {
      analogWrite(m1P, 255);
      analogWrite(m2P, 255);
      analogWrite(m3P, 255);
      analogWrite(m4P, 255);
      digitalWrite(m1a, LOW);
      digitalWrite(m1b, LOW);
      digitalWrite(m2a, HIGH);
      digitalWrite(m2b, LOW);
      digitalWrite(m3a, HIGH);
      digitalWrite(m3b, LOW);
      digitalWrite(m4a, LOW);
      digitalWrite(m4b, LOW);
    }
    //forward right
    if (data == 'I' && i != 1)
    {
      analogWrite(m1P, 255);
      analogWrite(m2P, 255);
      analogWrite(m3P, 255);
      analogWrite(m4P, 255);
      digitalWrite(m1a, HIGH);
      digitalWrite(m1b, LOW);
      digitalWrite(m2a, LOW);
      digitalWrite(m2b, LOW);
      digitalWrite(m3a, LOW);
      digitalWrite(m3b, LOW);
      digitalWrite(m4a, HIGH);
      digitalWrite(m4b, LOW);
    }
    //backward left
    if (data == 'H' && i != 1)
    {
      analogWrite(m1P, 255);
      analogWrite(m2P, 255);
      analogWrite(m3P, 255);
      analogWrite(m4P, 255);
      digitalWrite(m1a, LOW);
      digitalWrite(m1b, HIGH);
      digitalWrite(m2a, LOW);
      digitalWrite(m2b, LOW);
      digitalWrite(m3a, LOW);
      digitalWrite(m3b, LOW);
      digitalWrite(m4a, LOW);
      digitalWrite(m4b, HIGH);
    }
    //backward right
    if (data == 'J' && i != 1)
    {
      analogWrite(m1P, 255);
      analogWrite(m2P, 255);
      analogWrite(m3P, 255);
      analogWrite(m4P, 255);
      digitalWrite(m1a, LOW);
      digitalWrite(m1b, LOW);
      digitalWrite(m2a, LOW);
      digitalWrite(m2b, HIGH);
      digitalWrite(m3a, LOW);
      digitalWrite(m3b, HIGH);
      digitalWrite(m4a, LOW);
      digitalWrite(m4b, LOW);
    }
    //stop
    if ((data == 'S' || data == 'D') && i != 1)
    {
      digitalWrite(m1a, LOW);
      digitalWrite(m1b, LOW);
      digitalWrite(m2a, LOW);
      digitalWrite(m2b, LOW);
      digitalWrite(m3a, LOW);
      digitalWrite(m3b, LOW);
      digitalWrite(m4a, LOW);
      digitalWrite(m4b, LOW);
    }
    //counter clockwise
    if (data == '0' || data == '1' || data == '2' || data == '3')
    {
      //at medium speed
      analogWrite(m1P, 150);
      analogWrite(m2P, 150);
      analogWrite(m3P, 150);
      analogWrite(m4P, 150);
      digitalWrite(m1a, LOW);
      digitalWrite(m1b, HIGH);
      digitalWrite(m2a, HIGH);
      digitalWrite(m2b, LOW);
      digitalWrite(m3a, LOW);
      digitalWrite(m3b, HIGH);
      digitalWrite(m4a, HIGH);
      digitalWrite(m4b, LOW);
      i = 1;
    }
    //neutral
    if (data == '4' || data == '5' || data == '6')
    {
      digitalWrite(m1a, LOW);
      digitalWrite(m1b, LOW);
      digitalWrite(m2a, LOW);
      digitalWrite(m2b, LOW);
      digitalWrite(m3a, LOW);
      digitalWrite(m3b, LOW);
      digitalWrite(m4a, LOW);
      digitalWrite(m4b, LOW);
      i = 0;
    }
    //clockwise
    if (data == '7' || data == '8' || data == '9' || data == 'q')
    {
      i = 1;
      analogWrite(m1P, 150);
      analogWrite(m2P, 150);
      analogWrite(m3P, 150);
      analogWrite(m4P, 150);
      Serial.println("CLOCKWISE");
      digitalWrite(m1a, HIGH);
      digitalWrite(m1b, LOW);
      digitalWrite(m2a, LOW);
      digitalWrite(m2b, HIGH);
      digitalWrite(m3a, HIGH);
      digitalWrite(m3b, LOW);
      digitalWrite(m4a, LOW);
      digitalWrite(m4b, HIGH);

    }
    /*
    //kicking
    if ((data == 'W' || data == 'w' || data == 'U' || data == 'u') && i != 1)
    {
      digitalWrite(k1, HIGH);
      digitalWrite(k2, LOW);
      delay(500);
      digitalWrite(k1, LOW);
      digitalWrite(k2, LOW);
      delay(100);
      digitalWrite(k1, LOW);
      digitalWrite(k2, HIGH);
      delay(500);
      digitalWrite(k1, LOW);
      digitalWrite(k2, LOW);
    }*/
  }
}
