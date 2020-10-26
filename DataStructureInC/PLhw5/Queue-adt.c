#include <stdlib.h>
#include "Queue.h"  /* file Queue-adt.c
					   other includes such as stdio.h, stdlib.h, etc. */
typedef struct Node /* a private inner struct which is not exported */
{
	int data;
	struct Node* next;
} Node;

typedef struct QueueStruct
{
	Node* front; //first
	Node* back;  //last
	int length;
} QueueStruct;

/* Constructor-Destructor */
QueueHndl NewQueue(void)
{
	QueueHndl Q;
	Q = malloc(sizeof(QueueStruct));
	Q->front = Q->back = NULL;
	Q->length = 0;
	return(Q);
}
/* Access functions */
int getFront(QueueHndl Q) {
	return Q->front->data;
}
int getLength(QueueHndl Q) {
	return Q->length;
}
boolean isEmpty(QueueHndl Q) {
	if(Q->front == Q->back && Q->front==NULL){	
		return true;
	}
	return false;  
}

/* Manipulation procedures */
void Enqueue(QueueHndl Q, int data) {
	if(Q->length == 0){
		Node* newnode = malloc(sizeof(Node));
		newnode->data=data;
		newnode->next=NULL;
		Q->front=newnode;
		Q->back=newnode;
		Q->length++;
	}
	else{
		Node* newnode = malloc(sizeof(Node));
		newnode->data=data;
		newnode->next=NULL;
		Q->back->next=newnode;
		Q->back=Q->back->next;	
		Q->length++;
	}

}
void Dequeue(QueueHndl Q) {
	if(Q->length == 0){
//		printf("Queue is empty");
	}
	else if(Q->length == 1){
		free(Q->front);
		Q->front=NULL;
		Q->back=NULL;
		Q->length=0;
	}
	else{
		//ptr node to delete ntd
		Node* ntd = Q->front;
		Q->front = Q->front->next;
		free(ntd);
		Q->length--;
	}

}

void FreeQueue(QueueHndl* ptrQ) {
	int i;
	for(i=0;i<(*ptrQ)->length;i++){
		Dequeue(*ptrQ);
	}
} 
