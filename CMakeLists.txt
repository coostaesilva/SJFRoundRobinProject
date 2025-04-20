cmake_minimum_required(VERSION VERSION 3.31)
project(projetoSO2804 C)

set(CMAKE_C_STANDARD 23)

add_executable(projetoSO2804
        sjf.c
        sjf.h
        roundRobin.c
        roundRobin.h
        processes.c
        processes.h
        auxiliary.c
        auxiliary.h
        main.c)
