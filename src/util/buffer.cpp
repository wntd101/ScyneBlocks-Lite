#include <util/buffer.h>

void Buffer::bind(unsigned int type, int size, float data[], unsigned int mode)
{
	glGenBuffers(1, &id);
	glBindBuffer(type, id);
	glBufferData(type, size, data, mode);
}

void Buffer::bind(unsigned int type, int size, int data[], unsigned int mode)
{
	glGenBuffers(1, &id);
	glBindBuffer(type, id);
	glBufferData(type, size, data, mode);
}