#include "auxiliary.h"
#include <stdio.h>
#include <stdbool.h>
#include "processes.h"

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
};

void formatString(char *string) {
    const size_t len = strlen(string); //String length
    /*Checks if the last character of the string is a newline
    and, if so, replaces it with a null character to end the string*/
    if (len > 0 && string[len - 1] == '\n') {
        string[len - 1] = '\0';
    }
}

void isInt(int *num, char *string) {
    while (true) {
        //Requests input of a value until it is an integer
        printf("%s", string);
        if (scanf("%d", num) != 1) {
            printf("Invalid Value! Enter an integer number!\n");
            clearBuffer();
        } else {
            clearBuffer();
            break;
        }
    }
}

//Swaps processes in the queue
void swap(Process *a, Process *b) {
    Process aux = *a; //Creates an auxiliary variable and copies the content of 'a' to it
    *a = *b;          //Copies the content of 'b' to 'a'
    *b = aux;         //Copies the content saved in 'aux' (original 'a') to 'b'
}

//Array partitioning
int partition(int low, int high) {
    int pivot = processQueue[high].execTime; //Chooses the execution time of the last process as pivot
    int i = low; //Initializes the index of the smaller element
    for (int j = low; j < high; j++) {
        //Traverses from the beginning to before the pivot
        if (processQueue[j].execTime <= pivot) {
            //If the current process time is less than or equal to the pivot
            swap(&processQueue[i], &processQueue[j]); //Swaps the current process with the one at position 'i'
            i++; //Advances the 'i' index
        }
    }
    swap(&processQueue[i], &processQueue[high]); //Places the pivot in the correct position
    return i; //Returns the pivot index
}

//Main recursive function of quicksort
void quickSort(int low, int high) {
    if (low < high) {
        //Checks if there is more than one element to sort
        int partition_index = partition(low, high); //Partitions the array and gets the pivot position
        quickSort(low, partition_index - 1);        //Sorts the left Sub-Array
        quickSort(partition_index + 1, high);       //Sorts the right Sub-Array
    }
}