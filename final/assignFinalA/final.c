#include<stdio.h>
#include<string.h>
int main(int argc, char *argv[]){
	int menu = 0;
	int quit = 0;
	int x1,x2,y1,y2,z1,z2,inpro;

	int len2,j,i;
	int counter2 = 0;
	int array2[1000];

	char array3[1000];
	int len3;

	while(!quit){
		printf( "=======MENU=========\n"
				"1 - Inner Product\n"
				"2 - Unique Element\n"
				"3 - Capitalization\n"
				"4 - Overlapping Area\n"
				"6 - Permutation\n"
				"7 - EXIT\n"
				"====================\n"
				"Enter Your choice:\n") ;
		scanf( "%d", &menu ) ;
		getchar();
		switch( menu ) {
			case 1:
				// Inner Product
				scanf("%d %d %d",&x1,&y1,&z1);
				scanf("%d %d %d",&x2,&y2,&z2);
				inpro = x1*x2 + y1*y2 + z1*z2;
				printf("%d\n",inpro);
				// x1 x2 y1 y2 z1 z2 inpro
				break;
			case 2:
				scanf("%d",&len2);
				for(i=0;i<len2;i++){
					scanf("%d",&array2[i]);
				}
				for(i=0;i<len2;i++){
					for(j=0;j<i;j++){

					if(array2[i] == array2[j]){
						counter2++;
					}
					}
					if(counter2 == 0){
						printf("%d ",array2[i]);
				}
					counter2 = 0;
				}
//				printf("\n");
				//len2 i array2 counter2
				break;
			case 3:
				gets(array3);
				len3 = strlen(array3);
				for(i=0;i<len3;i++){
					if(i == 0 && (array3[i] >= 97 && array3[i] <= 122)){
						printf("%c", array3[i]-32);
					}
					else if(i == 0 && (array3[i] >= 65 && array3[i] <= 90)){
						printf("%c",array3[i]);
					}
					else if(i != 0 && (array3[i] >= 97 && array3[i] <= 122)){
						printf("%c",array3[i]);
					}
					else if(i != 0 && (array3[i] >= 65 && array3[i] <= 90)){
						printf("%c",array3[i]+32);
					}
				}
				printf("\n");
				// Capitalization
				break;
			case 4:
				// Overlapping Area
			//	scanf("%d %d %d %d",&a1,&b1,&a2,&b2);
			//	scanf("%d %d %d %d",&a3,&b3,&a4,&b4);
			//	if(b2>b3&&a2>a3){
			//		area == 
			//	}
				break;
			case 6:
			//	scanf("%d %d",&n6,&k6);
			//	while(h6>y6){
				
			//	}
				// Permutation
				break;
			case 7:
				quit = 1;
				break;
			default :
				printf( "Wrong choice!\n") ;
				break;
		}
		printf("\n");
	}

	return 0;
}
