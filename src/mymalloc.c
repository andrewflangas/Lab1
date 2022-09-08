#include "mymalloc.h"

//global variables
#define MEMORY_SIZE 4088
bool flag = false;

void Free(void *ptr)
{
    header_t *hptr = (header_t *) ptr -1;
    if (hptr != NULL)
    {
        munmap(hptr, sizeof(hptr->size));
    }
}

void *First_Fit(size_t size, size_t *block_size)
{
    for(int i=0; i<MEMORY_SIZE; ++i)
    {
        for(int j=0; j<size; ++j)
        {
            if(block_size[j] >= )
        }

    }
}

void *Malloc(size_t size)
{
    node_t *head;
    size_t *blk_size;
    size_t prev_size;
    if(!flag)
    {
        blk_size = mmap(NULL, MEMORY_SIZE, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
        head->size = MEMORY_SIZE + sizeof(node_t);
        head->next = NULL;
        flag = true;
    }

    prev_size = head->size;
    head = First_Fit(size,blk_size);
    head->size = prev_size - (size-8);

    return (void*) (&head[1]);
}

