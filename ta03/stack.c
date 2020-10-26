#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "list.h"

void push(NodePtr ptr, Stack* stack){
	(*stack)->next = ptr;
   	ptr -> prev = *stack;
	*stack = ptr;
}

void pop(Stack* stack){
	*stack = (*stack)->prev;
	(*stack)->next = NULL;
}

NodePtr top(Stack stack){

}

int isStackEmpty(Stack stack){

}

void deleteStack(Stack* stack){

}

int stackSize(Stack s){

}
