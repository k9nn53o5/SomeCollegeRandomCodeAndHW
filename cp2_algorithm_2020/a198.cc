#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
using namespace std;

int main(){
	time_t rawtime;
	struct tm * timeinfo;	
	int m,d;
	const char * weekday[] = { "Sunday", "Monday",
		"Tuesday", "Wednesday",
		"Thursday", "Friday", "Saturday"};
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){	
		scanf("%d %d",&m,&d);
		time ( &rawtime );
		timeinfo = localtime ( &rawtime );
		timeinfo->tm_year = 2020 - 1900;
		timeinfo->tm_mon = m - 1;
		timeinfo->tm_mday = d ;
		mktime ( timeinfo );

		printf ("%s\n", weekday[timeinfo->tm_wday]);
	}
	return 0;
}
