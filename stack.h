#ifndef STACKADT_H
#define STACKADT_H

#include <stdbool.h>

typedef struct stack_struct * Stack;

Stack create_stack(void);
void destroy(Stack s);
void push(Stack s, void * t);
void make_empty(Stack s);
bool is_empty(Stack s);
bool is_full(Stack s);
void * pop(Stack s);


#endif