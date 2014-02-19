/* list.h */

#ifndef LIST_H
#define LIST_H
// Point: define this header file

#include<stdlib.h>
// Point: import header file

/* Define a structure for linked list elements. */
typedef struct ListElmt_
{
    void *data;
    struct ListElmt_ *next;
    // Point: can have pointer to self-struct within struct
}ListElmt;
// Point: define struct and declare struct

/* Define a structure for linked lists. */
typedef struct LIST_
{
    int size;
    int (*match)(const void *key1, const void *key2);
    void (*destroy)(void *data);
    ListElmt *head;
    ListElmt *tail;
}List;


/* public Interface */
void list_init(List *list, void (*destroy)(void *data)); //?  why pass function as parameter
void list_destroy(List *list);
int list_ins_next(List *list, ListElmt *element, const void *data);
int list_rem_next(List *list, ListElmt *element, void **data);



#define list_size(list)((list)->size)
#define list_head(list)((list)->head)
#define list_tail(list)((list)->tail)
#define list_is_head(list, element)((element) == (list)->head?1:0)
#define list_is_tail(list, element)((element)->next == NULL?1:0)
#define list_data(element)((element)->data)
#define list_next(element)((element)->next)

#endif
