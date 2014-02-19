/* stack.h */
#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

#include "list.h"

/* implement stacks as linked lists. */
typedef list Stack;
list/* public interface */
#define stack_init list_init

#define stack_destroy list_destroy

int stack_push(Stack *stack, const void *data);
int stack_pop(Stack *stack, void **data);

#define stack_peek(stack)((stack)->head == NULL?NULL:(stack)->head->data)

#define stack size list_size

#endif
