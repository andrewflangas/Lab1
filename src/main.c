#include "../include/mymalloc.h"

int main()
{
    int *ptr;
    int *ptr1;
    int a, b, c, d;

    printf("Please enter number of elements: \n");
    scanf("%d",&a);

    printf("Entered number of elements %d \n", a);

    ptr = (int*) Malloc(a * sizeof(int));
    if(ptr == NULL)
    {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else
    {
        printf("Memory allocated successfully\n");
        for(b = 0; b < a; ++b)
        {
            ptr[b] = b + 1;
        }
        printf("The elements of the array are: \n");
        for(b = 0; b < a; ++b)
        {
            printf("%d \n", ptr[b]);
        }

        printf("Memory is free!\n");
        Free(&ptr);
        for(b = 0; b < a; ++b)
        {
            printf("%d \n", ptr[b]);
        }
    }

    printf("Please enter number of elements: \n");
    scanf("%d",&c);

    printf("Entered number of elements %d \n", c);

    ptr = (int*) Malloc(c * sizeof(int));
    if(ptr1 == NULL)
    {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else
    {
        printf("Memory allocated successfully\n");
        for(d = 0; d < c; ++d)
        {
            ptr1[d] = d + 1;
        }
        printf("The elements of the array are: \n");
        for(d = 0; d < c; ++d)
        {
            printf("%d \n", ptr1[d]);
        }

        printf("Memory is free!\n");
        Free(&ptr1);
        for(d = 0; d < c; ++d)
        {
            printf("%d \n", ptr1[d]);
        }
    }
    return 0;
}