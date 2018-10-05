#ifndef ARRAY_C_INCLUDED
#define ARRAY_C_INCLUDED

#include "array.h"

void _ArrayInterchange(void* arrayA, const uint32_t sizeArrayA, void* arrayB, const uint32_t sizeArrayB, const int8_t typeData, const char* functionName, const char* fileName, const uint32_t lineNumber)
{
    if((sizeArrayA <= 0) || (sizeArrayB <= 0) || (sizeArrayA != sizeArrayB))
    {
        ErrorRaise(errorSizeArray, fileName, functionName, lineNumber);
    }

    void *auxiliarArray = AllocatorCalloc(sizeArrayA, typeData);

    ArrayCopy(auxiliarArray, sizeArrayA, arrayA, sizeArrayA, typeData);
    ArrayCopy(arrayA, sizeArrayA, arrayB, sizeArrayB, typeData);
    ArrayCopy(arrayB, sizeArrayB, auxiliarArray, sizeArrayA, typeData);
    AllocatorFree(auxiliarArray);
}

void _ArrayCopy(void* arrayDestiny, const uint32_t sizeArrayDestiny, void* arraySource, const uint32_t sizeArraySource, const int8_t typeData, const char* fileName, const char* functionName, const uint32_t lineNumber)
{
    if( (sizeArrayDestiny <= 0) || (sizeArraySource <= 0) || (sizeArrayDestiny < sizeArraySource) )
    {
        ErrorRaise(errorSizeArray, fileName, functionName, lineNumber);
    }

    if(typeData == CHAR)
    {
        memcpy((char*)arrayDestiny, (char*)arraySource, sizeof(char)*sizeArraySource);
    }
    else if (typeData == UNSIGNED_CHAR)
    {
        memcpy((unsigned char*)arrayDestiny, (unsigned char*)arraySource, sizeof(unsigned char)*sizeArraySource);
    }
    else if(typeData == INT8)
    {
        memcpy((int8_t*)arrayDestiny, (int8_t*)arraySource, sizeof(int8_t)*sizeArraySource);
    }
    else if(typeData == UNSIGNED_INT8)
    {
        memcpy((uint8_t*)arrayDestiny, (uint8_t*)arraySource, sizeof(uint8_t)*sizeArraySource);
    }
    else if(typeData == INT16)
    {
        memcpy((int16_t*)arrayDestiny, (int16_t*)arraySource, sizeof(int16_t)*sizeArraySource);
    }
    else if(typeData == UNSIGNED_INT16)
    {
        memcpy((uint16_t*)arrayDestiny, (uint16_t*)arraySource,  sizeof(uint16_t)*sizeArraySource);
    }
    else if(typeData == INT32)
    {
        memcpy((int32_t*)arrayDestiny, (int32_t*)arraySource,  sizeof(int32_t)*sizeArraySource);
    }
    else if(typeData == UNSIGNED_INT32)
    {
        memcpy((uint32_t*)arrayDestiny, (uint32_t*)arraySource,  sizeof(uint32_t)*sizeArraySource);
    }
    else if(typeData == FLOAT)
    {
        memcpy((float*)arrayDestiny, (float*)arraySource,  sizeof(float)*sizeArraySource);
    }
    else if(typeData == DOUBLE)
    {
        memcpy((double*)arrayDestiny, (double*)arraySource,  sizeof(double)*sizeArraySource);
    }
    else
    {
        ErrorRaise(errorTypeArray, fileName, functionName, lineNumber);
    }
}

void _ArrayConcatenate(void* arrayDestiny, const uint32_t sizeArrayDestiny, void* arraySource, const uint32_t sizeArraySource, const int8_t typeData, const char* fileName, const char* functionName, const uint32_t lineNumber)
{
    if( (sizeArrayDestiny <= 0) )
    {
        ErrorRaise(errorSizeArray, fileName, functionName, lineNumber);
    }

    if(typeData == CHAR)
    {
        memcpy((char*)arrayDestiny + sizeArrayDestiny, (unsigned char*)arraySource, sizeArraySource);
    }
    else if(typeData == UNSIGNED_CHAR)
    {
        memcpy((unsigned char*)arrayDestiny + sizeArrayDestiny, (unsigned char*)arraySource, sizeArraySource);
    }
    else if(typeData == INT8)
    {
        memcpy((unsigned char*)arrayDestiny + sizeArrayDestiny, (unsigned char*)arraySource, sizeof(int8_t)*sizeArraySource);
    }
    else if(typeData == UNSIGNED_INT8)
    {
        memcpy((uint8_t*)arrayDestiny + sizeArrayDestiny, (uint8_t*)arraySource, sizeof(uint8_t)*sizeArraySource);
    }
    else if(typeData == INT16)
    {
        memcpy((int16_t*)arrayDestiny + sizeArrayDestiny, (int16_t*)arraySource, sizeof(int16_t)*sizeArraySource);
    }
    else if(typeData == UNSIGNED_INT16)
    {
        memcpy((uint16_t*)arrayDestiny + sizeArrayDestiny, (uint16_t*)arraySource, sizeof(uint16_t)*sizeArraySource);
    }
    else if(typeData == INT32)
    {
        memcpy((int32_t*)arrayDestiny + sizeArrayDestiny, (int32_t*)arraySource, sizeof(int32_t)*sizeArraySource);
    }
    else if(typeData == UNSIGNED_INT32)
    {
        memcpy((uint32_t*)arrayDestiny + sizeArrayDestiny, (uint32_t*)arraySource, sizeof(uint32_t)*sizeArraySource);
    }
    else if(typeData == FLOAT)
    {
        memcpy((float*)arrayDestiny + sizeArrayDestiny, (float*)arraySource, sizeof(float)*sizeArraySource);
    }
    else if(typeData == DOUBLE)
    {
        memcpy((double*)arrayDestiny + sizeArrayDestiny, (double*)arraySource, sizeof(double)*sizeArraySource);
    }
    else
    {
        ErrorRaise(errorTypeArray, fileName, functionName, lineNumber);
    }
}

void _ArrayClear(void* array, const uint32_t sizeArray, const int8_t typeData, const char* fileName, const char* functionName, const uint32_t lineNumber)
{
    if(sizeArray <= 0)
    {
        ErrorRaise(errorSizeArray, fileName, functionName, lineNumber);
    }

    const char emptyEscape = EMPTY_ESCAPE;
    const int8_t zero = ZERO;

    if( (typeData == CHAR) || (typeData == UNSIGNED_CHAR))
    {
        ArraySet(array, sizeArray, (void*)(&emptyEscape), typeData);
    }
    else if( (typeData >= INT8) && (typeData <= DOUBLE) )
    {
        ArraySet(array, sizeArray, (void*)(&zero), typeData);
    }
    else
    {
         ErrorRaise(errorTypeArray, fileName, functionName, lineNumber);
    }
}

