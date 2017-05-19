/*
The following is a description of the instance of this famous puzzle involving n=2 eggs and a 
building with k=36 floors.

Suppose that we wish to know which stories in a 36-story building are safe to drop eggs from, 
and which will cause the eggs to break on landing.
*/

#include <iostream>
#include <climits>
#include <algorithm>
#define MAX 100
using namespace std;

int eggDrop(int n, int k)
{
	int eggFloor[MAX][MAX] = { {0} };
	for (int i = 1; i <= n; ++i)
	{
		eggFloor[i][0] = 0;
		eggFloor[i][1] = 1;
	}

	for (int i = 1; i <= k; ++i)
	{
		eggFloor[1][i] = i;
	}

	for(int i = 2; i <= n; i++)
	{
		for(int j = 2; j <= k; j++)
		{
			eggFloor[i][j] = INT_MAX;
			for(int x = 1; x <= j; x++)
			{
				int res = 1 + max(eggFloor[i - 1][x - 1], eggFloor[i][j - x]);
				if(res < eggFloor[i][j]) eggFloor[i][j] = res;
			}
		}
	}
	
	return eggFloor[n][k];
}

int main(int argc, char const *argv[])
{
	int n, k;
	n = 2; // eggs
	k = 100;	// floors

	cout << eggDrop(n, k) << endl;

	return 0;
}