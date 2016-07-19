#!/bin/bash
./run_profiling.exe 7
gprof ./run_profiling.exe gmon.out > analysis.txt
