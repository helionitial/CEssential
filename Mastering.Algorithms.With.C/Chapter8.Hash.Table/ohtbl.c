/* ohtbl.c */
#include <stdlib.h>
#include <string.h>

#include "ohtbl.h"

/* Reserve a sentinel memory address for vacated elements. */
static char vacated;

/* ohtbl_init */
int ohtbl_init(OHTbl *htbl, int positions, int(*h1)(const void *key),
               int (*h2)(const void *key), int (*match)(const void *key1, const void *key2), void (*destroy)(void *data)){
    int i;
    
    /* allocate space for the hash table */
    if((htbl->table = (void **)malloc(positions * sizeof(void *))) == NULL)
        return -1;
    
    /* initialize each position */
    htbl->positions = positions;
    for(i = 0; i < htbl->positions; i++)
        htbl->table[i] = NULL;
    
    /* set the vacated member to the sentinel memory address reserved for this */
    htbl->vacated = &vacated;
    
    /* encapsulate the functions */
    htbl->h1 = h1;
    htbl->h2 = h2;
    htbl->match = match;
    htbl->destroy = destroy;
    
    /* initialize the number of elements in the table */
    htbl->size = 0;
    
    return 0;
}

/* ohtbl_destroy */
void ohtbl_destroy(OHTbl *htbl){
    int i;
    
    if(htbl->destroy != NULL){
        /* call a user-defined function to free dynamically allocated data. */
        for(i = 0; i < htbl->positions; i ++){
            if(htbl->table[i] != NULL&& htbl->table[i] != htbl->vacated)
                htbl->destroy(htbl->table[i]);
        }
    }
    
    /* free the storage allocated for the hash table */
    free(htbl->table);
    
    /* no operations are allowed now, but clear the structure as a precaution */
    memset(htbl, 0, sizeof(OHTbl));
    
    return;
}

/* ohtbl_insert */
int ohtbl_insert(OHTbl *htbl, const void *data){
    void *temp;
    int position, i;
    
    /* do not exceed the number of positions in the table. */
    if(htbl->size == htbl->positions)
        return -1;
    
    /* do nothing if the data is already in the table */
    temp = (void *)data;
    if(ohtbl_lookup(htbl, &temp) == 0)
        return 1;
    
    /* use double hasing to hash the key */
    for(i = 0; i < htbl->positions; i++){
        position = (htbl->h1(data) + (i * htbl->h2(data))) % htbl->positions;
        
        if(htbl->table[position] == NULL || htbl->table[position] == htbl->vacated){
            /* insert the data into the table */
            htbl->table[position] = (void *)data;
            htbl->size++;
            return 0;
        }
        
        /* return that the hash functions were selected incorrectly */
        return -1;
    }
}

/* ohtbl_remove */
int ohtbl_remove(OHTbl *htbl, void **data){
    int position, i;
    
    /* use double hashing to hash the key */
    for(i =0; i < htbl->positions; i++){
        position = (htbl->h1(*data) + (i * htbl->h2(* data))) % htbl->positions;
        
        if(htbl->table[position] == NULL){
            /* return that the data was not found */
            return -1;
        }else if(htbl->table[position] == htbl->vacated){
            continue;
        }else if(htbl->match(htbl->table[position], *data)){
            /* pass back the data from the table */
            *data = htbl->table[position];
            htbl->table[position] = htbl->vacated;
            htbl->size--;
            return 0;
        }
    }
    
    /* return that the data was not found */
    return -1;
    
}

/* ohtbl_lookup */
int ohtbl_lookup(const OHTbl *htbl, void **data){
    int position, i;
    
    /* use double hasing to hash the key */
    for(i = 0; i < htbl->positions; i++){
        position = (htbl->h1(*data) + (i * htbl->h2(*data))) % htbl->positions;
        
        if(htbl->table[position] == NULL){
            /* return that the data was not found */
            return -1;
        }else if(htbl->match(htbl->table[position], *data)){
            /* pass back the data from the table */
            *data = htbl->table[position];
            return 0;
        }
    }
    
    /* return that the data was not found */
    return -1;
}