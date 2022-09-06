#include "mymalloc.h"


void Free(void *ptr)
{
    header_t *hptr = (header_t *) ptr -1;
    if (hptr != NULL)
    {
        munmap(hptr, sizeof(hptr->size));
    }
}

void *Malloc(size_t size)
{
    node_t *head = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
    if(head == MAP_FAILED)
    {
        printf("Malloc failed\n");
        return NULL;
    }
    head->size = size + sizeof(node_t);
    head->next = NULL;
    return (void*) (&head[1]);
}