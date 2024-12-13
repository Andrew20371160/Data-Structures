#ifndef _vector_h_
#define _vector_h_
	#include <stdio.h>
	#include <stdlib.h>
	#include <stdint.h>
	//replace wanted data type with int
	#define DataType int

	#define true 1
	#define false 0
	#define bool uint8_t

	typedef struct vector
	{
		DataType*arr;
		uint32_t size;
		uint32_t elements_count;

	}vector;
	//assumes vector is just initialized with no memory in it
	//if there is memory in it memory leak would happen
	//initializes it with wanted size
	bool init_vector(vector*,uint32_t);
	bool remove_vector(vector*);
	//insert data at position if it's in range of elements count
	//it allocates needed memory if vector is full
	bool insert(vector*,DataType,uint32_t) ;
	//removes a position in vector
	bool remove_position(vector*,uint32_t);
	//removes first found instance of data in vector
	bool remove_data(vector*,DataType);
	//resizes vector to wanted size
	bool resize(vector*,uint32_t);
	//copy size ,contents of src vector into dest vec
	bool copy(vector*dest,vector*src) ;









#endif
