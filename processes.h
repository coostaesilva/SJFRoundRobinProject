#ifndef PROCESSES_H
#define PROCESSES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auxiliary.h"

//Enum to define states assigned to each number
typedef enum {
    BLOCKED = 0, //State = Blocked
    READY,       //State = Ready
    RUNNING,     //State = Running
    DONE         //State = Finished
} processState;

//Array to define process state messages equivalent to processState enum values
extern const char *processStateNames[];

//Process struct
typedef struct {
    char name[50];       //Process name
    int execTime;        //Process execution time
    int execTimeAux;     //Stores the original value of the process execution time
    int creationTime;    //Process creation time
    int initTime;        //Process execution start time
    int finishTime;      //Process finish time
    int turnaroundTime;  //Process turnaround time
    int waitTime;        //Process wait time
    processState state;  //Process state
} Process;

//Variables
extern Process *processQueue;      //Process queue
extern int numProcesses;           //Number of processes
extern int clock;                  //CPU clock
extern float turnaroundTimeMedian; //Average turnaround time
extern float waitTimeMedian;       //Average wait time
extern int processorUseTime;       //Total CPU usage time

//Queue functions
void initQueue(); /*Initializes the process queue, allocating memory for the array of structs and
                    defining default values for 'state' and 'initTime' fields.*/
void destroy();   //Frees the memory space of the queue's struct array

//Process functions
void setProcesses(); //Defines the values of the fields for each item in the process struct array

void resetCTRW();    /*Resets the values of clock, average turnaround time,
                       and average wait time variables to 0*/
void calcTRW();      //Calculates the average turnaround and wait time

void clockStart();   //Starts the clock count for cases where creation time is greater than 0

#endif //PROCESSES_H