void _ArraySet(void* array, const uint32_t sizeArray, void *data, const int8_t typeData, const char* functionName, const char* fileName, const uint32_t lineNumber)
{
    if(sizeArray <= 0)
    {
        ErrorRaise(errorSizeArray, fileName, functionName, lineNumber);
    }

    if(typeData == CHAR)
    {
        memset( (char*)array, *((char*)data), sizeof(char)*sizeArray);
    }
    else if (typeData == UNSIGNED_CHAR)
    {
        memset((unsigned char*)array, *((unsigned char*)data), sizeof(unsigned char)*sizeArray);
    }
    else if(typeData == INT8)
    {
        memset((int8_t*)array, *((int8_t*)data), sizeof(int8_t)*sizeArray);
    }
    else if(typeData == UNSIGNED_INT8)
    {
        memset((uint8_t*)array, *((uint8_t*)data), sizeof(uint8_t)*sizeArray);
    }
    else if(typeData == INT16)
    {
        memset((int16_t*)array, *((int16_t*)data), sizeof(int16_t)*sizeArray);
    }
    else if(typeData == UNSIGNED_INT16)
    {
        memset((uint16_t*)array, *((uint16_t*)data), sizeof(uint16_t)*sizeArray);
    }
    else if(typeData == INT32)
    {
        memset((int32_t*)array, *((int32_t*)data), sizeof(int32_t)*sizeArray);
    }
    else if(typeData == UNSIGNED_INT32)
    {
        memset((uint32_t*)array, *((uint32_t*)data), sizeof(uint32_t)*sizeArray);
    }
    else if(typeData == FLOAT)
    {
        memset((float*)array, *((float*)data), sizeof(float)*sizeArray);
    }
    else if(typeData == DOUBLE)
    {
        memset((double*)array, *((double*)data), sizeof(double)*sizeArray);
    }
    else
    {
        ErrorRaise(errorTypeArray, fileName, functionName, lineNumber);
    }
}

void* _ArrayFind(const void* array, const uint32_t sizeArray, void *data, const int8_t typeData, const char* fileName, const char* functionName, const uint32_t lineNumber)
{
    if(sizeArray <= 0)
    {
        ErrorRaise(errorSizeArray, fileName, functionName, lineNumber);
    }

    if(typeData == CHAR)
    {
        for(uint32_t i = 0; i<sizeArray; i++)
        {
            if( *((char*)array + i) == *((char*)data))
            {
                return ((char*)array + i);
            }
        }
    }
    else if(typeData == UNSIGNED_CHAR)
    {
        for(uint32_t i = 0; i<sizeArray; i++)
        {
            if( *((unsigned char*)array + i) == *((unsigned char*)data))
            {
                return ((unsigned char*)array + i);
            }
        }
    }
    else if(typeData == INT8)
    {
        for(uint32_t i = 0; i<sizeArray; i++)
        {
            if( *((int8_t*)array + i) == *((int8_t*)data))
            {
                return ((int8_t*)array + i);
            }
        }
    }
    else if(typeData == UNSIGNED_INT8)
    {
        for(uint32_t i = 0; i<sizeArray; i++)
        {
            if( *((uint8_t*)array + i) == *((uint8_t*)data))
            {
                return ((uint8_t*)array + i);
            }
        }
    }
    else if(typeData == INT16)
    {
        for(uint32_t i = 0; i<sizeArray; i++)
        {
            if( *((int16_t*)array + i) == *((int16_t*)data))
            {
                return ((int16_t*)array + i);
            }
        }
    }
    else if(typeData == UNSIGNED_INT16)
    {
        for(uint32_t i = 0; i<sizeArray; i++)
        {
            if( *((uint16_t*)array + i) == *((uint16_t*)data))
            {
                return ((uint16_t*)array + i);
            }
        }
    }
    else if(typeData == INT32)
    {
        for(uint32_t i = 0; i<sizeArray; i++)
        {
            if( *((int32_t*)array + i) == *((int32_t*)data))
            {
                return ((int32_t*)array + i);
            }
        }
    }
    else if(typeData == UNSIGNED_INT32)
    {
        for(uint32_t i = 0; i<sizeArray; i++)
        {
            if( *((uint32_t*)array + i) == *((uint32_t*)data))
            {
                return ((uint32_t*)array + i);
            }
        }
    }
    else if(typeData == FLOAT)
    {
        for(uint32_t i = 0; i<sizeArray; i++)
        {
            if( *((float*)array + i) == *((float*)data))
            {
                return ((float*)array + i);
            }
        }
    }
    else if(typeData == DOUBLE)
    {
        for(uint32_t i = 0; i<sizeArray; i++)
        {
            if( *((double*)array + i) == *((double*)data))
            {
                return ((double*)array + i);
            }
        }
    }
    else
    {
        ErrorRaise(errorTypeArray, fileName, functionName, lineNumber);
    }

    return NULL;
}

void* _ArrayFindMaxValue(const void* array, const uint32_t sizeArray, const int8_t typeData, const char* fileName, const char* functionName, const uint32_t lineNumber)
{
    if(sizeArray <= 0)
    {
        ErrorRaise(errorSizeArray, fileName, functionName, lineNumber);
    }

    if(typeData == CHAR)
    {
        char *maxValue = (char*)array;

        for(uint32_t i = 0; i<sizeArray; i++)
        {
            if( *((char*)array + i) > *maxValue)
            {
                maxValue = ((char*)array + i);
            }
        }

        return maxValue;
    }
    else if(typeData == UNSIGNED_CHAR)
    {
        unsigned char *maxValue = (unsigned char*)array;

        for(uint32_t i = 0; i<sizeArray; i++)
        {
            if( *((unsigned char*)array + i) > *maxValue)
            {
                maxValue = ((unsigned char*)array + i);
            }
        }

        return maxValue;
    }
    else if(typeData == INT8)
    {
        int8_t *maxValue = (int8_t*)array;

        for(uint32_t i = 0; i<sizeArray; i++)
        {
            if( *((int8_t*)array + i) > *maxValue)
            {
                maxValue = ((int8_t*)array + i);
            }
        }

        return maxValue;
    }
    else if(typeData == UNSIGNED_INT8)
    {
        uint8_t *maxValue = (uint8_t*)array;

        for(uint32_t i = 0; i<sizeArray; i++)
        {
            if( *((uint8_t*)array + i) > *maxValue)
            {
                maxValue = ((uint8_t*)array + i);
            }
        }

        return maxValue;
    }
    else if(typeData == INT16)
    {
        int16_t *maxValue = (int16_t*)array;

        for(uint32_t i = 0; i<sizeArray; i++)
        {
            if( *((int16_t*)array + i) > *maxValue)
            {
                maxValue = ((int16_t*)array + i);
            }
        }

        return maxValue;
    }
    else if(typeData == UNSIGNED_INT16)
    {
        uint16_t *maxValue = (uint16_t*)array;

        for(uint32_t i = 0; i<sizeArray; i++)
        {
            if( *((uint16_t*)array + i) > *maxValue)
            {
                maxValue = ((uint16_t*)array + i);
            }
        }

        return maxValue;
    }
    else if(typeData == INT32)
    {
        int32_t *maxValue = (int32_t*)array;

        for(uint32_t i = 0; i<sizeArray; i++)
        {
            if( *((int32_t*)array + i) > *maxValue)
            {
                maxValue = ((int32_t*)array + i);
            }
        }

        return maxValue;
    }
    else if(typeData == UNSIGNED_INT32)
    {
        uint32_t *maxValue = (uint32_t*)array;

        for(uint32_t i = 0; i<sizeArray; i++)
        {
            if( *((uint32_t*)array + i) > *maxValue)
            {
                maxValue = ((uint32_t*)array + i);
            }
        }

        return maxValue;
    }
    else if(typeData == FLOAT)
    {
        float *maxValue = (float*)array;

        for(uint32_t i = 0; i<sizeArray; i++)
        {
            if( *((float*)array + i) > *maxValue)
            {
                maxValue = ((float*)array + i);
            }
        }

        return maxValue;
    }
    else if(typeData == DOUBLE)
    {
        double *maxValue = (double*)array;

        for(uint32_t i = 0; i<sizeArray; i++)
        {
            if( *((double*)array + i) > *maxValue)
            {
                maxValue = ((double*)array + i);
            }
        }

        return maxValue;
    }
    else
    {
        ErrorRaise(errorTypeArray, fileName, functionName, lineNumber);
    }

    return NULL;
}

