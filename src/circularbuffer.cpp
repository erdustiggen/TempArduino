#include <Arduino.h>
#include <stdint.h>
#include "circularbuffer.hpp"

PMCircularBuffer::PMCircularBuffer(uint8_t* buffer, size_t size) :
	m_buffer{buffer}, m_size{size} {

	}

bool PMCircularBuffer::isFull() const {
	return m_full;
}

bool PMCircularBuffer::isEmpty() const {
	return (!m_full && this->m_head == this->m_tail);
}

void PMCircularBuffer::advancePointer() {
	if(this->m_full) {
		this->m_tail = (this->m_tail + 1) % this->m_size;
	}
	this->m_head = (this->m_head + 1) % this->m_size;
	this->m_full = (this->m_head == this->m_tail);
}
void PMCircularBuffer::retreatPointer() {
	this->m_full = false;
	this->m_tail = (this->m_tail +1) % this->m_size;
}
void PMCircularBuffer::put(uint8_t data) {
	this->m_buffer[this->m_head] = data;
	advancePointer();
}
void PMCircularBuffer::printValues() {
	for(uint8_t i = 0; i < this->m_size; ++i) {
		Serial.print(this->m_buffer[i]);
		Serial.print(" ");
	}
	Serial.print("\n");
}

void PMCircularBuffer::clearBuffer() {
	this->m_head = 0;
	this->m_tail = 0;
	for(uint8_t i = 0; i < this->m_size; ++i) {
		put(0);
	}
	this->m_full = 0;
}
