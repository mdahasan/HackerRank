/*
Given two strings str1 and str2 and below operations that can performed on str1. 
Find minimum number of edits (operations) required to convert ‘str1’ into ‘str2’.

Insert
Remove
Replace
All of the above operations are of equal cost.
DP way
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int editDist(string &X, string &Y, int xlen, int ylen)
{
	std::vector<std::vector<int> > dist;
	for(int i = 0; i < X.size(); i++)
		dist.push_back(std::vector<int> (Y.size()));

	for (int i = 0; i < xlen; ++i)
	{
		for(int j = 0; j < ylen; ++j)
		{
			if(i == 0)
				dist[i][j] = j;
			else if(j == 0)
				dist[i][j] = i;

			else if(X[i - 1] == Y[j - 1])
			{
				dist[i][j] = dist[i - 1][j - 1];
			}
			else
			{
				dist[i][j] = 1 + min(dist[i][j - 1],
								 min(dist[i - 1][j], dist[i - 1][j - 1]));
			}
		}
	}
	return dist[xlen - 1][ylen - 1];
}

int main(int argc, char const *argv[])
{
	string X = "sunday";
	string Y = "saturday";

	cout << editDist(X, Y, X.size(), Y.size()) << endl;

	return 0;
}