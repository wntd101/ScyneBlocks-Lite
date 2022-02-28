#pragma once
#include <main.h>

struct Buffer
{
	unsigned int id;
	void bind(unsigned int type, int size, float data[], unsigned int mode);
	void bind(unsigned int type, int size, int data[], unsigned int mode);
};