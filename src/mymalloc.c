#include "../include/mymalloc.h"

//global variables
#define MEMORY_SIZE 4088
bool flag = false;
node_t *mem_blk;
node_t *allocation;

void PrintMemory()
{
    while(mem_blk != NULL)
    {
        printf("Size of mem_blk %zu \n", mem_blk->size);
        printf("Memory Locations for mem_blk %p \n", mem_blk);
        mem_blk = mem_blk->next;
    }

    while(allocation != NULL)
    {
        printf("Size of allocation %zu \n", allocation->size);
        printf("Memory Locations for allocation %p \n", allocation);
        allocation = allocation->next;
    }
}

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
            mem_blk->size = block->size - size;
            allocation->next = mem_blk;
            break;
        }
        block = block->next;
    }
    //PrintMemory();
    return (void*) (&allocation[1]);
}

void *Malloc(size_t size)
{
    node_t *alloc;

    if(!flag)
    {
        mem_blk = mmap(NULL, MEMORY_SIZE, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
        mem_blk->size = MEMORY_SIZE - sizeof(node_t);
        mem_blk->next = NULL;
        flag = true;

    }

    alloc = First_Fit(size,mem_blk);
    alloc->size = allocation->size;
    alloc->next = mem_blk;
    printf("Mem of alloc!!!!! %p : \n", alloc);
    printf("Memory info in Malloc: \n");
    PrintMemory();

    return (void*) (&alloc[1]);
}



