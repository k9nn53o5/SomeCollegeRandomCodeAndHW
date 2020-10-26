#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
	char *Achar;
	stack <string> Astring;
	do{
		char c = getchar();
		Achar = &c;	
		Astring.push(Achar);
	}while(*Achar != '\n');				 
	while(Astring.size() != 0){ 
		cout << Astring.top();
		Astring.pop();
	}
					return 0;
}