void* _ArrayFindMInimumValue(const void* array, const uint32_t sizeArray, const int8_t typeData, const char* fileName, const char* functionName, const uint32_t lineNumber)
{
    if(sizeArray <= 0)
    {
        ErrorRaise(errorSizeArray, fileName, functionName, lineNumber);
    }

    if(typeData == CHAR)
    {
        char *minimumValue = (char*)array;

        for(uint32_t i = 0; i<sizeArray; i++)
        {
            if( *((char*)array + i) < *minimumValue)
            {
                minimumValue = ((char*)array + i);
            }
        }

        return minimumValue;
    }
    else if(typeData == UNSIGNED_CHAR)
    {
        unsigned char *minimumValue= (unsigned char*)array;

        for(uint32_t i = 0; i<sizeArray; i++)
        {
            if( *((unsigned char*)array + i) < *minimumValue)
            {
                minimumValue = ((unsigned char*)array + i);
            }
        }

        return minimumValue;
    }
    else if(typeData == INT8)
    {
        int8_t *minimumValue = (int8_t*)array;

        for(uint32_t i = 0; i<sizeArray; i++)
        {
            if( *((int8_t*)array + i) < *minimumValue)
            {
                minimumValue = ((int8_t*)array + i);
            }
        }

        return minimumValue;
    }
    else if(typeData == UNSIGNED_INT8)
    {
        uint8_t *minimumValue = (uint8_t*)array;

        for(uint32_t i = 0; i<sizeArray; i++)
        {
            if( *((uint8_t*)array + i) < *minimumValue)
            {
                minimumValue = ((uint8_t*)array + i);
            }
        }

        return minimumValue;
    }
    else if(typeData == INT16)
    {
        int16_t *minimumValue = (int16_t*)array;

        for(uint32_t i = 0; i<sizeArray; i++)
        {
            if( *((int16_t*)array + i) < *minimumValue)
            {
                minimumValue= ((int16_t*)array + i);
            }
        }

        return minimumValue;
    }
    else if(typeData == UNSIGNED_INT16)
    {
        uint16_t *minimumValue = (uint16_t*)array;

        for(uint32_t i = 0; i<sizeArray; i++)
        {
            if( *((uint16_t*)array + i) < *minimumValue)
            {
                minimumValue = ((uint16_t*)array + i);
            }
        }

        return minimumValue;
    }
    else if(typeData == INT32)
    {
        int32_t *minimumValue = (int32_t*)array;

        for(uint32_t i = 0; i<sizeArray; i++)
        {
            if( *((int32_t*)array + i) < *minimumValue)
            {
                minimumValue = ((int32_t*)array + i);
            }
        }

        return minimumValue;
    }
    else if(typeData == UNSIGNED_INT32)
    {
        uint32_t *minimumValue = (uint32_t*)array;

        for(uint32_t i = 0; i<sizeArray; i++)
        {
            if( *((uint32_t*)array + i) < *minimumValue)
            {
                minimumValue = ((uint32_t*)array + i);
            }
        }

        return minimumValue;
    }
    else if(typeData == FLOAT)
    {
        float *minimumValue = (float*)array;

        for(uint32_t i = 0; i<sizeArray; i++)
        {
            if( *((float*)array + i) < *minimumValue)
            {
                minimumValue = ((float*)array + i);
            }
        }

        return minimumValue;
    }
    else if(typeData == DOUBLE)
    {
        double *minimumValue = (double*)array;

        for(uint32_t i = 0; i<sizeArray; i++)
        {
            if( *((double*)array + i) < *minimumValue)
            {
                minimumValue = ((double*)array + i);
            }
        }

        return minimumValue;
    }
    else
    {
        ErrorRaise(errorTypeArray, fileName, functionName, lineNumber);
    }

    return NULL;
}

