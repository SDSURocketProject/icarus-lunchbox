#include <SD.h>
#include <SPI.h>
#include <String.h>

const int CS_Pin = 10;
const int POW_Pin = 8;

const int Load_Cell = A0;
const int Chamber = A1;
const int temp_sens = A2;

float ReadingmV;
float tempC;
float tempF;
float voltage;

float x_Load_Cell;
float voltage_Load_Cell;
float y_Load_Cell;

float x_Chamber;
float voltage_Chamber;
float y_Chamber;

float Precise_map(float x, float in_min, float in_max, float out_min, float out_max) {
  
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void setup() {
  Serial.begin(9600);

  Serial.println("Initalizaing SD Card");
  pinMode(CS_Pin, OUTPUT);
  pinMode(POW_Pin, OUTPUT);
  digitalWrite(CS_Pin, HIGH);

  if(!SD.begin(CS_Pin)){
    Serial.println("Card Failure");
  }
  else{
  Serial.println("Card Ready");
  }
}

void loop() {
//fix me for timestamp
//time = 0
//millis();  subtract 2 millis(); values and multiply by 60 to get seconds then add it to timestamp to get an accurate timestamp
  Serial.println("Enter your file name in the terminal");
  
  while(Serial.available() == 0){}
  String userinput = Serial.readString();
  char input[80];
  
  for (int i = 0; i < sizeof(userinput); i++) {
    input[i] = userinput[i];
  }
  
  int n = strcspn(input, '\n');
  strncpy(input, input, n-1);
  strncpy((input+(n-1)), ".txt\0", 5);
  
  File dataFile = SD.open(input, FILE_WRITE);
  if(dataFile){
    for(int i = 0; i < 100; ++i){
      long timestamp = millis();

      ReadingmV = analogRead(temp_sens);              
      voltage = ReadingmV * 5.0;              
      voltage /= 1023;                            
      tempC = (voltage - 0.5) * 100;           
      tempF = (tempC * 1.8) + 32;  

      x_Load_Cell = analogRead(Load_Cell);
      voltage_Load_Cell = (x_Load_Cell / 1023) * 5;
      y_Load_Cell = Precise_map(voltage_Load_Cell, 1, 5.0, 0.0, 500.0);
      y_Load_Cell = y_Load_Cell - 52.17;

      x_Chamber = analogRead(Chamber);
      voltage_Chamber = (x_Chamber / 1023) * 5;
      y_Chamber = Precise_map(voltage_Chamber, 0.99, 5.0, 0.0, 2500.0);
      y_Chamber -= 1.36;

      Serial.print(timestamp);
      Serial.print(", ");
      Serial.print(tempF);
      Serial.print(", ");
      Serial.print(y_Load_Cell);
      Serial.print(", ");
      Serial.println(y_Chamber);

      dataFile.print(timestamp);
      dataFile.print(", ");
      dataFile.print(tempF);
      dataFile.print(", ");
      dataFile.print(y_Load_Cell);
      dataFile.print(", ");
      dataFile.println(y_Chamber);
  
      delay(10);
    }
    dataFile.close();
  } else {
    Serial.println("Failed to open");
    dataFile.close();
  } 
}
