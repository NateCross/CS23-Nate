// simulates CPU job using priority. the shorter the time duration
// the higher the priority
// TODO: Make it decrement to fix it

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>
#include <conio.h>

#define S 10 // size of the task name
#define P 6 // size of the queue
#define F while(getchar() != '\n')

typedef struct
{
	int taskNo;
	char taskName[S];
	int duration; // in seconds (basis for prioritizing)
}TASK;

typedef struct
{
	TASK pQueue[P];
	int hSize;
}PQUEUE;

void insertTask(TASK, PQUEUE *);
TASK deleteTask(PQUEUE *);
PQUEUE heapify(int, PQUEUE);
bool isPFull(int);
bool isPEmpty(int);
void displayPriorty_Queue(PQUEUE);
TASK inputTask(void);
PQUEUE createPQueue(void);

int main(void)
{
	bool empty, full;
	TASK task;
	PQUEUE H;
	
	H = createPQueue();
	full = isPFull(H.hSize);
	while(!full)
	{
		task = inputTask();
		insertTask(task,&H);
		full = isPFull(H.hSize);
	}
	displayPriorty_Queue(H);
	empty = isPEmpty(H.hSize);
	while(!empty)
	{
		task = deleteTask(&H);
		printf("\n\n\tProcessing Task: %s",task.taskName);
		sleep(task.duration);
		empty = isPEmpty(H.hSize);
	}

    printf("\n\n\tFinished with tasks.\n\tPress any key to exit.");

    _getch();
	return 0;
}

void insertTask(TASK task, PQUEUE *H)
{
	unsigned int i;
	
	H->hSize = H->hSize + 1;
	i = H->hSize;
	while(H->pQueue[i/2].duration > task.duration)
	{
		H->pQueue[i] = H->pQueue[i/2];
		i /= 2;
	}
	H->pQueue[i] = task;
}

TASK deleteTask(PQUEUE *H)
{
	TASK min = H->pQueue[1];
	H->pQueue[1] = H->pQueue[H->hSize];
	H->hSize = H->hSize - 1;
	*H = heapify(1, *H);
	return min;
}

PQUEUE heapify(int i, PQUEUE H)
{
	int l, r, smaller;
	TASK temp;
	l = 2 * i;
	r = 2 * i + 1;
	
	if((l <= H.hSize) && (H.pQueue[l].duration < H.pQueue[i].duration))
		smaller = l;
	else
		smaller = i;
	
	if ((r <= H.hSize) && (H.pQueue[r].duration < H.pQueue[smaller].duration))
		smaller = r;
	if(smaller != i)
	{
		temp = H.pQueue[i]; // start of swap
		H.pQueue[i] = H.pQueue[smaller];
		H.pQueue[smaller] = temp; // end of swap
		H = heapify(smaller, H);
	}
	return H;
}

bool isPFull(int size)
{
	bool full = false;
	if (size == (P - 1))
		 full = true;
	return full;
}

bool isPEmpty(int size)
{
	bool empty = false;
	
	if (size == 0)
		empty = true;
	return empty;
}

void displayPriorty_Queue(PQUEUE H)
{
	int i;
	
	for (i = 1; i < P; i++)
	{
		printf("\n\n\tTask No: %d",H.pQueue[i].taskNo);
		printf("\n\tTask Name: %s",H.pQueue[i].taskName);
		printf("\n\tTask Duration: %d",H.pQueue[i].duration);
		printf("\n\n");
	}
	_getch();
}

TASK inputTask(void)
{
	TASK t;

	printf("\n\n\tTask No: ");
	scanf("%d",&t.taskNo);
		F;
	printf("\n\tTask Name: ");
	gets(t.taskName);
	printf("\n\tTask Duration: ");
	scanf("%d",&t.duration);
	return t;
}

PQUEUE createPQueue(void)
{
	int i;
	PQUEUE H;
	
	for(i = 0; i < P; i++)
	{
		H.pQueue[i].taskNo = 0;
		strcpy(H.pQueue[i].taskName,"");
		H.pQueue[i].duration = 0;
	}
	H.hSize = 0;
	return H;
}










