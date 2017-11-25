int ledpin = 13;

void setup() {

    Serial.begin(9600);
    pinMode(ledpin, OUTPUT);

}

void loop() {

  if(Serial.available())
  {
    int data = Serial.read();
    if(data == 'A')
      digitalWrite(ledpin,HIGH);
    else
      digitalWrite(ledpin,LOW);
  }
 
}
