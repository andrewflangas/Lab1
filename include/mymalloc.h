#ifndef LAB1_LIBRARY_H
#define LAB1_LIBRARY_H

#include <sys/mman.h>
#include <stdio.h>

typedef struct header_t
{
    int size;
    int magic;
} header_t;

typedef struct node_t
{
    int size;
    struct node_t *next;
} node_t;

void InitializeFreeList();

void Free(void *ptr);

void *Malloc(size_t size);

#endif //LAB1_LIBRARY_H