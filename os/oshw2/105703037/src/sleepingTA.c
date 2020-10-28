#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CHAIRS_NUM 10 //實驗室外可坐椅子的最大數量
#define TOTAL_TIME 100 //定義100個單位時間 

//- global param defination ------------------//
int studentPerTime[TOTAL_TIME];     // 每個單位時間點是否有學生來的情況 0：沒有學生來 1:有學生來
int numOfOccupiedChairs = 0; // 被佔據椅子的計數器
double waitingTime = 0;         // 所有學生總等待時間計數器
double avgWaitingTime;

//mutuex
sem_t chairMutex; //調用numOfOccupiedChairs變數時，使用mutex。範圍 0-1，初始值1
sem_t timeMutex;   //調用waitingTime時，使用此mutex。範圍 0-1，初始值1
//semaphore
sem_t availableStudentsSem; //代表等待學生之semaphore。範圍 0-n，初始值0
sem_t TA_sem;               //代表TA之semaphore。範圍 0-1，初始值0

int timeFlag = 0;
int allStudents = 0;     //100個單位時間內，來的學生的計數器
int waitingStudents = 0; //有進實驗室的學生人數


void *TA(void *temp);
void *Student(void *temp);

int main(void)
{
	pthread_t TA_id;
	pthread_t student_ids[TOTAL_TIME];

	FILE *f;
	f = fopen("input.txt", "r");

	for (int i = 0; i < TOTAL_TIME; i++)
	{
		int temp;
		fscanf(f, "%d\n", &temp);
		studentPerTime[i] = temp;
	}
	fclose(f);

	sem_init(&chairMutex, 0, 1);
	sem_init(&timeMutex, 0, 1);
	sem_init(&availableStudentsSem, 0, 0);
	sem_init(&TA_sem, 0, 0);

	pthread_create(&TA_id, NULL, TA, NULL);

	for (int i = 0; i < TOTAL_TIME; i++)
	{
		timeFlag++;
		printf("time %d \n", timeFlag);

		if (studentPerTime[i] != 0)
		{
			allStudents++;
			printf("Student %d comes.\n", allStudents);

			pthread_create(&student_ids[i], NULL, Student, NULL);
		}
		else
		{
			printf("No student come.\n");
		}

		usleep(1000);
	}




	for(int i=0;i<TOTAL_TIME;i++){
		if( studentPerTime[i] != 0){
			pthread_join(student_ids[i],NULL);
		}
		else{
		}
	}
//	pthread_join(TA_id,NULL);

	printf("waitingTime %f\n",waitingTime);
	printf("waitingStudents %d\n",waitingStudents);
	printf("%f\n",waitingTime / waitingStudents);
	return 0;
}

void *TA(void *temp)
{
	while(1){
		sem_wait(&availableStudentsSem);
		sem_wait(&chairMutex);
		numOfOccupiedChairs = numOfOccupiedChairs - 1;
		sem_post(&chairMutex);
		sem_post(&TA_sem);
		waitingStudents += 1;
		usleep(2000);
		sem_wait(&timeMutex);
		waitingTime += 2;
		sem_post(&timeMutex);
	}
}

void *Student(void *temp)
{
	sem_wait(&chairMutex);
	if(numOfOccupiedChairs < MAX_CHAIRS_NUM){
		numOfOccupiedChairs = numOfOccupiedChairs + 1;
		sem_post(&chairMutex);
		for(int i = 0 ;i < numOfOccupiedChairs-1 ;i++){
			usleep(2000);
			sem_wait(&timeMutex);
			waitingTime+=2;
			sem_post(&timeMutex);
		}
		sem_post(&availableStudentsSem);
		sem_wait(&TA_sem);
	}
	else{
		sem_post(&chairMutex);
	}

}
