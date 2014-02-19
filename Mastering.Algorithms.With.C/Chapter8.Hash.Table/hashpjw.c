/* hashpjw.c 
 * a sample hash function for processing string
 */

#include "hasnpjw.h"

/* hashpjw */
unsigned int hashpjw(const void *key){
    const char *ptr;
    unsigned int val;
    
    /* hash the key by performing a number of bit operations on it. */
    val = 0;
    ptr = key;
    
    while(*ptr != '\o'){
        unsigned int tmp;
        val = (val << 4) + (*ptr);
        
        if(tmp = (val & 0xf0000000)){
            val = val ^ (tmp >> 24);
            val = val ^ tmp;
        }
        
        ptr ++;
    }
    
    /* in practice, replace PRIME_TBLSIZ with the actual table size */
    return val % PRIME_TBLSIZ;
}
