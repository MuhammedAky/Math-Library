#include <stdio.h>

#include "./cmathematics/cmathematics.h"
#include "./cmathematics/vec.h"
#include "./cmathematics/matrix.h"


int main()
{
    printf("Hello, world!\n");

   mat m = newMatrix(4,4,
   2.0f,-1.0f,3.0f,5.0f,
   1.0f,3.0f,0.0f,4.0f,
   3.0f,0.0f,-1.0f,-2.0f,
   0.0f,0.0f,0.0f,1.0f);

    printMat(m);

    vec v = vector(2.0f,0.0f,-1.0f,1.0f);

    vec res = matVecMultiplication(m,v);

    printVec(res);

    return 0;
}