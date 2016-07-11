#include "solution.h"

void Solution::display( std::vector<vector<char> > input)
{

   // Display input
   for(int i=0;i<9;i++){
     for(int j=0;j<9;j++){
        printf(" %c", input[i][j]);
     }
     printf("\n");
   }
   printf("\n\n");


}

void Solution::solveSudoku(vector<vector<char>>& board) 
{
   
   Candidates candidates[9][9];
   set<char> original;
   for(char c='1'; c<='9'; c++) original.insert(c);

   for(int i=0;i<9;i++)  
     for(int j=0;j<9;j++) 
       candidates[i][j] = original;
   // get candidates
   for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){
      const char& c = board[i][j];
      if ( c=='.') continue;
      candidates[i][j].clear();
      for(int k=0;k<9;k++){
         candidates[i][k].erase(c);
         candidates[k][j].erase(c);
      }
    }
   }

   Solve( board, candidates,0); 
   display(board);
}

bool Solution::isValid(vector<vector<char> >board, int i, int j)
{
     bool result=true;
     char tmp=board[i][j];
     board[i][j]='D';
     for(int k=0;k<9;k++){
       if( board[i][k] == tmp) result=false;
     }
     for(int k=0;k<9;k++){
       if( board[k][j] == tmp) result=false;
     }
     for(int k=0;k<9;k++){
       if( board[(i/3)*3 +  k/3][ (j/3)*3 + k%3] == tmp) result=false;
     }

     board[i][j]=tmp;
     return result;
}

int Solution::Solve( vector<vector<char> >& board, Candidates candidates[9][9], int IJ)
{
  int i=IJ/9;
  int j=IJ%9;
  if( IJ>=81) return true;
  if(candidates[i][j].empty()){
    return Solve(board,candidates, IJ+1);
  }
  for(auto& it:candidates[i][j]){
     board[i][j] = it;
     if( isValid(board,i,j)==false){
     }
     else{
       if( Solve( board, candidates, IJ+1)){
         return true;
       }
     }
     board[i][j]='.';
  }
  return false;
}


