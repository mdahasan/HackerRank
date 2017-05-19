/*
Given a sequence, find the length of the longest palindromic subsequence in it. For example, if the given 
sequence is “BBABCBCAB”, then the output should be 7 as “BABCBAB” is the longest palindromic subseuqnce in it. 
“BBBBB” and “BBCBB” are also palindromic subsequences of the given sequence, but not the longest ones.
*/

#include <iostream>
#include <climits>
#include <algorithm>
#include <string>
using namespace std;

#define MAX 100

int LP(string s, int start, int end)
{
	int Table[MAX][MAX] = { {0} };
	for(int i = 0; i < end; i++)
		Table[i][i] = 1;

	for (int chr = 2; chr <= end; ++chr)
	{
		for(int i = 0; i < end - chr + 1; i++)
		{
			int j = i + chr - 1;
			if(s[i] == s[j] && chr == 2)
				Table[i][j] = 2;
			else if(s[i] == s[j])
				Table[i][j] = Table[i + 1][j - 1] + 2;
			else 
				Table[i][j] = max(Table[i + 1][j], Table[i][j - 1]); 
		}
	}
	// for(int i = 0; i < end; i++)
	// {
	// 	for(int j = 0; j < end; j++)
	// 	{
	// 		cout << Table[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	return Table[0][end - 1];
}

int main(int argc, char const *argv[])
{
	string s = "ABDAEA";
	
	cout << LP(s, 0, s.size()) << endl;

	return 0;
}