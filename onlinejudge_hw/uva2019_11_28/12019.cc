#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int dateNumOfMonthArray[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

string dayOfWeek_2011(int month,int date){
	//2011 1/1 is 6
	int daysAfter_1_1=0;
	int dayOfWeek;
	for(int i=1;i<month;i++){
		daysAfter_1_1+=dateNumOfMonthArray[i];
	}
	daysAfter_1_1+=(date-1);
	dayOfWeek = (6 + daysAfter_1_1)%7;
	switch(dayOfWeek){
		case 1:
			return "Monday";
			break;
		case 2:
			return "Tuesday";
			break;

		case 3:
			return "Wednewday";
			break;
		case 4:
			return "Thursday";
			break;
		case 5:
			return "Friday";
			break;
		case 6:
			return "Saturday";
			break;
		case 0:
			return "Sunday";
			break;
	}
}

int main(){
	int lineNum=0;
	int month,date;
	scanf("%d",&lineNum);
	for(int i=0;i<lineNum;i++){
		scanf("%d %d",&month,&date);
		cout<<dayOfWeek_2011(month,date)<<endl;
	}
	return 0;
}
