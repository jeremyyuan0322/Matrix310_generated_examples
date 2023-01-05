void setup() {
  // put your setup code here, to run once:
  String a="str";
  Serial.begin(115200);
  Serial.print("msg:\nabc");
  Serial.println("2");
  Serial.print(a.c_str());
  
  
}

void loop() {
  // put your main code here, to run repeatedly:
  // if(Serial.available() > 0){
  //   Serial.write(Serial.read());
  // } 

}