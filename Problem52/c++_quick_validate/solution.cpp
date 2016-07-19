/* 
   test quick validate: Speed up the validation function by keep a member set to keep the numbers already used. 
*/

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
	numbers.clear();;
  nSolution=0;
  std::vector<int> input(n,-1);
  Helper(0,input);
  return nSolution;
}
bool Solution::Helper(int n, std::vector<int>& v)
{
#ifdef DEBUG	
	bool debug=false;
	if(getenv("DEBUG")) debug=true;
#endif	
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
	
	bool hit= (numbers.find(candidate) != numbers.end()) ;
#ifdef DEBUG	
	if(debug && hit){
		printf("Validate: ");
		for(auto& ii:v) printf(" %d", ii);
		printf(" number collision for %d: numbers: ",candidate);	
		for(auto& ii:numbers) printf(" %d", ii);
		printf("\n");
	}
#endif
    if(hit || !validate(v, n)  ) { 
		v[n]=-1;   
		continue;
	}	
    numbers.insert(candidate);	
    if( Helper( n+1, v) ){
	   numbers.erase(candidate);
     // return true;
    }
    else{
		// Go to previous step, 
      for(int k=n;k<N;k++&&v[k]!=-1) {
		  numbers.erase(v[k]);
		  v[k]=-1;
	  }
    }
  }
  return false;
}

bool Solution::validate( std::vector<int>& input,int n)
{
#ifdef DEBUG
   bool debug=false;
   if(getenv("DEBUG")) debug=true;
#endif
//   std::set<int> tmp;
   int N=input.size();
#ifdef DEBUG	 
   if(debug){
     printf("validate: ");
     for(int ii=0;ii<N;ii++) printf("%d ", input[ii]);
   }
#endif

  for(int i=0;i<N;i++){
    if( input[i] <0 ) break;
    for(int j=i+1;j<N;j++){
        if( input[j] <0)  break;
        if( abs(input[i] - input[j]) == (j-i) ) {
#ifdef DEBUG					
           if(debug)printf("invalidated: \n");
#endif					 
          return false;
        }
    }
  }
#ifdef DEBUG	
   if(debug)printf("\n");
#endif
  return true;
}

