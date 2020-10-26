#include <iostream>
using namespace std;

int main(){
	int noNum,sum=0;
	cin>>noNum;
	for(int i=0;i<noNum;i++){
		int no;
		cin>>no;
		sum+=no;
	}
	cout<<sum;
	return 0;
}

