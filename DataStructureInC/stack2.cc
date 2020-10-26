#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
	char *Achar;
	stack <string> Astring;
	string s1,s2;
	do{
		char c = getchar();
		s2+=c;
		Achar=&c;
		Astring.push(Achar);
	}while(*Achar != '\n');
	while(Astring.size() != 0){
	s2+=Astring.top();
	Astring.pop();
	}
	cout << s1 << '\n' << s2 << '\n';
	if(s1 == s2){
		cout<<"yes";
	}
	else{
		cout <<"no";
	}
	return 0;
}
