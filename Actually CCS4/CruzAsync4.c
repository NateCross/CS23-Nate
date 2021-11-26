// Nathan Angelo B. Cruz

// Simulates CPU job using priority.
// This is the max queue version, edited such that
// it processes the highest duration task first over the lesser ones

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

// In changing this to max, the comparison in the while was flipped
// from '>' to '<'. But this causes a problem with pQueue index 1,
// because [i/2] = [0], which is less than task
// and thus produces unexpected behavior.
// To avoid this, an exception was placed if i == 1 to make the program
// behave as normal.
void insertTask(TASK task, PQUEUE *H)
{
	unsigned int i;
	
	H->hSize = H->hSize + 1;
	i = H->hSize;
	while(H->pQueue[i/2].duration < task.duration && i != 1)
	{
		H->pQueue[i] = H->pQueue[i/2];
		i /= 2;
	}
	H->pQueue[i] = task;
}

TASK deleteTask(PQUEUE *H)
{
	TASK max = H->pQueue[1];
	H->pQueue[1] = H->pQueue[H->hSize];
	H->hSize = H->hSize - 1;
	*H = heapify(1, *H);
	return max;
}

// To change to max heap, the duration now compares
// if the child is greater, rather than lesser.
PQUEUE heapify(int i, PQUEUE H)
{
	int l, r, larger;
	TASK temp;
	l = 2 * i;
	r = 2 * i + 1;
	
	if((l <= H.hSize) && (H.pQueue[l].duration > H.pQueue[i].duration))
		larger = l;
	else
		larger = i;
	
	if ((r <= H.hSize) && (H.pQueue[r].duration > H.pQueue[larger].duration))
		larger = r;
	if(larger != i)
	{
		temp = H.pQueue[i]; // start of swap
		H.pQueue[i] = H.pQueue[larger];
		H.pQueue[larger] = temp; // end of swap
		H = heapify(larger, H);
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










