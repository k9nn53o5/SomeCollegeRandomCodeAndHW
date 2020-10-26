#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int n=0;
	int coinnumarr[100]={0}; //b
	int minarr[];  //a
	while(cin>>n){
		int m=0;
		cin>>m;
		for(int i=0;i<m;i++){
			cin>>coinnumarr[i];	
		}

		//m(b1+..bm)-2(a1b1+a2b2+...ambm) ==> c-d
		int c =0;
		for(int i=0;i<m;i++){
			c+=(m*coinnumarr[i]);
		}
		int min=1000;
		for(int i=0;i<m;i++){
			
		}
	}

	return 0;
}

