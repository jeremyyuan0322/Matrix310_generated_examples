/*
Used for communication between the Matrix310 and a computer or other devices. 
Matrix310 uses SERIAL2 PINS to achieve RS485 communication.
*/

#include "./src/Artila-Matrix310.h"
char msg[] = "Message\0";
char buf[64];
int readLen = 0;
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
  int writeLen = Serial2.write(msg);
  Serial2.flush();
  digitalWrite(COM1_RTS, LOW); // read
  delay(0.01);
  Serial.print("data send: ");
  Serial.println(writeLen);
  delay(32);
  if (Serial2.available() > 0)
  {
    readLen = Serial2.readBytes(buf, sizeof(buf));
    Serial2.flush();
    digitalWrite(COM1_RTS, HIGH); // write
    delay(0.01);
  }
  else
  {
    Serial.println("read nothing!");
  }

  Serial.print("data receive: ");
  Serial.println(readLen);
  for (int i = 0; i < readLen; i++)
  {
    Serial.print(buf);
    Serial.print(" ");
  }
  Serial.println("");
  Serial.println("do it again~");
  Serial.println("");
  delay(3000);
}
