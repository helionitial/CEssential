/* page.h */
#ifndef PAGE_H
#define PAGE_H

#include "clist.h"
/*define a structure for information about pages. */
typedef struct Page_{
    int number;
    int reference;
}Page;

/* public interface */
int replace_page(CListElmt **current);

#endif