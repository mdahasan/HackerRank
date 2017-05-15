/*
Given a cost matrix cost[][] and a position (m, n) in cost[][], write a function that returns cost of minimum 
cost path to reach (m, n) from (0, 0). Each cell of the matrix represents a cost to traverse through that cell. 
Total cost of a path to reach (m, n) is sum of all the costs on that path (including both source and destination). 
You can only traverse down, right and diagonally lower cells from a given cell, i.e., from a given cell (i, j), 
cells (i+1, j), (i, j+1) and (i+1, j+1) can be traversed. You may assume that all costs are positive integers.

DP way
*/

#include <iostream>
#include <climits>
#define R 3
#define C 3

using namespace std;

int getMinCostPath(int Cost[R][C], int x, int y)
{
	int totalCost[R][C];
	totalCost[0][0] = Cost[0][0];

	for(int i = 1; i <= x; i++)
		totalCost[i][0] = totalCost[i - 1][0] + Cost[i][0];

	for (int i = 1; i <= y; ++i)
	{
		totalCost[0][i] = totalCost[0][i - 1] + Cost[0][i];
	}

	for (int i = 1; i <= x; ++i)
	{
		for(int j = 1; j <= y; ++j)
		{
			totalCost[i][j] = min(totalCost[i - 1][j], 
								 min(totalCost[i][j-1], totalCost[i - 1][j - 1])) + Cost[i][j];
		}
	}

	return totalCost[x][y];
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
