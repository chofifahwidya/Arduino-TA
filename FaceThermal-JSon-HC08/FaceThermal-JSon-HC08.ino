//Grove
#include <SoftwareSerial.h>
#include "Seeed_AMG8833_driver.h"

SoftwareSerial BTHC08Serial(10, 11); // RX | TX
AMG8833 sensor;

#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04


// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement
int co=0;
char data = 0;

char str[25];

void setup() {
    Serial.begin(9600);
    if (sensor.init()) {
        Serial.println("init failed!!!");
        while (1);
    }
    delay(5000);
}

void loop() {
    delay(100);
    data = Serial.read();    //Pembacaan dan ditampilkan data yang masuk   
    //Data yang masuk      
    if(data == '1'){
    distance = 0;
    float pixels_temp[PIXEL_NUM] = {0};
    sensor.read_pixel_temperature(pixels_temp);
    float temp=0;
    for (int i = 0; i < PIXEL_NUM; i++) {
        if(temp<pixels_temp[i])temp=pixels_temp[i];
    }
    Serial.print("{");
    Serial.print("Jarak:");
    Serial.print(distance);
    Serial.print(",");
    Serial.print("Suhu:");
    Serial.print(temp);
    Serial.print("}");
    Serial.println("\n");
    }
}
