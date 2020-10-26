#include <iostream>
#include <string.h>
using namespace std;

long int countMoveStep(int i1,int i2,int i3,int Total,long int (&m)[3][3]){
	long int result;
	result = Total - m[0][i1] - m[1][i2] - m[2][i3]; 
	return result;
}

int main(){
	long int maxtrix3_3 [3][3];
	while(scanf("%ld %ld %ld %ld %ld %ld %ld %ld %ld",
				&maxtrix3_3[0][0],&maxtrix3_3[1][0],&maxtrix3_3[2][0]
				,&maxtrix3_3[0][1],&maxtrix3_3[1][1],&maxtrix3_3[2][1]
				,&maxtrix3_3[0][2],&maxtrix3_3[1][2],&maxtrix3_3[2][2]
				) != EOF
			)
	{
		long int Total = 
				maxtrix3_3[0][0] + maxtrix3_3[1][0] + maxtrix3_3[2][0] +
				maxtrix3_3[0][1] + maxtrix3_3[1][1] + maxtrix3_3[2][1] +
				maxtrix3_3[0][2] + maxtrix3_3[1][2] + maxtrix3_3[2][2] ;

		long int min = 2147483647;
		char color[3];

		for(int i1=0;i1<3;i1++){
		for(int i2=0;i2<3;i2++){
		for(int i3=0;i3<3;i3++){
			if(i1!=i2 && i2!=i3 && i1!=i3){
				long int steps = countMoveStep(i1,i2,i3,Total,maxtrix3_3);
				char tmpcolor[3];
				tmpcolor[i1] = 'B';tmpcolor[i2] = 'G';tmpcolor[i3] = 'C';
				if(min>steps   ||   min==steps && strcmp(color,tmpcolor)>0){
					min = steps;
					strncpy(color,tmpcolor,3);
				}
			}
		}
		}
		}
		cout<<color<<" "<<min<<endl;
	}

	return 0;
}
