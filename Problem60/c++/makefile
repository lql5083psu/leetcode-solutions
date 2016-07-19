default: all

EXE=run.exe

profiling: CPPFLAGS=-Wall -pg -O0 -g
profiling: LDFLAGS=-pg
profiling: EXE:=run_profiling.exe
profiling: CPPFLAGS+=--std=c++0x

all: CPPFLAGS=-O3 

all: CPPFLAGS+=--std=c++0x
all:
	g++ -c main.cpp $(CPPFLAGS)
	g++ -o $(EXE) main.o  $(LDFLAGS)
#	./run.exe


