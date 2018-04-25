
const int Led = 7;
int value;
int mapped;

void setup() {
  // put your setup code here, to run once:
pinMode(Led, OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(Led, HIGH);
value = digitalRead(Led);
mapped = map(value, 0, 1, 0, 255);
delay(1000);

Serial.print(value);
Serial.print(", ");
Serial.print(mapped);

digitalWrite(Led, LOW);
value = digitalRead(Led);
mapped = map(value, 0, 1, 0, 255);
delay(1000);

Serial.print(", ");
Serial.print(value);
Serial.print(", ");
Serial.print(mapped);
Serial.println(" ");

}
