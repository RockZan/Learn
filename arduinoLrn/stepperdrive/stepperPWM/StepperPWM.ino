int pin = 8; //0~13
int i;

void setup()
{
    pinMode(pin, OUTPUT);

    for(i = 0; i < 20; i++)
    {
      digitalWrite(pin, HIGH);
      delayMicroseconds(100);
      digitalWrite(pin, LOW);
      delayMicroseconds(1000 - 100);
    }
}   

void loop()
{
}
