// simulates CPU job using priority. the shorter the time duration
// the higher the priority

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
	TASK test[P];
	int hSize;
}PQUEUE;

void insertTask(TASK, PQUEUE *);
TASK deleteTask(PQUEUE *);
PQUEUE heapify(int, PQUEUE);
PQUEUE heapifyMax(int, PQUEUE);
PQUEUE convertToMax(int, PQUEUE);
void correctConvertToMax(PQUEUE *);
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
    // H = convertToMax(1, H);
    correctConvertToMax(&H);
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

// Taken from https://www.geeksforgeeks.org/convert-min-heap-to-max-heap/
void correctConvertToMax(PQUEUE *H) {
    for (int i = (H->hSize - 1) / 2; i > 0; i--)
        *H = heapifyMax(i, *H);
}

void insertTask(TASK task, PQUEUE *H)
{
	unsigned int i;
	
	H->hSize = H->hSize + 1;
	i = H->hSize;
	while(H->test[i/2].duration > task.duration)
	{
		H->test[i] = H->test[i/2];
		i /= 2;
	}
	H->test[i] = task;
}

TASK deleteTask(PQUEUE *H)
{
	TASK min = H->test[1];
	H->test[1] = H->test[H->hSize];
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
	
	if((l <= H.hSize) && (H.test[l].duration < H.test[i].duration))
		smaller = l;
	else
		smaller = i;
	
	if ((r <= H.hSize) && (H.test[r].duration < H.test[smaller].duration))
		smaller = r;
	if(smaller != i)
	{
		temp = H.test[i]; // start of swap
		H.test[i] = H.test[smaller];
		H.test[smaller] = temp; // end of swap
		H = heapify(smaller, H);
	}
	return H;
}

PQUEUE heapifyMax(int i, PQUEUE H)
{
	int l, r, larger;
	TASK temp;
	l = 2 * i;
	r = 2 * i + 1;
	
	if((l <= H.hSize) && (H.test[l].duration > H.test[i].duration))
		larger = l;
	else
		larger = i;
	
	if ((r <= H.hSize) && (H.test[r].duration > H.test[larger].duration))
		larger = r;
	if(larger != i)
	{
		temp = H.test[i]; // start of swap
		H.test[i] = H.test[larger];
		H.test[larger] = temp; // end of swap
		H = heapifyMax(larger, H);
	}
	return H;
}

PQUEUE convertToMax(int i, PQUEUE H) {
    int l = 2 * i;
    int r = 2 * i + 1;
    int larger = i;
    TASK temp;
    printf("convertToMax int i: %d\n", i);
    for (int j = 1; j <= H.hSize; j++)
        printf("H[%d] = %d, ", j, H.test[j].duration);
    printf("\n");

    if (l <= H.hSize) {
        H = convertToMax(l, H);
        if (H.test[l].duration > H.test[i].duration)
            larger = l;
    }
    
    if (r <= H.hSize) {
        H = convertToMax(r, H);
        if (H.test[r].duration > H.test[larger].duration)
            larger = r;
    }
    
	if (larger != i)
	{
		temp = H.test[i]; // start of swap
		H.test[i] = H.test[larger];
		H.test[larger] = temp; // end of swap
        H = convertToMax(larger, H);
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
		printf("\n\n\tTask No: %d",H.test[i].taskNo);
		printf("\n\tTask Name: %s",H.test[i].taskName);
		printf("\n\tTask Duration: %d",H.test[i].duration);
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
		H.test[i].taskNo = 0;
		strcpy(H.test[i].taskName,"");
		H.test[i].duration = 0;
	}
	H.hSize = 0;
	return H;
}










