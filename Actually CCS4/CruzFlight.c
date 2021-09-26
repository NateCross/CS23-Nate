// Nate Cruz 2021

#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // getch()
#include <time.h> // For srand to initialize RNG
#include <stdbool.h>
#include <unistd.h> // For sleep

#define LANDING_TIME 4
#define TAKEOFF_TIME 6
#define LANDING_RATE 8
#define TAKEOFF_RATE 6
#define QUEUE_SIZE 6

typedef struct {
    int plane[QUEUE_SIZE], front, rear;
} QUEUE;

typedef struct {
    int firstRand, secondRand;
} RANDNUM;

RANDNUM generateNumber() {
    RANDNUM random;
    random.firstRand = (rand() % 501); // Generates a number from 0 - 500
    random.secondRand = (rand() % 501);

    return random;
}

QUEUE createCQueue() {
    QUEUE q;
    for (int i; i < QUEUE_SIZE; i++) {
        q.plane[i] = 0;
    }
    q.front = 0;
    q.rear = 0;
    return q;
}

bool isCEmpty(QUEUE q) {
    if (q.front == q.rear)
        return true;
    else
        return false;
}

bool isCFull(QUEUE q) { // Not needed?
    if (q.front == ((q.rear + 1) % QUEUE_SIZE))
        return true;
    else
        return false;
}

void enCQueue(QUEUE *q, int num) {
    q->plane[q->rear] = num;
    q->rear = (q->rear + 1) % QUEUE_SIZE;
}

int deCQueue(QUEUE *q) {
    int output = q->plane[q->front];
    q->front = (q->front + 1) % QUEUE_SIZE;
    return output;
}

void displayQueues(QUEUE land, QUEUE take) {
    printf("\n\tLanding:\n\n");
    for (int i = land.front; i != land.rear; i = ((i + 1) % QUEUE_SIZE))
        printf("\tFlight #%d\n", land.plane[i]);

    printf("\n\n");

    printf("\tTakeoff:\n\n");
    for (int i = take.front; i != take.rear; i = ((i + 1) % QUEUE_SIZE))
        printf("\tFlight #%d\n", take.plane[i]);
}

void airportOperation() {
    bool landingIsEmpty;
    int currentlyServing, waitTimer;
    RANDNUM rnd;

    QUEUE landing = createCQueue();
    QUEUE takeoff = createCQueue();

    rnd = generateNumber(); // Initializing landing queue with 2 elements
    enCQueue(&landing, rnd.firstRand);
    rnd = generateNumber();
    enCQueue(&landing, rnd.firstRand);

    while (true) {
        system("cls");
        landingIsEmpty = isCEmpty(landing);

        // Handling landing/takeoff at the runway
        if (!landingIsEmpty) { // Give priority to landing planes
            currentlyServing = deCQueue(&landing);
            waitTimer = LANDING_TIME;
            printf("\n\tFlight #%d is landing...\n", currentlyServing);
        }
        else {
            currentlyServing = deCQueue(&takeoff);
            waitTimer = TAKEOFF_TIME;
            printf("\n\tFlight #%d is taking off...\n", currentlyServing);
        }

        // Adding planes to the queues
        rnd = generateNumber();
        if (rnd.firstRand / 60 < LANDING_RATE && rnd.secondRand / 60 < TAKEOFF_RATE)
            enCQueue(&landing, rnd.firstRand);
        else
            enCQueue(&takeoff, rnd.secondRand);

        displayQueues(landing, takeoff);

        printf("\n\t");
        //printf("\n\tWait Timer: %d\n", waitTimer);
        for (int i = waitTimer * 60; i >= 0; i--) {
          printf("\r\tWait Timer: %d   ", i);
          sleep(1);
        }
        //sleep(waitTimer * 60); // The sleep is at the end to display the queues first

        printf("\n\n\tClearing runway...\n");
        sleep(5);
    }
}

int main() {
    srand(time(NULL)); // Initialize the random number generator every startup

    airportOperation();

    getch();
    return 0;
}
