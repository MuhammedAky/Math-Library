#include <stdio.h>

#include "../cmathematics/cmathematics.h"
#include "../cmathematics/vec.h"
#include "../cmathematics/matrix.h"
#include "../cmathematics/bigint.h"

int main()
{
    printf("Hello, world!\n");

    mat m = matrix(2,2,
                    4.0, 7.0,
                    2.0, 6.0
    );

    printMat(m);

    mat inv = inverseMat(&m);
    printMat(inv);

}