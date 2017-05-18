/*
Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total 
value in the knapsack. In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent 
values and weights associated with n items respectively. Also given an integer W which represents knapsack 
capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is 
smaller than or equal to W. You cannot break an item, either pick the complete item, or don’t 
pick it (0-1 property).
*/

#include <iostream>
#include <algorithm>
#define MAX 100

using namespace std;

int knapsack(int val[], int wt[], int n, int W)
{
	int T[MAX][MAX] = { {0} };

	for (int i = 0; i <= n; ++i)
	{
		for(int j = 0; j <= W; j++)
		{
			if(i == 0 || j == 0) T[i][j] = 0;
			else if(wt[i - 1] <= j)
				T[i][j] = max((val[i - 1] + T[i - 1][j - wt[i - 1]]), (T[i - 1][j]));
			else
				T[i][j] = T[i - 1][j];
				
		}
	}
	// for(int i = 0; i <= n; i++)
	// {
	// 	for(int j = 0; j <= W; j++)
	// 	{
	// 		cout << T[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	return T[n][W];
}

int main(int argc, char const *argv[])
{
	int val[] = {60, 100, 120};
	int wt[] = {10, 20, 30};
	int n = sizeof(val)/sizeof(val[0]);

	int W = 50;

	cout << knapsack(val, wt, n, W) << endl;
	return 0;
}