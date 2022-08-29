#include "mymalloc.h"

void InitializeFreeList()
{
    node_t *head = mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
    head->size = 4096 - sizeof(node_t);
    head->next = NULL;
}

void Free(void *ptr)
{
    header_t *hptr = (header_t *) ptr -1;
}

void *Malloc(size_t size)
{

}