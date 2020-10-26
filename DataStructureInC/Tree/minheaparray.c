#include <stdlib.h>
#include <stdio.h>

#define empty 10e8

int heap_d_num(int* h){
	int l=0;
	while(h[l]!= empty){
		l=l+1;
	}
	return l;
}

void swap(int* h,int po1,int po2){
	//swap data in heap between position -> po1 & po2
	if(po1 == po2){
		return;
	}
	int temp = h[po1];
	h[po1] = h[po2];
	h[po2] = temp;
	return;
}

void bubbleup(int* h,int po){
	// (child po - 1)/2 == parent po
	if(po == 0){
		return;
	}

	int parentpo =  (int)((po-1) / 2);
	if(h[po] >= h[parentpo]){
		return;
	}	

	swap(h,po,parentpo);
	bubbleup(h,parentpo);
}
void add_data_heap(int* h,int data){
	//printf("not implement yet\n");
	int curpo = heap_d_num(h);
	h[curpo] = data;
	bubbleup(h,curpo);
	return;
}

int sinkdown(int* h,int po){
	//make big num sink down
	//return the sinking to bottom position in heap
	//po's child -> po*2+1 & po*2+2
	int childpo1 = po*2+1;
	int childpo2 = po*2+2;
	if(h[po]<=h[childpo1] && h[po]<=h[childpo2]){
		return po;
	}

	else if(h[po]>h[childpo1] && h[po]>h[childpo2]){
		int nextpo = childpo2;
		if(h[childpo1]<h[childpo2]){
			nextpo = childpo1;
		}
		swap(h,po,nextpo);
		sinkdown(h,nextpo);
	}


	else{
		int nextpo = childpo2;
		if(h[childpo1]<h[childpo2]){
			nextpo = childpo1;
		}
		swap(h,po,nextpo);
		sinkdown(h,nextpo);
	}

}

int empty_heap(int* h){
	if(h[0] == empty){
		return 1;
	}
	return 0;
}

void del_min_heap(int* h){
	//printf("not implement yet\n");
	if(empty_heap(h)){
		printf("heap is empty\n");
		return;
	}
	h[0] = 10e8 - 1;
	int sinkpo = sinkdown(h,0);

	if(sinkpo == 0){
		h[0] = empty;
		return;
	}

	int heaplastpo = heap_d_num(h)-1;
	if(sinkpo == heaplastpo){
		h[sinkpo]=empty;
		return;
	}
	swap(h,heaplastpo,sinkpo);
	bubbleup(h,sinkpo);
	h[heaplastpo] = empty;
	return;
}

int get_min(int* h){
	return h[0];
}

void printheap(int* h){
	int l = heap_d_num(h);
	for(int i=0;i<l;i++){
		printf("%d ",h[i]);
	}
	printf("\n");
	return;
}

int main(){
	//can't put over 1024 elements into heap
	//can't put 10e8(def as empty) into heap

	int* root;
	int array[1024];
	root = array;
	int i=0;
	for(i;i<1024;i++){
		array[i] = empty;
	}


	int option,adddata;
	do{
		printf("1 add data// 2 del min// 3 get min// 4 exit // 5 print heap\n");
		scanf("%d",&option);
		switch(option){
			case 1:
				printf("enter a int data\n");
				scanf("%d",&adddata);
				add_data_heap(root,adddata);
				break;
			case 2:
				del_min_heap(root);
				break;
			case 3:
				get_min(root) != empty ? printf("min:%d\n",get_min(root)) 
					: printf("Heap is empty\n");

				break;
			case 4:
				return 0;
			case 5:
				printheap(root);
				break;
			default:
				printf("not an option\n");
				break;	
		}

	}while(1);

	return 0;
}
