/*
Given a cost matrix cost[][] and a position (m, n) in cost[][], write a function that returns cost of minimum 
cost path to reach (m, n) from (0, 0). Each cell of the matrix represents a cost to traverse through that cell. 
Total cost of a path to reach (m, n) is sum of all the costs on that path (including both source and destination). 
You can only traverse down, right and diagonally lower cells from a given cell, i.e., from a given cell (i, j), 
cells (i+1, j), (i, j+1) and (i+1, j+1) can be traversed. You may assume that all costs are positive integers.

Recursive way
*/

#include <iostream>
#include <climits>
#define R 3
#define C 3
using namespace std;

int getMinCostPath(int Cost[R][C], int x, int y)
{
	if(x < 0 || y < 0)
		return INT_MAX;
	else if(x == 0 && y == 0)
		return Cost[x][y];
	else
	{
		return Cost[x][y] + min(getMinCostPath(Cost, x - 1, y),
							min(getMinCostPath(Cost, x, y - 1), 
								getMinCostPath(Cost, x - 1, y - 1)));
	}
}

int main(int argc, char const *argv[])
{
	int Cost[R][C] = { {1, 2, 3},
					   {4, 8, 2},
					   {1, 5, 3} 
				     };
	cout << getMinCostPath(Cost, 2, 2) << endl;
	return 0;
}