#include <stdlib.h>
#include <stdio.h>

struct Node{
	int data;
	struct Node* left;
	struct Node* right;
};

typedef struct Node node;

int itdit(node* t,int d){
// itdit -> is the data in tree
// yes return 1 , no return 0
	node* curptr = t;
	if(curptr == NULL){
		return 0;
	}
	if(curptr->data == d){
		return 1;
	}
	else if(curptr->data > d){
		curptr = curptr->left;
		return itdit(curptr,d);
	}
	else if(curptr->data < d){
		curptr = curptr->right;
		return itdit(curptr,d);
	}
}

node* newnode(int data){
	node* newptr;
	newptr = (node*)malloc(sizeof(node));
	newptr->data = data;
	newptr->left = NULL;
	newptr->right = NULL;
	return newptr;	
}


/*
void addnode_connect(node* n,node* lastn,int d,int dir){
	//dir => 0:left / 1:right

	if( n== NULL){
		n = newnode(d);
		switch(dir){
			case 0:
				lastn->left = n;
			case 1:
				lastn->right = n;
		}	
		return;
	}

	node* curptr = n;
	if(curptr->data > d){
		node* lastptr = curptr;
		curptr = curptr->left;
		addnode_connect(curptr,lastptr,d,0);
		curptr = NULL;
		lastptr = NULL;
		return;
	}
	else if(curptr->data <= d){
		node* lastptr = curptr;
		curptr = curptr->right;
		addnode_connect(curptr,lastptr,d,1);
		curptr = NULL;
		lastptr = NULL;
		return;
	}
}


void addnode(node* t,int d){
	if(t == NULL){
	//tree size is 0
		t = newnode(d);
	//	printf("add node to root");
		return;
	}
	
	node* curptr = t;
	if(curptr->data > d){
		node* lastptr = curptr;
		curptr = curptr->left;
		addnode_connect(curptr,lastptr,d,0);
		curptr = NULL;
		lastptr = NULL;
		return;
	}
	else if(curptr->data <= d){
		node* lastptr = curptr;
		curptr = curptr->right;
		addnode_connect(curptr,lastptr,d,1);
		curptr = NULL;
		lastptr = NULL;
		return;
	}

}
*/

node* addnode(node* r, int d){
	if(r == NULL){
		r = newnode(d);
		return r;
	}

	node* curptr,* backupptr;
	curptr = r;
	while(curptr != NULL){
		if(d >= curptr->data){
			backupptr = curptr;
			curptr = curptr->right;	
		}
		else{
			backupptr = curptr;
			curptr = curptr->left;
		}
	}
	if(d >= backupptr->data){
		backupptr->right = newnode(d);
	}
	else{
		backupptr->left = newnode(d);
	}
	return r;	

}

void printinorder(node* t){
	if(t == NULL){
		return;
	}
	printinorder(t->left);
	printf("%d ",t->data);
	printinorder(t->right);	
}

int main(){
	node* r = NULL;
	int list[10]={2,5,4,9,1,7,6,3,0,8};
	int i;
	for(i=0;i<10;i++){
		r = addnode(r,list[i]);
	}
	//printf("%d",itdit(r,11));
	printinorder(r);
	return 0;
}
