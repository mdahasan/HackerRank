/*
The Longest Increasing Subsequence (LIS) problem is to find the length of the longest subsequence of a given 
sequence such that all elements of the subsequence are sorted in increasing order. For example, the length of 
LIS for {10, 22, 9, 33, 21, 50, 41, 60, 80} is 6 and LIS is {10, 22, 33, 50, 60, 80}.
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxLIS = 0;

void LIS(std::vector<int> &D)
{
	std::vector<std::vector<int> > L(D.size());
	L[0].push_back(D[0]);

	for(int i = 1; i < D.size(); i++)
	{
		for(int j = 0; j < i; j++)
		{
			if(D[j] < D[i] && (L[i].size() < L[j].size() + 1))
				L[i] = L[j];
		}
		L[i].push_back(D[i]);
	}

	for(int i = 0; i < L.size(); i++)
	{
		if(L[i].size() > maxLIS)
		{
			maxLIS = L[i].size();
		}
	}
	cout << maxLIS << endl;
}

int main(int argc, char const *argv[])
{
	int a[] = {3, 2, 6, 4, 5, 1};
	std::vector<int> arr(a, a + sizeof(a)/sizeof(a[0]));

	LIS(arr);

	return 0;
}