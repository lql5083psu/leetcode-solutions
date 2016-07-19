#include <stdio.h>
#include <set>
#include <vector>
#include <string>
#include <stdlib.h>
using namespace std;


class Solution {
public:
    string getPermutation(int n, int k) {
        std::vector<int> Fac(n+1,1);
        std::set<int> unused;
        for(int i=1;i<=n;i++) unused.insert(i);
        for(int i=1;i<=n;i++){
            Fac[i] = Fac[i-1]*i;
        }
        if( k > Fac[n]) {
		  printf("Error! input %d exceed maximum number %d\n", k, Fac[n]);
		}
		
        string result;
        
        k--; // I don't know why i need this step to make the solution correct -____-||
        for(int i=n;i>0;i--){
            std::vector<int> s(unused.begin(), unused.end());
            
            int N=k/Fac[i-1];    
            k = k % Fac[i-1] ;
            char buf[2];
            sprintf(buf,"%c",'0'+s[N]);
            result+= std::string(buf);
            unused.erase(s[N]);
        }
        return result;
    }
};


int main(int argc, char* argv[])
{
  if( argc != 3){
	printf("usage: %s n k\n", argv[0]);
	return 1;
  }
  Solution s;
  std::string result = s.getPermutation(atoi( argv[1]), atoi(argv[2]));
  printf("Result : %s\n", result.c_str());
  return 0;
}
