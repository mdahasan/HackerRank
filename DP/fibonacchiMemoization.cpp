/*
Memoization (Top Down)
*/

#include <iostream>
#define NIL -99
#define MAX 100

using namespace std;

int lookUpTable[MAX];

void init()
{
	for(int i = 0; i < MAX; i++)
	{	
		lookUpTable[i] = NIL;
	}
}

int fib(int n)
{
	if(lookUpTable[n] == NIL)
	{
		if(n <= 1)
			lookUpTable[n] = 1;
		else
			lookUpTable[n] = fib(n - 1) + fib(n - 2);
	}
	return lookUpTable[n];
}

int main(int argc, char const *argv[])
{
	init();

	int n;
	cout << "Enter a number: ";
	cin >> n;
	cout << n << "th Fibonacchi number is: " << fib(n) << endl;

	return 0;
}