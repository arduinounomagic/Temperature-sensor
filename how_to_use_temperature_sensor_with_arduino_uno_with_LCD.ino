/*
*How to use temperature sensor with Arduino uno (with LCD)
*This video describes how to use temperature sensor with arduino uno to display measured temperature in Celsius and Fahrenheit something on LCD.
*
*Copyright (C) 2007 Free Software Foundation, Inc. <arduinounomagic@gmail.com>
*for more projects based on Arduino uno please visit: https://arduinounomagic.blogspot.com/
*/

#include<LiquidCrystal.h>
LiquidCrystal ARDUINO_LCD(8, 2, 7, 6, 5, 4);// Set RS at pin=8, Enable at pin=2, data pins at: D4=7, D5=6, D6=5, d7=4.  
const int LM_35=A2;// LM_35 is connected to pin A2. 

float sensor_value; // variable to store temperature value.
float temp_f; // Variable to store temperature in fahrenheit.
float temp_c; // Variable to store temperature in celsius.


void setup() 
{  

Serial.begin(9600);
ARDUINO_LCD.begin(16, 2);//set up number of colomn and rows of LCD
delay(400);

}

void loop() {
  
sensor_value=analogRead(LM_35); //read the data from sensor

temp_c=(sensor_value*5*100)/1024; //calculates temperature in celsius.


temp_f=(temp_c*9/5)+32; // calculates temperature in fahrenheit.

 ARDUINO_LCD.setCursor(0,0); // Sets the location at which subsequent text written to the LCD will be displayed (at colomn=0 and row=0)
ARDUINO_LCD.print("In c=");
ARDUINO_LCD.print(temp_c); //display the temperature in celsius on LCD screen


ARDUINO_LCD.setCursor(0,1); // Sets the location at which subsequent text written to the LCD will be displayed (at colomn=0 and row=1)
ARDUINO_LCD.print("In f=");
ARDUINO_LCD.print(temp_f); //display the temperature in fahrenheit on LCD screen

delay(1000); //delay

}
