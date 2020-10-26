#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

class Dice{
	public:
		int topNum;
		int bottomNum;
		int norNum;
		int southNum;
		int eastNum;
		int westNum;

		Dice(){
			topNum = 1;
			bottomNum = 6;
			norNum = 2;
			southNum = 5;
			eastNum = 4;
			westNum = 3;
		}
		/*
		   Dice(const Dice &d2){	
		   topNum = d2.topNum;
		   bottomNum = d2.bottomNum;
		   norNum = d2.norNum;
		   southNum = d2.southNum;
		   eastNum = d2.eastNum;
		   westNum = d2.westNum;
		   }
		 */
		Dice(int t,int b,int n,int s,int e,int w){

			topNum = t;
			bottomNum = b;
			norNum = n;
			southNum = s;
			eastNum = e;
			westNum = w;

		}
		void roll(string dir);
		//	~Dice();
};



void Dice::roll(string dir){
	Dice dCopy;
	dCopy.topNum = topNum;
	dCopy.bottomNum = bottomNum;
	dCopy.norNum = norNum;
	dCopy.southNum = southNum;
	dCopy.eastNum = eastNum;
	dCopy.westNum =  westNum;

	//static Dice dCopy(topNum,bottomNum,norNum,southNum,eastNum,westNum);
	//	printf("///%d///",dCopy.topNum);

	if(dir == "north"){					
		topNum = dCopy.southNum;
		bottomNum = dCopy.norNum;
		norNum = dCopy.topNum;
		southNum = dCopy.bottomNum;
	}
	else if(dir == "south"){	
		topNum = dCopy.norNum;
		bottomNum = dCopy.southNum;
		norNum = dCopy.bottomNum;
		southNum = dCopy.topNum;
	}
	else if(dir == "east"){
		topNum = dCopy.westNum;
		bottomNum = dCopy.eastNum;
		eastNum = dCopy.topNum;
		westNum = dCopy.bottomNum;
	}
	else if(dir == "west"){	
		topNum = dCopy.eastNum;
		bottomNum = dCopy.westNum;
		eastNum = dCopy.bottomNum;
		westNum = dCopy.topNum;
	}
	else{
		printf("error:not dir");
	}
}

int main(){
	//	printf("myDice:%d",myDice.topNum);
	while(1){

		int inputNum;
		string inputDir;
		Dice myDice = Dice();
		scanf("%d\n",&inputNum);
		if(inputNum == 0){break;}
		for(int i=0;i<inputNum;i++){
			cin >> inputDir;
			myDice.roll(inputDir);
	//		cout << inputDir<<endl;
	//		printf("%d\n",myDice.topNum);
		}
			printf("%d\n",myDice.topNum);
	}

	return 0;
}
