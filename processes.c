#include "processes.h"

//Initialization of variables
Process *processQueue = NULL; //Queue (pointer without address)
int numProcesses = 0;
int processorUseTime = 0;
int clock = 0;
float turnaroundTimeMedian = 0;
float waitTimeMedian = 0;
const char *processStateNames[] = {"Blocked", "Ready", "Running", "Finished"};

//Functions
void initQueue() {
    processQueue = malloc(numProcesses * sizeof(Process));
    if (!processQueue) {
        //Memory allocation check
        printf("Error allocating memory!");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < numProcesses; i++) {
        //Initialize processes in waiting state (BLOCKED)
        processQueue[i].state = BLOCKED;
        /*Initialization time of processes is initially defined as
        -1 for verification during execution of scheduling algorithms*/
        processQueue[i].initTime = -1;
    }
}

void destroy() {
    free(processQueue);
    processQueue = NULL;
}

void setProcesses() {
    int positionInQueueAux = 0;
    int creationTimeAux = 0;
    //Definition of creation time for all processes
    isInt(&creationTimeAux, "Enter the creation time of processes: ");
    //Loop for individual process definition
    for (int i = 0; i < numProcesses; i++) {
        printf("\n---------Process Definition----------\n");
        char nameAux[50];
        //Definition of process name
        printf("Enter the process name: ");
        fgets(nameAux, sizeof(nameAux),stdin);
        formatString(nameAux);
        strcpy(processQueue[i].name, nameAux);
        //Definition of execution time
        isInt(&processQueue[i].execTime, "Enter the execution time of the process: ");
        processQueue[i].execTimeAux = processQueue[i].execTime;
        //Definition of standardized process creation time
        processQueue[i].creationTime = creationTimeAux;
        //Process state changes from BLOCKED to READY
        processQueue[i].state = READY;
        //Increments the queue position variable by 1 for the next process
        positionInQueueAux++;
        printf("Process defined.\n");
    }

    printf("---------------------------------------\n");
}

void resetCTRW() {
    clock = 0;
    turnaroundTimeMedian = 0.0;
    waitTimeMedian = 0.0;
}

void calcTRW() {
    turnaroundTimeMedian /= numProcesses;
    waitTimeMedian /= numProcesses;
}

void clockStart() {
    while (clock != processQueue[0].creationTime) {
        printf("Clock Time: %d\n", clock);
        clock++;
    }
}