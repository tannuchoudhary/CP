/*
 Divisors Of Factorial
Send Feedback
Given a number, find the total number of divisors of the factorial of the number.
Since the answer can be very large, print answer modulo 10^9+7.
Input

The first line contains T, number of testcases.


T lines follows each containing the number N.

Output

Print T lines of output each containing the answer.

Constraints

1 <= T <= 500

0 <= N <= 50000

Sample Input:

3
2
3
4

Sample Output:

2
4
8

*/
#include<bits/stdc++.h>
using namespace std;
#define MAX 50000
#define MOD 1000000007
#define pb push_back

typedef long long ll;

vector <int>* sieve(){
    bool isPrime[MAX];
    vector<int>* primes = new vector<int>(); //creating a dynamic vector
    for(int i=2; i<=MAX; i++){
        isPrime[i]= true;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i=2; i*i<=MAX; i++){
        if(isPrime){
            for(int j=i*i; j<=MAX; j+=i){
                isPrime[j] = false;
            }
        }
    }
    primes->pb(2);
    for(int i=3; i<=MAX; i+=2){
        if(isPrime[i])
        primes->pb(i);
    }
    return primes;
}

ll divisor(int n, vector<int>* &primes){
    ll result = 1;
    for(int i=0; primes->at(i)<=n; i++){
        int k=primes->at(i);
        ll count =0;
        while((n/k)!=0){
            count = (count+(n/k))%MOD;
            k = k*primes->at(i);
        }
        result = (result*((count+1)%MOD))%MOD;
    }
    return result;
}
int main(){
    vector<int>*primes = sieve();
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<divisor(n, primes)<<endl;
    }
    
}

