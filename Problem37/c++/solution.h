#include <assert.h>
#include <vector>
#include <stdio.h>
#include <set>
#include <map>
#include <list>
using namespace std;
typedef set<char> Candidates;
int Solve( vector<vector<char> >& board, Candidates candidate[9][9], int);

class Solution
{
  public:
    void solveSudoku( std::vector<std::vector<char> >& board);
	void display( std::vector<vector<char> > input);
	bool isValid(vector<vector<char> >board, int i, int j);
	int Solve( vector<vector<char> >& board, Candidates candidates[9][9], int IJ);
};
