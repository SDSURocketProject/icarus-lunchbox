
double ReadingmV;   //The variable we will use to store the sensor input
double tempC;        //The variable we will use to store temperature in degrees. 
double tempF;
double voltage;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //Start the Serial Port at 9600 baud (default)
  
}
void loop() {
  
  //This section of the code is for the tempature sensor
  /////////////////////////////////////////////////////////////////
   
  ReadingmV = analogRead(A0);               //read the analog sensor and store it
  voltage = ReadingmV * 5.0;                //gets the range of what the reading should be in a 750mv reading (from datasheet)
  voltage /= 1024;                          //scales the reading, arduino reads analog from 0-1023
  tempC = (voltage - 0.5) * 100;            //equation that comes from the datasheet, theres a 500mv offset and a 10mv scale factor
  tempF = (tempC * 1.8) + 32;               //converts celcius to fahrenhieght
  Serial.print("Current Temperature: ");
  Serial.println(tempF);

  /////////////////////////////////////////////////////////////////

  aarr
  
}

