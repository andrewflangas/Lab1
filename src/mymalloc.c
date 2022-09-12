#include "mymalloc.h"

//global variables
#define MEMORY_SIZE 1000
bool flag = false;

void Free(void *ptr)
{
    node_t *hptr = (node_t *) ptr -1;
    //printf("size!!!%zu \n", sizeof(ptr));
    hptr->size = sizeof(ptr)-8;
    if(ptr == NULL)
    {
        return;
    }

    munmap(hptr, sizeof(*hptr));
    hptr->next = (void*)hptr->size + 1;

    if(hptr->next == NULL)
    {
        *hptr = *hptr->next;
    }
    flag = false;
}

void *First_Fit(size_t size, node_t *block)
{
    node_t *allocation = block;

    for(int i=0; i<block->size; ++i)
    {
        for(int j=0; j<size; ++j)
        {
            if(sizeof(block[i]) >= size)
            {
                block[j].size -= size;
                allocation[j] = block[j];
                break;
            }
        }
    }

    return (void*) (&allocation[1]);
}

void *Malloc(size_t size)
{
    node_t *head;
    node_t *mem_blk;
    size_t prev_size;
    if(!flag)
    {
        mem_blk = mmap(NULL, MEMORY_SIZE, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
        mem_blk->size = MEMORY_SIZE + sizeof(node_t);
        mem_blk->next = NULL;
        flag = true;
    }

    prev_size = mem_blk->size;
    //printf("size!!!! %zu \n", prev_size);
    head = First_Fit(size,mem_blk);
    head->size = prev_size - (size-8);
    //printf("size2!!!! %zu \n", head->size);
    head->next = NULL;

    return (void*) (&head[1]);
}

