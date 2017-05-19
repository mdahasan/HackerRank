/*
The following is a description of the instance of this famous puzzle involving n=2 eggs and a 
building with k=36 floors.

Suppose that we wish to know which stories in a 36-story building are safe to drop eggs from, 
and which will cause the eggs to break on landing.
*/

#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int eggDrop(int n, int k)
{
	if(k == 0 || k == 1)
		return 1;
	if(n == 1)
		return k;

	int minStep = INT_MAX;

	for(int i = 1; i <=k; i++)
	{
		int res = max(eggDrop(n - 1, i - 1), eggDrop(n, k - i));
		if(res < minStep) minStep = res;
	}

	return minStep + 1;
}

int main(int argc, char const *argv[])
{
	int n, k;
	n = 2; // # of eggs
	k = 10; // # of floors

	cout << eggDrop(n, k) << endl;

	return 0;
}