#ifndef ARRAY_C_INCLUDED
#define ARRAY_C_INCLUDED

#include "array.h"

void ArrayInterchange(void* arrayA, int64_t sizeArrayA, void* arrayB, int64_t sizeArrayB, int8_t typeData)
{
    if((sizeArrayA <= 0) || (sizeArrayB <= 0) || (sizeArrayA != sizeArrayB))
    {
        ErrorRaise(errorSizeArray, __func__);
    }

    void *auxiliarArray = AllocatorCalloc(sizeArrayA, typeData);

    ArrayCopy(auxiliarArray, sizeArrayA, arrayA, sizeArrayA, typeData);
    ArrayCopy(arrayA, sizeArrayA, arrayB, sizeArrayB, typeData);
    ArrayCopy(arrayB, sizeArrayB, auxiliarArray, sizeArrayA, typeData);
    AllocatorFree(auxiliarArray);
}

void ArrayCopy(void* arrayDestiny, int64_t sizeArrayDestiny, void* arraySource, int64_t sizeArraySource, int8_t typeData)
{
    if( (sizeArrayDestiny <= 0) || (sizeArraySource <= 0) || (sizeArrayDestiny < sizeArraySource) )
    {
        ErrorRaise(errorSizeArray, __func__);
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
    else if(typeData == INT64)
    {
        memcpy((int64_t*)arrayDestiny, (int64_t*)arraySource,  sizeof(int64_t)*sizeArraySource);
    }
    else if(typeData == UNSIGNED_INT64)
    {
        memcpy((uint64_t*)arrayDestiny, (uint64_t*)arraySource,  sizeof(uint64_t)*sizeArraySource);
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
        exit(errorTypeArray);
    }
}

void ArrayConcatenate(void* arrayDestiny, int64_t sizeArrayDestiny, void* arraySource, int64_t sizeArraySource, int8_t typeData)
{
    if( (sizeArrayDestiny <= 0) )
    {
        ErrorRaise(errorSizeArray, __func__);
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
    else if(typeData == INT64)
    {
        memcpy((int64_t*)arrayDestiny + sizeArrayDestiny, (int64_t*)arraySource, sizeof(int64_t)*sizeArraySource);
    }
    else if(typeData == UNSIGNED_INT64)
    {
        memcpy((uint64_t*)arrayDestiny + sizeArrayDestiny, (uint64_t*)arraySource, sizeof(uint64_t)*sizeArraySource);
    }
    else
    {
        exit(errorTypeArray);
    }
}

void ArrayClear(void* arrayDestiny, int64_t sizeArray, int8_t typeData)
{
    if(sizeArray <= 0)
    {
        ErrorRaise(errorSizeArray, __func__);
    }

    const char emptyEscape = EMPTY_ESCAPE;
    const int8_t zero = ZERO;

    if( (typeData == CHAR) || (typeData == UNSIGNED_CHAR))
    {
        ArraySet(arrayDestiny, (void*)(&emptyEscape), sizeArray, typeData);
    }
    else if( (typeData == INT8) || (typeData == UNSIGNED_INT8) || (typeData == INT16) || (typeData == UNSIGNED_INT16) ||
        (typeData == INT32) || (typeData == UNSIGNED_INT32) || (typeData == INT64) || (typeData == UNSIGNED_INT64) ||
        (typeData == FLOAT) || (typeData == DOUBLE) )
    {
        ArraySet(arrayDestiny, (void*)(&zero), sizeArray, typeData);
    }
    else
    {
         exit(errorTypeArray);
    }
}

void ArraySet(void* array, void *data, int64_t sizeArray, int8_t typeData)
{
    if(sizeArray <= 0)
    {
        ErrorRaise(errorSizeArray, __func__);
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
    else if(typeData == INT64)
    {
        memset((int64_t*)array, *((int64_t*)data), sizeof(int64_t)*sizeArray);
    }
    else if(typeData == UNSIGNED_INT64)
    {
        memset((uint64_t*)array, *((uint64_t*)data), sizeof(uint64_t)*sizeArray);
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
        exit(errorTypeArray);
    }
}

void *ArrayFind(void* array, void *data, int64_t sizeArray, int8_t typeData)
{
    if(sizeArray <= 0)
    {
        ErrorRaise(errorSizeArray, __func__);
    }

    if(typeData == CHAR)
    {
        for(int64_t i = 0; i<sizeArray; i++)
        {
            if( *((char*)array + i) == *((char*)data))
            {
                return ((char*)array + i);
            }
        }
    }
    else if(typeData == UNSIGNED_CHAR)
    {
        for(int64_t i = 0; i<sizeArray; i++)
        {
            if( *((unsigned char*)array + i) == *((unsigned char*)data))
            {
                return ((unsigned char*)array + i);
            }
        }
    }
    else if(typeData == INT8)
    {
        for(int64_t i = 0; i<sizeArray; i++)
        {
            if( *((int8_t*)array + i) == *((int8_t*)data))
            {
                return ((int8_t*)array + i);
            }
        }
    }
    else if(typeData == UNSIGNED_INT8)
    {
        for(int64_t i = 0; i<sizeArray; i++)
        {
            if( *((uint8_t*)array + i) == *((uint8_t*)data))
            {
                return ((uint8_t*)array + i);
            }
        }
    }
    else if(typeData == INT16)
    {
        for(int64_t i = 0; i<sizeArray; i++)
        {
            if( *((int16_t*)array + i) == *((int16_t*)data))
            {
                return ((int16_t*)array + i);
            }
        }
    }
    else if(typeData == UNSIGNED_INT16)
    {
        for(int64_t i = 0; i<sizeArray; i++)
        {
            if( *((uint16_t*)array + i) == *((uint16_t*)data))
            {
                return ((uint16_t*)array + i);
            }
        }
    }
    else if(typeData == INT32)
    {
        for(int64_t i = 0; i<sizeArray; i++)
        {
            if( *((int32_t*)array + i) == *((int32_t*)data))
            {
                return ((int32_t*)array + i);
            }
        }
    }
    else if(typeData == UNSIGNED_INT32)
    {
        for(int64_t i = 0; i<sizeArray; i++)
        {
            if( *((uint32_t*)array + i) == *((uint32_t*)data))
            {
                return ((uint32_t*)array + i);
            }
        }
    }
    else if(typeData == INT64)
    {
        for(int64_t i = 0; i<sizeArray; i++)
        {
            if( *((int64_t*)array + i) == *((int64_t*)data))
            {
                return ((int64_t*)array + i);
            }
        }
    }
    else if(typeData == UNSIGNED_INT64)
    {
        for(int64_t i = 0; i<sizeArray; i++)
        {
            if( *((uint64_t*)array + i) == *((uint64_t*)data))
            {
                return ((uint64_t*)array + i);
            }
        }
    }
    else if(typeData == FLOAT)
    {
        for(int64_t i = 0; i<sizeArray; i++)
        {
            if( *((float*)array + i) == *((float*)data))
            {
                return ((float*)array + i);
            }
        }
    }
    else if(typeData == DOUBLE)
    {
        for(int64_t i = 0; i<sizeArray; i++)
        {
            if( *((double*)array + i) == *((double*)data))
            {
                return ((double*)array + i);
            }
        }
    }
    else
    {
        exit(errorTypeArray);
    }

    return NULL;
}

void *ArrayFindMaxValue(void* array, int64_t sizeArray, int8_t typeData)
{
    if(sizeArray <= 0)
    {
        ErrorRaise(errorSizeArray, __func__);
    }

    if(typeData == CHAR)
    {
        char *maxValue = (char*)array;

        for(int64_t i = 0; i<sizeArray; i++)
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

        for(int64_t i = 0; i<sizeArray; i++)
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

        for(int64_t i = 0; i<sizeArray; i++)
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

        for(int64_t i = 0; i<sizeArray; i++)
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

        for(int64_t i = 0; i<sizeArray; i++)
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

        for(int64_t i = 0; i<sizeArray; i++)
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

        for(int64_t i = 0; i<sizeArray; i++)
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

        for(int64_t i = 0; i<sizeArray; i++)
        {
            if( *((uint32_t*)array + i) > *maxValue)
            {
                maxValue = ((uint32_t*)array + i);
            }
        }

        return maxValue;
    }
    else if(typeData == INT64)
    {
        int64_t *maxValue = (int64_t*)array;

        for(int64_t i = 0; i<sizeArray; i++)
        {
            if( *((int64_t*)array + i) > *maxValue)
            {
                maxValue = ((int64_t*)array + i);
            }
        }

        return maxValue;
    }
    else if(typeData == UNSIGNED_INT64)
    {
        uint64_t *maxValue = (uint64_t*)array;

        for(int64_t i = 0; i<sizeArray; i++)
        {
            if( *((uint64_t*)array + i) > *maxValue)
            {
                maxValue = ((uint64_t*)array + i);
            }
        }

        return maxValue;
    }
    else if(typeData == FLOAT)
    {
        float *maxValue = (float*)array;

        for(int64_t i = 0; i<sizeArray; i++)
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

        for(int64_t i = 0; i<sizeArray; i++)
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
        exit(errorTypeArray);
    }

    return NULL;
}

uint64_t ArrayFindNumberRepetitions(void* array, void *data, int64_t sizeArray, int8_t typeData)
{

    uint64_t numberRepetitions = 0;

    if(typeData == CHAR)
    {
        char *positionFound = (char*)array;
        int64_t nextSizeArray = sizeArray;
        while( (nextSizeArray != 0) && (NULL != (positionFound = (char*)ArrayFind((char*)positionFound, data, nextSizeArray, typeData))) )
        {
            positionFound++;
            numberRepetitions++;
            nextSizeArray = (sizeArray - ((char*)positionFound - (char*)array));
        }
    }
    else if (typeData == UNSIGNED_CHAR)
    {
        unsigned char *positionFound = (unsigned char*)array;
        int64_t nextSizeArray = sizeArray;
        while( (nextSizeArray != 0) && (NULL != (positionFound = (unsigned char*)ArrayFind((unsigned char*)positionFound, data, nextSizeArray, typeData))) )
        {
            positionFound++;
            numberRepetitions++;
            nextSizeArray = (sizeArray - ((unsigned char*)positionFound - (unsigned char*)array));
        }
    }
    else if(typeData == INT8)
    {
        int8_t *positionFound = (int8_t*)array;
        int64_t nextSizeArray = sizeArray;
        while( (nextSizeArray != 0) && (NULL != (positionFound = (int8_t*)ArrayFind((int8_t*)positionFound, data, nextSizeArray, typeData))) )
        {
            positionFound++;
            numberRepetitions++;
            nextSizeArray = (sizeArray - ((int8_t*)positionFound - (int8_t*)array));
        }
    }
    else if(typeData == UNSIGNED_INT8)
    {
        uint8_t *positionFound = (uint8_t*)array;
        int64_t nextSizeArray = sizeArray;
        while( (nextSizeArray != 0) && (NULL != (positionFound = (uint8_t*)ArrayFind((uint8_t*)positionFound, data, nextSizeArray, typeData))) )
        {
            positionFound++;
            numberRepetitions++;
            nextSizeArray = (sizeArray - ((uint8_t*)positionFound - (uint8_t*)array));
        }
    }
    else if(typeData == INT16)
    {
        int16_t *positionFound = (int16_t*)array;
        int64_t nextSizeArray = sizeArray;
        while( (nextSizeArray != 0) && (NULL != (positionFound = (int16_t*)ArrayFind((int16_t*)positionFound, data, nextSizeArray, typeData))) )
        {
            positionFound++;
            numberRepetitions++;
            nextSizeArray = (sizeArray - ((int16_t*)positionFound - (int16_t*)array));
        }
    }
    else if(typeData == UNSIGNED_INT16)
    {
        uint16_t *positionFound = (uint16_t*)array;
        int64_t nextSizeArray = sizeArray;
        while( (nextSizeArray != 0) && (NULL != (positionFound = (uint16_t*)ArrayFind((uint16_t*)positionFound, data, nextSizeArray, typeData))) )
        {
            positionFound++;
            numberRepetitions++;
            nextSizeArray = (sizeArray - ((uint16_t*)positionFound - (uint16_t*)array));
        }
    }
    else if(typeData == INT32)
    {
        int32_t *positionFound = (int32_t*)array;
        int64_t nextSizeArray = sizeArray;
        while( (nextSizeArray != 0) && (NULL != (positionFound = (int32_t*)ArrayFind((int32_t*)positionFound, data, nextSizeArray, typeData))) )
        {
            positionFound++;
            numberRepetitions++;
            nextSizeArray = (sizeArray - ((int32_t*)positionFound - (int32_t*)array));
        }
    }
    else if(typeData == UNSIGNED_INT32)
    {
        uint32_t *positionFound = (uint32_t*)array;
        int64_t nextSizeArray = sizeArray;
        while( (nextSizeArray != 0) && (NULL != (positionFound = (uint32_t*)ArrayFind((uint32_t*)positionFound, data, nextSizeArray, typeData))) )
        {
            positionFound++;
            numberRepetitions++;
            nextSizeArray = (sizeArray - ((uint32_t*)positionFound - (uint32_t*)array));
        }
    }
    else if(typeData == INT64)
    {
        int64_t *positionFound = (int64_t*)array;
        int64_t nextSizeArray = sizeArray;
        while( (nextSizeArray != 0) && (NULL != (positionFound = (int64_t*)ArrayFind((int64_t*)positionFound, data, nextSizeArray, typeData))) )
        {
            positionFound++;
            numberRepetitions++;
            nextSizeArray = (sizeArray - ((int64_t*)positionFound - (int64_t*)array));
        }
    }
    else if(typeData == UNSIGNED_INT64)
    {
        uint64_t *positionFound = (uint64_t*)array;
        int64_t nextSizeArray = sizeArray;
        while( (nextSizeArray != 0) && (NULL != (positionFound = (uint64_t*)ArrayFind((uint64_t*)positionFound, data, nextSizeArray, typeData))) )
        {
            positionFound++;
            numberRepetitions++;
            nextSizeArray = (sizeArray - ((uint64_t*)positionFound - (uint64_t*)array));
        }
    }
    else if(typeData == FLOAT)
    {
        float *positionFound = (float*)array;
        int64_t nextSizeArray = sizeArray;
        while( (nextSizeArray != 0) && (NULL != (positionFound = (float*)ArrayFind((float*)positionFound, data, nextSizeArray, typeData))) )
        {
            positionFound++;
            numberRepetitions++;
            nextSizeArray = (sizeArray - ((float*)positionFound - (float*)array));
        }
    }
    else if(typeData == DOUBLE)
    {
        double *positionFound = (double*)array;
        int64_t nextSizeArray = sizeArray;
        while( (nextSizeArray != 0) && (NULL != (positionFound = (double*)ArrayFind((double*)positionFound, data, nextSizeArray, typeData))) )
        {
            positionFound++;
            numberRepetitions++;
            nextSizeArray = (sizeArray - ((double*)positionFound - (double*)array));
        }
    }
    else
    {
        exit(errorTypeArray);
    }

    return numberRepetitions;
}

void ArrayEndChar(void* array, int64_t sizeArray, int8_t typeData)
{
    if(sizeArray <= 0)
    {
        ErrorRaise(errorSizeArray, __func__);
    }

    --sizeArray; //position of the \0 character
    if(typeData == CHAR)
    {
        memset(((char*)array + sizeArray), EMPTY_ESCAPE, 1);
    }
    else if (typeData == UNSIGNED_CHAR)
    {
        memset(((unsigned char*)array + sizeArray), EMPTY_ESCAPE, 1);
    }
}

void ArrayRandomGenerator(void* array, int64_t sizeArray, void* lowerLimit, void* upperLimit, int8_t typeData)
{
    if(sizeArray <= 0)
    {
        ErrorRaise(errorSizeArray, __func__);
    }

    srand(time(NULL));

    if(typeData == CHAR)
    {
        if( *((char*)lowerLimit) >= 0)
        {
            for(int64_t i = 0; i < sizeArray; i++)
            {
                *((char*)array + i) = *((char*)lowerLimit) + (char)(rand()%( *((char*)upperLimit) + 1 - *((char*)lowerLimit) ));
            }
        }
        else
        {
            for(int64_t i = 0; i < sizeArray; i++)
            {
                if(rand()%2)
                {
                    *((char*)array + i) = (char)(rand()%(*((char*)upperLimit) + 1));
                }
                else
                {
                    *((char*)array + i) = -((char)(rand()%(*((char*)upperLimit) + 1)));
                }
            }
        }
    }
    else if(typeData == UNSIGNED_CHAR)
    {
        if( *((unsigned char*)lowerLimit) >= 0)
        {
            for(int64_t i = 0; i < sizeArray; i++)
            {
                *((unsigned char*)array + i) = *((unsigned char*)lowerLimit) + (unsigned char)(rand()%( *((unsigned char*)upperLimit) + 1 - *((unsigned char*)lowerLimit) ));
            }
        }
        else
        {
            for(int64_t i = 0; i < sizeArray; i++)
            {
                if(rand()%2)
                {
                    *((unsigned char*)array + i) = (unsigned char)(rand()%(*((unsigned char*)upperLimit) + 1));
                }
                else
                {
                    *((unsigned char*)array + i) = -((unsigned char)(rand()%(*((unsigned char*)upperLimit) + 1)));
                }
            }
        }
    }
    else if(typeData == INT8)
    {
        if( *((int8_t*)lowerLimit) >= 0)
        {
            for(int64_t i = 0; i < sizeArray; i++)
            {
                *((int8_t*)array + i) = *((int8_t*)lowerLimit) + (int8_t)(rand()%( *((int8_t*)upperLimit) + 1 - *((int8_t*)lowerLimit) ));
            }
        }
        else
        {
            for(int64_t i = 0; i < sizeArray; i++)
            {
                if(rand()%2)
                {
                    *((int8_t*)array + i) = (int8_t)(rand()%(*((int8_t*)upperLimit) + 1));
                }
                else
                {
                    *((int8_t*)array + i) = -((int8_t)(rand()%(*((int8_t*)upperLimit) + 1)));
                }
            }
        }
    }
    else if(typeData == UNSIGNED_INT8)
    {
        if( *((uint8_t*)lowerLimit) >= 0)
        {
            for(int64_t i = 0; i < sizeArray; i++)
            {
                *((uint8_t*)array + i) = *((uint8_t*)lowerLimit) + (uint8_t)(rand()%( *((uint8_t*)upperLimit) + 1 - *((uint8_t*)lowerLimit) ));
            }
        }
        else
        {
            for(int64_t i = 0; i < sizeArray; i++)
            {
                if(rand()%2)
                {
                    *((uint8_t*)array + i) = (uint8_t)(rand()%(*((uint8_t*)upperLimit) + 1));
                }
                else
                {
                    *((uint8_t*)array + i) = -((uint8_t)(rand()%(*((uint8_t*)upperLimit) + 1)));
                }
            }
        }
    }
    else if(typeData == INT16)
    {
        if( *((int16_t*)lowerLimit) >= 0)
        {
            for(int64_t i = 0; i < sizeArray; i++)
            {
                *((int16_t*)array + i) = *((int16_t*)lowerLimit) + (int16_t)(rand()%( *((int16_t*)upperLimit) + 1 - *((int16_t*)lowerLimit) ));
            }
        }
        else
        {
            for(int64_t i = 0; i < sizeArray; i++)
            {
                if(rand()%2)
                {
                    *((int16_t*)array + i) = (int16_t)(rand()%(*((int16_t*)upperLimit) + 1));
                }
                else
                {
                    *((int16_t*)array + i) = -((int16_t)(rand()%(*((int16_t*)upperLimit) + 1)));
                }
            }
        }
    }
    else if(typeData == UNSIGNED_INT16)
    {
        if( *((uint16_t*)lowerLimit) >= 0)
        {
            for(int64_t i = 0; i < sizeArray; i++)
            {
                *((uint16_t*)array + i) = *((uint16_t*)lowerLimit) + (uint16_t)(rand()%( *((uint16_t*)upperLimit) + 1 - *((uint16_t*)lowerLimit) ));
            }
        }
        else
        {
            for(int64_t i = 0; i < sizeArray; i++)
            {
                if(rand()%2)
                {
                    *((uint16_t*)array + i) = (uint16_t)(rand()%(*((uint16_t*)upperLimit) + 1));
                }
                else
                {
                    *((uint16_t*)array + i) = -((uint16_t)(rand()%(*((uint16_t*)upperLimit) + 1)));
                }
            }
        }
    }
    else if(typeData == INT32)
    {
        if( *((int32_t*)lowerLimit) >= 0)
        {
            for(int64_t i = 0; i < sizeArray; i++)
            {
                *((int32_t*)array + i) = *((int32_t*)lowerLimit) + (int32_t)(rand()%( *((int32_t*)upperLimit) + 1 - *((int32_t*)lowerLimit) ));
            }
        }
        else
        {
            for(int64_t i = 0; i < sizeArray; i++)
            {
                if(rand()%2)
                {
                    *((int32_t*)array + i) = (int32_t)(rand()%(*((int32_t*)upperLimit) + 1));
                }
                else
                {
                    *((int32_t*)array + i) = -((int32_t)(rand()%(*((int32_t*)upperLimit) + 1)));
                }
            }
        }
    }
    else if(typeData == UNSIGNED_INT32)
    {
        if( *((uint32_t*)lowerLimit) >= 0)
        {
            for(int64_t i = 0; i < sizeArray; i++)
            {
                *((uint32_t*)array + i) = *((uint32_t*)lowerLimit) + (uint32_t)(rand()%( *((uint32_t*)upperLimit) + 1 - *((uint32_t*)lowerLimit) ));
            }
        }
        else
        {
            for(int64_t i = 0; i < sizeArray; i++)
            {
                if(rand()%2)
                {
                    *((uint32_t*)array + i) = (uint32_t)(rand()%(*((uint32_t*)upperLimit) + 1));
                }
                else
                {
                    *((uint32_t*)array + i) = -((uint32_t)(rand()%(*((uint32_t*)upperLimit) + 1)));
                }
            }
        }
    }
    else if(typeData == INT64)
    {
        if( *((int64_t*)lowerLimit) >= 0)
        {
            for(int64_t i = 0; i < sizeArray; i++)
            {
                *((int64_t*)array + i) = *((int64_t*)lowerLimit) + (int64_t)(rand()%( *((int64_t*)upperLimit) + 1 - *((int64_t*)lowerLimit) ));
            }
        }
        else
        {
            for(int64_t i = 0; i < sizeArray; i++)
            {
                if(rand()%2)
                {
                    *((int64_t*)array + i) = (int64_t)(rand()%(*((int64_t*)upperLimit) + 1));
                }
                else
                {
                    *((int64_t*)array + i) = -((int64_t)(rand()%(*((int64_t*)upperLimit) + 1)));
                }
            }
        }
    }
    else if(typeData == UNSIGNED_INT64)
    {
        if( *((uint64_t*)lowerLimit) >= 0)
        {
            for(int64_t i = 0; i < sizeArray; i++)
            {
                *((uint64_t*)array + i) = *((uint64_t*)lowerLimit) + (uint64_t)(rand()%( *((uint64_t*)upperLimit) + 1 - *((uint64_t*)lowerLimit) ));
            }
        }
        else
        {
            for(int64_t i = 0; i < sizeArray; i++)
            {
                if(rand()%2)
                {
                    *((uint64_t*)array + i) = (uint64_t)(rand()%(*((uint64_t*)upperLimit) + 1));
                }
                else
                {
                    *((uint64_t*)array + i) = -((uint64_t)(rand()%(*((uint64_t*)upperLimit) + 1)));
                }
            }
        }
    }
    else if(typeData == FLOAT)
    {
        float range = *((float*)upperLimit) - *((float*)lowerLimit);
        float division = RAND_MAX / range;

        for(int64_t i = 0; i < sizeArray; i++)
        {
           *((float*)array + i) = *((float*)lowerLimit) + (rand() / division);
        }
    }
    else if(typeData == DOUBLE)
    {
        double range = *((double*)upperLimit) - *((double*)lowerLimit);
        double division = RAND_MAX / range;

        for(int64_t i = 0; i < sizeArray; i++)
        {
           *((double*)array + i) = *((double*)lowerLimit) + (rand() / division);
        }
    }
    else
    {
        exit(errorTypeArray);
    }
}

void ArrayReverse(void *array, int64_t sizeArray, int8_t typeData)
{
    if( sizeArray <= 0 )
    {
        ErrorRaise(errorSizeArray, __func__);
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
    else if(typeData == INT64)
    {
        for(int64_t *i = (int64_t*)array, *j = (int64_t*)array + sizeArray - 1 ;  i < j ; i++, j--)
        {
            SwapXor(i,j,typeData);
        }
    }
    else if(typeData == UNSIGNED_INT64)
    {
        for(uint64_t *i = (uint64_t*)array, *j = (uint64_t*)array + sizeArray - 1 ;  i < j ; i++, j--)
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
        exit(errorTypeArray);
    }
}

void ArrayReverseInterval(void *array, int64_t sizeArray, void* lowerLimit, void* upperLimit, int8_t typeData)
{
    if( sizeArray <= 0 )
    {
       ErrorRaise(errorSizeArray, __func__);
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
    else if(typeData == INT64)
    {
        for(int64_t *i = (int64_t*)lowerLimit, *j = (int64_t*)upperLimit;  i < j ; i++, j--)
        {
            SwapXor(i,j,typeData);
        }
    }
    else if(typeData == UNSIGNED_INT64)
    {
        for(uint64_t *i = (uint64_t*)lowerLimit, *j = (uint64_t*)upperLimit;  i < j ; i++, j--)
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
        exit(errorTypeArray);
    }
}

void ArrayReplaceAll(void *array, int64_t sizeArray, void* data, int8_t typeData)
{
    if( sizeArray <= 0 )
    {
        ErrorRaise(errorSizeArray, __func__);
    }

    if(typeData == CHAR)
    {
        char *positionFound = (char*)array;
        int64_t nextSizeArray = sizeArray;
        while( (nextSizeArray != 0) && (NULL != (positionFound = (char*)ArrayFind((char*)positionFound, data, nextSizeArray, typeData))) )
        {
            *(positionFound++) = *((char*)data);
            nextSizeArray = (sizeArray - ((char*)positionFound - (char*)array));
        }
    }
    else if (typeData == UNSIGNED_CHAR)
    {
        unsigned char *positionFound = (unsigned char*)array;
        int64_t nextSizeArray = sizeArray;
        while( (nextSizeArray != 0) && (NULL != (positionFound = (unsigned char*)ArrayFind((unsigned char*)positionFound, data, nextSizeArray, typeData))) )
        {
            *(positionFound++) = *((unsigned char*)data);
            nextSizeArray = (sizeArray - ((unsigned char*)positionFound - (unsigned char*)array));
        }
    }
    else if(typeData == INT8)
    {
        int8_t *positionFound = (int8_t*)array;
        int64_t nextSizeArray = sizeArray;
        while( (nextSizeArray != 0) && (NULL != (positionFound = (int8_t*)ArrayFind((int8_t*)positionFound, data, nextSizeArray, typeData))) )
        {
            *(positionFound++) = *((int8_t*)data);
            nextSizeArray = (sizeArray - ((int8_t*)positionFound - (int8_t*)array));
        }
    }
    else if(typeData == UNSIGNED_INT8)
    {
        uint8_t *positionFound = (uint8_t*)array;
        int64_t nextSizeArray = sizeArray;
        while( (nextSizeArray != 0) && (NULL != (positionFound = (uint8_t*)ArrayFind((uint8_t*)positionFound, data, nextSizeArray, typeData))) )
        {
            *(positionFound++) = *((uint8_t*)data);
            nextSizeArray = (sizeArray - ((uint8_t*)positionFound - (uint8_t*)array));
        }
    }
    else if(typeData == INT16)
    {
        int16_t *positionFound = (int16_t*)array;
        int64_t nextSizeArray = sizeArray;
        while( (nextSizeArray != 0) && (NULL != (positionFound = (int16_t*)ArrayFind((int16_t*)positionFound, data, nextSizeArray, typeData))) )
        {
            *(positionFound++) = *((int16_t*)data);
            nextSizeArray = (sizeArray - ((int16_t*)positionFound - (int16_t*)array));
        }
    }
    else if(typeData == UNSIGNED_INT16)
    {
        uint16_t *positionFound = (uint16_t*)array;
        int64_t nextSizeArray = sizeArray;
        while( (nextSizeArray != 0) && (NULL != (positionFound = (uint16_t*)ArrayFind((uint16_t*)positionFound, data, nextSizeArray, typeData))) )
        {
            *(positionFound++) = *((uint16_t*)data);
            nextSizeArray = (sizeArray - ((uint16_t*)positionFound - (uint16_t*)array));
        }
    }
    else if(typeData == INT32)
    {
        int32_t *positionFound = (int32_t*)array;
        int64_t nextSizeArray = sizeArray;
        while( (nextSizeArray != 0) && (NULL != (positionFound = (int32_t*)ArrayFind((int32_t*)positionFound, data, nextSizeArray, typeData))) )
        {
            *(positionFound++) = *((int32_t*)data);
            nextSizeArray = (sizeArray - ((int32_t*)positionFound - (int32_t*)array));
        }
    }
    else if(typeData == UNSIGNED_INT32)
    {
        uint32_t *positionFound = (uint32_t*)array;
        int64_t nextSizeArray = sizeArray;
        while( (nextSizeArray != 0) && (NULL != (positionFound = (uint32_t*)ArrayFind((uint32_t*)positionFound, data, nextSizeArray, typeData))) )
        {
            *(positionFound++) = *((uint32_t*)data);
            nextSizeArray = (sizeArray - ((uint32_t*)positionFound - (uint32_t*)array));
        }
    }
    else if(typeData == INT64)
    {
        int64_t *positionFound = (int64_t*)array;
        int64_t nextSizeArray = sizeArray;
        while( (nextSizeArray != 0) && (NULL != (positionFound = (int64_t*)ArrayFind((int64_t*)positionFound, data, nextSizeArray, typeData))) )
        {
            *(positionFound++) = *((int64_t*)data);
            nextSizeArray = (sizeArray - ((int64_t*)positionFound - (int64_t*)array));
        }
    }
    else if(typeData == UNSIGNED_INT64)
    {
        uint64_t *positionFound = (uint64_t*)array;
        int64_t nextSizeArray = sizeArray;
        while( (nextSizeArray != 0) && (NULL != (positionFound = (uint64_t*)ArrayFind((uint64_t*)positionFound, data, nextSizeArray, typeData))) )
        {
            *(positionFound++) = *((uint64_t*)data);
            nextSizeArray = (sizeArray - ((uint64_t*)positionFound - (uint64_t*)array));
        }
    }
    else if(typeData == FLOAT)
    {
        float *positionFound = (float*)array;
        int64_t nextSizeArray = sizeArray;
        while( (nextSizeArray != 0) && (NULL != (positionFound = (float*)ArrayFind((float*)positionFound, data, nextSizeArray, typeData))) )
        {
            *(positionFound++) = *((float*)data);
            nextSizeArray = (sizeArray - ((float*)positionFound - (float*)array));
        }
    }
    else if(typeData == DOUBLE)
    {
        double *positionFound = (double*)array;
        int64_t nextSizeArray = sizeArray;
        while( (nextSizeArray != 0) && (NULL != (positionFound = (double*)ArrayFind((double*)positionFound, data, nextSizeArray, typeData))) )
        {
            *(positionFound++) = *((double*)data);
            nextSizeArray = (sizeArray - ((double*)positionFound - (double*)array));
        }
    }
    else
    {
        exit(errorTypeArray);
    }
}

void ArrayReplaceFrequency(void *array, int64_t sizeArray, void* data, int64_t frequency, int8_t typeData)
{
    if( sizeArray <= 0 )
    {
        ErrorRaise(errorSizeArray, __func__);
    }

    if(frequency <= 0)
    {
        exit(errorNegativeNumberArray);
    }

    if(typeData == CHAR)
    {
        char *positionFound = (char*)array;
        int64_t nextSizeArray = sizeArray;
        while( (frequency-- != 0) && (nextSizeArray != 0) && (NULL != (positionFound = (char*)ArrayFind((char*)positionFound, data, nextSizeArray, typeData))) )
        {
            *(positionFound++) = *((char*)data);
            nextSizeArray = (sizeArray - ((char*)positionFound - (char*)array));
        }
    }
    else if (typeData == UNSIGNED_CHAR)
    {
        unsigned char *positionFound = (unsigned char*)array;
        int64_t nextSizeArray = sizeArray;
        while( (frequency-- != 0) && (nextSizeArray != 0) && (NULL != (positionFound = (unsigned char*)ArrayFind((unsigned char*)positionFound, data, nextSizeArray, typeData))) )
        {
            *(positionFound++) = *((unsigned char*)data);
            nextSizeArray = (sizeArray - ((unsigned char*)positionFound - (unsigned char*)array));
        }
    }
    else if(typeData == INT8)
    {
        int8_t *positionFound = (int8_t*)array;
        int64_t nextSizeArray = sizeArray;
        while( (frequency-- != 0) && (nextSizeArray != 0) && (NULL != (positionFound = (int8_t*)ArrayFind((int8_t*)positionFound, data, nextSizeArray, typeData))) )
        {
            *(positionFound++) = *((int8_t*)data);
            nextSizeArray = (sizeArray - ((int8_t*)positionFound - (int8_t*)array));
        }
    }
    else if(typeData == UNSIGNED_INT8)
    {
        uint8_t *positionFound = (uint8_t*)array;
        int64_t nextSizeArray = sizeArray;
        while( (frequency-- != 0) && (nextSizeArray != 0) && (NULL != (positionFound = (uint8_t*)ArrayFind((uint8_t*)positionFound, data, nextSizeArray, typeData))) )
        {
            *(positionFound++) = *((uint8_t*)data);
            nextSizeArray = (sizeArray - ((uint8_t*)positionFound - (uint8_t*)array));
        }
    }
    else if(typeData == INT16)
    {
        int16_t *positionFound = (int16_t*)array;
        int64_t nextSizeArray = sizeArray;
        while( (frequency-- != 0) && (nextSizeArray != 0) && (NULL != (positionFound = (int16_t*)ArrayFind((int16_t*)positionFound, data, nextSizeArray, typeData))) )
        {
            *(positionFound++) = *((int16_t*)data);
            nextSizeArray = (sizeArray - ((int16_t*)positionFound - (int16_t*)array));
        }
    }
    else if(typeData == UNSIGNED_INT16)
    {
        uint16_t *positionFound = (uint16_t*)array;
        int64_t nextSizeArray = sizeArray;
        while( (frequency-- != 0) && (nextSizeArray != 0) && (NULL != (positionFound = (uint16_t*)ArrayFind((uint16_t*)positionFound, data, nextSizeArray, typeData))) )
        {
            *(positionFound++) = *((uint16_t*)data);
            nextSizeArray = (sizeArray - ((uint16_t*)positionFound - (uint16_t*)array));
        }
    }
    else if(typeData == INT32)
    {
        int32_t *positionFound = (int32_t*)array;
        int64_t nextSizeArray = sizeArray;
        while( (frequency-- != 0) && (nextSizeArray != 0) && (NULL != (positionFound = (int32_t*)ArrayFind((int32_t*)positionFound, data, nextSizeArray, typeData))) )
        {
            *(positionFound++) = *((int32_t*)data);
            nextSizeArray = (sizeArray - ((int32_t*)positionFound - (int32_t*)array));
        }
    }
    else if(typeData == UNSIGNED_INT32)
    {
        uint32_t *positionFound = (uint32_t*)array;
        int64_t nextSizeArray = sizeArray;
        while( (frequency-- != 0) && (nextSizeArray != 0) && (NULL != (positionFound = (uint32_t*)ArrayFind((uint32_t*)positionFound, data, nextSizeArray, typeData))) )
        {
            *(positionFound++) = *((uint32_t*)data);
            nextSizeArray = (sizeArray - ((uint32_t*)positionFound - (uint32_t*)array));
        }
    }
    else if(typeData == INT64)
    {
        int64_t *positionFound = (int64_t*)array;
        int64_t nextSizeArray = sizeArray;
        while( (frequency-- != 0) && (nextSizeArray != 0) && (NULL != (positionFound = (int64_t*)ArrayFind((int64_t*)positionFound, data, nextSizeArray, typeData))) )
        {
            *(positionFound++) = *((int64_t*)data);
            nextSizeArray = (sizeArray - ((int64_t*)positionFound - (int64_t*)array));
        }
    }
    else if(typeData == UNSIGNED_INT64)
    {
        uint64_t *positionFound = (uint64_t*)array;
        int64_t nextSizeArray = sizeArray;
        while( (frequency-- != 0) && (nextSizeArray != 0) && (NULL != (positionFound = (uint64_t*)ArrayFind((uint64_t*)positionFound, data, nextSizeArray, typeData))) )
        {
            *(positionFound++) = *((uint64_t*)data);
            nextSizeArray = (sizeArray - ((uint64_t*)positionFound - (uint64_t*)array));
        }
    }
    else if(typeData == FLOAT)
    {
        float *positionFound = (float*)array;
        int64_t nextSizeArray = sizeArray;
        while( (frequency-- != 0) && (nextSizeArray != 0) && (NULL != (positionFound = (float*)ArrayFind((float*)positionFound, data, nextSizeArray, typeData))) )
        {
            *(positionFound++) = *((float*)data);
            nextSizeArray = (sizeArray - ((float*)positionFound - (float*)array));
        }
    }
    else if(typeData == DOUBLE)
    {
        double *positionFound = (double*)array;
        int64_t nextSizeArray = sizeArray;
        while( (frequency-- != 0) && (nextSizeArray != 0) && (NULL != (positionFound = (double*)ArrayFind((double*)positionFound, data, nextSizeArray, typeData))) )
        {
            *(positionFound++) = *((double*)data);
            nextSizeArray = (sizeArray - ((double*)positionFound - (double*)array));
        }
    }
    else
    {
        exit(errorTypeArray);
    }
}

void ArrayShuffle(void* array, int64_t sizeArray, int8_t typeData)
{
     if( sizeArray <= 0 )
    {
        ErrorRaise(errorSizeArray, __func__);
    }

    if(typeData == CHAR)
    {

    }
    else if (typeData == UNSIGNED_CHAR)
    {

    }
    else if(typeData == INT8)
    {

    }
    else if(typeData == UNSIGNED_INT8)
    {

    }
    else if(typeData == INT16)
    {

    }
    else if(typeData == UNSIGNED_INT16)
    {

    }
    else if(typeData == INT32)
    {

    }
    else if(typeData == UNSIGNED_INT32)
    {

    }
    else if(typeData == INT64)
    {

    }
    else if(typeData == UNSIGNED_INT64)
    {

    }
    else if(typeData == FLOAT)
    {

    }
    else if(typeData == DOUBLE)
    {

    }
    else
    {
        exit(errorTypeArray);
    }
}
#endif // ARRAY_C_INCLUDED
