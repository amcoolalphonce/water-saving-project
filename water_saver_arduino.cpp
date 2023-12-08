#include<Wire.h>
// Defining the constants required
const int motionSensorPin = 2; // pin to which the motion sensor is connected
const flushRelayPin = 3; // pin to which relay is connected

unsigned long lastMotionTime = 0;