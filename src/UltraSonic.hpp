#pragma once

#include "Arduino.h"

#define MAX_CM_VALUE 100
class UltraSonic {
private:
	int trigPin;
	int echoPin;
	long duration;
	long distanceCM;
	long filteredObjDistance = 0;
public:
	UltraSonic(int triggerPin, int echoPin);
	void timing();
	long getObjectDistance();
	long getFilteredObjectDistance();
	long median(long a, long b, long c, long d, long e);
};