uint32_t _ArrayFindNumberRepetitions(const void* array, const uint32_t sizeArray, void *data, const int8_t typeData, const char* fileName,  const char* functionName, const uint32_t lineNumber)
{
    if(sizeArray <= 0)
    {
        ErrorRaise(errorSizeArray, fileName, functionName, lineNumber);
    }

    uint64_t numberRepetitions = 0;

    if(typeData == CHAR)
    {
        char *positionFound = (char*)array;
        uint32_t nextSizeArray = sizeArray;
        while( (nextSizeArray != 0) && (NULL != (positionFound = (char*)ArrayFind((char*)positionFound, nextSizeArray, data, typeData))) )
        {
            positionFound++;
            numberRepetitions++;
            nextSizeArray = (sizeArray - ((char*)positionFound - (char*)array));
        }
    }
    else if (typeData == UNSIGNED_CHAR)
    {
        unsigned char *positionFound = (unsigned char*)array;
        uint32_t nextSizeArray = sizeArray;
        while( (nextSizeArray != 0) && (NULL != (positionFound = (unsigned char*)ArrayFind((unsigned char*)positionFound, nextSizeArray, data, typeData))) )
        {
            positionFound++;
            numberRepetitions++;
            nextSizeArray = (sizeArray - ((unsigned char*)positionFound - (unsigned char*)array));
        }
    }
    else if(typeData == INT8)
    {
        int8_t *positionFound = (int8_t*)array;
        uint32_t nextSizeArray = sizeArray;
        while( (nextSizeArray != 0) && (NULL != (positionFound = (int8_t*)ArrayFind((int8_t*)positionFound, nextSizeArray, data, typeData))) )
        {
            positionFound++;
            numberRepetitions++;
            nextSizeArray = (sizeArray - ((int8_t*)positionFound - (int8_t*)array));
        }
    }
    else if(typeData == UNSIGNED_INT8)
    {
        uint8_t *positionFound = (uint8_t*)array;
        uint32_t nextSizeArray = sizeArray;
        while( (nextSizeArray != 0) && (NULL != (positionFound = (uint8_t*)ArrayFind((uint8_t*)positionFound, nextSizeArray, data, typeData))) )
        {
            positionFound++;
            numberRepetitions++;
            nextSizeArray = (sizeArray - ((uint8_t*)positionFound - (uint8_t*)array));
        }
    }
    else if(typeData == INT16)
    {
        int16_t *positionFound = (int16_t*)array;
        uint32_t nextSizeArray = sizeArray;
        while( (nextSizeArray != 0) && (NULL != (positionFound = (int16_t*)ArrayFind((int16_t*)positionFound, nextSizeArray, data, typeData))) )
        {
            positionFound++;
            numberRepetitions++;
            nextSizeArray = (sizeArray - ((int16_t*)positionFound - (int16_t*)array));
        }
    }
    else if(typeData == UNSIGNED_INT16)
    {
        uint16_t *positionFound = (uint16_t*)array;
        uint32_t nextSizeArray = sizeArray;
        while( (nextSizeArray != 0) && (NULL != (positionFound = (uint16_t*)ArrayFind((uint16_t*)positionFound, nextSizeArray, data, typeData))) )
        {
            positionFound++;
            numberRepetitions++;
            nextSizeArray = (sizeArray - ((uint16_t*)positionFound - (uint16_t*)array));
        }
    }
    else if(typeData == INT32)
    {
        int32_t *positionFound = (int32_t*)array;
        uint32_t nextSizeArray = sizeArray;
        while( (nextSizeArray != 0) && (NULL != (positionFound = (int32_t*)ArrayFind((int32_t*)positionFound, nextSizeArray, data, typeData))) )
        {
            positionFound++;
            numberRepetitions++;
            nextSizeArray = (sizeArray - ((int32_t*)positionFound - (int32_t*)array));
        }
    }
    else if(typeData == UNSIGNED_INT32)
    {
        uint32_t *positionFound = (uint32_t*)array;
        uint32_t nextSizeArray = sizeArray;
        while( (nextSizeArray != 0) && (NULL != (positionFound = (uint32_t*)ArrayFind((uint32_t*)positionFound, nextSizeArray, data, typeData))) )
        {
            positionFound++;
            numberRepetitions++;
            nextSizeArray = (sizeArray - ((uint32_t*)positionFound - (uint32_t*)array));
        }
    }
    else if(typeData == FLOAT)
    {
        float *positionFound = (float*)array;
        uint32_t nextSizeArray = sizeArray;
        while( (nextSizeArray != 0) && (NULL != (positionFound = (float*)ArrayFind((float*)positionFound, nextSizeArray, data, typeData))) )
        {
            positionFound++;
            numberRepetitions++;
            nextSizeArray = (sizeArray - ((float*)positionFound - (float*)array));
        }
    }
    else if(typeData == DOUBLE)
    {
        double *positionFound = (double*)array;
        uint32_t nextSizeArray = sizeArray;
        while( (nextSizeArray != 0) && (NULL != (positionFound = (double*)ArrayFind((double*)positionFound, nextSizeArray, data, typeData))) )
        {
            positionFound++;
            numberRepetitions++;
            nextSizeArray = (sizeArray - ((double*)positionFound - (double*)array));
        }
    }
    else
    {
        ErrorRaise(errorTypeArray, fileName, functionName, lineNumber);
    }

    return numberRepetitions;
}

void _ArrayEndChar(void* array, const uint32_t sizeArray, const int8_t typeData, const char* fileName,  const char* functionName, const uint32_t lineNumber)
{
    if(sizeArray <= 0)
    {
        ErrorRaise(errorSizeArray, fileName, functionName, lineNumber);
    }


    if(typeData == CHAR)
    {
        memset(((char*)array + sizeArray -1), EMPTY_ESCAPE, 1);
    }
    else if (typeData == UNSIGNED_CHAR)
    {
        memset(((unsigned char*)array + sizeArray - 1), EMPTY_ESCAPE, 1);
    }
    else
    {
        ErrorRaise(errorTypeArray, fileName, functionName, lineNumber);
    }
}


void _ArrayReverse(void *array, const uint32_t sizeArray, const int8_t typeData, const char* fileName, const char* functionName, const uint32_t lineNumber)
{
    if( sizeArray <= 0 )
    {
        ErrorRaise(errorSizeArray, fileName, functionName, lineNumber);
    }

    if(typeData == CHAR)
    {
        for(char *i = (char*)array, *j = (char*)array + sizeArray - 2 ;  i < j ; i++, j--)
        {
            SwapXor(i,j,typeData);
        }

    }
    else if (typeData == UNSIGNED_CHAR)
    {
        for(unsigned char *i = (unsigned char*)array, *j = (unsigned char*)array + sizeArray - 2 ;  i < j ; i++, j--)
        {
            SwapXor(i,j,typeData);
        }
    }
    else if(typeData == INT8)
    {
        for(int8_t *i = (int8_t*)array, *j = (int8_t*)array + sizeArray - 1 ;  i < j ; i++, j--)
        {
            SwapXor(i,j,typeData);
        }
    }
    else if(typeData == UNSIGNED_INT8)
    {
        for(uint8_t *i = (uint8_t*)array, *j = (uint8_t*)array + sizeArray - 1 ;  i < j ; i++, j--)
        {
            SwapXor(i,j,typeData);
        }
    }
    else if(typeData == INT16)
    {
        for(int16_t *i = (int16_t*)array, *j = (int16_t*)array + sizeArray - 1 ;  i < j ; i++, j--)
        {
            SwapXor(i,j,typeData);
        }
    }
    else if(typeData == UNSIGNED_INT16)
    {
        for(uint16_t *i = (uint16_t*)array, *j = (uint16_t*)array + sizeArray - 1 ;  i < j ; i++, j--)
        {
            SwapXor(i,j,typeData);
        }
    }
    else if(typeData == INT32)
    {
        for(int32_t *i = (int32_t*)array, *j = (int32_t*)array + sizeArray - 1 ;  i < j ; i++, j--)
        {
            SwapXor(i,j,typeData);
        }
    }
    else if(typeData == UNSIGNED_INT32)
    {
        for(uint32_t *i = (uint32_t*)array, *j = (uint32_t*)array + sizeArray - 1 ;  i < j ; i++, j--)
        {
            SwapXor(i,j,typeData);
        }
    }
    else if(typeData == FLOAT)
    {
        for(float *i = (float*)array, *j = (float*)array + sizeArray - 1 ;  i < j ; i++, j--)
        {
            Swap(i,j,typeData);
        }
    }
    else if(typeData == DOUBLE)
    {
        for(double *i = (double*)array, *j = (double*)array + sizeArray - 1 ;  i < j ; i++, j--)
        {
            Swap(i,j,typeData);
        }
    }
    else
    {
        ErrorRaise(errorTypeArray, fileName, functionName, lineNumber);
    }
}

