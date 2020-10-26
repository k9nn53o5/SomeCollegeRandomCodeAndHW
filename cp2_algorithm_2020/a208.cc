#include <cstdio>
#include <ctype.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string standardStr(string str1){
	string standStr="";
	for(int i=0;i<str1.length();i++){
		if(str1[i]>=97 && str1[i]<=122){standStr+=str1[i];}
		else if(str1[i]>=65 && str1[i]<=90){standStr += (tolower(str1[i]));}
		else{ standStr+=str1[i];}
	}	
	return standStr;
}

void sortStrings(vector <string> &vec){
	for(int i=1; i<vec.size(); i++)
	{
		for(int j=1; j<vec.size(); j++)
		{
			if(vec[j-1].compare(vec[j]) > 0)
			{
				swap(vec[j-1],vec[j]);
			}
			else if(vec[j-1].compare(vec[j]) == 0){
				vec.erase(vec.begin()+j);
			}
		}
	}
}

int main(){
	string str,tmpStr;
	vector <string> strsInVec;

	while(cin>>str){
		str = standardStr(str);
		int last=0;
		for(int i=0,len= str.size() ; i<len ; i++){
/*			
			   if( !( str[i]>=97&&str[i]<=122 ) && i != last){
			   tmpStr = str.substr(last,i-1-last+1);
			   last = i+1;
			   strsInVec.push_back( tmpStr );
			   }

			   else if( !(str[i]>=97&&str[i]<=122 ) && i == last){
			   last = i+1;
			   }
			   if( i == str.length()-1 && str[i]>=97 && str[i]<=122){
			   tmpStr = str.substr(last,str.length()-1-last+1);
			   strsInVec.push_back( tmpStr );
			   }
*/			 

			if( !isalpha(str[i]) ){
				tmpStr = str.substr(0,i);
				strsInVec.push_back(tmpStr);
				str.erase(0,i+1);
				len = str.size();
				i = -1;
			}

		}
		
		if(!str.empty()){
			if(str.size()==1){
				if(ispunct(str[0])){
					continue;
				}
			}
			strsInVec.push_back(str);
		}	

	}

	sortStrings(strsInVec);

	for(int i=0;i<strsInVec.size();i++){
		cout<<strsInVec[i]<<endl;	
	}
	return 0;
}
