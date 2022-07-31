#include <stdarg.h>
#include <stdio.h>

#include "cmathematics.h"

#ifndef BIGINT_H
#define BIGINT_H

/**
 * structure representing an integer
 * each character in the array corresponds to one digit in base 10
 */
typedef struct
{
    bool sign;             // the sign of the number (true if 0 or positive, false if negative)
    unsigned int capacity; // number of slots in the array
    unsigned int noDigits; // number of used slots in the array
    char *digits;          // array of the digits in reverse order; digits[i] = 10^i component
} bigint;

extern const bigint BIGINT_ZERO; // zero integer

bigint allocateBigint(unsigned int capacity);

bigint strToBigint(char *str);

bigint newBigint(int i);

bigint newPositiveBigint(unsigned int i);

char *bigintPtrToString(bigint *i);

char *bigintToString(bigint i);

char compareBigint(bigint i1, bigint i2);

bigint addBigint(bigint i1, bigint i2);

bigint subtractBigint(bigint i1, bigint i2);

#endif