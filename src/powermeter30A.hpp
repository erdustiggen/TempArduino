#pragma once

/*
	Because it is a -30 to +30 Module, the resolution is 66mV per ampere on the output pin.
*/


class PowerMeter30A {
private:
	// Current
	double m_current{0};
	// Voltage
	double m_voltage{0};
	// Value used for reading sensor value
	int m_rawValue{0};
	// Scale factor
	int m_mVPerAmp{66};
	// The AC-offset
	int m_acOffset{2500};
	// Pin to read
	const int m_powerMeterPin = A1;

public:
	// Constructor, Nothing to set so just a defalut
	PowerMeter30A();
	// Destructor
	~PowerMeter30A();
	// Returns Current in Amps
	double getCurrent();
};
