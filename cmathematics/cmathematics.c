#include "cmathematics.h"
#include <stdio.h>

void swap(int *a, int *b) {
    *a ^= *b;
    *b = *a ^ *b;
    *a ^= *b;
}

void swapFloat(float *a, float *b) {
    swap((int *)a, (int *)b);
}

bool containsUint(unsigned int *arr, unsigned int noElements, unsigned int target) {
    for(unsigned int i=0; i < noElements; i++){
        if (arr[i] == target) {
            return true;
        }
    }

    return false;
}

void printUintArray(unsigned int *arr, unsigned int noElements){
    printf("[");
    for(unsigned int i=0;i < noElements; i++) {
        printf("%d", arr[i]);
    }

    printf("]\n");
}
