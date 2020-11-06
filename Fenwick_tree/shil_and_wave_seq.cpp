/*
 Shil and Wave Sequence
Send Feedback
Given a sequence A1 , A2 , A3 .. AN of length N . Find total number of wave subsequences having length greater than 1.
Wave subsequence of sequence A1 , A2 , A3 .. AN is defined as a set of integers i1 , i2 .. ik such that Ai1 < Ai2 > Ai3 < Ai4 .... or Ai1 > Ai2 < Ai3 > Ai4 .... and i1 < i2 < ...< ik.Two subsequences i1 , i2 .. ik and j1 , j2 .. jm are considered different if k != m or there exists some index l such that il ! = jl
INPUT

First line of input consists of integer N denoting total length of sequence.Next line consists of N integers A1 , A2 , A3 .. AN .

OUTPUT

Output total number of wave subsequences of given sequence . Since answer can be large, output it modulo 10^9+7

CONSTRAINTS

1 ≤ N ≤ 10^5

1 ≤ Ai ≤ 10^5

SAMPLE INPUT

5
1 3 5 4 2

SAMPLE OUTPUT

17

Explanation

All the possible sequences are: [ 1 3 ] , [1 5 ] , [ 1 4 ] , [1 2 ] , [1 3 2] , [1 4 2 ] , [1 5 2] , [1 5 4] , [3 5] , [3 4] , [3 2] , [3 5 2] , [3 4 2] , [3 5 4] , [5 4] , [5 2 ] , [4 2] . Note that value in the bracket are the values from the original sequence whose positions are maintained.

*/
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
#define pb push_back
#define mk make_pair
#define max 100002
ll power(ll a, ll b) {
ll x = 1, y = a;
    while(b > 0) {
        if(b%2 == 1) {
            x=(x*y);
            if(x>mod) x%=mod;
        }
        y = (y*y);
        if(y>mod) y%=mod;
        b /= 2;
    }
    return x;
}
ll tree[max][3];
ll read(ll idx, ll i) {
	ll sum = 0;
	while (idx > 0) {
		sum += tree[idx][i];
		if(sum > mod) sum %= mod;
		idx -= (idx & -idx);
	}
	return sum;
}
void update(ll idx ,ll val, ll i) {
	while (idx <= max) {
		tree[idx][i] += val;
		if(tree[idx][i] > mod) tree[idx][i] %= mod;
		idx += (idx & -idx);
	}
}
int main() 
{
    ll n,i,j;
    cin>>n;
    ll a[n];
    for(i = 0; i < n; i++) {
    	cin>>a[i];
    }
    if(n == 1) {
    	puts("0");
    	return 0;
    }
    memset(tree,0,sizeof(tree));
    ll ans = 0;
    update(a[0],1,0);
    update(a[0],0,1);
    update(a[0],0,2);
    for(i = 1; i < n; i++) {
    	ll x,y;
    	x = (read(a[i]-1,1) + read(a[i]-1,0))%mod;
    	y = (read(max-1,2) - read(a[i],2) + read(max-1,0) - read(a[i],0) + mod)%mod;
    	ans = (ans + x + y)%mod;
		update(a[i],y,1);
		update(a[i],x,2);
		update(a[i],1,0);
    }
    cout<<ans<<endl;
	return 0;
}
