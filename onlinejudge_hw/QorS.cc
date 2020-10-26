#include <iostream>
using namespace std;

int main(){
	int num,ind,data;
	do{	
		cin>>num;
		int array1[100];
		int array2[100];
		int count=0;
		int n1=0,n2=0;
		for(int i=0;i<num;i++){
			cin>>ind>>data;
			if(ind == 1){
				array1[n1]=data;
				n1++;
			}
			else if(ind == 2){
				array2[n2]=data;
				n2++;
			}

		}
		for(int i=0;i<n2;i++){
			if(array2[i]==array1[n1-i-1]){
				count++;
			}
			else if(array2[i]==array1[i]){
				count--;
			}
		}
		if(count == n2){
			cout<<"stack";
		}
		else if(count == n2*(-1)){
			cout<<"queue";
		}
		else {
			cout<<"impossible";
		}
	}while(!EOF);
	return 0;
}
