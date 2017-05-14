/*
Recursive implementation of LSC
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

std::vector<std::vector<char> > S;

int max(int a, int b)
{
	return (a > b) ? a : b;
}

int LCS(int xlen, int ylen, char *X, char *Y)
{
	if(xlen == 0 || ylen == 0)
		return 0;
	if(X[xlen - 1] == Y[ylen - 1])
	{
		return 1 + LCS(xlen - 1, ylen - 1, X, Y);
	}
	else {
		return max(LCS(xlen - 1, ylen, X, Y), LCS(xlen, ylen - 1, X, Y));
	}
}

int main(int argc, char const *argv[])
{
	char X[] = "AGGTAB";
	char Y[] = "GXTXAYB";

	int xlen = strlen(X);
	int ylen = strlen(Y);

	cout << LCS(xlen, ylen, X, Y) << endl;

	return 0;
}