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
	
	H->hSize = H->hSize + 1;    // Step 1. Increment array size by 1. This is because the i will be used quite a bit later
	i = H->hSize;               // Step 2. Make i equal to size. This i will be the marker for percolating the array upwards
	while(H->test[i/2].duration > task.duration) // Because this is a min heap, it checks if the value of the parent is greater than the child
	{
		H->test[i] = H->test[i/2]; // If it is greater, the parent goes to the child's position
		i /= 2; // i then moves upwards to the parent's position.
        // No need to swap between parent and child because the data will be stored if it is already at the right spot
        // That is, the parent is no longer greater than the child.
	}
	H->test[i] = task;
}

TASK deleteTask(PQUEUE *H)
{
	TASK min = H->test[1]; // Saves the head of the array as a temp, for returning
	H->test[1] = H->test[H->hSize]; // Moves the last node to the head
	H->hSize = H->hSize - 1; // Decrement size by 1
	*H = heapify(1, *H); // Calls heapify function on the head, which was just changed
	return min; // Return that temp we saved earlier
}

PQUEUE heapify(int i, PQUEUE H)
{
	int l, r, smaller;
	TASK temp;
	l = 2 * i;
	r = 2 * i + 1;
	
	if((l <= H.hSize) && (H.test[l].duration < H.test[i].duration)) // If left child exists and is smaller than parent, mark l as smaller
		smaller = l;
	else
		smaller = i; // Otherwise, it's the parent that's smaller
	
	if ((r <= H.hSize) && (H.test[r].duration < H.test[smaller].duration)) // Check if right child exists and is smaller than the value from before
		smaller = r;
	if(smaller != i) // If the smaller value is one of the child nodes, swap that one to the parent node
	{
		temp = H.test[i]; // start of swap
		H.test[i] = H.test[smaller];
		H.test[smaller] = temp; // end of swap
		H = heapify(smaller, H); // Call heapify again on the position of the child node that was swapped
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










