/*
 Segmented Sieve Problem
Send Feedback
In this problem you have to print all primes from given interval.
Input

t - the number of test cases, then t lines follows. [t <= 150]
On each line are written two integers L and U separated by a blank. L - lower bound of 
interval, U - upper bound of interval. [2 <= L < U <= 2147483647] [U-L <= 1000000].

Output

For each test case output must contain all primes from interval [L; U] in increasing order.

Sample Input:

2
2 10
3 7

Sample Output:

2
3
5
7
3
5
7 

*/
#include <bits/stdc++.h>
using namespace std ;
void sieve(int l , int r){
    bool isPrime[r - l + 1];
    for(int i = 0 ; i <= r - l ; i++) isPrime[i] = true ;
    for (long long i = 2; i * i <= r; ++i) {
        for (long long j = max(i * i, (l + (i - 1)) / i  * i); j <= r; j += i) {
            isPrime[j - l] = false ;
        }
    }
    for (long long i = max(l, 2); i <= r; ++i) {
        if (isPrime[i - l]) {
            cout << i << "\n" ;
        }
    }
}
int main(){
	int t ; cin >> t ;
	while(t--){
	    int l , r ; cin >> l >> r ;
	    sieve(l , r) ;
		cout << "\n" ;
	}
}
