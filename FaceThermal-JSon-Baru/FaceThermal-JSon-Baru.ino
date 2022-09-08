/***************************************************************************
  This is a library for the AMG88xx GridEYE 8x8 IR camera

  This sketch tries to read the pixels from the sensor

  Designed specifically to work with the Adafruit AMG88 breakout
  ----> http://www.adafruit.com/products/3538

  These sensors use I2C to communicate. The device's I2C address is 0x69

  Adafruit invests time and resources providing this open source code,
  please support Adafruit andopen-source hardware by purchasing products
  from Adafruit!

  Written by Dean Miller for Adafruit Industries.
  BSD license, all text above must be included in any redistribution
 ***************************************************************************/

#include <Wire.h>
#include <Adafruit_AMG88xx.h>

Adafruit_AMG88xx amg;

float pixels[AMG88xx_PIXEL_ARRAY_SIZE];

//#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
//#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement
int co=0;
char data = 0;

char str[25];


void setup() {
    bool status;
    // default settings
    status = amg.begin();
    if (!status) {
        Serial.println("Could not find a valid AMG88xx sensor, check wiring!");
        while (1);
    }
    Serial.begin(9600);
    delay(5000);
}


void loop() { 
    delay(100);
    data = Serial.read();    //Pembacaan dan ditampilkan data yang masuk   
    //Data yang masuk      
    if(data == '1'){
    distance = 0;
    //read all the pixels
    amg.readPixels(pixels);
    float temp=0;
    for (int i = 0; i < AMG88xx_PIXEL_ARRAY_SIZE; i++) {
        if(temp<pixels[i])temp=pixels[i];
    }
    Serial.print("{");
   // Serial.print("Jarak:");
 //   Serial.print(distance);
  //  Serial.print(",");
    Serial.print("Suhu:");
    Serial.print(temp);
    Serial.print("}");
    Serial.println("\n");
    }
}
