/*
*How to use temperature sensor with Arduino Uno (with serial monitor)
*This code describes how temperature sensor works with the help of Arduino Uno to display temperature in celsius and fahrenheit on serial monitor.
*
*https://www.arduinounomagic.com/2019/01/how-to-use-temperature-sensor-with.html
*
*Copyright (C) 2007 Free Software Foundation, Inc. <arduinounomagic@gmail.com>
*for more projects based on Arduino uno please visit: https://arduinounomagic.com/
*/


const int LM_35=A2; // LM_35 is connected to pin A2. 

float sensor_value; // variable to store temperature value.
float temp_f; // Variable to store temperature in fahrenheit.
float temp_c; // Variable to store temperature in celsius.


void setup() 
{  
Serial.begin(9600); 
}

void loop() {
 
sensor_value=analogRead(LM_35); //read data from sensor

temp_c=(sensor_value*5*100)/1024; //calculates temperature in celsius.


temp_f=(temp_c*9/5)+32; // calculates temperature in fahrenheit.

Serial.print("In celcius=");
Serial.println(temp_c); //prints temperature in celsius on serial monitor
Serial.print("In fahrenheit=");
Serial.println(temp_f); //prints temperature in fahrenheit on serial monitor.


delay(1000); //delay

}
