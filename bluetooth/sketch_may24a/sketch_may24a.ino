void setup()
{
    Serial.begin( 9600 );    // 9600 is the default baud rate for the
                              // serial Bluetooth module
                              
  pinMode(1, OUTPUT);
  
  pinMode(0, INPUT);
}
 
void loop()
{
    // Listen for data on the serial connection
    if ( Serial.available() > 1 )
    {
        // Read in 2 numbers
        float a = Serial.parseFloat();
        float b = Serial.parseFloat();
 
        // Add them together and return the result
        Serial.println( a + b );
    }
}
