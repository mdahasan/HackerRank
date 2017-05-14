/*
Tabulation (Bottom Up)
*/

#include <iostream>
using namespace std;

int fib(int n)
{
	int F[n + 1];
	F[0] = 1;
	F[1] = 1;
	for(int i = 2; i <= n; i++)
	{
		F[i] = F[i - 1] + F[i - 2];
	}
	return F[n];
}

int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter a number: ";
	cin >> n;
	cout << n << "th Fibonacci number is: " << fib(n) << endl;

	return 0;
}