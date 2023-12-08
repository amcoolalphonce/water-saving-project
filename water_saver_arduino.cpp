#include<Wire.h>
// Defining the constants required
const int motionSensorPin = 2; // pin to which the motion sensor is connected
const flushRelayPin = 3; // pin to which relay is connected

unsigned long lastMotionTime = 0; 
unsigned long flushDelay = 60000;  //flush  delay in seconds

void setup()
{
        Serial.begin(9600);
        //initialize pins
        pinMode(motionSensorPin, INPUT);
        pinMode(flushRelayPin, OUTPUT);
        digitalWrite(flushRelayPin, LOW); // ensure flush relay is iniitially off
}

void loop()
{
        //read motion sensor value
        int motionValue = digitalRead(motionSensorPin);

        if (motionValue == HIGH)
        {
                //motion detected and  update the last motuion time
                lastMotionTime = millis();
        }
        if (millis()- lastMotionTime > flushDelay)
        {
                Serial.printIn(" No motion detected for a minuted. Flushing...");
                digitalWrite(flushRelayPin, HIGH);
                delay(1000);
                digitalWrite(flushRelayPin, LOW);
                Serial.printIn("Flush Completed.");
        }
        delay(100);//a small delay to avoid continuos reading
}