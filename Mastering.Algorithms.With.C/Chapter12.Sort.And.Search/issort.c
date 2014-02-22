/* issort.c */
#include <stdlib.h>
#include <string.h>

#include "sort.h"

/* issort */
int issort(void *data, int size, int esize, int (*compare)(const void *key1, const void *key2)){
    char *a = data;
    void *key;
    int i, ;
    
    /* allocate storage for the key element */
    if((key = (char*)malloc(esize)) == NULL)
        return -1;
}