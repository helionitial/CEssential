/* cover.h */
#ifndef COVER_H
#define COVER_H

#include "set.h"

/* define a structure for subsets identified by a key */
typedef struct KSet_{
    void *key;
    Set set;
}KSet;

/* public interface */
int cover(Set *members, Set *subsets, Set *covering);

#endif