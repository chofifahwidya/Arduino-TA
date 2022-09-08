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

#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement
int co=0;
char data = 0;

char str[25];


void setup() {
    //Serial.begin(9600);
    //Serial.println(F("AMG88xx pixels"));

    bool status;
    
    // default settings
    status = amg.begin();
    if (!status) {
        Serial.println("Could not find a valid AMG88xx sensor, check wiring!");
        while (1);
    }
    
    //Serial.println("-- Pixels Test --");

    //Serial.println();

    //delay(100); // let sensor boot up
    
    //pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
    //pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
    //Serial.begin(9600);
    /*if (sensor.init()) {
        Serial.println("init failed!!!");
        while (1);
    }*/
    //Serial.println("AMG8833 OK");
    //Serial.println("HC-SR04 OK"); 
    Serial.begin(9600);
    delay(5000);
}


void loop() { 
    delay(100);
    data = Serial.read();    //Pembacaan dan ditampilkan data yang masuk   
    //Data yang masuk      
    if(data == '1'){
    /*digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    // Calculating the distance
    distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)*/
    distance = 0;
    //read all the pixels
    
    amg.readPixels(pixels);

    float temp=0;
    for (int i = 0; i < AMG88xx_PIXEL_ARRAY_SIZE; i++) {
        if(temp<pixels[i])temp=pixels[i];
    }
    //float temp=2.5;
    Serial.print("{");
    Serial.print("Jarak:");
    Serial.print(distance);
    Serial.print(",");
    Serial.print("Suhu:");
    Serial.print(temp);
    Serial.print("}");
    Serial.println("\n");
    }

    /*Serial.print("[");
    for(int i=1; i<=AMG88xx_PIXEL_ARRAY_SIZE; i++){
      Serial.print(pixels[i-1]);
      Serial.print(", ");
      if( i%8 == 0 ) Serial.println();
    }
    Serial.println("]");
    Serial.println();*/

    //delay a second
    //delay(1000);
}
