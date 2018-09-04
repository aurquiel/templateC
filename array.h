#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include "allocator.h"


void InterchangeArrayGeneric(void* a, void *b, int64_t sizeA, int64_t sizeB, int8_t typePointer);
void CopyArray(void* arrayDestiny, void* arraySource, int64_t numberBytes, int8_t typeData);
void ConcatenateCharArray(void* arrayDestiny, void* arraySource, int8_t typeData);
void ClearArray(void* arrayDestiny,int64_t numberBytes, int8_t typeData);
void SetArray(void* arrayDestiny, unsigned char character, int64_t numberBytes, int8_t typeData);

#endif // ARRAY_H_INCLUDED