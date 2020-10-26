#include <iostream>
#include <cstdio>
using namespace std;

const long long int Max=999999999999999;

bool check(long long n){
	int num0to9[10]={0,1,2,3,4,5,6,7,8,9};
//	cout<<"func1\n";
	while(n>=1){
		num0to9[(int)(n%10)]++;		
		n=n/10;
	}
	for(int i=0;i<10;i++){
		if(num0to9[i]>1){return false;}
	}
	return true;	
}

int main(){
	int Case=0;
	while(scanf("%d",&Case)!=EOF){
//		cout<<Case<<"\n";
		for(int n=0;n<Case;n++){
			long long int N=0;
			scanf("%d",&N);
//			cout<<N<<"\n";
			for(long long int i=1;i<Max;i++){
				if(i*N > Max){
//					cout<<i*N<<"\n";
					break;
				}
				if(check(i*N) && check(i)){
					cout<<"4\n";
					printf("%d / %d = %d\n",i*N,i,N);
				}	
			}
		}
	}
	return 0;
}
