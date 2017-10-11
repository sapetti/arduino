const int led=13;
// 12 is the maximum length of a decimal representation of a 32-bit integer,
// including space for a leading minus sign and terminating null byte
char intBuffer[12];
String intData = "";
int delimiter = (int) '\n';

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  luz(3);
}

void loop() {
  //if(Serial.available()) {
  //  int number=Serial.read();
  //  Serial.print("I received: ");
  //  Serial.println(number, DEC);
  //  luz(number);
  //}
  while (Serial.available()) {
      int ch = Serial.read();
      if (ch == -1) {
          // Handle error
      }
      else if (ch == delimiter) {
          break;
      }
      else {
          intData += (char) ch;
      }
            
      // Copy read data into a char array for use by atoi
      // Include room for the null terminator
      int intLength = intData.length() + 1;
      intData.toCharArray(intBuffer, intLength);
    
      // Reinitialize intData for use next time around the loop
      intData = "";
    
      // Convert ASCII-encoded integer to an int
      int i = atoi(intBuffer);
      luz(i);
  }
    
}

void luz(int n) {
  Serial.print("Luz: ");
  Serial.println(n, DEC);
  for(int i=0; i<n; i++) {
    digitalWrite(led, HIGH);
    delay(500);
    digitalWrite(led, LOW);
    delay(500);
  }
}
