int x=0;
int a,b;
int data[2];
void setup() {
  Serial.begin(9600);  // Seri Portu başlat
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available()){
for (x = 0; x < 2; x = x+1) {
  // statement(s);
    data[x] = Serial.parseInt(); // veri dizisindeki tam sayıları oku
    //Serial.print(data[x]);
    a=data[0];
    b=data[1];
}

}
  if ( x = 2)
  {
  Serial.println(a);
  Serial.println(b); 
  }
}
