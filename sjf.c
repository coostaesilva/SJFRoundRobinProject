#include "sjf.h"
#include <stdio.h>
#include "processes.h"
#include "auxiliary.h"

void createProcessesSJF() {
    printf("\n-------------General Definition--------------\n");
    isInt(&numProcesses, "Enter how many processes will be created: ");
    initQueue();
    setProcesses();
}

void runQueueSJF() {
    resetCTRW();
    quickSort(0, numProcesses - 1); //Sorts the queue according to the execution time of each process

    clockStart();

    for (int i = 0; i < numProcesses; i++) { //Goes through each process in the queue
        processQueue[i].state = RUNNING; //Changes the process state to RUNNING
        processQueue[i].initTime = clock; //Assigns clock time to the process start time

        //Executes the process until it finishes execution
        while (processQueue[i].execTime > 0) {
            printf("Process %s - State: %s - Clock Time: %d\n", processQueue[i].name,
                   processStateNames[processQueue[i].state], clock);
            processQueue[i].execTime--; //Decreases the remaining execution time of the process by 1
            clock++; //Increments the clock counter
        }

        processQueue[i].finishTime = clock; //Assigns clock time to the process finish time
        processQueue[i].state = DONE; //Process is defined as FINISHED
        printf("Process %s - State: %s - Clock Time: %d\n", processQueue[i].name,
               processStateNames[processQueue[i].state], clock);

        //Calculation of process turnaround time (Finish Time - Creation Time)
        processQueue[i].turnaroundTime = processQueue[i].finishTime - processQueue[i].creationTime;

        //Calculation of process wait time (Initialization Time - Creation Time)
        processQueue[i].waitTime = processQueue[i].initTime - processQueue[i].creationTime;

        //Adds the process turnaround time to the global variable
        turnaroundTimeMedian += processQueue[i].turnaroundTime;

        //Adds the process wait time to the global variable
        waitTimeMedian += processQueue[i].waitTime;

        printf("Turnaround Time: %d, Wait Time: %d\n", processQueue[i].turnaroundTime, processQueue[i].waitTime);
    }

    //Stores the processor usage time
    processorUseTime = processQueue[numProcesses-1].finishTime;

    calcTRW();

    printf("---------------------------------------\n");
    printf("Average Turnaround Time: %.2f\nAverage Wait Time: %.2f\nTotal Processor Time: %d\n\n",
           turnaroundTimeMedian, waitTimeMedian, processorUseTime);

    destroy();
}