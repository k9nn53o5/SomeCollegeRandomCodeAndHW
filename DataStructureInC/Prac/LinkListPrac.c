//still not working

#include <stdio.h>
#include <stdlib.h>


struct node{
	int data;
	struct node *next;
};
typedef struct node Node;

void AddFunc(Node *head,Node *ptr);
void DeleteFunc(Node *head,Node *ptr); 

int main(){
	Node *head=NULL;
	head = (Node*)malloc(sizeof(Node));
 	head->next = NULL;
	Node *ptr=NULL;
	ptr = (Node*)malloc(sizeof(Node));
	ptr->next = NULL;
	int option;
	do{
	printf("1 add node,2 delete ptr node,3 exit\n");
	scanf("%d",&option);
	if(option == 1){
		AddFunc(head,ptr);
	}
	else if(option == 2){
		DeleteFunc(head,ptr);
	}
	}while(option != 3);
	return 0;
}

void AddFunc(Node *head,Node *ptr){
	int i;
	for(i=0;i<2;i++){	
	Node *newnode;
	newnode = (Node*)malloc(sizeof(Node)); 
	newnode->data = i;
	newnode->next = NULL;
		if(head == NULL && ptr == NULL){
			head = newnode;
			ptr = newnode;
			printf("%d ",ptr->data);
			printf("A\n");	
		}
		else{
			ptr->next = newnode;
			ptr = ptr->next;
			printf("B\n");
		}
	}
	printf("\n");
//	ptr = head;
/*	while(ptr != NULL){
		printf("%d ",ptr->data);
		ptr = ptr->next;
		i++;
	}*/
	printf("%d\n",&head->data);
	printf("%d\n",head->data);
	printf("%d\n",&ptr->data);
	printf("%d\n",ptr->data);
}
void DeleteFunc(Node *head,Node *ptr){

}
