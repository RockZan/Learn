int pin = 8; //0~13

void setup()
{
    pinMode(pin, OUTPUT);
}   

void loop()
{
      digitalWrite(pin, HIGH);
      delayMicroseconds(100);
      digitalWrite(pin, LOW);
      delayMicroseconds(1000 - 100);
}
