#include "src/Artila-Matrix310.h"

int di1_status = 0;
int di2_status = 0;
const int interval = 5000;

void setDO(int status){
    digitalWrite(DO1, status);
}

void readDI(){
    di1_status = digitalRead(DI1);
    di2_status = digitalRead(DI2);
    
    Serial.println((String)"DI1: " + di1_status);
    Serial.println((String)"DI2: " + di2_status);
}

void setRreadyLed(int state){
    if(state) { // LED ON
        setLED(LED_READY, HIGH);
    }
    else { // LED OFF
        setLED(LED_READY, LOW);
    }
}

void setLED(int pin, int status){
    digitalWrite(pin, status);
}

void initGPIO()
{
    pinMode(DO1, OUTPUT);
    pinMode(DI1, INPUT);
    pinMode(DI2, INPUT);
    pinMode(SD_CS, OUTPUT);
    pinMode(COM1_RTS, OUTPUT);
    pinMode(LED_WIFI, OUTPUT);
    pinMode(LED_READY, OUTPUT);
    
    pinMode(SW_1, INPUT);
    pinMode(SW_2, INPUT);
    pinMode(SW_4, INPUT);
    
    // make sure LED OFF, if possible
    // setRreadyLed(1);
    // digitalWrite(LED_WIFI, LOW);
}

void setup() {
    initGPIO();
    Serial.begin(115200);
    while (!Serial);
    
    Serial.println("=== Hello ARTILA ===");
    setRreadyLed(1);
}

void loop() {
    setLED(LED_WIFI, LOW);
    Serial.println("Set DO1 to LOW");
    setDO(LOW);
    delay( 100 );
    readDI();
    delay( interval );
    
    setLED(LED_WIFI, HIGH);
    Serial.println("Set DO1 to HIGH");
    setDO(HIGH);
    delay( 100 );
    readDI();
    delay( interval );
}
