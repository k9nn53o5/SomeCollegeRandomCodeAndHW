#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "queue.h"
#define MAX_STATION_PASSENGER (8)
#define MAX_CABLE_CAR_LOAD (300)

int main(){
	int tmp=0,num=0,car=0,line=0,carry=0,i=0;
	Stack current=NULL,print=NULL;
	Queue whead=NULL,wtail=NULL,ohead=NULL,otail=NULL;


	while(1){
		if(scanf("%d",&tmp)==EOF)
			break;
		else if(tmp==-1){
			while(whead!=NULL){
				/*start take cable car*/
				while(carry<300){
					car++;
					carry = carry + whead->element;
					if(current==NULL)
						current=createNode(whead->element);
					else
						push(createNode(whead->element),&current);
					if(whead->next==NULL){
						whead=NULL;
						break;
					}
					else
						dequeue(&whead);
				}

				/*kick overweight*/
				if(carry>300){
					car--;
					if(whead!=NULL)
						enqueue(createNode(current->element),&wtail);
					else{
						whead=createNode(current->element);
						wtail=whead;
					}
					pop(&current);
				}

				/*print*/
				print=current;
				while(print!=NULL){
					printf("%d",print->element);
					if(print->prev!=NULL)
						printf(" ");
					print=print->prev;
				}
				puts("");

				/*people waiting outside go to the waiting line*/
				if(ohead!=NULL){
					for(i=0;i<car;i++){
						enqueue(createNode(ohead->element),&wtail);
						if(ohead->next!=NULL)
							dequeue(&ohead);
						else{
							ohead=NULL;
							break;
						}
					}
				}

				/*free cable car*/
				car=0;
				carry=0;
				current=NULL;
			}

			/*free all data to start another input*/
			num=0;
			whead=NULL;
			wtail=NULL;
			ohead=NULL;
			otail=NULL;
			puts("");
		}
		else{
			if(num<8){
				/*go to waiting line in queue*/
				if(whead==NULL){
					whead=createNode(tmp);
					wtail = whead;
				}
				else
					enqueue(createNode(tmp),&wtail);
			}
			else{
				/*go to outside in queue*/
				if(ohead==NULL){
					ohead=createNode(tmp);
					otail = ohead;
				}
				else
					enqueue(createNode(tmp),&otail);
			}
			num++;
		}
	}

    return 0;
}
