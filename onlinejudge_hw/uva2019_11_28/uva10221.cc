#include<cstdio>
#include<cstdlib>
#include<cmath>

using namespace std;

#define rOfE 6440


int main(){

	double pi = acos(-1);
	int s,a;
	char min_deg[5];
	int i;
	for(i=0;i<5;i++){
		min_deg[i]='\0';
	}
	while( scanf("%d %d",&s,&a) != EOF){
		gets(min_deg);
		double arcD,chordD,sfloat,afloat;
		double angle;
		double r;

		sfloat = (double)s;
		afloat = (double)a;


		if(min_deg[1] == 109){
			afloat = afloat / 60;	
		}
		while(afloat > 180){
			afloat = afloat - 180;
		}

		angle = 2 * pi * afloat/360;
		r =sfloat + rOfE;

		arcD = angle * r;
		chordD = sqrt( r*r + r*r - 2*r*r*cos(angle) );
		printf("%.6f %.6f\n",arcD,chordD);	
	}


	return 0;
}
