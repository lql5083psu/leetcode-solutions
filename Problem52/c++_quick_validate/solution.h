#include<vector>
#include <set>
class Solution {
        int nSolution;
  public:
        bool validate(std::vector<int>& input, int n);
        bool Helper(int n, std::vector<int>& v);
        int totalNQueens(int n); 
		
		std::set<int> numbers;
};
