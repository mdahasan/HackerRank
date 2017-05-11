/*
There are  strings. Each string's length is no more than  characters. There are also queries. For each query, you are given a string, and you need to find out how many times this string occurred previously.

Input Format

The first line contains , the number of strings.
The next  lines each contain a string.
The nd line contains , the number of queries.
The following  lines each contain a query string.

Constraints

 
 
    

Sample Input

4
aba
baba
aba
xzxb
3
aba
xzxb
ab
Sample Output

2
1
0
Explanation

Here, "aba" occurs twice, in the first and third string. The string "xzxb" occurs once in the fourth string, and "ab" does not occur at all.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, q;
    vector <string> N;
    
    string ns;
    string qs;
    
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> ns;
        N.push_back(ns);
    }
    
    cin >> q;
    for(int i = 0; i < q; i++)
    {
        int count = 0;
        cin >> qs;
        for(int j = 0; j < N.size(); j++)
        {
            if(qs == N[j])
                count++;
        }
        cout << count << endl;
    }
    
    
    return 0;
}
