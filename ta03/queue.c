#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "list.h"

void enqueue(NodePtr ptr, Queue* queue){
	(*queue)->next = ptr;
	ptr -> prev = *queue;
	*queue = ptr;
}

void dequeue(Queue* queue){
	*queue = (*queue)->next;
	(*queue)->prev = NULL;
}

NodePtr first(Queue queue){

}

int isQueueEmpty(Queue queue){

}

void deleteQueue(Queue* queue){

}

int queueSize(Queue q){

}

