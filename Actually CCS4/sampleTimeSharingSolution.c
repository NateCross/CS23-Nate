#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#define SIZE 100
#define QUEUEMAX 6

// Nate Cruz 2021

typedef struct {
    char processName[QUEUEMAX][SIZE]; // String of arrays to hold process name
    int processTime[QUEUEMAX]; // in seconds
    int front, rear;
} QUEUE;

QUEUE createCQueue () {
    QUEUE q;
    q.front = 0;
    q.rear = 0;
    return q;
}

void enQueueC (QUEUE *q, char *Name, int Time) {
    strcpy(q -> processName[q -> rear], Name);
    // q -> processName[q -> rear] = Name;
    q -> processTime[q -> rear] = Time;
    q -> rear = (q -> rear + 1) % QUEUEMAX;
    return;
}

void deQueueC (QUEUE *q, char *Name, int *Seconds) {
    strcpy(Name, q -> processName[q -> front]);
    //Name = q -> processName[q -> front];
    *Seconds = q -> processTime[q -> front];
    q -> front = (q -> front + 1) % QUEUEMAX;
    return; // Can adjust to make it return a thing
}

bool IsNotEmpty (QUEUE q) {
    if (q.front == q.rear)
        return false;
    else
        return true;
}

bool IsFull (QUEUE q) {
    if (q.front == q.rear + 1)
        return true;
    else
        return false;
}

void printQueue (QUEUE que) {
    for (int i = que.front; i < que.rear; i++) {
        printf("%s - %d sec.\n", que.processName[i], que.processTime[i]);
    }
    printf("Finished printing.\n");
}

void inputProcess (char *Name, int *Seconds) {
    fflush(stdin);

    printf("Input Process Name: ");
    gets(Name);
    fflush(stdin);

    while (true) { // TODO: Think of a better way to handle errors like this
        printf("Input Process Duration in seconds (max 10): ");
        scanf("%d", &(*Seconds));
        fflush(stdin);

        if (*Seconds > 10) {
            printf("Setting to the maximum of 10 seconds...\n");
            *Seconds = 10;
            getch();
            break;
        }
        else if (*Seconds <= 0) {
            printf("Error: Invalid duration. Please try again.\n\n");
            getch();
        }
        else
            break;
    }

    return;
}

void doProcess (QUEUE q) {
    char NameInput[SIZE], NameDequeue[SIZE];
    int TimeInput, TimeDequeue, elapsed;
    time_t start, end;
    q = createCQueue();

    for (int i = 0; i < QUEUEMAX - 1; i++) {
        system("cls");
        printf("Process %d\n", i + 1);
        inputProcess(NameInput, &TimeInput);
        enQueueC(&q, NameInput, TimeInput);

        /* --DEBUG--
        printf("NameInput: %s\nTimeInput: %d\n", NameInput, TimeInput);
        printf("q.processName: %s\nq.processTime: %d\n", q.processName[i], q.processTime[i]);
        printf("Front: %d\nRear: %d\n", q.front, q.rear);
        getch();
        */
    }
    system("cls");

    /* --DEBUG--
    printf("Front: %d\nRear: %d\n", q.front, q.rear);
    getch();
    */

    printQueue(q);
    printf("Enter anything to continue.\n");
    getch();

    while (IsNotEmpty(q)) {
        system("cls");
        strcpy(NameDequeue, " ");
        TimeDequeue = 0;

        deQueueC (&q, NameDequeue, &TimeInput);
        time(&start);

        printf("\tProcess\tTime\n");
        do {
            time(&end);
            elapsed = difftime(end, start);

            printf("\r\t%s\t%d", NameDequeue, elapsed);
            /*
            printf("\rProcess: %s", NameDequeue);
            printf("\n");
            printf("\rTime: %d", elapsed);
            printf("\n");
            */
        } while (elapsed < TimeInput);
        printf("\n\n\tProcess finished. Enter anything to continue.\n");
        getch();
    }
    system("cls");
    printf("All processes finished. Enter anything to continue.\n");
    getch();

}

int main() {
    /*
    time_t start, end;
    int elapsed;
    time(&start);
    */

    QUEUE timeShare;
    doProcess(timeShare);
    /*
    timeShare = createCQueue();
    enQueueC(&timeShare, "Peepee", 3);
    // printf("F%d R%d\n%s - %d seconds\n", timeShare.front, timeShare.rear, timeShare.processName[0], timeShare.processTime[0]);
    enQueueC(&timeShare, "Poopoo", 5);
    // printf("F%d R%d\n%s - %d seconds\n", timeShare.front, timeShare.rear, timeShare.processName[timeShare.rear-1], timeShare.processTime[timeShare.rear-1]);
    enQueueC(&timeShare, "Lmao", 7);

    printQueue(timeShare);

    printf("\n");

    deQueueC(&timeShare);

    printQueue(timeShare);

    printf("\n");

    do {
        time(&end);

        elapsed = difftime(end, start);

        printf("\rTime: %d", elapsed);
    } while (elapsed < 10);
    */

    return 0;
}
