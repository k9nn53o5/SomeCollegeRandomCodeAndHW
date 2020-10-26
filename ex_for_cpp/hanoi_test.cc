#include <iostream>
using namespace std;

void hanoi(int n,char a,char b,char c);
int main(){
	int DiskNum;
	char A,B,C;
	cout << "Please input the number of disks ";
	cin >> DiskNum;
	hanoi(DiskNum,'A','B','C');
	return 0;
} 

void hanoi(int n, char a,char b,char c){
	if(n==1){
		cout << "Move from " << a <<" to " << c << endl;
	}
	else{
		hanoi(n-1,a,c,b);
		cout << "Move from " << a << " to " << c << endl;
		hanoi(n-1,b,a,c);
	}
}
