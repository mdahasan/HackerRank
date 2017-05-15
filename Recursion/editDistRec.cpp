/*
Given two strings str1 and str2 and below operations that can performed on str1. 
Find minimum number of edits (operations) required to convert ‘str1’ into ‘str2’.

Insert
Remove
Replace
All of the above operations are of equal cost.
Recursives way
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int editDistance(string &X, string &Y, int xlen, int ylen)
{
	if(xlen == 0)return ylen;
	if(ylen == 0)return xlen;

	if(X[xlen - 1] == Y[ylen - 1])
		return editDistance(X, Y, xlen - 1, ylen - 1);
	else 
	{
		return 1 + min(editDistance(X, Y, xlen, ylen - 1),  		 // insert into X
					   min(editDistance(X, Y, xlen - 1, ylen),  	 // remove from X
					       editDistance(X, Y, xlen - 1, ylen - 1))); // replace
	}
}

int main(int argc, char const *argv[])
{
	string X = "sunday";
	string Y = "saturday";

	cout << editDistance(X, Y, X.size(), Y.size()) << endl;

	return 0;
}