
#include <Wire.h>

// #define rec 0xd0
// #define trans 0xd2

// #define reg 0x02
// #define data 0xa0

void setup() {
    Wire.begin();
    Serial.begin(9600);
    Serial.println("Sonar P2P Test\n");
    byte devAdd[2];
    scanDev(devAdd);
    byte trans = devAdd[0];
    byte rec = devAdd[1];
    Serial.print("Transmitter defined at 0x");
    if (trans < 16) {
        Serial.print("0");
    }
    Serial.println(trans, HEX);
    Serial.print("Receiver defined at 0x");
    if (rec < 16) {
            Serial.print("0");
    }
    Serial.println(rec, HEX);
}

void loop() {
    // Wire.beginTransmission(rec);
    // Wire.write(byte);

    // Wire.write();
    // Wire.endTransmission();
}

void scanDev(byte devAdd[]) {
    Serial.println("WARNING: The first I2C device found will be used");
    byte indAdd = 0;
    byte err, add;

    for (add = 0; add < 127; add++) {
        Wire.beginTransmission(add);
        err = Wire.endTransmission();
        
        if (err == 0) {
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

    }
}
