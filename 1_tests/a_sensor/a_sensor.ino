#include <MPU6050_tockn.h>
#include <Wire.h>
TwoWire i2c;


MPU6050 mpu6050(i2c);

long timeStamp = 0;


void setup() {
    Serial.begin(115200);
    Serial.println("Hello!");

    i2c.begin(D3, D4);
    mpu6050.begin();
}

void loop() {
    // 10ms => 100Hz
    if(millis() - timeStamp > 10){
        mpu6050.update();
        Serial.print("-2 2 ");
        Serial.println(mpu6050.getAccZ());
        timeStamp = millis();
    }
}

