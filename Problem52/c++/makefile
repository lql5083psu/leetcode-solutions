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
	g++ -c solution.cpp $(CPPFLAGS)
	g++ -o $(EXE) main.o solution.o $(LDFLAGS)
#	./run.exe

profiling:
	g++ -c main.cpp $(CPPFLAGS)
	g++ -c solution.cpp $(CPPFLAGS)
	g++ -o $(EXE) main.o solution.o $(LDFLAGS)

