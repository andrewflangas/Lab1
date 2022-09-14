#include "../include/mymalloc.h"

//global variables
#define MEMORY_SIZE 4088
bool flag = false;

void Free(void *ptr)
{
    node_t *hptr = (node_t *) ptr -1;
    hptr->size = sizeof(ptr)-8;

    if(ptr == NULL)
    {
        return;
    }

    munmap(hptr, hptr->size);
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

    for(int i=0; i<size; ++i)
    {
        for(int j=0; j<block->size; ++j)
        {
            if(block[j].size >= size)
            {
                block[i].size -= size;
                allocation[i] = block[j];
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

    if(!flag)
    {
        mem_blk = mmap(NULL, MEMORY_SIZE, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
        mem_blk->size = MEMORY_SIZE - sizeof(node_t);
        mem_blk->next = (void*)mem_blk->size + 1;
        flag = true;

    }

    head = First_Fit(size,mem_blk);
    head->next = NULL;
    mem_blk->size = size + sizeof(node_t);
    mem_blk->next = head;

    return (void*) (&head[1]);
}

