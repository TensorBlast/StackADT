#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"

struct node
{
	void * data;
	struct node * next;
};

struct stack_struct
{
	struct node *top;
};

static void die(const char * msg)
{
	printf("%s\n", msg);
	exit(EXIT_FAILURE);
}

void destroy(Stack s)
{
	make_empty(s);
	free(s);
}

void make_empty(Stack s)
{
	while (!is_empty(s))
		pop(s);
}

bool is_empty(Stack s)
{
	return s->top == NULL;
}

bool is_full(Stack s)
{
	return false;
}

Stack create_stack(void)
{
	Stack s = malloc(sizeof(struct stack_struct));
	if (s == NULL)
		die("Error in create: Couldn't create stack");

	s->top = NULL;
	return s;
}

void push(Stack s, void * item)
{
	struct node *new_node = malloc(sizeof(struct node));
	if (new_node == NULL)
		die("Error in push: stack is full");
	new_node->data = item;
	new_node->next = s->top;
	s->top = new_node;

}

void * pop(Stack s)
{
	if(is_empty(s))
		die("Error in pop: Stack is empty");

	struct node *old_node = s->top;
	void * data = old_node->data;
	s->top = s->top->next;
	free(old_node);
	return data;
}