#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct grade {
	char * name;  float grade;  
} grade;
int i;
grade students[5];
char *names[5] = {"John","Eric","Paul","Carol","Jim"};
float grades [5] = {90,76,80,70,60};
int compare1(const void* a,const void* b) {
	grade* tmp1 = (grade*) a;
	grade* tmp2 = (grade*) b;
	if(tmp1->grade > tmp2->grade){
		return 1;
	}
	return -1;
} //youri code
int compare2(const void* a,const void* b) {
	grade* tmp1 = (grade*) a;
	grade* tmp2 = (grade*) b;
	return strcmp(tmp1->name,tmp2->name);
} //your code
int main() {
	for (i=0; i<5; i++) {
		students[i].name = names[i];
		students[i].grade = grades[i];
	}

	// call qsort twice on students
	// one to sort by name, the other by grade 
	//your code
	grade* ptr=students;
	qsort(ptr,5,sizeof(grade),compare1);
	printf("(1)");
	for (i=0; i<5; i++) {
		printf("(%s, %f) ", students[i].name, students[i].grade );
	} 
	printf("\n");
	qsort(ptr,5,sizeof(grade),compare2); 
	//  //your code
	printf("(2)");
	for (i=0; i<5; i++) {
		printf("(%s, %f) ", students[i].name, students[i].grade );
	} 
	printf("\n");
	return 0;
}
// main
//output:
// (1) (Jim, 60.000000) ¡K  (John, 90.000000)
// (2)  (Carol, 70.00000) (Eric, 60.00000) ¡K (Paul, 80.000000)