void _ArrayReverseInterval(void *array, const uint32_t sizeArray, void* lowerLimit, void* upperLimit, const int8_t typeData, const char* fileName, const char* functionName, const uint32_t lineNumber)
{
    if( sizeArray <= 0 )
    {
        ErrorRaise(errorSizeArray, fileName, functionName, lineNumber);
    }
    else if( (lowerLimit < array) || upperLimit < lowerLimit )
    {
        exit(errorBoundaryLimits);
    }

    if(typeData == CHAR)
    {
        for(char *i = (char*)lowerLimit, *j = (char*)upperLimit;  i < j ; i++, j--)
        {
            SwapXor(i,j,typeData);
        }

    }
    else if (typeData == UNSIGNED_CHAR)
    {
        for(unsigned char *i = (unsigned char*)lowerLimit, *j = (unsigned char*)upperLimit;  i < j ; i++, j--)
        {
            SwapXor(i,j,typeData);
        }
    }
    else if(typeData == INT8)
    {
        for(int8_t *i = (int8_t*)lowerLimit, *j = (int8_t*)upperLimit;  i < j ; i++, j--)
        {
            SwapXor(i,j,typeData);
        }
    }
    else if(typeData == UNSIGNED_INT8)
    {
        for(uint8_t *i = (uint8_t*)lowerLimit, *j = (uint8_t*)upperLimit;  i < j ; i++, j--)
        {
            SwapXor(i,j,typeData);
        }
    }
    else if(typeData == INT16)
    {
        for(int16_t *i = (int16_t*)lowerLimit, *j = (int16_t*)upperLimit;  i < j ; i++, j--)
        {
            SwapXor(i,j,typeData);
        }
    }
    else if(typeData == UNSIGNED_INT16)
    {
        for(uint16_t *i = (uint16_t*)lowerLimit, *j = (uint16_t*)upperLimit;  i < j ; i++, j--)
        {
            SwapXor(i,j,typeData);
        }
    }
    else if(typeData == INT32)
    {
        for(int32_t *i = (int32_t*)lowerLimit, *j = (int32_t*)upperLimit;  i < j ; i++, j--)
        {
            SwapXor(i,j,typeData);
        }
    }
    else if(typeData == UNSIGNED_INT32)
    {
        for(uint32_t *i = (uint32_t*)lowerLimit, *j = (uint32_t*)upperLimit;  i < j ; i++, j--)
        {
            SwapXor(i,j,typeData);
        }
    }
    else if(typeData == FLOAT)
    {
        for(float *i = (float*)lowerLimit, *j = (float*)upperLimit;  i < j ; i++, j--)
        {
            Swap(i,j,typeData);
        }
    }
    else if(typeData == DOUBLE)
    {
        for(double *i = (double*)lowerLimit, *j = (double*)upperLimit;  i < j ; i++, j--)
        {
            Swap(i,j,typeData);
        }
    }
    else
    {
        ErrorRaise(errorTypeArray, fileName, functionName, lineNumber);
    }
}

void _ArrayReplaceAll(void *array, const uint32_t sizeArray, const void* data, const int8_t typeData, const char* fileName, const char* functionName, const uint32_t lineNumber)
{
    if( sizeArray <= 0 )
    {
        ErrorRaise(errorSizeArray, fileName, functionName, lineNumber);
    }

    if(typeData == CHAR)
    {
        char *positionFound = (char*)array;
        uint32_t nextSizeArray = sizeArray;
        char dataAuxiliar = *((char*)data);
        while( (nextSizeArray != 0) && (NULL != (positionFound = (char*)ArrayFind((char*)positionFound, nextSizeArray, (char*)&dataAuxiliar, typeData))) )
        {
            *(positionFound++) = dataAuxiliar;
            nextSizeArray = (sizeArray - ((char*)positionFound - (char*)array));
        }
    }
    else if (typeData == UNSIGNED_CHAR)
    {
        unsigned char *positionFound = (unsigned char*)array;
        uint32_t nextSizeArray = sizeArray;
        unsigned char dataAuxiliar = *((unsigned char*)data);
        while( (nextSizeArray != 0) && (NULL != (positionFound = (unsigned char*)ArrayFind((unsigned char*)positionFound, nextSizeArray, (unsigned char*)&dataAuxiliar, typeData))) )
        {
            *(positionFound++) = dataAuxiliar;
            nextSizeArray = (sizeArray - ((unsigned char*)positionFound - (unsigned char*)array));
        }
    }
    else if(typeData == INT8)
    {
        int8_t *positionFound = (int8_t*)array;
        uint32_t nextSizeArray = sizeArray;
        int8_t dataAuxiliar = *((int8_t*)data);
        while( (nextSizeArray != 0) && (NULL != (positionFound = (int8_t*)ArrayFind((int8_t*)positionFound, nextSizeArray, (int8_t*)&dataAuxiliar, typeData))) )
        {
            *(positionFound++) = dataAuxiliar;
            nextSizeArray = (sizeArray - ((int8_t*)positionFound - (int8_t*)array));
        }
    }
    else if(typeData == UNSIGNED_INT8)
    {
        uint8_t *positionFound = (uint8_t*)array;
        uint32_t nextSizeArray = sizeArray;
        uint8_t dataAuxiliar = *((uint8_t*)data);
        while( (nextSizeArray != 0) && (NULL != (positionFound = (uint8_t*)ArrayFind((uint8_t*)positionFound, nextSizeArray, (uint8_t*)&dataAuxiliar, typeData))) )
        {
            *(positionFound++) = dataAuxiliar;
            nextSizeArray = (sizeArray - ((uint8_t*)positionFound - (uint8_t*)array));
        }
    }
    else if(typeData == INT16)
    {
        int16_t *positionFound = (int16_t*)array;
        uint32_t nextSizeArray = sizeArray;
        int16_t dataAuxiliar = *((int16_t*)data);
        while( (nextSizeArray != 0) && (NULL != (positionFound = (int16_t*)ArrayFind((int16_t*)positionFound, nextSizeArray, (int16_t*)&dataAuxiliar, typeData))) )
        {
            *(positionFound++) = dataAuxiliar;
            nextSizeArray = (sizeArray - ((int16_t*)positionFound - (int16_t*)array));
        }
    }
    else if(typeData == UNSIGNED_INT16)
    {
        uint16_t *positionFound = (uint16_t*)array;
        uint32_t nextSizeArray = sizeArray;
        uint16_t dataAuxiliar = *((uint16_t*)data);
        while( (nextSizeArray != 0) && (NULL != (positionFound = (uint16_t*)ArrayFind((uint16_t*)positionFound, nextSizeArray, (uint16_t*)&dataAuxiliar, typeData))) )
        {
            *(positionFound++) = dataAuxiliar;
            nextSizeArray = (sizeArray - ((uint16_t*)positionFound - (uint16_t*)array));
        }
    }
    else if(typeData == INT32)
    {
        int32_t *positionFound = (int32_t*)array;
        uint32_t nextSizeArray = sizeArray;
        int32_t dataAuxiliar = *((int32_t*)data);
        while( (nextSizeArray != 0) && (NULL != (positionFound = (int32_t*)ArrayFind((int32_t*)positionFound, nextSizeArray,(int32_t*)&dataAuxiliar, typeData))) )
        {
            *(positionFound++) = dataAuxiliar;
            nextSizeArray = (sizeArray - ((int32_t*)positionFound - (int32_t*)array));
        }
    }
    else if(typeData == UNSIGNED_INT32)
    {
        uint32_t *positionFound = (uint32_t*)array;
        uint32_t nextSizeArray = sizeArray;
        uint32_t dataAuxiliar = *((uint32_t*)data);
        while( (nextSizeArray != 0) && (NULL != (positionFound = (uint32_t*)ArrayFind((uint32_t*)positionFound, nextSizeArray, (uint32_t*)&dataAuxiliar, typeData))) )
        {
            *(positionFound++) = dataAuxiliar;
            nextSizeArray = (sizeArray - ((uint32_t*)positionFound - (uint32_t*)array));
        }
    }
    else if(typeData == FLOAT)
    {
        float *positionFound = (float*)array;
        uint32_t nextSizeArray = sizeArray;
        float dataAuxiliar = *((float*)data);
        while( (nextSizeArray != 0) && (NULL != (positionFound = (float*)ArrayFind((float*)positionFound, nextSizeArray, (float*)&dataAuxiliar, typeData))) )
        {
            *(positionFound++) = dataAuxiliar;
            nextSizeArray = (sizeArray - ((float*)positionFound - (float*)array));
        }
    }
    else if(typeData == DOUBLE)
    {
        double *positionFound = (double*)array;
        uint32_t nextSizeArray = sizeArray;
        double dataAuxiliar = *((double*)data);
        while( (nextSizeArray != 0) && (NULL != (positionFound = (double*)ArrayFind((double*)positionFound, nextSizeArray, (double*)&dataAuxiliar, typeData))) )
        {
            *(positionFound++) = dataAuxiliar;
            nextSizeArray = (sizeArray - ((double*)positionFound - (double*)array));
        }
    }
    else
    {
        ErrorRaise(errorTypeArray, fileName, functionName, lineNumber);
    }
}

