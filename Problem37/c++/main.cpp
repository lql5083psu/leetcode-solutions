
#include <assert.h>
#include <vector>
#include <stdio.h>
#include <set>
#include <map>
#include <list>
#include "solution.h"
char input[9][9]={
{'5','3','.', '.', '7', '.', '.', '.', '.'},
{'6','.','.', '1', '9', '5', '.', '.', '.'},
{'.','9','8', '.', '.', '.', '.', '6', '.'},

{'8','.','.', '.', '6', '.', '.', '.', '3'},
{'4','.','.', '8', '.', '3', '.', '.', '1'},
{'7','.','.', '.', '2', '.', '.', '.', '6'},

{'.','6','.', '.', '.', '.', '2', '8', '.'},
{'.','.','.', '4', '1', '9', '.', '.', '5'},
{'.','.','.', '.', '8', '.', '.', '7', '9'}};



using namespace std;
int main(int argc, char* argv[])
{
  vector<vector<char> > board(9);
  for(int i=0;i<9;i++){
    board[i].resize(9);
    for(int j=0;j<9;j++){
       board[i][j] =  input[i][j];
    }
  }
  Solution s;
  s.solveSudoku( board);
  return 0;
}


