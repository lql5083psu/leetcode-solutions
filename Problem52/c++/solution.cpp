#include "solution.h"
#include <stdio.h>
#include <set>
#include <math.h>
#include <stdlib.h>
int abs(int i){
  if( i<0) return -i;
  return i;
}
int Solution::totalNQueens(int n)
{
  nSolution=0;
  std::vector<int> input(n,-1);
  bool result=Helper(0,input);
  return nSolution;
}
bool Solution::Helper(int n, std::vector<int>& v)
{
  int N=v.size(); 
  if( n>=N) {
    nSolution++;
    printf("Find a result: ");
    for(int i=0;i<N;i++)printf("%d ", v[i]);
    printf("\n");
    return true;
  }
  // play with position N;
  for(int candidate=0; candidate <N;candidate++){
    v[n] = candidate;
    if( ! validate(v)) { v[n]=-1; continue;}
    if( Helper( n+1, v) ){
     // return true;
    }
    else{
      for(int k=n;k<N;k++) v[k]=-1;
    }
  }
  return false;
}

bool Solution::validate( std::vector<int>& input)
{
  bool debug=false;
  if(getenv("DEBUG")) debug=true;
  std::set<int> tmp;
  int N=input.size();
  if(debug){
    printf("validate: ");
    for(int ii=0;ii<N;ii++) printf("%d ", input[ii]);
  }

  for(int i=0;i<N;i++){
    int thisI=input[i];
    if(thisI <0) {
      if(debug)printf("\n");
      return true;
    }
    if(tmp.find(input[i]) != tmp.end()){
      if(debug)printf("Invalidated\n");
      return false;
    }
    tmp.insert(input[i]);
  }

  for(int i=0;i<N;i++){
    if( input[i] <0 ) break;
    for(int j=i+1;j<N;j++){
        if( input[j] <0)  break;
        if( abs(input[i] - input[j]) == (j-i) ) {
          if(debug)printf("invalidated: \n");
          return false;
        }
    }
  }
  if(debug)printf("\n");
  return true;
}

