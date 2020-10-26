#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int deleteLeftNum(string balls){
	int leftNum = balls.length();
	int l=0,r=0;
	while(r<balls.length()){
		if(balls[l]==balls[r]){
			r++;
		}
		else{
			if(r-l >= 3){
				string subStr = balls;
				subStr.erase(l,r-l);
				int tmp = deleteLeftNum(subStr);
				if(leftNum >= tmp){
					leftNum = tmp;
				}
			}
			l=r;
		}
	}
	// check last
	if(r-l >= 3){
		string subStr = balls;
		subStr.erase(l,r-l);
		int tmp = deleteLeftNum(subStr);
		if(leftNum >= tmp){
			leftNum = tmp;
		}
	}
	return leftNum;
}


int main(){
	string balls;
	cin>>balls;
	int ballsNum = balls.length();
	cout<<deleteLeftNum(balls);

}
