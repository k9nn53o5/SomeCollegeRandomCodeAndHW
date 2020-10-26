#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	char c;
	vector<int> v1,v2;
	while(1){
		int tmp;
		while(cin>>tmp){
			char m;
			v1.push_back(tmp);
			m = getchar();
			if(m=='\n'){
				break;
			}
		}
		while(cin>>tmp){
			char m;
			v2.push_back(tmp);
			m = getchar();
			if(m=='\n'){
				break;
			}
		}
		if(cin>>tmp){break;}
	}
	/*
	   for(int i=0;i<v1.size();i++){
	   cout<<v2[i]<<" ";
	   }
	 */
	return 0;
}
