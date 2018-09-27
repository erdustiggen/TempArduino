#include <Arduino.h>
#include <stdint.h>
#include "powermeter30A.hpp"
#include "circularbuffer.hpp"
/*
	Because it is a -30 to +30 Module, the resolution is 66mV per ampere on the output pin.
*/
// uint8_t buff[50];
// PMCircularBuffer pmBuf(buff, 50);

PowerMeter30A pMeter;
double current{0};

void setup() {
	Serial.begin(9600);
}

void loop() {

	current = pMeter.getCurrent();
	Serial.print("Current is = ");
	Serial.print(current);
	Serial.print(" A\n");

}
