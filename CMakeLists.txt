cmake_minimum_required(VERSION 3.20)
project(sjfRoundRobin C)

set(CMAKE_C_STANDARD 11)

add_executable(sjfRoundRobin
        sjf.c
        sjf.h
        roundRobin.c
        roundRobin.h
        processes.c
        processes.h
        auxiliary.c
        auxiliary.h
        main.c)
