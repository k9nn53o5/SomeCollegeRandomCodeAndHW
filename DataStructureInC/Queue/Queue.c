#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}node;

struct list{
	node* head;
	node* back;
	int length;
};
typedef struct list * List;

List newlist(){
	List l;
	l = malloc(sizeof(struct list));
	l->head = NULL;
	l->back = NULL;
	l->length = 0;
	return l;
}

void addnode(List l,int d){
	node* newptr;
	newptr = malloc(sizeof(node));
	newptr->data = d;
	newptr->next = NULL;
	if(l->length == 0){
		l->head = newptr;
		l->back = newptr;
		l->length++;
		return;
	}
	l->back->next = newptr;
	l->back = l->back->next;
	l->length++;
}

void delnode(List l){
	if(l->length == 0){
		printf("there r no node to delete\n");
		return;
	}

	node* delptr = l->head;
	//put l->head to the next node
	l->head = l->head->next;
	l->length--;
	
	//delete the first node
	free(delptr);
	return;
}

void printlist(List l){
	node* printptr;
	printptr = l->head;
	while(printptr != l->back->next){
		printf("%d ",printptr->data);
		printptr = printptr->next;
	}
	printf("\n");
	return;
}

int main(){
	int option;
	int adddata;
	List Alist = newlist();
	do{
		printf("1 add node,2 del node,3 print list,4 exit\n");
		scanf("%d",&option);
		switch(option){
			case 1:
				printf("input a int to add it to the bottom of the list\n");
				scanf("%d",&adddata);
				addnode(Alist,adddata);
				break;
			case 2:
				delnode(Alist);
				break;
			case 3:
				printlist(Alist);
				break;
			case 4:
				return 0;
				break;
			default:
				printf("not an option");
				break;

		}
	}while(1);
//	system("pause");
	return 0;
}
