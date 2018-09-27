#include <Arduino.h>
#include "powermeter30A.hpp"


// Default constructor, all variables are already set, no need to do anything
PowerMeter30A::PowerMeter30A() {

}

// Default Destructor, no need to do anything
PowerMeter30A::~PowerMeter30A() {

}

double PowerMeter30A::getCurrent() {
	m_rawValue = analogRead(m_powerMeterPin);
	m_voltage = (m_rawValue/1024.0) * 5000;
	m_current = ((m_voltage - m_acOffset) /m_mVPerAmp);
	return m_current;
}
