#include "../include/mymalloc.h"

//global variables
#define MEMORY_SIZE 4088
bool flag = false;
node_t *mem_blk;
node_t *allocation;

void Free(void *ptr)
{
    node_t *hptr = (void *) ptr - sizeof(node_t);
    size_t free = hptr->size*4 + sizeof(*hptr);
    hptr->size = sizeof(ptr) - 8;
    printf("sizeee!!! %zu \n", free);

    while(allocation != NULL)
    {
        if(free == allocation->size)
        {
            printf("made it!!! \n");
            munmap(hptr, sizeof(*hptr));
            break;
        }
        allocation = allocation->next;
    }

    if(hptr->next == NULL)
    {
        *hptr = *hptr->next;
    }

    flag = false;
}

void *First_Fit(size_t size, node_t *block)
{
    while(block != NULL)
    {
        if(block->size >= size)
        {
            allocation = (void*)((node_t*)block + size);
            allocation->size = sizeof(*block) + size;
            allocation->next = mem_blk;
            break;
        }
        block = block->next;
    }
    printf("size!!!! %zu \n", allocation->size);
    return (void*) (&allocation[1]);
}

void *Malloc(size_t size)
{
    node_t *head;

    if(!flag)
    {
        mem_blk = mmap(NULL, MEMORY_SIZE, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
        mem_blk->size = MEMORY_SIZE - sizeof(node_t);
        mem_blk->next = NULL;
        flag = true;

    }

    head = First_Fit(size,mem_blk);
    head->size = mem_blk->size - size;
    head->next = NULL;
    printf("size!!!! %zu \n", head->size);
    mem_blk = head;

    return (void*) (&head[1]);
}

