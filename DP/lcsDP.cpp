/*
LCS DP
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void printSeq(std::vector<std::vector<char> > &S, string &X, int i, int j)
{
	if(i == 0 || j == 0)
		return;
	if(S[i][j] == 's')
	{
		printSeq(S, X, i - 1, j - 1);
		cout << X[i];
	}
	else if(S[i][j] == 'i')
		printSeq(S, X, i - 1, j);
	else 
		printSeq(S, X, i, j - 1);

}

void LCS(string &X, string &Y)
{
	std::vector<std::vector<int> > C;
	std::vector<std::vector<char> > S;

	for (int i = 0; i < X.size(); ++i)
	{
		C.push_back(std::vector<int> (Y.size(), 0));
		S.push_back(std::vector<char> (Y.size()));
	}

	for(int i = 1; i < X.size(); i++)
	{
		for(int j = 1; j < Y.size(); j++)
		{
			if(X[i] == Y[j])
			{
				C[i][j] = C[i - 1][j - 1] + 1;
				S[i][j] = 's';
			}
			else if(C[i - 1][j] > C[i][j - 1])
			{
				C[i][j] = C[i - 1][j];
				S[i][j] = 'i';
			}
			else
			{
				C[i][j] = C[i][j - 1];
				S[i][j] = 'j';
			}
		}
	}
	printSeq(S, X, X.size() - 1, Y.size() - 1);
}

int main(int argc, char const *argv[])
{
	string X = " ACCGGGTTAC";
	string Y = " AGGACCA";

	LCS(X, Y);

	return 0;
}