void _ArrayReplaceFrequency(void *array, const uint32_t sizeArray, const void* data, uint32_t frequency, const int8_t typeData, const char* fileName, const char* functionName, const uint32_t lineNumber)
{
    if( sizeArray <= 0 )
    {
        ErrorRaise(errorSizeArray, fileName, functionName, lineNumber);
    }

    if(frequency <= 0)
    {
        exit(errorNegativeNumberArray);
    }

    if(typeData == CHAR)
    {
        char *positionFound = (char*)array;
        uint32_t nextSizeArray = sizeArray;
        char dataAuxiliar = *((char*)data);
        while( (frequency-- != 0) && (nextSizeArray != 0) && (NULL != (positionFound = (char*)ArrayFind((char*)positionFound, nextSizeArray, (char*)&dataAuxiliar, typeData))) )
        {
            *(positionFound++) = dataAuxiliar;
            nextSizeArray = (sizeArray - ((char*)positionFound - (char*)array));
        }
    }
    else if (typeData == UNSIGNED_CHAR)
    {
        unsigned char *positionFound = (unsigned char*)array;
        uint32_t nextSizeArray = sizeArray;
        unsigned char dataAuxiliar = *((unsigned char*)data);
        while( (frequency-- != 0) && (nextSizeArray != 0) && (NULL != (positionFound = (unsigned char*)ArrayFind((unsigned char*)positionFound, nextSizeArray, (unsigned char*)&dataAuxiliar, typeData))) )
        {
            *(positionFound++) = dataAuxiliar;
            nextSizeArray = (sizeArray - ((unsigned char*)positionFound - (unsigned char*)array));
        }
    }
    else if(typeData == INT8)
    {
        int8_t *positionFound = (int8_t*)array;
        uint32_t nextSizeArray = sizeArray;
        int8_t dataAuxiliar = *((int8_t*)data);
        while( (frequency-- != 0) && (nextSizeArray != 0) && (NULL != (positionFound = (int8_t*)ArrayFind((int8_t*)positionFound, nextSizeArray, (int8_t*)&dataAuxiliar, typeData))) )
        {
            *(positionFound++) = dataAuxiliar;
            nextSizeArray = (sizeArray - ((int8_t*)positionFound - (int8_t*)array));
        }
    }
    else if(typeData == UNSIGNED_INT8)
    {
        uint8_t *positionFound = (uint8_t*)array;
        uint32_t nextSizeArray = sizeArray;
        uint8_t dataAuxiliar = *((uint8_t*)data);
        while( (frequency-- != 0) && (nextSizeArray != 0) && (NULL != (positionFound = (uint8_t*)ArrayFind((uint8_t*)positionFound, nextSizeArray, (uint8_t*)&dataAuxiliar, typeData))) )
        {
            *(positionFound++) = dataAuxiliar;
            nextSizeArray = (sizeArray - ((uint8_t*)positionFound - (uint8_t*)array));
        }
    }
    else if(typeData == INT16)
    {
        int16_t *positionFound = (int16_t*)array;
        uint32_t nextSizeArray = sizeArray;
        int16_t dataAuxiliar = *((int16_t*)data);
        while( (frequency-- != 0) && (nextSizeArray != 0) && (NULL != (positionFound = (int16_t*)ArrayFind((int16_t*)positionFound, nextSizeArray, (int16_t*)&dataAuxiliar, typeData))) )
        {
            *(positionFound++) = dataAuxiliar;
            nextSizeArray = (sizeArray - ((int16_t*)positionFound - (int16_t*)array));
        }
    }
    else if(typeData == UNSIGNED_INT16)
    {
        uint16_t *positionFound = (uint16_t*)array;
        uint32_t nextSizeArray = sizeArray;
        uint16_t dataAuxiliar = *((uint16_t*)data);
        while( (frequency-- != 0) && (nextSizeArray != 0) && (NULL != (positionFound = (uint16_t*)ArrayFind((uint16_t*)positionFound, nextSizeArray, (uint16_t*)&dataAuxiliar, typeData))) )
        {
            *(positionFound++) = dataAuxiliar;
            nextSizeArray = (sizeArray - ((uint16_t*)positionFound - (uint16_t*)array));
        }
    }
    else if(typeData == INT32)
    {
        int32_t *positionFound = (int32_t*)array;
        uint32_t nextSizeArray = sizeArray;
        int32_t dataAuxiliar = *((int32_t*)data);
        while( (frequency-- != 0) && (nextSizeArray != 0) && (NULL != (positionFound = (int32_t*)ArrayFind((int32_t*)positionFound, nextSizeArray, (int32_t*)&dataAuxiliar, typeData))) )
        {
            *(positionFound++) = dataAuxiliar;
            nextSizeArray = (sizeArray - ((int32_t*)positionFound - (int32_t*)array));
        }
    }
    else if(typeData == UNSIGNED_INT32)
    {
        uint32_t *positionFound = (uint32_t*)array;
        uint32_t nextSizeArray = sizeArray;
        uint32_t dataAuxiliar = *((uint32_t*)data);
        while( (frequency-- != 0) && (nextSizeArray != 0) && (NULL != (positionFound = (uint32_t*)ArrayFind((uint32_t*)positionFound, nextSizeArray, (uint32_t*)&dataAuxiliar, typeData))) )
        {
            *(positionFound++) = dataAuxiliar;
            nextSizeArray = (sizeArray - ((uint32_t*)positionFound - (uint32_t*)array));
        }
    }
    else if(typeData == FLOAT)
    {
        float *positionFound = (float*)array;
        uint32_t nextSizeArray = sizeArray;
        float dataAuxiliar = *((float*)data);
        while( (frequency-- != 0) && (nextSizeArray != 0) && (NULL != (positionFound = (float*)ArrayFind((float*)positionFound, nextSizeArray, (float*)&dataAuxiliar, typeData))) )
        {
            *(positionFound++) = dataAuxiliar;
            nextSizeArray = (sizeArray - ((float*)positionFound - (float*)array));
        }
    }
    else if(typeData == DOUBLE)
    {
        double *positionFound = (double*)array;
        uint32_t nextSizeArray = sizeArray;
        double dataAuxiliar = *((double*)data);
        while( (frequency-- != 0) && (nextSizeArray != 0) && (NULL != (positionFound = (double*)ArrayFind((double*)positionFound, nextSizeArray, (double*)&dataAuxiliar, typeData))) )
        {
            *(positionFound++) = dataAuxiliar;
            nextSizeArray = (sizeArray - ((double*)positionFound - (double*)array));
        }
    }
    else
    {
        ErrorRaise(errorTypeArray, fileName, functionName, lineNumber);
    }
}

