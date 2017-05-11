/*
You are given a list of size , initialized with zeroes. You have to perform  operations on the list and output the maximum of final values of all the  elements in the list. For every operation, you are given three integers ,  and  and you have to add value  to all the elements ranging from index  to (both inclusive).

Input Format

First line will contain two integers  and  separated by a single space.
Next  lines will contain three integers ,  and  separated by a single space.
Numbers in list are numbered from  to .

Constraints






Output Format

A single line containing maximum value in the updated list.

Sample Input

5 3
1 2 100
2 5 100
3 4 100
Sample Output

200
Explanation

After first update list will be 100 100 0 0 0. 
After second update list will be 100 200 100 100 100.
After third update list will be 100 200 200 200 100.
So the required answer will be 200.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    long n, m;
    long a, b, k;
    
    cin >> n >> m;
    vector <long> list(n);

    long max = -99999;
    for(long i = 0; i < m; i++)
    {
        cin >> a >> b >> k;
        list[a - 1] += k;
        if(b < n)list[b] -= k;
    }
    
    long sum = 0;
    for(long i = 0; i < n; i++)
    {
        sum = sum + list[i];
        if(sum > max)
            max = sum;
    }
    
    cout << max << endl;
    return 0;
}
