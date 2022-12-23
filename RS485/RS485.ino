/*
Used for communication between the Matrix310 and a computer or other devices. 
Matrix310 uses SERIAL2 PINS to achieve RS485 communication.
*/

#include "./src/Artila-Matrix310.h"
void setup() {
  Serial.begin(115200);
  Serial.setTimeout(100);
  //Setup Serial2 PINS with the specified baud rates that is depends on the device you connect.
  Serial2.begin(9600);
  Serial2.setTimeout(100);
  //Configures the COM1_RTS pin to behave as an output.
  pinMode(COM1_RTS, OUTPUT);
  //Write a HIGH value to COM1_RTS pin before the Matrix310 uses the Serial2 PINS to send/write data.
  //Write a LOW value to COM1_RTS pin before the Matrix310 uses the Serial2 PINS to receive/read data.
  digitalWrite(COM1_RTS, HIGH);
  delay(0.01);
  Serial.println("RS485 already setup.");
}

void loop() {
  // put your main code here, to run repeatedly:
}
