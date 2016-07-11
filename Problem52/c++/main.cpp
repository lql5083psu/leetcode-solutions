#include "solution.h"
#include <stdlib.h>
#include <stdio.h>
int main(int argc, char* argv[])
{
  if( argc < 2) return 0;
  int N=atoi(argv[1]);
  Solution s;
  int nSolution=s.totalNQueens(N);
  printf("Solution: %d\n", nSolution);
  return 0;
}
