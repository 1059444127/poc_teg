// CoagVista_GUI_v2.ino 
//
// Acquires data from temperature sensor and MEMS sensor
//
// By Alexander Godbout
//
// Last Updated On: 6/1/16


byte val = 0;
int voltage = 5; 
float potMeter = 0; 
const int numReadings = 10;

float readings[numReadings];
float savedreading = 0; 
int readIndex = 0;              // the index of the current reading
float total = 0;                  // the running total
float average = 0;  


#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  sensors.begin();

  // initialize all the readings to 0:
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
  readings[thisReading] = 0;
  }
}

void loop() {

  // put your main code here, to run repeatedly:

  //read temp sensor
  sensors.requestTemperatures();
  
  delay(100);  // we have to make a delay to avoid overloading the serial port

  //read MEMS sesnor and send to serial output
  potMeter = analogRead(A5);
  potMeter = potMeter*(5.0 / 1023.0);
  Serial.println(potMeter);

  /*  //////   Optional Noise Smoothing:   /////////
  // subtract the last reading:d
  total = total - readings[readIndex];
  savedreading = readings[readIndex];
  // read from the sensor:
  readings[readIndex] = potMeter;

  //Remove spikes 
  if (readings[readIndex] > 4.0){
    readings[readIndex] = savedreading;
  }
  
  // add the reading to the total:
  total = total + readings[readIndex];
  // advance to the next position in the array:
  readIndex = readIndex + 1;

  // if we're at the end of the array...
  if (readIndex >= numReadings) {
    // ...wrap around to the beginning:
    readIndex = 0;
  }

  // calculate the average:
  average = total / numReadings;
  // send it to the computer as ASCII digits
  //Serial.println(average);
  delay(1);        // delay in between reads for stability

  */
}


