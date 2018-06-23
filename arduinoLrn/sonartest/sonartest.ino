#include <Wire.h>

// #define rec 0xd0
// #define trans 0xd2

// #define reg 0x02
// #define data 0xa0

int * scanDev();

void setup() {
    Wire.begin();
    Serial.begin(9600);
    Serial.println("Sonar P2P Test\n");
    int *devAdd = scanDev();
    byte rec = *(devAdd + 0);
    byte trans = *(devAdd + 1);
    Serial.println(rec);
    Serial.println(trans);
}

void loop() {
    // Wire.beginTransmission(rec);
    // Wire.write(byte);

    // Wire.write();
    // Wire.endTransmission();
}

int * scanDev() {
    Serial.println("WARNING: The first I2C device found will be used");
    byte indAdd = 0;
    int devAdd[2];
    byte err, add;

    for (add = 0; add < 127; add++) {
        Wire.beginTransmission(add);
        err = Wire.endTransmission();
        
        if (err == 0) {
            Serial.print("I2C device found at address 0x");
            if (add<16) {
                Serial.print("0");
            }
            Serial.println(add, HEX);
            devAdd[indAdd] = add;
            indAdd++;
        } else if (err ==4) {
            Serial.print("Error at address 0x");
            if (add<16) {
                Serial.print("0");
            }
            Serial.println(add, HEX);
        }
    }

    if (indAdd < 2) {
        Serial.println("Less than two I2C devices found, test cannot be conducted\n");
    } else {
//        Serial.println(devAdd[0]);
//        Serial.println(devAdd[1]);
        return devAdd;
    }
}