void _ArrayFillSequency(void *array, const uint32_t sizeArray, const void* startPoint, const void* step, int8_t direction, const int8_t typeData, const char* fileName, const char* functionName, const uint32_t lineNumber)
{
    if( sizeArray <= 0 )
    {
        ErrorRaise(errorSizeArray, fileName, functionName, lineNumber);
    }

    if(typeData == CHAR)
    {
        for (uint32_t i = 0; i < sizeArray ; i++)
        {
            if(direction == TRUE)
            {
                *((char*)array + i) = *((char*)startPoint) + *((char*)step);
                *((char*)startPoint) += *((char*)step);
            }
            else
            {
                *((char*)array + i) = *((char*)startPoint) - *((char*)step);
                *((char*)startPoint) -= *((char*)step);
            }
        }
    }
    else if (typeData == UNSIGNED_CHAR)
    {
        for (uint32_t i = 0; i < sizeArray ; i++)
        {
            if(direction == TRUE)
            {
                *((unsigned char*)array + i) = *((unsigned char*)startPoint) + *((unsigned char*)step);
                *((unsigned char*)startPoint) += *((unsigned char*)step);
            }
            else
            {
                *((unsigned char*)array + i) = *((unsigned char*)startPoint) - *((unsigned char*)step);
                *((unsigned char*)startPoint) -= *((unsigned char*)step);
            }
        }
    }
    else if(typeData == INT8)
    {
        for (uint32_t i = 0; i < sizeArray ; i++)
        {
            if(direction == TRUE)
            {
                *((int8_t*)array + i) = *((int8_t*)startPoint) + *((int8_t*)step);
                *((int8_t*)startPoint) += *((int8_t*)step);
            }
            else
            {
                *((int8_t*)array + i) = *((int8_t*)startPoint) - *((int8_t*)step);
                *((int8_t*)startPoint) -= *((int8_t*)step);
            }
        }
    }
    else if(typeData == UNSIGNED_INT8)
    {
        for (uint32_t i = 0; i < sizeArray ; i++)
        {
            if(direction == TRUE)
            {
                *((uint8_t*)array + i) = *((uint8_t*)startPoint) + *((uint8_t*)step);
                *((uint8_t*)startPoint) += *((uint8_t*)step);
            }
            else
            {
                *((uint8_t*)array + i) = *((uint8_t*)startPoint) - *((uint8_t*)step);
                *((uint8_t*)startPoint) -= *((uint8_t*)step);
            }
        }
    }
    else if(typeData == INT16)
    {
        for (uint32_t i = 0; i < sizeArray ; i++)
        {
            if(direction == TRUE)
            {
                *((int16_t*)array + i) = *((int16_t*)startPoint) + *((int16_t*)step);
                *((int16_t*)startPoint) += *((int16_t*)step);
            }
            else
            {
                *((int16_t*)array + i) = *((int16_t*)startPoint) - *((int16_t*)step);
                *((int16_t*)startPoint) -= *((int16_t*)step);
            }
        }
    }
    else if(typeData == UNSIGNED_INT16)
    {
        for (uint32_t i = 0; i < sizeArray ; i++)
        {
            if(direction == TRUE)
            {
                *((uint16_t*)array + i) = *((uint16_t*)startPoint) + *((uint16_t*)step);
                *((uint16_t*)startPoint) += *((uint16_t*)step);
            }
            else
            {
                *((uint16_t*)array + i) = *((uint16_t*)startPoint) - *((uint16_t*)step);
                *((uint16_t*)startPoint) -= *((uint16_t*)step);
            }
        }
    }
    else if(typeData == INT32)
    {
        for (uint32_t i = 0; i < sizeArray ; i++)
        {
            if(direction == TRUE)
            {
                *((int32_t*)array + i) = *((int32_t*)startPoint) + *((int32_t*)step);
                *((int32_t*)startPoint) += *((int32_t*)step);
            }
            else
            {
                *((int32_t*)array + i) = *((int32_t*)startPoint) - *((int32_t*)step);
                *((int32_t*)startPoint) -= *((int32_t*)step);
            }
        }
    }
    else if(typeData == UNSIGNED_INT32)
    {
        for (uint32_t i = 0; i < sizeArray ; i++)
        {
            if(direction == TRUE)
            {
                *((uint32_t*)array + i) = *((uint32_t*)startPoint) + *((uint32_t*)step);
                *((uint32_t*)startPoint) += *((uint32_t*)step);
            }
            else
            {
                *((uint32_t*)array + i) = *((uint32_t*)startPoint) - *((uint32_t*)step);
                *((uint32_t*)startPoint) -= *((uint32_t*)step);
            }
        }
    }
    else if(typeData == FLOAT)
    {
        for (uint32_t i = 0; i < sizeArray ; i++)
        {
            if(direction == TRUE)
            {
                *((float*)array + i) = *((float*)startPoint) + *((float*)step);
                *((float*)startPoint) += *((float*)step);
            }
            else
            {
                *((float*)array + i) = *((float*)startPoint) - *((float*)step);
                *((float*)startPoint) -= *((float*)step);
            }
        }
    }
    else if(typeData == DOUBLE)
    {
        for (uint32_t i = 0; i < sizeArray ; i++)
        {
            if(direction == TRUE)
            {
                *((double*)array + i) = *((double*)startPoint) + *((double*)step);
                *((double*)startPoint) += *((double*)step);
            }
            else
            {
                *((double*)array + i) = *((double*)startPoint) - *((double*)step);
                *((double*)startPoint) -= *((double*)step);
            }
        }
    }
    else
    {
        ErrorRaise(errorTypeArray, fileName, functionName, lineNumber);
    }
}

