/*
Given a string, find the length of the longest substring without repeating characters. 
For example, the longest substrings without repeating characters for “ABDEFGABEF” are “BDEFGA” and “DEFGAB”, 
with length 6. For “BBBB” the longest substring is “B”, with length 1. For “GEEKSFORGEEKS”, 
there are two longest substrings shown in the below diagrams, with length 7.

O(nlogn) solution
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int search(std::vector<char> &LSS, char c)
{
	std::vector<char>::iterator it;
	it = find(LSS.begin(), LSS.end(), c);

	if(it != LSS.end())
		return *it;
	return -1;
}

int LSub(string s)
{
	std::vector<string> AllSubStr;
	std::vector<char> LongestSubStr;

	int index = 0;

	for(int i = index; i < s.size(); i++)
	{
		int check = search(LongestSubStr, s[i]);
		if(check > 0)
		{
			string toPush = "";
			for(int j = 0; j < LongestSubStr.size(); j++)
				toPush += LongestSubStr[i];

			AllSubStr.push_back(toPush);
			LongestSubStr.clear();
			LongestSubStr.push_back(s[i]);
			index = check + 1;
		}
		else
		{
			LongestSubStr.push_back(s[i]);
		}
	}
	int maxSubStr = 0;
	for(int i = 0; i < AllSubStr.size(); i++)
		if(AllSubStr[i].size() > maxSubStr) maxSubStr = AllSubStr[i].size();

	return maxSubStr;
}

int main(int argc, char const *argv[])
{
	string s = "GEEKSFORGEEKS";

	cout << LSub(s) << endl;

	return 0;
}