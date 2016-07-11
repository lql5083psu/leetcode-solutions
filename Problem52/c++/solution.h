#include<vector>
class Solution {
        int nSolution;
  public:
        bool validate(std::vector<int>& input);
        bool Helper(int n, std::vector<int>& v);
        int totalNQueens(int n); 
};
