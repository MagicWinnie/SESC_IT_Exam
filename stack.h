#ifndef BINTREE_H
#define BINTREE_H

#include <stdio.h>
#include <stdlib.h>

struct list {
	int data;
	struct list * next;
};

typedef struct stack{ struct list *top; } Stack;

void makenull(Stack  *S)
{	struct list *p;
	while (S->top)
	 {
		p = S->top;
		 S->top = p->next;
		free(p);
	} 
}

Stack *create ()
{	
	Stack* S;
	S = (Stack *) malloc (sizeof (Stack));
	S->top = NULL;
	return S;
}

int top(Stack *S)
{
	if (S->top)
		return (S->top->data);
	else 
		return 0;
}

int pop(Stack *S)
{
	int a;
	struct list *p;
	p = S->top;
	a = p->data;
	S-> top = p->next;
	free(p);
	return a;
}

void push(Stack *S, int a)
{
	struct list *p;
	p = (struct list *) malloc ( sizeof (struct list));
	p->data = a;
	p->next = S-> top;
	S->top = p ;
}

int empty(Stack *S)
{
	return (S->top == NULL);
}

#endif