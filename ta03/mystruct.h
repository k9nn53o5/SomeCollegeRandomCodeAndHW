#ifndef _MY_STRUCT_H_
#define _MY_STRUCT_H_

struct node;
typedef struct node Node;
typedef Node* NodePtr;


struct node{
    int element;
	struct node* prev;
    struct node* next;
};

/*Returns true if elements of two nodes are equal.*/
int isEqual(Node, Node);

/*Wrap the data and malloc a Node stores them and return*/
NodePtr createNode(int);


#endif
