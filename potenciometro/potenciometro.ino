int i = 0;
int inputPin = A0;
int inputValue = 0;

void setup(){
  pinMode(inputPin, INPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  inputValue = analogRead(inputPin);
  Serial.println(inputValue);
  delay(100);
  digitalWrite(2, inputValue >= 10 ? LOW : HIGH);
  digitalWrite(3, inputValue >= 200 ? LOW : HIGH);
  digitalWrite(4, inputValue >= 400 ? LOW : HIGH);
  digitalWrite(5, inputValue >= 600 ? LOW : HIGH);
  digitalWrite(6, inputValue >= 800 ? LOW : HIGH);
}

