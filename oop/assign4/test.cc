#include <iostream>
#include "Vector.h"
using namespace std;

int main(){
	int i=0;
	Vector a(3);
	cout << a.fDimension << '\n';
	while(*(a.fElements+i)){
		cout<<*(a.fElements+i);
		i++;
	}
	return 0;
}
