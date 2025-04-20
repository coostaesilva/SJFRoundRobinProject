#include "roundRobin.h"
#include <stdio.h>
#include "processes.h"

//Initialization of variables
int quantum = 0;

void createProcessesRoundRobin() {
    printf("\n-------------General Definition--------------\n");
    isInt(&numProcesses, "Enter how many processes will be created: ");
    initQueue();
    isInt(&quantum, "Enter the quantum value: ");
    setProcesses();
}

//Main scheduling function
void runQueue() {
    int finished = 0; //Iteration counter variable
    while (finished < numProcesses) { //Executes until the number of iterations equals the number of processes
        for (int i = 0; i < numProcesses; i++) { //Goes through each process in the queue
            if (processQueue[i].state == READY) { //Only executes if the process is READY
                /*If the initialization time is -1 (initial value of the process),
                assigns the clock time to the execution start time*/
                if (processQueue[i].initTime == -1) processQueue[i].initTime = clock;
                processQueue[i].state = RUNNING; //Changes the process state to RUNNING

                //Executes the process until interrupted by quantum time or finishes execution
                for (int j = 0; j < quantum && processQueue[i].execTime > 0; j++) {
                    printf("Process %s - State: %s - Clock Time: %d\n", processQueue[i].name,
                           processStateNames[processQueue[i].state], clock);
                    processQueue[i].execTime--; //Decreases the remaining execution time of the process by 1
                    clock++; //Increments the clock counter
                }

                //Checks if the process has finished execution
                if (processQueue[i].execTime == 0) {
                    processQueue[i].finishTime = clock; //Assigns the process finish time
                    processQueue[i].state = DONE; //Process is defined as FINISHED

                    //Calculation of process turnaround time (Finish Time - Creation Time)
                    processQueue[i].turnaroundTime = processQueue[i].finishTime - processQueue[i].creationTime;

                    /*Calculation of process wait time
                    (Finish Time - Creation Time - Execution Time)*/
                    processQueue[i].waitTime = processQueue[i].finishTime - processQueue[i].creationTime - processQueue[i].execTimeAux;

                    //Adds the process turnaround time to the global variable
                    turnaroundTimeMedian += processQueue[i].turnaroundTime;

                    //Adds the process wait time to the global variable
                    waitTimeMedian += processQueue[i].waitTime;

                    printf("Process %s - State: %s - Clock Time: %d\n", processQueue[i].name,
                           processStateNames[processQueue[i].state], clock);
                    printf("Turnaround Time: %d, Wait Time: %d\n",
                           processQueue[i].turnaroundTime, processQueue[i].waitTime);

                    finished++; //Increments the iteration counter

                    //Stores the processor usage time if it has finished executing all processes
                    if (finished == numProcesses) {
                        processorUseTime = processQueue[i].finishTime;
                    }

                    break; //Exits the loop before returning to READY state
                }

                //If the process has not yet finished execution, returns to the queue as READY
                processQueue[i].state = READY;
            }
        }
    }
}

void runQueueRoundRobin() {
    resetCTRW();
    clockStart();
    runQueue();

    calcTRW();

    printf("---------------------------------------\n");
    printf("Average Turnaround Time: %.2f\nAverage Wait Time: %.2f\nTotal Processor Time: %d\n\n",
           turnaroundTimeMedian, waitTimeMedian, processorUseTime);

    destroy();
}