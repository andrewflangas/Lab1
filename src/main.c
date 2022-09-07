#include "mymalloc.h"

int main()
{
    float* a = Malloc(sizeof (float));
    float* b = Malloc(sizeof (float));
    float* c = Malloc(sizeof (float));

    printf("Please enter two numbers\n");
    scanf("%f %f", b ,c);
    *a = *b + *c;
    printf("%f = %f + %f\n", *a, *b, *c);
    Free(c);
    Free(b);
    Free(a);
    printf("a = %f \n", *a);
}
