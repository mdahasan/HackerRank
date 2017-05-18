/*
Write a function that takes two parameters n and k and returns the value of Binomial Coefficient C(n, k). 
For example, your function should return 6 for n = 4 and k = 2, and it should return 10 for n = 5 and k = 2.
*/

#include <iostream>
using namespace std;

#define MAX 100

int min(int a, int b)
{
	return (a < b) ? a : b;
}

int binomial(int n, int k)
{
	int C[MAX][MAX] = { {0} };
	for (int i = 0; i <= n; ++i)
	{
		for(int j = 0; j <= min(i, k); j++)
		{
			if(j == 0 || j == n)
				C[i][j] = 1;
			else
				C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
		}
	}

	return C[n][k];
}

int main(int argc, char const *argv[])
{
	int n, k;
	
	n = 5;
	k = 2;
	
	cout << binomial(n, k) << endl;

	return 0;
}