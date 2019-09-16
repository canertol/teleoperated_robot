void setup(){
 Serial.begin(9600);
    
}

void loop(){
  // Define 
String str; 

char = Serial.read(); 

// Length (with one extra character for the null terminator)
int str_len = str.length() + 1; 

// Prepare the character array (the buffer) 
char char_array[str_len] = Serial.read();;

// Copy it over 
str.toCharArray(char_array, str_len);

for(int i=1; i<3;i++)
println(char_array[i]);
  
/* 
  String my_string;
  char buf[my_string.length()+1];
  if(Serial.available()>0)
  my_string = Serial.read();
  buf = my_string.toCharArray(buf, my_string.length()+1);
*/
 
}
