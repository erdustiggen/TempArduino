#pragma once

class PMCircularBuffer {
private:
	uint8_t * m_buffer;
    size_t m_head;
    size_t m_tail;
    size_t m_size; //of the buffer
    bool m_full = false;
	void resetBuffer();

public:
	bool isFull() const;
	bool isEmpty() const;
	void advancePointer();
	void retreatPointer();
	PMCircularBuffer(uint8_t* buffer, size_t size);
	void put(uint8_t data);
	void printValues();
	void clearBuffer();
};
