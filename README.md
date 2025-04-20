# Process Scheduling Simulation Algorithm

## Non-Preemptive SJF and Round-Robin 
![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![Static Badge](https://img.shields.io/badge/Academic-In%20development-orange?style=for-the-badge&labelColor=000066)
![GitHub](https://img.shields.io/badge/License-MIT-green)
***

## Index
- [Description](#description)
- [Features](#features)
- [Project Structure](#project-structure)
- [How to Run](#how-to-run)
  - [Using GCC](#using-gcc)
  - [Using MinGW](#using-mingw)
  - [Using Make](#using-make)
- [Usage](#usage)
  - [SJF](#sjf)
  - [Round-Robin](#round-robin)
- [Wait...](#wait)
- [Future...](#future)

## Description
***
This small academic project developed in C simulates how a CPU schedules
processes according to two different policies: Shortest Job First (non-preemptive)
and Round-Robin. It allows the user to see how each policy deals with the process
queue in real time.

## Features
***
* Non-preemptive SJF policy simulation
    * Custom name, execution time and creation time (all processes have the same
creation time).
* Round-Robin policy simulation
    * Custom name, execution time, creation time (all processes have the same
creation time) and quantum.
* Real time visualization of the simulation.
* Calculation of turn-around, wait and total CPU usage times.

## Project Structure
***
The algorithm is divided into multiple source and header files for a decent level of
modularization and code etiquette. Here's a quick summary of what each file is responsible
for:
* `auxiliary.c / .h`: Contains the useful functions used by the algorithm that are not directly
related to the processes and the scheduling policies.
* `processes.c / .h`: Contains the functions and variables used by the algorithm that are directly
related to the processes.
* `sjf.c / .h`: Contains the functions and variables used by the algorithm that are directly
related to the non-preemptive SJF policy simulation.
* `roundRobin.c / .h`: Contains the functions and variables used by the algorithm that are directly
related to the Round-Robin policy simulation.

## How to Run
***
This project can be compiled and run on different operating systems using various development environments. Choose
the one according to your preferences:
### Using GCC
***
### Compile the source files
```bash
gcc main.c processes.c sjf.c roundRobin.c auxiliary.c -o scheduler
```
### Run
```bash
./scheduler
```

### Using MinGW
***
### Compile the source files
```bash
gcc main.c processes.c sjf.c roundRobin.c auxiliary.c -o scheduler
```
### Run
```bash
scheduler.exe
```

### Using Make
***
### Create the Makefile
```makefile
CC = gcc
CFLAGS = -Wall -Wextra
SOURCES = main.c processes.c sjf.c roundRobin.c auxiliary.c
OBJECTS = $(SOURCES:.c=.o)
TARGET = simulador

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)
```
### Compile and run
```bash
make
./scheduler
```

## Usage
***
The algorithm has a simple text-based menu, where the user can choose which algorithm to simulate
by entering one of the numbers shown with their respective functions.\
Here's an example of the menu:
```
    ---------------Menu----------------
    1. SJF Simulation (Non-preemptive)
    2. Round-Robin Simulation
    3. Quit 
```
### SJF
***
By selecting this option, the user will be prompted four times:
* To insert the number of processes to be created.
* To insert the time of creation of all the processes
* To set the following fields in each created process:
    * Its name
    * Its execution time

The algorithm will then run the queue and show each process' state and the clock time every tick.
Whenever a process finishes executing, its turn-around and wait times will be displayed.
When the whole queue is finished, the average turn-around and wait times will be displayed.
After the simulation has finished, the user is once again prompted with the main menu.

### Round-Robin
***
By selecting this option, the user will be prompted five times:
* To insert the number of processes to be created.
* To insert the value of quantum.
* To insert the time of creation of all the processes
* To set the following fields in each created process:
    * Its name
    * Its execution time

Just like the SJF option, the algorithm will then run the queue and show each process' state and
the clock time every tick. Whenever a process finishes executing, its turn-around and wait times
will be displayed. When the whole queue is finished, the average turn-around and wait times will
be displayed. After the simulation has finished, the user is once again prompted with the main menu.

## Wait...
***
I know what you're probably thinking: Why do all processes have the same creation time? Why only the
non-preemptive version of SJF? Well, the answer to both questions is: this project was developed according
to the prerequisites present in the assignment for which this code was made.\
If you're curious, here are the prerequisites:
> _Based_ on the scheduling policies used by operational systems, develop an algorithm using any programming
> language to simulate the following:
> * Round-Robin: (preemptive, Quantum, same creation time)
> * SJF (non-preemptive, same creation time)

## Future...
***
I plan to update this project in future versions to add the following features:
* Preemptive SJF policy simulation
* Custom creation times for each process
* A better real-time visualization of the simulation (probably a Gantt's graphic)

## Authors: João Vitor Costa e Silva
## Note
***
This project was developed for academic and didactic purposes only.