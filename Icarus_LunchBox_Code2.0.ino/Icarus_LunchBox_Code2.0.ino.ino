const int Ducer1 = A0;
float value;
float mapped;


void setup() {
  // put your setup code here, to run once:
  
  pinMode(Ducer1, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  value = analogRead(Ducer1);
  mapped = map(value, 14, 25, 0, 1000); //the data we're getting is in mV and mPSI, so divide by 1000
  
  Serial.print(value);
  Serial.print(", ");
  Serial.print(mapped);
  Serial.println(" ");
  
}

