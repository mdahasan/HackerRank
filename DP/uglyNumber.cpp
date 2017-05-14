/*
Ugly numbers are numbers whose only prime factors are 2, 3 or 5. 
The sequence 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, … shows the first 11 ugly numbers. 
By convention, 1 is included.

Given a number n, the task is to find n’th Ugly number.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int ugly(int n)
{
	int U[n + 1];
	U[0] = 1;
	int i2 = 0;
	int i3 = 0;
	int i5 = 0;
	int uglyNum = 1;

	int next_mult_2 = 2;
	int next_mult_3 = 3;
	int next_mult_5 = 5;

	for(int i = 1; i < n; i++)
	{
		uglyNum = min(next_mult_2, min(next_mult_3, next_mult_5)); 
		U[i] = uglyNum;

		if(uglyNum == next_mult_2)
		{
			i2++;
			next_mult_2 = U[i2] * 2;
		}
		if(uglyNum == next_mult_3)
		{
			i3++;
			next_mult_3 = U[i3] * 3;
		}
		if(uglyNum == next_mult_5)
		{
			i5++;
			next_mult_5 = U[i5] * 5;
		}
	}
	return uglyNum;
}

int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter a number: ";
	cin >> n;
	cout << n << "th Ugly number is: " << ugly(n) << endl;
	return 0;
}