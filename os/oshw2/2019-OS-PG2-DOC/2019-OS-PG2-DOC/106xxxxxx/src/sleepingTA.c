#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_CHAIRS_NUM 10 //實驗室外可坐椅子的最大數量
#define TOTAL_TIME 100 //定義100個單位時間 

//- global param defination ------------------//
int studentPerTime[TOTAL_TIME];     // 每個單位時間點是否有學生來的情況 0：沒有學生來 1:有學生來
int numOfOccupiedChairs = 0; // 被佔據椅子的計數器
double waitingTime = 0;         // 所有學生總等待時間計數器
double avgWaitingTime;

//mutuex
sem_t chairMutex; //調用numOfOccupiedChairs變數時，使用mutex。範圍 0-1，初始值1
                  //to make sure that multi threads will not acess the var numOfoccupiesChair at the same time

sem_t timeMutex;   //調用waitingTime時，使用此mutex。範圍 0-1，初始值1
//semaphore
sem_t availableStudentsSem; //代表等待學生之semaphore。範圍 0-n，初始值0
                            // if sem > 0 then TA have to teach student and if sem == 0 then TA go to sleep
                            //TA will use it

sem_t TA_sem;               //代表TA之semaphore。範圍 0-1，初始值0, 0 is avialable then student can be teach
                            //1 is not available so student have to wait
                            //Student will use it

int timeFlag = 0;
int allStudents = 0;     //100個單位時間內，來的學生的計數器
int waitingStudents = 0; //有進實驗室的學生人數

//- function prototype -----------------------//
void *TA(void *temp);
void *Student(void *temp);

int main(void)
{
    //- thread defination --------------------//
    pthread_t TA_id;
    pthread_t student_ids[TOTAL_TIME]; //可能有100個student來

    //- read input.txt -----------------------//
    FILE *f;
    //FILE * fopen ( const char * filename, const char * mode )
    //"r" : 開啟檔案，供程式讀取文字內容
    f = fopen("input.txt", "r");

    for (int i = 0; i < TOTAL_TIME; i++)
    {
        int temp;
        // &temp為返回值
        // %d 代表 十進位數
        fscanf(f, "%d\n", &temp);
        studentPerTime[i] = temp;
    }
    fclose(f);

    //- initialize semaphores ----------------//
    // 初始化semaphore
    // 第二個參數是指定是否要讓其他的process共用semaphore
    // 第三個參數則是設定semaphore的初始值。
    // sem > 0
    sem_init(&chairMutex, 0, 1);
    sem_init(&timeMutex, 0, 1);
    sem_init(&availableStudentsSem, 0, 0);
    sem_init(&TA_sem, 0, 0);

    //- create TA thread -----------------//
    pthread_create(&TA_id, NULL, TA, NULL);

    //- create Student thread -----------------//
    for (int i = 0; i < TOTAL_TIME; i++)
    {
        timeFlag++;
        printf("time %d \n", timeFlag);

        if (studentPerTime[i] != 0)
        {
            allStudents++;
            printf("Student %d comes.\n", allStudents);
            // pthread_create(id's pointer, thread之屬性, 處理函數之pointer, 帶入函數之參數)
            pthread_create(&student_ids[i], NULL, Student, NULL);
        }
        else
        {
            printf("No student come.\n");
        }
        //將每次學生來的時間設為1毫秒
        usleep(1000);
    }

	//Make sure all thread has already completed
    //提示，可以使用pthread_join API

	//Please count and print out the average waiting time of every student who came into the Lab
    ///////////////////////////
	///<add your code here>////
	///////////////////////////

    return 0;
}

void *TA(void *temp)
{
    ///////////////////////////
	///<add your code here>////
    //(1) dealing with one student
    //(2) sleep
	///////////////////////////
}

void *Student(void *temp)
{
    ///////////////////////////
	///<add your code here>////
    //(1)waiting on the chair
    //(2)if all chair are full then student will leave
    //(3)being dealed by TA
	///////////////////////////
}