void _ArrayMultiplied(void* array, const uint32_t sizeArray, const void* multipe, const int8_t typeData, const char* fileName, const char* functionName, const uint32_t lineNumber)
{
    if(sizeArray <= 0)
    {
        ErrorRaise(errorSizeArray, fileName, functionName, lineNumber);
    }

    if(typeData == CHAR)
    {
        for(uint32_t i = 0; i < sizeArray; i++)
        {
            *((char*)array + i) *= *((char*)multipe);
        }
    }
    else if (typeData == UNSIGNED_CHAR)
    {
        for(uint32_t i = 0; i < sizeArray; i++)
        {
            *((unsigned char*)array + i) *= *((unsigned char*)multipe);
        }
    }
    else if(typeData == INT8)
    {
        for(uint32_t i = 0; i < sizeArray; i++)
        {
            *((int8_t*)array + i) *= *((int8_t*)multipe);
        }
    }
    else if(typeData == UNSIGNED_INT8)
    {
        for(uint32_t i = 0; i < sizeArray; i++)
        {
            *((uint8_t*)array + i) *= *((uint8_t*)multipe);
        }
    }
    else if(typeData == INT16)
    {
        for(uint32_t i = 0; i < sizeArray; i++)
        {
            *((int16_t*)array + i) *= *((int16_t*)multipe);
        }
    }
    else if(typeData == UNSIGNED_INT16)
    {
        for(uint32_t i = 0; i < sizeArray; i++)
        {
            *((uint16_t*)array + i) *= *((uint16_t*)multipe);
        }
    }
    else if(typeData == INT32)
    {
        for(uint32_t i = 0; i < sizeArray; i++)
        {
            *((int32_t*)array + i) *= *((int32_t*)multipe);
        }
    }
    else if(typeData == UNSIGNED_INT32)
    {
        for(uint32_t i = 0; i < sizeArray; i++)
        {
            *((uint32_t*)array + i) *= *((uint32_t*)multipe);
        }
    }
    else if(typeData == FLOAT)
    {
        for(uint32_t i = 0; i < sizeArray; i++)
        {
            *((float*)array + i) *= *((float*)multipe);
        }
    }
    else if(typeData == DOUBLE)
    {
        for(uint32_t i = 0; i < sizeArray; i++)
        {
            *((double*)array + i) *= *((double*)multipe);
        }
    }
    else
    {
        ErrorRaise(errorTypeArray, fileName, functionName, lineNumber);
    }
}

uint32_t _ArrayCountSign(const void* array, const uint32_t sizeArray, const int8_t sign, const int8_t typeData, const char* fileName, const char* functionName, const uint32_t lineNumber)
{
    if(sizeArray <= 0)
    {
        ErrorRaise(errorSizeArray, fileName, functionName, lineNumber);
    }

    uint32_t negatives = 0;
    uint32_t positives = 0;

    if(typeData == CHAR)
    {
        for(uint32_t i = 0; i < sizeArray; i++)
        {
            if(*((char*)array + i) >= 0)
            {
                positives++;
            }
            else
            {
                negatives++;
            }
        }
    }
    else if (typeData == UNSIGNED_CHAR)
    {
        for(uint32_t i = 0; i < sizeArray; i++)
        {
            if(*((unsigned char*)array + i) >= 0)
            {
                positives++;
            }
            else
            {
                negatives++;
            }
        }
    }
    else if(typeData == INT8)
    {
        for(uint32_t i = 0; i < sizeArray; i++)
        {
            if(*((int8_t*)array + i) >= 0)
            {
                positives++;
            }
            else
            {
                negatives++;
            }
        }
    }
    else if(typeData == UNSIGNED_INT8)
    {
        for(uint32_t i = 0; i < sizeArray; i++)
        {
            if(*((uint8_t*)array + i) >= 0)
            {
                positives++;
            }
            else
            {
                negatives++;
            }
        }
    }
    else if(typeData == INT16)
    {
        for(uint32_t i = 0; i < sizeArray; i++)
        {
            if(*((int16_t*)array + i) >= 0)
            {
                positives++;
            }
            else
            {
                negatives++;
            }
        }
    }
    else if(typeData == UNSIGNED_INT16)
    {
        for(uint32_t i = 0; i < sizeArray; i++)
        {
            if(*((uint16_t*)array + i) >= 0)
            {
                positives++;
            }
            else
            {
                negatives++;
            }
        }
    }
    else if(typeData == INT32)
    {
        for(uint32_t i = 0; i < sizeArray; i++)
        {
            if(*((int32_t*)array + i) >= 0)
            {
                positives++;
            }
            else
            {
                negatives++;
            }
        }
    }
    else if(typeData == UNSIGNED_INT32)
    {
        for(uint32_t i = 0; i < sizeArray; i++)
        {
            if(*((uint32_t*)array + i) >= 0)
            {
                positives++;
            }
            else
            {
                negatives++;
            }
        }
    }
    else if(typeData == FLOAT)
    {
        for(uint32_t i = 0; i < sizeArray; i++)
        {
            if(*((float*)array + i) >= 0)
            {
                positives++;
            }
            else
            {
                negatives++;
            }
        }
    }
    else if(typeData == DOUBLE)
    {
        for(uint32_t i = 0; i < sizeArray; i++)
        {
            if(*((double*)array + i) >= 0)
            {
                positives++;
            }
            else
            {
                negatives++;
            }
        }
    }
    else
    {
        ErrorRaise(errorTypeArray, fileName, functionName, lineNumber);
    }

    if(sign == TRUE)
    {
        return positives;
    }
    else
    {
        return negatives;
    }
}
#endif // ARRAY_C_INCLUDED
