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

void addnode(List l,int d,int po){
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

	if(po <= 0){
		newptr->next = l->head;
		l->head = newptr;
		l->length++;
		return;
	}
	else if(po>0 && po<=l->length-1){
		node* cur = l->head;
		int i;
		for(i=0;i<po-1;i++){
			cur = cur->next;
		}
		newptr->next = cur->next;
		cur->next = newptr;
		cur = NULL;
		l->length++;
		return;
	}
	else if(po > l->length-1){
		l->back->next = newptr;
		l->back = l->back->next;
		l->length++;
		return;
	}
}

void delnode(List l,int po){
	if(l->length == 0){
		printf("there r no node to delete\n");
		return;
	}
	if(po <= 0){
		node* delptr = l->head;
		l->head = l->head->next;
		free(delptr);
		delptr=NULL;
		l->length--;
		return;
	}
	else if(po > 0 && po < l->length-1){
		node* delptr = l->head;
		int i;
		for(i=0;i < po;i++){
			delptr = delptr->next;
		}
		node* curptr = l->head;
		for(i=0;i < po-1;i++){
			curptr = curptr->next;
		}
		curptr->next = delptr->next;
		free(delptr);
		curptr = NULL;
		delptr = NULL;
		l->length--;
		return;
	}
	else if(po >= l->length-1){
		node* delptr = l->back;
		int i;
		l->back = l->head;
		for(i=0;i<l->length-2;i++){
			l->back = l->back->next;
		}
		free(delptr);
		delptr=NULL;
		l->length--;
		return;	
	}
}

void printlist(List l){
	if(l->length == 0){
		printf("It is an empty list\n");
		return;
	}
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
	int adddata,addpo,delpo;
	List Alist = newlist();
	do{
		printf("length of the list is %d\n",Alist->length);
		printf("1 add node,2 del node,3 print list,4 exit\n");
		scanf("%d",&option);
		switch(option){
			case 1:
				printf("input a int (1) to a position (2) U want in the list\n");
				printf("(1)");
				scanf("%d",&adddata);
				printf("(2)");
				scanf("%d",&addpo);
				addnode(Alist,adddata,addpo);
				break;
			case 2:
				printf("(1) input a position to delete\n");
				//printf("(2) input a data to delete\n");
				scanf("%d",&delpo);
				delnode(Alist,delpo);
				break;
			case 3:
				printlist(Alist);
				break;
			case 4:
				return 0;
				break;
			default:
				printf("not an option\n");
				break;

		}
	}while(1);
	//	system("pause");
	return 0;
}
