#ifndef ROUNDROBIN_H
#define ROUNDROBIN_H

//Functions
void createProcessesRoundRobin(); //Creates the processes, initializes them and defines the quantum time

void runQueueRoundRobin();        //Starts the Round-Robin (Circular) scheduling simulation

//Variables
extern int quantum;

#endif //ROUNDROBIN_H