int ledPinR = 3;
int ledPinG = 5;
int ledPinB = 6;

void setup()  { 
} 

/* Note:
When driving LED's using common anode LED AMP's you have to inverse the duty cycle,
i. e. 255 is off and 0 is full power.
*/

void loop()  { 
  // Red
  for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=5) { 
    analogWrite(ledPinR, fadeValue);         
    delay(30);                            
  }
  for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=5) { 
    analogWrite(ledPinR, fadeValue);         
    delay(30);
  } 
  // Green
  for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=5) { 
    analogWrite(ledPinG, fadeValue);         
    delay(30);                            
  } 
  for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=5) { 
    analogWrite(ledPinG, fadeValue);         
    delay(30);
  } 
  // Blue
  for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=5) { 
    analogWrite(ledPinB, fadeValue);         
    delay(30);                            
  } 
  for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=5) { 
    analogWrite(ledPinB, fadeValue);         
    delay(30);
  } 
  // White
  for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=5) { 
    analogWrite(ledPinR, fadeValue);         
    analogWrite(ledPinG, fadeValue);
    analogWrite(ledPinB, fadeValue);
    delay(30);                            
  } 
  for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=5) { 
    analogWrite(ledPinR, fadeValue);         
    analogWrite(ledPinG, fadeValue);
    analogWrite(ledPinB, fadeValue);
    delay(30);
  } 
}
