#include <Arduino.h>
#include "UltraSonic.hpp"

int trigPin = A0;
int echoPin = A1;

UltraSonic ultraSonic(trigPin, echoPin);

int distanceToObject;

void setup() {
	Serial.begin(9600);
}

void loop() {
	distanceToObject = ultraSonic.getFilteredObjectDistance();
	Serial.print("Distance to closest object = ");
	Serial.print(distanceToObject);
	Serial.println(" cm");

	delay(100);
}
