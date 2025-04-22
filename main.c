#include <stdio.h>
#include "sjf.h"
#include "roundRobin.h"
#include "auxiliary.h"

//Enum for each menu option
enum {
    OP_NOT_SELECTED = 0,
    OP_SJF,
    OP_ROUNDROBIN,
    OP_QUIT
};

int menu();

int main(void) {
    int option = OP_NOT_SELECTED;
    while (option != OP_QUIT) {
        option = menu(); //Gets the return value from the menu function according to the enum
        switch (option) {
            case OP_SJF:
                createProcessesSJF();
                runQueueSJF();
                break;
            case OP_ROUNDROBIN:
                createProcessesRoundRobin();
                runQueueRoundRobin();
                break;
            case OP_QUIT:
                printf("Quitting...");
                break;
            default:
                printf("Invalid Option!\n");
        }
    }
}

int menu() {
    int op = OP_NOT_SELECTED; //Initializes the temporary variable 'op' as not selected (enum)
    printf("---------------Menu----------------\n");
    printf("%d. SJF Simulation (Non-preemptive)\n", OP_SJF);
    printf("%d. Round-Robin Simulation\n", OP_ROUNDROBIN);
    printf("%d. Quit\n", OP_QUIT);
    isInt(&op, "Select an option: ");
    return op;
}