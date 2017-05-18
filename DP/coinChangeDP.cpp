/*
Given a value N, if we want to make change for N cents, and we have infinite supply of each of 
S = { S1, S2, .. , Sm} valued coins, how many ways can we make the change? The order of coins doesn’t matter.

For example, for N = 4 and S = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. 
So output should be 4. For N = 10 and S = {2, 5, 3, 6}, there are five solutions: 
{2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. So the output should be 5.
*/

#include <iostream>
using namespace std;

int coinChange(int coins[], int n, int amount)
{
	int combinations[amount + 1];
	for(int i = 0; i <= amount + 1; i++)
		combinations[i] = 0;

	combinations[0] = 1;

	int start;
	for(int i = 0; i < n; i++)
	{
		start = coins[i];
		int coin = coins[i];
		for(int j = start; j < amount + 1; j++)
		{
			if(j >= coin)
			{
				combinations[j] += combinations[j - coin];
			}
		}
	}
	
	return combinations[amount];
}

int main(int argc, char const *argv[])
{
	int coins[] = {1, 2, 5};
	int n = sizeof(coins)/sizeof(coins[0]);

	int amount = 12;

	cout << "Total combinations: ";
	cout << coinChange(coins, n, amount) << endl;

	return 0;
}