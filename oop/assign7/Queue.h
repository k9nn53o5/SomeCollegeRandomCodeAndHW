#ifndef QUEUE_H
#define QUEUE_H
#include "Node.h"
#include <iostream>
using namespace std;
template<class T>
class Queue{
	public:
		Queue();
		~Queue();
		bool isempty();
		bool enqueue(const T& entry);
		bool dequeue();
		T peek();
		int len();
		
	private:
		Node<T>* top;
		Node<T>* last;
		int length=0;
};
template<class T> 
Queue<T>::Queue():top(NULL),last(NULL){
}
template<class T>
Queue<T>::~Queue(){
	while(!isempty()){
		dequeue();
	}
	top = NULL;
	last = NULL;
}
template<class T> 
bool Queue<T>::isempty(){
		if(top == NULL && last == NULL){
				return true;
				}
		else{
				return false;
				}
}
template<class T> 
bool Queue<T>::enqueue(const T& entry){
		Node<T>* newNodeptr = new Node<T>(entry);
//		newNodeptr->setdata(entry);
			if(isempty()){
				top = newNodeptr;
				last = newNodeptr;
						}
			else {
				last->setnext(newNodeptr);	
				last = last->getnext();
						}
			newNodeptr = NULL;
			length++;
					return true;	
}
template<class T> 
bool Queue<T>::dequeue(){
		if(!isempty()){
				Node<T>* deleteNodeptr = top;
				if(top->getnext() == NULL){
					top = NULL;
					last = NULL;
								}
				else{
					top = top->getnext();
						}
					deleteNodeptr->setnext(NULL);
					delete deleteNodeptr;
					deleteNodeptr =NULL;
					length--;
					return true;
						}
			else{
						return false;
							}
}
template<class T> 
T Queue<T>::peek(){
	if(!isempty()){
		return top->getdata();}
}
template<class T>
int Queue<T>::len(){
	return length;
}
					
#endif
