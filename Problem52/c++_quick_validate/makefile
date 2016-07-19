default: all

EXE=run.exe

profiling: all
profiling: CPPFLAGS=-Wall -pg -O0 -g
profiling: LDFLAGS=-pg
profiling: EXE:=run_profiling.exe


all: CPPFLAGS=-O3 -Wall

all:
	g++ -c main.cpp $(CPPFLAGS) --std=c++0x
	g++ -c solution.cpp $(CPPFLAGS) --std=c++0x
	g++ -o $(EXE) main.o solution.o $(LDFLAGS)
#	./run.exe


