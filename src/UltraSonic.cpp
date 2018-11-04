#include "Arduino.h"
#include "UltraSonic.hpp"

// Function for swapping elements
#define swap(a,b) a ^= b; b ^= a; a ^= b;
// Function for sorting between two elements
#define sort(a,b) if(a>b){ swap(a,b); }


UltraSonic::UltraSonic(int trigPin, int echoPin)
{
	pinMode(trigPin,OUTPUT);
   	pinMode(echoPin,INPUT);
	this->trigPin = trigPin;
	this->echoPin = echoPin;
}

void UltraSonic::timing()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin,HIGH);
}

long UltraSonic::getObjectDistance() {
  timing();
  distanceCM = (duration /29) / 2; // Because the ultrasonic wave travels at 330m/s, we need to devide by 29 to get us/cm //TODO: Verify this
  return distanceCM;

}

long UltraSonic::getFilteredObjectDistance() {
	long lastReadings[5];
	for(int i = 0; i < 5; ++i) {
		lastReadings[i] = getObjectDistance();
	}
	long medianVal = median(lastReadings[0], lastReadings[1], lastReadings[2], lastReadings[3], lastReadings[4]);
	return medianVal;
}

long UltraSonic::median(long a, long b, long c, long d, long e) {
    sort(a,b);
    sort(d,e);
    sort(a,c);
    sort(b,c);
    sort(a,d);
    sort(c,d);
    sort(b,e);
    sort(b,c);
    // this last one is obviously unnecessary for the median
    //sort(d,e);

    return c;
}
